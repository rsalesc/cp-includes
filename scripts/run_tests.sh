#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
pushd $DIR/../tests/unit
mkdir -p build && pushd build
cmake .. && cmake --build . && ./Lib_Unit
status=$?
popd
popd

exit $status