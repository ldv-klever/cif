#include <iostream>
#include <cstddef>
#include <string>
#include <map>
#include <sstream>
#include <utility>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

#include <getopt.h>
#include <sys/stat.h>
#include <spawn.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#ifdef __APPLE__
#include <mach-o/dyld.h>    /* _NSGetExecutablePath */
#endif

using namespace std;

#ifndef CIF_VERSION
#define CIF_VERSION "unknown"
#endif

extern char** environ;

void print_help();

vector<string> stages = {
    "aspect preprocessing",
    "file preparation",
    "macro instrumentation",
    "instrumentation",
    "compilation",
    "C-backend"
};

vector<string> back_ends = {"bin", "asm", "obj", "src"};

enum DEBUG_LEVELS {
    ERROR,
    QUIET,
    NORMAL,
    DEBUG,
    ALL
};

map<string, int> DEBUG_LEVELS = {
        {"ERROR",   ERROR},
        {"QUIET",   QUIET},
        {"NORMAL",  NORMAL},
        {"DEBUG",   DEBUG},
        {"ALL",   ALL},
};

// Overload + and += operators for Vectors.
template<typename T>
std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2){
    std::vector<T> vr(std::begin(v1), std::end(v1));
    vr.insert(std::end(vr), std::begin(v2), std::end(v2));
    return vr;
}

template <typename T>
void operator+=(std::vector<T> &v1, const std::vector<T> &v2) {
    v1.insert(v1.end(), v2.begin(), v2.end());
}

// Join a collection of strings into one string
template <typename Collection>
string join(const Collection& c, string d = " ", bool escape = false) {
    stringstream ss;
    bool first = true;

    for (const auto& i : c) {
        if (!first) {
            ss << d;
        }

        first = false;

        if (escape) {
            ss << '"' << i << '"';
        } else {
            ss << i;
        }
    }
    return ss.str();
}

// Split a string into a collection of strings
// Delimeters inside escaped quotes are ignored
vector<string> split(string str, char delimiter=' ') {
    vector<string> result;

    int begin = 0;
    char quote = 0;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '\'' || str[i] == '\"') {
            if (quote == 0) {
                quote = str[i];
            } else if (quote == str[i]) {
                quote = 0;
            }
        }

        // Do not split if the delimeter is inside escaped quotes
        if (str[i] == delimiter && quote == 0) {
            result.push_back(str.substr(begin, i - begin));
            begin = i + 1;
        }
    }
    result.push_back(str.substr(begin));

    return result;
}

// Check that a file exists
bool exists(const string& name) {
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}

// Convert vector of strings to array of c-strings
// Beware of memory leaks!
const char** convert(vector<string>& v) {
    const char** a = new const char*[v.size() + 1];

    for (size_t i = 0; i < v.size(); i++)
        a[i] = v[i].c_str();

    a[v.size()] = NULL;

    return a;
}

string dirname(const string& str) {
    return str.substr(0,str.find_last_of("/\\"));
}

string filename(const string& str) {
    return str.substr(str.find_last_of("/\\") + 1);
}

// Debug level for logger class
int debug_level = ERROR;

class Log {
public:
    explicit Log(enum DEBUG_LEVELS message_level, int exit_code=-1) {
        this->message_level = message_level;
        this->exit_code = exit_code;
    }

    template<typename T>
    ostringstream& operator<<(T input) {
        auto result = find_if(
                DEBUG_LEVELS.begin(),
                DEBUG_LEVELS.end(),
                [this](const pair<string, int>& p) {
                    return p.second == message_level;
                }
        );

        if(result == DEBUG_LEVELS.end()) {
            cerr << "Can't find debug level: " << message_level << endl;
            exit(-1);
        }

        os << "CIF: " << result->first << ": " << input;
        return os;
    }

    ~Log() {
        if (message_level == ERROR) {
            cerr << os.str();
            cerr.flush();
            exit(exit_code);
        }

        if (message_level <= debug_level) {
            cout << os.str();
            cout.flush();
        }
    }
private:
    ostringstream os;
    enum DEBUG_LEVELS message_level;
    int exit_code;
};

class Configuration {
public:
    void parse_opts(int argc, char **argv) {
        if (argc <= 1)
            Log(ERROR) << "No options were specified through command-line." << endl;

        struct option long_options[] = {
                // These options don’t set a flag.
                // We distinguish them by their indices.
                {"keep",                        no_argument,       nullptr, 'k'},
                {"help",                        no_argument,       nullptr, 'h'},
                {"version",                     no_argument,       nullptr, 'v'},
                {"aspect",                      required_argument, nullptr, 'a'},
                {"back-end",                    required_argument, nullptr, 'b'},
                {"debug",                       required_argument, nullptr, 'd'},
                {"file-preparation-opts",       required_argument, nullptr, 'f'},
                {"general-opts",                required_argument, nullptr, 'g'},
                {"in",                          required_argument, nullptr, 'c'},
                {"macro-instrumentation-opts",  required_argument, nullptr, 'm'},
                {"out",                         required_argument, nullptr, 'o'},
                {"stage",                       required_argument, nullptr, 's'},
                {"aspect-preprocessing-opts",   required_argument, nullptr, '1'},
                {"compilation-opts",            required_argument, nullptr, '2'},
                {"instrumentation-opts",        required_argument, nullptr, '3'},
                {"aspectator",                  required_argument, nullptr, '4'},
                {0, 0, 0, 0}
        };

        int opt_index = 0;
        char const *opt_string = "hvka:b:d:f:g:c:m:o:s:1:2:3:4:";
        while (int c = getopt_long(argc, argv, opt_string, long_options, &opt_index)) {
            if (c == -1)
                break;

            switch (c) {
                case 'h':
                    print_help();
                    exit(0);

                case 'v':
                    cout << "cif-" << CIF_VERSION << endl;
                    exit(0);

                case 'k':
                    keep = true;
                    break;

                case 'a':
                    aspect = optarg;
                    break;

                case 'b':
                    back_end = optarg;

                    if (find(back_ends.begin(), back_ends.end(), back_end) == back_ends.end())
                        Log(ERROR) << "Incorrect back-end '" << back_end << "' was specified." << endl;
                    break;

                case 'd':
                    debug = optarg;

                    // Now let's check that debug option is set correctly.
                    if (DEBUG_LEVELS.find(debug) == DEBUG_LEVELS.end())
                        Log(ERROR) << "Invalid debug level: '" << debug << "'. "
                                << "It can be 'QUIET', 'NORMAL' or 'DEBUG'" << endl;

                    debug_level = DEBUG_LEVELS[debug];
                    break;

                case 'f':
                    file_preparation_opts = split(optarg);
                    break;

                case 'g':
                    general_opts = split(optarg);
                    break;

                case 'c':
                    in = optarg;
                    break;

                case 'm':
                    macro_instrumentation_opts = split(optarg);
                    break;

                case 'o':
                    out = optarg;
                    break;

                case 's':
                    stage = optarg;

                    if (find(stages.begin(), stages.end(), stage) == stages.end())
                        Log(ERROR) << "Invalid stage: '" << stage << "'. "
                                << "It can be one of: " << join(stages, ", ", true) << endl;
                    break;

                case '1':
                    aspect_preprocessing_opts = split(optarg);
                    break;

                case '2':
                    compilation_opts = split(optarg);
                    break;

                case '3':
                    instrumentation_opts = split(optarg);
                    break;

                case '4':
                    aspectator = optarg;
                    break;

                default:
                    Log(ERROR) << "Invalid command-line options were specified - see error messages above." << endl;
            }
        }

        Log(NORMAL) << "Logging level is set to " << debug << endl;

        // Print all command-line options up to -- delimeter
        string allArgs = join(vector<string>(argv + 1, argv + argc));
        Log(DEBUG)
                << "Options '" << allArgs.substr(0, allArgs.find(" -- "))
                << "' were passed to script through command-line." << endl;

        // Get the rest of command-line options (options after '--').
        if (optind < argc) {
            rest_opts = vector<string>(argv + optind, argv + argc);
            Log(DEBUG)
                    << "Options '" << join(rest_opts) << "' will be passed to aspectator as is"
                    << " (note that these options are processed by your interpreter before"
                    << " passing to CIF, so don't forget about proper escaping)." << endl;
        }

        Log(DEBUG) << "CIF will perform all stages up to '" << stage << "' stage." << endl;

        if (in.empty())
            Log(ERROR) << "You should specify C file to be instrumented by means of command-line"
                    << " option --in (-c)." << endl;

        Log(DEBUG) << "File '" << in << "' will be instrumented or passed through C-backend." << endl;

        if (!aspect.empty() && stage != "C-backend") {
            if (!exists(aspect))
                Log(ERROR) << "Specified aspect '" << aspect << "' doesn't exist." << endl;

            Log(DEBUG) << "Aspect file '" << aspect << "' will be used for instrumentation." << endl;
        }
        else if (aspect.empty() && stage == "C-backend"){
            Log(DEBUG) << "Input file will be passed through C-backend." << endl;
        }
        else if (aspect.empty()) {
            Log(ERROR) << "You should specify aspect file to be used for instrumentation"
                    << " by means of command-line option --aspect or use 'C-backend' as value"
                    << " of command-line option --stage." << endl;
        } else {
            Log(ERROR) << "You shouldn't specify aspect file with 'C-backend' as"
                    << " value of command-line option --stage." << endl;
        }

        if (out.empty())
            Log(ERROR) << "You should specify output file by means of command-line option"
                    << " --out (-o)." << endl;

        Log(DEBUG) << "Output will be put to file '" << out << "' at 'compilation' stage." << endl;

        find_aspectator();

        if (stage == "compilation") {
            if (back_end.empty())
                Log(ERROR) << "Back-end for 'compilation' stage wasn't specified." << endl;

            Log(DEBUG) << "Back-end '" << back_end
                    << "' will be used at 'compilation' stage." << endl;
        }

        if (!general_opts.empty())
            Log(DEBUG) << "Options '" << join(general_opts)
                    << "' will be specified at all stages." << endl;


        if (!aspect_preprocessing_opts.empty())
            Log(DEBUG) << "Options '" << join(aspect_preprocessing_opts)
                    << "' will be specified at 'aspect preprocessing' stage." << endl;

        if (!file_preparation_opts.empty())
            Log(DEBUG) << "Options '" << join(file_preparation_opts)
                    << "' will be specified at 'file preparation' stage." << endl;

        if (!macro_instrumentation_opts.empty())
            Log(DEBUG) << "Options '" << join(macro_instrumentation_opts)
                    << "' will be specified at 'macro instrumentation' stage." << endl;

        if (!instrumentation_opts.empty())
            Log(DEBUG) << "Options '" << join(instrumentation_opts)
                    << "' will be specified at 'instrumentation' stage." << endl;

        if (!compilation_opts.empty())
            Log(DEBUG) << "Options '" << join(compilation_opts)
                    << "' will be specified at 'compilation' stage." << endl;
    }

private:
    string find_cross_compile_prefix(string& cif_filename) {
        auto pos = cif_filename.find("cif");

        if (pos == string::npos)
            Log(ERROR) << "Can't find 'cif' in CIF filename '" << cif_filename << "'." << endl;

        return string(cif_filename.substr(0, pos));
    }

    void find_aspectator() {
        if (!aspectator.empty()) {
            Log(DEBUG)
                    << "Aspectator '" << aspectator
                    << "' was specified by means of command-line option."
                    << endl;
            return;
        }

        uint32_t len = PATH_MAX;
        char real_cif_path[PATH_MAX];

    #ifdef __APPLE__
        char cif_path[PATH_MAX];

        if (_NSGetExecutablePath(cif_path, &len))
            Log(ERROR) << "Buffer to hold path to CIF is too small." << endl;

        if (!realpath(cif_path, real_cif_path))
            Log(ERROR) << "Can't find real path to aspectator." << endl;

    #else
        len = readlink("/proc/self/exe", real_cif_path, PATH_MAX);
        real_cif_path[len] = 0;
    #endif

        string cif_path_str(real_cif_path);
        string cif_dirname = dirname(cif_path_str);
        string cif_filename = filename(cif_path_str);
        string cross_compile_prefix = find_cross_compile_prefix(cif_filename);

        aspectator = cif_dirname + "/" + cross_compile_prefix + "gcc";
        Log(DEBUG) << "Aspectator '" << aspectator << "' will be used." << endl;
    }

public:
    bool keep = false;

    string debug;

    string aspect;
    string back_end;
    string in;
    string out;
    string stage = "compilation";
    string aspectator;

    vector<string> rest_opts;
    vector<string> general_opts;
    vector<string> compilation_opts;
    vector<string> instrumentation_opts;
    vector<string> file_preparation_opts;
    vector<string> macro_instrumentation_opts;
    vector<string> aspect_preprocessing_opts;
};

class Stages {
public:
    Stages(Configuration& conf) {
        this->conf = conf;

        /* Place preprocessed aspect file and all intermediate files near output
        * file. When several CIF operates in parallel they can overwrite
        * preprocessed aspect files otherwise.
        */
        string out_dirname = dirname(conf.out);
        string out_filename = filename(conf.out);

        if (out_dirname.empty())
            out_dirname = ".";

        aux_base = out_dirname + "/" + out_filename;
        if (!conf.aspect.empty()) {
            string aspect_filename =filename(conf.aspect);
            aspect_preprocessed = aux_base + "." + aspect_filename + ".i";
        }
    }

    void perform() {
        for (auto& stage : stages) {
            this->stage = stage;

            // Skip all instrumentation stages if C-backend should be invoked.
            if (conf.stage == "C-backend" && stage != "C-backend")
                continue;

            Log(DEBUG) << "********* " << stage << " *********" << endl;

            if (stage == "aspect preprocessing") {
                prepare_aspect_preprocessing();
            } else if (stage == "file preparation") {
                prepare_file_preparation();
            } else if (stage == "macro instrumentation") {
                prepare_macro_instrumentation();
            } else if (stage == "instrumentation") {
                prepare_instrumentation();
            } else if (stage == "compilation") {
                prepare_compilation();
            } else if (stage == "C-backend") {
                prepare_c_backend();
            }

            if (stage != "compilation" && stage != "C-backend")
                aux_files.push_back(out);

            if (stage != "C-backend") {
                /* Specify what stage should be performed. */
                /* Aspect file should be always specified to enable specific features of aspectator. */
                stage_envs_full = {"LDV_STAGE=" + to_string(stage_id), "LDV_ASPECT_FILE=" + aspect};
                stage_envs_full += stage_envs;
            } else {
                stage_envs_full = stage_envs;
            }

            execute_stage();

            // Make some magic for aspect preprocessing stage.
            if (stage == "aspect preprocessing") {
                /* Replace '@' with '#' to return back standard preprocessing directives. */
                // cmd = "sed -i.bak 's/@/#/g' \"" + out + "\"";
                // execute(cmd, stage_id);
                execute_cmd({"sed", "-i.bak", "s/@/#/g", out}, {}, stage_id);
            }

            stage_id++;

            if (conf.stage == stage)
                break;
        }

        Log(NORMAL) << "Make all successfully." << endl;
    }

private:
    void prepare_aspect_preprocessing() {
        in =  conf.aspect;
        out = aspect_preprocessed;
        aspect = conf.aspect;

        /* Do not use standard options set because of they may influence
        * aspect preprocessing (#865).
        */
        options = vector<string>();

        /* Aspect preprocessing can affect file paths that use word 'linux', since
        * there is the standard built-in macro '#define linux 1'. So undefine the
        * most of built-in macros by means of '-undef' (#865).
        * -nostdinc helps to avoid includes of system headers.
        * Keeps comments by means of option -C (#865).
        * Specify that aspect files "are" in C.
        */
        stage_post_opts = {"-E", "-undef", "-nostdinc", "-C", "-x", "c"};
        stage_post_opts += conf.aspect_preprocessing_opts;
    }

    void prepare_file_preparation() {
        // At file preparation stage recommendations with 'file' pointucts are applied.
        in = conf.in;
        // Use '.prepared' suffix for such kind of files.
        out = aux_base + ".prepared";
        // Use preprocessed aspect at other stages.
        aspect = aspect_preprocessed;

        options = conf.rest_opts;

        /* Even though standard preprocessing won't be done but nevertheless
        * specify that output should be a preprocessed file.
        */
        stage_post_opts = {"-E", "-x", "c"};
        stage_post_opts += conf.file_preparation_opts;
    }

    void prepare_macro_instrumentation() {
        // Input file is prepared file.
        in = aux_base + ".prepared";
        // Use preprocessed aspect.
        aspect = aspect_preprocessed;
        // Use '.macroinstrumented' suffix for macro instrumented files.
        out = aux_base + ".macroinstrumented";

        options = conf.rest_opts;

        // TODO: remove this auxiliary search directory when will get rid of *.prepared files.
        string aux_search_dir = dirname(conf.in);

        stage_pre_opts = {"-I", aux_search_dir};
        stage_post_opts = {"-E", "-x", "c"};
        stage_post_opts += conf.macro_instrumentation_opts;
    }

    void prepare_instrumentation() {
        // Input file is macro instrumented file.
        in = aux_base + ".macroinstrumented";
        // Use '.instrumented' suffix for instrumented files.
        out = aux_base + ".instrumented";
        // Use preprocessed aspect.
        aspect = aspect_preprocessed;

        options = conf.rest_opts;

        // Stop after preprocessed file is parsed.
        stage_post_opts = {"-fsyntax-only", "-x", "cpp-output"};
        stage_post_opts += conf.instrumentation_opts;
        // Print output using such the way instead of the standard one.
        stage_envs = {"LDV_OUT=" + out};
    }

    void prepare_compilation() {
        // Input file is instrumented file.
        in = aux_base + ".instrumented";
        out = conf.out;
        // Use preprocessed aspect.
        aspect = aspect_preprocessed;

        options = conf.rest_opts;

        // Use specific options for corresponding back-ends.
        if (conf.back_end == "asm")
            stage_opts_specific = {"-S"};
        else if (conf.back_end == "obj")
            stage_opts_specific = {"-c"};
        else if (conf.back_end == "src") {
            // Stop asfter preprocessed file is parsed.
            stage_opts_specific = {"-fsyntax-only"};
            // Print output using such the way instead of the standard one.
            stage_envs = {"LDV_C_BACKEND_OUT=" + out};
        }
        else
            stage_opts_specific = vector<string>();

        stage_post_opts = {"-x", "c"};
        stage_post_opts += stage_opts_specific + conf.compilation_opts;

        /* Remove -include options since they cause repeating include of
            * headers that may cause build failures, e.g. due to type
            * redeclaration. Since it is the last stage, we can safely
            * overwrite options.
            * It is worth mentioning that a long ago this was not necessary
            * due to using "-x cpp-output" like for the instrumentation
            * stage. This was changed to support comments added during
            * instrumentation. Those comments are useful, e.g. to handle
            * CIF auxiliary functions in a specific way at visualization. */
        while (true) {
            auto it = find_if(
                    options.begin(),
                    options.end(),
                    [] (const string& s) {return s.find("-include") == 0;}
            );

            if (it == options.end())
                break;

            /* Skip -include and its mandatory value that follows -include or
                * that is provide as one more option enclosed in quotes. */
            it = options.erase(it);
            if (it != options.end() && *(it->begin()) != '-') {
                options.erase(it);
            }
        }
    }

    void prepare_c_backend() {
        in = conf.in;
        out = conf.out;
        options = conf.rest_opts;

        // Stop asfter preprocessed file is parsed.
        stage_post_opts = {"-fsyntax-only"};
        // Print output using LDV_C_BACKEND_OUT instead of the standard way.
        stage_envs = {"LDV_C_BACKEND_OUT=" + out};
    }

    void execute_stage() {
        /* 1. CIF core executable.
         * 2. Some options like "-I" should be placed ahead to have more priority.
         * 3. Standard compilation (preprocesing) options.
         * 4. We wouldn't like to change original function calls with the gcc ones.
         *    So use -fno-builtin option for that purpose.
         * 5. Place all specific options at the end of other options to make them more of a priority.
         * 6. File to be instrumented.
         * 7. Output file. */
        vector<string> argv =
            vector<string>{conf.aspectator}
            + stage_pre_opts
            + options
            + vector<string>{"-fno-builtin"}
            + conf.general_opts
            + stage_post_opts
            + vector<string>{in, "-o", out};

        execute_cmd(argv, stage_envs_full, stage_id);
    }

    void execute_cmd(vector<string> argv, vector<string> envp, int stage_id) {
        Log(DEBUG) << "Execute '" << join(envp) << " " << join(argv) << "'." << endl;

        // Copy environment variables, they may be needed in the child process
        for (char** env = environ; *env != 0; env++) {
            envp.push_back(*env);
        }

        pid_t pid;
        char *const *cargv = (char *const *)convert(argv);
        char *const *cenvp = (char *const *)convert(envp);

        // posix_spawn() is faster than system()
        int status = posix_spawnp(&pid, argv[0].c_str(), NULL, NULL, cargv, cenvp);

        delete[] cargv;
        delete[] cenvp;

        if (status == 0) {
            do {
                waitpid(pid, &status, 0);

                if (status) {
                    // Remove intermediate files obtained thus far if required.
                    clean();
                    Log(ERROR, WEXITSTATUS(status))
                            << "Aspectator failed at '" << stage_id << "' stage: " << strerror(status) << endl;
                }
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        } else {
            // Remove intermediate files obtained thus far if required.
            clean();
            Log(ERROR, status)
                    << "posix_spawn failed: " << strerror(status) << endl;
        }
    }

    void clean() {
        // Do not remove intermediate files in this case.
        if (conf.keep)
            return;

        Log(DEBUG) << "Remove intermediate files." << endl;
        for (auto& file : aux_files) {
            if (!exists(file))
                unlink(file.c_str());
        }
    }

private:
    Configuration conf;
    string aux_base, aspect_preprocessed;

    int stage_id = 0;
    string in, out, aspect;
    string stage;
    vector<string> options;
    vector<string> stage_envs, stage_envs_full, stage_pre_opts, stage_post_opts, stage_opts_specific;
    vector<string> aux_files;
};

int main(int argc, char **argv) {
    Configuration conf;
    conf.parse_opts(argc, argv);

    Stages s = Stages(conf);
    s.perform();

    return 0;
}

void print_help() {
    cout << "\
NAME\n\
  cif: instruments a file using an aspect and options\n\
    specified.\n\
\n\
SYNOPSIS\n\
  $cif [option...] [-- options_for_aspectator]\n\
\n\
OPTIONS\n\
\n\
  -a, --aspect <file>\n\
    Aspect <file> to be used for instrumentation. It is mandatory except for\n\
    stage 'C-backend'.\n\
\n\
  --aspect-preprocessing-opts <string>\n\
    Options specified by means of <string> will be passed as is at\n\
    'aspect preprocessing' stage.\n\
\n\
  --back-end <back-end>\n\
    Use specified back-end to produce output at 'compilation' stage. Following\n\
    back-ends available: 'bin', 'asm', 'obj' and 'src'.\n\
\n\
  --compilation-opts <string>\n\
    Options specified by means of <string> will be passed as is at 'compilation'\n\
    stage.\n\
\n\
  --debug <level>\n\
    Logging <level> may be 'QUIET', 'NORMAL', 'DEBUG'. \n\
    Each following level includes all messages of levels before it.\n\
\n\
  --file-preparation-opts <string>\n\
    Options specified by means of <string> will be passed as is at\n\
    'file preparation' stage.\n\
\n\
  --general-opts <string>\n\
    Options specified by means of <string> will be passed as is at all stages.\n\
\n\
  -c, --in <file>\n\
    Input <file> to be instrumented.\n\
\n\
  --instrumentation-opts <string>\n\
    Options specified by means of <string> will be passed as is at\n\
    'instrumentation' stage.\n\
\n\
  --keep\n\
    Keep intermediate files.\n\
\n\
  --keep-prepared-file\n\
    Keep just prepared intermediate file. This may be required because of\n\
    preprocessed file refers to the given file instead of the original one.\n\
\n\
  --macro-instrumentation-opts <string>\n\
    Options specified by means of <string> will be passed as is at\n\
    'macro instrumentation' stage.\n\
\n\
  -o, --out <file>\n\
    Specified back-end will place output to <file> if 'compilation' stage will\n\
    be performed. Intermediate files are placed near output file.\n\
\n\
  --stage <stage>\n\
    <stage> may be one of 'aspect preprocessing', 'file preparation', 'macro\n\
    instrumentation', 'instrumentation', 'compilation'. Each following stage\n\
    includes all previous stages. 'Compilation' stage is used by default.\n\
    Special stage 'C-backend' means that instrumentation will not be performed\n\
    at all, just C-backend will be invoked for the input file.\n\
\n\
  -h, --help\n\
    Print this help and exit with a syntax error.\n\
\n\
  -v, --version\n\
    Print CIF version.\n\
\n\
  options_for_aspectator\n\
    This is list of options that will be passed to aspectator as is. Note that\n\
    these options are processed by your interpreter before passing to CIF, so\n\
    don't forget about proper escaping.\n";
}
