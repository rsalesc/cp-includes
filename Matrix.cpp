#ifndef _LIB_MATRIX
#define _LIB_MATRIX
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace linalg {
  template<typename T>
  struct Matrix {
    typedef long long large_int;
    typedef initializer_list<initializer_list<T>> nested_list;
    vector<T> g;
    int n, m;

    Matrix(int n, int m) : g(n*m), n(n), m(m) {}
    Matrix(const nested_list& l) : Matrix(l.size(), l[0].size()) {
      for(int i = 0; i < n; i++) {
        assert(l[i].size() == m);
        for(int j = 0; j < m; j++) {
          (*this)(i, j) = l[i][j];
        }
      }
    }

    int rows() const { return n; }
    int cols() const { return m; }
    int size() const { return n*m; }
    bool is_square() const { return n == m; }
    T operator()(const int i, const int j) const {
      return g[i*m+j];
    }
    T& operator()(const int i, const int j) {
      return g[i*m+j];
    }

    Matrix<T>& operator+=(const Matrix<T>& rhs) {
      assert(n == rhs.n && m == rhs.m);
      int sz = size();
      for(int i = 0; i < sz; i++)
        g[i] += rhs.g[i];
      return *this;
    }
    Matrix<T>& operator-=(const Matrix<T>& rhs) {
      assert(n == rhs.n && m == rhs.m);
      int sz = size();
      for(int i = 0; i < sz; i++)
        g[i] -= rhs.g[i];
      return *this;
    }
    Matrix<T>& operator*=(const Matrix<T>& rhs) {
      assert(n == rhs.n && m == rhs.m);
      int sz = size();
      for(int i = 0; i < sz; i++)
        g[i] *= rhs.g[i];
      return *this;
    }
    Matrix<T> operator-() const {
      Matrix<T> res = *this;
      for(T& t : g) t = -t;
      return res;
    }

    friend Matrix<T> operator+(const Matrix<T>& lhs, const Matrix<T>& rhs) {
      Matrix<T> res = lhs;
      return res += rhs;
    }
    friend Matrix<T> operator-(const Matrix<T>& lhs, const Matrix<T>& rhs) {
      Matrix<T> res = lhs;
      return res -= rhs;
    }
    friend Matrix<T>operator*(const Matrix<T>& lhs, const Matrix<T>& rhs) {
      Matrix<T> res = lhs;
      return res *= lhs;
    }
    friend Matrix<T> operator%(const Matrix<T>& lhs, const Matrix<T>& rhs) {
      assert(lhs.m == rhs.n);
      Matrix<T> res(lhs.n, rhs.m);
      for(int i = 0; i < lhs.n; i++) {
        for(int k = 0; k < lhs.m; k++) {
          for(int j = 0; j < rhs.m; j++) {
            res(i, j) += res(i, k) * res(k, j);
          }
        }
      }
      return res;
    }

    static Matrix<T> id(int n) {
      Matrix<T> res(n, n);
      for(int i = 0; i < n; i++) res(i, i) = 1;
      return res;
    }

    static Matrix<T> ones(int n, int m) {
      Matrix<T> res(n, m);
      for(T& t : res.g) t = 1;
      return res;
    }

    static Matrix<T> _power(const Matrix& a, large_int p) {
      if(p == 1) return a;
      Matrix<T> res = power(a, p >> 1);
      res = res % res;
      if(p&1) res = res % a;
      return res;
    }

    static Matrix<T> power(const Matrix& a, large_int p) {
      assert(p >= 0);
      if(p == 0) {
        assert(a.is_square());
        return Matrix<T>::id(a.n);
      } else if(p == 1)
        return a;
      else return _power(a, p);
    }

    friend Matrix<T> operator^(const Matrix& lhs, const large_int rhs) {
      return Matrix<T>::power(lhs, rhs);
    }

    void fill(T x) {
      for(T& t : g) t = x;
    }

    friend bool operator==(const Matrix<T>& lhs, const Matrix<T>& rhs) {
      assert(lhs.n == rhs.n && lhs.m == rhs.m);
      int sz = size();
      for(int i = 0; i < sz; i++)
        if(lhs.g[i] != rhs.g[i])
          return false;
      return true;
    }
    friend bool operator!=(const Matrix<T>& lhs, const Matrix<T>& rhs) {
      return !(lhs == rhs);
    }

    friend istream& operator>>(istream& input, Matrix<T>& var) {
      for(T& t : var.g)
        input >> t;
      return input;
    }
    friend ostream& operator<<(ostream& output, Matrix<T>& var) {
      for(int i = 0; i < var.n; i++) {
        if(i == 0) output << "[";
        else output << " ";
        for(int j = 0; j < var.m; j++) {
          if(j) output << " ";
          output << var(i, j);
        }
        output << "\n";
      }
      return output << "]";
    }
  };
}  // namespace linalg
}  // namespace lib

#endif
