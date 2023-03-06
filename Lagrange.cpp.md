---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: BitTricks.cpp
    title: BitTricks.cpp
  - icon: ':heavy_check_mark:'
    path: Combinatorics.cpp
    title: Combinatorics.cpp
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: polynomial/ExponentialSum.cpp
    title: Exponential Sum
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/exp-sum-limit.test.cpp
    title: tests/yosupo/exp-sum-limit.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/exp-sum.test.cpp
    title: tests/yosupo/exp-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Lagrange.cpp\"\n\n\n#include <bits/stdc++.h>\n#line 1 \"\
    Combinatorics.cpp\"\n\n\n#line 1 \"BitTricks.cpp\"\n\n\n#line 4 \"BitTricks.cpp\"\
    \n\nnamespace lib {\nlong long next_power_of_two(long long n) {\n  if (n <= 0)\
    \ return 1;\n  return 1LL << (sizeof(long long) * 8 - 1 - __builtin_clzll(n) +\n\
    \                 ((n & (n - 1LL)) != 0));\n}\n} // namespace lib\n\n\n#line 5\
    \ \"Combinatorics.cpp\"\n\nnamespace lib {\nusing namespace std;\ntemplate<typename\
    \ T>\nstruct Combinatorics {\n    static vector<T> fat;\n    static vector<T>\
    \ inv;\n    static vector<T> ifat;\n\n    static T factorial(int i) {\n      \
    \  ensure_fat(next_power_of_two(i));\n        return fat[i];\n    }\n\n    static\
    \ T inverse(int i) {\n        ensure_inv(next_power_of_two(i));\n        return\
    \ inv[i];\n    }\n\n    static T ifactorial(int i) {\n        ensure_ifat(next_power_of_two(i));\n\
    \        return ifat[i];\n    }\n\n    static T nCr(int n, int K) {\n        if(K\
    \ > n) return 0;\n        ensure_fat(next_power_of_two(n));\n        ensure_ifat(next_power_of_two(n));\n\
    \        return fat[n] * ifat[n-K] * ifat[K];\n    }\n\n    static T arrangement(int\
    \ n, int K) {\n        return nCr(n, K) * factorial(n);\n    }\n\n    static T\
    \ nCr_rep(int n, int K) {\n        return interpolate(n - 1, K);\n    }\n\n  \
    \  static T interpolate(int a, int b) {\n        return nCr(a+b, b);\n    }\n\n\
    \    static void ensure_fat(int i) {\n        int o = fat.size();\n        if(i\
    \ < o) return;\n        fat.resize(i+1);\n        for(int j = o; j <= i; j++)\
    \ fat[j] = fat[j-1]*j;\n    }\n\n    static void ensure_inv(int i) {\n       \
    \ int o = inv.size();\n        if(i < o) return;\n        inv.resize(i+1);\n \
    \       for(int j = o; j <= i; j++) inv[j] = -(inv[T::mod%j] * (T::mod/j));\n\
    \    }\n\n    static void ensure_ifat(int i) {\n        int o = ifat.size();\n\
    \        if(i < o) return;\n        ifat.resize(i+1);\n        ensure_inv(i);\n\
    \        for(int j = o; j <= i; j++) ifat[j] = ifat[j-1]*inv[j];\n    }\n};\n\n\
    template<typename T>\nvector<T> Combinatorics<T>::fat = vector<T>(1, T(1));\n\
    template<typename T>\nvector<T> Combinatorics<T>::inv = vector<T>(2, T(1));\n\
    template<typename T>\nvector<T> Combinatorics<T>::ifat = vector<T>(1, T(1));\n\
    } // namespace lib\n\n\n#line 5 \"Lagrange.cpp\"\n\nnamespace lib {\nusing namespace\
    \ std;\nnamespace linalg {\ntemplate <typename Field> struct PrefixLagrange {\n\
    \  vector<Field> pref, suf;\n  PrefixLagrange() {}\n\n  void ensure(int n) {\n\
    \    int o = pref.size();\n    if (n <= o)\n      return;\n    pref.resize(n),\
    \ suf.resize(n);\n  }\n\n  template <typename T> Field eval(const vector<Field>\
    \ &v, T x) {\n    using C = Combinatorics<Field>;\n    assert(!v.empty());\n \
    \   int d = (int)v.size() - 1;\n    if (x <= d)\n      return v[x];\n\n    ensure(d\
    \ + 1);\n\n    Field a = x;\n    pref[0] = suf[d] = 1;\n    for (T i = 0; i <\
    \ d; i++)\n      pref[i + 1] = pref[i] * a, a -= 1;\n    for (T i = d; i; i--)\n\
    \      suf[i - 1] = suf[i] * a, a += 1;\n\n    Field ans = 0;\n    for (int i\
    \ = 0; i <= d; i++) {\n      Field l = pref[i] * suf[i] * C::ifactorial(i) * C::ifactorial(d-i)\
    \ * v[i];\n      if ((d + i) & 1)\n        l = -l;\n      ans += l;\n    }\n \
    \   return ans;\n  }\n};\n\ntemplate<typename T, typename U>\nT lagrange_iota(const\
    \ vector<T>& f, U n) {\n  static PrefixLagrange<T> lag;\n  return lag.eval(f,\
    \ n);\n}\n\ntemplate<typename T, typename U>\nT lagrange_iota_sum(const vector<T>&\
    \ f, U n) {\n  int m = f.size();\n  vector<T> g(m + 1);\n  for(int i = 1; i <=\
    \ m; i++)\n      g[i] = g[i-1] + f[i-1];\n  return lagrange_iota(g, n);\n}\n}\
    \ // namespace linalg\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_LAGRANGE\n#define _LIB_LAGRANGE\n#include <bits/stdc++.h>\n\
    #include \"Combinatorics.cpp\"\n\nnamespace lib {\nusing namespace std;\nnamespace\
    \ linalg {\ntemplate <typename Field> struct PrefixLagrange {\n  vector<Field>\
    \ pref, suf;\n  PrefixLagrange() {}\n\n  void ensure(int n) {\n    int o = pref.size();\n\
    \    if (n <= o)\n      return;\n    pref.resize(n), suf.resize(n);\n  }\n\n \
    \ template <typename T> Field eval(const vector<Field> &v, T x) {\n    using C\
    \ = Combinatorics<Field>;\n    assert(!v.empty());\n    int d = (int)v.size()\
    \ - 1;\n    if (x <= d)\n      return v[x];\n\n    ensure(d + 1);\n\n    Field\
    \ a = x;\n    pref[0] = suf[d] = 1;\n    for (T i = 0; i < d; i++)\n      pref[i\
    \ + 1] = pref[i] * a, a -= 1;\n    for (T i = d; i; i--)\n      suf[i - 1] = suf[i]\
    \ * a, a += 1;\n\n    Field ans = 0;\n    for (int i = 0; i <= d; i++) {\n   \
    \   Field l = pref[i] * suf[i] * C::ifactorial(i) * C::ifactorial(d-i) * v[i];\n\
    \      if ((d + i) & 1)\n        l = -l;\n      ans += l;\n    }\n    return ans;\n\
    \  }\n};\n\ntemplate<typename T, typename U>\nT lagrange_iota(const vector<T>&\
    \ f, U n) {\n  static PrefixLagrange<T> lag;\n  return lag.eval(f, n);\n}\n\n\
    template<typename T, typename U>\nT lagrange_iota_sum(const vector<T>& f, U n)\
    \ {\n  int m = f.size();\n  vector<T> g(m + 1);\n  for(int i = 1; i <= m; i++)\n\
    \      g[i] = g[i-1] + f[i-1];\n  return lagrange_iota(g, n);\n}\n} // namespace\
    \ linalg\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - bits/stdc++.h
  - Combinatorics.cpp
  - BitTricks.cpp
  isVerificationFile: false
  path: Lagrange.cpp
  requiredBy:
  - polynomial/ExponentialSum.cpp
  timestamp: '2023-03-06 11:24:14-03:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/exp-sum.test.cpp
  - tests/yosupo/exp-sum-limit.test.cpp
documentation_of: Lagrange.cpp
layout: document
redirect_from:
- /library/Lagrange.cpp
- /library/Lagrange.cpp.html
title: Lagrange.cpp
---
