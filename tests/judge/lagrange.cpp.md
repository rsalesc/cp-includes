---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Lagrange.cpp
    title: Lagrange.cpp
  - icon: ':warning:'
    path: ModularInteger.cpp
    title: ModularInteger.cpp
  - icon: ':warning:'
    path: NumberTheory.cpp
    title: NumberTheory.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tests/judge/lagrange.cpp\"\n#include <bits/stdc++.h>\n#line\
    \ 1 \"Lagrange.cpp\"\n\n\n#line 4 \"Lagrange.cpp\"\n\nnamespace lib {\nusing namespace\
    \ std;\nnamespace linalg {\ntemplate <typename Field> struct PrefixLagrange {\n\
    \  vector<Field> fat, ifat, pref, suf;\n  PrefixLagrange() {\n    fat = {1};\n\
    \    ifat = {1};\n  }\n\n  void ensure(int n) {\n    int o = fat.size();\n   \
    \ if (n + 1 <= o)\n      return;\n    fat.resize(n + 1), ifat.resize(n + 1);\n\
    \    pref.resize(n + 5), suf.resize(n + 5);\n\n    for (int i = o; i <= n; i++)\n\
    \      fat[i] = fat[i - 1] * i;\n\n    ifat.back() = Field(1) / fat.back();\n\
    \    for (int i = n - 1; i >= o; i--)\n      ifat[i] = ifat[i + 1] * (i + 1);\n\
    \  }\n\n  template <typename T> Field eval(const vector<Field> &v, T x) {\n  \
    \  assert(!v.empty());\n    int d = (int)v.size() - 1;\n    if (x <= d)\n    \
    \  return v[x];\n\n    ensure(d + 1);\n\n    pref[0] = suf[d] = 1;\n    for (int\
    \ i = 0; i < d; i++)\n      pref[i + 1] = pref[i] * (x - i);\n    for (int i =\
    \ d; i; i--)\n      suf[i - 1] = suf[i] * (x - i);\n\n    Field ans = 0;\n   \
    \ for (int i = 0; i <= d; i++) {\n      Field l = pref[i] * suf[i] * ifat[i] *\
    \ ifat[d - i];\n      if ((d + i) & 1)\n        l = -l;\n      ans += l * v[i];\n\
    \    }\n    return ans;\n  }\n};\n} // namespace linalg\n} // namespace lib\n\n\
    \n#line 1 \"ModularInteger.cpp\"\n\n\n#line 1 \"NumberTheory.cpp\"\n\n\n#line\
    \ 4 \"NumberTheory.cpp\"\n\nnamespace lib {\nusing namespace std;\nnamespace nt\
    \ {\nint64_t inverse(int64_t a, int64_t b) {\n  long long b0 = b, t, q;\n  long\
    \ long x0 = 0, x1 = 1;\n  if (b == 1)\n    return 1;\n  while (a > 1) {\n    q\
    \ = a / b;\n    t = b, b = a % b, a = t;\n    t = x0, x0 = x1 - q * x0, x1 = t;\n\
    \  }\n  if (x1 < 0)\n    x1 += b0;\n  return x1;\n}\ntemplate<typename T, typename\
    \ U>\nT powmod (T a, U b, U p) {\n    int res = 1;\n    while (b)\n        if\
    \ (b & 1)\n            res = int (res * 1ll * a % p),  --b;\n        else\n  \
    \          a = int (a * 1ll * a % p),  b >>= 1;\n    return res;\n}\ntemplate<typename\
    \ T>\nvector<T> factors(T n) {\n  vector<T> f;\n  for(T i = 2; i*i <= n; i++)\
    \ {\n    if(n % i == 0) f.push_back(i);\n    while(n % i == 0) n /= i;\n  }\n\
    \  if(n > 1) f.push_back(n);\n  return f;\n}\n} // namespace nt\n} // namespace\
    \ lib\n\n\n#line 5 \"ModularInteger.cpp\"\n\n#if __cplusplus < 201300\n#error\
    \ required(c++14)\n#endif\n\nnamespace lib {\nusing namespace std;\nnamespace\
    \ {\ntemplate <typename T, T... Mods> struct ModularIntegerBase {\n  typedef ModularIntegerBase<T,\
    \ Mods...> type;\n\n  T x[sizeof...(Mods)];\n  friend ostream &operator<<(ostream\
    \ &output, const type &var) {\n    output << \"(\";\n    for (int i = 0; i < sizeof...(Mods);\
    \ i++) {\n      if (i)\n        output << \", \";\n      output << var.x[i];\n\
    \    }\n    return output << \")\";\n  }\n};\n\ntemplate <typename T, T Mod> struct\
    \ ModularIntegerBase<T, Mod> {\n  typedef ModularIntegerBase<T, Mod> type;\n \
    \ constexpr static T mod = Mod;\n\n  T x[1];\n\n  T& data() { return this->x[0];\
    \ }\n  T data() const { return this->x[0]; }\n  explicit operator int() const\
    \ { return this->x[0]; }\n  explicit operator int64_t() const { return this->x[0];\
    \ }\n  explicit operator long long() const { return this->x[0]; }\n  explicit\
    \ operator double() const { return this->x[0]; }\n  explicit operator long double()\
    \ const { return this->x[0]; }\n  friend ostream &operator<<(ostream &output,\
    \ const type &var) {\n    return output << var.x[0];\n  }\n};\n\ntemplate<typename\
    \ T, typename U, T... Mods>\nstruct InversesTable {\n  constexpr static size_t\
    \ n_mods = sizeof...(Mods);\n  constexpr static T mods[sizeof...(Mods)] = {Mods...};\n\
    \  constexpr static int n_inverses = 1e6 + 10;\n\n  T v[n_inverses][n_mods];\n\
    \  T max_x;\n\n  InversesTable() : v(), max_x(n_inverses) {\n    for(int j = 0;\
    \ j < sizeof...(Mods); j++)\n      v[1][j] = 1, max_x = min(max_x, mods[j]);\n\
    \    for(int i = 2; i < max_x; i++) {\n      for(int j = 0; j < sizeof...(Mods);\
    \ j++) {\n        v[i][j] = mods[j] - (T)((U)(mods[j] / i) * v[mods[j] % i][j]\
    \ % mods[j]);\n      }\n    }\n  }\n};\n\n// Make available for linkage.\ntemplate\
    \ <typename T, class U, T... Mods>\nconstexpr T InversesTable<T, U, Mods...>::mods[];\n\
    \ntemplate <typename T, class Enable, T... Mods>\nstruct ModularIntegerImpl :\
    \ ModularIntegerBase<T, Mods...> {\n  typedef ModularIntegerImpl<T, Enable, Mods...>\
    \ type;\n  typedef T type_int;\n  typedef uint64_t large_int;\n  constexpr static\
    \ size_t n_mods = sizeof...(Mods);\n  constexpr static T mods[sizeof...(Mods)]\
    \ = {Mods...};\n  using ModularIntegerBase<T, Mods...>::x;\n  using Inverses =\
    \ InversesTable<T, large_int, Mods...>;\n\n  struct Less {\n    bool operator()(const\
    \ type &lhs, const type &rhs) const {\n      for (size_t i = 0; i < sizeof...(Mods);\
    \ i++)\n        if (lhs.x[i] != rhs.x[i])\n          return lhs.x[i] < rhs.x[i];\n\
    \      return false;\n    };\n  };\n  typedef Less less;\n\n\n  ModularIntegerImpl()\
    \ {\n    for (size_t i = 0; i < sizeof...(Mods); i++)\n      x[i] = T();\n  }\n\
    \  ModularIntegerImpl(large_int y) {\n    for (size_t i = 0; i < sizeof...(Mods);\
    \ i++) {\n      x[i] = y % mods[i];\n      if (x[i] < 0)\n        x[i] += mods[i];\n\
    \    }\n  }\n  static type with_remainders(T y[sizeof...(Mods)]) {\n    type res;\n\
    \    for (size_t i = 0; i < sizeof...(Mods); i++)\n      res.x[i] = y[i];\n  \
    \  res.normalize();\n    return res;\n  }\n\n  inline void normalize() {\n   \
    \ for (size_t i = 0; i < sizeof...(Mods); i++)\n      if ((x[i] %= mods[i]) <\
    \ 0)\n        x[i] += mods[i];\n  }\n\n  inline T operator[](int i) const { return\
    \ x[i]; }\n\n  inline T multiply(T a, T b, T mod) const { return (large_int)a\
    \ * b % mod; }\n\n  inline T inv(T a, T mod) const { return static_cast<T>(nt::inverse(a,\
    \ mod)); }\n\n  inline T invi(T a, int i) const {\n    const static Inverses inverses\
    \ = Inverses();\n    if(a < inverses.max_x)\n      return inverses.v[a][i];\n\
    \    return inv(a, mods[i]);\n  }\n\n  type inverse() const {\n    T res[sizeof...(Mods)];\n\
    \    for (size_t i = 0; i < sizeof...(Mods); i++)\n      res[i] = invi(x[i], i);\n\
    \    return type::with_remainders(res);\n  }\n\n  template <typename U> T power_(T\
    \ a, U p, T mod) {\n    if (mod == 1)\n      return T();\n    if (p < 0) {\n \
    \     if (a == 0)\n        throw domain_error(\"0^p with negative p is invalid\"\
    );\n      p = -p;\n      a = inv(a, mod);\n    }\n    if (p == 0)\n      return\
    \ T(1);\n    if (p == 1)\n      return a;\n    T res = 1;\n    while (p > 0) {\n\
    \      if (p & 1)\n        res = multiply(res, a, mod);\n      p >>= 1;\n    \
    \  a = multiply(a, a, mod);\n    }\n    return res;\n  }\n\n  inline type &operator+=(const\
    \ type &rhs) {\n    for (size_t i = 0; i < sizeof...(Mods); i++)\n      if ((x[i]\
    \ += rhs.x[i]) >= mods[i])\n        x[i] -= mods[i];\n    return *this;\n  }\n\
    \  inline type &operator-=(const type &rhs) {\n    for (size_t i = 0; i < sizeof...(Mods);\
    \ i++)\n      if ((x[i] -= rhs.x[i]) < 0)\n        x[i] += mods[i];\n    return\
    \ *this;\n  }\n  inline type &operator*=(const type &rhs) {\n    for (size_t i\
    \ = 0; i < sizeof...(Mods); i++)\n      x[i] = multiply(x[i], rhs.x[i], mods[i]);\n\
    \    return *this;\n  }\n  inline type &operator/=(const type &rhs) {\n    for\
    \ (size_t i = 0; i < sizeof...(Mods); i++)\n      x[i] = multiply(x[i], invi(rhs.x[i],\
    \ i), mods[i]);\n    return *this;\n  }\n\n  inline type &operator+=(T rhs) {\n\
    \    for (size_t i = 0; i < sizeof...(Mods); i++)\n      if ((x[i] += rhs) >=\
    \ mods[i])\n        x[i] -= mods[i];\n    return *this;\n  }\n\n  type &operator-=(T\
    \ rhs) {\n    for (size_t i = 0; i < sizeof...(Mods); i++)\n      if ((x[i] -=\
    \ rhs) < 0)\n        x[i] += mods[i];\n    return *this;\n  }\n\n  type &operator*=(T\
    \ rhs) {\n    for (size_t i = 0; i < sizeof...(Mods); i++)\n      x[i] = multiply(x[i],\
    \ rhs, mods[i]);\n    return *this;\n  }\n\n  type &operator/=(T rhs) {\n    for\
    \ (size_t i = 0; i < sizeof...(Mods); i++)\n      x[i] = multiply(invi(rhs, i),\
    \ x[i], mods[i]);\n    return *this;\n  }\n\n  type &operator^=(large_int p) {\n\
    \    for (size_t i = 0; i < sizeof...(Mods); i++)\n      x[i] = power_(x[i], p,\
    \ mods[i]);\n    return *this;\n  }\n\n  type &operator++() {\n    for (size_t\
    \ i = 0; i < sizeof...(Mods); i++)\n      if ((++x[i]) >= mods[i])\n        x[i]\
    \ -= mods[i];\n    return *this;\n  }\n  type &operator--() {\n    for (size_t\
    \ i = 0; i < sizeof...(Mods); i++)\n      if ((--x[i]) < 0)\n        x[i] += mods[i];\n\
    \    return *this;\n  }\n  type operator++(int unused) {\n    type res = *this;\n\
    \    ++(*this);\n    return res;\n  }\n  type operator--(int unused) {\n    type\
    \ res = *this;\n    --(*this);\n    return res;\n  }\n\n  friend type operator+(const\
    \ type &lhs, const type &rhs) {\n    type res = lhs;\n    return res += rhs;\n\
    \  }\n  friend type operator-(const type &lhs, const type &rhs) {\n    type res\
    \ = lhs;\n    return res -= rhs;\n  }\n  friend type operator*(const type &lhs,\
    \ const type &rhs) {\n    type res = lhs;\n    return res *= rhs;\n  }\n  friend\
    \ type operator/(const type &lhs, const type &rhs) {\n    type res = lhs;\n  \
    \  return res /= rhs;\n  }\n\n  friend type operator+(const type &lhs, T rhs)\
    \ {\n    type res = lhs;\n    return res += rhs;\n  }\n\n  friend type operator-(const\
    \ type &lhs, T rhs) {\n    type res = lhs;\n    return res -= rhs;\n  }\n\n  friend\
    \ type operator*(const type &lhs, T rhs) {\n    type res = lhs;\n    return res\
    \ *= rhs;\n  }\n\n  friend type operator/(const type &lhs, T rhs) {\n    type\
    \ res = lhs;\n    return res /= rhs;\n  }\n\n  friend type operator^(const type\
    \ &lhs, large_int rhs) {\n    type res = lhs;\n    return res ^= rhs;\n  }\n\n\
    \  friend type power(const type &lhs, large_int rhs) { return lhs ^ rhs; }\n\n\
    \  type operator-() const {\n    type res = *this;\n    for (size_t i = 0; i <\
    \ sizeof...(Mods); i++)\n      if (res.x[i])\n        res.x[i] = mods[i] - res.x[i];\n\
    \    return res;\n  }\n\n  friend bool operator==(const type &lhs, const type\
    \ &rhs) {\n    for (size_t i = 0; i < sizeof...(Mods); i++)\n      if (lhs.x[i]\
    \ != rhs.x[i])\n        return false;\n    return true;\n  }\n  friend bool operator!=(const\
    \ type &lhs, const type &rhs) {\n    return !(lhs == rhs);\n  }\n\n  friend istream\
    \ &operator>>(istream &input, type &var) {\n    T y;\n    cin >> y;\n    var =\
    \ y;\n    return input;\n  }\n};\n} // namespace\n\n// Explicitly make constexpr\
    \ available for linkage.\ntemplate <typename T, class Enable, T... Mods>\nconstexpr\
    \ T ModularIntegerImpl<T, Enable, Mods...>::mods[];\n\ntemplate <typename T, T...\
    \ Mods>\nusing ModularInteger =\n    ModularIntegerImpl<T, typename enable_if<is_integral<T>::value>::type,\n\
    \                       Mods...>;\n\ntemplate <int32_t... Mods> using Mint32 =\
    \ ModularInteger<int32_t, Mods...>;\n\ntemplate <int64_t... Mods> using Mint64\
    \ = ModularInteger<int64_t, Mods...>;\n\nusing MintP = Mint32<(int32_t)1e9+7>;\n\
    using MintNTT = Mint32<998244353>;\n} // namespace lib\n\n\n#line 4 \"tests/judge/lagrange.cpp\"\
    \n\nusing namespace std;\nconst int MOD = (int)1e9+7;\nusing Field = lib::Mint32<MOD>;\n\
    \nlib::linalg::PrefixLagrange<Field> lagrange;\n\nconst int N = 3010;\nint n;\n\
    Field dp[N][N];\nvector<int> adj[N];\n\nvoid dfs(int u) {\n  for(int i = 0; i\
    \ <= n; i++) dp[u][i] = 1;\n  for(int v : adj[u]) {\n    dfs(v);\n    Field acc\
    \ = 0;\n    for(int i = 0; i <= n; i++) {\n      acc += dp[v][i];\n      dp[u][i]\
    \ *= acc;\n    }\n  }\n}\n\nint32_t main() {\n  int X;\n  cin >> n >> X;\n\n \
    \ for(int i = 1; i < n; i++) {\n    int p; cin >> p;\n    --p;\n    adj[p].push_back(i);\n\
    \  }\n\n  dfs(0);\n  vector<Field> p(n + 1);\n  p[0] = dp[0][0];\n  for(int i\
    \ = 1; i <= n; i++) p[i] = p[i-1] + dp[0][i];\n  cout << lagrange.eval(p, --X)\
    \ << endl;\n}\n"
  code: "#include <bits/stdc++.h>\n#include \"../../Lagrange.cpp\"\n#include \"../../ModularInteger.cpp\"\
    \n\nusing namespace std;\nconst int MOD = (int)1e9+7;\nusing Field = lib::Mint32<MOD>;\n\
    \nlib::linalg::PrefixLagrange<Field> lagrange;\n\nconst int N = 3010;\nint n;\n\
    Field dp[N][N];\nvector<int> adj[N];\n\nvoid dfs(int u) {\n  for(int i = 0; i\
    \ <= n; i++) dp[u][i] = 1;\n  for(int v : adj[u]) {\n    dfs(v);\n    Field acc\
    \ = 0;\n    for(int i = 0; i <= n; i++) {\n      acc += dp[v][i];\n      dp[u][i]\
    \ *= acc;\n    }\n  }\n}\n\nint32_t main() {\n  int X;\n  cin >> n >> X;\n\n \
    \ for(int i = 1; i < n; i++) {\n    int p; cin >> p;\n    --p;\n    adj[p].push_back(i);\n\
    \  }\n\n  dfs(0);\n  vector<Field> p(n + 1);\n  p[0] = dp[0][0];\n  for(int i\
    \ = 1; i <= n; i++) p[i] = p[i-1] + dp[0][i];\n  cout << lagrange.eval(p, --X)\
    \ << endl;\n}\n"
  dependsOn:
  - Lagrange.cpp
  - ModularInteger.cpp
  - NumberTheory.cpp
  isVerificationFile: false
  path: tests/judge/lagrange.cpp
  requiredBy: []
  timestamp: '2021-01-31 01:48:38-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tests/judge/lagrange.cpp
layout: document
redirect_from:
- /library/tests/judge/lagrange.cpp
- /library/tests/judge/lagrange.cpp.html
title: tests/judge/lagrange.cpp
---
