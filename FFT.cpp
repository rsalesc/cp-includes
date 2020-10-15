#ifndef _LIB_FFT
#define _LIB_FFT
#include "BitTricks.cpp"
#include "Complex.cpp"
#include "geometry/Trigonometry.cpp"
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace linalg {

template <typename fft_type> struct DFT {
  typedef Complex<fft_type> cd;
  typedef vector<cd> vcd;

  static constexpr fft_type PI = geo::trig::PI;

  static vector<int> rev;
  static vcd fa;
  static vcd w;

  static cd root(fft_type ang) {
    return cd(geo::trig::cos(ang), geo::trig::sin(ang));
  }

  // TODO: think how to correctly use this.
  static void dft_roots(int n) {
    if ((int)w.size() < n)
      w.resize(n);
    else
      return;
    w[0] = cd(1.0, 0.0);
    for (int i = 1; i < n; i++)
      w[i] = root(PI * 2.0 / n * i);
  }

  // function used to precompute rev for fixed size fft (n is a power of two)
  static void dft_rev(int n) {
    dft_roots(n);
    int lbn = __builtin_ctz(n);
    if ((int)rev.size() < (1 << lbn))
      rev.resize(1 << lbn);
    int h = -1;
    for (int i = 1; i < n; i++) {
      if ((i & (i - 1)) == 0)
        h++;
      rev[i] = rev[i ^ (1 << h)] | (1 << (lbn - h - 1));
    }
  }

  static void dft_iter(cd *p, int n) {
    for (int L = 2; L <= n; L <<= 1) {
      fft_type ang = PI * 2 / L;
      cd step = root(ang);
      for (int i = 0; i < n; i += L) {
        cd w = 1;
        for (int j = 0; j < L / 2; j++) {
          cd x = p[i + j];
          cd y = p[i + j + L / 2] * w;
          p[i + j] = x + y;
          p[i + j + L / 2] = x - y;
          w *= step;
        }
      }
    }
  }

  static void swap(vcd &buf) { std::swap(fa, buf); }
  static void _dft(cd *p, int n) {
    for (int i = 0; i < n; i++)
      if (i < rev[i])
        std::swap(p[i], p[rev[i]]);
    dft_iter(p, n);
  }
  static void _idft(cd *p, int n) {
    _dft(p, n);
    reverse(p + 1, p + n);
    for (int i = 0; i < n; i++)
      p[i] /= n;
  }

  static void dft(int n) { _dft(fa.data(), n); }

  static void idft(int n) { _idft(fa.data(), n); }

  static void dft(vcd &v, int n) {
    swap(v);
    dft(n);
    swap(v);
  }
  static void idft(vcd &v, int n) {
    swap(v);
    idft(n);
    swap(v);
  }

  static int ensure(int a, int b = 0) {
    int n = max(a, b);
    n = next_power_of_two(n) << 1;
    if ((int)fa.size() < n)
      fa.resize(n);
    return n;
  }

  static void clear(int n) { fill(fa.begin(), fa.begin() + n, 0); }
};

template <typename T, typename U = double>
void raw_fft(const vector<T> &a, const vector<T> &b) {
  int n = DFT<U>::ensure(a.size(), b.size());
  for (size_t i = 0; i < (size_t)n; i++)
    DFT<U>::fa[i] = typename DFT<U>::cd(i < a.size() ? (U)a[i] : U(),
                                        i < b.size() ? (U)b[i] : U());
  DFT<U>::dft_rev(n);
  DFT<U>::dft(n);
  for (int i = 0; i < n; i++)
    DFT<U>::fa[i] *= DFT<U>::fa[i];
  DFT<U>::idft(n);
  for (int i = 0; i < n; i++)
    DFT<U>::fa[i] = typename DFT<U>::cd(DFT<U>::fa[i].imag() / 2, U());
}

template <typename T, typename U = double>
vector<T> fft(const vector<T> &a, const vector<T> &b) {
  raw_fft<T, U>(a, b);
  typename DFT<U>::vcd &raw = DFT<U>::fa;
  int sz = raw.size();
  vector<T> res(sz);
  for (int i = 0; i < sz; i++)
    res[i] = raw[i].real();
  return res;
}

template <typename T, typename U = double>
vector<T> rounded_fft(const vector<T> &a, const vector<T> &b) {
  raw_fft<T, U>(a, b);
  typename DFT<U>::vcd &raw = DFT<U>::fa;
  int sz = raw.size();
  vector<T> res(sz);
  for (int i = 0; i < sz; i++)
    res[i] = (long long)(raw[i].real() + 0.5);
  return res;
}

// TODO: use separate static buffers for this function
template <typename M, typename U = double>
vector<M> mod_split_fft(const vector<M> &a, const vector<M> &b) {
  typedef typename M::type_int type_int;
  typedef typename M::large_int large_int;
  typedef typename DFT<U>::cd cd;
  typedef typename DFT<U>::vcd vcd;

  static_assert(sizeof(M::mods) / sizeof(type_int) == 1,
                "cant multiply with multiple mods");
  type_int base = sqrtl(M::mods[0]) + 0.5;
  M base_m = base;
  int sza = a.size();
  int szb = b.size();
  int n = 1;
  while (n <= sza + szb - 2)
    n *= 2;
  DFT<U>::dft_rev(n);

  vector<M> res(n);

  // establish buffers
  vcd fa(n), fb(n), C1(n), C2(n);

  for (int i = 0; i < n; i++)
    fa[i] = i < sza ? cd((type_int)a[i] / base, (type_int)a[i] % base) : cd();
  for (int i = 0; i < n; i++)
    fb[i] = i < szb ? cd((type_int)b[i] / base, (type_int)b[i] % base) : cd();
  DFT<U>::dft(fa, n);
  DFT<U>::dft(fb, n);

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
  DFT<U>::idft(C1, n), DFT<U>::idft(C2, n);
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

template <> vector<int> DFT<double>::rev = vector<int>();
template <> vector<int> DFT<long double>::rev = vector<int>();
template <> DFT<double>::vcd DFT<double>::fa = typename DFT<double>::vcd();
template <>
DFT<long double>::vcd DFT<long double>::fa = typename DFT<long double>::vcd();
template <> DFT<double>::vcd DFT<double>::w = typename DFT<double>::vcd();
template <>
DFT<long double>::vcd DFT<long double>::w = typename DFT<long double>::vcd();

} // namespace linalg

namespace math {
struct FastMultiplication {
  template <typename Field, typename U = double>
  vector<Field> operator()(const vector<Field> &a,
                           const vector<Field> &b) const {
    return linalg::rounded_fft<Field, U>(a, b);
  }
};

struct FFTMultiplication {
  template <typename Field, typename U = double>
  vector<Field> operator()(const vector<Field> &a,
                           const vector<Field> &b) const {
    return linalg::fft<Field, U>(a, b);
  }
};

struct SafeMultiplication {
  template <typename Field, typename U = double>
  vector<Field> operator()(const vector<Field> &a,
                           const vector<Field> &b) const {
    return linalg::mod_split_fft<Field, U>(a, b);
  };
};
} // namespace math
} // namespace lib

#endif
