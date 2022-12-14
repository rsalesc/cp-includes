---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: BitTricks.cpp
    title: BitTricks.cpp
  - icon: ':question:'
    path: DFT.cpp
    title: DFT.cpp
  - icon: ':question:'
    path: FHT.cpp
    title: FHT.cpp
  - icon: ':question:'
    path: ModularInteger.cpp
    title: ModularInteger.cpp
  - icon: ':question:'
    path: NTT.cpp
    title: NTT.cpp
  - icon: ':question:'
    path: NumberTheory.cpp
    title: NumberTheory.cpp
  - icon: ':question:'
    path: Traits.cpp
    title: Traits.cpp
  - icon: ':question:'
    path: VectorN.cpp
    title: VectorN.cpp
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  - icon: ':question:'
    path: polynomial/Transform.cpp
    title: polynomial/Transform.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"tests/yosupo/fht-convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include <bits/stdc++.h>\n\
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
    \ }\n  explicit operator double() const { return this->x[0]; }\n  explicit operator\
    \ long double() const { return this->x[0]; }\n  friend ostream &operator<<(ostream\
    \ &output, const type &var) {\n    return output << var.x[0];\n  }\n};\n\ntemplate<typename\
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
    using MintNTT = Mint32<998244353>;\n} // namespace lib\n\n\n#line 1 \"FHT.cpp\"\
    \n\n\n#line 1 \"BitTricks.cpp\"\n\n\n#line 4 \"BitTricks.cpp\"\n\nnamespace lib\
    \ {\nlong long next_power_of_two(long long n) {\n  return 1LL << (sizeof(long\
    \ long) * 8 - 1 - __builtin_clzll(n) +\n                 ((n & (n - 1LL)) != 0));\n\
    }\n} // namespace lib\n\n\n#line 1 \"NTT.cpp\"\n\n\n#line 1 \"DFT.cpp\"\n\n\n\
    #line 5 \"DFT.cpp\"\n\nnamespace lib {\nusing namespace std;\nnamespace linalg\
    \ {\ntemplate <typename Ring, typename Provider>\nstruct DFT {\n  static vector<int>\
    \ rev;\n  static vector<Ring> fa;\n\n  // function used to precompute rev for\
    \ fixed size fft (n is a power of two)\n  static void dft_rev(int n) {\n    Provider()(n);\n\
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
    \n\n#line 1 \"VectorN.cpp\"\n\n\n#line 1 \"Traits.cpp\"\n\n\n#line 4 \"Traits.cpp\"\
    \n\nnamespace lib {\nusing namespace std;\nnamespace traits {\n\ntemplate <typename...>\
    \ struct make_void { using type = void; };\n\ntemplate <typename... T> using void_t\
    \ = typename make_void<T...>::type;\n\n/// keep caide\ntemplate <typename Iterator>\n\
    using IteratorCategory = typename iterator_traits<Iterator>::iterator_category;\n\
    \n/// keep caide\ntemplate <typename Container>\nusing IteratorCategoryOf = IteratorCategory<typename\
    \ Container::iterator>;\n\n/// keep caide\ntemplate <typename Iterator>\nusing\
    \ IteratorValue = typename iterator_traits<Iterator>::value_type;\n\n/// keep\
    \ caide\ntemplate <typename Container>\nusing IteratorValueOf = IteratorValue<typename\
    \ Container::iterator>;\n\n/// keep caide\ntemplate <typename Iterator>\nusing\
    \ IsRandomIterator =\n    is_base_of<random_access_iterator_tag, IteratorCategory<Iterator>>;\n\
    \n/// keep caide\ntemplate <typename Iterator>\nusing IsInputIterator =\n    is_base_of<input_iterator_tag,\
    \ IteratorCategory<Iterator>>;\n\n/// keep caide\ntemplate <typename Iterator>\n\
    using IsBidirectionalIterator =\n    is_base_of<bidirectional_iterator_tag, IteratorCategory<Iterator>>;\n\
    \n/// keep caide\ntemplate <typename Container>\nusing HasRandomIterator =\n \
    \   is_base_of<random_access_iterator_tag, IteratorCategoryOf<Container>>;\n\n\
    /// keep caide\ntemplate <typename Container>\nusing HasInputIterator =\n    is_base_of<input_iterator_tag,\
    \ IteratorCategoryOf<Container>>;\n\n/// keep caide\ntemplate <typename Container>\n\
    using HasBidirectionalIterator =\n    is_base_of<bidirectional_iterator_tag, IteratorCategoryOf<Container>>;\n\
    } // namespace traits\n} // namespace lib\n\n\n#line 5 \"VectorN.cpp\"\n\n#define\
    \ VEC_CONST_OP(op, typ) \\\n  type operator op(const typ rhs) const { \\\n   \
    \ auto res = *this; \\\n    return res op##= rhs; \\\n  }\n\n#define VEC_BIN_OP(op)\
    \ \\\n  type& operator op##=(const type& rhs) { \\\n    if(rhs.size() > this->size())\
    \ \\\n      this->resize(rhs.size()); \\\n    int sz = this->size(); \\\n    for(int\
    \ i = 0; i < (int)rhs.size(); i++) \\\n      (*this)[i] op##= rhs[i]; \\\n   \
    \ for(int i = rhs.size(); i < sz; i++) \\\n      (*this)[i] op##= 0; \\\n    return\
    \ *this; \\\n  } \\\n  VEC_CONST_OP(op, type)\n\n#define VEC_SINGLE_OP(op, typ)\
    \ \\\n  type& operator op##=(const typ rhs) { \\\n    for(auto& x : *this) \\\n\
    \      x op##= rhs; \\\n    return *this; \\\n  } \\\n  VEC_CONST_OP(op, typ)\n\
    \  \n\nnamespace lib {\nusing namespace std;\ntemplate<typename T>\nstruct VectorN\
    \ : vector<T> {\n  using type = VectorN<T>;\n\n  template <\n      typename Container,\n\
    \      typename enable_if<traits::HasInputIterator<Container>::value>::type *\
    \ = nullptr>\n  VectorN(const Container &container)\n      : vector<T>(container.begin(),\
    \ container.end()) {}\n\n  VectorN(const initializer_list<T> &v)\n      : vector<T>(v.begin(),\
    \ v.end()) {}\n\n  template<typename... Args>\n  VectorN( Args&&... args ) \n\
    \      : vector<T>(std::forward<Args>(args)...) {}\n\n  VEC_BIN_OP(+)\n  VEC_BIN_OP(-)\n\
    \  VEC_BIN_OP(*)\n\n  VEC_SINGLE_OP(+, T&)\n  VEC_SINGLE_OP(-, T&)\n  VEC_SINGLE_OP(*,\
    \ T&)\n  VEC_SINGLE_OP(/, T&)\n  VEC_SINGLE_OP(^, int64_t)\n\n  type operator-()\
    \ const {\n    auto res = *this;\n    for(auto& x : res) x = -x;\n    return res;\n\
    \  }\n\n  type operator%(int n) const {\n    // TODO: get rid of this\n    //\
    \ return *const_cast<type*>(this);\n    return *this;\n  }\n};\n} // namespace\
    \ lib\n\n\n#line 7 \"NTT.cpp\"\n\nnamespace lib {\nusing namespace std;\nnamespace\
    \ linalg {\ntemplate<typename T>\nstruct MintRootProvider {\n  static size_t max_sz;\n\
    \  static T g;\n  static vector<T> w;\n\n  MintRootProvider() {\n    if(g == 0)\
    \ {\n      auto acc = T::mod-1;\n      while(acc % 2 == 0) acc /= 2, max_sz++;\n\
    \n      auto factors = nt::factors(T::mod - 1);\n      for(g = 2; (typename T::type_int)g\
    \ < T::mod; g++) {\n        bool ok = true;\n        for(auto f : factors) {\n\
    \          if(power(g, (T::mod-1)/f) == 1) {\n            ok = false;\n      \
    \      break;\n          }\n        }\n        if(ok) break;\n      }\n      assert(g\
    \ != 0);\n    }\n  }\n\n  pair<T, T> roots(int num, int den) {\n    auto p = g\
    \ ^ ((long long)(T::mod - 1) / den * num);\n    return {p, p.inverse()};\n  }\n\
    \n  T operator()(int n, int k) {\n    return power(g, (T::mod-1)/(n/k));\n  }\n\
    \  void operator()(int n) {\n    n = max(n, 2);\n    int k = max((int)w.size(),\
    \ 2);\n    assert(n <= (1LL << max_sz));\n    if ((int)w.size() < n)\n      w.resize(n);\n\
    \    else\n      return;\n    w[0] = w[1] = 1;\n    for (; k < n; k *= 2) {\n\
    \      T step = power(g, (T::mod-1)/(2*k));\n      for(int i = k; i < 2*k; i++)\n\
    \        w[i] = (i&1) ? w[i/2] * step : w[i/2];\n    }\n  }\n  T operator[](int\
    \ i) {\n    return w[i];\n  }\n\n  T inverse(int n) {\n    return T(1) / n;\n\
    \  }\n};\n\ntemplate<typename T>\nsize_t MintRootProvider<T>::max_sz = 1;\ntemplate<typename\
    \ T>\nT MintRootProvider<T>::g = T();\ntemplate<typename T>\nvector<T> MintRootProvider<T>::w\
    \ = vector<T>();\n\ntemplate<typename T>\nstruct NTT : public DFT<T, MintRootProvider<T>>\
    \ {\n  using Parent = DFT<T, MintRootProvider<T>>;\n  using Parent::fa;\n  using\
    \ Parent::dft;\n  using Parent::idft;\n\n  static void _convolve(const vector<T>\
    \ &a) {\n    int n = Parent::ensure(a.size(), a.size());\n    for (size_t i =\
    \ 0; i < (size_t)n; i++)\n      fa[i] = i < a.size() ? a[i] : T();\n    Parent::dft(n);\n\
    \    for (int i = 0; i < n; i++)\n      fa[i] *= fa[i];\n    Parent::idft(n);\n\
    \  }\n\n  static void _convolve(const vector<T> &a, const vector<T> &b) {\n  \
    \  if(std::addressof(a) == std::addressof(b))\n      return _convolve(a);\n  \
    \  int n = Parent::ensure(a.size(), b.size());\n    for (size_t i = 0; i < (size_t)n;\
    \ i++)\n      fa[i] = i < a.size() ? a[i] : T();\n    Parent::dft(n);\n    //\
    \ TODO: have a buffer for this\n    auto fb = retrieve<Parent, T>(n);\n    for(size_t\
    \ i = 0; i < (size_t)n; i++)\n      fa[i] = i < b.size() ? b[i] : T();\n    Parent::dft(n);\n\
    \    for (int i = 0; i < n; i++)\n      fa[i] *= fb[i];\n    Parent::idft(n);\n\
    \  }\n\n  static vector<T> convolve(const vector<T>& a, const vector<T>& b) {\n\
    \    int sz = (int)a.size() + b.size() - 1;\n    _convolve(a, b);\n    return\
    \ retrieve<Parent, T>(sz);\n  }\n  \n  static VectorN<T> transform(vector<T> a,\
    \ int n) {\n    a.resize(n);\n    Parent::dft(a, n);\n    return a;\n  }\n\n \
    \ static vector<T> itransform(vector<T> a, int n) {\n    int sz = a.size();\n\
    \    Parent::idft(a, sz);\n    a.resize(min(n, sz));\n    return a;\n  }\n};\n\
    }\n\nstruct NTTMultiplication {\n  template<typename T>\n  using Transform = linalg::NTT<T>;\n\
    \n  template <typename Field>\n  vector<Field> operator()(const vector<Field>\
    \ &a,\n                           const vector<Field> &b) const {\n    return\
    \ linalg::NTT<Field>::convolve(a, b);\n  };\n\n  template<typename Field>\n  inline\
    \ VectorN<Field> transform(int n, const vector<Field>& p) const {\n    int np\
    \ = next_power_of_two(n);\n    return linalg::NTT<Field>::transform(p, np);\n\
    \  }\n\n  template<typename Field>\n  inline vector<Field> itransform(int n, const\
    \ vector<Field>& p) const {\n    return linalg::NTT<Field>::itransform(p, n);\n\
    \  }\n\n  template <typename Field, typename Functor, typename ...Ts>\n  inline\
    \ vector<Field> on_transform(\n    int n,\n    Functor& f,        \n    const\
    \ vector<Ts>&... vs) const {\n    int np = next_power_of_two(n);\n    return linalg::NTT<Field>::itransform(\n\
    \      f(n, linalg::NTT<Field>::transform(vs, np)...), n);\n  }\n};\n} // namespace\
    \ lib\n\n\n#line 1 \"polynomial/Transform.cpp\"\n\n\n#line 4 \"polynomial/Transform.cpp\"\
    \n\nnamespace lib {\nusing namespace std;\ntemplate<template <class> class T>\n\
    struct TransformMultiplication {\n  template<typename Field>\n  using Transform\
    \ = T<Field>;\n\n  template <typename Field>\n  vector<Field> operator()(const\
    \ vector<Field> &a,\n                           const vector<Field> &b) const\
    \ {\n    return T<Field>::convolve(a, b);\n  };\n\n  template<typename Field>\n\
    \  inline VectorN<Field> transform(int n, const vector<Field>& p) const {\n  \
    \  int np = next_power_of_two(n);\n    return T<Field>::transform(p, np);\n  }\n\
    \n  template<typename Field>\n  inline vector<Field> itransform(int n, const vector<Field>&\
    \ p) const {\n    return T<Field>::itransform(p, n);\n  }\n\n  template <typename\
    \ Field, typename Functor, typename ...Ts>\n  inline vector<Field> on_transform(\n\
    \    int n,\n    Functor& f,        \n    const vector<Ts>&... vs) const {\n \
    \   int np = next_power_of_two(n);\n    return T<Field>::itransform(\n      f(n,\
    \ T<Field>::transform(vs, np)...), n);\n  }\n};\n} // namespace lib\n\n\n#line\
    \ 7 \"FHT.cpp\"\n\nnamespace lib {\nusing namespace std;\nnamespace linalg {\n\
    template <typename Ring>\nstruct FHT {\n  using Provider = MintRootProvider<Ring>;\n\
    \  using T = Ring;\n  using U = make_unsigned_t<typename Ring::type_int>;\n  using\
    \ U64 = make_unsigned_t<typename Ring::large_int>;\n  static vector<Ring> fa;\n\
    \  static const int MAX_LG_N = 30;\n  static vector<Ring> g, ig;\n  \n  static\
    \ void precompute() {\n    if(!g.empty()) return;\n    Provider();\n    g.resize(MAX_LG_N);\n\
    \    ig.resize(MAX_LG_N);\n    for(int i = 0; i < MAX_LG_N; i++) {\n      Ring\
    \ w = Provider::g ^ (((Ring::mod-1) >> (i + 2)) * 3);\n      w = -w;\n      Ring\
    \ iw = w.inverse();\n      g[i] = w;\n      ig[i] = iw;\n    }\n  }\n\n  static\
    \ inline U& v(Ring& p) {\n    return (U&)p.data();\n  }\n\n  static inline U v(const\
    \ Ring& p) {\n    return (U)p.data();\n  }\n\n  static void dft_iter(Ring *p,\
    \ int n) {\n    // decimation-in-time\n    // natural to reverse ordering\n  \
    \  for (int B = n >> 1; B; B >>= 1) {\n      Ring w = 1;\n      for (int i = 0,\
    \ twiddle = 0; i < n; i += B * 2) {\n        for (int j = i; j < i + B; j++) {\n\
    \          Ring z = p[j + B] * w;\n          p[j + B] = p[j] - z;\n          p[j]\
    \ += z;\n        }\n        w *= g[__builtin_ctz(++twiddle)];\n      }\n    }\n\
    \  }\n\n  static void idft_iter(Ring *p, int n) {\n    // decimation-in-frequency\n\
    \    // reverse to natural ordering\n    for (int B = 1; B < n; B <<= 1) {\n \
    \     Ring w = 1;\n      for (int i = 0, twiddle = 0; i < n; i += B * 2) {\n \
    \       for (int j = i; j < i + B; j++) {\n          Ring z = (p[j] - p[j + B])\
    \ * w;\n          p[j] += p[j + B];\n          p[j + B] = z;\n        }\n    \
    \    w *= ig[__builtin_ctz(++twiddle)];\n      }\n    }\n  }\n\n  static void\
    \ swap(vector<Ring> &buf) { std::swap(fa, buf); }\n  static void _dft(Ring *p,\
    \ int n) {\n    precompute();\n    dft_iter(p, n);\n  }\n  static void _idft(Ring\
    \ *p, int n) {\n    precompute();\n    idft_iter(p, n);\n    Ring inv = Provider().inverse(n);\n\
    \    for (int i = 0; i < n; i++)\n      p[i] *= inv;\n  }\n\n  static void dft(int\
    \ n) { _dft(fa.data(), n); }\n\n  static void idft(int n) { _idft(fa.data(), n);\
    \ }\n\n  static void dft(vector<Ring> &v, int n) {\n    swap(v);\n    dft(n);\n\
    \    swap(v);\n  }\n  static void idft(vector<Ring> &v, int n) {\n    swap(v);\n\
    \    idft(n);\n    swap(v);\n  }\n\n  static int ensure(int a, int b = 0) {\n\
    \    int n = a+b;\n    n = next_power_of_two(n);\n    if ((int)fa.size() < n)\n\
    \      fa.resize(n);\n    return n;\n  }\n\n  static void clear(int n) { fill(fa.begin(),\
    \ fa.begin() + n, 0); }\n\n  template<typename Iterator>\n  static void fill(Iterator\
    \ begin, Iterator end) {\n    int n = ensure(distance(begin, end));\n    int i\
    \ = 0;\n    for(auto it = begin; it != end; ++it) {\n      fa[i++] = *it;\n  \
    \  }\n    for(;i < n; i++) fa[i] = Ring();\n  }\n\n  static void _convolve(const\
    \ vector<T> &a) {\n    int n = ensure(a.size(), a.size());\n    for (size_t i\
    \ = 0; i < (size_t)n; i++)\n      fa[i] = i < a.size() ? a[i] : T();\n    dft(n);\n\
    \    for (int i = 0; i < n; i++)\n      fa[i] *= fa[i];\n    idft(n);\n  }\n\n\
    \  static void _convolve(const vector<T> &a, const vector<T> &b) {\n    if(std::addressof(a)\
    \ == std::addressof(b))\n      return _convolve(a);\n    int n = ensure(a.size(),\
    \ b.size());\n    for (size_t i = 0; i < (size_t)n; i++)\n      fa[i] = i < a.size()\
    \ ? a[i] : T();\n    dft(n);\n    // TODO: have a buffer for this\n    auto fb\
    \ = retrieve<FHT<T>, T>(n);\n    for(size_t i = 0; i < (size_t)n; i++)\n     \
    \ fa[i] = i < b.size() ? b[i] : T();\n    dft(n);\n    for (int i = 0; i < n;\
    \ i++)\n      fa[i] *= fb[i];\n    idft(n);\n  }\n\n  static vector<T> convolve(const\
    \ vector<T>& a, const vector<T>& b) {\n    int sz = (int)a.size() + b.size() -\
    \ 1;\n    _convolve(a, b);\n    return retrieve<FHT<T>, T>(sz);\n  }\n  \n  static\
    \ VectorN<T> transform(vector<T> a, int n) {\n    a.resize(n);\n    dft(a, n);\n\
    \    return a;\n  }\n\n  static vector<T> itransform(vector<T> a, int n) {\n \
    \   int sz = a.size();\n    idft(a, sz);\n    a.resize(min(n, sz));\n    return\
    \ a;\n  }\n};\n\ntemplate<typename Ring>\nvector<Ring> FHT<Ring>::fa = vector<Ring>();\n\
    template<typename Ring>\nvector<Ring> FHT<Ring>::g = vector<Ring>();\ntemplate<typename\
    \ Ring>\nvector<Ring> FHT<Ring>::ig = vector<Ring>();\n}\n\nusing FHTMultiplication\
    \ = TransformMultiplication<linalg::FHT>;\n} // namespace lib\n\n\n#line 6 \"\
    tests/yosupo/fht-convolution.test.cpp\"\nusing namespace std;\n \n#define mp make_pair\n\
    #define mt make_tuple\n#define pb push_back\n#define ms(v, x) memset((v), (x),\
    \ sizeof(v))\n#define all(v) (v).begin(), (v).end()\n#define ff first\n#define\
    \ ss second\n#define iopt ios::sync_with_stdio(false); cin.tie(0)\n#define untie(p,\
    \ a, b) decltype(p.first) a = p.first, decltype(p.second) b = p.second\n \nint\
    \ gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }\nint power(int x, int\
    \ p, int MOD) {\n    if(p == 0) return 1%MOD;\n    if(p == 1) return x%MOD;\n\
    \    int res = power(x, p/2, MOD);\n    res = (long long)res*res%MOD;\n    if(p&1)\
    \ res = (long long)res*x%MOD;\n    return res;\n}\n \ntypedef pair<int, int> ii;\n\
    typedef long double LD;\ntypedef vector<int> vi;\n\n#pragma region template\n\n\
    using ll = long long;\nusing ull = unsigned long long;\nconstexpr ll TEN(int n)\
    \ { return (n == 0) ? 1 : 10 * TEN(n - 1); }\ntemplate <class T> using V = vector<T>;\n\
    template <class T> using VV = V<V<T>>;\n\n#ifdef LOCAL\nstruct PrettyOS {\n  \
    \  ostream& os;\n    bool first;\n    template <class T> auto operator<<(T&& x)\
    \ {\n        if (!first) os << \", \";\n        first = false;\n        os <<\
    \ x;\n        return *this;\n    }\n};\ntemplate <class... T> void dbg0(T&&...\
    \ t) {\n    (PrettyOS{cerr, true} << ... << t);\n}\n#define dbg(...)         \
    \                                   \\\n    do {                             \
    \                       \\\n        cerr << __LINE__ << \" : \" << #__VA_ARGS__\
    \ << \" = \"; \\\n        dbg0(__VA_ARGS__);                                 \
    \ \\\n        cerr << endl;                                       \\\n    } while\
    \ (false);\n#else\n#define dbg(...)\n#endif\n\ntemplate <class T, class U>\nostream&\
    \ operator<<(ostream& os, const pair<T, U>& p) {\n    return os << \"P(\" << p.first\
    \ << \", \" << p.second << \")\";\n}\n\ntemplate <class T> ostream& operator<<(ostream&\
    \ os, const V<T>& v) {\n    os << \"[\";\n    for (auto d : v) os << d << \",\
    \ \";\n    return os << \"]\";\n}\n\nstruct Scanner {\n    FILE* fp = nullptr;\n\
    \    char line[1 << 15];\n    size_t st = 0, ed = 0;\n    void reread() {\n  \
    \      memmove(line, line + st, ed - st);\n        ed -= st;\n        st = 0;\n\
    \        ed += fread(line + ed, 1, (1 << 15) - ed, fp);\n    }\n    bool succ()\
    \ {\n        while (true) {\n            if (st == ed) {\n                reread();\n\
    \                if (st == ed) return false;\n            }\n            while\
    \ (st != ed && isspace(line[st])) st++;\n            if (st != ed) break;\n  \
    \      }\n        if (ed - st <= 50) reread();\n        return true;\n    }\n\
    \    template <class T, enable_if_t<is_same<T, string>::value, int> = 0>\n   \
    \ bool read_single(T& ref) {\n        if (!succ()) return false;\n        while\
    \ (true) {\n            succ();\n            size_t sz = 1;\n            while\
    \ (st + sz < ed && !isspace(line[st + sz])) sz++;\n            ref.append(line\
    \ + st, sz);\n            st += sz;\n            if (st != ed) break;\n      \
    \  }\n        return true;\n    }\n    template <class T, enable_if_t<is_integral<T>::value,\
    \ int> = 0>\n    bool read_single(T& ref) {\n        if (!succ()) return false;\n\
    \        bool neg = false;\n        if (line[st] == '-') {\n            neg =\
    \ true;\n            st++;\n        }\n        ref = T(0);\n        while (isdigit(line[st]))\
    \ {\n            ref = 10 * ref + (line[st++] - '0');\n        }\n        if (neg)\
    \ ref = -ref;\n        return true;\n    }\n    template <class T> bool read_single(V<T>&\
    \ ref) {\n        for (auto& d : ref) {\n            if (!read_single(d)) return\
    \ false;\n        }\n        return true;\n    }\n    void read() {}\n    template\
    \ <class H, class... T> void read(H& h, T&... t) {\n        bool f = read_single(h);\n\
    \        assert(f);\n        read(t...);\n    }\n    Scanner(FILE* _fp) : fp(_fp)\
    \ {}\n};\n\nstruct Printer {\n  public:\n    template <bool F = false> void write()\
    \ {}\n    template <bool F = false, class H, class... T>\n    void write(const\
    \ H& h, const T&... t) {\n        if (F) write_single(' ');\n        write_single(h);\n\
    \        write<true>(t...);\n    }\n    template <class... T>\n    void writeln(const\
    \ T&... t) {\n        write(t...);\n        write_single('\\n');\n    }\n\n  \
    \  Printer(FILE* _fp) : fp(_fp) {}\n    ~Printer() { flush(); }\n\n  private:\n\
    \    static constexpr size_t SIZE = 1 << 15;\n    FILE* fp;\n    char line[SIZE],\
    \ small[50];\n    size_t pos = 0;\n    void flush() {\n        fwrite(line, 1,\
    \ pos, fp);\n        pos = 0;\n    }\n    void write_single(const char& val) {\n\
    \        if (pos == SIZE) flush();\n        line[pos++] = val;\n    }\n    template\
    \ <class T, enable_if_t<is_same<T, string>::value, int> = 0>\n    void write_single(const\
    \ T& val) {\n        for (char c : val) write_single(c);\n    }\n    template\
    \ <class T, enable_if_t<is_integral<T>::value, int> = 0>\n    void write_single(T\
    \ val) {\n        if (pos > (1 << 15) - 50) flush();\n        if (val == 0) {\n\
    \            write_single('0');\n            return;\n        }\n        if (val\
    \ < 0) {\n            write_single('-');\n            val = -val;  // todo min\n\
    \        }\n        size_t len = 0;\n        while (val) {\n            small[len++]\
    \ = char('0' + (val % 10));\n            val /= 10;\n        }\n        reverse(small,\
    \ small + len);\n        memcpy(line + pos, small, len);\n        pos += len;\n\
    \    }\n    template <class T> void write_single(const V<T>& val) {\n        auto\
    \ n = val.size();\n        for (size_t i = 0; i < n; i++) {\n            if (i)\
    \ write_single(' ');\n            write_single(val[i]);\n        }\n    }\n};\n\
    \n#pragma endregion\n\nusing namespace lib;\nusing mint = MintNTT;\n\nint32_t\
    \ main(){\n    Scanner sc(stdin);\n    Printer pr(stdout);\n\n    int n, m;\n\
    \    sc.read(n, m);\n\n    V<mint> a(n);\n    for (int i = 0; i < n; i++) {\n\
    \        int x;\n        sc.read(x);\n        a[i] = x;\n    }\n    V<mint> b(m);\n\
    \    for (int i = 0; i < m; i++) {\n        int x;\n        sc.read(x);\n    \
    \    b[i] = x;\n    }\n    auto c = FHTMultiplication()(a, b);\n    for (auto\
    \ x: c) {\n        pr.write((int)x);\n        pr.write(' ');\n    }\n    pr.writeln();\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ <bits/stdc++.h>\n#include \"ModularInteger.cpp\"\n#include \"FHT.cpp\"\nusing\
    \ namespace std;\n \n#define mp make_pair\n#define mt make_tuple\n#define pb push_back\n\
    #define ms(v, x) memset((v), (x), sizeof(v))\n#define all(v) (v).begin(), (v).end()\n\
    #define ff first\n#define ss second\n#define iopt ios::sync_with_stdio(false);\
    \ cin.tie(0)\n#define untie(p, a, b) decltype(p.first) a = p.first, decltype(p.second)\
    \ b = p.second\n \nint gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }\n\
    int power(int x, int p, int MOD) {\n    if(p == 0) return 1%MOD;\n    if(p ==\
    \ 1) return x%MOD;\n    int res = power(x, p/2, MOD);\n    res = (long long)res*res%MOD;\n\
    \    if(p&1) res = (long long)res*x%MOD;\n    return res;\n}\n \ntypedef pair<int,\
    \ int> ii;\ntypedef long double LD;\ntypedef vector<int> vi;\n\n#pragma region\
    \ template\n\nusing ll = long long;\nusing ull = unsigned long long;\nconstexpr\
    \ ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }\ntemplate <class T>\
    \ using V = vector<T>;\ntemplate <class T> using VV = V<V<T>>;\n\n#ifdef LOCAL\n\
    struct PrettyOS {\n    ostream& os;\n    bool first;\n    template <class T> auto\
    \ operator<<(T&& x) {\n        if (!first) os << \", \";\n        first = false;\n\
    \        os << x;\n        return *this;\n    }\n};\ntemplate <class... T> void\
    \ dbg0(T&&... t) {\n    (PrettyOS{cerr, true} << ... << t);\n}\n#define dbg(...)\
    \                                            \\\n    do {                    \
    \                                \\\n        cerr << __LINE__ << \" : \" << #__VA_ARGS__\
    \ << \" = \"; \\\n        dbg0(__VA_ARGS__);                                 \
    \ \\\n        cerr << endl;                                       \\\n    } while\
    \ (false);\n#else\n#define dbg(...)\n#endif\n\ntemplate <class T, class U>\nostream&\
    \ operator<<(ostream& os, const pair<T, U>& p) {\n    return os << \"P(\" << p.first\
    \ << \", \" << p.second << \")\";\n}\n\ntemplate <class T> ostream& operator<<(ostream&\
    \ os, const V<T>& v) {\n    os << \"[\";\n    for (auto d : v) os << d << \",\
    \ \";\n    return os << \"]\";\n}\n\nstruct Scanner {\n    FILE* fp = nullptr;\n\
    \    char line[1 << 15];\n    size_t st = 0, ed = 0;\n    void reread() {\n  \
    \      memmove(line, line + st, ed - st);\n        ed -= st;\n        st = 0;\n\
    \        ed += fread(line + ed, 1, (1 << 15) - ed, fp);\n    }\n    bool succ()\
    \ {\n        while (true) {\n            if (st == ed) {\n                reread();\n\
    \                if (st == ed) return false;\n            }\n            while\
    \ (st != ed && isspace(line[st])) st++;\n            if (st != ed) break;\n  \
    \      }\n        if (ed - st <= 50) reread();\n        return true;\n    }\n\
    \    template <class T, enable_if_t<is_same<T, string>::value, int> = 0>\n   \
    \ bool read_single(T& ref) {\n        if (!succ()) return false;\n        while\
    \ (true) {\n            succ();\n            size_t sz = 1;\n            while\
    \ (st + sz < ed && !isspace(line[st + sz])) sz++;\n            ref.append(line\
    \ + st, sz);\n            st += sz;\n            if (st != ed) break;\n      \
    \  }\n        return true;\n    }\n    template <class T, enable_if_t<is_integral<T>::value,\
    \ int> = 0>\n    bool read_single(T& ref) {\n        if (!succ()) return false;\n\
    \        bool neg = false;\n        if (line[st] == '-') {\n            neg =\
    \ true;\n            st++;\n        }\n        ref = T(0);\n        while (isdigit(line[st]))\
    \ {\n            ref = 10 * ref + (line[st++] - '0');\n        }\n        if (neg)\
    \ ref = -ref;\n        return true;\n    }\n    template <class T> bool read_single(V<T>&\
    \ ref) {\n        for (auto& d : ref) {\n            if (!read_single(d)) return\
    \ false;\n        }\n        return true;\n    }\n    void read() {}\n    template\
    \ <class H, class... T> void read(H& h, T&... t) {\n        bool f = read_single(h);\n\
    \        assert(f);\n        read(t...);\n    }\n    Scanner(FILE* _fp) : fp(_fp)\
    \ {}\n};\n\nstruct Printer {\n  public:\n    template <bool F = false> void write()\
    \ {}\n    template <bool F = false, class H, class... T>\n    void write(const\
    \ H& h, const T&... t) {\n        if (F) write_single(' ');\n        write_single(h);\n\
    \        write<true>(t...);\n    }\n    template <class... T>\n    void writeln(const\
    \ T&... t) {\n        write(t...);\n        write_single('\\n');\n    }\n\n  \
    \  Printer(FILE* _fp) : fp(_fp) {}\n    ~Printer() { flush(); }\n\n  private:\n\
    \    static constexpr size_t SIZE = 1 << 15;\n    FILE* fp;\n    char line[SIZE],\
    \ small[50];\n    size_t pos = 0;\n    void flush() {\n        fwrite(line, 1,\
    \ pos, fp);\n        pos = 0;\n    }\n    void write_single(const char& val) {\n\
    \        if (pos == SIZE) flush();\n        line[pos++] = val;\n    }\n    template\
    \ <class T, enable_if_t<is_same<T, string>::value, int> = 0>\n    void write_single(const\
    \ T& val) {\n        for (char c : val) write_single(c);\n    }\n    template\
    \ <class T, enable_if_t<is_integral<T>::value, int> = 0>\n    void write_single(T\
    \ val) {\n        if (pos > (1 << 15) - 50) flush();\n        if (val == 0) {\n\
    \            write_single('0');\n            return;\n        }\n        if (val\
    \ < 0) {\n            write_single('-');\n            val = -val;  // todo min\n\
    \        }\n        size_t len = 0;\n        while (val) {\n            small[len++]\
    \ = char('0' + (val % 10));\n            val /= 10;\n        }\n        reverse(small,\
    \ small + len);\n        memcpy(line + pos, small, len);\n        pos += len;\n\
    \    }\n    template <class T> void write_single(const V<T>& val) {\n        auto\
    \ n = val.size();\n        for (size_t i = 0; i < n; i++) {\n            if (i)\
    \ write_single(' ');\n            write_single(val[i]);\n        }\n    }\n};\n\
    \n#pragma endregion\n\nusing namespace lib;\nusing mint = MintNTT;\n\nint32_t\
    \ main(){\n    Scanner sc(stdin);\n    Printer pr(stdout);\n\n    int n, m;\n\
    \    sc.read(n, m);\n\n    V<mint> a(n);\n    for (int i = 0; i < n; i++) {\n\
    \        int x;\n        sc.read(x);\n        a[i] = x;\n    }\n    V<mint> b(m);\n\
    \    for (int i = 0; i < m; i++) {\n        int x;\n        sc.read(x);\n    \
    \    b[i] = x;\n    }\n    auto c = FHTMultiplication()(a, b);\n    for (auto\
    \ x: c) {\n        pr.write((int)x);\n        pr.write(' ');\n    }\n    pr.writeln();\n\
    \    return 0;\n}\n"
  dependsOn:
  - bits/stdc++.h
  - ModularInteger.cpp
  - NumberTheory.cpp
  - FHT.cpp
  - BitTricks.cpp
  - NTT.cpp
  - DFT.cpp
  - VectorN.cpp
  - Traits.cpp
  - polynomial/Transform.cpp
  isVerificationFile: true
  path: tests/yosupo/fht-convolution.test.cpp
  requiredBy: []
  timestamp: '2022-12-14 09:29:18-03:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/yosupo/fht-convolution.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/fht-convolution.test.cpp
- /verify/tests/yosupo/fht-convolution.test.cpp.html
title: tests/yosupo/fht-convolution.test.cpp
---
