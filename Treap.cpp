#ifndef _LIB_TREAP
#define _LIB_TREAP
#include "Random.cpp"
#include "SegtreeImplicit.cpp"
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace treap {
template <typename T> struct SearchResult {
  bool found;
  T node;
};

struct EmptyPushdown {
  template <typename Node>
  inline void operator()(Node &no, Node *ln, Node *rn) const {}
};

struct EmptyCombiner {
  template <typename Node>
  inline void operator()(Node &no, Node *ln, Node *rn) const {}
};

template <typename T, typename Less = std::less<T>> struct DefaultNode {
  T key;
  int y;

  DefaultNode() {}
  DefaultNode(T key)
      : key(key), y(rng_gen.uniform_int(numeric_limits<int>::max())) {}

  inline bool operator<(const DefaultNode &rhs) const {
    return Less()(key, rhs.key);
  }

  inline int priority() const { return y; }

  template <typename Combiner>
  inline static void combine(DefaultNode &no, DefaultNode *ln, DefaultNode *rn,
                             const Combiner &combiner) {
    combiner(no, ln, rn);
  }
};

template <typename T, typename Combiner = EmptyCombiner,
          typename Pushdown = EmptyPushdown, typename Less = std::less<T>,
          typename TreapNode = DefaultNode<T, Less>,
          template <class> class ManagerTemplate = seg::Implicit>
struct TreapManager {
  using NodeManager = ManagerTemplate<TreapNode>;
  typedef TreapNode tnode;
  typedef typename NodeManager::vnode vnode;

  Combiner combiner_fn;
  Pushdown pushdown_fn;
  NodeManager manager;

  inline vnode make(T key) { return manager.make(TreapNode(key)); }
  inline vnode null() const { return manager.invalid(); }
  inline void push(vnode no) {}
  inline void update(vnode no) {
    if (!manager.has(no))
      return;
    combiner_fn(manager.ref(no), manager.ptr(manager.left(no)),
                manager.ptr(manager.right(no)));
  }

  template <typename Checker> bool check(vnode no, const Checker &checker) {
    if (!manager.has(no))
      return false;
    return checker(manager.ref(no), manager.ptr(manager.left(no)),
                   manager.ptr(manager.right(no)));
  }

  template <typename Checker>
  vnode bsearch_last_impl(vnode no, const Checker &checker) {
    push(no);
    if (!manager.has(no))
      return null();
    if (check(manager.right(no), checker))
      return bsearch_last_impl(manager.right(no), checker);
    else if (check(no, checker))
      return no;
    else
      return bsearch_last_impl(manager.left(no), checker);
  }

  template <typename Folder, typename Checker>
  vnode bsearch_last_impl(vnode no, const Folder &folder,
                          const Checker &checker) {
    push(no);
    if (!manager.has(no))
      return null();
  }

  template <typename Checker>
  SearchResult<tnode> bsearch_last(vnode no, const Checker &checker) {
    auto res = bsearch_last_impl(no, checker);
    if (!manager.has(res))
      return {false};
    return {true, manager.value(res)};
  }

  vnode merge(vnode small, vnode large) {
    push(small), push(large);
    vnode res;
    if (!manager.has(small))
      res = manager.replace(small, large);
    else if (!manager.has(large))
      res = manager.replace(large, small);
    else {
      const auto &t_small = manager.ref(small);
      const auto &t_large = manager.ref(large);
      if (t_small.priority() > t_large.priority()) {
        res = manager.persist(small);
        merge(manager.right(res), large);
      } else {
        res = manager.persist(large);
        merge(small, manager.left(res));
      }
    }
    update(res);
    return res;
  }

  template <typename Checker>
  pair<vnode, vnode> split(vnode no, const Checker &checker) {
    push(no);
    if (!manager.has(no))
      return {null(), null()};
    pair<vnode, vnode> res;
    no = manager.persist(no);
    if (check(no, checker)) {
      auto sp = split(manager.right(no), checker);
      manager.replace(manager.right(no), sp.first);
      res = {no, sp.second};
    } else {
      auto sp = split(manager.left(no), checker);
      manager.replace(manager.left(no), sp.second);
      res = {sp.first, no};
    }
    update(no);
    return res;
  }

  template <typename Checker>
  pair<vnode, vnode> split_on_node(vnode no, const Checker &checker) {
    return split(no, [&checker](const TreapNode &no, TreapNode *ln,
                                TreapNode *rn) { return checker(no); });
  }

  pair<vnode, vnode> split_on_key(vnode no, T x) {
    return split_on_node(no, [&x](const TreapNode &no) { return no.key < x; });
  }
};
} // namespace treap
} // namespace lib

#endif
