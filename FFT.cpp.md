---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: BitTricks.cpp
    title: BitTricks.cpp
  - icon: ':warning:'
    path: Complex.cpp
    title: Complex.cpp
  - icon: ':heavy_check_mark:'
    path: DFT.cpp
    title: DFT.cpp
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
  bundledCode: "#line 1 \"FFT.cpp\"\n\n\n#line 1 \"DFT.cpp\"\n\n\n#include <bits/stdc++.h>\n\
    #line 1 \"BitTricks.cpp\"\n\n\n#line 4 \"BitTricks.cpp\"\n\nnamespace lib {\n\
    long long next_power_of_two(long long n) {\n  return 1LL << (sizeof(long long)\
    \ * 8 - 1 - __builtin_clzll(n) +\n                 ((n & (n - 1LL)) != 0));\n\
    }\n} // namespace lib\n\n\n#line 5 \"DFT.cpp\"\n\nnamespace lib {\nusing namespace\
    \ std;\nnamespace linalg {\ntemplate <typename Ring, typename Provider>\nstruct\
    \ DFT {\n  static vector<int> rev;\n  static vector<Ring> fa;\n\n  // function\
    \ used to precompute rev for fixed size fft (n is a power of two)\n  static void\
    \ dft_rev(int n) {\n    Provider()(n);\n    int lbn = __builtin_ctz(n);\n    if\
    \ ((int)rev.size() < (1 << lbn))\n      rev.resize(1 << lbn);\n    int h = -1;\n\
    \    for (int i = 1; i < n; i++) {\n      if ((i & (i - 1)) == 0)\n        h++;\n\
    \      rev[i] = rev[i ^ (1 << h)] | (1 << (lbn - h - 1));\n    }\n  }\n\n  static\
    \ void dft_iter(Ring *p, int n) {\n    Provider w;\n    for (int L = 2; L <= n;\
    \ L <<= 1) {\n      for (int i = 0; i < n; i += L) {\n        for (int j = 0;\
    \ j < L / 2; j++) {\n          Ring z = p[i + j + L / 2] * w[j + L / 2];\n   \
    \       p[i + j + L / 2] = p[i + j] - z;\n          p[i + j] += z;\n        }\n\
    \      }\n    }\n  }\n\n  static void swap(vector<Ring> &buf) { std::swap(fa,\
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
    \ 1 \"Complex.cpp\"\n\n\n#line 4 \"Complex.cpp\"\n\nnamespace lib {\nusing namespace\
    \ std;\ntemplate <typename T> struct Complex {\n  T re, im;\n  Complex(T a = T(),\
    \ T b = T()) : re(a), im(b) {}\n  T real() const { return re; }\n  T imag() const\
    \ { return im; }\n  explicit operator T() const { return re; }\n  template<typename\
    \ G>\n  operator Complex<G>() const { return Complex<G>(re, im); }\n  Complex\
    \ conj() const { return Complex(re, -im); }\n  void operator+=(const Complex<T>\
    \ &rhs) { re += rhs.re, im += rhs.im; }\n  void operator-=(const Complex<T> &rhs)\
    \ { re -= rhs.re, im -= rhs.im; }\n  void operator*=(const Complex<T> &rhs) {\n\
    \    tie(re, im) =\n        make_pair(re * rhs.re - im * rhs.im, re * rhs.im +\
    \ im * rhs.re);\n  }\n  Complex<T> operator+(const Complex<T> &rhs) {\n    Complex<T>\
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
    \ namespace math\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_FFT\n#define _LIB_FFT\n#include \"DFT.cpp\"\n#include \"Complex.cpp\"\
    \n#include \"geometry/Trigonometry.cpp\"\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace linalg {\n\ntemplate<typename T>\nstruct\
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
    \ namespace math\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - DFT.cpp
  - BitTricks.cpp
  - Complex.cpp
  - geometry/Trigonometry.cpp
  isVerificationFile: false
  path: FFT.cpp
  requiredBy: []
  timestamp: '2021-01-30 22:31:25-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FFT.cpp
layout: document
redirect_from:
- /library/FFT.cpp
- /library/FFT.cpp.html
title: FFT.cpp
---
