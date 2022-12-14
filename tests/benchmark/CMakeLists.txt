cmake_minimum_required(VERSION 3.20)
project("Lib_Bench")

set (BENCHMARK_ENABLE_GTEST_TESTS OFF)
set (BENCHMARK_ENABLE_TESTING OFF)

include(FetchContent)
FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
        )
FetchContent_Declare(googlebenchmark
                     GIT_REPOSITORY https://github.com/google/benchmark
                     GIT_TAG main
        )
FetchContent_MakeAvailable(googletest googlebenchmark)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
    main.cpp
)

target_link_libraries(${PROJECT_NAME} benchmark::benchmark)

target_compile_options(
  ${PROJECT_NAME}
  PRIVATE
    -O3)