#ifndef _LIB_LINEAR_RECURRENCE
#define _LIB_LINEAR RECURRENCE
#include <bits/stdc++.h>
#include "PolynomialRing.cpp"
#include "Traits.cpp"

namespace lib {
  using namespace std;
namespace linalg {
  namespace {
    using traits::IsRandomIterator;
    using traits::HasRandomIterator;
  }

  template<typename P>
  struct BMSolver {
    typedef BMSolver<P> type;
    typedef typename P::field field_type;
    typedef P poly_type;

    vector<field_type> base;
    vector<field_type> T;
    
    template<
      typename Iterator,
      typename enable_if<IsRandomIterator<Iterator>::value>::type* = nullptr>
    void solve(Iterator begin, Iterator end) {
      auto get = [begin](int i) { return *(begin + i); };

      int n = distance(begin, end);
      
      vector<field_type> C = {1}, B = {1};
      field_type b = 1;
      int L = 0;

      for(int i = 0, x = 1; i < n; i++, x++) {
        // evaluate new element
        field_type d = 0;
        for(size_t j = 0; j < C.size(); j++)
          d += get(i-j) * C[j];
        if(d == 0) continue;
        if(2 * L <= i) {
          auto tmp = C;
          if(C.size() < B.size() + x)
            C.resize(B.size() + x);
          field_type coef = d / b;
          for(size_t j = 0; j < B.size(); j++)
            C[j + x] -= coef * B[j];
          L = i + 1 - L;
          B = tmp;
          b = d;
          x = 0;
        } else {
          if(C.size() < B.size() + x)
            C.resize(B.size() + x);
          field_type coef = d / b;
          for(size_t j = 0; j < B.size(); j++)
            C[j + x] -= coef * B[j];
        }
      }

      T = vector<field_type>((int)C.size() - 1);
      for(size_t i = 0; i < T.size(); i++) T[i] = -C[i+1];
      base = vector<field_type>(begin, end);
    }

    template<
      typename Container,
      typename enable_if<HasRandomIterator<Container>::value>::type* = nullptr>
    void solve(const Container& container) {
      solve(container.begin(), container.end());
    }

    void solve(const initializer_list<field_type>& l) {
      solve(l.begin(), l.end());
    }

    bool solved() const {
      return T.size() > 0 && base.size() >= T.size();
    }

    void ensure(int nsz) const {
      auto* self = const_cast<type*>(this);
      for(int j = base.size(); j < nsz; j++) {
        field_type acc = 0;
        for(int i = 0; i < (int)T.size(); i++)
          acc += base[j - i - 1] * T[i];
        self->base.push_back(acc);
      }
    }

    poly_type mod_function() const {
      poly_type res;
      int m = T.size();
      res[m] = 1;
      for(int i = 0; i < m; i++)
        res[i] = -T[m-i-1];
      return res;
    }

    vector<field_type> compute(long long K, int n) {
      assert(n > 0);
      assert(solved());
      vector<field_type> res;
      int N = T.size();
      int cons = min(n, N);

      if(K < (int)base.size()) {
        for(int j = 0; j < n && K + j < (int)base.size(); j++)
          res.push_back({base[K + j]});

        while((int)res.size() < cons) {
          field_type acc = 0;
          int sz = res.size();
          int mid = min(sz, N);
          for(int i = 0; i < mid; i++)
            acc += res[sz - i - 1] * T[i];
          sz = base.size();
          for(int i = mid; i < N; i++)
            acc += base[sz - 1 - (i - mid)] * T[i];
          res.push_back(acc);
        }
      } else {
        ensure(cons + N - 1);

        poly_type x = poly_type::kth(K, mod_function());

        for(int j = 0; j < cons; j++) {
          field_type acc = 0;
            for(int i = 0; i < N; i++)
              acc += x[i] * base[i + j];
          res.push_back(acc);
        }
      }

      for(int j = res.size(); j < n; j++) {
        field_type acc = 0;
        for(int i = 0; i < N; i++)
          acc += res[j - i - 1] * T[i];
        res.push_back(acc);
      }
      return res;
    }

    field_type compute(long long K) {
      return compute(K, 1)[0];
    }
  };
}  // namespace linalg
}  // namespace lib

#endif
