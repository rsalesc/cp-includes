#ifndef _LIB_POLYNOMIAL_RING
#define _LIB_POLYNOMIAL_RING
#include <bits/stdc++.h>
#include "ModularInteger.cpp"
#include "Traits.cpp"
#include "FFT.cpp"
#include "Math.cpp"

namespace lib {
  using namespace std;
namespace math {
namespace poly {

  namespace {
    /// keep caide
    using traits::IsInputIterator;
    /// keep caide
    using traits::HasInputIterator;
  }

  struct FastMultiplication {
    template<typename Field>
    vector<Field> operator()(const vector<Field>& a, const vector<Field>& b) const {
      return linalg::rounded_fft(a, b);
    }
  };
  
  struct SafeMultiplication {
    template<typename Field>
    vector<Field> operator()(const vector<Field>& a, const vector<Field>& b) const {
      return linalg::mod_split_fft(a, b);
    };
  };

  struct NaiveMultiplication {
    template<typename Field>
    vector<Field> operator()(const vector<Field>& a, const vector<Field>& b) const {
      vector<Field> res(a.size() + b.size());
      for(size_t i = 0; i < a.size(); i++) {
        for(size_t j = 0; j < b.size(); j++) {
          res[i + j] += a[i] * b[j];
        }
      }
      return res;
    }
  };

  template<typename P>
  struct DefaultPowerOp {
    int mod;
    DefaultPowerOp(int mod) : mod(mod) {}
    P operator()() const { return P(1); }
    P operator()(const P& a) const { return a % mod; }
    void operator()(P& x, const P& a, long long cur) const {
      (x *= x) %= mod;
      if(cur & 1)
        (x *= a) %= mod;
    }
  };

  template<typename P>
  struct ModPowerOp {
    const P& mod;
    ModPowerOp(const P& p) : mod(p) {}
    P operator()() const { return P(1); }
    P operator()(const P& a) { return a % mod; }
    void operator()(P& x, const P& a, long long cur) const {
      (x *= x) %= mod;
      if(cur & 1)
        (x *= a) %= mod;
    }
  };

  template<typename P>
  struct ModShiftPowerOp {
    const P& mod;
    ModShiftPowerOp(const P& p) : mod(p) {}
    P operator()() const { return P(1); }
    P operator()(const P& a) { return a % mod; }
    void operator()(P& x, const P& a, long long cur) const {
      //if(cur < mod.degree())
        //x = P::kth(cur);
      if(cur & 1)
        (x *= (x << 1)) %= mod;
      else
        (x *= x) %= mod;
    }
  };

  template<typename Field, typename Mult>
  struct Polynomial {
    typedef Polynomial<Field, Mult> type;
    typedef Field field;
    vector<Field> p;
    
    Polynomial() : p(0) {}
    explicit Polynomial(Field x): p(1, x) {}

    template<
      typename Iterator,
      typename enable_if<IsInputIterator<Iterator>::value>::type* = nullptr>
    Polynomial(Iterator begin, Iterator end) : p(distance(begin, end)) {
      int i = 0;
      for(auto it = begin; it != end; ++it, ++i)
        p[i] = *it;
      normalize();
    }

    template<
      typename Container,
      typename enable_if<HasInputIterator<Container>::value>::type* = nullptr>
    Polynomial(const Container& container) 
      : Polynomial(container.begin(), container.end()) {}

    Polynomial(const initializer_list<Field>& v) 
      : Polynomial(v.begin(), v.end()) {}

    static type from_root(const Field& root) {
      return Polynomial({-root, 1});
    }

    void normalize() const {
      type* self = const_cast<type*>(this);
      int sz = self->p.size();
      while(sz > 0 && self->p[sz-1] == 0) sz--;
      if(sz != (int)self->p.size())
        self->p.resize(sz);
    }

    inline int size() const { return p.size(); }
    inline int degree() const { return max((int)p.size()-1, 0); }
    bool null() const {
      for(Field x : p)
        if(x != 0) return false;
      return true;
    }

    inline Field operator[](const int i) const { 
      if(i >= size())
        return 0;
      return p[i]; 
    }
    inline Field& operator[](const int i) {
      if(i >= size())
        p.resize(i + 1);
      return p[i]; 
    }

    type& operator+=(const type& rhs) {
      if(rhs.size() > size())
        p.resize(rhs.size());
      int sz = size();
      for(int i = 0; i < sz; i++)
        p[i] += rhs[i];
      normalize();
      return *this;
    }

    type& operator-=(const type& rhs) {
      if(rhs.size() > size())
        p.resize(rhs.size());
      int sz = size();
      for(int i = 0; i < sz; i++)
        p[i] -= rhs[i];
      normalize();
      return *this;
    }

    type& operator*=(const type& rhs) {
      p = Mult()(p, rhs.p);
      normalize();
      return *this;
    }

    type& operator*=(const Field& rhs) {
      int sz = size();
      for(int i = 0; i < sz; i++)
        p[i] *= rhs;
      normalize();
      return *this;
    }

    type& operator/=(const Field& rhs) {
      int sz = size();
      for(int i = 0; i < sz; i++)
        p[i] /= rhs;
      normalize();
      return *this;
    }

    type& operator<<=(const int rhs) {
      if(rhs < 0) return *this >>= rhs;
      if(rhs == 0) return *this;
      int sz = size();
      p.resize(sz + rhs);
      for(int i = sz-1; i >= 0; i--)
        p[i + rhs] = p[i];
      fill_n(p.begin(), rhs, 0);
      return *this;
    }

    type& operator>>=(const int rhs) {
      if(rhs < 0) return *this <<= rhs;
      if(rhs == 0) return *this;
      int sz = size();
      if(rhs >= sz) {
        p.clear();
        return *this;
      }
      for(int i = rhs; i < sz; i++)
        p[i - rhs] = p[i];
      p.resize(sz - rhs);
      return *this;
    }

    type& operator%=(const int rhs) {
      if(rhs < size())
        p.resize(rhs);
      normalize();
      return *this;
    }

    type& operator/=(const type& rhs) {
      return *this = *this / rhs;
    }

    type operator%=(const type& rhs) {
      return *this = *this % rhs;
    }

    type operator+(const type& rhs) const {
      type res = *this;
      return res += rhs;
    }

    type operator-(const type& rhs) const {
      type res = *this;
      return res -= rhs;
    }

    type operator*(const type& rhs) const {
      return type(Mult()(p, rhs.p));
    }

    type operator*(const Field& rhs) const {
      type res = *this;
      return res *= rhs;
    }

    type operator/(const Field& rhs) const {
      type res = *this;
      return res /= rhs;
    }

    type operator<<(const int rhs) const {
      type res = *this;
      return res <<= rhs;
    }

    type operator>>(const int rhs) const {
      type res = *this;
      return res >>= rhs;
    }

    type operator%(const int rhs) const {
      return Polynomial(p.begin(), p.begin() + min(rhs, size()));
    }

    type operator/(const type& rhs) const {
      return type::divmod(*this, rhs).first;
    }

    type operator%(const type& rhs) const {
      return type::divmod(*this, rhs).second;
    }

    bool operator==(const type& rhs) const {
      normalize();
      rhs.normalize();
      return p == rhs.p;
    }

    type inverse() const {
      int sz = size();
      if(sz == 0)
        return type();
      if(sz == 1) {
        assert(p[0] != 0);
        return type(p[0].inverse());
      }
      type q = (*this % ((sz+1)/2)).inverse();
      q -= (*this * q % sz - type(1)) * q % sz;
      return q % sz;
    }

    type reciprocal() const {
      normalize();
      return type(p.rbegin(), p.rend());
    }

    type integral() const {
      int sz = size();
      if(sz == 0) return {};
      type res = *this;
      for(int i = sz; i; i--) {
        res[i] = res[i-1] / i;
      }
      res[0] = 0;
      res.normalize();
      return res;
    }

    type derivative() const {
      int sz = size();
      if(sz == 0) return {};
      type res = *this;
      for(int i = 0; i + 1 < sz; i++) {
        res[i] = res[i+1] * (i + 1);
      }
      res.p.back() = 0;
      res.normalize();
      return res;
    }

    static pair<type, type> divmod(const type& a, const type& b) {
      a.normalize();
      b.normalize();
      int m = a.size();
      int n = b.size();
      if(m < n) return {Polynomial(), a};
      type ar = a.reciprocal();
      type bri = (b.reciprocal() % (m - n + 1)).inverse();
      type q = (ar * bri % (m - n + 1)).reciprocal();
      type r = a - b * q;

      if(r.degree() >= b.degree()) {
        q += divmod(r, b).first;
        r = a - b * q;
      }

      return {q, r};
    }

    static type power(const type& a, long long n, const int mod) {
      return math::generic_power<type>(a, n, DefaultPowerOp<type>(mod));
    }

    static type power(const type& a, long long n, const type& mod) {
      return math::generic_power<type>(a, n, ModPowerOp<type>(mod));
    }

    static type kth(int K) {
      return type(1) << K;
    }

    static type kth(long long K, const type& mod) {
      return math::generic_power<type>(type(1) << 1, K, ModShiftPowerOp<type>(mod));
    }

    friend ostream& operator<<(ostream& output, const type& var) {
      output << "[";
      int sz = var.size();
      for(int i = sz-1; i >= 0; i--) {
        output << var[i];
        if(i) output << " ";
      }
      return output << "]";
    }
  };
}  // namespace poly
/// keep caide
using poly::Polynomial;
}  // namespace math
}  // namespace lib

#endif
