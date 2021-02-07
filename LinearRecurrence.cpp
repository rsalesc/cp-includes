#ifndef _LIB_LINEAR_RECURRENCE
#define _LIB_LINEAR_RECURRENCE
#include "PolynomialRing.cpp"
#include "Traits.cpp"
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace linalg {
namespace {
using traits::HasRandomIterator;
using traits::IsRandomIterator;
} // namespace

template <typename P> struct BMSolver {
  typedef BMSolver<P> type;
  typedef typename P::field field_type;
  typedef P poly_type;

  vector<field_type> base;
  vector<field_type> T;

  template <
      typename Iterator,
      typename enable_if<IsRandomIterator<Iterator>::value>::type * = nullptr>
  void solve(Iterator begin, Iterator end) {
    auto get = [begin](int i) { return *(begin + i); };

    int n = distance(begin, end);

    vector<field_type> C = {1}, B = {1};
    field_type b = 1;
    int L = 0;

    for (int i = 0, x = 1; i < n; i++, x++) {
      // evaluate new element
      field_type d = 0;
      for (size_t j = 0; j < C.size(); j++)
        d += get(i - j) * C[j];
      if (d == 0)
        continue;
      if (2 * L <= i) {
        auto tmp = C;
        if (C.size() < B.size() + x)
          C.resize(B.size() + x);
        field_type coef = d / b;
        for (size_t j = 0; j < B.size(); j++)
          C[j + x] -= coef * B[j];
        L = i + 1 - L;
        B = tmp;
        b = d;
        x = 0;
      } else {
        if (C.size() < B.size() + x)
          C.resize(B.size() + x);
        field_type coef = d / b;
        for (size_t j = 0; j < B.size(); j++)
          C[j + x] -= coef * B[j];
      }
    }

    T = vector<field_type>((int)C.size() - 1);
    for (size_t i = 0; i < T.size(); i++)
      T[i] = -C[i + 1];
    base = vector<field_type>(begin, end);
  }

  template <
      typename Container,
      typename enable_if<HasRandomIterator<Container>::value>::type * = nullptr>
  void solve(const Container &container) {
    solve(container.begin(), container.end());
  }

  void solve(const initializer_list<field_type> &l) {
    solve(l.begin(), l.end());
  }

  bool solved() const { return T.size() > 0 && base.size() >= T.size(); }

  void ensure(int nsz) const {
    auto *self = const_cast<type *>(this);
    for (int j = base.size(); j < nsz; j++) {
      field_type acc = 0;
      for (int i = 0; i < (int)T.size(); i++)
        acc += base[j - i - 1] * T[i];
      self->base.push_back(acc);
    }
  }

  poly_type mod_function() const {
    poly_type res;
    int m = T.size();
    res[m] = 1;
    for (int i = 0; i < m; i++)
      res[i] = -T[m - i - 1];
    return res;
  }

  vector<field_type> compute(long long K, int n) {
    assert(n > 0);
    assert(solved());
    vector<field_type> res;
    int N = T.size();
    int cons = min(n, N);

    if (K < (int)base.size()) {
      for (int j = 0; j < n && K + j < (int)base.size(); j++)
        res.push_back({base[K + j]});

      while ((int)res.size() < cons) {
        field_type acc = 0;
        int sz = res.size();
        int mid = min(sz, N);
        for (int i = 0; i < mid; i++)
          acc += res[sz - i - 1] * T[i];
        sz = base.size();
        for (int i = mid; i < N; i++)
          acc += base[sz - 1 - (i - mid)] * T[i];
        res.push_back(acc);
      }
    } else {
      ensure(cons + N - 1);

      poly_type x = poly_type::kth(K, mod_function());

      for (int j = 0; j < cons; j++) {
        field_type acc = 0;
        for (int i = 0; i < N; i++)
          acc += x[i] * base[i + j];
        res.push_back(acc);
      }
    }

    for (int j = res.size(); j < n; j++) {
      field_type acc = 0;
      for (int i = 0; i < N; i++)
        acc += res[j - i - 1] * T[i];
      res.push_back(acc);
    }
    return res;
  }

  field_type compute(long long K) { return compute(K, 1)[0]; }
};

template<typename Poly>
struct LinearRecurrence {
  typedef LinearRecurrence<Poly> type;
  typedef typename Poly::field field_type;
  typedef Poly poly_type;

  poly_type P, Q;

  LinearRecurrence(const vector<field_type>& base, vector<field_type> T) {
    assert(base.size() == T.size());
    assert(T.back() == field_type());
    for(auto& x : T) x = -x;
    T.insert(T.begin(), field_type(1));
    Q = poly_type(T);
    P = poly_type(base) % T.size() * Q % ((int)T.size() - 1);
  }

  template<typename I>
  field_type compute(I N) {
    auto P1 = P;
    auto Q1 = Q;
    while(N) {
      auto Q2 = Q1;
      for(int i = 1; i < Q2.size(); i += 2) Q2[i] = -Q2[i];
      auto U = P1 * Q2;
      P1 = poly_type();
      for(int i = N % 2, j = 0; j < Q.degree(); j++, i += 2)
        P1[j] = U[i];
      auto A = Q1 * Q2;
      Q1 = poly_type();
      for(int i = 0, j = 0; j <= Q.degree(); j++, i += 2)
        Q1[j] = A[i];
      N /= 2;
      if(N < P.size()) break;
    }
    return (P1 * Q1.inverse())[N];
  }
};
} // namespace linalg
} // namespace lib

#endif
