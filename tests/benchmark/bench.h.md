---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: tests/benchmark/benchmark.h
    title: tests/benchmark/benchmark.h
  - icon: ':warning:'
    path: tests/jngen.h
    title: tests/jngen.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tests/benchmark/PolynomialRing.cpp
    title: tests/benchmark/PolynomialRing.cpp
  - icon: ':warning:'
    path: tests/benchmark/PowerSeries.cpp
    title: tests/benchmark/PowerSeries.cpp
  - icon: ':warning:'
    path: tests/benchmark/main.cpp
    title: tests/benchmark/main.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
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
  code: '#ifndef _LIB_BENCH

    #define _LIB_BENCH

    #include "benchmark.h"

    #include "../jngen.h"

    #endif'
  dependsOn:
  - tests/benchmark/benchmark.h
  - tests/jngen.h
  isVerificationFile: false
  path: tests/benchmark/bench.h
  requiredBy:
  - tests/benchmark/PowerSeries.cpp
  - tests/benchmark/PolynomialRing.cpp
  - tests/benchmark/main.cpp
  timestamp: '2020-10-28 22:28:43-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tests/benchmark/bench.h
layout: document
redirect_from:
- /library/tests/benchmark/bench.h
- /library/tests/benchmark/bench.h.html
title: tests/benchmark/bench.h
---
