---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Segtree.cpp
    title: Segtree.cpp
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: RangeDSU.cpp
    title: RangeDSU.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"SegtreeFast.cpp\"\n\n\n#line 1 \"Segtree.cpp\"\n\n\n#include\
    \ <bits/stdc++.h>\n\nnamespace lib {\nusing namespace std;\nnamespace seg {\n\
    struct LeafBuilder {\n  template <typename Node> void operator()(Node &no, int\
    \ i) const {}\n  inline pair<int, int> range() const { return {0, 0}; }\n  bool\
    \ should_build() const { return true; }\n};\n\nstruct EmptyLeafBuilder : LeafBuilder\
    \ {\n  int n;\n  explicit EmptyLeafBuilder(int n) : n(n) {}\n  inline pair<int,\
    \ int> range() const { return {0, n - 1}; }\n  bool should_build() const { return\
    \ true; }\n};\n\nstruct ImplicitBuilder : LeafBuilder {\n  int L, R;\n  explicit\
    \ ImplicitBuilder(int L, int R) : L(L), R(R) {}\n  inline pair<int, int> range()\
    \ const { return {L, R}; }\n  bool should_build() const { return false; }\n};\n\
    \n// TODO: NOT IMPLEMENTED\ntemplate <typename DefaultNode>\nstruct ImplicitWithDefaultBuilder\
    \ : LeafBuilder {\n  int L, R;\n  DefaultNode default_node;\n  explicit ImplicitWithDefaultBuilder(int\
    \ L, int R, DefaultNode def)\n      : L(L), R(R), default_node(def) {}\n\n  template\
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
    \ no, int l, int r, \n                  Node* ln, Node* rn) const {}\n};\n\ntemplate<typename\
    \ Node>\nstruct Active : public Node {\n  bool active_ = false;\n  Active& operator=(const\
    \ Node& no) {\n    Node::operator=(no);\n    return *this;\n  }\n  bool is_active()\
    \ const { return active_; }\n  Active& activate() {\n    active_ = true;\n   \
    \ return *this;\n  }\n  Active& deactivate() {\n    active_ = false;\n    return\
    \ *this;\n  }\n  void toggle() {\n    active_ = !active_;\n  }\n  friend Active<Node>\
    \ operator+(const Active<Node>& a, const Active<Node>& b) {\n    if(!a.active_)\
    \ return b;\n    else if(!b.active_) return a;\n    Active<Node> res;\n    res\
    \ = Node(a) + Node(b);\n    return res.activate();\n  }\n};\n\ntemplate <typename\
    \ T>\nstruct ActiveUpdater {\n  bool flag;\n\n  ActiveUpdater(bool f) : flag(f)\
    \ {}\n\n  template <typename Node> inline void operator()(Node &no) const {\n\
    \    no.active_ = flag;\n  }\n};\n}  // namespace seg\n}  // namespace lib\n\n\
    \n#line 5 \"SegtreeFast.cpp\"\n\nnamespace lib {\nusing namespace std;\nnamespace\
    \ seg {\ntemplate <typename Node, typename CombinerFn> struct SegtreeFastBase\
    \ {\n  const static int MULTIPLIER = 2;\n\n  CombinerFn combiner_fn;\n\n  vector<Node>\
    \ t;\n  int L, n;\n\n  template <typename Builder> explicit SegtreeFastBase(const\
    \ Builder &builder) {\n    pair<int, int> range = builder.range();\n    L = range.first;\n\
    \    n = range.second - range.first + 1;\n    assert(n > 0);\n    t = vector<Node>(n\
    \ * MULTIPLIER);\n    build(builder);\n  }\n\n  template <typename Builder> void\
    \ build(const Builder &builder) {\n    for (int i = n; i < 2 * n; i++)\n     \
    \ builder(t[i], L + i - n);\n    for (int i = n - 1; i > 0; i--)\n      t[i] =\
    \ combiner_fn(t[i << 1], t[i << 1 | 1]);\n  }\n\n  template <typename Rebuilder>\
    \ void rebuild(const Rebuilder &rebuilder) {\n    for (int i = n; i < 2 * n; i++)\n\
    \      rebuilder(t[i]);\n    for (int i = n - 1; i > 0; i--)\n      rebuilder(t[i],\
    \ t[i << 1], t[i << 1 | 1]);\n  }\n};\n\ntemplate <typename Node, typename CombinerFn>\n\
    struct SegtreeFast : SegtreeFastBase<Node, CombinerFn> {\n  typedef SegtreeFastBase<Node,\
    \ CombinerFn> Base;\n  using Base::combiner_fn;\n  using Base::L;\n  using Base::n;\n\
    \  using Base::SegtreeFastBase;\n  using Base::t;\n\n  template <typename Updater>\n\
    \  void update_element(int i, const Updater &updater) {\n    i -= L;\n    assert(i\
    \ >= 0);\n    for (updater(t[i += n]); i /= 2;)\n      t[i] = combiner_fn(t[i\
    \ << 1], t[i << 1 | 1]);\n  }\n\n  template <typename T, typename Folder>\n  T\
    \ query(int i, int j, const Folder &folder) {\n    // input is [i, j]\n    i -=\
    \ L, j -= L;\n    assert(i >= 0 && j >= 0);\n    i += n, j += n;\n    if (i ==\
    \ j)\n      return folder(t[i]);\n    T resl = folder(t[i]), resr = folder(t[j]);\n\
    \n    // now it is [i, j)\n    i++;\n    while (i < j) {\n      if (i & 1)\n \
    \       resl = folder(resl, folder(t[i++]));\n      if (j & 1)\n        resr =\
    \ folder(folder(t[--j]), resr);\n      i /= 2, j /= 2;\n    }\n\n    return folder(resl,\
    \ resr);\n  }\n};\n\ntemplate <typename Node>\nstruct SegtreeFastSplash : SegtreeFastBase<Node,\
    \ EmptyFolder<Node>> {\n  typedef SegtreeFastBase<Node, EmptyFolder<Node>> Base;\n\
    \  using Base::L;\n  using Base::n;\n  using Base::SegtreeFastBase;\n  using Base::t;\n\
    \n  template <typename T, typename Folder>\n  T query_element(int i, const Folder\
    \ &folder) {\n    i -= L;\n    assert(i >= 0);\n    T res = folder(t[i += n]);\n\
    \    while (i /= 2) {\n      res = folder(folder(t[i]), res);\n    }\n    return\
    \ res;\n  }\n\n  template <typename Updater>\n  void splash(int i, int j, const\
    \ Updater &updater) {\n    // input is [i, j]\n    i -= L, j -= L;\n    assert(i\
    \ >= 0 && j >= 0);\n    // now it is [i, j)\n    i += n, j += n + 1;\n\n    while\
    \ (i < j) {\n      if (i & 1)\n        updater(t[i++]);\n      if (j & 1)\n  \
    \      updater(t[--j]);\n      i /= 2, j /= 2;\n    }\n  }\n};\n\n} // namespace\
    \ seg\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_SEGTREE_FAST\n#define _LIB_SEGTREE_FAST\n#include \"Segtree.cpp\"\
    \n#include <bits/stdc++.h>\n\nnamespace lib {\nusing namespace std;\nnamespace\
    \ seg {\ntemplate <typename Node, typename CombinerFn> struct SegtreeFastBase\
    \ {\n  const static int MULTIPLIER = 2;\n\n  CombinerFn combiner_fn;\n\n  vector<Node>\
    \ t;\n  int L, n;\n\n  template <typename Builder> explicit SegtreeFastBase(const\
    \ Builder &builder) {\n    pair<int, int> range = builder.range();\n    L = range.first;\n\
    \    n = range.second - range.first + 1;\n    assert(n > 0);\n    t = vector<Node>(n\
    \ * MULTIPLIER);\n    build(builder);\n  }\n\n  template <typename Builder> void\
    \ build(const Builder &builder) {\n    for (int i = n; i < 2 * n; i++)\n     \
    \ builder(t[i], L + i - n);\n    for (int i = n - 1; i > 0; i--)\n      t[i] =\
    \ combiner_fn(t[i << 1], t[i << 1 | 1]);\n  }\n\n  template <typename Rebuilder>\
    \ void rebuild(const Rebuilder &rebuilder) {\n    for (int i = n; i < 2 * n; i++)\n\
    \      rebuilder(t[i]);\n    for (int i = n - 1; i > 0; i--)\n      rebuilder(t[i],\
    \ t[i << 1], t[i << 1 | 1]);\n  }\n};\n\ntemplate <typename Node, typename CombinerFn>\n\
    struct SegtreeFast : SegtreeFastBase<Node, CombinerFn> {\n  typedef SegtreeFastBase<Node,\
    \ CombinerFn> Base;\n  using Base::combiner_fn;\n  using Base::L;\n  using Base::n;\n\
    \  using Base::SegtreeFastBase;\n  using Base::t;\n\n  template <typename Updater>\n\
    \  void update_element(int i, const Updater &updater) {\n    i -= L;\n    assert(i\
    \ >= 0);\n    for (updater(t[i += n]); i /= 2;)\n      t[i] = combiner_fn(t[i\
    \ << 1], t[i << 1 | 1]);\n  }\n\n  template <typename T, typename Folder>\n  T\
    \ query(int i, int j, const Folder &folder) {\n    // input is [i, j]\n    i -=\
    \ L, j -= L;\n    assert(i >= 0 && j >= 0);\n    i += n, j += n;\n    if (i ==\
    \ j)\n      return folder(t[i]);\n    T resl = folder(t[i]), resr = folder(t[j]);\n\
    \n    // now it is [i, j)\n    i++;\n    while (i < j) {\n      if (i & 1)\n \
    \       resl = folder(resl, folder(t[i++]));\n      if (j & 1)\n        resr =\
    \ folder(folder(t[--j]), resr);\n      i /= 2, j /= 2;\n    }\n\n    return folder(resl,\
    \ resr);\n  }\n};\n\ntemplate <typename Node>\nstruct SegtreeFastSplash : SegtreeFastBase<Node,\
    \ EmptyFolder<Node>> {\n  typedef SegtreeFastBase<Node, EmptyFolder<Node>> Base;\n\
    \  using Base::L;\n  using Base::n;\n  using Base::SegtreeFastBase;\n  using Base::t;\n\
    \n  template <typename T, typename Folder>\n  T query_element(int i, const Folder\
    \ &folder) {\n    i -= L;\n    assert(i >= 0);\n    T res = folder(t[i += n]);\n\
    \    while (i /= 2) {\n      res = folder(folder(t[i]), res);\n    }\n    return\
    \ res;\n  }\n\n  template <typename Updater>\n  void splash(int i, int j, const\
    \ Updater &updater) {\n    // input is [i, j]\n    i -= L, j -= L;\n    assert(i\
    \ >= 0 && j >= 0);\n    // now it is [i, j)\n    i += n, j += n + 1;\n\n    while\
    \ (i < j) {\n      if (i & 1)\n        updater(t[i++]);\n      if (j & 1)\n  \
    \      updater(t[--j]);\n      i /= 2, j /= 2;\n    }\n  }\n};\n\n} // namespace\
    \ seg\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - Segtree.cpp
  - bits/stdc++.h
  isVerificationFile: false
  path: SegtreeFast.cpp
  requiredBy:
  - RangeDSU.cpp
  timestamp: '2022-12-14 09:28:49-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegtreeFast.cpp
layout: document
redirect_from:
- /library/SegtreeFast.cpp
- /library/SegtreeFast.cpp.html
title: SegtreeFast.cpp
---
