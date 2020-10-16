#ifndef _LIB_SEGTREE_BEATS
#define _LIB_SEGTREE_BEATS
#include "Segtree.cpp"
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace seg {
struct DefaultBreakCond {
  template <typename Node>
  inline bool operator()(const Node &no, int l, int r, int i, int j) const {
    return i > r || j < l;
  }
};

struct DefaultTagCond {
  template <typename Node>
  inline bool operator()(const Node &no, int l, int r, int i, int j) const {
    return i <= l && r <= j;
  }
};

template <typename T> struct SearchResult {
  bool found;
  int pos;
  T value;

  static SearchResult<T> not_found(T acc = T()) { return {false, 0, acc}; }
};

struct PrefixSearch;
struct SuffixSearch;

template <typename Direction> using IsSuffix = is_same<Direction, SuffixSearch>;

template <typename Node> struct InMemoryNodeManager {
  typedef int vnode;
  vector<Node> t;

  template <typename Builder> void initialize(const Builder &builder) {
    int L, R;
    tie(L, R) = builder.range();
    t = vector<Node>(4 * (R - L + 1));
  }

  inline bool has(vnode no) { return true; }
  inline vnode root() { return 1; }
  inline vnode new_root(vnode no) { return no; }
  inline vnode left(vnode no) { return no << 1; }
  inline vnode right(vnode no) { return no << 1 | 1; }
  inline Node &ref(vnode no) { return t[no]; }
  inline Node *ptr(vnode no) { return &t[no]; }
  inline Node value(vnode no) { return t[no]; }

  inline vnode persist(vnode no) { return no; }
  inline void ensure_left(vnode no) {}
  inline void ensure_right(vnode no) {}
};

template <
    typename Node, typename NodeManager, typename CombinerFn = EmptyFolder<int>,
    typename PushdownFn = EmptyPushdown, typename BreakCond = DefaultBreakCond,
    typename TagCond = DefaultTagCond>
struct SegtreeImpl {
  typedef typename NodeManager::vnode vnode;
  constexpr static bool has_lazy = !is_same<PushdownFn, EmptyPushdown>::value;
  constexpr static bool is_implicit =
      !is_same<NodeManager, InMemoryNodeManager<Node>>::value;

  CombinerFn combiner_fn;
  PushdownFn pushdown_fn;
  BreakCond break_cond;
  TagCond tag_cond;
  NodeManager manager;

  int L, R;

  template <typename Builder> explicit SegtreeImpl(const Builder &builder) {
    tie(L, R) = builder.range();
    assert(L <= R);
    manager.initialize(builder);
    if (builder.should_build())
      build(builder);
  }

  inline vnode root() { return manager.root(); }
  inline int split(int l, int r) { return l + (r - l) / 2; }

  template <typename Builder>
  vnode build(const Builder &builder, vnode no, int l, int r) {
    no = manager.persist(no);
    if (l == r) {
      builder(manager.ref(no), l);
    } else {
      int mid = split(l, r);
      build(builder, manager.left(no), l, mid);
      build(builder, manager.right(no), mid + 1, r);
      manager.ref(no) = combiner_fn(manager.value(manager.left(no)),
                                    manager.value(manager.right(no)));
    }
    return no;
  }

  template <typename Builder> vnode build(const Builder &builder) {
    return manager.new_root(build(builder, root(), L, R));
  }

  inline int size() const { return R - L + 1; }

  void push(vnode no, int l, int r) {
    if (!pushdown_fn.dirty(no))
      return;
    manager.ensure_left(no);
    manager.ensure_right(no);
    Node *left = l == r ? nullptr : manager.ptr(manager.left(no));
    Node *right = l == r ? nullptr : manager.ptr(manager.right(no));
    pushdown_fn(manager.ref(no), l, r, left, right);
  }

  template <typename T, typename Folder>
  T query(vnode no, int l, int r, int i, int j, const Folder &folder) {
    if (!manager.has(no))
      return folder();
    if (j < l || i > r)
      return folder();
    if (has_lazy)
      push(no, l, r);
    if (i <= l && r <= j)
      return folder(manager.ref(no));
    int mid = split(l, r);
    return folder(query<T>(manager.left(no), l, mid, i, j, folder),
                  query<T>(manager.right(no), mid + 1, r, i, j, folder));
  }

  template <typename T, typename Folder>
  inline T query(vnode root, int i, int j, const Folder &folder) {
    return query<T>(root, L, R, i, j, folder);
  }

  template <typename T, typename Folder>
  inline T query(int i, int j, const Folder &folder) {
    return query<T>(root(), i, j, folder);
  }

  template <typename Updater>
  vnode update(vnode no, int l, int r, int i, int j, const Updater &updater) {
    push(no, l, r);
    if (break_cond(manager.ref(no), l, r, i, j)) {
      return no;
    }
    no = manager.persist(no);
    if (tag_cond(manager.ref(no), l, r, i, j)) {
      updater(manager.ref(no));
      push(no, l, r);
      return no;
    }
    int mid = split(l, r);
    update(manager.left(no), l, mid, i, j, updater);
    update(manager.right(no), mid + 1, r, i, j, updater);
    manager.ref(no) = combiner_fn(manager.value(manager.left(no)),
                                  manager.value(manager.right(no)));
    return no;
  }

  template <typename Updater>
  inline vnode update(vnode root, int i, int j, const Updater &updater) {
    return manager.new_root(update(root, L, R, i, j, updater));
  }

  template <typename Updater>
  inline vnode update(int i, int j, const Updater &updater) {
    return update(root(), i, j, updater);
  }

  template <typename Beater, typename U = NodeManager,
            typename enable_if<
                is_same<U, InMemoryNodeManager<Node>>::value>::type * = nullptr>
  void beat(vnode no, int l, int r, int i, int j, const Beater &beater) {
    push(no, l, r);
    if (break_cond(manager.ref(no), l, r, i, j) ||
        beater.stop(manager.ref(no), l, r, i, j)) {
      return;
    }
    if (tag_cond(manager.ref(no), l, r, i, j) &&
        beater.tag(manager.ref(no), l, r, i, j)) {
      beater(manager.ref(no));
      push(no, l, r);
      return;
    }
    int mid = split(l, r);
    beat(manager.left(no), l, mid, i, j, beater);
    beat(manager.right(no), mid + 1, r, i, j, beater);
    manager.ref(no) = combiner_fn(manager.value(manager.left(no)),
                                  manager.value(manager.right(no)));
  }

  template <typename Beater>
  inline void beat(int i, int j, const Beater &beater) {
    beat(root(), L, R, i, j, beater);
  }

  template <typename T, typename Direction, typename Folder, typename Checker>
  SearchResult<T> bsearch_first(vnode no, int l, int r, int i, int j,
                                const Folder &folder, const Checker &checker,
                                T acc) {
    if (manager.has(no) && has_lazy)
      push(no, l, r);
    if (j < l || i > r)
      return SearchResult<T>::not_found(folder());
    if (!manager.has(no)) {
      auto value = folder(acc, folder());
      if (checker(value))
        return {true, IsSuffix<Direction>::value ? r : l, value};
      else
        return SearchResult<T>::not_found(folder());
    }
    int mid = split(l, r);
    if (i <= l && r <= j) {
      auto b_value = folder(acc, manager.value(no));
      if (!checker(b_value))
        return SearchResult<T>::not_found(manager.value(no));
      if (l == r)
        return {true, l, b_value};
    }
    if (!IsSuffix<Direction>::value) {
      auto res_left = bsearch_first<T, Direction>(manager.left(no), l, mid, i,
                                                  j, folder, checker, acc);
      if (res_left.found)
        return res_left;
      return bsearch_first<T, Direction>(manager.right(no), mid + 1, r, i, j,
                                         folder, checker,
                                         folder(acc, res_left.value));
    } else {
      auto res_right = bsearch_first<T, Direction>(
          manager.right(no), mid + 1, r, i, j, folder, checker, acc);
      if (res_right.found)
        return res_right;
      return bsearch_first<T, Direction>(manager.left(no), l, mid, i, j, folder,
                                         checker, folder(acc, res_right.value));
    }
  }

  template <typename T, typename Direction, typename Folder, typename Checker>
  inline SearchResult<T> bsearch_first(vnode root, int i, int j,
                                       const Folder &folder,
                                       const Checker &checker) {
    auto res = bsearch_first<T, Direction>(root, L, R, i, j, folder, checker,
                                           folder());
    if (!res.found)
      res.pos = IsSuffix<Direction>::value ? i - 1 : j + 1;
    return res;
  }

  template <typename T, typename Direction, typename Folder, typename Checker>
  inline SearchResult<T> bsearch_first(int i, int j, const Folder &folder,
                                       const Checker &checker) {
    return bsearch_first<T, Direction>(root(), i, j, folder, checker);
  }

  template <typename T, typename Direction, typename Folder, typename Checker>
  inline SearchResult<T> bsearch_last(vnode root, int i, int j,
                                      const Folder &folder,
                                      const Checker &checker) {
    auto res = bsearch_first<T, Direction>(
        root, i, j, folder, [&checker](T x) { return !checker(x); });
    if (!IsSuffix<Direction>::value) {
      if (res.pos == i)
        res.found = false;
      res.pos--;
    } else {
      if (res.pos == j)
        res.found = false;
      res.pos++;
    }
    return res;
  }

  template <typename T, typename Direction, typename Folder, typename Checker>
  inline SearchResult<T> bsearch_last(int i, int j, const Folder &folder,
                                      const Checker &checker) {
    return bsearch_last<T, Direction>(root(), i, j, folder, checker);
  }
};

template <typename Node, typename CombinerFn = EmptyFolder<int>,
          typename PushdownFn = EmptyPushdown,
          typename BreakCond = DefaultBreakCond,
          typename TagCond = DefaultTagCond>
struct SegtreeBeats : SegtreeImpl<Node, InMemoryNodeManager<Node>, CombinerFn,
                                  PushdownFn, BreakCond, TagCond> {

  template <typename Builder>
  explicit SegtreeBeats(const Builder &builder)
      : SegtreeImpl<Node, InMemoryNodeManager<Node>, CombinerFn, PushdownFn,
                    BreakCond, TagCond>(builder) {}
};

template <typename Node> using Explicit = InMemoryNodeManager<Node>;
} // namespace seg
} // namespace lib

#endif
