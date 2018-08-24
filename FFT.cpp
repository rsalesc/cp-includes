#ifndef _LIB_FFT
#define _LIB_FFT
#include <bits/stdc++.h>
#include "Complex.cpp"

namespace lib {
  using namespace std;
namespace linalg {
namespace internal {
  typedef long double fft_type;
  typedef Complex<fft_type> cd;
  typedef vector<cd> vcd;

  const fft_type PI = acosl(-1);
  vector<int> rev;
  vcd fa, fb;

  // function used to precompute rev for fixed size fft (n is a power of two)
  void dft_rev(int n) {
    int lbn = __builtin_ctz(n);
    if((int)rev.size() < (1 << lbn)) rev.resize(1 << lbn);
    int h = -1;
    for (int i = 1; i < n; i++) {
      if ((i & (i - 1)) == 0) h++;
      rev[i] = rev[i ^ (1 << h)] | (1 << (lbn - h - 1));
    }
  }

  void dft_iter(cd* p, int n) {
    for (int L = 2; L <= n; L <<= 1) {
      fft_type ang = PI * 2 / L;
      cd step = cd(cosl(ang), sinl(ang)); // root
      // for (int i = L; i < root_sz; i <<= 1) NTT HERE
      //   step = step * step % MOD;
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

  void dft(cd* p, int n) {
    for (int i = 0; i < n; i++)
      if (i < rev[i]) swap(p[i], p[rev[i]]);
    dft_iter(p, n);
  }

  void idft(cd* p, int n) {
    dft(p, n);
    reverse(p+1, p+n);
    for (int i = 0; i < n; i++) p[i] /= n;
  }
}

  template<typename T>
  void raw_fft(const vector<T>& a, const vector<T>& b) {
    int n = max(a.size(), b.size());
    n = 1 << (32 - __builtin_clz(n) + ((n & (n-1)) != 0));
    if((int)internal::fa.size() < n) internal::fa.resize(n);
    if((int)internal::fb.size() < n) internal::fb.resize(n);
    for(size_t i = 0; i < a.size(); i++)
      internal::fa[i] = (internal::fft_type) a[i];
    for(size_t i = 0; i < b.size(); i++)
      internal::fb[i] = (internal::fft_type) b[i];
    fill(internal::fa.begin() + a.size(), internal::fa.end(), 0);
    fill(internal::fb.begin() + b.size(), internal::fb.end(), 0);
    internal::dft_rev(n);
    internal::dft(internal::fa.data(), n);
    internal::dft(internal::fb.data(), n);
    for(int i = 0; i < n; i++) internal::fa[i] *= internal::fb[i];
    internal::idft(internal::fa.data(), n);
  }

  template<typename T>
  internal::vcd fft(const vector<T>& a, const vector<T>& b) {
    raw_fft(a, b);
    internal::vcd& raw = internal::fa;
    int sz = raw.size();
    vector<T> res(sz);
    for(int i = 0; i < sz; i++)
      res[i] = raw[i];
    return res;
  }

  template<typename T>
  vector<T> rounded_fft(const vector<T>& a, const vector<T>& b) {
    raw_fft(a, b);
    internal::vcd& raw = internal::fa;
    int sz = raw.size();
    vector<T> res(sz);
    for(int i = 0; i < sz; i++)
      res[i] = (long long)(raw[i].real() + 0.5);
    return res;
  }

  // TODO: optimize this
  template<typename M>
  vector<M> mod_split_fft(const vector<M>& a, const vector<M>& b) {
    typedef typename M::type_int type_int;
    static_assert(sizeof(M::mods) / sizeof(type_int) == 1, 
        "cant multiply with multiple mods");
    type_int base = sqrtl(M::mods[0]) + 0.5;
    M base_m = base;
    int sza = a.size();
    int szb = b.size();

    vector<M> a0(sza), a1(sza);
    for(int i = 0; i < sza; i++) {
      a0[i] = (type_int)a[i] % base;
      a1[i] = (type_int)a[i] / base;
    }

    vector<M> b0(szb), b1(szb);
    for(int i = 0; i < szb; i++) {
      b0[i] = (type_int)b[i] % base;
      b1[i] = (type_int)b[i] / base;
    }

    vector<M> a01 = a0, b01 = b0;
    for(int i = 0; i < sza; i++) a01[i] += a1[i];
    for(int i = 0; i < szb; i++) b01[i] += b1[i];
    vector<M> C = rounded_fft(a01, b01);
    vector<M> a0b0 = rounded_fft(a0, b0);
    vector<M> a1b1 = rounded_fft(a1, b1);

    vector<M> mid = C;
    int sz = C.size();
    for(int i = 0; i < sz; i++) {
      mid[i] -= a0b0[i];
      mid[i] -= a1b1[i];
    }

    vector<M> res = a0b0;
    for(int i = 0; i < sz; i++)
      res[i] += base_m * mid[i];
    base_m *= base_m;
    for(int i = 0; i < sz; i++)
      res[i] += base_m * a1b1[i];
    return res;
  }
}  // namespace linalg
}  // namespace lib

#endif
