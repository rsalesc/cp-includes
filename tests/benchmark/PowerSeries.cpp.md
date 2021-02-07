---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: BitTricks.cpp
    title: BitTricks.cpp
  - icon: ':warning:'
    path: Complex.cpp
    title: Complex.cpp
  - icon: ':warning:'
    path: DFT.cpp
    title: DFT.cpp
  - icon: ':warning:'
    path: Epsilon.cpp
    title: Epsilon.cpp
  - icon: ':warning:'
    path: FFT.cpp
    title: FFT.cpp
  - icon: ':warning:'
    path: LongMultiplication.cpp
    title: LongMultiplication.cpp
  - icon: ':warning:'
    path: LongMultiplication.cpp
    title: LongMultiplication.cpp
  - icon: ':warning:'
    path: Math.cpp
    title: Math.cpp
  - icon: ':warning:'
    path: ModularInteger.cpp
    title: ModularInteger.cpp
  - icon: ':warning:'
    path: ModularInteger.cpp
    title: ModularInteger.cpp
  - icon: ':warning:'
    path: NumberTheory.cpp
    title: NumberTheory.cpp
  - icon: ':warning:'
    path: PolynomialRing.cpp
    title: PolynomialRing.cpp
  - icon: ':warning:'
    path: PolynomialRing.cpp
    title: PolynomialRing.cpp
  - icon: ':warning:'
    path: PolynomialRing.cpp
    title: PolynomialRing.cpp
  - icon: ':warning:'
    path: PowerSeries.cpp
    title: PowerSeries.cpp
  - icon: ':warning:'
    path: Traits.cpp
    title: Traits.cpp
  - icon: ':warning:'
    path: Traits.cpp
    title: Traits.cpp
  - icon: ':warning:'
    path: VectorN.cpp
    title: VectorN.cpp
  - icon: ':warning:'
    path: geometry/Trigonometry.cpp
    title: geometry/Trigonometry.cpp
  - icon: ':warning:'
    path: polynomial/MultipointEvaluation.cpp
    title: polynomial/MultipointEvaluation.cpp
  - icon: ':warning:'
    path: tests/benchmark/bench.h
    title: tests/benchmark/bench.h
  - icon: ':warning:'
    path: tests/benchmark/benchmark.h
    title: tests/benchmark/benchmark.h
  - icon: ':warning:'
    path: tests/jngen.h
    title: tests/jngen.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tests/benchmark/main.cpp
    title: tests/benchmark/main.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
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
  code: "#include \"../../ModularInteger.cpp\"\n#include \"../../PolynomialRing.cpp\"\
    \n#include \"../../FFT.cpp\"\n#include \"../../LongMultiplication.cpp\"\n#include\
    \ \"../../polynomial/MultipointEvaluation.cpp\"\n#include \"../../PowerSeries.cpp\"\
    \n\n#include \"bench.h\"\n\nusing namespace lib;\nusing namespace lib::linalg;\n\
    using namespace lib::math;\n\nnamespace lib::bench::PowerSeries {\n\nconst static\
    \ int MOD = (int)1e9+7;\nusing Field = Mint32<MOD>;\nusing Poly = Polynomial<Field,\
    \ SafeMultiplication>;\n\nstatic void BM_Series_Power(benchmark::State& state)\
    \ {\n    const int n = state.range(0);\n    const int K = state.range(1);\n  \
    \  auto v = Array::random(n, MOD);\n    vector<Field> a(v.begin(), v.end());\n\
    \    Poly p = a;\n\n    for(auto _ : state) {\n        benchmark::DoNotOptimize(series::power(p,\
    \ K, n*K - (K-1)));\n    }\n}\n\nstatic void BM_Series_Inverse(benchmark::State&\
    \ state) {\n    const int n = state.range(0);\n    auto v = Array::random(n, MOD);\n\
    \    vector<Field> a(v.begin(), v.end());\n    Poly p = a;\n\n    for(auto _ :\
    \ state) {\n        benchmark::DoNotOptimize(series::inverse(p, n));\n    }\n\
    }\n\nstatic void BM_Series_Exp(benchmark::State& state) {\n    const int n = state.range(0);\n\
    \    auto v = Array::random(n, MOD);\n    vector<Field> a(v.begin(), v.end());\n\
    \    a[0] = 0; // exp needs a[0] to be zero\n    Poly p = a;\n\n    for(auto _\
    \ : state) {\n        benchmark::DoNotOptimize(series::exp(p, n));\n    }\n}\n\
    \nstatic void BM_Series_Ln(benchmark::State& state) {\n    const int n = state.range(0);\n\
    \    auto v = Array::random(n, MOD);\n    vector<Field> a(v.begin(), v.end());\n\
    \    a[0] = 1; // ln needs a[0] to be non-null\n    Poly p = a;\n\n    for(auto\
    \ _ : state) {\n        benchmark::DoNotOptimize(series::ln(p, n));\n    }\n}\n\
    \nBENCHMARK(BM_Series_Power)\n    ->Args({1000, 1000})->Args({10000, 20})\n  \
    \  ->Unit(benchmark::kMillisecond);\n\nBENCHMARK(BM_Series_Inverse)\n    ->Arg(1000)->Arg((int)1e5)\n\
    \    ->Unit(benchmark::kMillisecond);\n\nBENCHMARK(BM_Series_Exp)\n    ->Arg((int)1e5)\n\
    \    ->Unit(benchmark::kMillisecond);\n\nBENCHMARK(BM_Series_Ln)\n    ->Arg((int)1e5)\n\
    \    ->Unit(benchmark::kMillisecond);\n\n}  // end namespace"
  dependsOn:
  - ModularInteger.cpp
  - NumberTheory.cpp
  - PolynomialRing.cpp
  - Epsilon.cpp
  - Math.cpp
  - ModularInteger.cpp
  - Traits.cpp
  - LongMultiplication.cpp
  - VectorN.cpp
  - FFT.cpp
  - DFT.cpp
  - BitTricks.cpp
  - Complex.cpp
  - geometry/Trigonometry.cpp
  - LongMultiplication.cpp
  - polynomial/MultipointEvaluation.cpp
  - PolynomialRing.cpp
  - Traits.cpp
  - PowerSeries.cpp
  - PolynomialRing.cpp
  - tests/benchmark/bench.h
  - tests/benchmark/benchmark.h
  - tests/jngen.h
  isVerificationFile: false
  path: tests/benchmark/PowerSeries.cpp
  requiredBy:
  - tests/benchmark/main.cpp
  timestamp: '2021-01-31 01:48:38-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tests/benchmark/PowerSeries.cpp
layout: document
redirect_from:
- /library/tests/benchmark/PowerSeries.cpp
- /library/tests/benchmark/PowerSeries.cpp.html
title: tests/benchmark/PowerSeries.cpp
---
