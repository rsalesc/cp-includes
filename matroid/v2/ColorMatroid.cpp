#ifndef _LIB_COLOR_MATROID
#define _LIB_COLOR_MATROID
#include <bits/stdc++.h>
#include "Matroid.cpp"
#include "../../DSU.cpp"

namespace lib {
  using namespace std;
struct ColorMatroid : IncrementalMatroid {
  vector<int> cnt, limits, lazy;
  lambda::Map<int> color;
  int lazy_n = 0;
  ColorMatroid(vector<int> limits, const lambda::Map<int>& color_)
    : IncrementalMatroid(), limits(limits), color(color_),
      lazy(limits.size()), cnt(limits.size()) {}
  ColorMatroid(int n, int K, const lambda::Map<int>& color_)
    : IncrementalMatroid(), limits(n, K), color(color_),
      lazy(n), cnt(n) {}
  void clear() override {
    lazy_n++;
  }
  void fix_(int i) {
    if(lazy[i] != lazy_n) lazy[i] = lazy_n, cnt[i] = 0;
  }
  void add(int i) override {
    auto c = color(F(i));
    fix_(c);
    cnt[c]++;
  }
  bool check(int i) override {
    auto c = color(F(i));
    fix_(c);
    return cnt[c] < limits[c];
  }
};
} // namespace lib

#endif
