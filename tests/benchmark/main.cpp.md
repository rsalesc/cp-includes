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
    path: tests/benchmark/PolynomialRing.cpp
    title: tests/benchmark/PolynomialRing.cpp
  - icon: ':warning:'
    path: tests/benchmark/PowerSeries.cpp
    title: tests/benchmark/PowerSeries.cpp
  - icon: ':warning:'
    path: tests/benchmark/bench.h
    title: tests/benchmark/bench.h
  - icon: ':warning:'
    path: tests/benchmark/benchmark.h
    title: tests/benchmark/benchmark.h
  - icon: ':warning:'
    path: tests/jngen.h
    title: tests/jngen.h
  _extendedRequiredBy: []
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
  code: '#include "benchmark.h"


    #include "PolynomialRing.cpp"

    #include "PowerSeries.cpp"


    BENCHMARK_MAIN();'
  dependsOn:
  - tests/benchmark/benchmark.h
  - tests/benchmark/PolynomialRing.cpp
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
  - tests/jngen.h
  - tests/benchmark/PowerSeries.cpp
  isVerificationFile: false
  path: tests/benchmark/main.cpp
  requiredBy: []
  timestamp: '2021-01-31 01:48:38-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tests/benchmark/main.cpp
layout: document
redirect_from:
- /library/tests/benchmark/main.cpp
- /library/tests/benchmark/main.cpp.html
title: tests/benchmark/main.cpp
---
