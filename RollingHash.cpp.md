---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ModularInteger.cpp
    title: ModularInteger.cpp
  - icon: ':question:'
    path: NumberTheory.cpp
    title: NumberTheory.cpp
  - icon: ':warning:'
    path: Random.cpp
    title: Random.cpp
  - icon: ':question:'
    path: Traits.cpp
    title: Traits.cpp
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
  bundledCode: "#line 1 \"RollingHash.cpp\"\n\n\n#line 1 \"ModularInteger.cpp\"\n\n\
    \n#line 1 \"NumberTheory.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace lib\
    \ {\nusing namespace std;\nnamespace nt {\nint64_t inverse(int64_t a, int64_t\
    \ b) {\n  long long b0 = b, t, q;\n  long long x0 = 0, x1 = 1;\n  if (b == 1)\n\
    \    return 1;\n  while (a > 1) {\n    q = a / b;\n    t = b, b = a % b, a = t;\n\
    \    t = x0, x0 = x1 - q * x0, x1 = t;\n  }\n  if (x1 < 0)\n    x1 += b0;\n  return\
    \ x1;\n}\ntemplate<typename T, typename U>\nT powmod (T a, U b, U p) {\n    int\
    \ res = 1;\n    while (b)\n        if (b & 1)\n            res = (int) (res *\
    \ 1ll * a % p),  --b;\n        else\n            a = (int) (a * 1ll * a % p),\
    \  b >>= 1;\n    return res;\n}\ntemplate<typename T>\nvector<T> factors(T n)\
    \ {\n  vector<T> f;\n  for(T i = 2; i*i <= n; i++) {\n    if(n % i == 0) f.push_back(i);\n\
    \    while(n % i == 0) n /= i;\n  }\n  if(n > 1) f.push_back(n);\n  return f;\n\
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
    using MintNTT = Mint32<998244353>;\n} // namespace lib\n\n\n#line 1 \"Random.cpp\"\
    \n\n\n#line 4 \"Random.cpp\"\n\nnamespace lib {\nusing namespace std;\nnamespace\
    \ rng {\nstruct Generator {\n  mt19937 rng;\n  Generator() {\n    seed_seq seq\
    \ {\n      (uint64_t) chrono::duration_cast<chrono::nanoseconds>(\n          chrono::high_resolution_clock::now().time_since_epoch())\n\
    \          .count(),\n#if __cplusplus > 201300\n          (uint64_t)make_unique<char>().get(),\n\
    #else\n          (uint64_t)unique_ptr<char>(new char).get(),\n#endif\n       \
    \   (uint64_t)__builtin_ia32_rdtsc()\n    };\n    rng = mt19937(seq);\n  }\n \
    \ Generator(seed_seq &seq) : rng(seq) {}\n\n  template <typename T,\n        \
    \    typename enable_if<is_integral<T>::value>::type * = nullptr>\n  inline T\
    \ uniform_int(T L, T R) {\n    return uniform_int_distribution<T>(L, R)(rng);\n\
    \  }\n\n  template <typename T> inline T uniform_int(T N) {\n    return uniform_int(T(),\
    \ N - 1);\n  }\n\n  template <typename T> inline T uniform_real(T N) {\n    return\
    \ uniform_real(0.0, static_cast<double>(N));\n  }\n\n  template <typename T> inline\
    \ T uniform_real(T L, T R) {\n    return uniform_real_distribution<double>(static_cast<double>(L),\n\
    \                                             static_cast<double>(R))(rng);\n\
    \  }\n\n  inline double uniform_real() { return uniform_real(0.0, 1.0); }\n};\n\
    \nstatic Generator gen = Generator();\n} // namespace rng\nstatic rng::Generator\
    \ &rng_gen = rng::gen;\n} // namespace lib\n\n\n#line 1 \"Traits.cpp\"\n\n\n#line\
    \ 4 \"Traits.cpp\"\n\nnamespace lib {\nusing namespace std;\nnamespace traits\
    \ {\n\ntemplate <typename...> struct make_void { using type = void; };\n\ntemplate\
    \ <typename... T> using void_t = typename make_void<T...>::type;\n\n/// keep caide\n\
    template <typename Iterator>\nusing IteratorCategory = typename iterator_traits<Iterator>::iterator_category;\n\
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
    } // namespace traits\n} // namespace lib\n\n\n#line 7 \"RollingHash.cpp\"\n\n\
    namespace lib {\nusing namespace std;\nnamespace hashing {\nnamespace {\nusing\
    \ traits::HasBidirectionalIterator;\nusing traits::HasInputIterator;\nusing traits::IsBidirectionalIterator;\n\
    using traits::IsInputIterator;\nusing traits::IsRandomIterator;\n} // namespace\n\
    \nconst static int DEFAULT_MAX_POWERS = 1e6 + 5;\nconst static int GOOD_MOD1 =\
    \ (int)1e9 + 7;\nconst static int GOOD_MOD2 = (int)1e9 + 9;\n\ntemplate <typename\
    \ T, T... Mods> struct BaseProvider {\n  typedef BaseProvider<T, Mods...> type;\n\
    \  typedef ModularInteger<T, Mods...> mint_type;\n\n  mint_type b;\n  vector<mint_type>\
    \ powers;\n  int max_powers = 0;\n\n  BaseProvider(T bases[sizeof...(Mods)]) :\
    \ powers(1, 1) {\n    b = mint_type::with_remainders(bases);\n  }\n  BaseProvider()\
    \ : powers(1, 1) {\n    T bases[sizeof...(Mods)];\n    for (size_t i = 0; i <\
    \ sizeof...(Mods); i++)\n      bases[i] = rng::gen.uniform_int(mint_type::mods[i]);\n\
    \    b = mint_type::with_remainders(bases);\n  }\n\n  void set_max_powers(int\
    \ x) { max_powers = x; }\n\n  inline operator mint_type() const { return b; }\n\
    \  inline T operator()(int i) { return b[i]; }\n\n  void ensure(int p) const {\n\
    \    type *self = const_cast<type *>(this);\n    int cur = powers.size();\n  \
    \  if (p > cur)\n      self->powers.resize(max(2 * cur, p));\n    else\n     \
    \ return;\n    int nsz = powers.size();\n    for (int i = cur; i < nsz; i++)\n\
    \      self->powers[i] = powers[i - 1] * b;\n  }\n\n  mint_type power(int p) const\
    \ {\n    if (p >= max_powers)\n      return b ^ p;\n    ensure(p + 1);\n    return\
    \ powers[p];\n  }\n  T power(int p, int i) const { return power(p)[i]; }\n};\n\
    \ntemplate <typename T, T... Mods> struct RollingHash {\n  typedef RollingHash<T,\
    \ Mods...> type;\n  typedef ModularInteger<T, Mods...> mint_type;\n  typedef BaseProvider<T,\
    \ Mods...> base_type;\n\n  vector<mint_type> hs;\n\n  struct Hash {\n    mint_type\
    \ x;\n    int n;\n\n    struct Less {\n      typename mint_type::less mint_less;\n\
    \      bool operator()(const Hash &lhs, const Hash &rhs) const {\n        if (lhs.n\
    \ == rhs.n)\n          return mint_less(lhs.x, rhs.x);\n        return lhs.n <\
    \ rhs.n;\n      }\n    };\n    typedef Less less;\n\n    Hash() : n(0) {}\n  \
    \  explicit Hash(mint_type y) : x(y), n(1) {}\n    Hash(mint_type y, int n) :\
    \ x(y), n(n) { assert(n >= 0); }\n\n    explicit operator mint_type() const {\
    \ return x; }\n\n    friend bool operator==(const Hash &lhs, const Hash &rhs)\
    \ {\n      return tie(lhs.n, lhs.x) == tie(rhs.n, rhs.x);\n    }\n    friend bool\
    \ operator!=(const Hash &lhs, const Hash &rhs) {\n      return !(lhs == rhs);\n\
    \    }\n    friend ostream &operator<<(ostream &output, const Hash &var) {\n \
    \     return output << var.x << \"{\" << var.n << \"}\";\n    }\n  };\n\n  struct\
    \ Cat {\n    shared_ptr<base_type> base;\n    Cat(const shared_ptr<base_type>\
    \ &base) : base(base) {}\n\n    template <\n        typename Iterator,\n     \
    \   typename enable_if<IsInputIterator<Iterator>::value>::type * = nullptr>\n\
    \    Hash operator()(Iterator begin, Iterator end) {\n      Hash res;\n      for\
    \ (auto it = begin; it != end; ++it) {\n        res.n += it->n;\n        res.x\
    \ *= base->power(it->n);\n        res.x += it->x;\n      }\n      return res;\n\
    \    }\n\n    Hash operator()(const initializer_list<Hash> &hashes) {\n      return\
    \ (*this)(hashes.begin(), hashes.end());\n    }\n\n    template <class... Args>\
    \ Hash operator()(Args... args) {\n      return (*this)({args...});\n    }\n\n\
    \    template <class... Args>\n    pair<Hash, Hash> cat(const pair<Args, Args>\
    \ &... args) {\n      initializer_list<Hash> fwd_list = {args.first...};\n   \
    \   initializer_list<Hash> bwd_list = {args.second...};\n      return {cat(fwd_list.begin(),\
    \ fwd_list.end()),\n              cat(bwd_list.rbegin(), bwd_list.rend())};\n\
    \    }\n  };\n\n  Cat cat;\n\n  RollingHash(const shared_ptr<base_type> &base)\
    \ : hs(1), cat(base) {}\n\n  template <\n      typename Container,\n      typename\
    \ enable_if<HasInputIterator<Container>::value>::type * = nullptr>\n  RollingHash(const\
    \ Container &container, const shared_ptr<base_type> &base)\n      : hs(1), cat(base)\
    \ {\n    (*this) += container;\n  }\n\n  template <\n      typename Iterator,\n\
    \      typename enable_if<IsInputIterator<Iterator>::value>::type * = nullptr>\n\
    \  RollingHash(Iterator begin, Iterator end, const shared_ptr<base_type> &base)\n\
    \      : hs(1), cat(base) {\n    append(begin, end);\n  }\n\n  inline int size()\
    \ const { return (int)hs.size() - 1; }\n\n  template <\n      typename Iterator,\n\
    \      typename enable_if<IsRandomIterator<Iterator>::value>::type * = nullptr>\n\
    \  void append(Iterator begin, Iterator end) {\n    int i = hs.size();\n    hs.resize(hs.size()\
    \ + distance(begin, end));\n    for (auto it = begin; it != end; ++it, ++i)\n\
    \      hs[i] = hs[i - 1] * (*cat.base) + mint_type(*it);\n  }\n\n  template <\n\
    \      typename Iterator,\n      typename enable_if<!IsRandomIterator<Iterator>::value>::type\
    \ * = nullptr>\n  void append(Iterator begin, Iterator end) {\n    for (auto it\
    \ = begin; it != end; ++it)\n      (*this) += *it;\n  }\n\n  template <typename\
    \ U> void append(U rhs) { (*this) += rhs; }\n\n  template <typename U,\n     \
    \       typename enable_if<is_integral<U>::value>::type * = nullptr>\n  RollingHash\
    \ &operator+=(U rhs) {\n    hs.push_back(mint_type(rhs) + hs.back() * (*cat.base));\n\
    \    return *this;\n  }\n\n  template <\n      typename Container,\n      typename\
    \ enable_if<HasInputIterator<Container>::value>::type * = nullptr>\n  RollingHash\
    \ &operator+=(const Container &rhs) {\n    append(rhs.begin(), rhs.end());\n \
    \   return *this;\n  }\n\n  inline void pop() {\n    assert(size() > 0);\n   \
    \ hs.pop_back();\n  }\n\n  Hash prefix(int n) const {\n    n = min(n, size());\n\
    \    return Hash(hs[n], n);\n  }\n\n  Hash operator()(int i, int j) const {\n\
    \    return Hash(hs[j + 1] - hs[i] * (cat.base->power(j - i + 1)), j - i + 1);\n\
    \  }\n\n  Hash suffix(int n) const {\n    int sz = size();\n    n = min(n, sz);\n\
    \    return (*this)(sz - n, sz - 1);\n  }\n\n  pair<Hash, Hash> border(int n)\
    \ const { return {prefix(n), suffix(n)}; }\n\n  Hash substr(int i) const {\n \
    \   i = min(i, size());\n    return (*this)(i, size() - 1);\n  }\n\n  Hash substr(int\
    \ i, int j) const { return (*this)(i, j); }\n\n  Hash all() const { return Hash(hs.back(),\
    \ size()); }\n\n  friend int lcp(const type &lhs, const type &rhs) {\n    int\
    \ l = 0, r = min(lhs.size(), rhs.size());\n    while (l < r) {\n      int mid\
    \ = (l + r) / 2;\n      if (lhs.hs[mid + 1] != rhs.hs[mid + 1])\n        r = mid;\n\
    \      else\n        l = mid + 1;\n    }\n    return l;\n  }\n\n  friend bool\
    \ operator<(const type &lhs, const type &rhs) {\n    int l = lcp(lhs, rhs);\n\
    \    if (l == min(lhs.size(), rhs.size()))\n      return lhs.size() < rhs.size();\n\
    \    return lhs(l, l) < rhs(l, l);\n  }\n};\n\ntemplate <typename T, T... Mods>\
    \ struct BidirectionalRollingHash {\n  typedef RollingHash<T, Mods...> type;\n\
    \  using Hash = typename type::Hash;\n  using base_type = typename type::base_type;\n\
    \  using Cat = typename type::Cat;\n\n  type fwd, bwd;\n  typename type::Cat cat;\n\
    \n  template <typename Container,\n            typename enable_if<HasBidirectionalIterator<Container>::value>::type\n\
    \                * = nullptr>\n  BidirectionalRollingHash(const Container &container,\n\
    \                           const shared_ptr<base_type> &base)\n      : BidirectionalRollingHash<T,\
    \ Mods...>(container.begin(), container.end(),\n                             \
    \                base) {}\n\n  template <typename Iterator,\n            typename\
    \ enable_if<IsBidirectionalIterator<Iterator>::value>::type\n                *\
    \ = nullptr>\n  BidirectionalRollingHash(Iterator begin, Iterator end,\n     \
    \                      const shared_ptr<base_type> &base)\n      : fwd(begin,\
    \ end, base),\n        bwd(make_reverse_iterator(end), make_reverse_iterator(begin),\
    \ base),\n        cat(base) {}\n\n  inline Hash forward(int i, int j) const {\
    \ return fwd(i, j); }\n\n  inline Hash backward(int i, int j) const {\n    int\
    \ n = fwd.size();\n    return bwd(n - j - 1, n - i - 1);\n  }\n\n  inline pair<Hash,\
    \ Hash> operator()(int i, int j) const {\n    return {forward(i, j), backward(i,\
    \ j)};\n  }\n};\n\ntemplate <typename R> struct HashProvider {\n  typedef R Roll;\n\
    \  typedef typename R::base_type base_type;\n  typedef typename R::Hash Hash;\n\
    \n  typename R::Cat cat;\n  HashProvider() : cat(make_shared<base_type>()) {}\n\
    \  explicit HashProvider(base_type base) : cat(make_shared<base_type>(base)) {}\n\
    \n  template <class... Args> R operator()(Args... args) {\n    return R(args...,\
    \ cat.base);\n  }\n};\n\ntemplate <typename R> struct PowerHashProvider : HashProvider<R>\
    \ {\n  using typename HashProvider<R>::base_type;\n  using HashProvider<R>::cat;\n\
    \n  PowerHashProvider() : PowerHashProvider<R>(base_type()) {}\n  PowerHashProvider(base_type\
    \ base) : HashProvider<R>(base) {\n    cat.base->set_max_powers(DEFAULT_MAX_POWERS);\n\
    \  }\n};\n\ntemplate <int32_t... Mods> using Roll32 = RollingHash<int32_t, Mods...>;\n\
    \ntemplate <int64_t... Mods> using Roll64 = RollingHash<int64_t, Mods...>;\n\n\
    template <int32_t... Mods>\nusing Biroll32 = BidirectionalRollingHash<int32_t,\
    \ Mods...>;\n\ntemplate <int64_t... Mods>\nusing Biroll64 = BidirectionalRollingHash<int64_t,\
    \ Mods...>;\n\nusing DefaultProvider = PowerHashProvider<Roll32<GOOD_MOD1, GOOD_MOD2>>;\n\
    using BiDefaultProvider = PowerHashProvider<Biroll32<GOOD_MOD1, GOOD_MOD2>>;\n\
    } // namespace hashing\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_ROLLING_HASH\n#define _LIB_ROLLING_HASH\n#include \"ModularInteger.cpp\"\
    \n#include \"Random.cpp\"\n#include \"Traits.cpp\"\n#include <bits/stdc++.h>\n\
    \nnamespace lib {\nusing namespace std;\nnamespace hashing {\nnamespace {\nusing\
    \ traits::HasBidirectionalIterator;\nusing traits::HasInputIterator;\nusing traits::IsBidirectionalIterator;\n\
    using traits::IsInputIterator;\nusing traits::IsRandomIterator;\n} // namespace\n\
    \nconst static int DEFAULT_MAX_POWERS = 1e6 + 5;\nconst static int GOOD_MOD1 =\
    \ (int)1e9 + 7;\nconst static int GOOD_MOD2 = (int)1e9 + 9;\n\ntemplate <typename\
    \ T, T... Mods> struct BaseProvider {\n  typedef BaseProvider<T, Mods...> type;\n\
    \  typedef ModularInteger<T, Mods...> mint_type;\n\n  mint_type b;\n  vector<mint_type>\
    \ powers;\n  int max_powers = 0;\n\n  BaseProvider(T bases[sizeof...(Mods)]) :\
    \ powers(1, 1) {\n    b = mint_type::with_remainders(bases);\n  }\n  BaseProvider()\
    \ : powers(1, 1) {\n    T bases[sizeof...(Mods)];\n    for (size_t i = 0; i <\
    \ sizeof...(Mods); i++)\n      bases[i] = rng::gen.uniform_int(mint_type::mods[i]);\n\
    \    b = mint_type::with_remainders(bases);\n  }\n\n  void set_max_powers(int\
    \ x) { max_powers = x; }\n\n  inline operator mint_type() const { return b; }\n\
    \  inline T operator()(int i) { return b[i]; }\n\n  void ensure(int p) const {\n\
    \    type *self = const_cast<type *>(this);\n    int cur = powers.size();\n  \
    \  if (p > cur)\n      self->powers.resize(max(2 * cur, p));\n    else\n     \
    \ return;\n    int nsz = powers.size();\n    for (int i = cur; i < nsz; i++)\n\
    \      self->powers[i] = powers[i - 1] * b;\n  }\n\n  mint_type power(int p) const\
    \ {\n    if (p >= max_powers)\n      return b ^ p;\n    ensure(p + 1);\n    return\
    \ powers[p];\n  }\n  T power(int p, int i) const { return power(p)[i]; }\n};\n\
    \ntemplate <typename T, T... Mods> struct RollingHash {\n  typedef RollingHash<T,\
    \ Mods...> type;\n  typedef ModularInteger<T, Mods...> mint_type;\n  typedef BaseProvider<T,\
    \ Mods...> base_type;\n\n  vector<mint_type> hs;\n\n  struct Hash {\n    mint_type\
    \ x;\n    int n;\n\n    struct Less {\n      typename mint_type::less mint_less;\n\
    \      bool operator()(const Hash &lhs, const Hash &rhs) const {\n        if (lhs.n\
    \ == rhs.n)\n          return mint_less(lhs.x, rhs.x);\n        return lhs.n <\
    \ rhs.n;\n      }\n    };\n    typedef Less less;\n\n    Hash() : n(0) {}\n  \
    \  explicit Hash(mint_type y) : x(y), n(1) {}\n    Hash(mint_type y, int n) :\
    \ x(y), n(n) { assert(n >= 0); }\n\n    explicit operator mint_type() const {\
    \ return x; }\n\n    friend bool operator==(const Hash &lhs, const Hash &rhs)\
    \ {\n      return tie(lhs.n, lhs.x) == tie(rhs.n, rhs.x);\n    }\n    friend bool\
    \ operator!=(const Hash &lhs, const Hash &rhs) {\n      return !(lhs == rhs);\n\
    \    }\n    friend ostream &operator<<(ostream &output, const Hash &var) {\n \
    \     return output << var.x << \"{\" << var.n << \"}\";\n    }\n  };\n\n  struct\
    \ Cat {\n    shared_ptr<base_type> base;\n    Cat(const shared_ptr<base_type>\
    \ &base) : base(base) {}\n\n    template <\n        typename Iterator,\n     \
    \   typename enable_if<IsInputIterator<Iterator>::value>::type * = nullptr>\n\
    \    Hash operator()(Iterator begin, Iterator end) {\n      Hash res;\n      for\
    \ (auto it = begin; it != end; ++it) {\n        res.n += it->n;\n        res.x\
    \ *= base->power(it->n);\n        res.x += it->x;\n      }\n      return res;\n\
    \    }\n\n    Hash operator()(const initializer_list<Hash> &hashes) {\n      return\
    \ (*this)(hashes.begin(), hashes.end());\n    }\n\n    template <class... Args>\
    \ Hash operator()(Args... args) {\n      return (*this)({args...});\n    }\n\n\
    \    template <class... Args>\n    pair<Hash, Hash> cat(const pair<Args, Args>\
    \ &... args) {\n      initializer_list<Hash> fwd_list = {args.first...};\n   \
    \   initializer_list<Hash> bwd_list = {args.second...};\n      return {cat(fwd_list.begin(),\
    \ fwd_list.end()),\n              cat(bwd_list.rbegin(), bwd_list.rend())};\n\
    \    }\n  };\n\n  Cat cat;\n\n  RollingHash(const shared_ptr<base_type> &base)\
    \ : hs(1), cat(base) {}\n\n  template <\n      typename Container,\n      typename\
    \ enable_if<HasInputIterator<Container>::value>::type * = nullptr>\n  RollingHash(const\
    \ Container &container, const shared_ptr<base_type> &base)\n      : hs(1), cat(base)\
    \ {\n    (*this) += container;\n  }\n\n  template <\n      typename Iterator,\n\
    \      typename enable_if<IsInputIterator<Iterator>::value>::type * = nullptr>\n\
    \  RollingHash(Iterator begin, Iterator end, const shared_ptr<base_type> &base)\n\
    \      : hs(1), cat(base) {\n    append(begin, end);\n  }\n\n  inline int size()\
    \ const { return (int)hs.size() - 1; }\n\n  template <\n      typename Iterator,\n\
    \      typename enable_if<IsRandomIterator<Iterator>::value>::type * = nullptr>\n\
    \  void append(Iterator begin, Iterator end) {\n    int i = hs.size();\n    hs.resize(hs.size()\
    \ + distance(begin, end));\n    for (auto it = begin; it != end; ++it, ++i)\n\
    \      hs[i] = hs[i - 1] * (*cat.base) + mint_type(*it);\n  }\n\n  template <\n\
    \      typename Iterator,\n      typename enable_if<!IsRandomIterator<Iterator>::value>::type\
    \ * = nullptr>\n  void append(Iterator begin, Iterator end) {\n    for (auto it\
    \ = begin; it != end; ++it)\n      (*this) += *it;\n  }\n\n  template <typename\
    \ U> void append(U rhs) { (*this) += rhs; }\n\n  template <typename U,\n     \
    \       typename enable_if<is_integral<U>::value>::type * = nullptr>\n  RollingHash\
    \ &operator+=(U rhs) {\n    hs.push_back(mint_type(rhs) + hs.back() * (*cat.base));\n\
    \    return *this;\n  }\n\n  template <\n      typename Container,\n      typename\
    \ enable_if<HasInputIterator<Container>::value>::type * = nullptr>\n  RollingHash\
    \ &operator+=(const Container &rhs) {\n    append(rhs.begin(), rhs.end());\n \
    \   return *this;\n  }\n\n  inline void pop() {\n    assert(size() > 0);\n   \
    \ hs.pop_back();\n  }\n\n  Hash prefix(int n) const {\n    n = min(n, size());\n\
    \    return Hash(hs[n], n);\n  }\n\n  Hash operator()(int i, int j) const {\n\
    \    return Hash(hs[j + 1] - hs[i] * (cat.base->power(j - i + 1)), j - i + 1);\n\
    \  }\n\n  Hash suffix(int n) const {\n    int sz = size();\n    n = min(n, sz);\n\
    \    return (*this)(sz - n, sz - 1);\n  }\n\n  pair<Hash, Hash> border(int n)\
    \ const { return {prefix(n), suffix(n)}; }\n\n  Hash substr(int i) const {\n \
    \   i = min(i, size());\n    return (*this)(i, size() - 1);\n  }\n\n  Hash substr(int\
    \ i, int j) const { return (*this)(i, j); }\n\n  Hash all() const { return Hash(hs.back(),\
    \ size()); }\n\n  friend int lcp(const type &lhs, const type &rhs) {\n    int\
    \ l = 0, r = min(lhs.size(), rhs.size());\n    while (l < r) {\n      int mid\
    \ = (l + r) / 2;\n      if (lhs.hs[mid + 1] != rhs.hs[mid + 1])\n        r = mid;\n\
    \      else\n        l = mid + 1;\n    }\n    return l;\n  }\n\n  friend bool\
    \ operator<(const type &lhs, const type &rhs) {\n    int l = lcp(lhs, rhs);\n\
    \    if (l == min(lhs.size(), rhs.size()))\n      return lhs.size() < rhs.size();\n\
    \    return lhs(l, l) < rhs(l, l);\n  }\n};\n\ntemplate <typename T, T... Mods>\
    \ struct BidirectionalRollingHash {\n  typedef RollingHash<T, Mods...> type;\n\
    \  using Hash = typename type::Hash;\n  using base_type = typename type::base_type;\n\
    \  using Cat = typename type::Cat;\n\n  type fwd, bwd;\n  typename type::Cat cat;\n\
    \n  template <typename Container,\n            typename enable_if<HasBidirectionalIterator<Container>::value>::type\n\
    \                * = nullptr>\n  BidirectionalRollingHash(const Container &container,\n\
    \                           const shared_ptr<base_type> &base)\n      : BidirectionalRollingHash<T,\
    \ Mods...>(container.begin(), container.end(),\n                             \
    \                base) {}\n\n  template <typename Iterator,\n            typename\
    \ enable_if<IsBidirectionalIterator<Iterator>::value>::type\n                *\
    \ = nullptr>\n  BidirectionalRollingHash(Iterator begin, Iterator end,\n     \
    \                      const shared_ptr<base_type> &base)\n      : fwd(begin,\
    \ end, base),\n        bwd(make_reverse_iterator(end), make_reverse_iterator(begin),\
    \ base),\n        cat(base) {}\n\n  inline Hash forward(int i, int j) const {\
    \ return fwd(i, j); }\n\n  inline Hash backward(int i, int j) const {\n    int\
    \ n = fwd.size();\n    return bwd(n - j - 1, n - i - 1);\n  }\n\n  inline pair<Hash,\
    \ Hash> operator()(int i, int j) const {\n    return {forward(i, j), backward(i,\
    \ j)};\n  }\n};\n\ntemplate <typename R> struct HashProvider {\n  typedef R Roll;\n\
    \  typedef typename R::base_type base_type;\n  typedef typename R::Hash Hash;\n\
    \n  typename R::Cat cat;\n  HashProvider() : cat(make_shared<base_type>()) {}\n\
    \  explicit HashProvider(base_type base) : cat(make_shared<base_type>(base)) {}\n\
    \n  template <class... Args> R operator()(Args... args) {\n    return R(args...,\
    \ cat.base);\n  }\n};\n\ntemplate <typename R> struct PowerHashProvider : HashProvider<R>\
    \ {\n  using typename HashProvider<R>::base_type;\n  using HashProvider<R>::cat;\n\
    \n  PowerHashProvider() : PowerHashProvider<R>(base_type()) {}\n  PowerHashProvider(base_type\
    \ base) : HashProvider<R>(base) {\n    cat.base->set_max_powers(DEFAULT_MAX_POWERS);\n\
    \  }\n};\n\ntemplate <int32_t... Mods> using Roll32 = RollingHash<int32_t, Mods...>;\n\
    \ntemplate <int64_t... Mods> using Roll64 = RollingHash<int64_t, Mods...>;\n\n\
    template <int32_t... Mods>\nusing Biroll32 = BidirectionalRollingHash<int32_t,\
    \ Mods...>;\n\ntemplate <int64_t... Mods>\nusing Biroll64 = BidirectionalRollingHash<int64_t,\
    \ Mods...>;\n\nusing DefaultProvider = PowerHashProvider<Roll32<GOOD_MOD1, GOOD_MOD2>>;\n\
    using BiDefaultProvider = PowerHashProvider<Biroll32<GOOD_MOD1, GOOD_MOD2>>;\n\
    } // namespace hashing\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - ModularInteger.cpp
  - NumberTheory.cpp
  - bits/stdc++.h
  - Random.cpp
  - Traits.cpp
  isVerificationFile: false
  path: RollingHash.cpp
  requiredBy: []
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: RollingHash.cpp
layout: document
redirect_from:
- /library/RollingHash.cpp
- /library/RollingHash.cpp.html
title: RollingHash.cpp
---
