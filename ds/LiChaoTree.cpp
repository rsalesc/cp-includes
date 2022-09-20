#ifndef _LIB_LI_CHAO_TREE
#define _LIB_LI_CHAO_TREE

#include <bits/stdc++.h>

namespace lib {
using namespace std;

template <typename D, typename T, bool Prune = true> struct LiChaoTree {
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
    // mid is exclusive
    int mid = (l + r) / 2;
    bool l_wins = fns[i](xs[l]) < fns[t[no]](xs[l]);
    if (Prune) {
      bool r_wins = fns[i](xs[r-1]) < fns[t[no]](xs[r-1]);
      if (l_wins == r_wins) {
        if (l_wins) swap(i, t[no]);
        return;
      }
    }
    bool mid_wins = fns[i](xs[mid]) < fns[t[no]](xs[mid]);
    if (mid_wins)
      swap(i, t[no]);
    if (l + 1 == r)
      return;
    if (l_wins != mid_wins)
      add(i, 2 * no, l, mid);
    else
      add(i, 2 * no + 1, mid, r);
  }

  void add_segment(int idx, int no, int l, int r, int i, int j) {
    if (i >= r || j <= l) return;
    if (i <= l && r <= j) add(idx, no, l, r);
    else {
      int mid = (l+r)/2;
      add_segment(idx, 2*no, l, mid, i, j);
      add_segment(idx, 2*no+1, mid, r, i, j);
    }
  }

  void add_segment(const Fn& fn, D a, D b) {
    int i = fns.size();
    fns.push_back(fn);
    int l = lower_bound(xs.begin(), xs.end(), a) - xs.begin();
    int r = lower_bound(xs.begin(), xs.end(), b) - xs.begin();
    if (l == r) return;
    add_segment(i, 1, 0, xs.size(), l, r);
  }

  T query(D x, int no, int l, int r) const {
    if (l + 1 == r)
      return fns[t[no]](x);
    int mid = (l + r) / 2;
    if (x < xs[mid])
      return min(fns[t[no]](x), query(x, 2 * no, l, mid));
    else
      return min(fns[t[no]](x), query(x, 2 * no + 1, mid, r));
  }

  T query(D x) const { return query(x, 1, 0, xs.size()); }
};
} // namespace lib

#endif