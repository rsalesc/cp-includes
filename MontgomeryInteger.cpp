#ifndef _LIB_MONTGOMERY_INTEGER
#define _LIB_MONTGOMERY_INTEGER
#include <bits/stdc++.h>

#if __cplusplus < 201300
#error required(c++14)
#endif

namespace lib {
using namespace std;
namespace {
template <typename U, U Mod>
struct MontgomeryIntegerImpl {
  using S = make_signed_t<U>;
  using T = make_unsigned_t<U>;
  typedef MontgomeryIntegerImpl<U, Mod> type;
  constexpr static T mod = (T)Mod;

  T x;
  typedef U type_int;
  typedef uint64_t large_int;

  constexpr static T get_r() {
    T ret = Mod;
    for(int i = 0; i < 4; i++)
      ret *= 2 - mod * ret;
    return ret;
  }

  constexpr static T r = get_r();
  constexpr static T n2 = -large_int(mod) % mod;
  static_assert(r * mod == 1, "assert(r * mod == 1)");
  static_assert(mod < (1 << 30), "assert(mod < 2^30)");
  static_assert(mod % 2 == 1, "assert(mod % 2 == 1)");

  constexpr MontgomeryIntegerImpl() : x(0) {}
  constexpr MontgomeryIntegerImpl(large_int y)
    : x(reduce(large_int(y % mod + mod) * n2)) {}
  
  constexpr inline static T reduce(large_int y) {
    return (y + large_int(T(y) * T(-r)) * mod) >> 32;
  }

  constexpr inline type &operator+=(const type &rhs) {
    if(S(x += rhs.x - 2 * mod) < 0) x += 2 * mod;
    return *this;
  }
  constexpr inline type &operator-=(const type &rhs) {
    if(S(x -= rhs.x) < 0) x += 2 * mod;
    return *this;
  }
  constexpr inline type &operator*=(const type &rhs) {
    x = reduce(large_int(x) * rhs.x);
    return *this;
  }
  constexpr inline type &operator/=(const type &rhs) {
    return *this *= rhs.inverse();
  }

  constexpr inline type inverse() const {
    return (*this).power(large_int(mod - 2));
  }

  constexpr type &operator^=(large_int p) {
    return *this = power(p);
  }

  constexpr type &operator++() {
    return *this += type(1);
  }
  constexpr type &operator--() {
    return *this -= type(1);
  }
  constexpr type operator++(int unused) {
    type res = *this;
    ++(*this);
    return res;
  }
  constexpr type operator--(int unused) {
    type res = *this;
    --(*this);
    return res;
  }

  friend constexpr type operator+(const type &lhs, const type &rhs) {
    type res = lhs;
    return res += rhs;
  }
  friend constexpr type operator-(const type &lhs, const type &rhs) {
    type res = lhs;
    return res -= rhs;
  }
  friend constexpr type operator*(const type &lhs, const type &rhs) {
    type res = lhs;
    return res *= rhs;
  }
  friend constexpr type operator/(const type &lhs, const type &rhs) {
    type res = lhs;
    return res /= rhs;
  }

  friend constexpr type operator^(const type &lhs, large_int rhs) {
    type res = lhs;
    return res ^= rhs;
  }

  friend constexpr type power(const type &lhs, large_int rhs) {
    return lhs.power(rhs);
  }

  constexpr type operator-() const {
    return type() - *this;
  }

  constexpr type power(large_int rhs) const {
    type ret(1), mul(*this);
    while(rhs > 0) {
      if(rhs&1) ret *= mul;
      mul *= mul;
      rhs /= 2;
    }
    return ret;
  }

  constexpr T get() const {
    T ret = reduce(x);
    return ret >= mod ? ret - mod : ret;
  }

  friend bool operator==(const type &lhs, const type &rhs) {
    return lhs.get() == rhs.get();
  }
  friend bool operator!=(const type &lhs, const type &rhs) {
    return !(lhs == rhs);
  }

  explicit operator int() const { return get();; }
  explicit operator int64_t() const { return get(); }
  explicit operator long long() const { return get(); }
  explicit operator double() const { return get(); }
  explicit operator long double() const { return get(); }
  friend ostream &operator<<(ostream &output, const type &var) {
    return output << var.get();
  }

  friend istream &operator>>(istream &input, type &var) {
    T y;
    cin >> y;
    var = type(y);
    return input;
  }
};
} // namespace


template <typename T, T... Mods>
using MontgomeryInteger = MontgomeryIntegerImpl<T, Mods...>;

template <int32_t... Mods> using Mont32 = MontgomeryInteger<int32_t, Mods...>;

using MontP = Mont32<(int32_t)1e9+7>;
using MontNTT = Mont32<998244353>;
} // namespace lib

#endif
