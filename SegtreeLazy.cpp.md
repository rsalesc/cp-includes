---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Segtree.cpp
    title: Segtree.cpp
  - icon: ':warning:'
    path: SegtreeBeats.cpp
    title: SegtreeBeats.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tests/judge/horrible.cpp
    title: tests/judge/horrible.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"SegtreeLazy.cpp\"\n\n\n#line 1 \"SegtreeBeats.cpp\"\n\n\n\
    #line 1 \"Segtree.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace lib {\nusing\
    \ namespace std;\nnamespace seg {\nstruct LeafBuilder {\n  template <typename\
    \ Node> void operator()(Node &no, int i) const {}\n  inline pair<int, int> range()\
    \ const { return {0, 0}; }\n  bool should_build() const { return true; }\n};\n\
    \nstruct EmptyLeafBuilder : LeafBuilder {\n  int n;\n  explicit EmptyLeafBuilder(int\
    \ n) : n(n) {}\n  inline pair<int, int> range() const { return {0, n - 1}; }\n\
    \  bool should_build() const { return true; }\n};\n\nstruct ImplicitBuilder :\
    \ LeafBuilder {\n  int L, R;\n  explicit ImplicitBuilder(int L, int R) : L(L),\
    \ R(R) {}\n  inline pair<int, int> range() const { return {L, R}; }\n  bool should_build()\
    \ const { return false; }\n};\n\n// TODO: NOT IMPLEMENTED\ntemplate <typename\
    \ DefaultNode>\nstruct ImplicitWithDefaultBuilder : LeafBuilder {\n  int L, R;\n\
    \  DefaultNode default_node;\n  explicit ImplicitWithDefaultBuilder(int L, int\
    \ R, DefaultNode def)\n      : L(L), R(R), default_node(def) {}\n\n  template\
    \ <typename Node> inline void operator()(Node &no, int i) const {\n    no = default_node;\n\
    \  }\n\n  inline pair<int, int> range() const { return {L, R}; }\n  bool should_build()\
    \ const { return false; }\n};\n\ntemplate <typename RandomIterator> struct RangeLeafBuilder\
    \ : LeafBuilder {\n  RandomIterator begin, end;\n  explicit RangeLeafBuilder(RandomIterator\
    \ begin, RandomIterator end)\n      : begin(begin), end(end) {}\n\n  template\
    \ <typename Node> inline void operator()(Node &no, int i) const {\n    no = *(begin\
    \ + i);\n  }\n\n  inline pair<int, int> range() const { return {0, end - begin\
    \ - 1}; }\n};\n\nEmptyLeafBuilder make_builder(int n) { return EmptyLeafBuilder(n);\
    \ }\n\ntemplate <typename RandomIterator>\nRangeLeafBuilder<RandomIterator> make_builder(RandomIterator\
    \ begin,\n                                              RandomIterator end) {\n\
    \  return RangeLeafBuilder<RandomIterator>(begin, end);\n}\n\ntemplate <typename\
    \ T>\nRangeLeafBuilder<typename vector<T>::const_iterator>\nmake_builder(const\
    \ vector<T> &v) {\n  return RangeLeafBuilder<typename vector<T>::const_iterator>(v.begin(),\n\
    \                                                              v.end());\n}\n\n\
    template <typename T> struct CombineFolder {\n  inline T operator()() const {\
    \ return T(); }\n\n  template <typename Node> inline T operator()(const Node &no)\
    \ const {\n    return T(no);\n  }\n\n  inline T operator()(const T &a, const T\
    \ &b) const { return a + b; }\n};\n\ntemplate <typename T> struct EmptyFolder\
    \ : CombineFolder<T> {\n  using CombineFolder<T>::operator();\n\n  template <typename\
    \ Node> inline T operator()(const Node &no) const {\n    return T();\n  }\n  inline\
    \ T operator()(const T &a, const T &b) const { return T(); }\n};\n\ntemplate <typename\
    \ T> struct SumFolder : CombineFolder<T> {};\n\ntemplate <typename T> struct ProductFolder\
    \ : CombineFolder<T> {\n  using CombineFolder<T>::operator();\n  inline T operator()()\
    \ const { return T(1); }\n  inline T operator()(const T &a, const T &b) const\
    \ { return a * b; }\n};\n\ntemplate <typename T> struct MaxFolder : CombineFolder<T>\
    \ {\n  using CombineFolder<T>::operator();\n  inline T operator()() const { return\
    \ numeric_limits<T>::min(); }\n  inline T operator()(const T &a, const T &b) const\
    \ { return max(a, b); }\n};\n\ntemplate <typename T> struct MinFolder : CombineFolder<T>\
    \ {\n  using CombineFolder<T>::operator();\n  inline T operator()() const { return\
    \ numeric_limits<T>::max(); }\n  inline T operator()(const T &a, const T &b) const\
    \ { return min(a, b); }\n};\n\ntemplate <typename T> struct SingleValueUpdater\
    \ {\n  T value;\n  explicit SingleValueUpdater(T val) : value(val) {}\n};\n\n\
    template <typename T> struct SetUpdater : SingleValueUpdater<T> {\n  using SingleValueUpdater<T>::SingleValueUpdater;\n\
    \n  template <typename Node> inline void operator()(Node &no) const {\n    no\
    \ = this->value;\n  }\n};\n\ntemplate <typename T> struct AddUpdater : SingleValueUpdater<T>\
    \ {\n  using SingleValueUpdater<T>::SingleValueUpdater;\n\n  template <typename\
    \ Node> inline void operator()(Node &no) const {\n    no += this->value;\n  }\n\
    };\n\ntemplate <typename T> struct MultUpdater : SingleValueUpdater<T> {\n  using\
    \ SingleValueUpdater<T>::SingleValueUpdater;\n\n  template <typename Node> inline\
    \ void operator()(Node &no) const {\n    no *= this->value;\n  }\n};\n\nstruct\
    \ EmptyPushdown {\n  template<typename Node>\n  inline bool dirty(const Node&\
    \ no) const { return false; }\n\n  template<typename Node>\n  inline void operator()(Node&\
    \ no, int l, int r, \n                  Node* ln, Node* rn) const {}\n};\n}  //\
    \ namespace seg\n}  // namespace lib\n\n\n#line 5 \"SegtreeBeats.cpp\"\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace seg {\nstruct DefaultBreakCond {\n  template\
    \ <typename Node>\n  inline bool operator()(const Node &no, int l, int r, int\
    \ i, int j) const {\n    return i > r || j < l;\n  }\n};\n\nstruct DefaultTagCond\
    \ {\n  template <typename Node>\n  inline bool operator()(const Node &no, int\
    \ l, int r, int i, int j) const {\n    return i <= l && r <= j;\n  }\n};\n\ntemplate\
    \ <typename T> struct SearchResult {\n  bool found;\n  int pos;\n  T value;\n\n\
    \  static SearchResult<T> not_found(T acc = T()) { return {false, 0, acc}; }\n\
    };\n\nstruct PrefixSearch;\nstruct SuffixSearch;\n\ntemplate <typename Direction>\
    \ using IsSuffix = is_same<Direction, SuffixSearch>;\n\ntemplate <typename Node>\
    \ struct InMemoryNodeManager {\n  typedef int vnode;\n  vector<Node> t;\n\n  template\
    \ <typename Builder> void initialize(const Builder &builder) {\n    int L, R;\n\
    \    tie(L, R) = builder.range();\n    t = vector<Node>(4 * (R - L + 1));\n  }\n\
    \n  inline bool has(vnode no) { return true; }\n  inline vnode root() { return\
    \ 1; }\n  inline vnode new_root(vnode no) { return no; }\n  inline vnode left(vnode\
    \ no) { return no << 1; }\n  inline vnode right(vnode no) { return no << 1 | 1;\
    \ }\n  inline Node &ref(vnode no) { return t[no]; }\n  inline Node *ptr(vnode\
    \ no) { return &t[no]; }\n  inline Node value(vnode no) { return t[no]; }\n\n\
    \  inline vnode persist(vnode no) { return no; }\n  inline void ensure_left(vnode\
    \ no) {}\n  inline void ensure_right(vnode no) {}\n};\n\ntemplate <\n    typename\
    \ Node, typename NodeManager, typename CombinerFn = EmptyFolder<int>,\n    typename\
    \ PushdownFn = EmptyPushdown, typename BreakCond = DefaultBreakCond,\n    typename\
    \ TagCond = DefaultTagCond>\nstruct SegtreeImpl {\n  typedef typename NodeManager::vnode\
    \ vnode;\n  constexpr static bool has_lazy = !is_same<PushdownFn, EmptyPushdown>::value;\n\
    \  constexpr static bool is_implicit =\n      !is_same<NodeManager, InMemoryNodeManager<Node>>::value;\n\
    \n  CombinerFn combiner_fn;\n  PushdownFn pushdown_fn;\n  BreakCond break_cond;\n\
    \  TagCond tag_cond;\n  NodeManager manager;\n\n  int L, R;\n\n  template <typename\
    \ Builder> explicit SegtreeImpl(const Builder &builder) {\n    tie(L, R) = builder.range();\n\
    \    assert(L <= R);\n    manager.initialize(builder);\n    if (builder.should_build())\n\
    \      build(builder);\n  }\n\n  inline vnode root() { return manager.root();\
    \ }\n  inline int split(int l, int r) { return l + (r - l) / 2; }\n\n  template\
    \ <typename Builder>\n  vnode build(const Builder &builder, vnode no, int l, int\
    \ r) {\n    no = manager.persist(no);\n    if (l == r) {\n      builder(manager.ref(no),\
    \ l);\n    } else {\n      int mid = split(l, r);\n      build(builder, manager.left(no),\
    \ l, mid);\n      build(builder, manager.right(no), mid + 1, r);\n      manager.ref(no)\
    \ = combiner_fn(manager.value(manager.left(no)),\n                           \
    \         manager.value(manager.right(no)));\n    }\n    return no;\n  }\n\n \
    \ template <typename Builder> vnode build(const Builder &builder) {\n    return\
    \ manager.new_root(build(builder, root(), L, R));\n  }\n\n  inline int size()\
    \ const { return R - L + 1; }\n\n  void push(vnode no, int l, int r) {\n    if(!has_lazy)\
    \ return;\n    if (!pushdown_fn.dirty(manager.ref(no)))\n      return;\n    if(l\
    \ == r) {\n      pushdown_fn(manager.ref(no), l, r, nullptr, nullptr);\n     \
    \ return;\n    }\n    manager.ensure_left(no);\n    manager.ensure_right(no);\n\
    \    vnode lno = manager.persist(manager.left(no));\n    vnode rno = manager.persist(manager.right(no));\n\
    \    pushdown_fn(manager.ref(no), l, r, manager.ptr(lno), manager.ptr(rno));\n\
    \  }\n\n  template <typename T, typename Folder>\n  T query(vnode no, int l, int\
    \ r, int i, int j, const Folder &folder) {\n    if (!manager.has(no))\n      return\
    \ folder();\n    if (j < l || i > r)\n      return folder();\n    push(no, l,\
    \ r);\n    if (i <= l && r <= j)\n      return folder(manager.ref(no));\n    int\
    \ mid = split(l, r);\n    return folder(query<T>(manager.left(no), l, mid, i,\
    \ j, folder),\n                  query<T>(manager.right(no), mid + 1, r, i, j,\
    \ folder));\n  }\n\n  template <typename T, typename Folder>\n  inline T query(vnode\
    \ root, int i, int j, const Folder &folder) {\n    return query<T>(root, L, R,\
    \ i, j, folder);\n  }\n\n  template <typename T, typename Folder>\n  inline T\
    \ query(int i, int j, const Folder &folder) {\n    return query<T>(root(), i,\
    \ j, folder);\n  }\n\n  template <typename Updater>\n  vnode update(vnode no,\
    \ int l, int r, int i, int j, const Updater &updater) {\n    push(no, l, r);\n\
    \    if (break_cond(manager.ref(no), l, r, i, j)) {\n      return no;\n    }\n\
    \    no = manager.persist(no);\n    if (tag_cond(manager.ref(no), l, r, i, j))\
    \ {\n      updater(manager.ref(no));\n      push(no, l, r);\n      return no;\n\
    \    }\n    int mid = split(l, r);\n    update(manager.left(no), l, mid, i, j,\
    \ updater);\n    update(manager.right(no), mid + 1, r, i, j, updater);\n    manager.ref(no)\
    \ = combiner_fn(manager.value(manager.left(no)),\n                           \
    \       manager.value(manager.right(no)));\n    return no;\n  }\n\n  template\
    \ <typename Updater>\n  inline vnode update(vnode root, int i, int j, const Updater\
    \ &updater) {\n    return manager.new_root(update(root, L, R, i, j, updater));\n\
    \  }\n\n  template <typename Updater>\n  inline vnode update(int i, int j, const\
    \ Updater &updater) {\n    return update(root(), i, j, updater);\n  }\n\n  template\
    \ <typename Beater, typename U = NodeManager,\n            typename enable_if<\n\
    \                is_same<U, InMemoryNodeManager<Node>>::value>::type * = nullptr>\n\
    \  void beat(vnode no, int l, int r, int i, int j, const Beater &beater) {\n \
    \   push(no, l, r);\n    if (break_cond(manager.ref(no), l, r, i, j) ||\n    \
    \    beater.stop(manager.ref(no), l, r, i, j)) {\n      return;\n    }\n    if\
    \ (tag_cond(manager.ref(no), l, r, i, j) &&\n        beater.tag(manager.ref(no),\
    \ l, r, i, j)) {\n      beater(manager.ref(no));\n      push(no, l, r);\n    \
    \  return;\n    }\n    int mid = split(l, r);\n    beat(manager.left(no), l, mid,\
    \ i, j, beater);\n    beat(manager.right(no), mid + 1, r, i, j, beater);\n   \
    \ manager.ref(no) = combiner_fn(manager.value(manager.left(no)),\n           \
    \                       manager.value(manager.right(no)));\n  }\n\n  template\
    \ <typename Beater>\n  inline void beat(int i, int j, const Beater &beater) {\n\
    \    beat(root(), L, R, i, j, beater);\n  }\n\n  template <typename T, typename\
    \ Direction, typename Folder, typename Checker>\n  SearchResult<T> bsearch_first(vnode\
    \ no, int l, int r, int i, int j,\n                                const Folder\
    \ &folder, const Checker &checker,\n                                T acc) {\n\
    \    if (manager.has(no))\n      push(no, l, r);\n    if (j < l || i > r)\n  \
    \    return SearchResult<T>::not_found(folder());\n    if (!manager.has(no)) {\n\
    \      auto value = folder(acc, folder());\n      if (checker(value))\n      \
    \  return {true, IsSuffix<Direction>::value ? r : l, value};\n      else\n   \
    \     return SearchResult<T>::not_found(folder());\n    }\n    int mid = split(l,\
    \ r);\n    if (i <= l && r <= j) {\n      auto b_value = folder(acc, manager.value(no));\n\
    \      if (!checker(b_value))\n        return SearchResult<T>::not_found(manager.value(no));\n\
    \      if (l == r)\n        return {true, l, b_value};\n    }\n    if (!IsSuffix<Direction>::value)\
    \ {\n      auto res_left = bsearch_first<T, Direction>(manager.left(no), l, mid,\
    \ i,\n                                                  j, folder, checker, acc);\n\
    \      if (res_left.found)\n        return res_left;\n      return bsearch_first<T,\
    \ Direction>(manager.right(no), mid + 1, r, i, j,\n                          \
    \               folder, checker,\n                                         folder(acc,\
    \ res_left.value));\n    } else {\n      auto res_right = bsearch_first<T, Direction>(\n\
    \          manager.right(no), mid + 1, r, i, j, folder, checker, acc);\n     \
    \ if (res_right.found)\n        return res_right;\n      return bsearch_first<T,\
    \ Direction>(manager.left(no), l, mid, i, j, folder,\n                       \
    \                  checker, folder(acc, res_right.value));\n    }\n  }\n\n  template\
    \ <typename T, typename Direction, typename Folder, typename Checker>\n  inline\
    \ SearchResult<T> bsearch_first(vnode root, int i, int j,\n                  \
    \                     const Folder &folder,\n                                \
    \       const Checker &checker) {\n    auto res = bsearch_first<T, Direction>(root,\
    \ L, R, i, j, folder, checker,\n                                           folder());\n\
    \    if (!res.found)\n      res.pos = IsSuffix<Direction>::value ? i - 1 : j +\
    \ 1;\n    return res;\n  }\n\n  template <typename T, typename Direction, typename\
    \ Folder, typename Checker>\n  inline SearchResult<T> bsearch_first(int i, int\
    \ j, const Folder &folder,\n                                       const Checker\
    \ &checker) {\n    return bsearch_first<T, Direction>(root(), i, j, folder, checker);\n\
    \  }\n\n  template <typename T, typename Direction, typename Folder, typename\
    \ Checker>\n  inline SearchResult<T> bsearch_last(vnode root, int i, int j,\n\
    \                                      const Folder &folder,\n               \
    \                       const Checker &checker) {\n    auto res = bsearch_first<T,\
    \ Direction>(\n        root, i, j, folder, [&checker](T x) { return !checker(x);\
    \ });\n    if (!IsSuffix<Direction>::value) {\n      if (res.pos == i)\n     \
    \   res.found = false;\n      res.pos--;\n    } else {\n      if (res.pos == j)\n\
    \        res.found = false;\n      res.pos++;\n    }\n    return res;\n  }\n\n\
    \  template <typename T, typename Direction, typename Folder, typename Checker>\n\
    \  inline SearchResult<T> bsearch_last(int i, int j, const Folder &folder,\n \
    \                                     const Checker &checker) {\n    return bsearch_last<T,\
    \ Direction>(root(), i, j, folder, checker);\n  }\n};\n\ntemplate <typename Node,\
    \ typename CombinerFn = EmptyFolder<int>,\n          typename PushdownFn = EmptyPushdown,\n\
    \          typename BreakCond = DefaultBreakCond,\n          typename TagCond\
    \ = DefaultTagCond>\nstruct SegtreeBeats : SegtreeImpl<Node, InMemoryNodeManager<Node>,\
    \ CombinerFn,\n                                  PushdownFn, BreakCond, TagCond>\
    \ {\n\n  template <typename Builder>\n  explicit SegtreeBeats(const Builder &builder)\n\
    \      : SegtreeImpl<Node, InMemoryNodeManager<Node>, CombinerFn, PushdownFn,\n\
    \                    BreakCond, TagCond>(builder) {}\n};\n\ntemplate <typename\
    \ Node> using Explicit = InMemoryNodeManager<Node>;\n} // namespace seg\n} //\
    \ namespace lib\n\n\n#line 5 \"SegtreeLazy.cpp\"\n\nnamespace lib {\nusing namespace\
    \ std;\nnamespace seg {\ntemplate <typename Node, typename CombinerFn, typename\
    \ PushdownFn,\n          typename NodeManager = Explicit<Node>>\nstruct SegtreeLazy\
    \ : SegtreeImpl<Node, NodeManager, CombinerFn, PushdownFn> {\n  typedef SegtreeImpl<Node,\
    \ NodeManager, CombinerFn, PushdownFn> Base;\n  using Base::SegtreeImpl;\n  using\
    \ typename Base::vnode;\n};\n} // namespace seg\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_SEGTREE_LAZY\n#define _LIB_SEGTREE_LAZY\n#include \"SegtreeBeats.cpp\"\
    \n#include <bits/stdc++.h>\n\nnamespace lib {\nusing namespace std;\nnamespace\
    \ seg {\ntemplate <typename Node, typename CombinerFn, typename PushdownFn,\n\
    \          typename NodeManager = Explicit<Node>>\nstruct SegtreeLazy : SegtreeImpl<Node,\
    \ NodeManager, CombinerFn, PushdownFn> {\n  typedef SegtreeImpl<Node, NodeManager,\
    \ CombinerFn, PushdownFn> Base;\n  using Base::SegtreeImpl;\n  using typename\
    \ Base::vnode;\n};\n} // namespace seg\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - SegtreeBeats.cpp
  - Segtree.cpp
  isVerificationFile: false
  path: SegtreeLazy.cpp
  requiredBy:
  - tests/judge/horrible.cpp
  timestamp: '2020-11-07 21:20:14-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegtreeLazy.cpp
layout: document
redirect_from:
- /library/SegtreeLazy.cpp
- /library/SegtreeLazy.cpp.html
title: SegtreeLazy.cpp
---
