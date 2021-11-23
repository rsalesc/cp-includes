#ifndef _LIB_FHT
#define _LIB_FHT
#include <bits/stdc++.h>
#include "BitTricks.cpp"
#include "NTT.cpp"
#include "polynomial/Transform.cpp"

namespace lib {
using namespace std;
namespace linalg {
template <typename Ring>
struct FHT {
  using Provider = MintRootProvider<Ring>;
  using T = Ring;
  using U = make_unsigned_t<typename Ring::type_int>;
  using U64 = make_unsigned_t<typename Ring::large_int>;
  static vector<Ring> fa;
  static const int MAX_LG_N = 30;
  static vector<Ring> g, ig;
  
  static void precompute() {
    if(!g.empty()) return;
    Provider();
    g.resize(MAX_LG_N);
    ig.resize(MAX_LG_N);
    for(int i = 0; i < MAX_LG_N; i++) {
      Ring w = Provider::g ^ (((Ring::mod-1) >> (i + 2)) * 3);
      w = -w;
      Ring iw = w.inverse();
      g[i] = w;
      ig[i] = iw;
    }
  }

  static inline U& v(Ring& p) {
    return (U&)p.data();
  }

  static inline U v(const Ring& p) {
    return (U)p.data();
  }

  static void dft_iter(Ring *p, int n) {
    // decimation-in-time
    // natural to reverse ordering
    for (int B = n >> 1; B; B >>= 1) {
      Ring w = 1;
      for (int i = 0, twiddle = 0; i < n; i += B * 2) {
        for (int j = i; j < i + B; j++) {
          Ring z = p[j + B] * w;
          p[j + B] = p[j] - z;
          p[j] += z;
        }
        w *= g[__builtin_ctz(++twiddle)];
      }
    }
  }

  static void idft_iter(Ring *p, int n) {
    // decimation-in-frequency
    // reverse to natural ordering
    for (int B = 1; B < n; B <<= 1) {
      Ring w = 1;
      for (int i = 0, twiddle = 0; i < n; i += B * 2) {
        for (int j = i; j < i + B; j++) {
          Ring z = (p[j] - p[j + B]) * w;
          p[j] += p[j + B];
          p[j + B] = z;
        }
        w *= ig[__builtin_ctz(++twiddle)];
      }
    }
  }

  static void swap(vector<Ring> &buf) { std::swap(fa, buf); }
  static void _dft(Ring *p, int n) {
    precompute();
    dft_iter(p, n);
  }
  static void _idft(Ring *p, int n) {
    precompute();
    idft_iter(p, n);
    Ring inv = Provider().inverse(n);
    for (int i = 0; i < n; i++)
      p[i] *= inv;
  }

  static void dft(int n) { _dft(fa.data(), n); }

  static void idft(int n) { _idft(fa.data(), n); }

  static void dft(vector<Ring> &v, int n) {
    swap(v);
    dft(n);
    swap(v);
  }
  static void idft(vector<Ring> &v, int n) {
    swap(v);
    idft(n);
    swap(v);
  }

  static int ensure(int a, int b = 0) {
    int n = a+b;
    n = next_power_of_two(n);
    if ((int)fa.size() < n)
      fa.resize(n);
    return n;
  }

  static void clear(int n) { fill(fa.begin(), fa.begin() + n, 0); }

  template<typename Iterator>
  static void fill(Iterator begin, Iterator end) {
    int n = ensure(distance(begin, end));
    int i = 0;
    for(auto it = begin; it != end; ++it) {
      fa[i++] = *it;
    }
    for(;i < n; i++) fa[i] = Ring();
  }

  static void _convolve(const vector<T> &a) {
    int n = ensure(a.size(), a.size());
    for (size_t i = 0; i < (size_t)n; i++)
      fa[i] = i < a.size() ? a[i] : T();
    dft(n);
    for (int i = 0; i < n; i++)
      fa[i] *= fa[i];
    idft(n);
  }

  static void _convolve(const vector<T> &a, const vector<T> &b) {
    if(std::addressof(a) == std::addressof(b))
      return _convolve(a);
    int n = ensure(a.size(), b.size());
    for (size_t i = 0; i < (size_t)n; i++)
      fa[i] = i < a.size() ? a[i] : T();
    dft(n);
    // TODO: have a buffer for this
    auto fb = retrieve<FHT<T>, T>(n);
    for(size_t i = 0; i < (size_t)n; i++)
      fa[i] = i < b.size() ? b[i] : T();
    dft(n);
    for (int i = 0; i < n; i++)
      fa[i] *= fb[i];
    idft(n);
  }

  static vector<T> convolve(const vector<T>& a, const vector<T>& b) {
    int sz = (int)a.size() + b.size() - 1;
    _convolve(a, b);
    return retrieve<FHT<T>, T>(sz);
  }
  
  static VectorN<T> transform(vector<T> a, int n) {
    a.resize(n);
    dft(a, n);
    return a;
  }

  static vector<T> itransform(vector<T> a, int n) {
    int sz = a.size();
    idft(a, sz);
    a.resize(min(n, sz));
    return a;
  }
};

template<typename Ring>
vector<Ring> FHT<Ring>::fa = vector<Ring>();
template<typename Ring>
vector<Ring> FHT<Ring>::g = vector<Ring>();
template<typename Ring>
vector<Ring> FHT<Ring>::ig = vector<Ring>();
}

using FHTMultiplication = TransformMultiplication<linalg::FHT>;
} // namespace lib

#endif
