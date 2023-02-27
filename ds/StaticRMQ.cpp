#ifndef _LIB_STATIC_RMQ
#define _LIB_STATIC_RMQ
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace {
  inline int lsb(int x) { return x&-x; }
}

// Credits: hly1204
template<typename T, typename Cmp = std::less<T>>
struct StaticRMQ {
  Cmp cmp;
  vector<T> t1, t2, a;

  StaticRMQ() {}

  StaticRMQ(const vector<T>& a)
    : t1(a.size() + 1), t2(a.size() + 1), a(a) {
    copy(a.begin(), a.end(), t1.begin() + 1);
    copy(a.begin(), a.end(), t2.begin() + 1);
    build();
  }

  int size() const { return (int)t1.size() - 1; }

  T best(const T& a, const T& b) const {
    return cmp(a, b) ? a : b;
  }

  void build() {
    int n = size();
    for(int i = 1; i <= n; i++) {
      int b = lsb(i);
      if(i + b <= n) t1[i + b] = best(t1[i + b], t1[i]);
    }
    for(int i = n; i; i--) {
      int b = lsb(i);
      t2[i - b] = best(t2[i - b], t2[i]);
    }
  }

  // [l, r], 0-indexed
  T query(int l, int r) const {
    if(l == r) return a[l];
    ++l, ++r;
    T ans = best(a[l-1], a[r-1]);
    int x = l;
    for(; x + lsb(x) - 1 <= r; x += lsb(x))
      ans = best(ans, t2[x]);
    for(int y = r; y != 0 && y - lsb(y) + 1 >= l; y -= lsb(y))
      ans = best(ans, t1[y]);
    if(x <= r)
      ans = best(ans, a[x-1]);
    return ans;
  }
};
} // namespace lib

#endif

