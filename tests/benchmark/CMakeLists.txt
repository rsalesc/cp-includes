cmake_minimum_required(VERSION 3.12)
project("Lib_Bench")

set (BENCHMARK_ENABLE_INSTALL OFF)
set (BENCHMARK_ENABLE_GTEST_TESTS OFF)
set (BENCHMARK_ENABLE_TESTING OFF)

include(FetchContent)
FetchContent_Declare(googlebenchmark
                     GIT_REPOSITORY https://github.com/google/benchmark
        )
FetchContent_MakeAvailable(googlebenchmark)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
    main.cpp
)

target_link_libraries(${PROJECT_NAME} benchmark::benchmark)