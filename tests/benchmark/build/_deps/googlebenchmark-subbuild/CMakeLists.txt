# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.18.4)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(googlebenchmark-populate NONE)

include(ExternalProject)
ExternalProject_Add(googlebenchmark-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/google/benchmark"
                    SOURCE_DIR          "/home/roberto/CP/cp-includes/tests/benchmark/build/_deps/googlebenchmark-src"
                    BINARY_DIR          "/home/roberto/CP/cp-includes/tests/benchmark/build/_deps/googlebenchmark-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)


