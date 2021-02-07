---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: BitTricks.cpp
    title: BitTricks.cpp
  - icon: ':warning:'
    path: DFT.cpp
    title: DFT.cpp
  - icon: ':warning:'
    path: NTT.cpp
    title: NTT.cpp
  - icon: ':warning:'
    path: NumberTheory.cpp
    title: NumberTheory.cpp
  - icon: ':warning:'
    path: Traits.cpp
    title: Traits.cpp
  - icon: ':warning:'
    path: VectorN.cpp
    title: VectorN.cpp
  - icon: ':warning:'
    path: polynomial/Transform.cpp
    title: polynomial/Transform.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tests/yosupo/convolution.cpp
    title: tests/yosupo/convolution.cpp
  - icon: ':warning:'
    path: tests/yosupo/fps_power.cpp
    title: tests/yosupo/fps_power.cpp
  - icon: ':warning:'
    path: tests/yosupo/kth_term_lr.cpp
    title: tests/yosupo/kth_term_lr.cpp
  - icon: ':warning:'
    path: tests/yosupo/lr.cpp
    title: tests/yosupo/lr.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"FHT.cpp\"\n\n\n#include <bits/stdc++.h>\n#line 1 \"BitTricks.cpp\"\
    \n\n\n#line 4 \"BitTricks.cpp\"\n\nnamespace lib {\nlong long next_power_of_two(long\
    \ long n) {\n  return 1LL << (sizeof(long long) * 8 - 1 - __builtin_clzll(n) +\n\
    \                 ((n & (n - 1LL)) != 0));\n}\n} // namespace lib\n\n\n#line 1\
    \ \"NTT.cpp\"\n\n\n#line 1 \"DFT.cpp\"\n\n\n#line 5 \"DFT.cpp\"\n\nnamespace lib\
    \ {\nusing namespace std;\nnamespace linalg {\ntemplate <typename Ring, typename\
    \ Provider>\nstruct DFT {\n  static vector<int> rev;\n  static vector<Ring> fa;\n\
    \n  // function used to precompute rev for fixed size fft (n is a power of two)\n\
    \  static void dft_rev(int n) {\n    Provider()(n);\n    int lbn = __builtin_ctz(n);\n\
    \    if ((int)rev.size() < (1 << lbn))\n      rev.resize(1 << lbn);\n    int h\
    \ = -1;\n    for (int i = 1; i < n; i++) {\n      if ((i & (i - 1)) == 0)\n  \
    \      h++;\n      rev[i] = rev[i ^ (1 << h)] | (1 << (lbn - h - 1));\n    }\n\
    \  }\n\n  static void dft_iter(Ring *p, int n) {\n    Provider w;\n    for (int\
    \ L = 2; L <= n; L <<= 1) {\n      for (int i = 0; i < n; i += L) {\n        for\
    \ (int j = 0; j < L / 2; j++) {\n          Ring z = p[i + j + L / 2] * w[j + L\
    \ / 2];\n          p[i + j + L / 2] = p[i + j] - z;\n          p[i + j] += z;\n\
    \        }\n      }\n    }\n  }\n\n  static void swap(vector<Ring> &buf) { std::swap(fa,\
    \ buf); }\n  static void _dft(Ring *p, int n) {\n    dft_rev(n);\n    for (int\
    \ i = 0; i < n; i++)\n      if (i < rev[i])\n        std::swap(p[i], p[rev[i]]);\n\
    \    dft_iter(p, n);\n  }\n  static void _idft(Ring *p, int n) {\n    _dft(p,\
    \ n);\n    reverse(p + 1, p + n);\n    Ring inv = Provider().inverse(n);\n   \
    \ for (int i = 0; i < n; i++)\n      p[i] *= inv;\n  }\n\n  static void dft(int\
    \ n) { _dft(fa.data(), n); }\n\n  static void idft(int n) { _idft(fa.data(), n);\
    \ }\n\n  static void dft(vector<Ring> &v, int n) {\n    swap(v);\n    dft(n);\n\
    \    swap(v);\n  }\n  static void idft(vector<Ring> &v, int n) {\n    swap(v);\n\
    \    idft(n);\n    swap(v);\n  }\n\n  static int ensure(int a, int b = 0) {\n\
    \    int n = a+b;\n    n = next_power_of_two(n);\n    if ((int)fa.size() < n)\n\
    \      fa.resize(n);\n    return n;\n  }\n\n  static void clear(int n) { fill(fa.begin(),\
    \ fa.begin() + n, 0); }\n\n  template<typename Iterator>\n  static void fill(Iterator\
    \ begin, Iterator end) {\n    int n = ensure(distance(begin, end));\n    int i\
    \ = 0;\n    for(auto it = begin; it != end; ++it) {\n      fa[i++] = *it;\n  \
    \  }\n    for(;i < n; i++) fa[i] = Ring();\n  }\n};\n\ntemplate<typename DF, typename\
    \ U>\nstatic vector<U> retrieve(int n) {\n  assert(n <= DF::fa.size());\n  vector<U>\
    \ res(n);\n  for(int i = 0; i < n; i++) res[i] = (U)DF::fa[i];\n  return res;\n\
    }\n\ntemplate<typename Ring, typename Provider>\nvector<int> DFT<Ring, Provider>::rev\
    \ = vector<int>();\n\ntemplate<typename Ring, typename Provider>\nvector<Ring>\
    \ DFT<Ring, Provider>::fa = vector<Ring>();\n}\n} // namespace lib\n\n\n#line\
    \ 1 \"NumberTheory.cpp\"\n\n\n#line 4 \"NumberTheory.cpp\"\n\nnamespace lib {\n\
    using namespace std;\nnamespace nt {\nint64_t inverse(int64_t a, int64_t b) {\n\
    \  long long b0 = b, t, q;\n  long long x0 = 0, x1 = 1;\n  if (b == 1)\n    return\
    \ 1;\n  while (a > 1) {\n    q = a / b;\n    t = b, b = a % b, a = t;\n    t =\
    \ x0, x0 = x1 - q * x0, x1 = t;\n  }\n  if (x1 < 0)\n    x1 += b0;\n  return x1;\n\
    }\ntemplate<typename T, typename U>\nT powmod (T a, U b, U p) {\n    int res =\
    \ 1;\n    while (b)\n        if (b & 1)\n            res = int (res * 1ll * a\
    \ % p),  --b;\n        else\n            a = int (a * 1ll * a % p),  b >>= 1;\n\
    \    return res;\n}\ntemplate<typename T>\nvector<T> factors(T n) {\n  vector<T>\
    \ f;\n  for(T i = 2; i*i <= n; i++) {\n    if(n % i == 0) f.push_back(i);\n  \
    \  while(n % i == 0) n /= i;\n  }\n  if(n > 1) f.push_back(n);\n  return f;\n\
    }\n} // namespace nt\n} // namespace lib\n\n\n#line 1 \"VectorN.cpp\"\n\n\n#line\
    \ 1 \"Traits.cpp\"\n\n\n#line 4 \"Traits.cpp\"\n\nnamespace lib {\nusing namespace\
    \ std;\nnamespace traits {\n\ntemplate <typename...> struct make_void { using\
    \ type = void; };\n\ntemplate <typename... T> using void_t = typename make_void<T...>::type;\n\
    \n/// keep caide\ntemplate <typename Iterator>\nusing IteratorCategory = typename\
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
    \ = TransformMultiplication<linalg::FHT>;\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_FHT\n#define _LIB_FHT\n#include <bits/stdc++.h>\n#include \"\
    BitTricks.cpp\"\n#include \"NTT.cpp\"\n#include \"polynomial/Transform.cpp\"\n\
    \nnamespace lib {\nusing namespace std;\nnamespace linalg {\ntemplate <typename\
    \ Ring>\nstruct FHT {\n  using Provider = MintRootProvider<Ring>;\n  using T =\
    \ Ring;\n  using U = make_unsigned_t<typename Ring::type_int>;\n  using U64 =\
    \ make_unsigned_t<typename Ring::large_int>;\n  static vector<Ring> fa;\n  static\
    \ const int MAX_LG_N = 30;\n  static vector<Ring> g, ig;\n  \n  static void precompute()\
    \ {\n    if(!g.empty()) return;\n    Provider();\n    g.resize(MAX_LG_N);\n  \
    \  ig.resize(MAX_LG_N);\n    for(int i = 0; i < MAX_LG_N; i++) {\n      Ring w\
    \ = Provider::g ^ (((Ring::mod-1) >> (i + 2)) * 3);\n      w = -w;\n      Ring\
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
    \ = TransformMultiplication<linalg::FHT>;\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - BitTricks.cpp
  - NTT.cpp
  - DFT.cpp
  - NumberTheory.cpp
  - VectorN.cpp
  - Traits.cpp
  - polynomial/Transform.cpp
  isVerificationFile: false
  path: FHT.cpp
  requiredBy:
  - tests/yosupo/convolution.cpp
  - tests/yosupo/fps_power.cpp
  - tests/yosupo/kth_term_lr.cpp
  - tests/yosupo/lr.cpp
  timestamp: '2021-01-30 22:33:20-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FHT.cpp
layout: document
redirect_from:
- /library/FHT.cpp
- /library/FHT.cpp.html
title: FHT.cpp
---
