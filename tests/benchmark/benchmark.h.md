---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tests/benchmark/PolynomialRing.cpp
    title: tests/benchmark/PolynomialRing.cpp
  - icon: ':warning:'
    path: tests/benchmark/PowerSeries.cpp
    title: tests/benchmark/PowerSeries.cpp
  - icon: ':warning:'
    path: tests/benchmark/bench.h
    title: tests/benchmark/bench.h
  - icon: ':warning:'
    path: tests/benchmark/main.cpp
    title: tests/benchmark/main.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://www.apache.org/licenses/LICENSE-2.0
    - https://youtu.be/nXaxk27zwlk?t=2441
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 289, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 188, in _get_uncommented_code\n    return subprocess.check_output(command)\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/subprocess.py\"\
    , line 420, in check_output\n    return run(*popenargs, stdout=PIPE, timeout=timeout,\
    \ check=True,\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/subprocess.py\"\
    , line 524, in run\n    raise CalledProcessError(retcode, process.args,\nsubprocess.CalledProcessError:\
    \ Command '['g++', '-x', 'c++', '-I', '/home/runner/work/cp-includes/cp-includes',\
    \ '-fpreprocessed', '-dD', '-E', '/home/runner/work/cp-includes/cp-includes/tests/benchmark/benchmark.h']'\
    \ returned non-zero exit status 1.\n"
  code: "// Copyright 2015 Google Inc. All rights reserved.\n//\n// Licensed under\
    \ the Apache License, Version 2.0 (the \"License\");\n// you may not use this\
    \ file except in compliance with the License.\n// You may obtain a copy of the\
    \ License at\n//\n//     http://www.apache.org/licenses/LICENSE-2.0\n//\n// Unless\
    \ required by applicable law or agreed to in writing, software\n// distributed\
    \ under the License is distributed on an \"AS IS\" BASIS,\n// WITHOUT WARRANTIES\
    \ OR CONDITIONS OF ANY KIND, either express or implied.\n// See the License for\
    \ the specific language governing permissions and\n// limitations under the License.\n\
    \n// Support for registering benchmarks for functions.\n\n/* Example usage:\n\
    // Define a function that executes the code to be measured a\n// specified number\
    \ of times:\nstatic void BM_StringCreation(benchmark::State& state) {\n  for (auto\
    \ _ : state)\n    std::string empty_string;\n}\n\n// Register the function as\
    \ a benchmark\nBENCHMARK(BM_StringCreation);\n\n// Define another benchmark\n\
    static void BM_StringCopy(benchmark::State& state) {\n  std::string x = \"hello\"\
    ;\n  for (auto _ : state)\n    std::string copy(x);\n}\nBENCHMARK(BM_StringCopy);\n\
    \n// Augment the main() program to invoke benchmarks if specified\n// via the\
    \ --benchmarks command line flag.  E.g.,\n//       my_unittest --benchmark_filter=all\n\
    //       my_unittest --benchmark_filter=BM_StringCreation\n//       my_unittest\
    \ --benchmark_filter=String\n//       my_unittest --benchmark_filter='Copy|Creation'\n\
    int main(int argc, char** argv) {\n  benchmark::Initialize(&argc, argv);\n  benchmark::RunSpecifiedBenchmarks();\n\
    \  return 0;\n}\n\n// Sometimes a family of microbenchmarks can be implemented\
    \ with\n// just one routine that takes an extra argument to specify which\n//\
    \ one of the family of benchmarks to run.  For example, the following\n// code\
    \ defines a family of microbenchmarks for measuring the speed\n// of memcpy()\
    \ calls of different lengths:\n\nstatic void BM_memcpy(benchmark::State& state)\
    \ {\n  char* src = new char[state.range(0)]; char* dst = new char[state.range(0)];\n\
    \  memset(src, 'x', state.range(0));\n  for (auto _ : state)\n    memcpy(dst,\
    \ src, state.range(0));\n  state.SetBytesProcessed(state.iterations() * state.range(0));\n\
    \  delete[] src; delete[] dst;\n}\nBENCHMARK(BM_memcpy)->Arg(8)->Arg(64)->Arg(512)->Arg(1<<10)->Arg(8<<10);\n\
    \n// The preceding code is quite repetitive, and can be replaced with the\n//\
    \ following short-hand.  The following invocation will pick a few\n// appropriate\
    \ arguments in the specified range and will generate a\n// microbenchmark for\
    \ each such argument.\nBENCHMARK(BM_memcpy)->Range(8, 8<<10);\n\n// You might\
    \ have a microbenchmark that depends on two inputs.  For\n// example, the following\
    \ code defines a family of microbenchmarks for\n// measuring the speed of set\
    \ insertion.\nstatic void BM_SetInsert(benchmark::State& state) {\n  set<int>\
    \ data;\n  for (auto _ : state) {\n    state.PauseTiming();\n    data = ConstructRandomSet(state.range(0));\n\
    \    state.ResumeTiming();\n    for (int j = 0; j < state.range(1); ++j)\n   \
    \   data.insert(RandomNumber());\n  }\n}\nBENCHMARK(BM_SetInsert)\n   ->Args({1<<10,\
    \ 128})\n   ->Args({2<<10, 128})\n   ->Args({4<<10, 128})\n   ->Args({8<<10, 128})\n\
    \   ->Args({1<<10, 512})\n   ->Args({2<<10, 512})\n   ->Args({4<<10, 512})\n \
    \  ->Args({8<<10, 512});\n\n// The preceding code is quite repetitive, and can\
    \ be replaced with\n// the following short-hand.  The following macro will pick\
    \ a few\n// appropriate arguments in the product of the two specified ranges\n\
    // and will generate a microbenchmark for each such pair.\nBENCHMARK(BM_SetInsert)->Ranges({{1<<10,\
    \ 8<<10}, {128, 512}});\n\n// For more complex patterns of inputs, passing a custom\
    \ function\n// to Apply allows programmatic specification of an\n// arbitrary\
    \ set of arguments to run the microbenchmark on.\n// The following example enumerates\
    \ a dense range on\n// one parameter, and a sparse range on the second.\nstatic\
    \ void CustomArguments(benchmark::internal::Benchmark* b) {\n  for (int i = 0;\
    \ i <= 10; ++i)\n    for (int j = 32; j <= 1024*1024; j *= 8)\n      b->Args({i,\
    \ j});\n}\nBENCHMARK(BM_SetInsert)->Apply(CustomArguments);\n\n// Templated microbenchmarks\
    \ work the same way:\n// Produce then consume 'size' messages 'iters' times\n\
    // Measures throughput in the absence of multiprogramming.\ntemplate <class Q>\
    \ int BM_Sequential(benchmark::State& state) {\n  Q q;\n  typename Q::value_type\
    \ v;\n  for (auto _ : state) {\n    for (int i = state.range(0); i--; )\n    \
    \  q.push(v);\n    for (int e = state.range(0); e--; )\n      q.Wait(&v);\n  }\n\
    \  // actually messages, not bytes:\n  state.SetBytesProcessed(state.iterations()\
    \ * state.range(0));\n}\nBENCHMARK_TEMPLATE(BM_Sequential, WaitQueue<int>)->Range(1<<0,\
    \ 1<<10);\n\nUse `Benchmark::MinTime(double t)` to set the minimum time used to\
    \ run the\nbenchmark. This option overrides the `benchmark_min_time` flag.\n\n\
    void BM_test(benchmark::State& state) {\n ... body ...\n}\nBENCHMARK(BM_test)->MinTime(2.0);\
    \ // Run for at least 2 seconds.\n\nIn a multithreaded test, it is guaranteed\
    \ that none of the threads will start\nuntil all have reached the loop start,\
    \ and all will have finished before any\nthread exits the loop body. As such,\
    \ any global setup or teardown you want to\ndo can be wrapped in a check against\
    \ the thread index:\n\nstatic void BM_MultiThreaded(benchmark::State& state) {\n\
    \  if (state.thread_index == 0) {\n    // Setup code here.\n  }\n  for (auto _\
    \ : state) {\n    // Run the test as normal.\n  }\n  if (state.thread_index ==\
    \ 0) {\n    // Teardown code here.\n  }\n}\nBENCHMARK(BM_MultiThreaded)->Threads(4);\n\
    \n\nIf a benchmark runs a few milliseconds it may be hard to visually compare\
    \ the\nmeasured times, since the output data is given in nanoseconds per default.\
    \ In\norder to manually set the time unit, you can specify it manually:\n\nBENCHMARK(BM_test)->Unit(benchmark::kMillisecond);\n\
    */\n\n#ifndef BENCHMARK_BENCHMARK_H_\n#define BENCHMARK_BENCHMARK_H_\n\n// The\
    \ _MSVC_LANG check should detect Visual Studio 2015 Update 3 and newer.\n#if __cplusplus\
    \ >= 201103L || (defined(_MSVC_LANG) && _MSVC_LANG >= 201103L)\n#define BENCHMARK_HAS_CXX11\n\
    #endif\n\n#include <stdint.h>\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <cstddef>\n#include <iosfwd>\n#include <map>\n#include <set>\n#include <string>\n\
    #include <utility>\n#include <vector>\n\n#if defined(BENCHMARK_HAS_CXX11)\n#include\
    \ <initializer_list>\n#include <type_traits>\n#include <utility>\n#endif\n\n#if\
    \ defined(_MSC_VER)\n#include <intrin.h>  // for _ReadWriteBarrier\n#endif\n\n\
    #ifndef BENCHMARK_HAS_CXX11\n#define BENCHMARK_DISALLOW_COPY_AND_ASSIGN(TypeName)\
    \ \\\n  TypeName(const TypeName&);                         \\\n  TypeName& operator=(const\
    \ TypeName&)\n#else\n#define BENCHMARK_DISALLOW_COPY_AND_ASSIGN(TypeName) \\\n\
    \  TypeName(const TypeName&) = delete;                \\\n  TypeName& operator=(const\
    \ TypeName&) = delete\n#endif\n\n#if defined(__GNUC__)\n#define BENCHMARK_UNUSED\
    \ __attribute__((unused))\n#define BENCHMARK_ALWAYS_INLINE __attribute__((always_inline))\n\
    #define BENCHMARK_NOEXCEPT noexcept\n#define BENCHMARK_NOEXCEPT_OP(x) noexcept(x)\n\
    #elif defined(_MSC_VER) && !defined(__clang__)\n#define BENCHMARK_UNUSED\n#define\
    \ BENCHMARK_ALWAYS_INLINE __forceinline\n#if _MSC_VER >= 1900\n#define BENCHMARK_NOEXCEPT\
    \ noexcept\n#define BENCHMARK_NOEXCEPT_OP(x) noexcept(x)\n#else\n#define BENCHMARK_NOEXCEPT\n\
    #define BENCHMARK_NOEXCEPT_OP(x)\n#endif\n#define __func__ __FUNCTION__\n#else\n\
    #define BENCHMARK_UNUSED\n#define BENCHMARK_ALWAYS_INLINE\n#define BENCHMARK_NOEXCEPT\n\
    #define BENCHMARK_NOEXCEPT_OP(x)\n#endif\n\n#define BENCHMARK_INTERNAL_TOSTRING2(x)\
    \ #x\n#define BENCHMARK_INTERNAL_TOSTRING(x) BENCHMARK_INTERNAL_TOSTRING2(x)\n\
    \n#if defined(__GNUC__) || defined(__clang__)\n#define BENCHMARK_BUILTIN_EXPECT(x,\
    \ y) __builtin_expect(x, y)\n#define BENCHMARK_DEPRECATED_MSG(msg) __attribute__((deprecated(msg)))\n\
    #else\n#define BENCHMARK_BUILTIN_EXPECT(x, y) x\n#define BENCHMARK_DEPRECATED_MSG(msg)\n\
    #define BENCHMARK_WARNING_MSG(msg)                           \\\n  __pragma(message(__FILE__\
    \ \"(\" BENCHMARK_INTERNAL_TOSTRING( \\\n      __LINE__) \") : warning note: \"\
    \ msg))\n#endif\n\n#if defined(__GNUC__) && !defined(__clang__)\n#define BENCHMARK_GCC_VERSION\
    \ (__GNUC__ * 100 + __GNUC_MINOR__)\n#endif\n\n#ifndef __has_builtin\n#define\
    \ __has_builtin(x) 0\n#endif\n\n#if defined(__GNUC__) || __has_builtin(__builtin_unreachable)\n\
    #define BENCHMARK_UNREACHABLE() __builtin_unreachable()\n#elif defined(_MSC_VER)\n\
    #define BENCHMARK_UNREACHABLE() __assume(false)\n#else\n#define BENCHMARK_UNREACHABLE()\
    \ ((void)0)\n#endif\n\nnamespace benchmark {\nclass BenchmarkReporter;\nclass\
    \ MemoryManager;\n\nvoid Initialize(int* argc, char** argv);\n\n// Report to stdout\
    \ all arguments in 'argv' as unrecognized except the first.\n// Returns true there\
    \ is at least on unrecognized argument (i.e. 'argc' > 1).\nbool ReportUnrecognizedArguments(int\
    \ argc, char** argv);\n\n// Generate a list of benchmarks matching the specified\
    \ --benchmark_filter flag\n// and if --benchmark_list_tests is specified return\
    \ after printing the name\n// of each matching benchmark. Otherwise run each matching\
    \ benchmark and\n// report the results.\n//\n// The second and third overload\
    \ use the specified 'display_reporter' and\n//  'file_reporter' respectively.\
    \ 'file_reporter' will write to the file\n//  specified\n//   by '--benchmark_output'.\
    \ If '--benchmark_output' is not given the\n//  'file_reporter' is ignored.\n\
    //\n// RETURNS: The number of matching benchmarks.\nsize_t RunSpecifiedBenchmarks();\n\
    size_t RunSpecifiedBenchmarks(BenchmarkReporter* display_reporter);\nsize_t RunSpecifiedBenchmarks(BenchmarkReporter*\
    \ display_reporter,\n                              BenchmarkReporter* file_reporter);\n\
    \n// Register a MemoryManager instance that will be used to collect and report\n\
    // allocation measurements for benchmark runs.\nvoid RegisterMemoryManager(MemoryManager*\
    \ memory_manager);\n\nnamespace internal {\nclass Benchmark;\nclass BenchmarkImp;\n\
    class BenchmarkFamilies;\n\nvoid UseCharPointer(char const volatile*);\n\n// Take\
    \ ownership of the pointer and register the benchmark. Return the\n// registered\
    \ benchmark.\nBenchmark* RegisterBenchmarkInternal(Benchmark*);\n\n// Ensure that\
    \ the standard streams are properly initialized in every TU.\nint InitializeStreams();\n\
    BENCHMARK_UNUSED static int stream_init_anchor = InitializeStreams();\n\n}  //\
    \ namespace internal\n\n#if (!defined(__GNUC__) && !defined(__clang__)) || defined(__pnacl__)\
    \ || \\\n    defined(__EMSCRIPTEN__)\n#define BENCHMARK_HAS_NO_INLINE_ASSEMBLY\n\
    #endif\n\n// The DoNotOptimize(...) function can be used to prevent a value or\n\
    // expression from being optimized away by the compiler. This function is\n//\
    \ intended to add little to no overhead.\n// See: https://youtu.be/nXaxk27zwlk?t=2441\n\
    #ifndef BENCHMARK_HAS_NO_INLINE_ASSEMBLY\ntemplate <class Tp>\ninline BENCHMARK_ALWAYS_INLINE\
    \ void DoNotOptimize(Tp const& value) {\n  asm volatile(\"\" : : \"r,m\"(value)\
    \ : \"memory\");\n}\n\ntemplate <class Tp>\ninline BENCHMARK_ALWAYS_INLINE void\
    \ DoNotOptimize(Tp& value) {\n#if defined(__clang__)\n  asm volatile(\"\" : \"\
    +r,m\"(value) : : \"memory\");\n#else\n  asm volatile(\"\" : \"+m,r\"(value) :\
    \ : \"memory\");\n#endif\n}\n\n// Force the compiler to flush pending writes to\
    \ global memory. Acts as an\n// effective read/write barrier\ninline BENCHMARK_ALWAYS_INLINE\
    \ void ClobberMemory() {\n  asm volatile(\"\" : : : \"memory\");\n}\n#elif defined(_MSC_VER)\n\
    template <class Tp>\ninline BENCHMARK_ALWAYS_INLINE void DoNotOptimize(Tp const&\
    \ value) {\n  internal::UseCharPointer(&reinterpret_cast<char const volatile&>(value));\n\
    \  _ReadWriteBarrier();\n}\n\ninline BENCHMARK_ALWAYS_INLINE void ClobberMemory()\
    \ { _ReadWriteBarrier(); }\n#else\ntemplate <class Tp>\ninline BENCHMARK_ALWAYS_INLINE\
    \ void DoNotOptimize(Tp const& value) {\n  internal::UseCharPointer(&reinterpret_cast<char\
    \ const volatile&>(value));\n}\n// FIXME Add ClobberMemory() for non-gnu and non-msvc\
    \ compilers\n#endif\n\n// This class is used for user-defined counters.\nclass\
    \ Counter {\n public:\n  enum Flags {\n    kDefaults = 0,\n    // Mark the counter\
    \ as a rate. It will be presented divided\n    // by the duration of the benchmark.\n\
    \    kIsRate = 1U << 0U,\n    // Mark the counter as a thread-average quantity.\
    \ It will be\n    // presented divided by the number of threads.\n    kAvgThreads\
    \ = 1U << 1U,\n    // Mark the counter as a thread-average rate. See above.\n\
    \    kAvgThreadsRate = kIsRate | kAvgThreads,\n    // Mark the counter as a constant\
    \ value, valid/same for *every* iteration.\n    // When reporting, it will be\
    \ *multiplied* by the iteration count.\n    kIsIterationInvariant = 1U << 2U,\n\
    \    // Mark the counter as a constant rate.\n    // When reporting, it will be\
    \ *multiplied* by the iteration count\n    // and then divided by the duration\
    \ of the benchmark.\n    kIsIterationInvariantRate = kIsRate | kIsIterationInvariant,\n\
    \    // Mark the counter as a iteration-average quantity.\n    // It will be presented\
    \ divided by the number of iterations.\n    kAvgIterations = 1U << 3U,\n    //\
    \ Mark the counter as a iteration-average rate. See above.\n    kAvgIterationsRate\
    \ = kIsRate | kAvgIterations,\n\n    // In the end, invert the result. This is\
    \ always done last!\n    kInvert = 1U << 31U\n  };\n\n  enum OneK {\n    // 1'000\
    \ items per 1k\n    kIs1000 = 1000,\n    // 1'024 items per 1k\n    kIs1024 =\
    \ 1024\n  };\n\n  double value;\n  Flags flags;\n  OneK oneK;\n\n  BENCHMARK_ALWAYS_INLINE\n\
    \  Counter(double v = 0., Flags f = kDefaults, OneK k = kIs1000)\n      : value(v),\
    \ flags(f), oneK(k) {}\n\n  BENCHMARK_ALWAYS_INLINE operator double const&() const\
    \ { return value; }\n  BENCHMARK_ALWAYS_INLINE operator double&() { return value;\
    \ }\n};\n\n// A helper for user code to create unforeseen combinations of Flags,\
    \ without\n// having to do this cast manually each time, or providing this operator.\n\
    Counter::Flags inline operator|(const Counter::Flags& LHS,\n                 \
    \               const Counter::Flags& RHS) {\n  return static_cast<Counter::Flags>(static_cast<int>(LHS)\
    \ |\n                                     static_cast<int>(RHS));\n}\n\n// This\
    \ is the container for the user-defined counters.\ntypedef std::map<std::string,\
    \ Counter> UserCounters;\n\n// TimeUnit is passed to a benchmark in order to specify\
    \ the order of magnitude\n// for the measured time.\nenum TimeUnit { kNanosecond,\
    \ kMicrosecond, kMillisecond };\n\n// BigO is passed to a benchmark in order to\
    \ specify the asymptotic\n// computational\n// complexity for the benchmark. In\
    \ case oAuto is selected, complexity will be\n// calculated automatically to the\
    \ best fit.\nenum BigO { oNone, o1, oN, oNSquared, oNCubed, oLogN, oNLogN, oAuto,\
    \ oLambda };\n\ntypedef uint64_t IterationCount;\n\n// BigOFunc is passed to a\
    \ benchmark in order to specify the asymptotic\n// computational complexity for\
    \ the benchmark.\ntypedef double(BigOFunc)(IterationCount);\n\n// StatisticsFunc\
    \ is passed to a benchmark in order to compute some descriptive\n// statistics\
    \ over all the measurements of some type\ntypedef double(StatisticsFunc)(const\
    \ std::vector<double>&);\n\nnamespace internal {\nstruct Statistics {\n  std::string\
    \ name_;\n  StatisticsFunc* compute_;\n\n  Statistics(const std::string& name,\
    \ StatisticsFunc* compute)\n      : name_(name), compute_(compute) {}\n};\n\n\
    struct BenchmarkInstance;\nclass ThreadTimer;\nclass ThreadManager;\n\nenum AggregationReportMode\n\
    #if defined(BENCHMARK_HAS_CXX11)\n    : unsigned\n#else\n#endif\n{\n  // The mode\
    \ has not been manually specified\n  ARM_Unspecified = 0,\n  // The mode is user-specified.\n\
    \  // This may or may not be set when the following bit-flags are set.\n  ARM_Default\
    \ = 1U << 0U,\n  // File reporter should only output aggregates.\n  ARM_FileReportAggregatesOnly\
    \ = 1U << 1U,\n  // Display reporter should only output aggregates\n  ARM_DisplayReportAggregatesOnly\
    \ = 1U << 2U,\n  // Both reporters should only display aggregates.\n  ARM_ReportAggregatesOnly\
    \ =\n      ARM_FileReportAggregatesOnly | ARM_DisplayReportAggregatesOnly\n};\n\
    \n}  // namespace internal\n\n// State is passed to a running Benchmark and contains\
    \ state for the\n// benchmark to use.\nclass State {\n public:\n  struct StateIterator;\n\
    \  friend struct StateIterator;\n\n  // Returns iterators used to run each iteration\
    \ of a benchmark using a\n  // C++11 ranged-based for loop. These functions should\
    \ not be called directly.\n  //\n  // REQUIRES: The benchmark has not started\
    \ running yet. Neither begin nor end\n  // have been called previously.\n  //\n\
    \  // NOTE: KeepRunning may not be used after calling either of these functions.\n\
    \  BENCHMARK_ALWAYS_INLINE StateIterator begin();\n  BENCHMARK_ALWAYS_INLINE StateIterator\
    \ end();\n\n  // Returns true if the benchmark should continue through another\
    \ iteration.\n  // NOTE: A benchmark may not return from the test until KeepRunning()\
    \ has\n  // returned false.\n  bool KeepRunning();\n\n  // Returns true iff the\
    \ benchmark should run n more iterations.\n  // REQUIRES: 'n' > 0.\n  // NOTE:\
    \ A benchmark must not return from the test until KeepRunningBatch()\n  // has\
    \ returned false.\n  // NOTE: KeepRunningBatch() may overshoot by up to 'n' iterations.\n\
    \  //\n  // Intended usage:\n  //   while (state.KeepRunningBatch(1000)) {\n \
    \ //     // process 1000 elements\n  //   }\n  bool KeepRunningBatch(IterationCount\
    \ n);\n\n  // REQUIRES: timer is running and 'SkipWithError(...)' has not been\
    \ called\n  //           by the current thread.\n  // Stop the benchmark timer.\
    \  If not called, the timer will be\n  // automatically stopped after the last\
    \ iteration of the benchmark loop.\n  //\n  // For threaded benchmarks the PauseTiming()\
    \ function only pauses the timing\n  // for the current thread.\n  //\n  // NOTE:\
    \ The \"real time\" measurement is per-thread. If different threads\n  // report\
    \ different measurements the largest one is reported.\n  //\n  // NOTE: PauseTiming()/ResumeTiming()\
    \ are relatively\n  // heavyweight, and so their use should generally be avoided\n\
    \  // within each benchmark iteration, if possible.\n  void PauseTiming();\n\n\
    \  // REQUIRES: timer is not running and 'SkipWithError(...)' has not been called\n\
    \  //           by the current thread.\n  // Start the benchmark timer.  The timer\
    \ is NOT running on entrance to the\n  // benchmark function. It begins running\
    \ after control flow enters the\n  // benchmark loop.\n  //\n  // NOTE: PauseTiming()/ResumeTiming()\
    \ are relatively\n  // heavyweight, and so their use should generally be avoided\n\
    \  // within each benchmark iteration, if possible.\n  void ResumeTiming();\n\n\
    \  // REQUIRES: 'SkipWithError(...)' has not been called previously by the\n \
    \ //            current thread.\n  // Report the benchmark as resulting in an\
    \ error with the specified 'msg'.\n  // After this call the user may explicitly\
    \ 'return' from the benchmark.\n  //\n  // If the ranged-for style of benchmark\
    \ loop is used, the user must explicitly\n  // break from the loop, otherwise\
    \ all future iterations will be run.\n  // If the 'KeepRunning()' loop is used\
    \ the current thread will automatically\n  // exit the loop at the end of the\
    \ current iteration.\n  //\n  // For threaded benchmarks only the current thread\
    \ stops executing and future\n  // calls to `KeepRunning()` will block until all\
    \ threads have completed\n  // the `KeepRunning()` loop. If multiple threads report\
    \ an error only the\n  // first error message is used.\n  //\n  // NOTE: Calling\
    \ 'SkipWithError(...)' does not cause the benchmark to exit\n  // the current\
    \ scope immediately. If the function is called from within\n  // the 'KeepRunning()'\
    \ loop the current iteration will finish. It is the users\n  // responsibility\
    \ to exit the scope as needed.\n  void SkipWithError(const char* msg);\n\n  //\
    \ Returns true if an error has been reported with 'SkipWithError(...)'.\n  bool\
    \ error_occurred() const { return error_occurred_; }\n\n  // REQUIRES: called\
    \ exactly once per iteration of the benchmarking loop.\n  // Set the manually\
    \ measured time for this benchmark iteration, which\n  // is used instead of automatically\
    \ measured time if UseManualTime() was\n  // specified.\n  //\n  // For threaded\
    \ benchmarks the final value will be set to the largest\n  // reported values.\n\
    \  void SetIterationTime(double seconds);\n\n  // Set the number of bytes processed\
    \ by the current benchmark\n  // execution.  This routine is typically called\
    \ once at the end of a\n  // throughput oriented benchmark.\n  //\n  // REQUIRES:\
    \ a benchmark has exited its benchmarking loop.\n  BENCHMARK_ALWAYS_INLINE\n \
    \ void SetBytesProcessed(int64_t bytes) {\n    counters[\"bytes_per_second\"]\
    \ =\n        Counter(static_cast<double>(bytes), Counter::kIsRate, Counter::kIs1024);\n\
    \  }\n\n  BENCHMARK_ALWAYS_INLINE\n  int64_t bytes_processed() const {\n    if\
    \ (counters.find(\"bytes_per_second\") != counters.end())\n      return static_cast<int64_t>(counters.at(\"\
    bytes_per_second\"));\n    return 0;\n  }\n\n  // If this routine is called with\
    \ complexity_n > 0 and complexity report is\n  // requested for the\n  // family\
    \ benchmark, then current benchmark will be part of the computation\n  // and\
    \ complexity_n will\n  // represent the length of N.\n  BENCHMARK_ALWAYS_INLINE\n\
    \  void SetComplexityN(int64_t complexity_n) { complexity_n_ = complexity_n; }\n\
    \n  BENCHMARK_ALWAYS_INLINE\n  int64_t complexity_length_n() const { return complexity_n_;\
    \ }\n\n  // If this routine is called with items > 0, then an items/s\n  // label\
    \ is printed on the benchmark report line for the currently\n  // executing benchmark.\
    \ It is typically called at the end of a processing\n  // benchmark where a processing\
    \ items/second output is desired.\n  //\n  // REQUIRES: a benchmark has exited\
    \ its benchmarking loop.\n  BENCHMARK_ALWAYS_INLINE\n  void SetItemsProcessed(int64_t\
    \ items) {\n    counters[\"items_per_second\"] =\n        Counter(static_cast<double>(items),\
    \ benchmark::Counter::kIsRate);\n  }\n\n  BENCHMARK_ALWAYS_INLINE\n  int64_t items_processed()\
    \ const {\n    if (counters.find(\"items_per_second\") != counters.end())\n  \
    \    return static_cast<int64_t>(counters.at(\"items_per_second\"));\n    return\
    \ 0;\n  }\n\n  // If this routine is called, the specified label is printed at\
    \ the\n  // end of the benchmark report line for the currently executing\n  //\
    \ benchmark.  Example:\n  //  static void BM_Compress(benchmark::State& state)\
    \ {\n  //    ...\n  //    double compress = input_size / output_size;\n  //  \
    \  state.SetLabel(StrFormat(\"compress:%.1f%%\", 100.0*compression));\n  //  }\n\
    \  // Produces output that looks like:\n  //  BM_Compress   50         50   14115038\
    \  compress:27.3%\n  //\n  // REQUIRES: a benchmark has exited its benchmarking\
    \ loop.\n  void SetLabel(const char* label);\n\n  void BENCHMARK_ALWAYS_INLINE\
    \ SetLabel(const std::string& str) {\n    this->SetLabel(str.c_str());\n  }\n\n\
    \  // Range arguments for this run. CHECKs if the argument has been set.\n  BENCHMARK_ALWAYS_INLINE\n\
    \  int64_t range(std::size_t pos = 0) const {\n    assert(range_.size() > pos);\n\
    \    return range_[pos];\n  }\n\n  BENCHMARK_DEPRECATED_MSG(\"use 'range(0)' instead\"\
    )\n  int64_t range_x() const { return range(0); }\n\n  BENCHMARK_DEPRECATED_MSG(\"\
    use 'range(1)' instead\")\n  int64_t range_y() const { return range(1); }\n\n\
    \  BENCHMARK_ALWAYS_INLINE\n  IterationCount iterations() const {\n    if (BENCHMARK_BUILTIN_EXPECT(!started_,\
    \ false)) {\n      return 0;\n    }\n    return max_iterations - total_iterations_\
    \ + batch_leftover_;\n  }\n\n private\n     :  // items we expect on the first\
    \ cache line (ie 64 bytes of the struct)\n  // When total_iterations_ is 0, KeepRunning()\
    \ and friends will return false.\n  // May be larger than max_iterations.\n  IterationCount\
    \ total_iterations_;\n\n  // When using KeepRunningBatch(), batch_leftover_ holds\
    \ the number of\n  // iterations beyond max_iters that were run. Used to track\n\
    \  // completed_iterations_ accurately.\n  IterationCount batch_leftover_;\n\n\
    \ public:\n  const IterationCount max_iterations;\n\n private:\n  bool started_;\n\
    \  bool finished_;\n  bool error_occurred_;\n\n private:  // items we don't need\
    \ on the first cache line\n  std::vector<int64_t> range_;\n\n  int64_t complexity_n_;\n\
    \n public:\n  // Container for user-defined counters.\n  UserCounters counters;\n\
    \  // Index of the executing thread. Values from [0, threads).\n  const int thread_index;\n\
    \  // Number of threads concurrently executing the benchmark.\n  const int threads;\n\
    \n private:\n  State(IterationCount max_iters, const std::vector<int64_t>& ranges,\n\
    \        int thread_i, int n_threads, internal::ThreadTimer* timer,\n        internal::ThreadManager*\
    \ manager);\n\n  void StartKeepRunning();\n  // Implementation of KeepRunning()\
    \ and KeepRunningBatch().\n  // is_batch must be true unless n is 1.\n  bool KeepRunningInternal(IterationCount\
    \ n, bool is_batch);\n  void FinishKeepRunning();\n  internal::ThreadTimer* timer_;\n\
    \  internal::ThreadManager* manager_;\n\n  friend struct internal::BenchmarkInstance;\n\
    };\n\ninline BENCHMARK_ALWAYS_INLINE bool State::KeepRunning() {\n  return KeepRunningInternal(1,\
    \ /*is_batch=*/false);\n}\n\ninline BENCHMARK_ALWAYS_INLINE bool State::KeepRunningBatch(IterationCount\
    \ n) {\n  return KeepRunningInternal(n, /*is_batch=*/true);\n}\n\ninline BENCHMARK_ALWAYS_INLINE\
    \ bool State::KeepRunningInternal(IterationCount n,\n                        \
    \                                       bool is_batch) {\n  // total_iterations_\
    \ is set to 0 by the constructor, and always set to a\n  // nonzero value by StartKepRunning().\n\
    \  assert(n > 0);\n  // n must be 1 unless is_batch is true.\n  assert(is_batch\
    \ || n == 1);\n  if (BENCHMARK_BUILTIN_EXPECT(total_iterations_ >= n, true)) {\n\
    \    total_iterations_ -= n;\n    return true;\n  }\n  if (!started_) {\n    StartKeepRunning();\n\
    \    if (!error_occurred_ && total_iterations_ >= n) {\n      total_iterations_\
    \ -= n;\n      return true;\n    }\n  }\n  // For non-batch runs, total_iterations_\
    \ must be 0 by now.\n  if (is_batch && total_iterations_ != 0) {\n    batch_leftover_\
    \ = n - total_iterations_;\n    total_iterations_ = 0;\n    return true;\n  }\n\
    \  FinishKeepRunning();\n  return false;\n}\n\nstruct State::StateIterator {\n\
    \  struct BENCHMARK_UNUSED Value {};\n  typedef std::forward_iterator_tag iterator_category;\n\
    \  typedef Value value_type;\n  typedef Value reference;\n  typedef Value pointer;\n\
    \  typedef std::ptrdiff_t difference_type;\n\n private:\n  friend class State;\n\
    \  BENCHMARK_ALWAYS_INLINE\n  StateIterator() : cached_(0), parent_() {}\n\n \
    \ BENCHMARK_ALWAYS_INLINE\n  explicit StateIterator(State* st)\n      : cached_(st->error_occurred_\
    \ ? 0 : st->max_iterations), parent_(st) {}\n\n public:\n  BENCHMARK_ALWAYS_INLINE\n\
    \  Value operator*() const { return Value(); }\n\n  BENCHMARK_ALWAYS_INLINE\n\
    \  StateIterator& operator++() {\n    assert(cached_ > 0);\n    --cached_;\n \
    \   return *this;\n  }\n\n  BENCHMARK_ALWAYS_INLINE\n  bool operator!=(StateIterator\
    \ const&) const {\n    if (BENCHMARK_BUILTIN_EXPECT(cached_ != 0, true)) return\
    \ true;\n    parent_->FinishKeepRunning();\n    return false;\n  }\n\n private:\n\
    \  IterationCount cached_;\n  State* const parent_;\n};\n\ninline BENCHMARK_ALWAYS_INLINE\
    \ State::StateIterator State::begin() {\n  return StateIterator(this);\n}\ninline\
    \ BENCHMARK_ALWAYS_INLINE State::StateIterator State::end() {\n  StartKeepRunning();\n\
    \  return StateIterator();\n}\n\nnamespace internal {\n\ntypedef void(Function)(State&);\n\
    \n// ------------------------------------------------------\n// Benchmark registration\
    \ object.  The BENCHMARK() macro expands\n// into an internal::Benchmark* object.\
    \  Various methods can\n// be called on this object to change the properties of\
    \ the benchmark.\n// Each method returns \"this\" so that multiple method calls\
    \ can\n// chained into one expression.\nclass Benchmark {\n public:\n  virtual\
    \ ~Benchmark();\n\n  // Note: the following methods all return \"this\" so that\
    \ multiple\n  // method calls can be chained together in one expression.\n\n \
    \ // Run this benchmark once with \"x\" as the extra argument passed\n  // to\
    \ the function.\n  // REQUIRES: The function passed to the constructor must accept\
    \ an arg1.\n  Benchmark* Arg(int64_t x);\n\n  // Run this benchmark with the given\
    \ time unit for the generated output report\n  Benchmark* Unit(TimeUnit unit);\n\
    \n  // Run this benchmark once for a number of values picked from the\n  // range\
    \ [start..limit].  (start and limit are always picked.)\n  // REQUIRES: The function\
    \ passed to the constructor must accept an arg1.\n  Benchmark* Range(int64_t start,\
    \ int64_t limit);\n\n  // Run this benchmark once for all values in the range\
    \ [start..limit] with\n  // specific step\n  // REQUIRES: The function passed\
    \ to the constructor must accept an arg1.\n  Benchmark* DenseRange(int64_t start,\
    \ int64_t limit, int step = 1);\n\n  // Run this benchmark once with \"args\"\
    \ as the extra arguments passed\n  // to the function.\n  // REQUIRES: The function\
    \ passed to the constructor must accept arg1, arg2 ...\n  Benchmark* Args(const\
    \ std::vector<int64_t>& args);\n\n  // Equivalent to Args({x, y})\n  // NOTE:\
    \ This is a legacy C++03 interface provided for compatibility only.\n  //   New\
    \ code should use 'Args'.\n  Benchmark* ArgPair(int64_t x, int64_t y) {\n    std::vector<int64_t>\
    \ args;\n    args.push_back(x);\n    args.push_back(y);\n    return Args(args);\n\
    \  }\n\n  // Run this benchmark once for a number of values picked from the\n\
    \  // ranges [start..limit].  (starts and limits are always picked.)\n  // REQUIRES:\
    \ The function passed to the constructor must accept arg1, arg2 ...\n  Benchmark*\
    \ Ranges(const std::vector<std::pair<int64_t, int64_t> >& ranges);\n\n  // Run\
    \ this benchmark once for each combination of values in the (cartesian)\n  //\
    \ product of the supplied argument lists.\n  // REQUIRES: The function passed\
    \ to the constructor must accept arg1, arg2 ...\n  Benchmark* ArgsProduct(const\
    \ std::vector<std::vector<int64_t> >& arglists);\n\n  // Equivalent to ArgNames({name})\n\
    \  Benchmark* ArgName(const std::string& name);\n\n  // Set the argument names\
    \ to display in the benchmark name. If not called,\n  // only argument values\
    \ will be shown.\n  Benchmark* ArgNames(const std::vector<std::string>& names);\n\
    \n  // Equivalent to Ranges({{lo1, hi1}, {lo2, hi2}}).\n  // NOTE: This is a legacy\
    \ C++03 interface provided for compatibility only.\n  //   New code should use\
    \ 'Ranges'.\n  Benchmark* RangePair(int64_t lo1, int64_t hi1, int64_t lo2, int64_t\
    \ hi2) {\n    std::vector<std::pair<int64_t, int64_t> > ranges;\n    ranges.push_back(std::make_pair(lo1,\
    \ hi1));\n    ranges.push_back(std::make_pair(lo2, hi2));\n    return Ranges(ranges);\n\
    \  }\n\n  // Pass this benchmark object to *func, which can customize\n  // the\
    \ benchmark by calling various methods like Arg, Args,\n  // Threads, etc.\n \
    \ Benchmark* Apply(void (*func)(Benchmark* benchmark));\n\n  // Set the range\
    \ multiplier for non-dense range. If not called, the range\n  // multiplier kRangeMultiplier\
    \ will be used.\n  Benchmark* RangeMultiplier(int multiplier);\n\n  // Set the\
    \ minimum amount of time to use when running this benchmark. This\n  // option\
    \ overrides the `benchmark_min_time` flag.\n  // REQUIRES: `t > 0` and `Iterations`\
    \ has not been called on this benchmark.\n  Benchmark* MinTime(double t);\n\n\
    \  // Specify the amount of iterations that should be run by this benchmark.\n\
    \  // REQUIRES: 'n > 0' and `MinTime` has not been called on this benchmark.\n\
    \  //\n  // NOTE: This function should only be used when *exact* iteration control\
    \ is\n  //   needed and never to control or limit how long a benchmark runs, where\n\
    \  // `--benchmark_min_time=N` or `MinTime(...)` should be used instead.\n  Benchmark*\
    \ Iterations(IterationCount n);\n\n  // Specify the amount of times to repeat\
    \ this benchmark. This option overrides\n  // the `benchmark_repetitions` flag.\n\
    \  // REQUIRES: `n > 0`\n  Benchmark* Repetitions(int n);\n\n  // Specify if each\
    \ repetition of the benchmark should be reported separately\n  // or if only the\
    \ final statistics should be reported. If the benchmark\n  // is not repeated\
    \ then the single result is always reported.\n  // Applies to *ALL* reporters\
    \ (display and file).\n  Benchmark* ReportAggregatesOnly(bool value = true);\n\
    \n  // Same as ReportAggregatesOnly(), but applies to display reporter only.\n\
    \  Benchmark* DisplayAggregatesOnly(bool value = true);\n\n  // By default, the\
    \ CPU time is measured only for the main thread, which may\n  // be unrepresentative\
    \ if the benchmark uses threads internally. If called,\n  // the total CPU time\
    \ spent by all the threads will be measured instead.\n  // By default, the only\
    \ the main thread CPU time will be measured.\n  Benchmark* MeasureProcessCPUTime();\n\
    \n  // If a particular benchmark should use the Wall clock instead of the CPU\
    \ time\n  // (be it either the CPU time of the main thread only (default), or\
    \ the\n  // total CPU usage of the benchmark), call this method. If called, the\
    \ elapsed\n  // (wall) time will be used to control how many iterations are run,\
    \ and in the\n  // printing of items/second or MB/seconds values.\n  // If not\
    \ called, the CPU time used by the benchmark will be used.\n  Benchmark* UseRealTime();\n\
    \n  // If a benchmark must measure time manually (e.g. if GPU execution time is\n\
    \  // being\n  // measured), call this method. If called, each benchmark iteration\
    \ should\n  // call\n  // SetIterationTime(seconds) to report the measured time,\
    \ which will be used\n  // to control how many iterations are run, and in the\
    \ printing of items/second\n  // or MB/second values.\n  Benchmark* UseManualTime();\n\
    \n  // Set the asymptotic computational complexity for the benchmark. If called\n\
    \  // the asymptotic computational complexity will be shown on the output.\n \
    \ Benchmark* Complexity(BigO complexity = benchmark::oAuto);\n\n  // Set the asymptotic\
    \ computational complexity for the benchmark. If called\n  // the asymptotic computational\
    \ complexity will be shown on the output.\n  Benchmark* Complexity(BigOFunc* complexity);\n\
    \n  // Add this statistics to be computed over all the values of benchmark run\n\
    \  Benchmark* ComputeStatistics(std::string name, StatisticsFunc* statistics);\n\
    \n  // Support for running multiple copies of the same benchmark concurrently\n\
    \  // in multiple threads.  This may be useful when measuring the scaling\n  //\
    \ of some piece of code.\n\n  // Run one instance of this benchmark concurrently\
    \ in t threads.\n  Benchmark* Threads(int t);\n\n  // Pick a set of values T from\
    \ [min_threads,max_threads].\n  // min_threads and max_threads are always included\
    \ in T.  Run this\n  // benchmark once for each value in T.  The benchmark run\
    \ for a\n  // particular value t consists of t threads running the benchmark\n\
    \  // function concurrently.  For example, consider:\n  //    BENCHMARK(Foo)->ThreadRange(1,16);\n\
    \  // This will run the following benchmarks:\n  //    Foo in 1 thread\n  // \
    \   Foo in 2 threads\n  //    Foo in 4 threads\n  //    Foo in 8 threads\n  //\
    \    Foo in 16 threads\n  Benchmark* ThreadRange(int min_threads, int max_threads);\n\
    \n  // For each value n in the range, run this benchmark once using n threads.\n\
    \  // min_threads and max_threads are always included in the range.\n  // stride\
    \ specifies the increment. E.g. DenseThreadRange(1, 8, 3) starts\n  // a benchmark\
    \ with 1, 4, 7 and 8 threads.\n  Benchmark* DenseThreadRange(int min_threads,\
    \ int max_threads, int stride = 1);\n\n  // Equivalent to ThreadRange(NumCPUs(),\
    \ NumCPUs())\n  Benchmark* ThreadPerCpu();\n\n  virtual void Run(State& state)\
    \ = 0;\n\n protected:\n  explicit Benchmark(const char* name);\n  Benchmark(Benchmark\
    \ const&);\n  void SetName(const char* name);\n\n  int ArgsCnt() const;\n\n private:\n\
    \  friend class BenchmarkFamilies;\n\n  std::string name_;\n  AggregationReportMode\
    \ aggregation_report_mode_;\n  std::vector<std::string> arg_names_;       // Args\
    \ for all benchmark runs\n  std::vector<std::vector<int64_t> > args_;  // Args\
    \ for all benchmark runs\n  TimeUnit time_unit_;\n  int range_multiplier_;\n \
    \ double min_time_;\n  IterationCount iterations_;\n  int repetitions_;\n  bool\
    \ measure_process_cpu_time_;\n  bool use_real_time_;\n  bool use_manual_time_;\n\
    \  BigO complexity_;\n  BigOFunc* complexity_lambda_;\n  std::vector<Statistics>\
    \ statistics_;\n  std::vector<int> thread_counts_;\n\n  Benchmark& operator=(Benchmark\
    \ const&);\n};\n\n}  // namespace internal\n\n// Create and register a benchmark\
    \ with the specified 'name' that invokes\n// the specified functor 'fn'.\n//\n\
    // RETURNS: A pointer to the registered benchmark.\ninternal::Benchmark* RegisterBenchmark(const\
    \ char* name,\n                                       internal::Function* fn);\n\
    \n#if defined(BENCHMARK_HAS_CXX11)\ntemplate <class Lambda>\ninternal::Benchmark*\
    \ RegisterBenchmark(const char* name, Lambda&& fn);\n#endif\n\n// Remove all registered\
    \ benchmarks. All pointers to previously registered\n// benchmarks are invalidated.\n\
    void ClearRegisteredBenchmarks();\n\nnamespace internal {\n// The class used to\
    \ hold all Benchmarks created from static function.\n// (ie those created using\
    \ the BENCHMARK(...) macros.\nclass FunctionBenchmark : public Benchmark {\n public:\n\
    \  FunctionBenchmark(const char* name, Function* func)\n      : Benchmark(name),\
    \ func_(func) {}\n\n  virtual void Run(State& st);\n\n private:\n  Function* func_;\n\
    };\n\n#ifdef BENCHMARK_HAS_CXX11\ntemplate <class Lambda>\nclass LambdaBenchmark\
    \ : public Benchmark {\n public:\n  virtual void Run(State& st) { lambda_(st);\
    \ }\n\n private:\n  template <class OLambda>\n  LambdaBenchmark(const char* name,\
    \ OLambda&& lam)\n      : Benchmark(name), lambda_(std::forward<OLambda>(lam))\
    \ {}\n\n  LambdaBenchmark(LambdaBenchmark const&) = delete;\n\n private:\n  template\
    \ <class Lam>\n  friend Benchmark* ::benchmark::RegisterBenchmark(const char*,\
    \ Lam&&);\n\n  Lambda lambda_;\n};\n#endif\n\n}  // namespace internal\n\ninline\
    \ internal::Benchmark* RegisterBenchmark(const char* name,\n                 \
    \                             internal::Function* fn) {\n  return internal::RegisterBenchmarkInternal(\n\
    \      ::new internal::FunctionBenchmark(name, fn));\n}\n\n#ifdef BENCHMARK_HAS_CXX11\n\
    template <class Lambda>\ninternal::Benchmark* RegisterBenchmark(const char* name,\
    \ Lambda&& fn) {\n  using BenchType =\n      internal::LambdaBenchmark<typename\
    \ std::decay<Lambda>::type>;\n  return internal::RegisterBenchmarkInternal(\n\
    \      ::new BenchType(name, std::forward<Lambda>(fn)));\n}\n#endif\n\n#if defined(BENCHMARK_HAS_CXX11)\
    \ && \\\n    (!defined(BENCHMARK_GCC_VERSION) || BENCHMARK_GCC_VERSION >= 409)\n\
    template <class Lambda, class... Args>\ninternal::Benchmark* RegisterBenchmark(const\
    \ char* name, Lambda&& fn,\n                                       Args&&... args)\
    \ {\n  return benchmark::RegisterBenchmark(\n      name, [=](benchmark::State&\
    \ st) { fn(st, args...); });\n}\n#else\n#define BENCHMARK_HAS_NO_VARIADIC_REGISTER_BENCHMARK\n\
    #endif\n\n// The base class for all fixture tests.\nclass Fixture : public internal::Benchmark\
    \ {\n public:\n  Fixture() : internal::Benchmark(\"\") {}\n\n  virtual void Run(State&\
    \ st) {\n    this->SetUp(st);\n    this->BenchmarkCase(st);\n    this->TearDown(st);\n\
    \  }\n\n  // These will be deprecated ...\n  virtual void SetUp(const State&)\
    \ {}\n  virtual void TearDown(const State&) {}\n  // ... In favor of these.\n\
    \  virtual void SetUp(State& st) { SetUp(const_cast<const State&>(st)); }\n  virtual\
    \ void TearDown(State& st) { TearDown(const_cast<const State&>(st)); }\n\n protected:\n\
    \  virtual void BenchmarkCase(State&) = 0;\n};\n\n}  // namespace benchmark\n\n\
    // ------------------------------------------------------\n// Macro to register\
    \ benchmarks\n\n// Check that __COUNTER__ is defined and that __COUNTER__ increases\
    \ by 1\n// every time it is expanded. X + 1 == X + 0 is used in case X is defined\
    \ to be\n// empty. If X is empty the expression becomes (+1 == +0).\n#if defined(__COUNTER__)\
    \ && (__COUNTER__ + 1 == __COUNTER__ + 0)\n#define BENCHMARK_PRIVATE_UNIQUE_ID\
    \ __COUNTER__\n#else\n#define BENCHMARK_PRIVATE_UNIQUE_ID __LINE__\n#endif\n\n\
    // Helpers for generating unique variable names\n#define BENCHMARK_PRIVATE_NAME(n)\
    \ \\\n  BENCHMARK_PRIVATE_CONCAT(_benchmark_, BENCHMARK_PRIVATE_UNIQUE_ID, n)\n\
    #define BENCHMARK_PRIVATE_CONCAT(a, b, c) BENCHMARK_PRIVATE_CONCAT2(a, b, c)\n\
    #define BENCHMARK_PRIVATE_CONCAT2(a, b, c) a##b##c\n\n#define BENCHMARK_PRIVATE_DECLARE(n)\
    \                                 \\\n  static ::benchmark::internal::Benchmark*\
    \ BENCHMARK_PRIVATE_NAME(n) \\\n      BENCHMARK_UNUSED\n\n#define BENCHMARK(n)\
    \                                     \\\n  BENCHMARK_PRIVATE_DECLARE(n) =   \
    \                      \\\n      (::benchmark::internal::RegisterBenchmarkInternal(\
    \ \\\n          new ::benchmark::internal::FunctionBenchmark(#n, n)))\n\n// Old-style\
    \ macros\n#define BENCHMARK_WITH_ARG(n, a) BENCHMARK(n)->Arg((a))\n#define BENCHMARK_WITH_ARG2(n,\
    \ a1, a2) BENCHMARK(n)->Args({(a1), (a2)})\n#define BENCHMARK_WITH_UNIT(n, t)\
    \ BENCHMARK(n)->Unit((t))\n#define BENCHMARK_RANGE(n, lo, hi) BENCHMARK(n)->Range((lo),\
    \ (hi))\n#define BENCHMARK_RANGE2(n, l1, h1, l2, h2) \\\n  BENCHMARK(n)->RangePair({{(l1),\
    \ (h1)}, {(l2), (h2)}})\n\n#ifdef BENCHMARK_HAS_CXX11\n\n// Register a benchmark\
    \ which invokes the function specified by `func`\n// with the additional arguments\
    \ specified by `...`.\n//\n// For example:\n//\n// template <class ...ExtraArgs>`\n\
    // void BM_takes_args(benchmark::State& state, ExtraArgs&&... extra_args) {\n\
    //  [...]\n//}\n// /* Registers a benchmark named \"BM_takes_args/int_string_test`\
    \ */\n// BENCHMARK_CAPTURE(BM_takes_args, int_string_test, 42, std::string(\"\
    abc\"));\n#define BENCHMARK_CAPTURE(func, test_case_name, ...)     \\\n  BENCHMARK_PRIVATE_DECLARE(func)\
    \ =                      \\\n      (::benchmark::internal::RegisterBenchmarkInternal(\
    \ \\\n          new ::benchmark::internal::FunctionBenchmark(  \\\n          \
    \    #func \"/\" #test_case_name,                 \\\n              [](::benchmark::State&\
    \ st) { func(st, __VA_ARGS__); })))\n\n#endif  // BENCHMARK_HAS_CXX11\n\n// This\
    \ will register a benchmark for a templatized function.  For example:\n//\n//\
    \ template<int arg>\n// void BM_Foo(int iters);\n//\n// BENCHMARK_TEMPLATE(BM_Foo,\
    \ 1);\n//\n// will register BM_Foo<1> as a benchmark.\n#define BENCHMARK_TEMPLATE1(n,\
    \ a)                        \\\n  BENCHMARK_PRIVATE_DECLARE(n) =             \
    \            \\\n      (::benchmark::internal::RegisterBenchmarkInternal( \\\n\
    \          new ::benchmark::internal::FunctionBenchmark(#n \"<\" #a \">\", n<a>)))\n\
    \n#define BENCHMARK_TEMPLATE2(n, a, b)                                       \
    \  \\\n  BENCHMARK_PRIVATE_DECLARE(n) =                                      \
    \       \\\n      (::benchmark::internal::RegisterBenchmarkInternal(         \
    \            \\\n          new ::benchmark::internal::FunctionBenchmark(#n \"\
    <\" #a \",\" #b \">\", \\\n                                                  \
    \     n<a, b>)))\n\n#ifdef BENCHMARK_HAS_CXX11\n#define BENCHMARK_TEMPLATE(n,\
    \ ...)                       \\\n  BENCHMARK_PRIVATE_DECLARE(n) =            \
    \             \\\n      (::benchmark::internal::RegisterBenchmarkInternal( \\\n\
    \          new ::benchmark::internal::FunctionBenchmark(  \\\n              #n\
    \ \"<\" #__VA_ARGS__ \">\", n<__VA_ARGS__>)))\n#else\n#define BENCHMARK_TEMPLATE(n,\
    \ a) BENCHMARK_TEMPLATE1(n, a)\n#endif\n\n#define BENCHMARK_PRIVATE_DECLARE_F(BaseClass,\
    \ Method)        \\\n  class BaseClass##_##Method##_Benchmark : public BaseClass\
    \ { \\\n   public:                                                    \\\n   \
    \ BaseClass##_##Method##_Benchmark() : BaseClass() {        \\\n      this->SetName(#BaseClass\
    \ \"/\" #Method);                  \\\n    }                                 \
    \                        \\\n                                                \
    \              \\\n   protected:                                             \
    \    \\\n    virtual void BenchmarkCase(::benchmark::State&);          \\\n  };\n\
    \n#define BENCHMARK_TEMPLATE1_PRIVATE_DECLARE_F(BaseClass, Method, a) \\\n  class\
    \ BaseClass##_##Method##_Benchmark : public BaseClass<a> {    \\\n   public: \
    \                                                         \\\n    BaseClass##_##Method##_Benchmark()\
    \ : BaseClass<a>() {           \\\n      this->SetName(#BaseClass \"<\" #a \"\
    >/\" #Method);                \\\n    }                                      \
    \                         \\\n                                               \
    \                     \\\n   protected:                                      \
    \                 \\\n    virtual void BenchmarkCase(::benchmark::State&);   \
    \             \\\n  };\n\n#define BENCHMARK_TEMPLATE2_PRIVATE_DECLARE_F(BaseClass,\
    \ Method, a, b) \\\n  class BaseClass##_##Method##_Benchmark : public BaseClass<a,\
    \ b> {    \\\n   public:                                                     \
    \        \\\n    BaseClass##_##Method##_Benchmark() : BaseClass<a, b>() {    \
    \       \\\n      this->SetName(#BaseClass \"<\" #a \",\" #b \">/\" #Method);\
    \            \\\n    }                                                       \
    \           \\\n                                                             \
    \          \\\n   protected:                                                 \
    \         \\\n    virtual void BenchmarkCase(::benchmark::State&);           \
    \        \\\n  };\n\n#ifdef BENCHMARK_HAS_CXX11\n#define BENCHMARK_TEMPLATE_PRIVATE_DECLARE_F(BaseClass,\
    \ Method, ...)       \\\n  class BaseClass##_##Method##_Benchmark : public BaseClass<__VA_ARGS__>\
    \ { \\\n   public:                                                           \
    \      \\\n    BaseClass##_##Method##_Benchmark() : BaseClass<__VA_ARGS__>() {\
    \        \\\n      this->SetName(#BaseClass \"<\" #__VA_ARGS__ \">/\" #Method);\
    \             \\\n    }                                                      \
    \                \\\n                                                        \
    \                   \\\n   protected:                                        \
    \                      \\\n    virtual void BenchmarkCase(::benchmark::State&);\
    \                       \\\n  };\n#else\n#define BENCHMARK_TEMPLATE_PRIVATE_DECLARE_F(n,\
    \ a) \\\n  BENCHMARK_TEMPLATE1_PRIVATE_DECLARE_F(n, a)\n#endif\n\n#define BENCHMARK_DEFINE_F(BaseClass,\
    \ Method)    \\\n  BENCHMARK_PRIVATE_DECLARE_F(BaseClass, Method) \\\n  void BaseClass##_##Method##_Benchmark::BenchmarkCase\n\
    \n#define BENCHMARK_TEMPLATE1_DEFINE_F(BaseClass, Method, a)    \\\n  BENCHMARK_TEMPLATE1_PRIVATE_DECLARE_F(BaseClass,\
    \ Method, a) \\\n  void BaseClass##_##Method##_Benchmark::BenchmarkCase\n\n#define\
    \ BENCHMARK_TEMPLATE2_DEFINE_F(BaseClass, Method, a, b)    \\\n  BENCHMARK_TEMPLATE2_PRIVATE_DECLARE_F(BaseClass,\
    \ Method, a, b) \\\n  void BaseClass##_##Method##_Benchmark::BenchmarkCase\n\n\
    #ifdef BENCHMARK_HAS_CXX11\n#define BENCHMARK_TEMPLATE_DEFINE_F(BaseClass, Method,\
    \ ...)            \\\n  BENCHMARK_TEMPLATE_PRIVATE_DECLARE_F(BaseClass, Method,\
    \ __VA_ARGS__) \\\n  void BaseClass##_##Method##_Benchmark::BenchmarkCase\n#else\n\
    #define BENCHMARK_TEMPLATE_DEFINE_F(BaseClass, Method, a) \\\n  BENCHMARK_TEMPLATE1_DEFINE_F(BaseClass,\
    \ Method, a)\n#endif\n\n#define BENCHMARK_REGISTER_F(BaseClass, Method) \\\n \
    \ BENCHMARK_PRIVATE_REGISTER_F(BaseClass##_##Method##_Benchmark)\n\n#define BENCHMARK_PRIVATE_REGISTER_F(TestName)\
    \ \\\n  BENCHMARK_PRIVATE_DECLARE(TestName) =        \\\n      (::benchmark::internal::RegisterBenchmarkInternal(new\
    \ TestName()))\n\n// This macro will define and register a benchmark within a\
    \ fixture class.\n#define BENCHMARK_F(BaseClass, Method)           \\\n  BENCHMARK_PRIVATE_DECLARE_F(BaseClass,\
    \ Method) \\\n  BENCHMARK_REGISTER_F(BaseClass, Method);       \\\n  void BaseClass##_##Method##_Benchmark::BenchmarkCase\n\
    \n#define BENCHMARK_TEMPLATE1_F(BaseClass, Method, a)           \\\n  BENCHMARK_TEMPLATE1_PRIVATE_DECLARE_F(BaseClass,\
    \ Method, a) \\\n  BENCHMARK_REGISTER_F(BaseClass, Method);                  \
    \  \\\n  void BaseClass##_##Method##_Benchmark::BenchmarkCase\n\n#define BENCHMARK_TEMPLATE2_F(BaseClass,\
    \ Method, a, b)           \\\n  BENCHMARK_TEMPLATE2_PRIVATE_DECLARE_F(BaseClass,\
    \ Method, a, b) \\\n  BENCHMARK_REGISTER_F(BaseClass, Method);               \
    \        \\\n  void BaseClass##_##Method##_Benchmark::BenchmarkCase\n\n#ifdef\
    \ BENCHMARK_HAS_CXX11\n#define BENCHMARK_TEMPLATE_F(BaseClass, Method, ...)  \
    \                 \\\n  BENCHMARK_TEMPLATE_PRIVATE_DECLARE_F(BaseClass, Method,\
    \ __VA_ARGS__) \\\n  BENCHMARK_REGISTER_F(BaseClass, Method);                \
    \             \\\n  void BaseClass##_##Method##_Benchmark::BenchmarkCase\n#else\n\
    #define BENCHMARK_TEMPLATE_F(BaseClass, Method, a) \\\n  BENCHMARK_TEMPLATE1_F(BaseClass,\
    \ Method, a)\n#endif\n\n// Helper macro to create a main routine in a test that\
    \ runs the benchmarks\n#define BENCHMARK_MAIN()                              \
    \                  \\\n  int main(int argc, char** argv) {                   \
    \                  \\\n    ::benchmark::Initialize(&argc, argv);             \
    \                  \\\n    if (::benchmark::ReportUnrecognizedArguments(argc,\
    \ argv)) return 1; \\\n    ::benchmark::RunSpecifiedBenchmarks();            \
    \                  \\\n  }                                                   \
    \                  \\\n  int main(int, char**)\n\n// ------------------------------------------------------\n\
    // Benchmark Reporters\n\nnamespace benchmark {\n\nstruct CPUInfo {\n  struct\
    \ CacheInfo {\n    std::string type;\n    int level;\n    int size;\n    int num_sharing;\n\
    \  };\n\n  enum Scaling {\n    UNKNOWN,\n    ENABLED,\n    DISABLED\n  };\n\n\
    \  int num_cpus;\n  double cycles_per_second;\n  std::vector<CacheInfo> caches;\n\
    \  Scaling scaling;\n  std::vector<double> load_avg;\n\n  static const CPUInfo&\
    \ Get();\n\n private:\n  CPUInfo();\n  BENCHMARK_DISALLOW_COPY_AND_ASSIGN(CPUInfo);\n\
    };\n\n// Adding Struct for System Information\nstruct SystemInfo {\n  std::string\
    \ name;\n  static const SystemInfo& Get();\n\n private:\n  SystemInfo();\n  BENCHMARK_DISALLOW_COPY_AND_ASSIGN(SystemInfo);\n\
    };\n\n// BenchmarkName contains the components of the Benchmark's name\n// which\
    \ allows individual fields to be modified or cleared before\n// building the final\
    \ name using 'str()'.\nstruct BenchmarkName {\n  std::string function_name;\n\
    \  std::string args;\n  std::string min_time;\n  std::string iterations;\n  std::string\
    \ repetitions;\n  std::string time_type;\n  std::string threads;\n\n  // Return\
    \ the full name of the benchmark with each non-empty\n  // field separated by\
    \ a '/'\n  std::string str() const;\n};\n\n// Interface for custom benchmark result\
    \ printers.\n// By default, benchmark reports are printed to stdout. However an\
    \ application\n// can control the destination of the reports by calling\n// RunSpecifiedBenchmarks\
    \ and passing it a custom reporter object.\n// The reporter object must implement\
    \ the following interface.\nclass BenchmarkReporter {\n public:\n  struct Context\
    \ {\n    CPUInfo const& cpu_info;\n    SystemInfo const& sys_info;\n    // The\
    \ number of chars in the longest benchmark name.\n    size_t name_field_width;\n\
    \    static const char* executable_name;\n    Context();\n  };\n\n  struct Run\
    \ {\n    static const int64_t no_repetition_index = -1;\n    enum RunType { RT_Iteration,\
    \ RT_Aggregate };\n\n    Run()\n        : run_type(RT_Iteration),\n          error_occurred(false),\n\
    \          iterations(1),\n          threads(1),\n          time_unit(kNanosecond),\n\
    \          real_accumulated_time(0),\n          cpu_accumulated_time(0),\n   \
    \       max_heapbytes_used(0),\n          complexity(oNone),\n          complexity_lambda(),\n\
    \          complexity_n(0),\n          report_big_o(false),\n          report_rms(false),\n\
    \          counters(),\n          has_memory_result(false),\n          allocs_per_iter(0.0),\n\
    \          max_bytes_used(0) {}\n\n    std::string benchmark_name() const;\n \
    \   BenchmarkName run_name;\n    RunType run_type;\n    std::string aggregate_name;\n\
    \    std::string report_label;  // Empty if not set by benchmark.\n    bool error_occurred;\n\
    \    std::string error_message;\n\n    IterationCount iterations;\n    int64_t\
    \ threads;\n    int64_t repetition_index;\n    int64_t repetitions;\n    TimeUnit\
    \ time_unit;\n    double real_accumulated_time;\n    double cpu_accumulated_time;\n\
    \n    // Return a value representing the real time per iteration in the unit\n\
    \    // specified by 'time_unit'.\n    // NOTE: If 'iterations' is zero the returned\
    \ value represents the\n    // accumulated time.\n    double GetAdjustedRealTime()\
    \ const;\n\n    // Return a value representing the cpu time per iteration in the\
    \ unit\n    // specified by 'time_unit'.\n    // NOTE: If 'iterations' is zero\
    \ the returned value represents the\n    // accumulated time.\n    double GetAdjustedCPUTime()\
    \ const;\n\n    // This is set to 0.0 if memory tracing is not enabled.\n    double\
    \ max_heapbytes_used;\n\n    // Keep track of arguments to compute asymptotic\
    \ complexity\n    BigO complexity;\n    BigOFunc* complexity_lambda;\n    int64_t\
    \ complexity_n;\n\n    // what statistics to compute from the measurements\n \
    \   const std::vector<internal::Statistics>* statistics;\n\n    // Inform print\
    \ function whether the current run is a complexity report\n    bool report_big_o;\n\
    \    bool report_rms;\n\n    UserCounters counters;\n\n    // Memory metrics.\n\
    \    bool has_memory_result;\n    double allocs_per_iter;\n    int64_t max_bytes_used;\n\
    \  };\n\n  // Construct a BenchmarkReporter with the output stream set to 'std::cout'\n\
    \  // and the error stream set to 'std::cerr'\n  BenchmarkReporter();\n\n  //\
    \ Called once for every suite of benchmarks run.\n  // The parameter \"context\"\
    \ contains information that the\n  // reporter may wish to use when generating\
    \ its report, for example the\n  // platform under which the benchmarks are running.\
    \ The benchmark run is\n  // never started if this function returns false, allowing\
    \ the reporter\n  // to skip runs based on the context information.\n  virtual\
    \ bool ReportContext(const Context& context) = 0;\n\n  // Called once for each\
    \ group of benchmark runs, gives information about\n  // cpu-time and heap memory\
    \ usage during the benchmark run. If the group\n  // of runs contained more than\
    \ two entries then 'report' contains additional\n  // elements representing the\
    \ mean and standard deviation of those runs.\n  // Additionally if this group\
    \ of runs was the last in a family of benchmarks\n  // 'reports' contains additional\
    \ entries representing the asymptotic\n  // complexity and RMS of that benchmark\
    \ family.\n  virtual void ReportRuns(const std::vector<Run>& report) = 0;\n\n\
    \  // Called once and only once after ever group of benchmarks is run and\n  //\
    \ reported.\n  virtual void Finalize() {}\n\n  // REQUIRES: The object referenced\
    \ by 'out' is valid for the lifetime\n  // of the reporter.\n  void SetOutputStream(std::ostream*\
    \ out) {\n    assert(out);\n    output_stream_ = out;\n  }\n\n  // REQUIRES: The\
    \ object referenced by 'err' is valid for the lifetime\n  // of the reporter.\n\
    \  void SetErrorStream(std::ostream* err) {\n    assert(err);\n    error_stream_\
    \ = err;\n  }\n\n  std::ostream& GetOutputStream() const { return *output_stream_;\
    \ }\n\n  std::ostream& GetErrorStream() const { return *error_stream_; }\n\n \
    \ virtual ~BenchmarkReporter();\n\n  // Write a human readable string to 'out'\
    \ representing the specified\n  // 'context'.\n  // REQUIRES: 'out' is non-null.\n\
    \  static void PrintBasicContext(std::ostream* out, Context const& context);\n\
    \n private:\n  std::ostream* output_stream_;\n  std::ostream* error_stream_;\n\
    };\n\n// Simple reporter that outputs benchmark data to the console. This is the\n\
    // default reporter used by RunSpecifiedBenchmarks().\nclass ConsoleReporter :\
    \ public BenchmarkReporter {\n public:\n  enum OutputOptions {\n    OO_None =\
    \ 0,\n    OO_Color = 1,\n    OO_Tabular = 2,\n    OO_ColorTabular = OO_Color |\
    \ OO_Tabular,\n    OO_Defaults = OO_ColorTabular\n  };\n  explicit ConsoleReporter(OutputOptions\
    \ opts_ = OO_Defaults)\n      : output_options_(opts_),\n        name_field_width_(0),\n\
    \        prev_counters_(),\n        printed_header_(false) {}\n\n  virtual bool\
    \ ReportContext(const Context& context);\n  virtual void ReportRuns(const std::vector<Run>&\
    \ reports);\n\n protected:\n  virtual void PrintRunData(const Run& report);\n\
    \  virtual void PrintHeader(const Run& report);\n\n  OutputOptions output_options_;\n\
    \  size_t name_field_width_;\n  UserCounters prev_counters_;\n  bool printed_header_;\n\
    };\n\nclass JSONReporter : public BenchmarkReporter {\n public:\n  JSONReporter()\
    \ : first_report_(true) {}\n  virtual bool ReportContext(const Context& context);\n\
    \  virtual void ReportRuns(const std::vector<Run>& reports);\n  virtual void Finalize();\n\
    \n private:\n  void PrintRunData(const Run& report);\n\n  bool first_report_;\n\
    };\n\nclass BENCHMARK_DEPRECATED_MSG(\n    \"The CSV Reporter will be removed\
    \ in a future release\") CSVReporter\n    : public BenchmarkReporter {\n public:\n\
    \  CSVReporter() : printed_header_(false) {}\n  virtual bool ReportContext(const\
    \ Context& context);\n  virtual void ReportRuns(const std::vector<Run>& reports);\n\
    \n private:\n  void PrintRunData(const Run& report);\n\n  bool printed_header_;\n\
    \  std::set<std::string> user_counter_names_;\n};\n\n// If a MemoryManager is\
    \ registered, it can be used to collect and report\n// allocation metrics for\
    \ a run of the benchmark.\nclass MemoryManager {\n public:\n  struct Result {\n\
    \    Result() : num_allocs(0), max_bytes_used(0) {}\n\n    // The number of allocations\
    \ made in total between Start and Stop.\n    int64_t num_allocs;\n\n    // The\
    \ peak memory use between Start and Stop.\n    int64_t max_bytes_used;\n  };\n\
    \n  virtual ~MemoryManager() {}\n\n  // Implement this to start recording allocation\
    \ information.\n  virtual void Start() = 0;\n\n  // Implement this to stop recording\
    \ and fill out the given Result structure.\n  virtual void Stop(Result* result)\
    \ = 0;\n};\n\ninline const char* GetTimeUnitString(TimeUnit unit) {\n  switch\
    \ (unit) {\n    case kMillisecond:\n      return \"ms\";\n    case kMicrosecond:\n\
    \      return \"us\";\n    case kNanosecond:\n      return \"ns\";\n  }\n  BENCHMARK_UNREACHABLE();\n\
    }\n\ninline double GetTimeUnitMultiplier(TimeUnit unit) {\n  switch (unit) {\n\
    \    case kMillisecond:\n      return 1e3;\n    case kMicrosecond:\n      return\
    \ 1e6;\n    case kNanosecond:\n      return 1e9;\n  }\n  BENCHMARK_UNREACHABLE();\n\
    }\n\n}  // namespace benchmark\n\n#endif  // BENCHMARK_BENCHMARK_H_"
  dependsOn: []
  isVerificationFile: false
  path: tests/benchmark/benchmark.h
  requiredBy:
  - tests/benchmark/PowerSeries.cpp
  - tests/benchmark/bench.h
  - tests/benchmark/PolynomialRing.cpp
  - tests/benchmark/main.cpp
  timestamp: '2020-10-28 22:28:43-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tests/benchmark/benchmark.h
layout: document
redirect_from:
- /library/tests/benchmark/benchmark.h
- /library/tests/benchmark/benchmark.h.html
title: tests/benchmark/benchmark.h
---
