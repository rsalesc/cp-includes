#ifndef _LIB_COLOR_MATROID
#define _LIB_COLOR_MATROID
#include <bits/stdc++.h>
#include "Matroid.cpp"

namespace lib {
  using namespace std;
struct ColorMatroid : IncrementalMatroid {
  vector<int> cnt, limits, lazy;
  lambda::Map<int> color;
  int lazy_n = 0;
  ColorMatroid() {}
  ColorMatroid(vector<int> limits, const lambda::SubsetMap<int>& color_)
    : IncrementalMatroid(), limits(limits), color(color_),
      lazy(limits.size()), cnt(limits.size()) {
      set_ground(color_.size());
    }
  ColorMatroid(int n, int K, const lambda::SubsetMap<int>& color_)
    : IncrementalMatroid(), limits(n, K), color(color_),
      lazy(n), cnt(n) {
      set_ground(color_.size());
    }
  void clear() override {
    lazy_n++;
  }
  void fix_(int i) {
    if(lazy[i] != lazy_n) lazy[i] = lazy_n, cnt[i] = 0;
  }
  void add(int i) override {
    auto c = color(i);
    fix_(c);
    cnt[c]++;
  }
  bool check(int i) override {
    auto c = color(i);
    fix_(c);
    bool res = cnt[c] < limits[c];
    return res;
  }
};
} // namespace lib

#endif
