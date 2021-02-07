---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: BitTricks.cpp
    title: BitTricks.cpp
  - icon: ':warning:'
    path: Complex.cpp
    title: Complex.cpp
  - icon: ':warning:'
    path: DFT.cpp
    title: DFT.cpp
  - icon: ':warning:'
    path: FFT.cpp
    title: FFT.cpp
  - icon: ':warning:'
    path: LongMultiplication.cpp
    title: LongMultiplication.cpp
  - icon: ':warning:'
    path: ModularInteger.cpp
    title: ModularInteger.cpp
  - icon: ':warning:'
    path: NumberTheory.cpp
    title: NumberTheory.cpp
  - icon: ':warning:'
    path: geometry/Trigonometry.cpp
    title: geometry/Trigonometry.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tests/judge/kinv.cpp\"\n#include <bits/stdc++.h>\n#line\
    \ 1 \"ModularInteger.cpp\"\n\n\n#line 1 \"NumberTheory.cpp\"\n\n\n#line 4 \"NumberTheory.cpp\"\
    \n\nnamespace lib {\nusing namespace std;\nnamespace nt {\nint64_t inverse(int64_t\
    \ a, int64_t b) {\n  long long b0 = b, t, q;\n  long long x0 = 0, x1 = 1;\n  if\
    \ (b == 1)\n    return 1;\n  while (a > 1) {\n    q = a / b;\n    t = b, b = a\
    \ % b, a = t;\n    t = x0, x0 = x1 - q * x0, x1 = t;\n  }\n  if (x1 < 0)\n   \
    \ x1 += b0;\n  return x1;\n}\ntemplate<typename T, typename U>\nT powmod (T a,\
    \ U b, U p) {\n    int res = 1;\n    while (b)\n        if (b & 1)\n         \
    \   res = int (res * 1ll * a % p),  --b;\n        else\n            a = int (a\
    \ * 1ll * a % p),  b >>= 1;\n    return res;\n}\ntemplate<typename T>\nvector<T>\
    \ factors(T n) {\n  vector<T> f;\n  for(T i = 2; i*i <= n; i++) {\n    if(n %\
    \ i == 0) f.push_back(i);\n    while(n % i == 0) n /= i;\n  }\n  if(n > 1) f.push_back(n);\n\
    \  return f;\n}\n} // namespace nt\n} // namespace lib\n\n\n#line 5 \"ModularInteger.cpp\"\
    \n\n#if __cplusplus < 201300\n#error required(c++14)\n#endif\n\nnamespace lib\
    \ {\nusing namespace std;\nnamespace {\ntemplate <typename T, T... Mods> struct\
    \ ModularIntegerBase {\n  typedef ModularIntegerBase<T, Mods...> type;\n\n  T\
    \ x[sizeof...(Mods)];\n  friend ostream &operator<<(ostream &output, const type\
    \ &var) {\n    output << \"(\";\n    for (int i = 0; i < sizeof...(Mods); i++)\
    \ {\n      if (i)\n        output << \", \";\n      output << var.x[i];\n    }\n\
    \    return output << \")\";\n  }\n};\n\ntemplate <typename T, T Mod> struct ModularIntegerBase<T,\
    \ Mod> {\n  typedef ModularIntegerBase<T, Mod> type;\n  constexpr static T mod\
    \ = Mod;\n\n  T x[1];\n\n  T& data() { return this->x[0]; }\n  T data() const\
    \ { return this->x[0]; }\n  explicit operator int() const { return this->x[0];\
    \ }\n  explicit operator int64_t() const { return this->x[0]; }\n  explicit operator\
    \ long long() const { return this->x[0]; }\n  explicit operator double() const\
    \ { return this->x[0]; }\n  explicit operator long double() const { return this->x[0];\
    \ }\n  friend ostream &operator<<(ostream &output, const type &var) {\n    return\
    \ output << var.x[0];\n  }\n};\n\ntemplate<typename T, typename U, T... Mods>\n\
    struct InversesTable {\n  constexpr static size_t n_mods = sizeof...(Mods);\n\
    \  constexpr static T mods[sizeof...(Mods)] = {Mods...};\n  constexpr static int\
    \ n_inverses = 1e6 + 10;\n\n  T v[n_inverses][n_mods];\n  T max_x;\n\n  InversesTable()\
    \ : v(), max_x(n_inverses) {\n    for(int j = 0; j < sizeof...(Mods); j++)\n \
    \     v[1][j] = 1, max_x = min(max_x, mods[j]);\n    for(int i = 2; i < max_x;\
    \ i++) {\n      for(int j = 0; j < sizeof...(Mods); j++) {\n        v[i][j] =\
    \ mods[j] - (T)((U)(mods[j] / i) * v[mods[j] % i][j] % mods[j]);\n      }\n  \
    \  }\n  }\n};\n\n// Make available for linkage.\ntemplate <typename T, class U,\
    \ T... Mods>\nconstexpr T InversesTable<T, U, Mods...>::mods[];\n\ntemplate <typename\
    \ T, class Enable, T... Mods>\nstruct ModularIntegerImpl : ModularIntegerBase<T,\
    \ Mods...> {\n  typedef ModularIntegerImpl<T, Enable, Mods...> type;\n  typedef\
    \ T type_int;\n  typedef uint64_t large_int;\n  constexpr static size_t n_mods\
    \ = sizeof...(Mods);\n  constexpr static T mods[sizeof...(Mods)] = {Mods...};\n\
    \  using ModularIntegerBase<T, Mods...>::x;\n  using Inverses = InversesTable<T,\
    \ large_int, Mods...>;\n\n  struct Less {\n    bool operator()(const type &lhs,\
    \ const type &rhs) const {\n      for (size_t i = 0; i < sizeof...(Mods); i++)\n\
    \        if (lhs.x[i] != rhs.x[i])\n          return lhs.x[i] < rhs.x[i];\n  \
    \    return false;\n    };\n  };\n  typedef Less less;\n\n\n  ModularIntegerImpl()\
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
    using MintNTT = Mint32<998244353>;\n} // namespace lib\n\n\n#line 1 \"LongMultiplication.cpp\"\
    \n\n\n#line 4 \"LongMultiplication.cpp\"\n\nnamespace lib {\nusing namespace std;\n\
    namespace math {\nstruct NaiveMultiplication {\n  template<typename T>\n  using\
    \ Transform = void;\n\n  template <typename Field>\n  vector<Field> operator()(const\
    \ vector<Field> &a,\n                           const vector<Field> &b) const\
    \ {\n    vector<Field> res(a.size() + b.size());\n    for (size_t i = 0; i < a.size();\
    \ i++) {\n      for (size_t j = 0; j < b.size(); j++) {\n        res[i + j] +=\
    \ a[i] * b[j];\n      }\n    }\n    return res;\n  }\n};\n\ntemplate <typename\
    \ Mult, typename Field>\nvector<Field> shift_conv(const vector<Field> &a, vector<Field>\
    \ b) {\n  if (b.empty())\n    return {};\n  reverse(b.begin(), b.end());\n  int\
    \ n = a.size();\n  int m = b.size();\n\n  auto res = Mult()(a, b);\n  return vector<Field>(res.begin()\
    \ + m - 1, res.end());\n}\n} // namespace math\n} // namespace lib\n\n\n#line\
    \ 1 \"FFT.cpp\"\n\n\n#line 1 \"DFT.cpp\"\n\n\n#line 1 \"BitTricks.cpp\"\n\n\n\
    #line 4 \"BitTricks.cpp\"\n\nnamespace lib {\nlong long next_power_of_two(long\
    \ long n) {\n  return 1LL << (sizeof(long long) * 8 - 1 - __builtin_clzll(n) +\n\
    \                 ((n & (n - 1LL)) != 0));\n}\n} // namespace lib\n\n\n#line 5\
    \ \"DFT.cpp\"\n\nnamespace lib {\nusing namespace std;\nnamespace linalg {\ntemplate\
    \ <typename Ring, typename Provider>\nstruct DFT {\n  static vector<int> rev;\n\
    \  static vector<Ring> fa;\n\n  // function used to precompute rev for fixed size\
    \ fft (n is a power of two)\n  static void dft_rev(int n) {\n    Provider()(n);\n\
    \    int lbn = __builtin_ctz(n);\n    if ((int)rev.size() < (1 << lbn))\n    \
    \  rev.resize(1 << lbn);\n    int h = -1;\n    for (int i = 1; i < n; i++) {\n\
    \      if ((i & (i - 1)) == 0)\n        h++;\n      rev[i] = rev[i ^ (1 << h)]\
    \ | (1 << (lbn - h - 1));\n    }\n  }\n\n  static void dft_iter(Ring *p, int n)\
    \ {\n    Provider w;\n    for (int L = 2; L <= n; L <<= 1) {\n      for (int i\
    \ = 0; i < n; i += L) {\n        for (int j = 0; j < L / 2; j++) {\n         \
    \ Ring z = p[i + j + L / 2] * w[j + L / 2];\n          p[i + j + L / 2] = p[i\
    \ + j] - z;\n          p[i + j] += z;\n        }\n      }\n    }\n  }\n\n  static\
    \ void swap(vector<Ring> &buf) { std::swap(fa, buf); }\n  static void _dft(Ring\
    \ *p, int n) {\n    dft_rev(n);\n    for (int i = 0; i < n; i++)\n      if (i\
    \ < rev[i])\n        std::swap(p[i], p[rev[i]]);\n    dft_iter(p, n);\n  }\n \
    \ static void _idft(Ring *p, int n) {\n    _dft(p, n);\n    reverse(p + 1, p +\
    \ n);\n    Ring inv = Provider().inverse(n);\n    for (int i = 0; i < n; i++)\n\
    \      p[i] *= inv;\n  }\n\n  static void dft(int n) { _dft(fa.data(), n); }\n\
    \n  static void idft(int n) { _idft(fa.data(), n); }\n\n  static void dft(vector<Ring>\
    \ &v, int n) {\n    swap(v);\n    dft(n);\n    swap(v);\n  }\n  static void idft(vector<Ring>\
    \ &v, int n) {\n    swap(v);\n    idft(n);\n    swap(v);\n  }\n\n  static int\
    \ ensure(int a, int b = 0) {\n    int n = a+b;\n    n = next_power_of_two(n);\n\
    \    if ((int)fa.size() < n)\n      fa.resize(n);\n    return n;\n  }\n\n  static\
    \ void clear(int n) { fill(fa.begin(), fa.begin() + n, 0); }\n\n  template<typename\
    \ Iterator>\n  static void fill(Iterator begin, Iterator end) {\n    int n = ensure(distance(begin,\
    \ end));\n    int i = 0;\n    for(auto it = begin; it != end; ++it) {\n      fa[i++]\
    \ = *it;\n    }\n    for(;i < n; i++) fa[i] = Ring();\n  }\n};\n\ntemplate<typename\
    \ DF, typename U>\nstatic vector<U> retrieve(int n) {\n  assert(n <= DF::fa.size());\n\
    \  vector<U> res(n);\n  for(int i = 0; i < n; i++) res[i] = (U)DF::fa[i];\n  return\
    \ res;\n}\n\ntemplate<typename Ring, typename Provider>\nvector<int> DFT<Ring,\
    \ Provider>::rev = vector<int>();\n\ntemplate<typename Ring, typename Provider>\n\
    vector<Ring> DFT<Ring, Provider>::fa = vector<Ring>();\n}\n} // namespace lib\n\
    \n\n#line 1 \"Complex.cpp\"\n\n\n#line 4 \"Complex.cpp\"\n\nnamespace lib {\n\
    using namespace std;\ntemplate <typename T> struct Complex {\n  T re, im;\n  Complex(T\
    \ a = T(), T b = T()) : re(a), im(b) {}\n  T real() const { return re; }\n  T\
    \ imag() const { return im; }\n  explicit operator T() const { return re; }\n\
    \  template<typename G>\n  operator Complex<G>() const { return Complex<G>(re,\
    \ im); }\n  Complex conj() const { return Complex(re, -im); }\n  void operator+=(const\
    \ Complex<T> &rhs) { re += rhs.re, im += rhs.im; }\n  void operator-=(const Complex<T>\
    \ &rhs) { re -= rhs.re, im -= rhs.im; }\n  void operator*=(const Complex<T> &rhs)\
    \ {\n    tie(re, im) =\n        make_pair(re * rhs.re - im * rhs.im, re * rhs.im\
    \ + im * rhs.re);\n  }\n  Complex<T> operator+(const Complex<T> &rhs) {\n    Complex<T>\
    \ res = *this;\n    res += rhs;\n    return res;\n  }\n  Complex<T> operator-(const\
    \ Complex<T> &rhs) {\n    Complex<T> res = *this;\n    res -= rhs;\n    return\
    \ res;\n  }\n  Complex<T> operator*(const Complex<T> &rhs) {\n    Complex<T> res\
    \ = *this;\n    res *= rhs;\n    return res;\n  }\n  Complex<T> operator-() const\
    \ {\n    return {-re, -im};\n  }\n  void operator/=(const T x) { re /= x, im /=\
    \ x; }\n};\n} // namespace lib\n\n\n#line 1 \"geometry/Trigonometry.cpp\"\n\n\n\
    #line 4 \"geometry/Trigonometry.cpp\"\n\nnamespace lib {\nusing namespace std;\n\
    namespace geo {\nnamespace trig {\nconstexpr static long double PI = acosl(-1);\n\
    double cos(double x) { return ::cos(x); }\ndouble sin(double x) { return ::sin(x);\
    \ }\ndouble asin(double x) { return ::asin(x); }\ndouble acos(double x) { return\
    \ ::acos(x); }\ndouble atan2(double y, double x) { return ::atan2(y, x); }\nlong\
    \ double cos(long double x) { return ::cosl(x); }\nlong double sin(long double\
    \ x) { return ::sinl(x); }\nlong double asin(long double x) { return ::asinl(x);\
    \ }\nlong double acos(long double x) { return ::acosl(x); }\nlong double atan2(long\
    \ double y, long double x) { return ::atan2l(y, x); }\n} // namespace trig\n}\
    \ // namespace geo\n} // namespace lib\n\n\n#line 7 \"FFT.cpp\"\n\nnamespace lib\
    \ {\nusing namespace std;\nnamespace linalg {\n\ntemplate<typename T>\nstruct\
    \ ComplexRootProvider {\n  typedef Complex<T> cd;\n  typedef Complex<long double>\
    \ cld;\n  static vector<cd> w;\n  static vector<cld> wl;\n\n  static cld root(long\
    \ double ang) {\n    return cld(geo::trig::cos(ang), geo::trig::sin(ang));\n \
    \ }\n\n  cd operator()(int n, int k) {\n    long double ang = 2.0l * geo::trig::PI\
    \ / (n / k);\n    return root(ang);\n  }\n  void operator()(int n) {\n    n =\
    \ max(n, 2);\n    int k = max((int)w.size(), 2);\n    if ((int)w.size() < n)\n\
    \      w.resize(n), wl.resize(n);\n    else\n      return;\n    w[0] = w[1] =\
    \ cd(1.0, 0.0);\n    wl[0] = wl[1] = cld(1.0, 0.0);\n    for (; k < n; k *= 2)\
    \ {\n      long double ang = 2.0l * geo::trig::PI / (2*k);\n      cld step = root(ang);\n\
    \      for(int i = k; i < 2*k; i++)\n        w[i] = wl[i] = (i&1) ? wl[i/2] *\
    \ step : wl[i/2];\n    }\n  }\n  cd operator[](int i) {\n    return w[i];\n  }\n\
    \  cd inverse(int n) {\n    return cd(1.0 / n, 0.0);\n  }\n};\n\ntemplate<typename\
    \ T>\nvector<Complex<T>> ComplexRootProvider<T>::w = vector<Complex<T>>();\ntemplate<typename\
    \ T>\nvector<Complex<long double>> ComplexRootProvider<T>::wl = vector<Complex<long\
    \ double>>();\n\ntemplate<typename T = double>\nstruct FFT : public DFT<Complex<T>,\
    \ ComplexRootProvider<T>> {\n  using Parent = DFT<Complex<T>, ComplexRootProvider<T>>;\n\
    \  using Parent::fa;\n\n  template <typename U>\n  static void _convolve(const\
    \ vector<U> &a, const vector<U> &b) {\n    typedef Complex<T> cd;\n    int n =\
    \ Parent::ensure(a.size(), b.size());\n    for (size_t i = 0; i < (size_t)n; i++)\n\
    \      fa[i] = cd(i < a.size() ? (T)a[i] : T(),\n                 i < b.size()\
    \ ? (T)b[i] : T());\n    Parent::dft(n);\n    for (int i = 0; i < n; i++)\n  \
    \    fa[i] *= fa[i];\n    Parent::idft(n);\n    for (int i = 0; i < n; i++)\n\
    \      fa[i] = cd(fa[i].imag() / 2, T());\n  }\n\n  template<typename U>\n  static\
    \ vector<U> convolve(const vector<U>& a, const vector<U>& b) {\n    int sz = (int)a.size()\
    \ + b.size() - 1;\n    _convolve(a, b);\n    return retrieve<Parent, U>(sz);\n\
    \  }\n\n  template<typename U>\n  static vector<U> convolve_rounded(const vector<U>&\
    \ a, const vector<U>& b) {\n    int sz = (int)a.size() + b.size() - 1;\n    _convolve(a,\
    \ b);\n    vector<U> res(sz);\n    for(int i = 0; i < sz; i++) res[i] = (U)(long\
    \ long)(fa[i].real() + 0.5);\n    return res;\n  }\n\n  // TODO: use separate\
    \ static buffers for this function\n  template <typename M>\n  static vector<M>\
    \ convolve_mod(const vector<M> &a, const vector<M> &b) {\n    typedef typename\
    \ M::type_int type_int;\n    typedef typename M::large_int large_int;\n    typedef\
    \ Complex<T> cd;\n    typedef vector<cd> vcd;\n\n    static_assert(sizeof(M::mods)\
    \ / sizeof(type_int) == 1,\n                  \"cant multiply with multiple mods\"\
    );\n    type_int base = sqrtl(M::mods[0]) + 0.5;\n    M base_m = base;\n    int\
    \ sza = a.size();\n    int szb = b.size();\n    int sz = sza+szb-1;\n    int n\
    \ = next_power_of_two(sz);\n    Parent::dft_rev(n);\n\n    // establish buffers\n\
    \    vcd fa(n), fb(n), C1(n), C2(n);\n\n    for (int i = 0; i < n; i++)\n    \
    \  fa[i] = i < sza ? cd((type_int)a[i] / base, (type_int)a[i] % base) : cd();\n\
    \    for (int i = 0; i < n; i++)\n      fb[i] = i < szb ? cd((type_int)b[i] /\
    \ base, (type_int)b[i] % base) : cd();\n    Parent::dft(fa, n);\n    Parent::dft(fb,\
    \ n);\n\n    for (int i = 0; i < n; i++) {\n      int j = i ? n - i : 0;\n   \
    \   cd a1 = (fa[i] + fa[j].conj()) * cd(0.5, 0.0);\n      cd a2 = (fa[i] - fa[j].conj())\
    \ * cd(0.0, -0.5);\n      cd b1 = (fb[i] + fb[j].conj()) * cd(0.5, 0.0);\n   \
    \   cd b2 = (fb[i] - fb[j].conj()) * cd(0.0, -0.5);\n      cd c11 = a1 * b1, c12\
    \ = a1 * b2;\n      cd c21 = a2 * b1, c22 = a2 * b2;\n      C1[j] = c11 + c12\
    \ * cd(0.0, 1.0);\n      C2[j] = c21 + c22 * cd(0.0, 1.0);\n    }\n    Parent::idft(C1,\
    \ n), Parent::idft(C2, n);\n\n    vector<M> res(sz);\n    for (int i = 0; i <\
    \ sz; i++) {\n      int j = i ? n - i : 0;\n      M x = large_int(C1[j].real()\
    \ + 0.5);\n      M y1 = large_int(C1[j].imag() + 0.5);\n      M y2 = large_int(C2[j].real()\
    \ + 0.5);\n      M z = large_int(C2[j].imag() + 0.5);\n      res[i] = x * base_m\
    \ * base_m + (y1 + y2) * base_m + z;\n    }\n\n    return res;\n  }\n};\n} //\
    \ namespace linalg\n\nnamespace math {\nstruct FastMultiplication {\n  template<typename\
    \ T>\n  using Transform = linalg::FFT<T>;\n  template <typename Field, typename\
    \ U = double>\n  vector<Field> operator()(const vector<Field> &a,\n          \
    \                 const vector<Field> &b) const {\n    return linalg::FFT<U>::convolve_rounded(a,\
    \ b);\n  }\n};\n\nstruct FFTMultiplication {\n  template<typename T>\n  using\
    \ Transform = linalg::FFT<T>;\n  template <typename Field, typename U = double>\n\
    \  vector<Field> operator()(const vector<Field> &a,\n                        \
    \   const vector<Field> &b) const {\n    return linalg::FFT<U>::convolve(a, b);\n\
    \  }\n};\n\nstruct SafeMultiplication {\n  template<typename T>\n  using Transform\
    \ = linalg::FFT<T>;\n  template <typename Field, typename U = double>\n  vector<Field>\
    \ operator()(const vector<Field> &a,\n                           const vector<Field>\
    \ &b) const {\n    return linalg::FFT<U>::convolve_mod(a, b);\n  };\n};\n} //\
    \ namespace math\n} // namespace lib\n\n\n#line 5 \"tests/judge/kinv.cpp\"\n\n\
    using namespace std;\nusing namespace lib;\n\ntypedef long long ll;\n\nusing Field\
    \ = MintNTT;\n\nint32_t main() {\n  ios::sync_with_stdio(false); cin.tie(0);\n\
    \  string s;\n  cin >> s;\n\n  int n = s.size();\n\n  vector<Field> a(n), b(n);\n\
    \  for(int i = 0; i < n; i++) {\n    if(s[i] == 'A') a[i] = 1;\n    else b[i]\
    \ = 1;\n  }\n\n  auto res = math::shift_conv<math::FastMultiplication>(a, b);\n\
    \  for(int i = 1; i < n; i++) cout << res[i] << endl;\n}\n"
  code: "#include <bits/stdc++.h>\n#include \"../../ModularInteger.cpp\"\n#include\
    \ \"../../LongMultiplication.cpp\"\n#include \"../../FFT.cpp\"\n\nusing namespace\
    \ std;\nusing namespace lib;\n\ntypedef long long ll;\n\nusing Field = MintNTT;\n\
    \nint32_t main() {\n  ios::sync_with_stdio(false); cin.tie(0);\n  string s;\n\
    \  cin >> s;\n\n  int n = s.size();\n\n  vector<Field> a(n), b(n);\n  for(int\
    \ i = 0; i < n; i++) {\n    if(s[i] == 'A') a[i] = 1;\n    else b[i] = 1;\n  }\n\
    \n  auto res = math::shift_conv<math::FastMultiplication>(a, b);\n  for(int i\
    \ = 1; i < n; i++) cout << res[i] << endl;\n}\n"
  dependsOn:
  - ModularInteger.cpp
  - NumberTheory.cpp
  - LongMultiplication.cpp
  - FFT.cpp
  - DFT.cpp
  - BitTricks.cpp
  - Complex.cpp
  - geometry/Trigonometry.cpp
  isVerificationFile: false
  path: tests/judge/kinv.cpp
  requiredBy: []
  timestamp: '2021-01-31 01:48:38-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tests/judge/kinv.cpp
layout: document
redirect_from:
- /library/tests/judge/kinv.cpp
- /library/tests/judge/kinv.cpp.html
title: tests/judge/kinv.cpp
---
