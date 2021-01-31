#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
pushd $DIR/../tests/benchmark
mkdir -p build && pushd build
cmake .. -DCMAKE_BUILD_TYPE=Release && cmake --build . --config Release && ./Lib_Bench
status=$?
popd
popd

exit $status