---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: RollingHash.cpp
    title: RollingHash.cpp
  - icon: ':warning:'
    path: Treap.cpp
    title: Treap.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Random.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace rng {\nstruct Generator {\n  mt19937\
    \ rng;\n  Generator() {\n    seed_seq seq {\n      (uint64_t) chrono::duration_cast<chrono::nanoseconds>(\n\
    \          chrono::high_resolution_clock::now().time_since_epoch())\n        \
    \  .count(),\n#if __cplusplus > 201300\n          (uint64_t)make_unique<char>().get(),\n\
    #else\n          (uint64_t)unique_ptr<char>(new char).get(),\n#endif\n       \
    \   (uint64_t)__builtin_ia32_rdtsc()\n    };\n    rng = mt19937(seq);\n  }\n \
    \ Generator(seed_seq &seq) : rng(seq) {}\n\n  template <typename T,\n        \
    \    typename enable_if<is_integral<T>::value>::type * = nullptr>\n  inline T\
    \ uniform_int(T L, T R) {\n    return uniform_int_distribution<T>(L, R)(rng);\n\
    \  }\n\n  template <typename T> inline T uniform_int(T N) {\n    return uniform_int(T(),\
    \ N - 1);\n  }\n\n  template <typename T> inline T uniform_real(T N) {\n    return\
    \ uniform_real(0.0, static_cast<double>(N));\n  }\n\n  template <typename T> inline\
    \ T uniform_real(T L, T R) {\n    return uniform_real_distribution<double>(static_cast<double>(L),\n\
    \                                             static_cast<double>(R))(rng);\n\
    \  }\n\n  inline double uniform_real() { return uniform_real(0.0, 1.0); }\n};\n\
    \nstatic Generator gen = Generator();\n} // namespace rng\nstatic rng::Generator\
    \ &rng_gen = rng::gen;\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_RANDOM\n#define _LIB_RANDOM\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace rng {\nstruct Generator {\n  mt19937\
    \ rng;\n  Generator() {\n    seed_seq seq {\n      (uint64_t) chrono::duration_cast<chrono::nanoseconds>(\n\
    \          chrono::high_resolution_clock::now().time_since_epoch())\n        \
    \  .count(),\n#if __cplusplus > 201300\n          (uint64_t)make_unique<char>().get(),\n\
    #else\n          (uint64_t)unique_ptr<char>(new char).get(),\n#endif\n       \
    \   (uint64_t)__builtin_ia32_rdtsc()\n    };\n    rng = mt19937(seq);\n  }\n \
    \ Generator(seed_seq &seq) : rng(seq) {}\n\n  template <typename T,\n        \
    \    typename enable_if<is_integral<T>::value>::type * = nullptr>\n  inline T\
    \ uniform_int(T L, T R) {\n    return uniform_int_distribution<T>(L, R)(rng);\n\
    \  }\n\n  template <typename T> inline T uniform_int(T N) {\n    return uniform_int(T(),\
    \ N - 1);\n  }\n\n  template <typename T> inline T uniform_real(T N) {\n    return\
    \ uniform_real(0.0, static_cast<double>(N));\n  }\n\n  template <typename T> inline\
    \ T uniform_real(T L, T R) {\n    return uniform_real_distribution<double>(static_cast<double>(L),\n\
    \                                             static_cast<double>(R))(rng);\n\
    \  }\n\n  inline double uniform_real() { return uniform_real(0.0, 1.0); }\n};\n\
    \nstatic Generator gen = Generator();\n} // namespace rng\nstatic rng::Generator\
    \ &rng_gen = rng::gen;\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: Random.cpp
  requiredBy:
  - Treap.cpp
  - RollingHash.cpp
  timestamp: '2022-12-14 09:28:49-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Random.cpp
layout: document
redirect_from:
- /library/Random.cpp
- /library/Random.cpp.html
title: Random.cpp
---
