#ifndef _LIB_MODULAR_INTEGER
#define _LIB_MODULAR_INTEGER
#include "NumberTheory.cpp"
#include <bits/stdc++.h>

#if __cplusplus < 201300
#error required(c++14)
#endif

namespace lib {
using namespace std;
namespace {
template <typename T, T... Mods> struct ModularIntegerBase {
  typedef ModularIntegerBase<T, Mods...> type;

  T x[sizeof...(Mods)];
  friend ostream &operator<<(ostream &output, const type &var) {
    output << "(";
    for (int i = 0; i < sizeof...(Mods); i++) {
      if (i)
        output << ", ";
      output << var.x[i];
    }
    return output << ")";
  }
};

template <typename T, T Mod> struct ModularIntegerBase<T, Mod> {
  typedef ModularIntegerBase<T, Mod> type;
  constexpr static T mod = Mod;

  T x[1];

  T& data() { return this->x[0]; }
  T data() const { return this->x[0]; }
  explicit operator int() const { return this->x[0]; }
  explicit operator int64_t() const { return this->x[0]; }
  explicit operator long long() const { return this->x[0]; }
  explicit operator double() const { return this->x[0]; }
  explicit operator long double() const { return this->x[0]; }
  friend ostream &operator<<(ostream &output, const type &var) {
    return output << var.x[0];
  }
};

template<typename T, typename U, T... Mods>
struct InversesTable {
  constexpr static size_t n_mods = sizeof...(Mods);
  constexpr static T mods[sizeof...(Mods)] = {Mods...};
  constexpr static int n_inverses = 1e6 + 10;

  T v[n_inverses][n_mods];
  T max_x;

  constexpr InversesTable() : v(), max_x(n_inverses) {
    for(int j = 0; j < sizeof...(Mods); j++)
      v[1][j] = 1, max_x = min(max_x, mods[j]);
    for(int i = 2; i < max_x; i++) {
      for(int j = 0; j < sizeof...(Mods); j++) {
        v[i][j] = mods[j] - (T)((U)(mods[j] / i) * v[mods[j] % i][j] % mods[j]);
      }
    }
  }
};

// Make available for linkage.
template <typename T, class U, T... Mods>
constexpr T InversesTable<T, U, Mods...>::mods[];

template <typename T, class Enable, T... Mods>
struct ModularIntegerImpl : ModularIntegerBase<T, Mods...> {
  typedef ModularIntegerImpl<T, Enable, Mods...> type;
  typedef T type_int;
  typedef uint64_t large_int;
  constexpr static size_t n_mods = sizeof...(Mods);
  constexpr static T mods[sizeof...(Mods)] = {Mods...};
  using ModularIntegerBase<T, Mods...>::x;
  using Inverses = InversesTable<T, large_int, Mods...>;

  struct Less {
    bool operator()(const type &lhs, const type &rhs) const {
      for (size_t i = 0; i < sizeof...(Mods); i++)
        if (lhs.x[i] != rhs.x[i])
          return lhs.x[i] < rhs.x[i];
      return false;
    };
  };
  typedef Less less;


  ModularIntegerImpl() {
    for (size_t i = 0; i < sizeof...(Mods); i++)
      x[i] = T();
  }
  ModularIntegerImpl(large_int y) {
    for (size_t i = 0; i < sizeof...(Mods); i++) {
      x[i] = y % mods[i];
      if (x[i] < 0)
        x[i] += mods[i];
    }
  }
  static type with_remainders(T y[sizeof...(Mods)]) {
    type res;
    for (size_t i = 0; i < sizeof...(Mods); i++)
      res.x[i] = y[i];
    res.normalize();
    return res;
  }

  inline void normalize() {
    for (size_t i = 0; i < sizeof...(Mods); i++)
      if ((x[i] %= mods[i]) < 0)
        x[i] += mods[i];
  }

  inline T operator[](int i) const { return x[i]; }

  inline T multiply(T a, T b, T mod) const { return (large_int)a * b % mod; }

  inline T inv(T a, T mod) const { return static_cast<T>(nt::inverse(a, mod)); }

  inline T invi(T a, int i) const {
    const static Inverses inverses = Inverses();
    if(a < inverses.max_x)
      return inverses.v[a][i];
    return inv(a, mods[i]);
  }

  type inverse() const {
    T res[sizeof...(Mods)];
    for (size_t i = 0; i < sizeof...(Mods); i++)
      res[i] = invi(x[i], i);
    return type::with_remainders(res);
  }

  template <typename U> T power_(T a, U p, T mod) {
    if (mod == 1)
      return T();
    if (p < 0) {
      if (a == 0)
        throw domain_error("0^p with negative p is invalid");
      p = -p;
      a = inv(a, mod);
    }
    if (p == 0)
      return T(1);
    if (p == 1)
      return a;
    T res = 1;
    while (p > 0) {
      if (p & 1)
        res = multiply(res, a, mod);
      p >>= 1;
      a = multiply(a, a, mod);
    }
    return res;
  }

  inline type &operator+=(const type &rhs) {
    for (size_t i = 0; i < sizeof...(Mods); i++)
      if ((x[i] += rhs.x[i]) >= mods[i])
        x[i] -= mods[i];
    return *this;
  }
  inline type &operator-=(const type &rhs) {
    for (size_t i = 0; i < sizeof...(Mods); i++)
      if ((x[i] -= rhs.x[i]) < 0)
        x[i] += mods[i];
    return *this;
  }
  inline type &operator*=(const type &rhs) {
    for (size_t i = 0; i < sizeof...(Mods); i++)
      x[i] = multiply(x[i], rhs.x[i], mods[i]);
    return *this;
  }
  inline type &operator/=(const type &rhs) {
    for (size_t i = 0; i < sizeof...(Mods); i++)
      x[i] = multiply(x[i], invi(rhs.x[i], i), mods[i]);
    return *this;
  }

  inline type &operator+=(T rhs) {
    for (size_t i = 0; i < sizeof...(Mods); i++)
      if ((x[i] += rhs) >= mods[i])
        x[i] -= mods[i];
    return *this;
  }

  type &operator-=(T rhs) {
    for (size_t i = 0; i < sizeof...(Mods); i++)
      if ((x[i] -= rhs) < 0)
        x[i] += mods[i];
    return *this;
  }

  type &operator*=(T rhs) {
    for (size_t i = 0; i < sizeof...(Mods); i++)
      x[i] = multiply(x[i], rhs, mods[i]);
    return *this;
  }

  type &operator/=(T rhs) {
    for (size_t i = 0; i < sizeof...(Mods); i++)
      x[i] = multiply(invi(rhs, i), x[i], mods[i]);
    return *this;
  }

  type &operator^=(large_int p) {
    for (size_t i = 0; i < sizeof...(Mods); i++)
      x[i] = power_(x[i], p, mods[i]);
    return *this;
  }

  type &operator++() {
    for (size_t i = 0; i < sizeof...(Mods); i++)
      if ((++x[i]) >= mods[i])
        x[i] -= mods[i];
    return *this;
  }
  type &operator--() {
    for (size_t i = 0; i < sizeof...(Mods); i++)
      if ((--x[i]) < 0)
        x[i] += mods[i];
    return *this;
  }
  type operator++(int unused) {
    type res = *this;
    ++(*this);
    return res;
  }
  type operator--(int unused) {
    type res = *this;
    --(*this);
    return res;
  }

  friend type operator+(const type &lhs, const type &rhs) {
    type res = lhs;
    return res += rhs;
  }
  friend type operator-(const type &lhs, const type &rhs) {
    type res = lhs;
    return res -= rhs;
  }
  friend type operator*(const type &lhs, const type &rhs) {
    type res = lhs;
    return res *= rhs;
  }
  friend type operator/(const type &lhs, const type &rhs) {
    type res = lhs;
    return res /= rhs;
  }

  friend type operator+(const type &lhs, T rhs) {
    type res = lhs;
    return res += rhs;
  }

  friend type operator-(const type &lhs, T rhs) {
    type res = lhs;
    return res -= rhs;
  }

  friend type operator*(const type &lhs, T rhs) {
    type res = lhs;
    return res *= rhs;
  }

  friend type operator/(const type &lhs, T rhs) {
    type res = lhs;
    return res /= rhs;
  }

  friend type operator^(const type &lhs, large_int rhs) {
    type res = lhs;
    return res ^= rhs;
  }

  friend type power(const type &lhs, large_int rhs) { return lhs ^ rhs; }

  type operator-() const {
    type res = *this;
    for (size_t i = 0; i < sizeof...(Mods); i++)
      if (res.x[i])
        res.x[i] = mods[i] - res.x[i];
    return res;
  }

  friend bool operator==(const type &lhs, const type &rhs) {
    for (size_t i = 0; i < sizeof...(Mods); i++)
      if (lhs.x[i] != rhs.x[i])
        return false;
    return true;
  }
  friend bool operator!=(const type &lhs, const type &rhs) {
    return !(lhs == rhs);
  }

  friend istream &operator>>(istream &input, type &var) {
    T y;
    cin >> y;
    var = y;
    return input;
  }
};
} // namespace

// Explicitly make constexpr available for linkage.
template <typename T, class Enable, T... Mods>
constexpr T ModularIntegerImpl<T, Enable, Mods...>::mods[];

template <typename T, T... Mods>
using ModularInteger =
    ModularIntegerImpl<T, typename enable_if<is_integral<T>::value>::type,
                       Mods...>;

template <int32_t... Mods> using Mint32 = ModularInteger<int32_t, Mods...>;

template <int64_t... Mods> using Mint64 = ModularInteger<int64_t, Mods...>;

using MintP = Mint32<(int32_t)1e9+7>;
using MintNTT = Mint32<998244353>;
} // namespace lib

#endif
