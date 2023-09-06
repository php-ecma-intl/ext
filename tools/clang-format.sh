#!/usr/bin/env bash

###############################################################################
# clang-format-action
# https://github.com/jidicula/clang-format-action
#
# Copyright (c) 2021 Johanan Idicula <git@johanan.dev>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
###############################################################################
#                                entrypoint.sh                                #
###############################################################################
# USAGE: ./entrypoint.sh [<path>] [<fallback style>]
#
# Checks all C/C++/Protobuf/CUDA files (.h, .H, .hpp, .hh, .h++, .hxx and .c,
# .C, .cpp, .cc, .c++, .cxx, .proto, .cu) in the provided GitHub repository path
# (arg1) for conforming to clang-format. If no path is provided or provided path
# is not a directory, all C/C++/Protobuf/CUDA files are checked. If any files
# are incorrectly formatted, the script lists them and exits with 1.

tools_dir=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
cd "$tools_dir/.." || exit 2

clang_format="$(which clang-format)"
if [[ "$?" -ne 0 ]]; then
    clang_format="docker run --platform linux/amd64 -i -v $(pwd):$(pwd) -w $(pwd) --rm ghcr.io/jidicula/clang-format:16"
fi

APPLY="--dry-run"
if [[ "$1" == "apply" ]]; then
    APPLY="-i"
fi

# format_diff function
# Accepts a filepath argument. The filepath passed to this function must point
# to a C/C++/Protobuf/CUDA file.
format_diff() {
    local filepath="$1"

    # Invoke clang-format with dry run and formatting error output
    local local_format
    local_format=$(eval "$clang_format $APPLY --Werror --style=file --fallback-style=llvm $filepath")

    local format_status="$?"
    if [[ ${format_status} -ne 0 ]]; then
        echo "Failed on file: $filepath" >&2
        echo "$local_format" >&2
        exit_code=1 # flip the global exit code
        return "${format_status}"
    fi
    return 0
}

CHECK_PATH="src"
EXCLUDE_REGEX="^.*arginfo\\.h$"

# Find all C/C++/Protobuf/CUDA files:
#   h, H, hpp, hh, h++, hxx
#   c, C, cpp, cc, c++, cxx
#   ino, pde
#   proto
#   cu
INCLUDE_REGEX='^.*\.((((c|C)(c|pp|xx|\+\+)?$)|((h|H)h?(pp|xx|\+\+)?$))|(ino|pde|proto|cu))$'

# initialize exit code
exit_code=0

# All files improperly formatted will be printed to the output.
src_files=$(find "$CHECK_PATH" -name .git -prune -o -regextype posix-egrep -regex "$INCLUDE_REGEX" -print 2>&1)

if [[ "$?" -ne 0 ]] && [[ "$src_files" == *"regextype: unknown primary"* ]]; then
    # Use a find command that works on BSD variants.
    src_files=$(find -E "$CHECK_PATH" -name .git -prune -o -regex "$INCLUDE_REGEX" -print)
fi

# check formatting in each source file
IFS=$'\n' # Loop below should separate on new lines, not spaces.
for file in $src_files; do
    # Only check formatting if the path doesn't match the regex
    if ! [[ ${file} =~ $EXCLUDE_REGEX ]]; then
        format_diff "${file}"
    fi
done

# global exit code is flipped to nonzero if any invocation of `format_diff` has
# a formatting difference.
exit "$exit_code"
