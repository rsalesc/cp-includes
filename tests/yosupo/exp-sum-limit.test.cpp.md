---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: BitTricks.cpp
    title: BitTricks.cpp
  - icon: ':heavy_check_mark:'
    path: Combinatorics.cpp
    title: Combinatorics.cpp
  - icon: ':heavy_check_mark:'
    path: Combinatorics.cpp
    title: Combinatorics.cpp
  - icon: ':heavy_check_mark:'
    path: Lagrange.cpp
    title: Lagrange.cpp
  - icon: ':question:'
    path: ModularInteger.cpp
    title: ModularInteger.cpp
  - icon: ':question:'
    path: NumberTheory.cpp
    title: NumberTheory.cpp
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  - icon: ':heavy_check_mark:'
    path: polynomial/ExponentialSum.cpp
    title: Exponential Sum
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
    links:
    - https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
  bundledCode: "#line 1 \"tests/yosupo/exp-sum-limit.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit\"\n\n\
    #include <bits/stdc++.h>\n#line 1 \"ModularInteger.cpp\"\n\n\n#line 1 \"NumberTheory.cpp\"\
    \n\n\n#line 4 \"NumberTheory.cpp\"\n\nnamespace lib {\nusing namespace std;\n\
    namespace nt {\nint64_t inverse(int64_t a, int64_t b) {\n  long long b0 = b, t,\
    \ q;\n  long long x0 = 0, x1 = 1;\n  if (b == 1)\n    return 1;\n  while (a >\
    \ 1) {\n    q = a / b;\n    t = b, b = a % b, a = t;\n    t = x0, x0 = x1 - q\
    \ * x0, x1 = t;\n  }\n  if (x1 < 0)\n    x1 += b0;\n  return x1;\n}\ntemplate<typename\
    \ T, typename U>\nT powmod (T a, U b, U p) {\n    int res = 1;\n    while (b)\n\
    \        if (b & 1)\n            res = (int) (res * 1ll * a % p),  --b;\n    \
    \    else\n            a = (int) (a * 1ll * a % p),  b >>= 1;\n    return res;\n\
    }\ntemplate<typename T>\nvector<T> factors(T n) {\n  vector<T> f;\n  for(T i =\
    \ 2; i*i <= n; i++) {\n    if(n % i == 0) f.push_back(i);\n    while(n % i ==\
    \ 0) n /= i;\n  }\n  if(n > 1) f.push_back(n);\n  return f;\n}\n} // namespace\
    \ nt\n} // namespace lib\n\n\n#line 5 \"ModularInteger.cpp\"\n\n#if __cplusplus\
    \ < 201300\n#error required(c++14)\n#endif\n\nnamespace lib {\nusing namespace\
    \ std;\nnamespace {\ntemplate <typename T, T... Mods> struct ModularIntegerBase\
    \ {\n  typedef ModularIntegerBase<T, Mods...> type;\n\n  T x[sizeof...(Mods)];\n\
    \  friend ostream &operator<<(ostream &output, const type &var) {\n    output\
    \ << \"(\";\n    for (int i = 0; i < sizeof...(Mods); i++) {\n      if (i)\n \
    \       output << \", \";\n      output << var.x[i];\n    }\n    return output\
    \ << \")\";\n  }\n};\n\ntemplate <typename T, T Mod> struct ModularIntegerBase<T,\
    \ Mod> {\n  typedef ModularIntegerBase<T, Mod> type;\n  constexpr static T mod\
    \ = Mod;\n\n  T x[1];\n\n  T& data() { return this->x[0]; }\n  T data() const\
    \ { return this->x[0]; }\n  explicit operator int() const { return this->x[0];\
    \ }\n  explicit operator int64_t() const { return this->x[0]; }\n  explicit operator\
    \ double() const { return this->x[0]; }\n  explicit operator long double() const\
    \ { return this->x[0]; }\n  friend ostream &operator<<(ostream &output, const\
    \ type &var) {\n    return output << var.x[0];\n  }\n};\n\ntemplate<typename T,\
    \ typename U, T... Mods>\nstruct InversesTable {\n  constexpr static size_t n_mods\
    \ = sizeof...(Mods);\n  constexpr static T mods[sizeof...(Mods)] = {Mods...};\n\
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
    \      return false;\n    };\n  };\n  typedef Less less;\n\n\n  constexpr ModularIntegerImpl()\
    \ {\n    for (size_t i = 0; i < sizeof...(Mods); i++)\n      x[i] = T();\n  }\n\
    \  constexpr ModularIntegerImpl(large_int y) {\n    for (size_t i = 0; i < sizeof...(Mods);\
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
    using MintNTT = Mint32<998244353>;\n} // namespace lib\n\n\n#line 1 \"polynomial/ExponentialSum.cpp\"\
    \n\n\n#line 1 \"Combinatorics.cpp\"\n\n\n#line 1 \"BitTricks.cpp\"\n\n\n#line\
    \ 4 \"BitTricks.cpp\"\n\nnamespace lib {\nlong long next_power_of_two(long long\
    \ n) {\n  return 1LL << (sizeof(long long) * 8 - 1 - __builtin_clzll(n) +\n  \
    \               ((n & (n - 1LL)) != 0));\n}\n} // namespace lib\n\n\n#line 5 \"\
    Combinatorics.cpp\"\n\nnamespace lib {\nusing namespace std;\ntemplate<typename\
    \ T>\nstruct Combinatorics {\n    static vector<T> fat;\n    static vector<T>\
    \ inv;\n    static vector<T> ifat;\n\n    static T factorial(int i) {\n      \
    \  ensure_fat(next_power_of_two(i));\n        return fat[i];\n    }\n\n    static\
    \ T inverse(int i) {\n        ensure_inv(next_power_of_two(i));\n        return\
    \ inv[i];\n    }\n\n    static T ifactorial(int i) {\n        ensure_ifat(next_power_of_two(i));\n\
    \        return ifat[i];\n    }\n\n    static T nCr(int n, int K) {\n        if(K\
    \ > n) return 0;\n        ensure_fat(next_power_of_two(n));\n        ensure_ifat(next_power_of_two(n));\n\
    \        return fat[n] * ifat[n-K] * ifat[K];\n    }\n\n    static T arrangement(int\
    \ n, int K) {\n        return nCr(n, K) * factorial(n);\n    }\n\n    static T\
    \ nCr_rep(int n, int K) {\n        return interpolate(n - 1, K);\n    }\n\n  \
    \  static T interpolate(int a, int b) {\n        return nCr(a+b, b);\n    }\n\n\
    \    static void ensure_fat(int i) {\n        int o = fat.size();\n        if(i\
    \ < o) return;\n        fat.resize(i+1);\n        for(int j = o; j <= i; j++)\
    \ fat[j] = fat[j-1]*j;\n    }\n\n    static void ensure_inv(int i) {\n       \
    \ int o = inv.size();\n        if(i < o) return;\n        inv.resize(i+1);\n \
    \       for(int j = o; j <= i; j++) inv[j] = -(inv[T::mod%j] * (T::mod/j));\n\
    \    }\n\n    static void ensure_ifat(int i) {\n        int o = ifat.size();\n\
    \        if(i < o) return;\n        ifat.resize(i+1);\n        ensure_inv(i);\n\
    \        for(int j = o; j <= i; j++) ifat[j] = ifat[j-1]*inv[j];\n    }\n};\n\n\
    template<typename T>\nvector<T> Combinatorics<T>::fat = vector<T>(1, T(1));\n\
    template<typename T>\nvector<T> Combinatorics<T>::inv = vector<T>(2, T(1));\n\
    template<typename T>\nvector<T> Combinatorics<T>::ifat = vector<T>(1, T(1));\n\
    } // namespace lib\n\n\n#line 1 \"Lagrange.cpp\"\n\n\n#line 5 \"Lagrange.cpp\"\
    \n\nnamespace lib {\nusing namespace std;\nnamespace linalg {\ntemplate <typename\
    \ Field> struct PrefixLagrange {\n  vector<Field> pref, suf;\n  PrefixLagrange()\
    \ {}\n\n  void ensure(int n) {\n    int o = pref.size();\n    if (n <= o)\n  \
    \    return;\n    pref.resize(n), suf.resize(n);\n  }\n\n  template <typename\
    \ T> Field eval(const vector<Field> &v, T x) {\n    using C = Combinatorics<Field>;\n\
    \    assert(!v.empty());\n    int d = (int)v.size() - 1;\n    if (x <= d)\n  \
    \    return v[x];\n\n    ensure(d + 1);\n\n    Field a = x;\n    pref[0] = suf[d]\
    \ = 1;\n    for (T i = 0; i < d; i++)\n      pref[i + 1] = pref[i] * a, a -= 1;\n\
    \    for (T i = d; i; i--)\n      suf[i - 1] = suf[i] * a, a += 1;\n\n    Field\
    \ ans = 0;\n    for (int i = 0; i <= d; i++) {\n      Field l = pref[i] * suf[i]\
    \ * C::ifactorial(i) * C::ifactorial(d-i) * v[i];\n      if ((d + i) & 1)\n  \
    \      l = -l;\n      ans += l;\n    }\n    return ans;\n  }\n};\n\ntemplate<typename\
    \ T, typename U>\nT lagrange_iota(const vector<T>& f, U n) {\n  static PrefixLagrange<T>\
    \ lag;\n  return lag.eval(f, n);\n}\n\ntemplate<typename T, typename U>\nT lagrange_iota_sum(const\
    \ vector<T>& f, U n) {\n  int m = f.size();\n  vector<T> g(m + 1);\n  for(int\
    \ i = 1; i <= m; i++)\n      g[i] = g[i-1] + f[i-1];\n  return lagrange_iota(g,\
    \ n);\n}\n} // namespace linalg\n} // namespace lib\n\n\n#line 6 \"polynomial/ExponentialSum.cpp\"\
    \n\nnamespace lib {\nusing namespace std;\n\n// given  : f(0)...f(k) (deg(f) =\
    \ k), a\n// return : \\sum_{i=0...infty} a^i f(i)\ntemplate<typename Field>\n\
    Field exponential_sum_limit(const vector<Field>& f, Field a) {\n  if(a == 0) return\
    \ f[0];\n  assert(a != 1);\n  int m = f.size();\n  vector<Field> g(m);\n  Field\
    \ acc = 1;\n  for(int i = 0; i < m; i++) g[i] = f[i] * acc, acc *= a;\n  for(int\
    \ i = 1; i < m; i++) g[i] += g[i-1];\n  Field c = 0;\n  acc = 1;\n  for(int i\
    \ = 0; i < m; i++) {\n    c += Combinatorics<Field>::nCr(m, i) * acc * g[m - i\
    \ - 1];\n    acc *= -a;\n  }\n  c /= (1 - a)^m;\n  return c;\n}\n\n// given  :\
    \ f(0)...f(k) (deg(f) = k), a, n\n// return : \\sum_{i=0...n-1} a^i f(i)\ntemplate<typename\
    \ Field>\nField exponential_sum(const vector<Field>& f, Field a, int64_t n) {\n\
    \  if(n == 0) return 0;\n  if(a == 0) return f[0];\n  if(a == 1) {\n    // Interpolate\
    \ polynomial of deg == k + 1\n    return linalg::lagrange_iota_sum(f, n);\n  }\n\
    \  int m = f.size();\n  vector<Field> g(m);\n  auto c = exponential_sum_limit(f,\
    \ a);\n  Field acc = 1;\n  for(int i = 0; i < m; i++) g[i] = f[i] * acc, acc *=\
    \ a;\n  for(int i = 1; i < m; i++) g[i] += g[i-1];\n  auto ai = Field(1) / a;\n\
    \  acc = 1;\n  for(int i = 0; i < m; i++) {\n    g[i] = (g[i] - c) * acc;\n  \
    \  acc *= ai;\n  }\n  // Interpolate polynomial of deg == k\n  auto tn = linalg::lagrange_iota(g,\
    \ n - 1);\n  return c + (a^(n-1)) * tn;\n}\n\n// given  : p, n\n// return : (0^p,\
    \ 1^p, ... , n^p)\ntemplate <typename Field>\nvector<Field> monomials(int p, int\
    \ n) {\n  vector<Field> f(n + 1, Field(0));\n  if (!p) {\n    f[0] = 1;\n    return\
    \ std::move(f);\n  }\n  f[1] = 1;\n  vector<bool> sieve(n + 1, false);\n  vector<int>\
    \ ps;\n  for (int i = 2; i <= n; i++) {\n    if (!sieve[i]) {\n      f[i] = Field(i)^p;\n\
    \      ps.push_back(i);\n    }\n    for (int j = 0; j < (int)ps.size() && i *\
    \ ps[j] <= n; j++) {\n      sieve[i * ps[j]] = 1;\n      f[i * ps[j]] = f[i] *\
    \ f[ps[j]];\n      if (i % ps[j] == 0) break;\n    }\n  }\n  return std::move(f);\n\
    }\n} // namespace lib\n\n\n#line 6 \"tests/yosupo/exp-sum-limit.test.cpp\"\n#define\
    \ int long long\nusing namespace std;\n \n#define mp make_pair\n#define mt make_tuple\n\
    #define pb push_back\n#define ms(v, x) memset((v), (x), sizeof(v))\n#define all(v)\
    \ (v).begin(), (v).end()\n#define ff first\n#define ss second\n#define iopt ios::sync_with_stdio(false);\
    \ cin.tie(0)\n#define untie(p, a, b) decltype(p.first) a = p.first, decltype(p.second)\
    \ b = p.second\n \nint gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }\n\
    int power(int x, int p, int MOD) {\n    if(p == 0) return 1%MOD;\n    if(p ==\
    \ 1) return x%MOD;\n    int res = power(x, p/2, MOD);\n    res = (long long)res*res%MOD;\n\
    \    if(p&1) res = (long long)res*x%MOD;\n    return res;\n}\n \ntypedef pair<int,\
    \ int> ii;\ntypedef long double LD;\ntypedef vector<int> vi;\n\nusing namespace\
    \ lib;\nusing mint = MintNTT;\n\nint32_t main(){\n    // Scanner sc(stdin);\n\
    \    // Printer pr(stdout);\n    iopt;\n\n    mint r;\n    int d;\n    cin >>\
    \ r >> d;\n\n    auto f = monomials<mint>(d, d);\n    cout << exponential_sum_limit(f,\
    \ r) << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit\"\
    \n\n#include <bits/stdc++.h>\n#include \"ModularInteger.cpp\"\n#include \"polynomial/ExponentialSum.cpp\"\
    \n#define int long long\nusing namespace std;\n \n#define mp make_pair\n#define\
    \ mt make_tuple\n#define pb push_back\n#define ms(v, x) memset((v), (x), sizeof(v))\n\
    #define all(v) (v).begin(), (v).end()\n#define ff first\n#define ss second\n#define\
    \ iopt ios::sync_with_stdio(false); cin.tie(0)\n#define untie(p, a, b) decltype(p.first)\
    \ a = p.first, decltype(p.second) b = p.second\n \nint gcd(int a, int b) { return\
    \ b == 0 ? a : gcd(b, a%b); }\nint power(int x, int p, int MOD) {\n    if(p ==\
    \ 0) return 1%MOD;\n    if(p == 1) return x%MOD;\n    int res = power(x, p/2,\
    \ MOD);\n    res = (long long)res*res%MOD;\n    if(p&1) res = (long long)res*x%MOD;\n\
    \    return res;\n}\n \ntypedef pair<int, int> ii;\ntypedef long double LD;\n\
    typedef vector<int> vi;\n\nusing namespace lib;\nusing mint = MintNTT;\n\nint32_t\
    \ main(){\n    // Scanner sc(stdin);\n    // Printer pr(stdout);\n    iopt;\n\n\
    \    mint r;\n    int d;\n    cin >> r >> d;\n\n    auto f = monomials<mint>(d,\
    \ d);\n    cout << exponential_sum_limit(f, r) << endl;\n    return 0;\n}\n"
  dependsOn:
  - bits/stdc++.h
  - ModularInteger.cpp
  - NumberTheory.cpp
  - polynomial/ExponentialSum.cpp
  - Combinatorics.cpp
  - BitTricks.cpp
  - Lagrange.cpp
  - Combinatorics.cpp
  isVerificationFile: true
  path: tests/yosupo/exp-sum-limit.test.cpp
  requiredBy: []
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/yosupo/exp-sum-limit.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/exp-sum-limit.test.cpp
- /verify/tests/yosupo/exp-sum-limit.test.cpp.html
title: tests/yosupo/exp-sum-limit.test.cpp
---
