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
  bundledCode: "#line 1 \"MontgomeryInteger.cpp\"\n\n\n#include <bits/stdc++.h>\n\n\
    #if __cplusplus < 201300\n#error required(c++14)\n#endif\n\nnamespace lib {\n\
    using namespace std;\nnamespace {\ntemplate <typename U, U Mod>\nstruct MontgomeryIntegerImpl\
    \ {\n  using S = make_signed_t<U>;\n  using T = make_unsigned_t<U>;\n  typedef\
    \ MontgomeryIntegerImpl<U, Mod> type;\n  constexpr static T mod = (T)Mod;\n\n\
    \  T x;\n  typedef U type_int;\n  typedef uint64_t large_int;\n\n  constexpr static\
    \ T get_r() {\n    T ret = Mod;\n    for(int i = 0; i < 4; i++)\n      ret *=\
    \ 2 - mod * ret;\n    return ret;\n  }\n\n  constexpr static T r = get_r();\n\
    \  constexpr static T n2 = -large_int(mod) % mod;\n  static_assert(r * mod ==\
    \ 1, \"assert(r * mod == 1)\");\n  static_assert(mod < (1 << 30), \"assert(mod\
    \ < 2^30)\");\n  static_assert(mod % 2 == 1, \"assert(mod % 2 == 1)\");\n\n  constexpr\
    \ MontgomeryIntegerImpl() : x(0) {}\n  constexpr MontgomeryIntegerImpl(large_int\
    \ y)\n    : x(reduce(large_int(y % mod + mod) * n2)) {}\n  \n  constexpr inline\
    \ static T reduce(large_int y) {\n    return (y + large_int(T(y) * T(-r)) * mod)\
    \ >> 32;\n  }\n\n  constexpr inline type &operator+=(const type &rhs) {\n    if(S(x\
    \ += rhs.x - 2 * mod) < 0) x += 2 * mod;\n    return *this;\n  }\n  constexpr\
    \ inline type &operator-=(const type &rhs) {\n    if(S(x -= rhs.x) < 0) x += 2\
    \ * mod;\n    return *this;\n  }\n  constexpr inline type &operator*=(const type\
    \ &rhs) {\n    x = reduce(large_int(x) * rhs.x);\n    return *this;\n  }\n  constexpr\
    \ inline type &operator/=(const type &rhs) {\n    return *this *= rhs.inverse();\n\
    \  }\n\n  constexpr inline type inverse() const {\n    return (*this).power(large_int(mod\
    \ - 2));\n  }\n\n  constexpr type &operator^=(large_int p) {\n    return *this\
    \ = power(p);\n  }\n\n  constexpr type &operator++() {\n    return *this += type(1);\n\
    \  }\n  constexpr type &operator--() {\n    return *this -= type(1);\n  }\n  constexpr\
    \ type operator++(int unused) {\n    type res = *this;\n    ++(*this);\n    return\
    \ res;\n  }\n  constexpr type operator--(int unused) {\n    type res = *this;\n\
    \    --(*this);\n    return res;\n  }\n\n  friend constexpr type operator+(const\
    \ type &lhs, const type &rhs) {\n    type res = lhs;\n    return res += rhs;\n\
    \  }\n  friend constexpr type operator-(const type &lhs, const type &rhs) {\n\
    \    type res = lhs;\n    return res -= rhs;\n  }\n  friend constexpr type operator*(const\
    \ type &lhs, const type &rhs) {\n    type res = lhs;\n    return res *= rhs;\n\
    \  }\n  friend constexpr type operator/(const type &lhs, const type &rhs) {\n\
    \    type res = lhs;\n    return res /= rhs;\n  }\n\n  friend constexpr type operator^(const\
    \ type &lhs, large_int rhs) {\n    type res = lhs;\n    return res ^= rhs;\n \
    \ }\n\n  friend constexpr type power(const type &lhs, large_int rhs) {\n    return\
    \ lhs.power(rhs);\n  }\n\n  constexpr type operator-() const {\n    return type()\
    \ - *this;\n  }\n\n  constexpr type power(large_int rhs) const {\n    type ret(1),\
    \ mul(*this);\n    while(rhs > 0) {\n      if(rhs&1) ret *= mul;\n      mul *=\
    \ mul;\n      rhs /= 2;\n    }\n    return ret;\n  }\n\n  constexpr T get() const\
    \ {\n    T ret = reduce(x);\n    return ret >= mod ? ret - mod : ret;\n  }\n\n\
    \  friend bool operator==(const type &lhs, const type &rhs) {\n    return lhs.get()\
    \ == rhs.get();\n  }\n  friend bool operator!=(const type &lhs, const type &rhs)\
    \ {\n    return !(lhs == rhs);\n  }\n\n  explicit operator int() const { return\
    \ get();; }\n  explicit operator int64_t() const { return get(); }\n  explicit\
    \ operator long long() const { return get(); }\n  explicit operator double() const\
    \ { return get(); }\n  explicit operator long double() const { return get(); }\n\
    \  friend ostream &operator<<(ostream &output, const type &var) {\n    return\
    \ output << var.get();\n  }\n\n  friend istream &operator>>(istream &input, type\
    \ &var) {\n    T y;\n    cin >> y;\n    var = type(y);\n    return input;\n  }\n\
    };\n} // namespace\n\n\ntemplate <typename T, T... Mods>\nusing MontgomeryInteger\
    \ = MontgomeryIntegerImpl<T, Mods...>;\n\ntemplate <int32_t... Mods> using Mont32\
    \ = MontgomeryInteger<int32_t, Mods...>;\n\nusing MontP = Mont32<(int32_t)1e9+7>;\n\
    using MontNTT = Mont32<998244353>;\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_MONTGOMERY_INTEGER\n#define _LIB_MONTGOMERY_INTEGER\n#include\
    \ <bits/stdc++.h>\n\n#if __cplusplus < 201300\n#error required(c++14)\n#endif\n\
    \nnamespace lib {\nusing namespace std;\nnamespace {\ntemplate <typename U, U\
    \ Mod>\nstruct MontgomeryIntegerImpl {\n  using S = make_signed_t<U>;\n  using\
    \ T = make_unsigned_t<U>;\n  typedef MontgomeryIntegerImpl<U, Mod> type;\n  constexpr\
    \ static T mod = (T)Mod;\n\n  T x;\n  typedef U type_int;\n  typedef uint64_t\
    \ large_int;\n\n  constexpr static T get_r() {\n    T ret = Mod;\n    for(int\
    \ i = 0; i < 4; i++)\n      ret *= 2 - mod * ret;\n    return ret;\n  }\n\n  constexpr\
    \ static T r = get_r();\n  constexpr static T n2 = -large_int(mod) % mod;\n  static_assert(r\
    \ * mod == 1, \"assert(r * mod == 1)\");\n  static_assert(mod < (1 << 30), \"\
    assert(mod < 2^30)\");\n  static_assert(mod % 2 == 1, \"assert(mod % 2 == 1)\"\
    );\n\n  constexpr MontgomeryIntegerImpl() : x(0) {}\n  constexpr MontgomeryIntegerImpl(large_int\
    \ y)\n    : x(reduce(large_int(y % mod + mod) * n2)) {}\n  \n  constexpr inline\
    \ static T reduce(large_int y) {\n    return (y + large_int(T(y) * T(-r)) * mod)\
    \ >> 32;\n  }\n\n  constexpr inline type &operator+=(const type &rhs) {\n    if(S(x\
    \ += rhs.x - 2 * mod) < 0) x += 2 * mod;\n    return *this;\n  }\n  constexpr\
    \ inline type &operator-=(const type &rhs) {\n    if(S(x -= rhs.x) < 0) x += 2\
    \ * mod;\n    return *this;\n  }\n  constexpr inline type &operator*=(const type\
    \ &rhs) {\n    x = reduce(large_int(x) * rhs.x);\n    return *this;\n  }\n  constexpr\
    \ inline type &operator/=(const type &rhs) {\n    return *this *= rhs.inverse();\n\
    \  }\n\n  constexpr inline type inverse() const {\n    return (*this).power(large_int(mod\
    \ - 2));\n  }\n\n  constexpr type &operator^=(large_int p) {\n    return *this\
    \ = power(p);\n  }\n\n  constexpr type &operator++() {\n    return *this += type(1);\n\
    \  }\n  constexpr type &operator--() {\n    return *this -= type(1);\n  }\n  constexpr\
    \ type operator++(int unused) {\n    type res = *this;\n    ++(*this);\n    return\
    \ res;\n  }\n  constexpr type operator--(int unused) {\n    type res = *this;\n\
    \    --(*this);\n    return res;\n  }\n\n  friend constexpr type operator+(const\
    \ type &lhs, const type &rhs) {\n    type res = lhs;\n    return res += rhs;\n\
    \  }\n  friend constexpr type operator-(const type &lhs, const type &rhs) {\n\
    \    type res = lhs;\n    return res -= rhs;\n  }\n  friend constexpr type operator*(const\
    \ type &lhs, const type &rhs) {\n    type res = lhs;\n    return res *= rhs;\n\
    \  }\n  friend constexpr type operator/(const type &lhs, const type &rhs) {\n\
    \    type res = lhs;\n    return res /= rhs;\n  }\n\n  friend constexpr type operator^(const\
    \ type &lhs, large_int rhs) {\n    type res = lhs;\n    return res ^= rhs;\n \
    \ }\n\n  friend constexpr type power(const type &lhs, large_int rhs) {\n    return\
    \ lhs.power(rhs);\n  }\n\n  constexpr type operator-() const {\n    return type()\
    \ - *this;\n  }\n\n  constexpr type power(large_int rhs) const {\n    type ret(1),\
    \ mul(*this);\n    while(rhs > 0) {\n      if(rhs&1) ret *= mul;\n      mul *=\
    \ mul;\n      rhs /= 2;\n    }\n    return ret;\n  }\n\n  constexpr T get() const\
    \ {\n    T ret = reduce(x);\n    return ret >= mod ? ret - mod : ret;\n  }\n\n\
    \  friend bool operator==(const type &lhs, const type &rhs) {\n    return lhs.get()\
    \ == rhs.get();\n  }\n  friend bool operator!=(const type &lhs, const type &rhs)\
    \ {\n    return !(lhs == rhs);\n  }\n\n  explicit operator int() const { return\
    \ get();; }\n  explicit operator int64_t() const { return get(); }\n  explicit\
    \ operator long long() const { return get(); }\n  explicit operator double() const\
    \ { return get(); }\n  explicit operator long double() const { return get(); }\n\
    \  friend ostream &operator<<(ostream &output, const type &var) {\n    return\
    \ output << var.get();\n  }\n\n  friend istream &operator>>(istream &input, type\
    \ &var) {\n    T y;\n    cin >> y;\n    var = type(y);\n    return input;\n  }\n\
    };\n} // namespace\n\n\ntemplate <typename T, T... Mods>\nusing MontgomeryInteger\
    \ = MontgomeryIntegerImpl<T, Mods...>;\n\ntemplate <int32_t... Mods> using Mont32\
    \ = MontgomeryInteger<int32_t, Mods...>;\n\nusing MontP = Mont32<(int32_t)1e9+7>;\n\
    using MontNTT = Mont32<998244353>;\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: MontgomeryInteger.cpp
  requiredBy: []
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: MontgomeryInteger.cpp
layout: document
redirect_from:
- /library/MontgomeryInteger.cpp
- /library/MontgomeryInteger.cpp.html
title: MontgomeryInteger.cpp
---
