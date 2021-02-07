---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ModularInteger.cpp
    title: ModularInteger.cpp
  - icon: ':heavy_check_mark:'
    path: NumberTheory.cpp
    title: NumberTheory.cpp
  - icon: ':heavy_check_mark:'
    path: Subset.cpp
    title: Subset.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/subset_convolution
    links:
    - https://judge.yosupo.jp/problem/subset_convolution
  bundledCode: "#line 1 \"tests/yosupo/subset-convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/subset_convolution\"\n\n#include <bits/stdc++.h>\n\
    #line 1 \"ModularInteger.cpp\"\n\n\n#line 1 \"NumberTheory.cpp\"\n\n\n#line 4\
    \ \"NumberTheory.cpp\"\n\nnamespace lib {\nusing namespace std;\nnamespace nt\
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
    using MintNTT = Mint32<998244353>;\n} // namespace lib\n\n\n#line 1 \"Subset.cpp\"\
    \n\n\n#line 4 \"Subset.cpp\"\n\nnamespace lib {\nusing namespace std;\n// Source:\
    \ https://github.com/NyaanNyaan/library/tree/master/set-function\n\ntemplate <typename\
    \ T>\nvoid superset_zeta_transform(vector<T>& f) {\n  int n = f.size();\n  assert((n\
    \ & (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0;\
    \ j < n; j++) {\n      if ((j & i) == 0) {\n        f[j] += f[j | i];\n      }\n\
    \    }\n  }\n}\n\ntemplate <typename T>\nvoid superset_mobius_transform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j] -= f[j | i];\n      }\n    }\n  }\n}\n\ntemplate <typename T>\n\
    void subset_zeta_transform(vector<T>& f) {\n  int n = f.size();\n  assert((n &\
    \ (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0; j\
    \ < n; j++) {\n      if ((j & i) == 0) {\n        f[j | i] += f[j];\n      }\n\
    \    }\n  }\n}\n\ntemplate <typename T>\nvoid subset_mobius_transform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j | i] -= f[j];\n      }\n    }\n  }\n}\n\ntemplate <typename T>\n\
    vector<T> or_convolution(vector<T> a, vector<T> b) {\n  assert(a.size() == b.size());\n\
    \  subset_zeta_transform(a);\n  subset_zeta_transform(b);\n  for (int i = 0; i\
    \ < (int)a.size(); i++) a[i] *= b[i];\n  subset_mobius_transform(a);\n  return\
    \ a;\n}\n\ntemplate <typename T>\nvector<T> and_convolution(vector<T> a, vector<T>\
    \ b) {\n  assert(a.size() == b.size());\n  superset_zeta_transform(a);\n  superset_zeta_transform(b);\n\
    \  for (int i = 0; i < (int)a.size(); i++) a[i] *= b[i];\n  superset_mobius_transform(a);\n\
    \  return a;\n}\n\ntemplate<typename T>\nvector<vector<T>> ranked_zeta_transform(const\
    \ vector<T>& f) {\n  int N = f.size();\n  assert((N & (N-1)) == 0);\n  int R =\
    \ __builtin_ctz(N);\n  vector<vector<T>> F(R + 1, vector<T>(N));\n  for(int i\
    \ = 0; i < N; i++)\n    F[__builtin_popcount(i)][i] = f[i];\n  for(int i = 0;\
    \ i <= R; i++)\n    subset_zeta_transform(F[i]);\n  return F;\n}\n\ntemplate<typename\
    \ T>\nvector<T> subset_convolution(const vector<T>& a, const vector<T>& b, int\
    \ offset = 0) {\n  int N = a.size();\n  assert(N == b.size());\n  assert((N &\
    \ (N-1)) == 0);\n  int R = __builtin_ctz(N);\n\n  auto A = ranked_zeta_transform(a),\
    \ B = ranked_zeta_transform(b);\n  auto C = vector<vector<T>>(R + 1, vector<T>(N));\n\
    \n  for(int m = 0; m < N; m++) {\n    for(int i = 0; i <= R; i++) {\n      for(int\
    \ j = offset; j <= i; j++) {\n        C[i][m] += A[j][m] * B[i + offset - j][m];\n\
    \      }\n    }\n  }\n\n  for(int i = 0; i <= R; i++)\n    subset_mobius_transform(C[i]);\n\
    \  vector<T> res(N);\n  for(int i = 0; i < N; i++)\n    res[i] = C[__builtin_popcount(i)][i];\n\
    \  return res;\n}\n} // namespace lib\n\n\n#line 6 \"tests/yosupo/subset-convolution.test.cpp\"\
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
    \    int N; cin >> N;\n    N = 1 << N;\n    vector<mint> A(N), B(N);\n    for(int\
    \ i = 0; i < N; i++)\n      cin >> A[i];\n    for(int i = 0; i < N; i++)\n   \
    \   cin >> B[i];\n    auto res = subset_convolution(A, B);\n    for(int i = 0;\
    \ i < N; i++) cout << res[i] << \" \";\n    cout << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n\n\
    #include <bits/stdc++.h>\n#include \"ModularInteger.cpp\"\n#include \"Subset.cpp\"\
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
    \    int N; cin >> N;\n    N = 1 << N;\n    vector<mint> A(N), B(N);\n    for(int\
    \ i = 0; i < N; i++)\n      cin >> A[i];\n    for(int i = 0; i < N; i++)\n   \
    \   cin >> B[i];\n    auto res = subset_convolution(A, B);\n    for(int i = 0;\
    \ i < N; i++) cout << res[i] << \" \";\n    cout << endl;\n    return 0;\n}\n"
  dependsOn:
  - ModularInteger.cpp
  - NumberTheory.cpp
  - Subset.cpp
  isVerificationFile: true
  path: tests/yosupo/subset-convolution.test.cpp
  requiredBy: []
  timestamp: '2021-02-07 15:36:07-03:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/yosupo/subset-convolution.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/subset-convolution.test.cpp
- /verify/tests/yosupo/subset-convolution.test.cpp.html
title: tests/yosupo/subset-convolution.test.cpp
---
