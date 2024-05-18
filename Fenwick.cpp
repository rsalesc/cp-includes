#ifndef _LIB_FENWICK
#define _LIB_FENWICK
#include <bits/stdc++.h>

namespace lib {
using namespace std;
template<typename T>
struct Fenwick {
  vector<T> t;
  Fenwick(int n) : t(n+1) {}
  int size() const { return(int) t.size() - 1; }
  void add(int i, const T& x) {
    for(i++; i < t.size(); i += (i&-i))
      t[i] += x;
  }
  T get(int i) const {
    T res = 0;
    for(i++; i > 0; i -= (i&-i))
      res += t[i];
    return res;
  }
  T get(int i, int j) const {
    return get(j) - get(i - 1);
  }
  T from(int i) const {
    return get(i, size() - 1);
  }
  template<typename Func>
  int find_last(const Func& func) {
    int n = size();
    int msb = 32 - __builtin_clz(n);
    int res = 0;
    T acc = 0;
    for(int b = msb; b >= 0; b--) {
      T nxt = acc + t[res | (1 << b)];
      if (func(nxt)) {
        acc = nxt;
        res |= (1 << b);
      }
    }
    return res-1;
  }

  template<typename Func>
  int find_first(const Func& func) {
    return find_last([&](const T& val) {
      return !func(val);
    }) + 1;
  }
};
} // namespace lib
#endif
