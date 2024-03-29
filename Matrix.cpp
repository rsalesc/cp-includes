#ifndef _LIB_MATRIX
#define _LIB_MATRIX
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace linalg {

template <typename T>
struct MultCombiner {
  inline constexpr static T default_value = 0;
  void operator()(T& x, const T& a, const T& b) {
    x += a * b;
  }
};

template <typename T, T def = numeric_limits<T>::max(), typename Cmp = less<T>>
struct OptCombiner {
  inline constexpr static T default_value = def;
  void operator()(T& x, const T& a, const T& b) {
    x = Cmp()(a, b) ? a : b;
  }
};

template <typename T, T def = numeric_limits<T>::max(), typename Cmp = less<T>>
struct OptSumCombiner {
  inline constexpr static T default_value = def;
  void operator()(T& x, const T& a, const T& b) {
    auto sum = a + b;
    x = Cmp()(x, sum) ? x : sum;
  }
};

template <typename T, typename Cmp = less<T>>
struct SafeOptSumCombiner {
  inline constexpr static T default_value = numeric_limits<T>::max();
  void operator()(T& x, const T& a, const T& b) {
    if (a == default_value || b == default_value) return;
    T sum;
    if(!__builtin_add_overflow(a, b, &sum))
      x = Cmp()(x, sum) ? x : sum;
  }
};

template <typename T, typename Combiner = MultCombiner<T>> struct Matrix {
  inline constexpr static T default_value = Combiner::default_value;
  typedef long long large_int;
  typedef initializer_list<initializer_list<T>> nested_list;
  vector<T> g;
  int n, m;

  Matrix() {}
  Matrix(int n, int m) : g(n * m), n(n), m(m) {}
  Matrix(const nested_list &l) : Matrix(l.size(), l.begin()->size()) {
    auto it1 = l.begin();
    for (int i = 0; i < n; i++, ++it1) {
      assert((int)it1->size() == m);
      auto it2 = it1->begin();
      for (int j = 0; j < m; j++, ++it2) {
        (*this)(i, j) = *it2;
      }
    }
  }

  inline int rows() const { return n; }
  inline int cols() const { return m; }
  inline int size() const { return n * m; }
  inline bool is_square() const { return n == m; }
  T operator()(const int i, const int j) const { return g[i * m + j]; }
  T &operator()(const int i, const int j) { return g[i * m + j]; }

  Matrix t() const {
    Matrix res(m, n);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        res(i, j) = (*this)(j, i);
      }
    }
    return res;
  }

  Matrix &operator+=(const Matrix &rhs) {
    assert(n == rhs.n && m == rhs.m);
    int sz = size();
    for (int i = 0; i < sz; i++)
      g[i] += rhs.g[i];
    return *this;
  }
  Matrix &operator-=(const Matrix &rhs) {
    assert(n == rhs.n && m == rhs.m);
    int sz = size();
    for (int i = 0; i < sz; i++)
      g[i] -= rhs.g[i];
    return *this;
  }
  Matrix &operator*=(const Matrix &rhs) {
    assert(n == rhs.n && m == rhs.m);
    int sz = size();
    for (int i = 0; i < sz; i++)
      g[i] *= rhs.g[i];
    return *this;
  }
  Matrix operator-() const {
    Matrix res = *this;
    for (T &t : g)
      t = -t;
    return res;
  }

  friend Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
    Matrix res = lhs;
    return res += rhs;
  }
  friend Matrix<T> operator-(const Matrix &lhs, const Matrix &rhs) {
    Matrix res = lhs;
    return res -= rhs;
  }
  friend Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
    Matrix res = lhs;
    return res *= rhs;
  }
  friend Matrix operator%(const Matrix &lhs, const Matrix &rhs) {
    assert(lhs.m == rhs.n);
    auto res = Matrix::same(lhs.n, rhs.m, Combiner::default_value);
    Combiner combiner;
    for (int i = 0; i < lhs.n; i++) {
      for (int k = 0; k < lhs.m; k++) {
        for (int j = 0; j < rhs.m; j++) {
          combiner(res(i, j), lhs(i, k), rhs(k, j));
        }
      }
    }
    return res;
  }

  static Matrix id(int n) {
    Matrix res(n, n);
    for (int i = 0; i < n; i++)
      res(i, i) = 1;
    return res;
  }

  static Matrix ones(int n, int m) {
    return same(n, m, 1);
  }

  static Matrix same(int n, int m, T x) {
    Matrix res(n, m);
    res.fill(x);
    return res;
  }

  static Matrix _power(const Matrix &a, large_int p) {
    if (p == 1)
      return a;
    Matrix res = power(a, p >> 1);
    res = res % res;
    if (p & 1)
      res = res % a;
    return res;
  }

  static Matrix power(const Matrix &a, large_int p) {
    assert(p >= 0);
    if (p == 0) {
      assert(a.is_square());
      return Matrix::id(a.n);
    } else if (p == 1)
      return a;
    else
      return _power(a, p);
  }

  friend Matrix operator^(const Matrix &lhs, const large_int rhs) {
    return Matrix::power(lhs, rhs);
  }

  inline void fill(T x) {
    for (T &t : g)
      t = x;
  }

  friend bool operator==(const Matrix &lhs, const Matrix &rhs) {
    assert(lhs.n == rhs.n && lhs.m == rhs.m);
    int sz = size();
    for (int i = 0; i < sz; i++)
      if (lhs.g[i] != rhs.g[i])
        return false;
    return true;
  }
  friend bool operator!=(const Matrix &lhs, const Matrix &rhs) {
    return !(lhs == rhs);
  }

  friend istream &operator>>(istream &input, Matrix &var) {
    for (T &t : var.g)
      input >> t;
    return input;
  }
  friend ostream &operator<<(ostream &output, Matrix &var) {
    for (int i = 0; i < var.n; i++) {
      if (i == 0)
        output << "[";
      else
        output << " ";
      for (int j = 0; j < var.m; j++) {
        if (j)
          output << " ";
        output << var(i, j);
      }
      output << "\n";
    }
    return output << "]";
  }
};
} // namespace linalg
} // namespace lib

#endif
