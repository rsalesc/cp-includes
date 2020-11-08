#ifndef _LIB_FFT
#define _LIB_FFT
#include "DFT.cpp"
#include "Complex.cpp"
#include "geometry/Trigonometry.cpp"
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace linalg {

template<typename T>
struct ComplexRootProvider {
  typedef Complex<T> cd;
  typedef Complex<long double> cld;
  static vector<cd> w;
  static vector<cld> wl;

  static Complex<long double> root(long double ang) {
    return Complex<long double>(geo::trig::cos(ang), geo::trig::sin(ang));
  }

  void operator()(int n) {
    n = max(n, 2);
    int k = max((int)w.size(), 2);
    if ((int)w.size() < n)
      w.resize(n), wl.resize(n);
    else
      return;
    w[0] = w[1] = cd(1.0, 0.0);
    wl[0] = wl[1] = cld(1.0, 0.0);
    for (; k < n; k *= 2) {
      long double ang = 2.0l * geo::trig::PI / (2*k);
      cld step = root(ang);
      for(int i = k; i < 2*k; i++)
        w[i] = wl[i] = (i&1) ? wl[i/2] * step : wl[i/2];
    }
  }
  cd operator[](int i) {
    return w[i];
  }
};

template<typename T>
vector<Complex<T>> ComplexRootProvider<T>::w = vector<Complex<T>>();
template<typename T>
vector<Complex<long double>> ComplexRootProvider<T>::wl = vector<Complex<long double>>();

template<typename T = double>
struct FFT : public DFT<Complex<T>, ComplexRootProvider<T>> {
  using Parent = DFT<Complex<T>, ComplexRootProvider<T>>;
  using Parent::fa;

  template <typename U>
  static void _convolve(const vector<U> &a, const vector<U> &b) {
    typedef Complex<T> cd;
    int n = Parent::ensure(a.size(), b.size());
    for (size_t i = 0; i < (size_t)n; i++)
      fa[i] = cd(i < a.size() ? (T)a[i] : T(),
                 i < b.size() ? (T)b[i] : T());
    Parent::dft(n);
    for (int i = 0; i < n; i++)
      fa[i] *= fa[i];
    Parent::idft(n);
    for (int i = 0; i < n; i++)
      fa[i] = cd(fa[i].imag() / 2, T());
  }

  template<typename U>
  static vector<U> convolve(const vector<U>& a, const vector<U>& b) {
    int sz = (int)a.size() + b.size() - 1;
    _convolve(a, b);
    return retrieve<Parent, U>(sz);
  }

  template<typename U>
  static vector<U> convolve_rounded(const vector<U>& a, const vector<U>& b) {
    int sz = (int)a.size() + b.size() - 1;
    _convolve(a, b);
    vector<U> res(sz);
    for(int i = 0; i < sz; i++) res[i] = (U)(long long)(fa[i].real() + 0.5);
    return res;
  }

  // TODO: use separate static buffers for this function
  template <typename M>
  static vector<M> convolve_mod(const vector<M> &a, const vector<M> &b) {
    typedef typename M::type_int type_int;
    typedef typename M::large_int large_int;
    typedef Complex<T> cd;
    typedef vector<cd> vcd;

    static_assert(sizeof(M::mods) / sizeof(type_int) == 1,
                  "cant multiply with multiple mods");
    type_int base = sqrtl(M::mods[0]) + 0.5;
    M base_m = base;
    int sza = a.size();
    int szb = b.size();
    int n = 1;
    while (n <= sza + szb - 2)
      n *= 2;
    Parent::dft_rev(n);

    vector<M> res(n);

    // establish buffers
    vcd fa(n), fb(n), C1(n), C2(n);

    for (int i = 0; i < n; i++)
      fa[i] = i < sza ? cd((type_int)a[i] / base, (type_int)a[i] % base) : cd();
    for (int i = 0; i < n; i++)
      fb[i] = i < szb ? cd((type_int)b[i] / base, (type_int)b[i] % base) : cd();
    Parent::dft(fa, n);
    Parent::dft(fb, n);

    for (int i = 0; i < n; i++) {
      int j = i ? n - i : 0;
      cd a1 = (fa[i] + fa[j].conj()) * cd(0.5, 0.0);
      cd a2 = (fa[i] - fa[j].conj()) * cd(0.0, -0.5);
      cd b1 = (fb[i] + fb[j].conj()) * cd(0.5, 0.0);
      cd b2 = (fb[i] - fb[j].conj()) * cd(0.0, -0.5);
      cd c11 = a1 * b1, c12 = a1 * b2;
      cd c21 = a2 * b1, c22 = a2 * b2;
      C1[j] = c11 + c12 * cd(0.0, 1.0);
      C2[j] = c21 + c22 * cd(0.0, 1.0);
    }
    Parent::idft(C1, n), Parent::idft(C2, n);
    for (int i = 0; i < n; i++) {
      int j = i ? n - i : 0;
      M x = large_int(C1[j].real() + 0.5);
      M y1 = large_int(C1[j].imag() + 0.5);
      M y2 = large_int(C2[j].real() + 0.5);
      M z = large_int(C2[j].imag() + 0.5);
      res[i] = x * base_m * base_m + (y1 + y2) * base_m + z;
    }

    return res;
  }
};
} // namespace linalg

namespace math {
struct FastMultiplication {
  template <typename Field, typename U = double>
  vector<Field> operator()(const vector<Field> &a,
                           const vector<Field> &b) const {
    return linalg::FFT<U>::convolve_rounded(a, b);
  }
};

struct FFTMultiplication {
  template <typename Field, typename U = double>
  vector<Field> operator()(const vector<Field> &a,
                           const vector<Field> &b) const {
    return linalg::FFT<U>::convolve(a, b);
  }
};

struct SafeMultiplication {
  template <typename Field, typename U = double>
  vector<Field> operator()(const vector<Field> &a,
                           const vector<Field> &b) const {
    return linalg::FFT<U>::convolve_mod(a, b);
  };
};
} // namespace math
} // namespace lib

#endif
