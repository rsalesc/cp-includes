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
    path: NTT.cpp
    title: NTT.cpp
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
    \n#include \"../../FFT.cpp\"\n#include \"../../NTT.cpp\"\n#include \"../../LongMultiplication.cpp\"\
    \n#include \"../../polynomial/MultipointEvaluation.cpp\"\n#include \"../../PowerSeries.cpp\"\
    \n\n#include \"bench.h\"\n\nusing namespace lib;\nusing namespace lib::linalg;\n\
    using namespace lib::math;\n\nnamespace lib::bench::PolynomialRing {\n\nconst\
    \ static int MOD = (int)1e9+7;\nusing Field = Mint32<MOD>;\nusing Poly = Polynomial<Field,\
    \ SafeMultiplication>;\n\nstatic void BM_Polynomial_SafeMultiplication(benchmark::State&\
    \ state) {\n    const int n = state.range(0);\n    auto v = Array::random(n, MOD);\n\
    \    vector<Field> a(v.begin(), v.end());\n    Poly p = a;\n\n    for(auto _ :\
    \ state) {\n        benchmark::DoNotOptimize(p*p);\n    }\n}\n\nstatic void BM_Polynomial_FastMultiplication(benchmark::State&\
    \ state) {\n    const int n = state.range(0);\n    auto v = Array::random(n, MOD);\n\
    \    vector<Field> a(v.begin(), v.end());\n    Polynomial<Field, FastMultiplication>\
    \ p = a;\n\n    for(auto _ : state) {\n        benchmark::DoNotOptimize(p*p);\n\
    \    }\n}\n\nstatic void BM_Polynomial_NTTMultiplication(benchmark::State& state)\
    \ {\n    const int n = state.range(0);\n    auto v = Array::random(n, int(Field::mod));\n\
    \    vector<Field> a(v.begin(), v.end());\n    Polynomial<Field, NTTMultiplication>\
    \ p = a;\n\n    for(auto _ : state) {\n        benchmark::DoNotOptimize(p*p);\n\
    \    }\n}\n\n\nstatic void BM_Polynomial_Power(benchmark::State& state) {\n  \
    \  const int n = state.range(0);\n    const int K = state.range(1);\n    auto\
    \ v = Array::random(n, MOD);\n    vector<Field> a(v.begin(), v.end());\n    Poly\
    \ p = a;\n\n    for(auto _ : state) {\n        benchmark::DoNotOptimize(Poly::power(p,\
    \ K, n*K - (K-1)));\n    }\n}\n\nstatic void BM_Polynomial_Division(benchmark::State&\
    \ state) {\n    const int n = state.range(0);\n    const int m = state.range(1);\n\
    \    auto v1 = Array::random(n, MOD);\n    auto v2 = Array::random(m, MOD);\n\
    \    vector<Field> a(v1.begin(), v1.end()), b(v2.begin(), v2.end());\n    Poly\
    \ p = a;\n    Poly q = b;\n\n    for(auto _ : state) {\n        benchmark::DoNotOptimize(Poly::divmod(p,\
    \ q));\n    }\n}\n\nstatic void BM_Polynomial_MultipointEvaluation(benchmark::State&\
    \ state) {\n    const int n = state.range(0);\n    const int m = state.range(1);\n\
    \    auto v1 = Array::random(n, MOD);\n    auto v2 = Array::random(m, MOD);\n\
    \    vector<Field> a(v1.begin(), v1.end()), b(v2.begin(), v2.end());\n    Poly\
    \ p = a;\n    MultipointEvaluation<Poly> me(b);\n\n    for(auto _ : state) {\n\
    \        benchmark::DoNotOptimize(me.eval(p));\n    }\n}\n\nstatic void BM_Polynomial_Interpolation(benchmark::State&\
    \ state) {\n    const int n = state.range(0);\n    auto v1 = Array::random(n,\
    \ MOD);\n    vector<Field> y(v1.begin(), v1.end());\n    vector<Field> x(n);\n\
    \    iota(x.begin(), x.end(), 0);\n    MultipointEvaluation<Poly> me(x);\n\n \
    \   for(auto _ : state) {\n        benchmark::DoNotOptimize(me.interp(y.begin(),\
    \ y.end()));\n    }\n}\n\nstatic void BM_Polynomial_Kmul(benchmark::State& state)\
    \ {\n    const int n = state.range(0);\n    auto v1 = Array::random(n, MOD);\n\
    \    vector<Field> w(v1.begin(), v1.end());\n    vector<Poly> polys(n);\n    for(int\
    \ i = 0; i < n; i++)\n        polys[i] = Poly::from_root(w[i]);\n\n    for(auto\
    \ _ : state) {\n        benchmark::DoNotOptimize(kmul(polys));\n    }\n}\n\nBENCHMARK(BM_Polynomial_SafeMultiplication)\n\
    \    ->Arg(100000)->Arg((int)1e6)\n    ->Unit(benchmark::kMillisecond);\n\nBENCHMARK(BM_Polynomial_FastMultiplication)\n\
    \    ->Arg((int)1e5)->Arg((int)1e6)\n    ->Unit(benchmark::kMillisecond);\n\n\
    BENCHMARK(BM_Polynomial_NTTMultiplication)\n    ->Arg((int)1e5)->Arg((int)1e6)\n\
    \    ->Unit(benchmark::kMillisecond);\n\nBENCHMARK(BM_Polynomial_Power)\n    ->Args({1000,\
    \ 1000})->Args({10000, 20})\n    ->Unit(benchmark::kMillisecond);\n\nBENCHMARK(BM_Polynomial_Division)\n\
    \    ->Args({100000, 10000})\n    ->Unit(benchmark::kMillisecond);\n\nBENCHMARK(BM_Polynomial_MultipointEvaluation)\n\
    \    ->Args({100000, 100000})\n    ->Unit(benchmark::kMillisecond);\n\nBENCHMARK(BM_Polynomial_Interpolation)\n\
    \    ->Arg((int)1e5)\n    ->Unit(benchmark::kMillisecond);\n\nBENCHMARK(BM_Polynomial_Kmul)\n\
    \    ->Arg((int)1e5)\n    ->Unit(benchmark::kMillisecond);\n\n}  // end namespace"
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
  - NTT.cpp
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
  path: tests/benchmark/PolynomialRing.cpp
  requiredBy:
  - tests/benchmark/main.cpp
  timestamp: '2021-01-31 01:48:38-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tests/benchmark/PolynomialRing.cpp
layout: document
redirect_from:
- /library/tests/benchmark/PolynomialRing.cpp
- /library/tests/benchmark/PolynomialRing.cpp.html
title: tests/benchmark/PolynomialRing.cpp
---
