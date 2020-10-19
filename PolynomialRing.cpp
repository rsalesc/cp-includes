#ifndef _LIB_POLYNOMIAL_RING
#define _LIB_POLYNOMIAL_RING
#include "Epsilon.cpp"
#include "Math.cpp"
#include "ModularInteger.cpp"
#include "Traits.cpp"
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace math {
namespace poly {

namespace {
/// keep caide
using traits::IsInputIterator;
/// keep caide
using traits::HasInputIterator;
} // namespace

template <typename P> struct DefaultPowerOp {
  int mod;
  DefaultPowerOp(int mod) : mod(mod) {}
  P operator()() const { return P(1); }
  P operator()(const P &a) const { return a % mod; }
  void operator()(P &x, const P &a, long long cur) const {
    (x *= x) %= mod;
    if (cur & 1)
      (x *= a) %= mod;
  }
};

template <typename P> struct ModPowerOp {
  const P &mod;
  ModPowerOp(const P &p) : mod(p) {}
  P operator()() const { return P(1); }
  P operator()(const P &a) { return a % mod; }
  void operator()(P &x, const P &a, long long cur) const {
    (x *= x) %= mod;
    if (cur & 1)
      (x *= a) %= mod;
  }
};

template <typename P> struct ModShiftPowerOp {
  const P &mod;
  ModShiftPowerOp(const P &p) : mod(p) {}
  P operator()() const { return P(1); }
  P operator()(const P &a) { return a % mod; }
  void operator()(P &x, const P &a, long long cur) const {
    // if(cur < mod.degree())
    // x = P::kth(cur);
    if (cur & 1)
      (x *= (x << 1)) %= mod;
    else
      (x *= x) %= mod;
  }
};

struct DefaultDivmod;
struct NaiveDivmod;

template <typename Field, typename Mult, typename Divmod = DefaultDivmod>
struct Polynomial {
  constexpr static bool NaiveMod = is_same<Divmod, NaiveDivmod>::value;
  typedef Polynomial<Field, Mult, Divmod> type;
  typedef Field field;
  vector<Field> p;

  Polynomial() : p(0) {}
  explicit Polynomial(Field x) : p(1, x) {}

  template <
      typename Iterator,
      typename enable_if<IsInputIterator<Iterator>::value>::type * = nullptr>
  Polynomial(Iterator begin, Iterator end) : p(distance(begin, end)) {
    int i = 0;
    for (auto it = begin; it != end; ++it, ++i)
      p[i] = *it;
    normalize();
  }

  template <
      typename Container,
      typename enable_if<HasInputIterator<Container>::value>::type * = nullptr>
  Polynomial(const Container &container)
      : Polynomial(container.begin(), container.end()) {}

  Polynomial(const initializer_list<Field> &v)
      : Polynomial(v.begin(), v.end()) {}

  static type from_root(const Field &root) { return Polynomial({-root, 1}); }

  void normalize() const {
    type *self = const_cast<type *>(this);
    int sz = self->p.size();
    while (sz > 0 && Epsilon<>().null(self->p[sz - 1]))
      sz--;
    if (sz != (int)self->p.size())
      self->p.resize(sz);
  }

  inline int size() const { return p.size(); }
  inline int degree() const { return max((int)p.size() - 1, 0); }
  bool null() const {
    for (Field x : p)
      if (!Epsilon<>().null(x))
        return false;
    return true;
  }

  inline Field operator[](const int i) const {
    if (i >= size())
      return 0;
    return p[i];
  }
  inline Field &operator[](const int i) {
    if (i >= size())
      p.resize(i + 1);
    return p[i];
  }

  Field operator()(const Field &x) const {
    if (null())
      return Field();
    Field acc = p.back();
    for (int i = (int)size() - 2; i >= 0; i--) {
      acc *= x;
      acc += p[i];
    }
    return acc;
  }

  type substr(int i, int sz) const {
    int j = min(sz + i, size());
    i = min(i, size());
    if(i >= j) return type();
    return type(begin(p)+i, begin(p)+j);
  }

  type &operator+=(const type &rhs) {
    if (rhs.size() > size())
      p.resize(rhs.size());
    int sz = size();
    for (int i = 0; i < sz; i++)
      p[i] += rhs[i];
    normalize();
    return *this;
  }

  type &operator-=(const type &rhs) {
    if (rhs.size() > size())
      p.resize(rhs.size());
    int sz = size();
    for (int i = 0; i < sz; i++)
      p[i] -= rhs[i];
    normalize();
    return *this;
  }

  type &operator*=(const type &rhs) {
    p = Mult()(p, rhs.p);
    normalize();
    return *this;
  }

  type &operator*=(const Field &rhs) {
    int sz = size();
    for (int i = 0; i < sz; i++)
      p[i] *= rhs;
    normalize();
    return *this;
  }

  type &operator/=(const Field &rhs) {
    int sz = size();
    for (int i = 0; i < sz; i++)
      p[i] /= rhs;
    normalize();
    return *this;
  }

  type &operator<<=(const int rhs) {
    if (rhs < 0)
      return *this >>= rhs;
    if (rhs == 0)
      return *this;
    int sz = size();
    p.resize(sz + rhs);
    for (int i = sz - 1; i >= 0; i--)
      p[i + rhs] = p[i];
    fill_n(p.begin(), rhs, 0);
    return *this;
  }

  type &operator>>=(const int rhs) {
    if (rhs < 0)
      return *this <<= rhs;
    if (rhs == 0)
      return *this;
    int sz = size();
    if (rhs >= sz) {
      p.clear();
      return *this;
    }
    for (int i = rhs; i < sz; i++)
      p[i - rhs] = p[i];
    p.resize(sz - rhs);
    return *this;
  }

  type &operator%=(const int rhs) {
    if (rhs < size())
      p.resize(rhs);
    normalize();
    return *this;
  }

  type &operator/=(const type &rhs) { return *this = *this / rhs; }

  type operator%=(const type &rhs) { return *this = *this % rhs; }

  type operator+(const type &rhs) const {
    type res = *this;
    return res += rhs;
  }

  type operator-(const type &rhs) const {
    type res = *this;
    return res -= rhs;
  }

  type operator*(const type &rhs) const { return type(Mult()(p, rhs.p)); }

  type operator*(const Field &rhs) const {
    type res = *this;
    return res *= rhs;
  }

  type operator/(const Field &rhs) const {
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

  type operator/(const type &rhs) const {
    return type::divmod(*this, rhs).first;
  }

  type operator%(const type &rhs) const {
    return type::divmod(*this, rhs).second;
  }

  bool operator==(const type &rhs) const {
    normalize();
    rhs.normalize();
    return p == rhs.p;
  }

  type inverse() const {
    int sz = size();
    if (sz == 0)
      return type();
    if (sz == 1) {
      assert(!Epsilon<>().null(p[0]));
      return type(p[0].inverse());
    }
    type q = (*this % ((sz + 1) / 2)).inverse();
    q -= (*this * q % sz - type(1)) * q % sz;
    return q % sz;
  }

  type reciprocal() const {
    normalize();
    return type(p.rbegin(), p.rend());
  }

  type integral() const {
    int sz = size();
    if (sz == 0)
      return {};
    type res = *this;
    for (int i = sz; i; i--) {
      res[i] = res[i - 1] / i;
    }
    res[0] = 0;
    res.normalize();
    return res;
  }

  type derivative() const {
    int sz = size();
    if (sz == 0)
      return {};
    type res = *this;
    for (int i = 0; i + 1 < sz; i++) {
      res[i] = res[i + 1] * (i + 1);
    }
    res.p.back() = 0;
    res.normalize();
    return res;
  }

  type mulx(field x) const { // component-wise multiplication with x^k
    field cur = 1;
    type res(*this);
    for(auto& c : res.p)
      c *= cur, cur *= x;
    return res;
  }
  type mulx_sq(field x) const { // component-wise multiplication with x^{k^2}
    field cur = x;
    field total = 1;
    field xx = x * x;
    type res(*this);
    for(auto& c : res.p)
      c *= total, total *= cur, cur *= xx;
    return res;
  }
  static pair<type, type> divmod(const type &a, const type &b) {
    if (NaiveMod)
      return naive_divmod(a, b);
    a.normalize();
    b.normalize();
    int m = a.size();
    int n = b.size();
    if (m < n)
      return {Polynomial(), a};
    type ar = a.reciprocal();
    type bri = (b.reciprocal() % (m - n + 1)).inverse();
    type q = (ar * bri % (m - n + 1)).reciprocal();
    type r = a - b * q;

    if (r.degree() >= b.degree()) {
      q += divmod(r, b).first;
      r = a - b * q;
    }

    return {q, r};
  }

  static pair<type, type> naive_divmod(const type &a, const type &b) {
    type res = a;
    int a_deg = a.degree();
    int b_deg = b.degree();
    Field normalizer = Field(1) / b[b_deg];
    for (int i = 0; i < a_deg - b_deg + 1; i++) {
      Field coef = (res[a_deg - i] *= normalizer);
      if (coef != 0) {
        for (int j = 1; j <= b_deg; j++) {
          res[a_deg - i - j] += -b[b_deg - j] * coef;
        }
      }
    }
    return {res >> b_deg, res % b_deg};
  }
  vector<Field> czt_even(Field z, int n) const { // P(1), P(z^2), P(z^4), ..., P(z^2(n-1))
    int m = degree();
    if(null()) {
      return vector<Field>(n);
    }
    vector<Field> vv(m + n);
    Field zi = Field(1) / z;
    Field zz = zi * zi;
    Field cur = zi;
    Field total = 1;
    for(int i = 0; i <= max(n - 1, m); i++) {
      if(i <= m) {vv[m - i] = total;}
      if(i < n) {vv[m + i] = total;}
      total *= cur;
      cur *= zz;
    }
    type w = (mulx_sq(z) * vv).substr(m, n).mulx_sq(z);
    vector<Field> res(n);
    for(int i = 0; i < n; i++) {
      res[i] = w[i];
    }
    return res;
  }
  vector<Field> czt(Field z, int n) const {
    auto even = czt_even(z, (n+1)/2);
    auto odd = mulx(z).czt_even(z, n/2);
    vector<Field> ans(n);
    for(int i = 0; i < n/2; i++) {
      ans[2*i] = even[i];
      ans[2*i+1] = odd[i];
    }
    if(n&1) {
      ans.back() = even.back();
    }
    return ans;
  }
  static type power(const type &a, long long n, const int mod) {
    return math::generic_power<type>(a, n, DefaultPowerOp<type>(mod));
  }

  static type power(const type &a, long long n, const type &mod) {
    return math::generic_power<type>(a, n, ModPowerOp<type>(mod));
  }

  static type kth(int K) { return type(1) << K; }

  static type kth(long long K, const type &mod) {
    return math::generic_power<type>(type(1) << 1, K,
                                     ModShiftPowerOp<type>(mod));
  }

  friend ostream &operator<<(ostream &output, const type &var) {
    output << "[";
    int sz = var.size();
    for (int i = sz - 1; i >= 0; i--) {
      output << var[i];
      if (i)
        output << " ";
    }
    return output << "]";
  }
};
} // namespace poly
/// keep caide
using poly::Polynomial;
} // namespace math
} // namespace lib

#endif
