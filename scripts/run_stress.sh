#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
pushd $DIR/../tests/stress
mkdir -p build && pushd build
cmake .. && cmake --build . && ./Lib_Stress -r compact
popd
popd