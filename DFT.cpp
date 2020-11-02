#ifndef _LIB_DFT
#define _LIB_DFT
#include <bits/stdc++.h>
#include "BitTricks.cpp"

namespace lib {
using namespace std;
namespace linalg {
template <typename Ring, typename Provider>
struct DFT {
  static vector<int> rev;
  static vector<Ring> fa;

  // function used to precompute rev for fixed size fft (n is a power of two)
  static void dft_rev(int n) {
    Provider()(n);
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

  static void dft_iter(Ring *p, int n) {
    Provider w;
    for (int L = 2; L <= n; L <<= 1) {
      for (int i = 0; i < n; i += L) {
        for (int j = 0; j < L / 2; j++) {
          Ring z = p[i + j + L / 2] * w[j + L / 2];
          p[i + j + L / 2] = p[i + j] - z;
          p[i + j] = p[i + j] + z;
        }
      }
    }
  }

  static void swap(vector<Ring> &buf) { std::swap(fa, buf); }
  static void _dft(Ring *p, int n) {
    for (int i = 0; i < n; i++)
      if (i < rev[i])
        std::swap(p[i], p[rev[i]]);
    dft_iter(p, n);
  }
  static void _idft(Ring *p, int n) {
    _dft(p, n);
    reverse(p + 1, p + n);
    for (int i = 0; i < n; i++)
      p[i] /= n;
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
    int n = max(a, b);
    n = next_power_of_two(n) << 1;
    if ((int)fa.size() < n)
      fa.resize(n);
    return n;
  }

  static void clear(int n) { fill(fa.begin(), fa.begin() + n, 0); }
};

template<typename Ring, typename Provider>
vector<int> DFT<Ring, Provider>::rev = vector<int>();

template<typename Ring, typename Provider>
vector<Ring> DFT<Ring, Provider>::fa = vector<Ring>();
}
} // namespace lib

#endif
