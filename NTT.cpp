#ifndef _LIB_NTT
#define _LIB_NTT
#include <bits/stdc++.h>
#include "DFT.cpp"
#include "NumberTheory.cpp"

namespace lib {
using namespace std;
namespace linalg {
template<typename T>
struct MintRootProvider {
  static size_t max_sz;
  static T g;
  static vector<T> w;

  MintRootProvider() {
    if(g == 0) {
      auto acc = T::mod-1;
      while(acc % 2 == 0) acc /= 2, max_sz++;

      auto factors = nt::factors(T::mod - 1);
      for(g = 2; (typename T::type_int)g < T::mod; g++) {
        bool ok = true;
        for(auto f : factors) {
          if(power(g, (T::mod-1)/f) == 1) {
            ok = false;
            break;
          }
        }
        if(ok) break;
      }
      assert(g != 0);
    }
  }

  void operator()(int n) {
    n = max(n, 2);
    int k = max((int)w.size(), 2);
    assert(n <= (1LL << max_sz));
    if ((int)w.size() < n)
      w.resize(n);
    else
      return;
    w[0] = w[1] = 1;
    for (; k < n; k *= 2) {
      T step = power(g, (T::mod-1)/(2*k));
      for(int i = k; i < 2*k; i++)
        w[i] = (i&1) ? w[i/2] * step : w[i/2];
    }
  }
  T operator[](int i) {
    return w[i];
  }

  T inverse(int n) {
    return T(1) / n;
  }
};

template<typename T>
size_t MintRootProvider<T>::max_sz = 1;
template<typename T>
T MintRootProvider<T>::g = T();
template<typename T>
vector<T> MintRootProvider<T>::w = vector<T>();

template<typename T>
struct NTT : public DFT<T, MintRootProvider<T>> {
  using Parent = DFT<T, MintRootProvider<T>>;
  using Parent::fa;

  static void _convolve(const vector<T> &a, const vector<T> &b) {
    int n = Parent::ensure(a.size(), b.size());
    for (size_t i = 0; i < (size_t)n; i++)
      fa[i] = i < a.size() ? a[i] : T();
    Parent::dft(n);
    // TODO: have a buffer for this
    auto fb = retrieve<Parent, T>(n);
    for(size_t i = 0; i < (size_t)n; i++)
      fa[i] = i < b.size() ? b[i] : T();
    Parent::dft(n);
    for (int i = 0; i < n; i++)
      fa[i] *= fb[i];
    Parent::idft(n);
  }

  static vector<T> convolve(const vector<T>& a, const vector<T>& b) {
    int sz = (int)a.size() + b.size() - 1;
    _convolve(a, b);
    return retrieve<Parent, T>(sz);
  }
};
}

struct NTTMultiplication {
  template <typename Field>
  vector<Field> operator()(const vector<Field> &a,
                           const vector<Field> &b) const {
    return linalg::NTT<Field>::convolve(a, b);
  };
};
} // namespace lib

#endif
