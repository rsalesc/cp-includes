---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Epsilon.cpp
    title: Epsilon.cpp
  - icon: ':question:'
    path: LongMultiplication.cpp
    title: LongMultiplication.cpp
  - icon: ':question:'
    path: Math.cpp
    title: Math.cpp
  - icon: ':question:'
    path: ModularInteger.cpp
    title: ModularInteger.cpp
  - icon: ':question:'
    path: NumberTheory.cpp
    title: NumberTheory.cpp
  - icon: ':question:'
    path: PolynomialRing.cpp
    title: PolynomialRing.cpp
  - icon: ':question:'
    path: Traits.cpp
    title: Traits.cpp
  - icon: ':question:'
    path: VectorN.cpp
    title: VectorN.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/find-lr.test.cpp
    title: tests/yosupo/find-lr.test.cpp
  - icon: ':x:'
    path: tests/yosupo/kth-term-lr.test.cpp
    title: tests/yosupo/kth-term-lr.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"LinearRecurrence.cpp\"\n\n\n#line 1 \"PolynomialRing.cpp\"\
    \n\n\n#line 1 \"Epsilon.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace lib {\n\
    using namespace std;\n\ntemplate <typename T = double> struct Epsilon {\n  T eps;\n\
    \  constexpr Epsilon(T eps = 1e-9) : eps(eps) {}\n\n  template <typename G,\n\
    \            typename enable_if<is_floating_point<G>::value>::type * = nullptr>\n\
    \  int operator()(G a, G b = 0) const {\n    return a + eps < b ? -1 : (b + eps\
    \ < a ? 1 : 0);\n  }\n\n  template <typename G,\n            typename enable_if<!is_floating_point<G>::value>::type\
    \ * = nullptr>\n  int operator()(G a, G b = 0) const {\n    return a < b ? -1\
    \ : (a > b ? 1 : 0);\n  }\n\n  template <typename G,\n            typename enable_if<is_floating_point<G>::value>::type\
    \ * = nullptr>\n  bool null(G a) const {\n    return (*this)(a) == 0;\n  }\n\n\
    \  template <typename G,\n            typename enable_if<!is_floating_point<G>::value>::type\
    \ * = nullptr>\n  bool null(G a) const {\n    return a == 0;\n  }\n};\n} // namespace\
    \ lib\n\n\n#line 1 \"Math.cpp\"\n\n\n#line 4 \"Math.cpp\"\n\nnamespace lib {\n\
    using namespace std;\nnamespace math {\n\n/// caide keep\ntemplate <typename Type>\
    \ struct DefaultPowerOp {\n  Type operator()() const { return Type(1); }\n  Type\
    \ operator()(const Type &a) const { return a; }\n  void operator()(Type &x, const\
    \ Type &a, long long cur) const {\n    x *= x;\n    if (cur & 1)\n      x *= a;\n\
    \  }\n};\n\ntemplate <typename Type, typename Op>\nType generic_power(const Type\
    \ &a, long long n, Op op) {\n  if (n == 0)\n    return op();\n  Type res = op(a);\n\
    \  int hi = 63 - __builtin_clzll(n);\n  for (int i = hi - 1; ~i; i--) {\n    op(res,\
    \ a, n >> i);\n  }\n  return res;\n}\n\ntemplate <typename Type> Type generic_power(const\
    \ Type &a, long long n) {\n  return generic_power(a, n, DefaultPowerOp<Type>());\n\
    }\n} // namespace math\n} // namespace lib\n\n\n#line 1 \"ModularInteger.cpp\"\
    \n\n\n#line 1 \"NumberTheory.cpp\"\n\n\n#line 4 \"NumberTheory.cpp\"\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace nt {\nint64_t inverse(int64_t a, int64_t\
    \ b) {\n  long long b0 = b, t, q;\n  long long x0 = 0, x1 = 1;\n  if (b == 1)\n\
    \    return 1;\n  while (a > 1) {\n    q = a / b;\n    t = b, b = a % b, a = t;\n\
    \    t = x0, x0 = x1 - q * x0, x1 = t;\n  }\n  if (x1 < 0)\n    x1 += b0;\n  return\
    \ x1;\n}\ntemplate<typename T, typename U>\nT powmod (T a, U b, U p) {\n    int\
    \ res = 1;\n    while (b)\n        if (b & 1)\n            res = int (res * 1ll\
    \ * a % p),  --b;\n        else\n            a = int (a * 1ll * a % p),  b >>=\
    \ 1;\n    return res;\n}\ntemplate<typename T>\nvector<T> factors(T n) {\n  vector<T>\
    \ f;\n  for(T i = 2; i*i <= n; i++) {\n    if(n % i == 0) f.push_back(i);\n  \
    \  while(n % i == 0) n /= i;\n  }\n  if(n > 1) f.push_back(n);\n  return f;\n\
    }\n} // namespace nt\n} // namespace lib\n\n\n#line 5 \"ModularInteger.cpp\"\n\
    \n#if __cplusplus < 201300\n#error required(c++14)\n#endif\n\nnamespace lib {\n\
    using namespace std;\nnamespace {\ntemplate <typename T, T... Mods> struct ModularIntegerBase\
    \ {\n  typedef ModularIntegerBase<T, Mods...> type;\n\n  T x[sizeof...(Mods)];\n\
    \  friend ostream &operator<<(ostream &output, const type &var) {\n    output\
    \ << \"(\";\n    for (int i = 0; i < sizeof...(Mods); i++) {\n      if (i)\n \
    \       output << \", \";\n      output << var.x[i];\n    }\n    return output\
    \ << \")\";\n  }\n};\n\ntemplate <typename T, T Mod> struct ModularIntegerBase<T,\
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
    using MintNTT = Mint32<998244353>;\n} // namespace lib\n\n\n#line 1 \"Traits.cpp\"\
    \n\n\n#line 4 \"Traits.cpp\"\n\nnamespace lib {\nusing namespace std;\nnamespace\
    \ traits {\n\ntemplate <typename...> struct make_void { using type = void; };\n\
    \ntemplate <typename... T> using void_t = typename make_void<T...>::type;\n\n\
    /// keep caide\ntemplate <typename Iterator>\nusing IteratorCategory = typename\
    \ iterator_traits<Iterator>::iterator_category;\n\n/// keep caide\ntemplate <typename\
    \ Container>\nusing IteratorCategoryOf = IteratorCategory<typename Container::iterator>;\n\
    \n/// keep caide\ntemplate <typename Iterator>\nusing IteratorValue = typename\
    \ iterator_traits<Iterator>::value_type;\n\n/// keep caide\ntemplate <typename\
    \ Container>\nusing IteratorValueOf = IteratorValue<typename Container::iterator>;\n\
    \n/// keep caide\ntemplate <typename Iterator>\nusing IsRandomIterator =\n   \
    \ is_base_of<random_access_iterator_tag, IteratorCategory<Iterator>>;\n\n/// keep\
    \ caide\ntemplate <typename Iterator>\nusing IsInputIterator =\n    is_base_of<input_iterator_tag,\
    \ IteratorCategory<Iterator>>;\n\n/// keep caide\ntemplate <typename Iterator>\n\
    using IsBidirectionalIterator =\n    is_base_of<bidirectional_iterator_tag, IteratorCategory<Iterator>>;\n\
    \n/// keep caide\ntemplate <typename Container>\nusing HasRandomIterator =\n \
    \   is_base_of<random_access_iterator_tag, IteratorCategoryOf<Container>>;\n\n\
    /// keep caide\ntemplate <typename Container>\nusing HasInputIterator =\n    is_base_of<input_iterator_tag,\
    \ IteratorCategoryOf<Container>>;\n\n/// keep caide\ntemplate <typename Container>\n\
    using HasBidirectionalIterator =\n    is_base_of<bidirectional_iterator_tag, IteratorCategoryOf<Container>>;\n\
    } // namespace traits\n} // namespace lib\n\n\n#line 1 \"LongMultiplication.cpp\"\
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
    \ 1 \"VectorN.cpp\"\n\n\n#line 5 \"VectorN.cpp\"\n\n#define VEC_CONST_OP(op, typ)\
    \ \\\n  type operator op(const typ rhs) const { \\\n    auto res = *this; \\\n\
    \    return res op##= rhs; \\\n  }\n\n#define VEC_BIN_OP(op) \\\n  type& operator\
    \ op##=(const type& rhs) { \\\n    if(rhs.size() > this->size()) \\\n      this->resize(rhs.size());\
    \ \\\n    int sz = this->size(); \\\n    for(int i = 0; i < (int)rhs.size(); i++)\
    \ \\\n      (*this)[i] op##= rhs[i]; \\\n    for(int i = rhs.size(); i < sz; i++)\
    \ \\\n      (*this)[i] op##= 0; \\\n    return *this; \\\n  } \\\n  VEC_CONST_OP(op,\
    \ type)\n\n#define VEC_SINGLE_OP(op, typ) \\\n  type& operator op##=(const typ\
    \ rhs) { \\\n    for(auto& x : *this) \\\n      x op##= rhs; \\\n    return *this;\
    \ \\\n  } \\\n  VEC_CONST_OP(op, typ)\n  \n\nnamespace lib {\nusing namespace\
    \ std;\ntemplate<typename T>\nstruct VectorN : vector<T> {\n  using type = VectorN<T>;\n\
    \n  template <\n      typename Container,\n      typename enable_if<traits::HasInputIterator<Container>::value>::type\
    \ * = nullptr>\n  VectorN(const Container &container)\n      : vector<T>(container.begin(),\
    \ container.end()) {}\n\n  VectorN(const initializer_list<T> &v)\n      : vector<T>(v.begin(),\
    \ v.end()) {}\n\n  template<typename... Args>\n  VectorN( Args&&... args ) \n\
    \      : vector<T>(std::forward<Args>(args)...) {}\n\n  VEC_BIN_OP(+)\n  VEC_BIN_OP(-)\n\
    \  VEC_BIN_OP(*)\n\n  VEC_SINGLE_OP(+, T&)\n  VEC_SINGLE_OP(-, T&)\n  VEC_SINGLE_OP(*,\
    \ T&)\n  VEC_SINGLE_OP(/, T&)\n  VEC_SINGLE_OP(^, int64_t)\n\n  type operator-()\
    \ const {\n    auto res = *this;\n    for(auto& x : res) x = -x;\n    return res;\n\
    \  }\n\n  type operator%(int n) const {\n    // TODO: get rid of this\n    //\
    \ return *const_cast<type*>(this);\n    return *this;\n  }\n};\n} // namespace\
    \ lib\n\n\n#line 10 \"PolynomialRing.cpp\"\n\nnamespace lib {\nusing namespace\
    \ std;\nnamespace math {\nnamespace poly {\n\nnamespace {\n/// keep caide\nusing\
    \ traits::IsInputIterator;\n/// keep caide\nusing traits::HasInputIterator;\n\
    } // namespace\n\nnamespace detail {\n  template<class>\n  struct sfinae_true\
    \ : std::true_type{};\n\n  template<class T, class Field, class Func>\n  static\
    \ auto test_transform(int)\n      -> sfinae_true<decltype(\n    std::declval<T>().template\
    \ on_transform<Field>(std::declval<int>(), std::declval<Func&>()))>;\n\n  template<class,\
    \ class Field, class Func>\n  static auto test_transform(long) -> std::false_type;\n\
    } // detail::\n\ntemplate<class T, class Field, class Func = std::function<VectorN<Field>(int)>>\n\
    struct has_transform : decltype(detail::test_transform<T, Field, Func>(0)){};\n\
    \ntemplate <typename P> struct DefaultPowerOp {\n  int mod;\n  DefaultPowerOp(int\
    \ mod) : mod(mod) {}\n  P operator()() const { return P(1); }\n  P operator()(const\
    \ P &a) const { return a % mod; }\n  void operator()(P &x, const P &a, long long\
    \ cur) const {\n    (x *= x) %= mod;\n    if (cur & 1)\n      (x *= a) %= mod;\n\
    \  }\n};\n\ntemplate <typename P> struct ModPowerOp {\n  const P &mod;\n  ModPowerOp(const\
    \ P &p) : mod(p) {}\n  P operator()() const { return P(1); }\n  P operator()(const\
    \ P &a) { return a % mod; }\n  void operator()(P &x, const P &a, long long cur)\
    \ const {\n    (x *= x) %= mod;\n    if (cur & 1)\n      (x *= a) %= mod;\n  }\n\
    };\n\ntemplate <typename P> struct ModShiftPowerOp {\n  const P &mod;\n  ModShiftPowerOp(const\
    \ P &p) : mod(p) {}\n  P operator()() const { return P(1); }\n  P operator()(const\
    \ P &a) { return a % mod; }\n  void operator()(P &x, const P &a, long long cur)\
    \ const {\n    // if(cur < mod.degree())\n    // x = P::kth(cur);\n    if (cur\
    \ & 1)\n      (x *= (x << 1)) %= mod;\n    else\n      (x *= x) %= mod;\n  }\n\
    };\n\nstruct DefaultDivmod;\nstruct NaiveDivmod;\n\ntemplate <typename Field,\
    \ typename Mult, typename Divmod = DefaultDivmod>\nstruct Polynomial {\n  constexpr\
    \ static int Magic = 64;\n  constexpr static bool NaiveMod = is_same<Divmod, NaiveDivmod>::value;\n\
    \  constexpr static bool HasTransform = has_transform<Mult, Field>::value;\n \
    \ using Transform =  typename Mult::template Transform<Field>;\n\n  typedef Polynomial<Field,\
    \ Mult, Divmod> type;\n  typedef Field field;\n  vector<Field> p;\n\n  Polynomial()\
    \ : p(0) {}\n  explicit Polynomial(Field x) : p(1, x) {}\n\n  template <\n   \
    \   typename Iterator,\n      typename enable_if<IsInputIterator<Iterator>::value>::type\
    \ * = nullptr>\n  Polynomial(Iterator begin, Iterator end) : p(distance(begin,\
    \ end)) {\n    int i = 0;\n    for (auto it = begin; it != end; ++it, ++i)\n \
    \     p[i] = *it;\n    normalize();\n  }\n\n  template <\n      typename Container,\n\
    \      typename enable_if<HasInputIterator<Container>::value>::type * = nullptr>\n\
    \  Polynomial(const Container &container)\n      : Polynomial(container.begin(),\
    \ container.end()) {}\n\n  Polynomial(const initializer_list<Field> &v)\n    \
    \  : Polynomial(v.begin(), v.end()) {}\n\n  static type from_root(const Field\
    \ &root) { return Polynomial({-root, 1}); }\n\n  void normalize() const {\n  \
    \  type *self = const_cast<type *>(this);\n    int sz = self->p.size();\n    while\
    \ (sz > 0 && Epsilon<>().null(self->p[sz - 1]))\n      sz--;\n    if (sz != (int)self->p.size())\n\
    \      self->p.resize(sz);\n  }\n\n  inline int size() const { return p.size();\
    \ }\n  inline int degree() const { return max((int)p.size() - 1, 0); }\n  bool\
    \ null() const {\n    for (Field x : p)\n      if (!Epsilon<>().null(x))\n   \
    \     return false;\n    return true;\n  }\n\n  const vector<Field>& data() const\
    \ {\n    return p;\n  }\n\n  Field eval(Field x) const {\n    Field pw = 1;\n\
    \    Field res = 0;\n    for(Field c : p) {\n      res += pw * c;\n      pw *=\
    \ x;\n    }\n    return res;\n  }\n\n  inline Field operator[](const int i) const\
    \ {\n    if (i >= size())\n      return 0;\n    return p[i];\n  }\n  inline Field\
    \ &operator[](const int i) {\n    if (i >= size())\n      p.resize(i + 1);\n \
    \   return p[i];\n  }\n\n  Field operator()(const Field &x) const {\n    if (null())\n\
    \      return Field();\n    Field acc = p.back();\n    for (int i = (int)size()\
    \ - 2; i >= 0; i--) {\n      acc *= x;\n      acc += p[i];\n    }\n    return\
    \ acc;\n  }\n\n  type substr(int i, int sz) const {\n    int j = min(sz + i, size());\n\
    \    i = min(i, size());\n    if(i >= j) return type();\n    return type(begin(p)+i,\
    \ begin(p)+j);\n  }\n\n  type &operator+=(const type &rhs) {\n    if (rhs.size()\
    \ > size())\n      p.resize(rhs.size());\n    int sz = size();\n    for (int i\
    \ = 0; i < sz; i++)\n      p[i] += rhs[i];\n    normalize();\n    return *this;\n\
    \  }\n\n  type &operator-=(const type &rhs) {\n    if (rhs.size() > size())\n\
    \      p.resize(rhs.size());\n    int sz = size();\n    for (int i = 0; i < sz;\
    \ i++)\n      p[i] -= rhs[i];\n    normalize();\n    return *this;\n  }\n\n  static\
    \ vector<Field> multiply(const vector<Field>& a, const vector<Field>& b) {\n \
    \   if(min(a.size(), b.size()) < Magic)\n      return NaiveMultiplication()(a,\
    \ b);\n    return Mult()(a, b);\n  }\n\n  type &operator*=(const type &rhs) {\n\
    \    p = multiply(p, rhs.p);\n    normalize();\n    return *this;\n  }\n\n  type\
    \ &operator*=(const Field &rhs) {\n    int sz = size();\n    for (int i = 0; i\
    \ < sz; i++)\n      p[i] *= rhs;\n    normalize();\n    return *this;\n  }\n\n\
    \  type &operator/=(const Field &rhs) {\n    int sz = size();\n    for (int i\
    \ = 0; i < sz; i++)\n      p[i] /= rhs;\n    normalize();\n    return *this;\n\
    \  }\n\n  type &operator<<=(const int rhs) {\n    if (rhs < 0)\n      return *this\
    \ >>= rhs;\n    if (rhs == 0)\n      return *this;\n    int sz = size();\n   \
    \ p.resize(sz + rhs);\n    for (int i = sz - 1; i >= 0; i--)\n      p[i + rhs]\
    \ = p[i];\n    fill_n(p.begin(), rhs, 0);\n    return *this;\n  }\n\n  type &operator>>=(const\
    \ int rhs) {\n    if (rhs < 0)\n      return *this <<= rhs;\n    if (rhs == 0)\n\
    \      return *this;\n    int sz = size();\n    if (rhs >= sz) {\n      p.clear();\n\
    \      return *this;\n    }\n    for (int i = rhs; i < sz; i++)\n      p[i - rhs]\
    \ = p[i];\n    p.resize(sz - rhs);\n    return *this;\n  }\n\n  type &operator%=(const\
    \ int rhs) {\n    if (rhs < size())\n      p.resize(rhs);\n    normalize();\n\
    \    return *this;\n  }\n\n  type &operator/=(const type &rhs) { return *this\
    \ = *this / rhs; }\n\n  type operator%=(const type &rhs) { return *this = *this\
    \ % rhs; }\n\n  type operator+(const type &rhs) const {\n    type res = *this;\n\
    \    return res += rhs;\n  }\n\n  type operator-(const type &rhs) const {\n  \
    \  type res = *this;\n    return res -= rhs;\n  }\n\n  type operator*(const type\
    \ &rhs) const { return type(multiply(p, rhs.p)); }\n\n  type operator*(const Field\
    \ &rhs) const {\n    type res = *this;\n    return res *= rhs;\n  }\n\n  type\
    \ operator/(const Field &rhs) const {\n    type res = *this;\n    return res /=\
    \ rhs;\n  }\n\n  type operator<<(const int rhs) const {\n    type res = *this;\n\
    \    return res <<= rhs;\n  }\n\n  type operator>>(const int rhs) const {\n  \
    \  type res = *this;\n    return res >>= rhs;\n  }\n\n  type operator%(const int\
    \ rhs) const {\n    return Polynomial(p.begin(), p.begin() + min(rhs, size()));\n\
    \  }\n\n  type operator/(const type &rhs) const {\n    return type::divmod(*this,\
    \ rhs).first;\n  }\n\n  type operator%(const type &rhs) const {\n    return type::divmod(*this,\
    \ rhs).second;\n  }\n\n  bool operator==(const type &rhs) const {\n    normalize();\n\
    \    rhs.normalize();\n    return p == rhs.p;\n  }\n\n  template <// Used in SFINAE.\n\
    \            typename U = Field,\n            enable_if_t<has_transform<Mult,\
    \ U>::value>* = nullptr>\n  inline VectorN<U> transform(int n) {\n    return Mult().template\
    \ transform<U>(n, p);\n  }\n\n  template <// Used in SFINAE.\n            typename\
    \ U = Field,\n            enable_if_t<has_transform<Mult, U>::value>* = nullptr>\n\
    \  inline static type itransform(int n, const vector<U>& v) {\n    return Mult().template\
    \ itransform<U>(n, v);\n  }\n\n  template <typename Functor,\n            // Used\
    \ in SFINAE.\n            typename U = Field,\n            enable_if_t<has_transform<Mult,\
    \ U>::value>* = nullptr,\n            typename ...Ts>\n  inline static type on_transform(\n\
    \    int n,\n    Functor f,        \n    const Ts&... vs) {\n    if(n < Magic)\n\
    \      return f(n, vs...);\n    return Mult().template on_transform<U>(n, f, vs.p...);\n\
    \  }\n\n  template <typename Functor,\n            // Used in SFINAE.\n      \
    \      typename U = Field,\n            enable_if_t<!has_transform<Mult, U>::value>*\
    \ = nullptr,\n            typename ...Ts>\n  inline static type on_transform(\n\
    \    int n,\n    Functor f,        \n    const Ts&... vs) {\n    return f(n, vs...);\n\
    \  }\n\n  template <\n    // Used in SFINAE.\n    typename U = Field,\n    enable_if_t<has_transform<Mult,\
    \ U>::value>* = nullptr>\n  type inverse(int m) const {\n    if(null()) return\
    \ *this;\n    type r = {Field(1) / p[0]};\n    r.p.reserve(m);\n    for(int i\
    \ = 1; i < m; i *= 2) {\n      int n = 2 * i;\n      vector<U> f = (*this % n).p;\
    \ f.resize(n);\n      vector<U> g = r.p; g.resize(n);\n      Transform::dft(f,\
    \ n);\n      Transform::dft(g, n);\n      for(int j = 0; j < n; j++) f[j] *= g[j];\n\
    \      Transform::idft(f, n);\n      for(int j = 0; j < i; j++) f[j] = 0;\n  \
    \    Transform::dft(f, n);\n      for(int j = 0; j < n; j++) f[j] *= g[j];\n \
    \     Transform::idft(f, n);\n      for(int j = i; j < min(n, m); j++)\n     \
    \   r[j] = -f[j];\n    }\n    return r;\n  }\n\n  type inverse_slow(int m) const\
    \ {\n    if(null()) return *this;\n    type b = {Field(1) / p[0]};\n    b.p.reserve(2\
    \ * m);\n    for(int i = 1; i < m; i *= 2) {\n      int n = min(2 * i, m);\n \
    \     auto bb = b * b % n;\n      b += b;\n      b -= *this % n * bb;\n      b\
    \ %= n;\n    }\n    return b % m;\n  }\n\n  template <\n    // Used in SFINAE.\n\
    \    typename U = Field,\n    enable_if_t<!has_transform<Mult, U>::value>* = nullptr>\n\
    \  type inverse(int m) const {\n    return inverse_slow(m);\n  }\n\n  type inverse()\
    \ const {\n    return inverse(size());\n  }\n\n  type reciprocal() const {\n \
    \   normalize();\n    return type(p.rbegin(), p.rend());\n  }\n\n  type integral()\
    \ const {\n    int sz = size();\n    if (sz == 0)\n      return {};\n    type\
    \ res = *this;\n    for (int i = sz; i; i--) {\n      res[i] = res[i - 1] / i;\n\
    \    }\n    res[0] = 0;\n    res.normalize();\n    return res;\n  }\n\n  type\
    \ derivative() const {\n    int sz = size();\n    if (sz == 0)\n      return {};\n\
    \    type res = *this;\n    for (int i = 0; i + 1 < sz; i++) {\n      res[i] =\
    \ res[i + 1] * (i + 1);\n    }\n    res.p.back() = 0;\n    res.normalize();\n\
    \    return res;\n  }\n\n  type mulx(field x) const { // component-wise multiplication\
    \ with x^k\n    field cur = 1;\n    type res(*this);\n    for(auto& c : res.p)\n\
    \      c *= cur, cur *= x;\n    return res;\n  }\n  type mulx_sq(field x) const\
    \ { // component-wise multiplication with x^{k^2}\n    field cur = x;\n    field\
    \ total = 1;\n    field xx = x * x;\n    type res(*this);\n    for(auto& c : res.p)\n\
    \      c *= total, total *= cur, cur *= xx;\n    return res;\n  }\n  static pair<type,\
    \ type> divmod(const type &a, const type &b) {\n    if (NaiveMod || min(a.size(),\
    \ b.size()) < Magic)\n      return naive_divmod(a, b);\n    a.normalize();\n \
    \   b.normalize();\n    int m = a.size();\n    int n = b.size();\n    if (m <\
    \ n)\n      return {Polynomial(), a};\n    int sz = m - n + 1;\n    type ar =\
    \ a.reciprocal() % sz;\n    type br = b.reciprocal() % sz;\n    type q = (ar *\
    \ br.inverse(sz) % sz).reciprocal();\n    type r = a - b * q;\n\n    return {q,\
    \ r % (n-1)};\n  }\n\n  static pair<type, type> naive_divmod(const type &a, const\
    \ type &b) {\n    type res = a;\n    int a_deg = a.degree();\n    int b_deg =\
    \ b.degree();\n    Field normalizer = Field(1) / b[b_deg];\n    for (int i = 0;\
    \ i < a_deg - b_deg + 1; i++) {\n      Field coef = (res[a_deg - i] *= normalizer);\n\
    \      if (coef != 0) {\n        for (int j = 1; j <= b_deg; j++) {\n        \
    \  res[a_deg - i - j] += -b[b_deg - j] * coef;\n        }\n      }\n    }\n  \
    \  return {res >> b_deg, res % b_deg};\n  }\n  vector<Field> czt_even(Field z,\
    \ int n) const { // P(1), P(z^2), P(z^4), ..., P(z^2(n-1))\n    int m = degree();\n\
    \    if(null()) {\n      return vector<Field>(n);\n    }\n    vector<Field> vv(m\
    \ + n);\n    Field zi = Field(1) / z;\n    Field zz = zi * zi;\n    Field cur\
    \ = zi;\n    Field total = 1;\n    for(int i = 0; i <= max(n - 1, m); i++) {\n\
    \      if(i <= m) {vv[m - i] = total;}\n      if(i < n) {vv[m + i] = total;}\n\
    \      total *= cur;\n      cur *= zz;\n    }\n    type w = (mulx_sq(z) * vv).substr(m,\
    \ n).mulx_sq(z);\n    vector<Field> res(n);\n    for(int i = 0; i < n; i++) {\n\
    \      res[i] = w[i];\n    }\n    return res;\n  }\n  vector<Field> czt(Field\
    \ z, int n) const {\n    auto even = czt_even(z, (n+1)/2);\n    auto odd = mulx(z).czt_even(z,\
    \ n/2);\n    vector<Field> ans(n);\n    for(int i = 0; i < n/2; i++) {\n     \
    \ ans[2*i] = even[i];\n      ans[2*i+1] = odd[i];\n    }\n    if(n&1) {\n    \
    \  ans.back() = even.back();\n    }\n    return ans;\n  }\n  friend type kmul(const\
    \ vector<type>& polys, int l, int r) {\n    if(l == r) return polys[l];\n    int\
    \ mid = (l+r)/2;\n    return kmul(polys, l, mid) * kmul(polys, mid+1, r);\n  }\n\
    \  friend type kmul(const vector<type>& polys) {\n    if(polys.empty()) return\
    \ type();\n    return kmul(polys, 0, (int)polys.size() - 1);\n  }\n  static type\
    \ power(const type &a, long long n, const int mod) {\n    return math::generic_power<type>(a,\
    \ n, DefaultPowerOp<type>(mod));\n  }\n\n  static type power(const type &a, long\
    \ long n, const type &mod) {\n    return math::generic_power<type>(a, n, ModPowerOp<type>(mod));\n\
    \  }\n\n  static type kth(int K) { return type(1) << K; }\n\n  static type kth(long\
    \ long K, const type &mod) {\n    return math::generic_power<type>(type(1) <<\
    \ 1, K,\n                                     ModShiftPowerOp<type>(mod));\n \
    \ }\n\n  friend ostream &operator<<(ostream &output, const type &var) {\n    output\
    \ << \"[\";\n    int sz = var.size();\n    for (int i = sz - 1; i >= 0; i--) {\n\
    \      output << var[i];\n      if (i)\n        output << \" \";\n    }\n    return\
    \ output << \"]\";\n  }\n};\n} // namespace poly\n/// keep caide\nusing poly::Polynomial;\n\
    } // namespace math\n} // namespace lib\n\n\n#line 6 \"LinearRecurrence.cpp\"\n\
    \nnamespace lib {\nusing namespace std;\nnamespace linalg {\nnamespace {\nusing\
    \ traits::HasRandomIterator;\nusing traits::IsRandomIterator;\n} // namespace\n\
    \ntemplate <typename P> struct BMSolver {\n  typedef BMSolver<P> type;\n  typedef\
    \ typename P::field field_type;\n  typedef P poly_type;\n\n  vector<field_type>\
    \ base;\n  vector<field_type> T;\n\n  template <\n      typename Iterator,\n \
    \     typename enable_if<IsRandomIterator<Iterator>::value>::type * = nullptr>\n\
    \  void solve(Iterator begin, Iterator end) {\n    auto get = [begin](int i) {\
    \ return *(begin + i); };\n\n    int n = distance(begin, end);\n\n    vector<field_type>\
    \ C = {1}, B = {1};\n    field_type b = 1;\n    int L = 0;\n\n    for (int i =\
    \ 0, x = 1; i < n; i++, x++) {\n      // evaluate new element\n      field_type\
    \ d = 0;\n      for (size_t j = 0; j < C.size(); j++)\n        d += get(i - j)\
    \ * C[j];\n      if (d == 0)\n        continue;\n      if (2 * L <= i) {\n   \
    \     auto tmp = C;\n        if (C.size() < B.size() + x)\n          C.resize(B.size()\
    \ + x);\n        field_type coef = d / b;\n        for (size_t j = 0; j < B.size();\
    \ j++)\n          C[j + x] -= coef * B[j];\n        L = i + 1 - L;\n        B\
    \ = tmp;\n        b = d;\n        x = 0;\n      } else {\n        if (C.size()\
    \ < B.size() + x)\n          C.resize(B.size() + x);\n        field_type coef\
    \ = d / b;\n        for (size_t j = 0; j < B.size(); j++)\n          C[j + x]\
    \ -= coef * B[j];\n      }\n    }\n\n    T = vector<field_type>((int)C.size()\
    \ - 1);\n    for (size_t i = 0; i < T.size(); i++)\n      T[i] = -C[i + 1];\n\
    \    base = vector<field_type>(begin, end);\n  }\n\n  template <\n      typename\
    \ Container,\n      typename enable_if<HasRandomIterator<Container>::value>::type\
    \ * = nullptr>\n  void solve(const Container &container) {\n    solve(container.begin(),\
    \ container.end());\n  }\n\n  void solve(const initializer_list<field_type> &l)\
    \ {\n    solve(l.begin(), l.end());\n  }\n\n  bool solved() const { return T.size()\
    \ > 0 && base.size() >= T.size(); }\n\n  void ensure(int nsz) const {\n    auto\
    \ *self = const_cast<type *>(this);\n    for (int j = base.size(); j < nsz; j++)\
    \ {\n      field_type acc = 0;\n      for (int i = 0; i < (int)T.size(); i++)\n\
    \        acc += base[j - i - 1] * T[i];\n      self->base.push_back(acc);\n  \
    \  }\n  }\n\n  poly_type mod_function() const {\n    poly_type res;\n    int m\
    \ = T.size();\n    res[m] = 1;\n    for (int i = 0; i < m; i++)\n      res[i]\
    \ = -T[m - i - 1];\n    return res;\n  }\n\n  vector<field_type> compute(long\
    \ long K, int n) {\n    assert(n > 0);\n    assert(solved());\n    vector<field_type>\
    \ res;\n    int N = T.size();\n    int cons = min(n, N);\n\n    if (K < (int)base.size())\
    \ {\n      for (int j = 0; j < n && K + j < (int)base.size(); j++)\n        res.push_back({base[K\
    \ + j]});\n\n      while ((int)res.size() < cons) {\n        field_type acc =\
    \ 0;\n        int sz = res.size();\n        int mid = min(sz, N);\n        for\
    \ (int i = 0; i < mid; i++)\n          acc += res[sz - i - 1] * T[i];\n      \
    \  sz = base.size();\n        for (int i = mid; i < N; i++)\n          acc +=\
    \ base[sz - 1 - (i - mid)] * T[i];\n        res.push_back(acc);\n      }\n   \
    \ } else {\n      ensure(cons + N - 1);\n\n      poly_type x = poly_type::kth(K,\
    \ mod_function());\n\n      for (int j = 0; j < cons; j++) {\n        field_type\
    \ acc = 0;\n        for (int i = 0; i < N; i++)\n          acc += x[i] * base[i\
    \ + j];\n        res.push_back(acc);\n      }\n    }\n\n    for (int j = res.size();\
    \ j < n; j++) {\n      field_type acc = 0;\n      for (int i = 0; i < N; i++)\n\
    \        acc += res[j - i - 1] * T[i];\n      res.push_back(acc);\n    }\n   \
    \ return res;\n  }\n\n  field_type compute(long long K) { return compute(K, 1)[0];\
    \ }\n};\n\ntemplate<typename Poly>\nstruct LinearRecurrence {\n  typedef LinearRecurrence<Poly>\
    \ type;\n  typedef typename Poly::field field_type;\n  typedef Poly poly_type;\n\
    \n  poly_type P, Q;\n\n  LinearRecurrence(const vector<field_type>& base, vector<field_type>\
    \ T) {\n    assert(base.size() == T.size());\n    assert(T.back() == field_type());\n\
    \    for(auto& x : T) x = -x;\n    T.insert(T.begin(), field_type(1));\n    Q\
    \ = poly_type(T);\n    P = poly_type(base) % T.size() * Q % ((int)T.size() - 1);\n\
    \  }\n\n  template<typename I>\n  field_type compute(I N) {\n    auto P1 = P;\n\
    \    auto Q1 = Q;\n    while(N) {\n      auto Q2 = Q1;\n      for(int i = 1; i\
    \ < Q2.size(); i += 2) Q2[i] = -Q2[i];\n      auto U = P1 * Q2;\n      P1 = poly_type();\n\
    \      for(int i = N % 2, j = 0; j < Q.degree(); j++, i += 2)\n        P1[j] =\
    \ U[i];\n      auto A = Q1 * Q2;\n      Q1 = poly_type();\n      for(int i = 0,\
    \ j = 0; j <= Q.degree(); j++, i += 2)\n        Q1[j] = A[i];\n      N /= 2;\n\
    \      if(N < P.size()) break;\n    }\n    return (P1 * Q1.inverse())[N];\n  }\n\
    };\n} // namespace linalg\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_LINEAR_RECURRENCE\n#define _LIB_LINEAR_RECURRENCE\n#include\
    \ \"PolynomialRing.cpp\"\n#include \"Traits.cpp\"\n#include <bits/stdc++.h>\n\n\
    namespace lib {\nusing namespace std;\nnamespace linalg {\nnamespace {\nusing\
    \ traits::HasRandomIterator;\nusing traits::IsRandomIterator;\n} // namespace\n\
    \ntemplate <typename P> struct BMSolver {\n  typedef BMSolver<P> type;\n  typedef\
    \ typename P::field field_type;\n  typedef P poly_type;\n\n  vector<field_type>\
    \ base;\n  vector<field_type> T;\n\n  template <\n      typename Iterator,\n \
    \     typename enable_if<IsRandomIterator<Iterator>::value>::type * = nullptr>\n\
    \  void solve(Iterator begin, Iterator end) {\n    auto get = [begin](int i) {\
    \ return *(begin + i); };\n\n    int n = distance(begin, end);\n\n    vector<field_type>\
    \ C = {1}, B = {1};\n    field_type b = 1;\n    int L = 0;\n\n    for (int i =\
    \ 0, x = 1; i < n; i++, x++) {\n      // evaluate new element\n      field_type\
    \ d = 0;\n      for (size_t j = 0; j < C.size(); j++)\n        d += get(i - j)\
    \ * C[j];\n      if (d == 0)\n        continue;\n      if (2 * L <= i) {\n   \
    \     auto tmp = C;\n        if (C.size() < B.size() + x)\n          C.resize(B.size()\
    \ + x);\n        field_type coef = d / b;\n        for (size_t j = 0; j < B.size();\
    \ j++)\n          C[j + x] -= coef * B[j];\n        L = i + 1 - L;\n        B\
    \ = tmp;\n        b = d;\n        x = 0;\n      } else {\n        if (C.size()\
    \ < B.size() + x)\n          C.resize(B.size() + x);\n        field_type coef\
    \ = d / b;\n        for (size_t j = 0; j < B.size(); j++)\n          C[j + x]\
    \ -= coef * B[j];\n      }\n    }\n\n    T = vector<field_type>((int)C.size()\
    \ - 1);\n    for (size_t i = 0; i < T.size(); i++)\n      T[i] = -C[i + 1];\n\
    \    base = vector<field_type>(begin, end);\n  }\n\n  template <\n      typename\
    \ Container,\n      typename enable_if<HasRandomIterator<Container>::value>::type\
    \ * = nullptr>\n  void solve(const Container &container) {\n    solve(container.begin(),\
    \ container.end());\n  }\n\n  void solve(const initializer_list<field_type> &l)\
    \ {\n    solve(l.begin(), l.end());\n  }\n\n  bool solved() const { return T.size()\
    \ > 0 && base.size() >= T.size(); }\n\n  void ensure(int nsz) const {\n    auto\
    \ *self = const_cast<type *>(this);\n    for (int j = base.size(); j < nsz; j++)\
    \ {\n      field_type acc = 0;\n      for (int i = 0; i < (int)T.size(); i++)\n\
    \        acc += base[j - i - 1] * T[i];\n      self->base.push_back(acc);\n  \
    \  }\n  }\n\n  poly_type mod_function() const {\n    poly_type res;\n    int m\
    \ = T.size();\n    res[m] = 1;\n    for (int i = 0; i < m; i++)\n      res[i]\
    \ = -T[m - i - 1];\n    return res;\n  }\n\n  vector<field_type> compute(long\
    \ long K, int n) {\n    assert(n > 0);\n    assert(solved());\n    vector<field_type>\
    \ res;\n    int N = T.size();\n    int cons = min(n, N);\n\n    if (K < (int)base.size())\
    \ {\n      for (int j = 0; j < n && K + j < (int)base.size(); j++)\n        res.push_back({base[K\
    \ + j]});\n\n      while ((int)res.size() < cons) {\n        field_type acc =\
    \ 0;\n        int sz = res.size();\n        int mid = min(sz, N);\n        for\
    \ (int i = 0; i < mid; i++)\n          acc += res[sz - i - 1] * T[i];\n      \
    \  sz = base.size();\n        for (int i = mid; i < N; i++)\n          acc +=\
    \ base[sz - 1 - (i - mid)] * T[i];\n        res.push_back(acc);\n      }\n   \
    \ } else {\n      ensure(cons + N - 1);\n\n      poly_type x = poly_type::kth(K,\
    \ mod_function());\n\n      for (int j = 0; j < cons; j++) {\n        field_type\
    \ acc = 0;\n        for (int i = 0; i < N; i++)\n          acc += x[i] * base[i\
    \ + j];\n        res.push_back(acc);\n      }\n    }\n\n    for (int j = res.size();\
    \ j < n; j++) {\n      field_type acc = 0;\n      for (int i = 0; i < N; i++)\n\
    \        acc += res[j - i - 1] * T[i];\n      res.push_back(acc);\n    }\n   \
    \ return res;\n  }\n\n  field_type compute(long long K) { return compute(K, 1)[0];\
    \ }\n};\n\ntemplate<typename Poly>\nstruct LinearRecurrence {\n  typedef LinearRecurrence<Poly>\
    \ type;\n  typedef typename Poly::field field_type;\n  typedef Poly poly_type;\n\
    \n  poly_type P, Q;\n\n  LinearRecurrence(const vector<field_type>& base, vector<field_type>\
    \ T) {\n    assert(base.size() == T.size());\n    assert(T.back() == field_type());\n\
    \    for(auto& x : T) x = -x;\n    T.insert(T.begin(), field_type(1));\n    Q\
    \ = poly_type(T);\n    P = poly_type(base) % T.size() * Q % ((int)T.size() - 1);\n\
    \  }\n\n  template<typename I>\n  field_type compute(I N) {\n    auto P1 = P;\n\
    \    auto Q1 = Q;\n    while(N) {\n      auto Q2 = Q1;\n      for(int i = 1; i\
    \ < Q2.size(); i += 2) Q2[i] = -Q2[i];\n      auto U = P1 * Q2;\n      P1 = poly_type();\n\
    \      for(int i = N % 2, j = 0; j < Q.degree(); j++, i += 2)\n        P1[j] =\
    \ U[i];\n      auto A = Q1 * Q2;\n      Q1 = poly_type();\n      for(int i = 0,\
    \ j = 0; j <= Q.degree(); j++, i += 2)\n        Q1[j] = A[i];\n      N /= 2;\n\
    \      if(N < P.size()) break;\n    }\n    return (P1 * Q1.inverse())[N];\n  }\n\
    };\n} // namespace linalg\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - PolynomialRing.cpp
  - Epsilon.cpp
  - Math.cpp
  - ModularInteger.cpp
  - NumberTheory.cpp
  - Traits.cpp
  - LongMultiplication.cpp
  - VectorN.cpp
  isVerificationFile: false
  path: LinearRecurrence.cpp
  requiredBy: []
  timestamp: '2021-02-06 22:48:25-03:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/yosupo/find-lr.test.cpp
  - tests/yosupo/kth-term-lr.test.cpp
documentation_of: LinearRecurrence.cpp
layout: document
redirect_from:
- /library/LinearRecurrence.cpp
- /library/LinearRecurrence.cpp.html
title: LinearRecurrence.cpp
---
