#ifndef _LIB_COLOR_MATROID
#define _LIB_COLOR_MATROID
#include <bits/stdc++.h>
#include "Matroid.cpp"

namespace lib {
  using namespace std;
struct ColorMatroid : Matroid {
  vector<int> cnt, limits;
  lambda::Map<int> color;
  ColorMatroid(vector<int> limits, const lambda::Map<int>& color_)
    : Matroid(), limits(limits), color(color_) {}
  ColorMatroid(int n, int K, const lambda::Map<int>& color_)
    : Matroid(), limits(n, K), color(color_) {}
  void setup() {
    cnt.assign(limits.size(), 0);
    for(int i = 0; i < ground_set_size(); i++)
      if(in_I(i))
        cnt[color(i)]++;
  }
  void setup_exchange(int i) {
    cnt[color(i)]--;
  }
  void finish_exchange(int i) {
    cnt[color(i)]++;
  }
  bool can_exchange(int i, int j) {
    return can_add(j);
  }
  bool can_add(int i) {
    int c = color(i);
    return cnt[c] < limits[c];
  }
  void print() const {
    for(int x : cnt) cout << x << " ";
    cout << endl;
  }
};
} // namespace lib

#endif
