#ifndef _LIB_LAZY_ARRAY
#define _LIB_LAZY_ARRAY
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
template<typename T>
struct LazyArray {
  vector<T> v;
  vector<int> lz;
  T lz_v;
  int tempo = 1;

  LazyArray() {}
  LazyArray(int n, T lz_v) : v(n), lz(n), lz_v(lz_v) {}

  int size() const { return v.size(); }
  void fill(T vv) { lz_v = vv, tempo++; }
  void clear() {
    fill(T());
  }
  T get(int i) const {
    return tempo == lz[i] ? v[i] : lz_v;
  }
  T operator[](int i) const {
    return get(i);
  }
  T& operator[](int i) {
    if(lz[i] != tempo) {
      lz[i] = tempo;
      v[i] = lz_v;
    }
    return v[i];
  }
};
} // namespace lib

#endif
