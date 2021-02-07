---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: LinearProgram.cpp
    title: LinearProgram.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Simplex.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\ntemplate <typename DOUBLE> struct LPSolver {\n\
    \  typedef vector<DOUBLE> VD;\n  typedef vector<VD> VVD;\n  typedef vector<int>\
    \ VI;\n\n  constexpr static DOUBLE EPS = 1e-9;\n\n  int m, n;\n  VI B, N;\n  VVD\
    \ D;\n\n  LPSolver(const VVD &A, const VD &b, const VD &c)\n      : m(b.size()),\
    \ n(c.size()), N(n + 1), B(m), D(m + 2, VD(n + 2)) {\n    for (int i = 0; i <\
    \ m; i++)\n      for (int j = 0; j < n; j++)\n        D[i][j] = A[i][j];\n   \
    \ for (int i = 0; i < m; i++) {\n      B[i] = n + i;\n      D[i][n] = -1;\n  \
    \    D[i][n + 1] = b[i];\n    }\n    for (int j = 0; j < n; j++) {\n      N[j]\
    \ = j;\n      D[m][j] = -c[j];\n    }\n    N[n] = -1;\n    D[m + 1][n] = 1;\n\
    \  }\n\n  void Pivot(int r, int s) {\n    for (int i = 0; i < m + 2; i++)\n  \
    \    if (i != r)\n        for (int j = 0; j < n + 2; j++)\n          if (j !=\
    \ s)\n            D[i][j] -= D[r][j] * D[i][s] / D[r][s];\n    for (int j = 0;\
    \ j < n + 2; j++)\n      if (j != s)\n        D[r][j] /= D[r][s];\n    for (int\
    \ i = 0; i < m + 2; i++)\n      if (i != r)\n        D[i][s] /= -D[r][s];\n  \
    \  D[r][s] = 1.0 / D[r][s];\n    swap(B[r], N[s]);\n  }\n\n  bool Simplex(int\
    \ phase) {\n    int x = phase == 1 ? m + 1 : m;\n    while (true) {\n      int\
    \ s = -1;\n      for (int j = 0; j <= n; j++) {\n        if (phase == 2 && N[j]\
    \ == -1)\n          continue;\n        if (s == -1 || D[x][j] < D[x][s] || D[x][j]\
    \ == D[x][s] && N[j] < N[s])\n          s = j;\n      }\n      if (D[x][s] > -EPS)\n\
    \        return true;\n      int r = -1;\n      for (int i = 0; i < m; i++) {\n\
    \        if (D[i][s] < EPS)\n          continue;\n        if (r == -1 || D[i][n\
    \ + 1] / D[i][s] < D[r][n + 1] / D[r][s] ||\n            (D[i][n + 1] / D[i][s])\
    \ == (D[r][n + 1] / D[r][s]) && B[i] < B[r])\n          r = i;\n      }\n    \
    \  if (r == -1)\n        return false;\n      Pivot(r, s);\n    }\n  }\n\n  DOUBLE\
    \ Solve(VD &x) {\n    int r = 0;\n    for (int i = 1; i < m; i++)\n      if (D[i][n\
    \ + 1] < D[r][n + 1])\n        r = i;\n    if (D[r][n + 1] < -EPS) {\n      Pivot(r,\
    \ n);\n      if (!Simplex(1) || D[m + 1][n + 1] < -EPS)\n        return -numeric_limits<DOUBLE>::infinity();\n\
    \      for (int i = 0; i < m; i++)\n        if (B[i] == -1) {\n          int s\
    \ = -1;\n          for (int j = 0; j <= n; j++)\n            if (s == -1 || D[i][j]\
    \ < D[i][s] ||\n                D[i][j] == D[i][s] && N[j] < N[s])\n         \
    \     s = j;\n          Pivot(i, s);\n        }\n    }\n    if (!Simplex(2))\n\
    \      return numeric_limits<DOUBLE>::infinity();\n    x = VD(n);\n    for (int\
    \ i = 0; i < m; i++)\n      if (B[i] < n)\n        x[B[i]] = D[i][n + 1];\n  \
    \  return D[m][n + 1];\n  }\n};\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_SIMPLEX\n#define _LIB_SIMPLEX\n#include <bits/stdc++.h>\n\n\
    namespace lib {\nusing namespace std;\ntemplate <typename DOUBLE> struct LPSolver\
    \ {\n  typedef vector<DOUBLE> VD;\n  typedef vector<VD> VVD;\n  typedef vector<int>\
    \ VI;\n\n  constexpr static DOUBLE EPS = 1e-9;\n\n  int m, n;\n  VI B, N;\n  VVD\
    \ D;\n\n  LPSolver(const VVD &A, const VD &b, const VD &c)\n      : m(b.size()),\
    \ n(c.size()), N(n + 1), B(m), D(m + 2, VD(n + 2)) {\n    for (int i = 0; i <\
    \ m; i++)\n      for (int j = 0; j < n; j++)\n        D[i][j] = A[i][j];\n   \
    \ for (int i = 0; i < m; i++) {\n      B[i] = n + i;\n      D[i][n] = -1;\n  \
    \    D[i][n + 1] = b[i];\n    }\n    for (int j = 0; j < n; j++) {\n      N[j]\
    \ = j;\n      D[m][j] = -c[j];\n    }\n    N[n] = -1;\n    D[m + 1][n] = 1;\n\
    \  }\n\n  void Pivot(int r, int s) {\n    for (int i = 0; i < m + 2; i++)\n  \
    \    if (i != r)\n        for (int j = 0; j < n + 2; j++)\n          if (j !=\
    \ s)\n            D[i][j] -= D[r][j] * D[i][s] / D[r][s];\n    for (int j = 0;\
    \ j < n + 2; j++)\n      if (j != s)\n        D[r][j] /= D[r][s];\n    for (int\
    \ i = 0; i < m + 2; i++)\n      if (i != r)\n        D[i][s] /= -D[r][s];\n  \
    \  D[r][s] = 1.0 / D[r][s];\n    swap(B[r], N[s]);\n  }\n\n  bool Simplex(int\
    \ phase) {\n    int x = phase == 1 ? m + 1 : m;\n    while (true) {\n      int\
    \ s = -1;\n      for (int j = 0; j <= n; j++) {\n        if (phase == 2 && N[j]\
    \ == -1)\n          continue;\n        if (s == -1 || D[x][j] < D[x][s] || D[x][j]\
    \ == D[x][s] && N[j] < N[s])\n          s = j;\n      }\n      if (D[x][s] > -EPS)\n\
    \        return true;\n      int r = -1;\n      for (int i = 0; i < m; i++) {\n\
    \        if (D[i][s] < EPS)\n          continue;\n        if (r == -1 || D[i][n\
    \ + 1] / D[i][s] < D[r][n + 1] / D[r][s] ||\n            (D[i][n + 1] / D[i][s])\
    \ == (D[r][n + 1] / D[r][s]) && B[i] < B[r])\n          r = i;\n      }\n    \
    \  if (r == -1)\n        return false;\n      Pivot(r, s);\n    }\n  }\n\n  DOUBLE\
    \ Solve(VD &x) {\n    int r = 0;\n    for (int i = 1; i < m; i++)\n      if (D[i][n\
    \ + 1] < D[r][n + 1])\n        r = i;\n    if (D[r][n + 1] < -EPS) {\n      Pivot(r,\
    \ n);\n      if (!Simplex(1) || D[m + 1][n + 1] < -EPS)\n        return -numeric_limits<DOUBLE>::infinity();\n\
    \      for (int i = 0; i < m; i++)\n        if (B[i] == -1) {\n          int s\
    \ = -1;\n          for (int j = 0; j <= n; j++)\n            if (s == -1 || D[i][j]\
    \ < D[i][s] ||\n                D[i][j] == D[i][s] && N[j] < N[s])\n         \
    \     s = j;\n          Pivot(i, s);\n        }\n    }\n    if (!Simplex(2))\n\
    \      return numeric_limits<DOUBLE>::infinity();\n    x = VD(n);\n    for (int\
    \ i = 0; i < m; i++)\n      if (B[i] < n)\n        x[B[i]] = D[i][n + 1];\n  \
    \  return D[m][n + 1];\n  }\n};\n} // namespace lib\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: Simplex.cpp
  requiredBy:
  - LinearProgram.cpp
  timestamp: '2020-10-15 12:03:07-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Simplex.cpp
layout: document
redirect_from:
- /library/Simplex.cpp
- /library/Simplex.cpp.html
title: Simplex.cpp
---
