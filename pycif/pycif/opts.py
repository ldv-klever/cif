# Copyright (c) 2020 ISP RAS (http://www.ispras.ru)
# Ivannikov Institute for System Programming of the Russian Academy of Sciences
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import re

optimization_opts = [
    "-O",
    "-O1",
    "-O2",
    "-O3",
    "-O0",
    "-Os",
    "-Ofast",
    "-Og",
]

include_opts = [
    "-include",
    "-I",
    "-iquote",
    "-isystem",
    "-idirafter",
    "-imacros",
    "-isysroot",
]

require_value = include_opts + ["-D", "-U"]

required_opts = (
    ["-D", "-U", "-nostdinc", "-fshort-wchar", "-std"]
    + ["{}$".format(opt) for opt in optimization_opts]
    + include_opts
)

r_regex = re.compile("|".join(required_opts))


def filter_opts(opts):
    if not required_opts:
        return []

    filtered_opts = []

    opts = iter(opts)
    for opt in opts:
        if not r_regex.match(opt):
            continue

        filtered_opts.append(opt)

        if opt in require_value:
            filtered_opts.append(next(opts))

    return filtered_opts
