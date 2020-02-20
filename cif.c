#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <limits.h>
#include <libgen.h>
#include <unistd.h>

#ifdef __APPLE__
#include <mach-o/dyld.h>    /* _NSGetExecutablePath */
#endif

#define QUIET   0
#define NORMAL  10
#define DEBUG   100

#define LOG_PREFIX_SIZE 16

static void parse_opts(int argc, char **argv);
static void perform_stages(void);
static void print_debug(int level, const char *format, ...);
static void print_help(void);
static void clean(void);

struct aux {
    char *aspect_preprocessed;
    char *file_prepared;
    char *macro_instrumented;
    char *instrumented;
} aux_files;

struct options {
    int keep;
    int keep_prepared_file;
    const char *aspect;
    const char *back_end;
    int debug_level;
    const char *debug;
    const char *file_preparation_opts;
    const char *general_opts;
    const char *in;
    const char *macro_instrumentation_opts;
    const char *out;
    const char *stage;
    const char *aspectator;
    const char *aspect_preprocessing_opts;
    const char *compilation_opts;
    const char *instrumentation_opts;
} opts;

char *rest_opts = NULL;
char aspectator[PATH_MAX];

struct stat stat_buf;

int main (int argc, char **argv) {
    parse_opts(argc, argv);

    /* Perform all required stages. */
    perform_stages();

    print_debug(NORMAL, "Make all successfully.\n");

    if (rest_opts)
        free(rest_opts);

    free(aux_files.aspect_preprocessed);
    free(aux_files.file_prepared);
    free(aux_files.macro_instrumented);
    free(aux_files.instrumented);

    return 0;
}

static void parse_opts(int argc, char **argv) {
    int i, c, ret, opts_len = 0, opt_index = 0;
    char *opts_string;
    char aspectator_compilation[PATH_MAX+32]; // 32 == for options

    if (argc <= 1) {
        fprintf (stderr, "No options were specified through command-line. "\
            "Please see help to understand how to use this script.\n");
        exit(-1);
    }

    struct option long_options[] = {
        /* These options set a flag. */
        {"keep",                no_argument, &(opts.keep), 1},
        {"keep-prepared-file",  no_argument, &(opts.keep_prepared_file), 1},
        /* These options don’t set a flag.
         We distinguish them by their indices. */
        {"help",                        no_argument, 0, 'h'},
        {"aspect",                      required_argument, 0, 'a'},
        {"back-end",                    required_argument, 0, 'b'},
        {"debug",                       required_argument, 0, 'd'},
        {"file-preparation-opts",       required_argument, 0, 'f'},
        {"general-opts",                required_argument, 0, 'g'},
        {"in",                          required_argument, 0, 'c'},
        {"macro-instrumentation-opts",  required_argument, 0, 'm'},
        {"out",                         required_argument, 0, 'o'},
        {"stage",                       required_argument, 0, 's'},
        {"aspect-preprocessing-opts",   required_argument, 0, '1'},
        {"compilation-opts",            required_argument, 0, '2'},
        {"instrumentation-opts",        required_argument, 0, '3'},
        {0, 0, 0, 0}
    };

    while ((c = getopt_long (argc, argv, "hco", long_options, &opt_index)) != -1) {
        /* getopt_long stores the option index here. */

        if (long_options[opt_index].flag != 0)
            continue;

        switch (c) {
            case 'h':
                print_help();
                exit(0);
                break;

            case 'a':
                opts.aspect = optarg;
                break;

            case 'b':
                opts.back_end = optarg;
                break;

            case 'd':
                opts.debug = optarg;

                if (!strcmp(optarg, "QUIET"))
                    opts.debug_level = QUIET;
                else if (!strcmp(optarg, "NORMAL"))
                    opts.debug_level = NORMAL;
                else if (!strcmp(optarg, "DEBUG"))
                    opts.debug_level = DEBUG;
                else if (!strcmp(optarg, "ALL")) {
                    opts.debug_level = DEBUG;
                    opts.debug = "DEBUG";
                } else {
                    opts.debug_level = -1;
                }

                break;

            case 'f':
                opts.file_preparation_opts = optarg;
                break;

            case 'g':
                opts.general_opts = optarg;
                break;

            case 'c':
                opts.in = optarg;
                break;

            case 'm':
                opts.macro_instrumentation_opts = optarg;
                break;

            case 'o':
                opts.out = optarg;
                break;

            case 's':
                opts.stage = optarg;
                break;

            case '1':
                opts.aspect_preprocessing_opts = optarg;
                break;

            case '2':
                opts.compilation_opts = optarg;
                break;

            case '3':
                opts.instrumentation_opts = optarg;
                break;

            default:
                fprintf(stderr, "Invalid command-line options were specified - see error messages above.\n");
                exit(-1);
        }
    }

    /* Now let's check that debug option is set correctly. */

    if (opts.debug_level != QUIET
        && opts.debug_level != NORMAL
        && opts.debug_level != DEBUG)
    {
        fprintf(stderr, "Incorrect debug level. It can be 'QUIET', 'NORMAL' or 'DEBUG'.\n");
        exit(-1);
    }

    print_debug(NORMAL, "Debug level is set to '%s'.\n", opts.debug);

    /* Convert array of strings with options to a single string. */

    for (i = 1; i < argc; i++) {
        opts_len += strlen(argv[i]) + strlen(" ");
    }

    opts_string = malloc(opts_len + 1);
    if (opts_string == NULL) {
        fprintf(stderr, "Malloc failed.\n");
        exit(-1);
    }

    /* strcat(dest, src) searches for the a null byte starting at dest and going forward,
     * and then write the src string there.
     */
    opts_string[0] = 0;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--")) {
            strcat(opts_string, argv[i]);
            if (i != argc - 1 && strcmp(argv[i+1], "--"))
                strcat(opts_string, " ");
        } else {
            i = argc;
        }
    }

    print_debug(DEBUG, "Options '%s' were passed to script through command-line.\n", opts_string);

    /* Get the rest of command-line options (options after '--'). */

    if (optind < argc) {
        /* 2 "* argc" is for double quotes around options. */
        rest_opts = malloc(opts_len + 2 * argc + 1);
        rest_opts[0] = 0;
    }

    while (optind < argc) {
        strcat(rest_opts, "\"");
        strcat(rest_opts, argv[optind++]);
        strcat(rest_opts, "\"");
        if (optind != argc)
            strcat(rest_opts, " ");
    }

    if (rest_opts && strlen(rest_opts) > 1)
    print_debug(DEBUG, "Options '%s' will be passed to aspectator as is"\
        " (note that these options are processed by your interpreter before"\
        " passing to CIF, so don't forget about proper escaping).\n", rest_opts);

    if (!opts.stage)
        opts.stage = "compilation";

    if (strcmp(opts.stage, "aspect preprocessing")
        && strcmp(opts.stage, "file preparation")
        && strcmp(opts.stage, "macro instrumentation")
        && strcmp(opts.stage, "instrumentation")
        && strcmp(opts.stage, "compilation")
        && strcmp(opts.stage, "C-backend"))
    {
        fprintf(stderr, "Incorrect stage '%s' was specified.\n", opts.stage);
        exit(-1);
    }

    print_debug(DEBUG, "CIF will perform all stages up to '%s' stage.\n", opts.stage);

    if (!opts.in) {
        fprintf(stderr, "You should specify C file to be instrumented by means of command-line"\
            " option --in (-c).\n");
        exit(-1);
    }

    print_debug(DEBUG, "File '%s' will be instrumented or passed through C-backend.\n", opts.in);


    if (opts.aspect && strcmp(opts.stage, "C-backend")) {
        if (stat(opts.aspect, &stat_buf) == -1) {
            fprintf(stderr, "Specified aspect '%s' doesn't exist.\n", opts.aspect);
            exit(-1);
        }

        print_debug(DEBUG, "Aspect file '%s' will be used for instrumentation.\n", opts.aspect);
    }
    else if (!opts.aspect && !strcmp(opts.stage, "C-backend")){
        print_debug(DEBUG, "Input file will be passed through C-backend.\n");
    }
    else if (!opts.aspect) {
        fprintf(stderr, "You should specify aspect file to be used for instrumentation"\
            " by means of command-line option --aspect or use 'C-backend' as value"\
            " of command-line option --stage.\n");
        exit(-1);
    } else {
        fprintf(stderr, "You shouldn't specify aspect file with 'C-backend' as"\
            " value of command-line option --stage.\n");
        exit(-1);
    }

    if (!opts.out) {
        fprintf(stderr, "You should specify output file by means of command-line option"\
            " --out (-o).\n");
        exit(-1);
    }

    print_debug(DEBUG, "Output will be put to file '%s' at"\
        " 'compilation' stage.\n", opts.out);

    uint32_t len = PATH_MAX;

    #ifdef __APPLE__
    char buf[PATH_MAX];

    if (_NSGetExecutablePath(buf, &len)) {
        fprintf(stderr, "Buffer is too small, which is impossible by the way.\n");
        exit(-1);
    }

    if (!realpath(buf, aspectator)) {
        fprintf(stderr, "Can't find real path to aspectator.\n");
        exit(-1);
    }

    #else
    len = readlink("/proc/self/exe", aspectator, PATH_MAX);
    aspectator[len] = '\0';
    #endif

    char *aspectator_dir= strdup(aspectator);
    aspectator_dir = dirname(aspectator_dir);

    aspectator[0] = 0;
    strcpy(aspectator, aspectator_dir);
    strcat(aspectator, "/gcc");

    free(aspectator_dir);

    print_debug(DEBUG, "Aspectator '%s' will be used.\n", aspectator);

    /* Check that back-end is specified and aspectator works correctly for 'compilation' stage. */

    if (!strcmp(opts.stage, "compilation")) {
        if (!opts.back_end) {
            fprintf(stderr, "Back-end for 'compilation' stage wasn't specified.\n");
            exit(-1);
        }

        if (strcmp(opts.back_end, "bin")
            && strcmp(opts.back_end, "asm")
            && strcmp(opts.back_end, "obj")
            && strcmp(opts.back_end, "src"))
        {
            fprintf(stderr, "Incorrect back-end '%s' was specified.\n", opts.back_end);
            exit(-1);
        }

        print_debug(DEBUG, "Back-end '%s' will be used at 'compilation' stage.\n", opts.back_end);

        sprintf(aspectator_compilation, "%s -fsyntax-only -x c /dev/null", aspectator);
        print_debug(DEBUG, "Execute '%s'.\n", aspectator_compilation);

        ret = system(aspectator_compilation);
        if (ret) {
            fprintf(stderr, "Aspectator '%s' doesn't work.\n", aspectator);
            exit(WEXITSTATUS(ret));
        }

        print_debug(DEBUG, "Aspectator '%s' has worked well.\n", aspectator);
    }

    if (opts.general_opts)
        print_debug(DEBUG, "Options '%s' will be specified at all stages.\n", opts.general_opts);
    else
        opts.general_opts = "";


    if (opts.aspect_preprocessing_opts)
        print_debug(DEBUG, "Options '%s' will be specified at 'aspect preprocessing' stage.\n"\
            , opts.aspect_preprocessing_opts);
    else
        opts.aspect_preprocessing_opts = "";


    if (opts.file_preparation_opts)
        print_debug(DEBUG, "Options '%s' will be specified at 'file preparation' stage.\n"\
            , opts.file_preparation_opts);
    else
        opts.file_preparation_opts = "";


    if (opts.macro_instrumentation_opts)
        print_debug(DEBUG, "Options '%s' will be specified at 'macro instrumentation' stage.\n"\
            , opts.macro_instrumentation_opts);
    else
        opts.macro_instrumentation_opts = "";


    if (opts.instrumentation_opts)
        print_debug(DEBUG, "Options '%s' will be specified at 'instrumentation' stage.\n"\
            , opts.instrumentation_opts);
    else
        opts.instrumentation_opts = "";


    if (opts.compilation_opts)
        print_debug(DEBUG, "Options '%s' will be specified at 'compilation' stage.\n"\
            , opts.compilation_opts);
    else
        opts.compilation_opts = "";

    free(opts_string);
}

static void perform_stages(void) {
    int stages_len, aux_base_len, aspect_preprocessed_len, stage_pre_opts_len, stage_post_opts_len, stage_envs_len,
        stage_envs_full_len, cmd_len, ret;
    int i, stage_id = 0;
    char *in, *aspect, *options, *out, *aux_search_dir, *aux_base, *aspect_preprocessed, *cmd;
    char *stages[] = {"aspect preprocessing", "file preparation", "macro instrumentation",
        "instrumentation", "compilation", "C-backend"};

    /* Stage specific environment variables and options. */
    char *stage_envs, *stage_envs_full, *stage_pre_opts, *stage_post_opts, *stage_opts_specific, *pch;

    stages_len = sizeof(stages)/sizeof(stages[0]);

    for (i = 0; i < stages_len; i++) {
        /* Skip all instrumentation stages if C-backend should be invoked. */
        if (!strcmp(opts.stage, "C-backend") && strcmp(stages[i], "C-backend"))
            continue;

        options = NULL;
        aspect = NULL;
        stage_envs = NULL;
        stage_pre_opts = "";
        stage_post_opts = NULL;

        in      = malloc(strlen(opts.in) + 1);
        out     = malloc(strlen(opts.out) + 1);
        if (opts.aspect)
            aspect = malloc(strlen(opts.aspect) + 1);
        strcpy(in, opts.in);
        strcpy(out, opts.out);
        if (opts.aspect)
            strcpy(aspect, opts.aspect);
        if (rest_opts) {
            options = malloc(strlen(rest_opts) + 1);
            strcpy(options, rest_opts);
        }

        /* Place preprocessed aspect file and all intermediate files near output
         * file. When several CIF operates in parallel they can overwrite
         * preprocessed aspect files otherwise.
         */
        char *out_copy1 = strdup(out);
        char *out_copy2 = strdup(out);
        char *out_dirname = strdup(dirname(out_copy1));
        char *out_basename = strdup(basename(out_copy2));

        aux_base_len = strlen(out_dirname) + strlen(out_basename) + strlen("/");
        aux_base = malloc(aux_base_len + 1);
        sprintf(aux_base, "%s/%s", out_dirname, out_basename);

        free(out_copy1);
        free(out_copy2);
        free(out_dirname);
        free(out_basename);

        if (aspect) {
            char *aspect_copy = strdup(aspect);
            char *aspect_basename = strdup(basename(aspect_copy));

            aspect_preprocessed_len = strlen(aux_base) + strlen(".") + strlen(aspect_basename) + strlen(".i");
            aspect_preprocessed = malloc(aspect_preprocessed_len + 1);
            sprintf(aspect_preprocessed, "%s.%s.i", aux_base, aspect_basename);

            free(aspect_copy);
            free(aspect_basename);
        } else {
            aspect_preprocessed = malloc(strlen("") + 1);
            strcpy(aspect_preprocessed, "");
        }

        print_debug(DEBUG, "********* %s *********\n", stages[i]);

        /* At aspect preprocessing stage aspect file is preprocessed as well as
         * common C file (thus option '-E' is specified). But aspect preprocessor
         * directives begin with '@' instead of '#'.
         */

        if (!strcmp(stages[i], "aspect preprocessing")) {
            free(in);
            in = aspect;

            /* Do not use standard options set because of they may influence
             * aspect preprocessing (#865).
             */

            if (options)
                free(options);
            options = "";

            /* Aspect preprocessing can affect file paths that use word 'linux', since
             * there is the standard built-in macro '#define linux 1'. So undefine the
             * most of built-in macros by means of '-undef' (#865).
             * -nostdinc helps to avoid includes of system headers.
             * Keeps comments by means of option -C (#865).
             * Specify that aspect files "are" in C.
             */

            stage_post_opts_len = strlen(opts.aspect_preprocessing_opts) + strlen("-E -undef -nostdinc -C -x c ");
            stage_post_opts = malloc(stage_post_opts_len + 1);
            sprintf(stage_post_opts, "-E -undef -nostdinc -C -x c %s", opts.aspect_preprocessing_opts);

            free(out);
            out = aspect_preprocessed;

            aux_files.aspect_preprocessed = malloc(strlen(out) + 1);
            strcpy(aux_files.aspect_preprocessed, out);
        } else {
            /* Use preprocessed aspect at other stages. */
            free(aspect);
            aspect = aspect_preprocessed;

            /* At file preparation stage recommendations with 'file' pointucts are applied. */
            if (!strcmp(stages[i], "file preparation")) {
                /* Even though standard preprocessing won't be done but nevertheless
                 * specify that output should be a preprocessed file.
                 */
                stage_post_opts_len = strlen(opts.file_preparation_opts) + strlen("-E -x c ");
                stage_post_opts = malloc(stage_post_opts_len + 1);
                sprintf(stage_post_opts, "-E -x c %s", opts.file_preparation_opts);

                /* Use '.prepared' suffix for such kind of files. */
                free(out);
                out = malloc(strlen(aux_base) + strlen(".prepared") + 1);
                sprintf(out, "%s.prepared", aux_base);

                aux_files.file_prepared = malloc(strlen(out) + 1);
                strcpy(aux_files.file_prepared, out);
            }
            /* At macro instrumentation stage standard preprocessing will be done. */
            else if (!strcmp(stages[i], "macro instrumentation")) {
                char *in_copy = strdup(in);
                char *in_dirname = strdup(dirname(in_copy));

                /* TODO: remove this auxiliary search directory when will get rid of *.prepared files. */
                aux_search_dir = strdup(in_dirname);

                free(in_copy);
                free(in_dirname);

                /* Input file is prepared file. */
                free(in);
                in = malloc(strlen(aux_base) + strlen(".prepared") + 1);
                sprintf(in, "%s.prepared", aux_base);

                stage_pre_opts_len = strlen("-I \"\"") + strlen(aux_search_dir) ;
                stage_pre_opts = malloc(stage_pre_opts_len + 1);
                sprintf(stage_pre_opts, "-I \"%s\"", aux_search_dir);
                free(aux_search_dir);

                stage_post_opts_len = strlen(opts.macro_instrumentation_opts) + strlen("-E -x c ");
                stage_post_opts = malloc(stage_post_opts_len + 1);
                sprintf(stage_post_opts, "-E -x c %s", opts.macro_instrumentation_opts);

                /* Use '.macroinstrumented' suffix for macro instrumented files. */
                free(out);
                out = malloc(strlen(aux_base) + strlen(".macroinstrumented") + 1);
                sprintf(out, "%s.macroinstrumented", aux_base);

                aux_files.macro_instrumented = malloc(strlen(out) + 1);
                strcpy(aux_files.macro_instrumented, out);
            }
            /* At instrumentation stage auxiliary functions implementing recommendation
             * bodies and type declaration extensions required are performed.
             */
            else if (!strcmp(stages[i], "instrumentation")) {
                /* Input file is macro instrumented file. */
                free(in);
                in =malloc(strlen(aux_base)+strlen(".macroinstrumented") + 1);
                sprintf(in, "%s.macroinstrumented", aux_base);

                /* Stop after preprocessed file is parsed. */
                stage_post_opts_len =
                    strlen(opts.instrumentation_opts) + strlen("-fsyntax-only -x cpp-output ");
                stage_post_opts = malloc(stage_post_opts_len + 1);
                sprintf(stage_post_opts, "-fsyntax-only -x cpp-output %s", opts.instrumentation_opts);

                /* Use '.instrumented' suffix for instrumented files. */
                free(out);
                out = malloc(strlen(aux_base) + strlen(".instrumented") + 1);
                sprintf(out, "%s.instrumented", aux_base);

                aux_files.instrumented = malloc(strlen(out) + 1);
                strcpy(aux_files.instrumented, out);

                /* Print output using such the way instead of the standard one. */
                stage_envs_len = strlen("LDV_OUT=\"") + strlen(out) + strlen("\"");
                stage_envs = malloc(stage_envs_len + 1);
                sprintf(stage_envs, "LDV_OUT=\"%s\"", out);
            }
            /* At compilation stage auxiliary functions are related with original code
             * and some back-end is involved.
             */
            else if (!strcmp(stages[i], "compilation")) {
                /* Input file is instrumented file. */
                free(in);
                in = malloc(strlen(aux_base) + strlen(".instrumented") + 1);
                sprintf(in, "%s.instrumented", aux_base);

                /* Use specific options for corresponding back-ends. */
                if (!strcmp(opts.back_end, "asm")) {
                    stage_opts_specific = "-S";
                }
                else if (!strcmp(opts.back_end, "obj")) {
                    stage_opts_specific = "-c";
                }
                else if (!strcmp(opts.back_end, "src")) {
                    /* Stop asfter preprocessed file is parsed. */
                    stage_opts_specific = "-fsyntax-only";
                    /* Print output using such the way instead of the standard one. */
                    stage_envs_len = strlen("LDV_C_BACKEND_OUT=\"") + strlen(out) + strlen("\"");
                    stage_envs = malloc(stage_envs_len + 1);
                    sprintf(stage_envs, "LDV_C_BACKEND_OUT=\"%s\"", out);
                }
                stage_post_opts_len = strlen("-x c ") + strlen(stage_opts_specific)
                    + strlen(" ") + strlen(opts.compilation_opts);
                stage_post_opts = malloc(stage_post_opts_len + 1);
                sprintf(stage_post_opts,
                    "-x c %s %s", stage_opts_specific, opts.compilation_opts);

                /* Remove -include options since they cause repeating include of
                 * headers that may cause build failures, e.g. due to type
                 * redeclaration. Since it is the last stage, we can safely
                 * overwrite options. */
                if (options)
                    pch = strstr(options, "\"-include\"");
                else
                    pch = NULL;

                if (pch)
                {
                    char *new_options;
                    const char *cur_start;
                    int j;

                    /* Original string length will be enough since we are going
                     * to eclude some substrings from it. */
                    new_options = malloc(strlen(options) + 1);

                    /* Current start equals to beginning of former options. */
                    cur_start = options;
                    /* Current index of symbol within new options. */
                    j = 0;

                    while (1)
                    {
                        /* Copy characters between current start and pointer to
                         * start of -include. */
                        while (cur_start != pch)
                        {
                            new_options[j] = *cur_start;
                            cur_start++;
                            j++;
                        }

                        /* Skip -include and its mandatory value enclosed in
                         * quotes. 12 = strlen("\"-include\" \"") */
                        cur_start += 12;
                        pch = strstr(cur_start, "\"");

                        if (!pch)
                        {
                            fprintf(stderr, "Can't find double quote in '%s'.\n", cur_start);
                            exit(-1);
                        }

                        /* Move to next symbol after -include value. */
                        cur_start = pch + 1;

                        /* Proceed to next -include if so. */
                        pch = strstr(cur_start, "\"-include\"");

                        /* Finish. */
                        if (!pch)
                        {
                            /* Copy remaining general options. */
                            while (1)
                            {
                                new_options[j] = *cur_start;

                                if (*cur_start == '\0')
                                    break;

                                cur_start++;
                                j++;
                            }

                            break;
                        }
                    }

                    free(options);
                    options = new_options;
                }
            }
            /* At this stage input file is passed to C-backend. This likes back-end
             * 'src' for compilation stage.
             */
            else if (!strcmp(stages[i], "C-backend")) {
                /* Stop asfter preprocessed file is parsed. */
                stage_post_opts = " -fsyntax-only";
                /* Print output using such the way instead of the standard one. */
                stage_envs_len = strlen("LDV_C_BACKEND_OUT=\"") + strlen(out) + strlen("\"");
                stage_envs = malloc(stage_envs_len + 1);
                sprintf(stage_envs, "LDV_C_BACKEND_OUT=\"%s\"", out);
            }

        }

        if (!stage_envs) {
            stage_envs = "";
        }

        if (!options)
            options = "";

        if (strcmp(stages[i], "C-backend")) {
            /* Specify what stage should be performed. */
            /* Aspect file should be always specified to enable specific features of aspectator. */
            stage_envs_full_len = strlen("LDV_STAGE=") + sizeof(stage_id) + strlen(" ")
                + strlen("LDV_ASPECT_FILE=\"") + strlen(aspect) + strlen("\" ") + strlen(stage_envs);
            stage_envs_full = malloc(stage_envs_full_len + 1);
            sprintf(stage_envs_full, "LDV_STAGE=%d LDV_ASPECT_FILE=\"%s\" %s",
                stage_id, aspect, stage_envs);
        } else {
            stage_envs_full = stage_envs;
        }

        cmd_len =
            /* Stage specific environment variables. */
            strlen(stage_envs_full)
            /* CIF core executable. */
            + strlen(aspectator)
            /* Some options like "-I" should be placed ahead to have more priority. */
            + strlen(stage_pre_opts)
            /* Standard compilation (preprocesing) options. */
            + strlen(options)
            /* We wouldn't like to change original function calls
                with the gcc ones. So use -fno-builtin option for that purpose. */
            + strlen("-fno-builtin")
            /* Place all specific options at the end of other options to make them
                more of a priority. */
            + strlen(opts.general_opts)
            + strlen(stage_post_opts)
            /* File to be instrumented. */
            + strlen(in)
            /* Output file. */
            + strlen("-o")
            + strlen(out)
            /* Spaces. */
            + 11
            /* Double quotes. */
            + 4;
        cmd = malloc(cmd_len + 1);
        sprintf(cmd, "%s %s %s %s -fno-builtin %s %s \"%s\" -o \"%s\"", stage_envs_full, aspectator,
            stage_pre_opts, options, opts.general_opts, stage_post_opts, in, out);

        print_debug(DEBUG, "Execute '%s'.\n", cmd);

        ret = system(cmd);
        free(cmd);

        if (ret) {
            fprintf(stderr, "Aspectator failed at '%d' stage.\n", stage_id);
            /* Remove intermediate files obtained thus far if required. */
            clean();
            exit(WEXITSTATUS(ret));
        }

        /* Make some magic for aspect preprocessing stage. */
        if (!strcmp(stages[i], "aspect preprocessing")) {
            /* Replace '@' with '#' to return back standard preprocessing directives. */
            cmd_len = strlen("sed -i.bak 's/@/#/g' \"") + strlen(out) + strlen("\"");
            cmd = malloc(cmd_len + 1);
            sprintf(cmd, "sed -i.bak 's/@/#/g' \"%s\"", out);

            print_debug(DEBUG, "Execute '%s'.\n", cmd);

            ret = system(cmd);
            free(cmd);

            if (ret) {
                fprintf(stderr, "Aspectator failed at '%d' stage.\n", stage_id);
                /* Remove intermediate files obtained thus far if required. */
                clean();
                exit(WEXITSTATUS(ret));
            }
        }

        stage_id++;

        /* Cleanup. */
        if (strcmp(stages[i], "aspect preprocessing")) {
            free(in);
            free(out);
        }

        if (strcmp(stages[i], "C-backend")) {
            free(stage_envs_full);
            free(stage_post_opts);
        }

        if ((!strcmp(stages[i], "compilation") && !strcmp(opts.back_end, "src"))
            || !strcmp(stages[i], "instrumentation")
            || !strcmp(stages[i], "C-backend"))
        {
            free(stage_envs);
        }

        if (opts.aspect && !strcmp(stages[i], "aspect preprocessing"))
            free(aspect);

        if (strcmp(stage_pre_opts, ""))
            free(stage_pre_opts);
        if (strcmp(options, ""))
            free(options);
        free(aux_base);
        free(aspect_preprocessed);

        if (!strcmp(opts.stage, stages[i]))
            break;
    }

    /* Remove intermediate files if required. */
    clean();
}

static void print_debug(int level, const char *format, ...) {
    char format_with_prefix[LOG_PREFIX_SIZE + strlen(format)];
    va_list args;

    if (level <= opts.debug_level) {
        if (NORMAL == level) {
            strcpy(format_with_prefix, "CIF: NORMAL: ");
        }
        else if (DEBUG == level) {
            strcpy(format_with_prefix, "CIF: DEBUG: ");
        }

        strcat(format_with_prefix, format);

        if (level != QUIET) {
            va_start(args, format);
            vprintf(format_with_prefix, args);
            va_end(args);
        }
    }
}

static void clean(void) {
    /* Do not remove intermediate files this case. */
    if (opts.keep)
        return;

    /* Keep prepared files since error traces can reference them. */
    if (!opts.keep_prepared_file)
        unlink(aux_files.file_prepared);

    print_debug(DEBUG, "Remove intermediate files.\n");

    if (!stat(aux_files.aspect_preprocessed, &stat_buf))
        unlink(aux_files.aspect_preprocessed);

    if (!stat(aux_files.macro_instrumented, &stat_buf))
        unlink(aux_files.macro_instrumented);

    if (!stat(aux_files.instrumented, &stat_buf))
        unlink(aux_files.instrumented);
}

static void print_help(void) {
    fputs (("\
NAME\n\
  cif: instruments a file using an aspect and options\n\
    specified.\n\
\n\
SYNOPSIS\n\
  $cif [option...] [-- options_for_aspectator]\n\
\n\
OPTIONS\n\
\n\
  --aspect <file>\n\
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
    Debug <level> may be 'QUIET', 'NORMAL', 'DEBUG'\n\
    or 'ALL'. Each following level includes all messages of levels before it.\n\
\n\
  --file-preparation-opts <string>\n\
    Options specified by means of <string> will be passed as is at\n\
    'file preparation' stage.\n\
\n\
  --general-opts <string>\n\
    Options specified by means of <string> will be passed as is at all stages.\n\
\n\
  -h, --help\n\
    Print this help and exit with a syntax error.\n\
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
  options_for_aspectator\n\
    This is list of options that will be passed to aspectator as is. Note that\n\
    these options are processed by your interpreter before passing to CIF, so\n\
    don't forget about proper escaping.\n"), stdout);
}
