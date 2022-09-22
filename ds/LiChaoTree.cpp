#ifndef _LIB_LI_CHAO_TREE
#define _LIB_LI_CHAO_TREE

#include <bits/stdc++.h>

namespace lib {
using namespace std;

template <typename D, typename T> struct LiChaoTree {
  inline constexpr static T inf = numeric_limits<T>::max();

  using Fn = function<T(D)>;
  vector<Fn> fns;
  vector<D> xs;
  vector<int> t;

  template <typename U = D,
            typename enable_if<is_integral<U>::value>::type = nullptr>
  LiChaoTree(D left, D right) {
    assert(right > left);
    xs = vector<D>(right - left);
    iota(xs.begin(), xs.end(), left);
    init();
  }

  LiChaoTree(const vector<D>& xs_) : xs(xs_) {
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    init();
  }

  void init() {
    t = vector<int>(xs.size() * 4);
    fns.clear();
    fns.push_back([](D x) { return numeric_limits<T>::max(); });
  }

  void add(const Fn &fn) {
    int i = fns.size();
    fns.push_back(fn);
    add(i, 1, 0, xs.size());
  }

  // r is exclusive
  void add(int i, int no, int l, int r) {
    while (1) {
      int mid = (l + r) / 2;
      bool l_wins = fns[i](xs[l]) < fns[t[no]](xs[l]);
      bool r_wins = fns[i](xs[r-1]) < fns[t[no]](xs[r-1]);
      if (l_wins == r_wins) {
        if (l_wins) swap(i, t[no]);
        return;
      }
      bool mid_wins = fns[i](xs[mid]) < fns[t[no]](xs[mid]);
      if (mid_wins)
        swap(i, t[no]);
      if (l + 1 == r)
        return;
      if (l_wins != mid_wins)
        no = 2 * no, r = mid;
      else
        no = 2 * no + 1, l = mid;
    }
  }

  int seg_l, seg_r, seg_idx;
  void add_segment(int no, int l, int r) {
    if (seg_l >= r || seg_r <= l) return;
    if (seg_l <= l && r <= seg_r) add(seg_idx, no, l, r);
    else {
      int mid = (l+r)/2;
      add_segment(2*no, l, mid);
      add_segment(2*no+1, mid, r);
    }
  }

  void add_segment(const Fn& fn, D a, D b) {
    int i = fns.size();
    fns.push_back(fn);
    int l = lower_bound(xs.begin(), xs.end(), a) - xs.begin();
    int r = lower_bound(xs.begin(), xs.end(), b) - xs.begin();
    if (l == r) return;
    seg_idx = i, seg_l = l, seg_r = r;
    add_segment(1, 0, xs.size());
  }

  T query(D x, int no, int l, int r) const {
    auto res = inf;
    while (1) {
      res = min(res, fns[t[no]](x));
      if (l + 1 == r)
        return res;
      int mid = (l + r) / 2;
      if (x < xs[mid])
        no = 2 * no, r = mid;
      else
        no = 2 * no + 1, l = mid;
    }
  }

  T query(D x) const { return query(x, 1, 0, xs.size()); }
};
} // namespace lib

#endif