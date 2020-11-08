#ifndef _LIB_FENWICK
#define _LIB_FENWICK
#include <bits/stdc++.h>

namespace lib {
using namespace std;
template<typename T>
struct Fenwick {
  vector<int> t;
  Fenwick(int n) : t(n+1) {}
  int size() const { return t.size() - 1; }
  void add(int i, T x) {
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
};
} // namespace lib
#endif
