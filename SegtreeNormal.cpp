#ifndef _LIB_SEGTREE_NORMAL
#define _LIB_SEGTREE_NORMAL
#include "SegtreeBeats.cpp"
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace seg {
template <typename Node, typename CombinerFn,
          typename NodeManager = Explicit<Node>>
struct SegtreeNormal : public SegtreeImpl<Node, NodeManager, CombinerFn> {
  typedef SegtreeImpl<Node, NodeManager, CombinerFn> Base;
  using Base::combiner_fn;
  using Base::L;
  using Base::manager;
  using Base::R;
  using Base::Base;
  using Base::split;
  using typename Base::vnode;

  template <typename Updater>
  vnode update_element(vnode no, int l, int r, int idx,
                       const Updater &updater) {
    no = manager.persist(no);
    if (l == r)
      updater(manager.ref(no));
    else {
      int mid = split(l, r);
      if (idx <= mid)
        update_element(manager.left(no), l, mid, idx, updater);
      else
        update_element(manager.right(no), mid + 1, r, idx, updater);
      auto left_no = manager.left(no);
      auto right_no = manager.right(no);
      auto left_value =
          manager.has(left_no) ? manager.value(left_no) : combiner_fn();
      auto right_value =
          manager.has(right_no) ? manager.value(right_no) : combiner_fn();
      manager.ref(no) = combiner_fn(left_value, right_value);
    }
    return no;
  }

  template <typename Updater>
  inline vnode update_element(vnode root, int idx, const Updater &updater) {
    return manager.new_root(update_element(root, L, R, idx, updater));
  }

  template <typename Updater>
  inline vnode update_element(int idx, const Updater &updater) {
    return update_element(this->root(), idx, updater);
  }
};
} // namespace seg
} // namespace lib

#endif
