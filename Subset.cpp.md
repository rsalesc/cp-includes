---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/and-convolution.test.cpp
    title: tests/yosupo/and-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/subset-convolution.test.cpp
    title: tests/yosupo/subset-convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/NyaanNyaan/library/tree/master/set-function
  bundledCode: "#line 1 \"Subset.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\n// Source: https://github.com/NyaanNyaan/library/tree/master/set-function\n\
    \ntemplate <typename T>\nvoid superset_zeta_transform(vector<T>& f) {\n  int n\
    \ = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1)\
    \ {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0) {\n        f[j]\
    \ += f[j | i];\n      }\n    }\n  }\n}\n\ntemplate <typename T>\nvoid superset_mobius_transform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j] -= f[j | i];\n      }\n    }\n  }\n}\n\ntemplate <typename T>\n\
    void subset_zeta_transform(vector<T>& f) {\n  int n = f.size();\n  assert((n &\
    \ (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0; j\
    \ < n; j++) {\n      if ((j & i) == 0) {\n        f[j | i] += f[j];\n      }\n\
    \    }\n  }\n}\n\ntemplate <typename T>\nvoid subset_mobius_transform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j | i] -= f[j];\n      }\n    }\n  }\n}\n\ntemplate <typename T>\n\
    vector<T> or_convolution(vector<T> a, vector<T> b) {\n  assert(a.size() == b.size());\n\
    \  subset_zeta_transform(a);\n  subset_zeta_transform(b);\n  for (int i = 0; i\
    \ < (int)a.size(); i++) a[i] *= b[i];\n  subset_mobius_transform(a);\n  return\
    \ a;\n}\n\ntemplate <typename T>\nvector<T> and_convolution(vector<T> a, vector<T>\
    \ b) {\n  assert(a.size() == b.size());\n  superset_zeta_transform(a);\n  superset_zeta_transform(b);\n\
    \  for (int i = 0; i < (int)a.size(); i++) a[i] *= b[i];\n  superset_mobius_transform(a);\n\
    \  return a;\n}\n\ntemplate<typename T>\nvector<vector<T>> ranked_zeta_transform(const\
    \ vector<T>& f) {\n  int N = f.size();\n  assert((N & (N-1)) == 0);\n  int R =\
    \ __builtin_ctz(N);\n  vector<vector<T>> F(R + 1, vector<T>(N));\n  for(int i\
    \ = 0; i < N; i++)\n    F[__builtin_popcount(i)][i] = f[i];\n  for(int i = 0;\
    \ i <= R; i++)\n    subset_zeta_transform(F[i]);\n  return F;\n}\n\ntemplate<typename\
    \ T>\nvector<T> subset_convolution(const vector<T>& a, const vector<T>& b, int\
    \ offset = 0) {\n  int N = a.size();\n  assert(N == b.size());\n  assert((N &\
    \ (N-1)) == 0);\n  int R = __builtin_ctz(N);\n\n  auto A = ranked_zeta_transform(a),\
    \ B = ranked_zeta_transform(b);\n  auto C = vector<vector<T>>(R + 1, vector<T>(N));\n\
    \n  for(int m = 0; m < N; m++) {\n    for(int i = 0; i <= R; i++) {\n      for(int\
    \ j = offset; j <= i; j++) {\n        C[i][m] += A[j][m] * B[i + offset - j][m];\n\
    \      }\n    }\n  }\n\n  for(int i = 0; i <= R; i++)\n    subset_mobius_transform(C[i]);\n\
    \  vector<T> res(N);\n  for(int i = 0; i < N; i++)\n    res[i] = C[__builtin_popcount(i)][i];\n\
    \  return res;\n}\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_SUBSET\n#define _LIB_SUBSET\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\n// Source: https://github.com/NyaanNyaan/library/tree/master/set-function\n\
    \ntemplate <typename T>\nvoid superset_zeta_transform(vector<T>& f) {\n  int n\
    \ = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1)\
    \ {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0) {\n        f[j]\
    \ += f[j | i];\n      }\n    }\n  }\n}\n\ntemplate <typename T>\nvoid superset_mobius_transform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j] -= f[j | i];\n      }\n    }\n  }\n}\n\ntemplate <typename T>\n\
    void subset_zeta_transform(vector<T>& f) {\n  int n = f.size();\n  assert((n &\
    \ (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0; j\
    \ < n; j++) {\n      if ((j & i) == 0) {\n        f[j | i] += f[j];\n      }\n\
    \    }\n  }\n}\n\ntemplate <typename T>\nvoid subset_mobius_transform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j | i] -= f[j];\n      }\n    }\n  }\n}\n\ntemplate <typename T>\n\
    vector<T> or_convolution(vector<T> a, vector<T> b) {\n  assert(a.size() == b.size());\n\
    \  subset_zeta_transform(a);\n  subset_zeta_transform(b);\n  for (int i = 0; i\
    \ < (int)a.size(); i++) a[i] *= b[i];\n  subset_mobius_transform(a);\n  return\
    \ a;\n}\n\ntemplate <typename T>\nvector<T> and_convolution(vector<T> a, vector<T>\
    \ b) {\n  assert(a.size() == b.size());\n  superset_zeta_transform(a);\n  superset_zeta_transform(b);\n\
    \  for (int i = 0; i < (int)a.size(); i++) a[i] *= b[i];\n  superset_mobius_transform(a);\n\
    \  return a;\n}\n\ntemplate<typename T>\nvector<vector<T>> ranked_zeta_transform(const\
    \ vector<T>& f) {\n  int N = f.size();\n  assert((N & (N-1)) == 0);\n  int R =\
    \ __builtin_ctz(N);\n  vector<vector<T>> F(R + 1, vector<T>(N));\n  for(int i\
    \ = 0; i < N; i++)\n    F[__builtin_popcount(i)][i] = f[i];\n  for(int i = 0;\
    \ i <= R; i++)\n    subset_zeta_transform(F[i]);\n  return F;\n}\n\ntemplate<typename\
    \ T>\nvector<T> subset_convolution(const vector<T>& a, const vector<T>& b, int\
    \ offset = 0) {\n  int N = a.size();\n  assert(N == b.size());\n  assert((N &\
    \ (N-1)) == 0);\n  int R = __builtin_ctz(N);\n\n  auto A = ranked_zeta_transform(a),\
    \ B = ranked_zeta_transform(b);\n  auto C = vector<vector<T>>(R + 1, vector<T>(N));\n\
    \n  for(int m = 0; m < N; m++) {\n    for(int i = 0; i <= R; i++) {\n      for(int\
    \ j = offset; j <= i; j++) {\n        C[i][m] += A[j][m] * B[i + offset - j][m];\n\
    \      }\n    }\n  }\n\n  for(int i = 0; i <= R; i++)\n    subset_mobius_transform(C[i]);\n\
    \  vector<T> res(N);\n  for(int i = 0; i < N; i++)\n    res[i] = C[__builtin_popcount(i)][i];\n\
    \  return res;\n}\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: Subset.cpp
  requiredBy: []
  timestamp: '2022-12-14 09:28:49-03:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/and-convolution.test.cpp
  - tests/yosupo/subset-convolution.test.cpp
documentation_of: Subset.cpp
layout: document
redirect_from:
- /library/Subset.cpp
- /library/Subset.cpp.html
title: Subset.cpp
---
