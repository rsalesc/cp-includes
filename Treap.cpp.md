---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Random.cpp
    title: Random.cpp
  - icon: ':warning:'
    path: SegtreeImplicit.cpp
    title: SegtreeImplicit.cpp
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Treap.cpp\"\n\n\n#line 1 \"Random.cpp\"\n\n\n#include <bits/stdc++.h>\n\
    \nnamespace lib {\nusing namespace std;\nnamespace rng {\nstruct Generator {\n\
    \  mt19937 rng;\n  Generator() {\n    seed_seq seq {\n      (uint64_t) chrono::duration_cast<chrono::nanoseconds>(\n\
    \          chrono::high_resolution_clock::now().time_since_epoch())\n        \
    \  .count(),\n#if __cplusplus > 201300\n          (uint64_t)make_unique<char>().get(),\n\
    #else\n          (uint64_t)unique_ptr<char>(new char).get(),\n#endif\n       \
    \   (uint64_t)__builtin_ia32_rdtsc()\n    };\n    rng = mt19937(seq);\n  }\n \
    \ Generator(seed_seq &seq) : rng(seq) {}\n\n  template <typename T,\n        \
    \    typename enable_if<is_integral<T>::value>::type * = nullptr>\n  inline T\
    \ uniform_int(T L, T R) {\n    return uniform_int_distribution<T>(L, R)(rng);\n\
    \  }\n\n  template <typename T> inline T uniform_int(T N) {\n    return uniform_int(T(),\
    \ N - 1);\n  }\n\n  template <typename T> inline T uniform_real(T N) {\n    return\
    \ uniform_real(0.0, static_cast<double>(N));\n  }\n\n  template <typename T> inline\
    \ T uniform_real(T L, T R) {\n    return uniform_real_distribution<double>(static_cast<double>(L),\n\
    \                                             static_cast<double>(R))(rng);\n\
    \  }\n\n  inline double uniform_real() { return uniform_real(0.0, 1.0); }\n};\n\
    \nstatic Generator gen = Generator();\n} // namespace rng\nstatic rng::Generator\
    \ &rng_gen = rng::gen;\n} // namespace lib\n\n\n#line 1 \"SegtreeImplicit.cpp\"\
    \n\n\n#line 4 \"SegtreeImplicit.cpp\"\n\nnamespace lib {\nusing namespace std;\n\
    namespace seg {\n\ntemplate <typename Node> struct ImplicitNodeManager {\n  struct\
    \ NodeWrapper {\n    Node no;\n    NodeWrapper *left = nullptr;\n    NodeWrapper\
    \ *right = nullptr;\n  };\n\n  struct VirtualNode {\n    NodeWrapper *cur = nullptr,\
    \ **edge = nullptr;\n  };\n\n  typedef VirtualNode vnode;\n\n  vnode r = {new\
    \ NodeWrapper()};\n\n  template <typename Builder> void initialize(const Builder\
    \ &builder) {}\n\n  inline bool has(vnode no) const { return no.cur; }\n  inline\
    \ vnode root() { return r; }\n  inline vnode new_root(vnode no) { return r = no;\
    \ }\n  inline vnode left(vnode no) { return {no.cur->left, &(no.cur->left)}; }\n\
    \  inline vnode right(vnode no) { return {no.cur->right, &(no.cur->right)}; }\n\
    \  inline Node &ref(vnode no) { return no.cur->no; }\n  inline Node *ptr(vnode\
    \ no) { return &(no.cur->no); }\n  inline Node value(vnode no) { return no.cur->no;\
    \ }\n\n  inline vnode persist(vnode no) {\n    if (no.cur)\n      return no;\n\
    \    vnode res = no;\n    res.cur = *res.edge = new NodeWrapper();\n    return\
    \ res;\n  }\n  inline void ensure_left(vnode no) {\n    if (!no.cur->left)\n \
    \     no.cur->left = new NodeWrapper();\n  }\n  inline void ensure_right(vnode\
    \ no) {\n    if (!no.cur->right)\n      no.cur->right = new NodeWrapper();\n \
    \ }\n};\n\ntemplate <typename Node> using Implicit = ImplicitNodeManager<Node>;\n\
    } // namespace seg\n} // namespace lib\n\n\n#line 6 \"Treap.cpp\"\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace treap {\ntemplate <typename T> struct\
    \ SearchResult {\n  bool found;\n  T node;\n};\n\nstruct EmptyPushdown {\n  template\
    \ <typename Node>\n  inline void operator()(Node &no, Node *ln, Node *rn) const\
    \ {}\n};\n\nstruct EmptyCombiner {\n  template <typename Node>\n  inline void\
    \ operator()(Node &no, Node *ln, Node *rn) const {}\n};\n\ntemplate <typename\
    \ T, typename Less = std::less<T>> struct DefaultNode {\n  T key;\n  int y;\n\n\
    \  DefaultNode() {}\n  DefaultNode(T key)\n      : key(key), y(rng_gen.uniform_int(numeric_limits<int>::max()))\
    \ {}\n\n  inline bool operator<(const DefaultNode &rhs) const {\n    return Less()(key,\
    \ rhs.key);\n  }\n\n  inline int priority() const { return y; }\n\n  template\
    \ <typename Combiner>\n  inline static void combine(DefaultNode &no, DefaultNode\
    \ *ln, DefaultNode *rn,\n                             const Combiner &combiner)\
    \ {\n    combiner(no, ln, rn);\n  }\n};\n\ntemplate <typename T, typename Combiner\
    \ = EmptyCombiner,\n          typename Pushdown = EmptyPushdown, typename Less\
    \ = std::less<T>,\n          typename TreapNode = DefaultNode<T, Less>,\n    \
    \      template <class> class ManagerTemplate = seg::Implicit>\nstruct TreapManager\
    \ {\n  using NodeManager = ManagerTemplate<TreapNode>;\n  typedef TreapNode tnode;\n\
    \  typedef typename NodeManager::vnode vnode;\n\n  Combiner combiner_fn;\n  Pushdown\
    \ pushdown_fn;\n  NodeManager manager;\n\n  inline vnode make(T key) { return\
    \ manager.make(TreapNode(key)); }\n  inline vnode null() const { return manager.invalid();\
    \ }\n  inline void push(vnode no) {}\n  inline void update(vnode no) {\n    if\
    \ (!manager.has(no))\n      return;\n    combiner_fn(manager.ref(no), manager.ptr(manager.left(no)),\n\
    \                manager.ptr(manager.right(no)));\n  }\n\n  template <typename\
    \ Checker> bool check(vnode no, const Checker &checker) {\n    if (!manager.has(no))\n\
    \      return false;\n    return checker(manager.ref(no), manager.ptr(manager.left(no)),\n\
    \                   manager.ptr(manager.right(no)));\n  }\n\n  template <typename\
    \ Checker>\n  vnode bsearch_last_impl(vnode no, const Checker &checker) {\n  \
    \  push(no);\n    if (!manager.has(no))\n      return null();\n    if (check(manager.right(no),\
    \ checker))\n      return bsearch_last_impl(manager.right(no), checker);\n   \
    \ else if (check(no, checker))\n      return no;\n    else\n      return bsearch_last_impl(manager.left(no),\
    \ checker);\n  }\n\n  template <typename Folder, typename Checker>\n  vnode bsearch_last_impl(vnode\
    \ no, const Folder &folder,\n                          const Checker &checker)\
    \ {\n    push(no);\n    if (!manager.has(no))\n      return null();\n  }\n\n \
    \ template <typename Checker>\n  SearchResult<tnode> bsearch_last(vnode no, const\
    \ Checker &checker) {\n    auto res = bsearch_last_impl(no, checker);\n    if\
    \ (!manager.has(res))\n      return {false};\n    return {true, manager.value(res)};\n\
    \  }\n\n  vnode merge(vnode small, vnode large) {\n    push(small), push(large);\n\
    \    vnode res;\n    if (!manager.has(small))\n      res = manager.replace(small,\
    \ large);\n    else if (!manager.has(large))\n      res = manager.replace(large,\
    \ small);\n    else {\n      const auto &t_small = manager.ref(small);\n     \
    \ const auto &t_large = manager.ref(large);\n      if (t_small.priority() > t_large.priority())\
    \ {\n        res = manager.persist(small);\n        merge(manager.right(res),\
    \ large);\n      } else {\n        res = manager.persist(large);\n        merge(small,\
    \ manager.left(res));\n      }\n    }\n    update(res);\n    return res;\n  }\n\
    \n  template <typename Checker>\n  pair<vnode, vnode> split(vnode no, const Checker\
    \ &checker) {\n    push(no);\n    if (!manager.has(no))\n      return {null(),\
    \ null()};\n    pair<vnode, vnode> res;\n    no = manager.persist(no);\n    if\
    \ (check(no, checker)) {\n      auto sp = split(manager.right(no), checker);\n\
    \      manager.replace(manager.right(no), sp.first);\n      res = {no, sp.second};\n\
    \    } else {\n      auto sp = split(manager.left(no), checker);\n      manager.replace(manager.left(no),\
    \ sp.second);\n      res = {sp.first, no};\n    }\n    update(no);\n    return\
    \ res;\n  }\n\n  template <typename Checker>\n  pair<vnode, vnode> split_on_node(vnode\
    \ no, const Checker &checker) {\n    return split(no, [&checker](const TreapNode\
    \ &no, TreapNode *ln,\n                                TreapNode *rn) { return\
    \ checker(no); });\n  }\n\n  pair<vnode, vnode> split_on_key(vnode no, T x) {\n\
    \    return split_on_node(no, [&x](const TreapNode &no) { return no.key < x; });\n\
    \  }\n};\n} // namespace treap\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_TREAP\n#define _LIB_TREAP\n#include \"Random.cpp\"\n#include\
    \ \"SegtreeImplicit.cpp\"\n#include <bits/stdc++.h>\n\nnamespace lib {\nusing\
    \ namespace std;\nnamespace treap {\ntemplate <typename T> struct SearchResult\
    \ {\n  bool found;\n  T node;\n};\n\nstruct EmptyPushdown {\n  template <typename\
    \ Node>\n  inline void operator()(Node &no, Node *ln, Node *rn) const {}\n};\n\
    \nstruct EmptyCombiner {\n  template <typename Node>\n  inline void operator()(Node\
    \ &no, Node *ln, Node *rn) const {}\n};\n\ntemplate <typename T, typename Less\
    \ = std::less<T>> struct DefaultNode {\n  T key;\n  int y;\n\n  DefaultNode()\
    \ {}\n  DefaultNode(T key)\n      : key(key), y(rng_gen.uniform_int(numeric_limits<int>::max()))\
    \ {}\n\n  inline bool operator<(const DefaultNode &rhs) const {\n    return Less()(key,\
    \ rhs.key);\n  }\n\n  inline int priority() const { return y; }\n\n  template\
    \ <typename Combiner>\n  inline static void combine(DefaultNode &no, DefaultNode\
    \ *ln, DefaultNode *rn,\n                             const Combiner &combiner)\
    \ {\n    combiner(no, ln, rn);\n  }\n};\n\ntemplate <typename T, typename Combiner\
    \ = EmptyCombiner,\n          typename Pushdown = EmptyPushdown, typename Less\
    \ = std::less<T>,\n          typename TreapNode = DefaultNode<T, Less>,\n    \
    \      template <class> class ManagerTemplate = seg::Implicit>\nstruct TreapManager\
    \ {\n  using NodeManager = ManagerTemplate<TreapNode>;\n  typedef TreapNode tnode;\n\
    \  typedef typename NodeManager::vnode vnode;\n\n  Combiner combiner_fn;\n  Pushdown\
    \ pushdown_fn;\n  NodeManager manager;\n\n  inline vnode make(T key) { return\
    \ manager.make(TreapNode(key)); }\n  inline vnode null() const { return manager.invalid();\
    \ }\n  inline void push(vnode no) {}\n  inline void update(vnode no) {\n    if\
    \ (!manager.has(no))\n      return;\n    combiner_fn(manager.ref(no), manager.ptr(manager.left(no)),\n\
    \                manager.ptr(manager.right(no)));\n  }\n\n  template <typename\
    \ Checker> bool check(vnode no, const Checker &checker) {\n    if (!manager.has(no))\n\
    \      return false;\n    return checker(manager.ref(no), manager.ptr(manager.left(no)),\n\
    \                   manager.ptr(manager.right(no)));\n  }\n\n  template <typename\
    \ Checker>\n  vnode bsearch_last_impl(vnode no, const Checker &checker) {\n  \
    \  push(no);\n    if (!manager.has(no))\n      return null();\n    if (check(manager.right(no),\
    \ checker))\n      return bsearch_last_impl(manager.right(no), checker);\n   \
    \ else if (check(no, checker))\n      return no;\n    else\n      return bsearch_last_impl(manager.left(no),\
    \ checker);\n  }\n\n  template <typename Folder, typename Checker>\n  vnode bsearch_last_impl(vnode\
    \ no, const Folder &folder,\n                          const Checker &checker)\
    \ {\n    push(no);\n    if (!manager.has(no))\n      return null();\n  }\n\n \
    \ template <typename Checker>\n  SearchResult<tnode> bsearch_last(vnode no, const\
    \ Checker &checker) {\n    auto res = bsearch_last_impl(no, checker);\n    if\
    \ (!manager.has(res))\n      return {false};\n    return {true, manager.value(res)};\n\
    \  }\n\n  vnode merge(vnode small, vnode large) {\n    push(small), push(large);\n\
    \    vnode res;\n    if (!manager.has(small))\n      res = manager.replace(small,\
    \ large);\n    else if (!manager.has(large))\n      res = manager.replace(large,\
    \ small);\n    else {\n      const auto &t_small = manager.ref(small);\n     \
    \ const auto &t_large = manager.ref(large);\n      if (t_small.priority() > t_large.priority())\
    \ {\n        res = manager.persist(small);\n        merge(manager.right(res),\
    \ large);\n      } else {\n        res = manager.persist(large);\n        merge(small,\
    \ manager.left(res));\n      }\n    }\n    update(res);\n    return res;\n  }\n\
    \n  template <typename Checker>\n  pair<vnode, vnode> split(vnode no, const Checker\
    \ &checker) {\n    push(no);\n    if (!manager.has(no))\n      return {null(),\
    \ null()};\n    pair<vnode, vnode> res;\n    no = manager.persist(no);\n    if\
    \ (check(no, checker)) {\n      auto sp = split(manager.right(no), checker);\n\
    \      manager.replace(manager.right(no), sp.first);\n      res = {no, sp.second};\n\
    \    } else {\n      auto sp = split(manager.left(no), checker);\n      manager.replace(manager.left(no),\
    \ sp.second);\n      res = {sp.first, no};\n    }\n    update(no);\n    return\
    \ res;\n  }\n\n  template <typename Checker>\n  pair<vnode, vnode> split_on_node(vnode\
    \ no, const Checker &checker) {\n    return split(no, [&checker](const TreapNode\
    \ &no, TreapNode *ln,\n                                TreapNode *rn) { return\
    \ checker(no); });\n  }\n\n  pair<vnode, vnode> split_on_key(vnode no, T x) {\n\
    \    return split_on_node(no, [&x](const TreapNode &no) { return no.key < x; });\n\
    \  }\n};\n} // namespace treap\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - Random.cpp
  - bits/stdc++.h
  - SegtreeImplicit.cpp
  isVerificationFile: false
  path: Treap.cpp
  requiredBy: []
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Treap.cpp
layout: document
redirect_from:
- /library/Treap.cpp
- /library/Treap.cpp.html
title: Treap.cpp
---
