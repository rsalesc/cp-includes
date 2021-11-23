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

  StaticRMQ(const vector<T>& a)
    : t1(a.size() + 1), t2(a.size() + 1), a(a) {
    copy(a.begin(), a.end(), t1.begin() + 1);
    copy(a.begin(), a.end(), t2.begin() + 1);
    build();
  }

  int size() const { return (int)t1.size() - 1; }

  void build() {
    int n = size();
    for(int i = 1; i <= n; i++) {
      int b = lsb(i);
      if(i + b <= n) t1[i + b] = min(t1[i + b], t1[i]);
    }
    for(int i = n; i; i--) {
      int b = lsb(i);
      t2[i - b] = min(t2[i - b], t2[i]);
    }
  }

  // [l, r], 0-indexed
  T query(int l, int r) const {
    if(l == r) return a[l];
    ++l, ++r;
    T ans = min(a[l-1], a[r-1]);
    T x = l;
    for(; x + lsb(x) - 1 <= r; x += lsb(x))
      ans = min(ans, t2[x]);
    for(T y = r; y != 0 && y - lsb(y) + 1 >= l; y -= lsb(y))
      ans = min(ans, t1[y]);
    if(x <= r)
      ans = min(ans, a[x-1]);
    return ans;
  }
};
} // namespace lib

#endif

