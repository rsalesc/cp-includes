#ifndef _LIB_SEGTREE_SPLASH
#define _LIB_SEGTREE_SPLASH
#include "SegtreeBeats.cpp"
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace seg {
template <typename Node, typename NodeManager = Explicit<Node>>
struct SegtreeSplash : SegtreeBeats<Node, NodeManager, EmptyFolder<void>> {
  typedef SegtreeBeats<Node, NodeManager, EmptyFolder<void>> Base;
  using Base::L;
  using Base::manager;
  using Base::R;
  using Base::SegtreeBeats;
  using Base::split;
  using typename Base::vnode;

  template <typename T, typename Folder>
  T query_element(vnode no, int l, int r, int idx, const Folder &folder) {
    if (!manager.has(no))
      return folder();
    T res = folder(manager.ref(no));
    if (l != r) {
      int mid = split(l, r);
      if (idx <= mid)
        res = folder(res,
                     query_element<T>(manager.left(no), l, mid, idx, folder));
      else
        res = folder(
            res, query_element<T>(manager.right(no), mid + 1, r, idx, folder));
    }
    return res;
  }

  template <typename T, typename Folder>
  inline T query_element(vnode root, int idx, const Folder &folder) {
    return query_element<T>(root, L, R, idx, folder);
  }

  template <typename T, typename Folder>
  inline T query_element(int idx, const Folder &folder) {
    return query_element<T>(this->root(), idx, folder);
  }

  template <typename Updater>
  vnode splash(vnode no, int l, int r, int i, int j, const Updater &updater) {
    no = manager.persist(no);
    if (tag_cond(manager.ref(no), l, r, i, j)) {
      updater(manager.ref(no));
      return no;
    }
    int mid = split(l, r);
    if (j <= mid) {
      manager.ensure_left(no);
      splash(manager.left(no), l, mid, i, j, updater);
    } else if (i > mid) {
      manager.ensure_right(no);
      splash(manager.right(no), mid + 1, r, i, j, updater);
    } else {
      manager.ensure_left(no), manager.ensure_right(no);
      splash(manager.left(no), l, mid, i, j, updater);
      splash(manager.right(no), mid + 1, r, i, j, updater);
    }
    return no;
  }

  template <typename Updater>
  inline vnode splash(vnode root, int i, int j, const Updater &updater) {
    return manager.new_root(splash(root, L, R, i, j, updater));
  }

  template <typename Updater>
  inline vnode splash(int i, int j, const Updater &updater) {
    return splash(this->root(), i, j, updater);
  }
};
} // namespace seg
} // namespace lib

#endif
