---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Matrix.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace linalg {\n\ntemplate <typename T>\nstruct\
    \ MultCombiner {\n  inline constexpr static T default_value = 0;\n  void operator()(T&\
    \ x, const T& a, const T& b) {\n    x += a * b;\n  }\n};\n\ntemplate <typename\
    \ T, T def = numeric_limits<T>::max(), typename Cmp = less<T>>\nstruct OptCombiner\
    \ {\n  inline constexpr static T default_value = def;\n  void operator()(T& x,\
    \ const T& a, const T& b) {\n    x = Cmp()(a, b) ? a : b;\n  }\n};\n\ntemplate\
    \ <typename T, T def = numeric_limits<T>::max(), typename Cmp = less<T>>\nstruct\
    \ OptSumCombiner {\n  inline constexpr static T default_value = def;\n  void operator()(T&\
    \ x, const T& a, const T& b) {\n    auto sum = a + b;\n    x = Cmp()(x, sum) ?\
    \ x : sum;\n  }\n};\n\ntemplate <typename T, typename Cmp = less<T>>\nstruct SafeOptSumCombiner\
    \ {\n  inline constexpr static T default_value = numeric_limits<T>::max();\n \
    \ void operator()(T& x, const T& a, const T& b) {\n    if (a == default_value\
    \ || b == default_value) return;\n    T sum;\n    if(!__builtin_add_overflow(a,\
    \ b, &sum))\n      x = Cmp()(x, sum) ? x : sum;\n  }\n};\n\ntemplate <typename\
    \ T, typename Combiner = MultCombiner<T>> struct Matrix {\n  inline constexpr\
    \ static T default_value = Combiner::default_value;\n  typedef long long large_int;\n\
    \  typedef initializer_list<initializer_list<T>> nested_list;\n  vector<T> g;\n\
    \  int n, m;\n\n  Matrix() {}\n  Matrix(int n, int m) : g(n * m), n(n), m(m) {}\n\
    \  Matrix(const nested_list &l) : Matrix(l.size(), l.begin()->size()) {\n    auto\
    \ it1 = l.begin();\n    for (int i = 0; i < n; i++, ++it1) {\n      assert((int)it1->size()\
    \ == m);\n      auto it2 = it1->begin();\n      for (int j = 0; j < m; j++, ++it2)\
    \ {\n        (*this)(i, j) = *it2;\n      }\n    }\n  }\n\n  inline int rows()\
    \ const { return n; }\n  inline int cols() const { return m; }\n  inline int size()\
    \ const { return n * m; }\n  inline bool is_square() const { return n == m; }\n\
    \  T operator()(const int i, const int j) const { return g[i * m + j]; }\n  T\
    \ &operator()(const int i, const int j) { return g[i * m + j]; }\n\n  Matrix t()\
    \ const {\n    Matrix res(m, n);\n    for (int i = 0; i < m; i++) {\n      for\
    \ (int j = 0; j < n; j++) {\n        res(i, j) = (*this)(j, i);\n      }\n   \
    \ }\n    return res;\n  }\n\n  Matrix &operator+=(const Matrix &rhs) {\n    assert(n\
    \ == rhs.n && m == rhs.m);\n    int sz = size();\n    for (int i = 0; i < sz;\
    \ i++)\n      g[i] += rhs.g[i];\n    return *this;\n  }\n  Matrix &operator-=(const\
    \ Matrix &rhs) {\n    assert(n == rhs.n && m == rhs.m);\n    int sz = size();\n\
    \    for (int i = 0; i < sz; i++)\n      g[i] -= rhs.g[i];\n    return *this;\n\
    \  }\n  Matrix &operator*=(const Matrix &rhs) {\n    assert(n == rhs.n && m ==\
    \ rhs.m);\n    int sz = size();\n    for (int i = 0; i < sz; i++)\n      g[i]\
    \ *= rhs.g[i];\n    return *this;\n  }\n  Matrix operator-() const {\n    Matrix\
    \ res = *this;\n    for (T &t : g)\n      t = -t;\n    return res;\n  }\n\n  friend\
    \ Matrix operator+(const Matrix &lhs, const Matrix &rhs) {\n    Matrix res = lhs;\n\
    \    return res += rhs;\n  }\n  friend Matrix<T> operator-(const Matrix &lhs,\
    \ const Matrix &rhs) {\n    Matrix res = lhs;\n    return res -= rhs;\n  }\n \
    \ friend Matrix operator*(const Matrix &lhs, const Matrix &rhs) {\n    Matrix\
    \ res = lhs;\n    return res *= rhs;\n  }\n  friend Matrix operator%(const Matrix\
    \ &lhs, const Matrix &rhs) {\n    assert(lhs.m == rhs.n);\n    auto res = Matrix::same(lhs.n,\
    \ rhs.m, Combiner::default_value);\n    Combiner combiner;\n    for (int i = 0;\
    \ i < lhs.n; i++) {\n      for (int k = 0; k < lhs.m; k++) {\n        for (int\
    \ j = 0; j < rhs.m; j++) {\n          combiner(res(i, j), lhs(i, k), rhs(k, j));\n\
    \        }\n      }\n    }\n    return res;\n  }\n\n  static Matrix id(int n)\
    \ {\n    Matrix res(n, n);\n    for (int i = 0; i < n; i++)\n      res(i, i) =\
    \ 1;\n    return res;\n  }\n\n  static Matrix ones(int n, int m) {\n    return\
    \ same(n, m, 1);\n  }\n\n  static Matrix same(int n, int m, T x) {\n    Matrix\
    \ res(n, m);\n    res.fill(x);\n    return res;\n  }\n\n  static Matrix _power(const\
    \ Matrix &a, large_int p) {\n    if (p == 1)\n      return a;\n    Matrix res\
    \ = power(a, p >> 1);\n    res = res % res;\n    if (p & 1)\n      res = res %\
    \ a;\n    return res;\n  }\n\n  static Matrix power(const Matrix &a, large_int\
    \ p) {\n    assert(p >= 0);\n    if (p == 0) {\n      assert(a.is_square());\n\
    \      return Matrix::id(a.n);\n    } else if (p == 1)\n      return a;\n    else\n\
    \      return _power(a, p);\n  }\n\n  friend Matrix operator^(const Matrix &lhs,\
    \ const large_int rhs) {\n    return Matrix::power(lhs, rhs);\n  }\n\n  inline\
    \ void fill(T x) {\n    for (T &t : g)\n      t = x;\n  }\n\n  friend bool operator==(const\
    \ Matrix &lhs, const Matrix &rhs) {\n    assert(lhs.n == rhs.n && lhs.m == rhs.m);\n\
    \    int sz = size();\n    for (int i = 0; i < sz; i++)\n      if (lhs.g[i] !=\
    \ rhs.g[i])\n        return false;\n    return true;\n  }\n  friend bool operator!=(const\
    \ Matrix &lhs, const Matrix &rhs) {\n    return !(lhs == rhs);\n  }\n\n  friend\
    \ istream &operator>>(istream &input, Matrix &var) {\n    for (T &t : var.g)\n\
    \      input >> t;\n    return input;\n  }\n  friend ostream &operator<<(ostream\
    \ &output, Matrix &var) {\n    for (int i = 0; i < var.n; i++) {\n      if (i\
    \ == 0)\n        output << \"[\";\n      else\n        output << \" \";\n    \
    \  for (int j = 0; j < var.m; j++) {\n        if (j)\n          output << \" \"\
    ;\n        output << var(i, j);\n      }\n      output << \"\\n\";\n    }\n  \
    \  return output << \"]\";\n  }\n};\n} // namespace linalg\n} // namespace lib\n\
    \n\n"
  code: "#ifndef _LIB_MATRIX\n#define _LIB_MATRIX\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace linalg {\n\ntemplate <typename T>\nstruct\
    \ MultCombiner {\n  inline constexpr static T default_value = 0;\n  void operator()(T&\
    \ x, const T& a, const T& b) {\n    x += a * b;\n  }\n};\n\ntemplate <typename\
    \ T, T def = numeric_limits<T>::max(), typename Cmp = less<T>>\nstruct OptCombiner\
    \ {\n  inline constexpr static T default_value = def;\n  void operator()(T& x,\
    \ const T& a, const T& b) {\n    x = Cmp()(a, b) ? a : b;\n  }\n};\n\ntemplate\
    \ <typename T, T def = numeric_limits<T>::max(), typename Cmp = less<T>>\nstruct\
    \ OptSumCombiner {\n  inline constexpr static T default_value = def;\n  void operator()(T&\
    \ x, const T& a, const T& b) {\n    auto sum = a + b;\n    x = Cmp()(x, sum) ?\
    \ x : sum;\n  }\n};\n\ntemplate <typename T, typename Cmp = less<T>>\nstruct SafeOptSumCombiner\
    \ {\n  inline constexpr static T default_value = numeric_limits<T>::max();\n \
    \ void operator()(T& x, const T& a, const T& b) {\n    if (a == default_value\
    \ || b == default_value) return;\n    T sum;\n    if(!__builtin_add_overflow(a,\
    \ b, &sum))\n      x = Cmp()(x, sum) ? x : sum;\n  }\n};\n\ntemplate <typename\
    \ T, typename Combiner = MultCombiner<T>> struct Matrix {\n  inline constexpr\
    \ static T default_value = Combiner::default_value;\n  typedef long long large_int;\n\
    \  typedef initializer_list<initializer_list<T>> nested_list;\n  vector<T> g;\n\
    \  int n, m;\n\n  Matrix() {}\n  Matrix(int n, int m) : g(n * m), n(n), m(m) {}\n\
    \  Matrix(const nested_list &l) : Matrix(l.size(), l.begin()->size()) {\n    auto\
    \ it1 = l.begin();\n    for (int i = 0; i < n; i++, ++it1) {\n      assert((int)it1->size()\
    \ == m);\n      auto it2 = it1->begin();\n      for (int j = 0; j < m; j++, ++it2)\
    \ {\n        (*this)(i, j) = *it2;\n      }\n    }\n  }\n\n  inline int rows()\
    \ const { return n; }\n  inline int cols() const { return m; }\n  inline int size()\
    \ const { return n * m; }\n  inline bool is_square() const { return n == m; }\n\
    \  T operator()(const int i, const int j) const { return g[i * m + j]; }\n  T\
    \ &operator()(const int i, const int j) { return g[i * m + j]; }\n\n  Matrix t()\
    \ const {\n    Matrix res(m, n);\n    for (int i = 0; i < m; i++) {\n      for\
    \ (int j = 0; j < n; j++) {\n        res(i, j) = (*this)(j, i);\n      }\n   \
    \ }\n    return res;\n  }\n\n  Matrix &operator+=(const Matrix &rhs) {\n    assert(n\
    \ == rhs.n && m == rhs.m);\n    int sz = size();\n    for (int i = 0; i < sz;\
    \ i++)\n      g[i] += rhs.g[i];\n    return *this;\n  }\n  Matrix &operator-=(const\
    \ Matrix &rhs) {\n    assert(n == rhs.n && m == rhs.m);\n    int sz = size();\n\
    \    for (int i = 0; i < sz; i++)\n      g[i] -= rhs.g[i];\n    return *this;\n\
    \  }\n  Matrix &operator*=(const Matrix &rhs) {\n    assert(n == rhs.n && m ==\
    \ rhs.m);\n    int sz = size();\n    for (int i = 0; i < sz; i++)\n      g[i]\
    \ *= rhs.g[i];\n    return *this;\n  }\n  Matrix operator-() const {\n    Matrix\
    \ res = *this;\n    for (T &t : g)\n      t = -t;\n    return res;\n  }\n\n  friend\
    \ Matrix operator+(const Matrix &lhs, const Matrix &rhs) {\n    Matrix res = lhs;\n\
    \    return res += rhs;\n  }\n  friend Matrix<T> operator-(const Matrix &lhs,\
    \ const Matrix &rhs) {\n    Matrix res = lhs;\n    return res -= rhs;\n  }\n \
    \ friend Matrix operator*(const Matrix &lhs, const Matrix &rhs) {\n    Matrix\
    \ res = lhs;\n    return res *= rhs;\n  }\n  friend Matrix operator%(const Matrix\
    \ &lhs, const Matrix &rhs) {\n    assert(lhs.m == rhs.n);\n    auto res = Matrix::same(lhs.n,\
    \ rhs.m, Combiner::default_value);\n    Combiner combiner;\n    for (int i = 0;\
    \ i < lhs.n; i++) {\n      for (int k = 0; k < lhs.m; k++) {\n        for (int\
    \ j = 0; j < rhs.m; j++) {\n          combiner(res(i, j), lhs(i, k), rhs(k, j));\n\
    \        }\n      }\n    }\n    return res;\n  }\n\n  static Matrix id(int n)\
    \ {\n    Matrix res(n, n);\n    for (int i = 0; i < n; i++)\n      res(i, i) =\
    \ 1;\n    return res;\n  }\n\n  static Matrix ones(int n, int m) {\n    return\
    \ same(n, m, 1);\n  }\n\n  static Matrix same(int n, int m, T x) {\n    Matrix\
    \ res(n, m);\n    res.fill(x);\n    return res;\n  }\n\n  static Matrix _power(const\
    \ Matrix &a, large_int p) {\n    if (p == 1)\n      return a;\n    Matrix res\
    \ = power(a, p >> 1);\n    res = res % res;\n    if (p & 1)\n      res = res %\
    \ a;\n    return res;\n  }\n\n  static Matrix power(const Matrix &a, large_int\
    \ p) {\n    assert(p >= 0);\n    if (p == 0) {\n      assert(a.is_square());\n\
    \      return Matrix::id(a.n);\n    } else if (p == 1)\n      return a;\n    else\n\
    \      return _power(a, p);\n  }\n\n  friend Matrix operator^(const Matrix &lhs,\
    \ const large_int rhs) {\n    return Matrix::power(lhs, rhs);\n  }\n\n  inline\
    \ void fill(T x) {\n    for (T &t : g)\n      t = x;\n  }\n\n  friend bool operator==(const\
    \ Matrix &lhs, const Matrix &rhs) {\n    assert(lhs.n == rhs.n && lhs.m == rhs.m);\n\
    \    int sz = size();\n    for (int i = 0; i < sz; i++)\n      if (lhs.g[i] !=\
    \ rhs.g[i])\n        return false;\n    return true;\n  }\n  friend bool operator!=(const\
    \ Matrix &lhs, const Matrix &rhs) {\n    return !(lhs == rhs);\n  }\n\n  friend\
    \ istream &operator>>(istream &input, Matrix &var) {\n    for (T &t : var.g)\n\
    \      input >> t;\n    return input;\n  }\n  friend ostream &operator<<(ostream\
    \ &output, Matrix &var) {\n    for (int i = 0; i < var.n; i++) {\n      if (i\
    \ == 0)\n        output << \"[\";\n      else\n        output << \" \";\n    \
    \  for (int j = 0; j < var.m; j++) {\n        if (j)\n          output << \" \"\
    ;\n        output << var(i, j);\n      }\n      output << \"\\n\";\n    }\n  \
    \  return output << \"]\";\n  }\n};\n} // namespace linalg\n} // namespace lib\n\
    \n#endif\n"
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: Matrix.cpp
  requiredBy: []
  timestamp: '2023-02-24 16:39:19-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Matrix.cpp
layout: document
redirect_from:
- /library/Matrix.cpp
- /library/Matrix.cpp.html
title: Matrix.cpp
---
