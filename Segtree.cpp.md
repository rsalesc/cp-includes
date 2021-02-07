---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: HLD.cpp
    title: HLD.cpp
  - icon: ':warning:'
    path: SegtreeBeats.cpp
    title: SegtreeBeats.cpp
  - icon: ':warning:'
    path: SegtreeFast.cpp
    title: SegtreeFast.cpp
  - icon: ':warning:'
    path: SegtreeHLD.cpp
    title: SegtreeHLD.cpp
  - icon: ':warning:'
    path: SegtreeLazy.cpp
    title: SegtreeLazy.cpp
  - icon: ':warning:'
    path: SegtreeNormal.cpp
    title: SegtreeNormal.cpp
  - icon: ':warning:'
    path: SegtreeSplash.cpp
    title: SegtreeSplash.cpp
  - icon: ':warning:'
    path: tests/judge/child.cpp
    title: tests/judge/child.cpp
  - icon: ':warning:'
    path: tests/judge/concat.cpp
    title: tests/judge/concat.cpp
  - icon: ':warning:'
    path: tests/judge/gorgonzola.cpp
    title: tests/judge/gorgonzola.cpp
  - icon: ':warning:'
    path: tests/judge/hld.cpp
    title: tests/judge/hld.cpp
  - icon: ':warning:'
    path: tests/judge/horrible.cpp
    title: tests/judge/horrible.cpp
  - icon: ':warning:'
    path: tests/judge/minimos.cpp
    title: tests/judge/minimos.cpp
  - icon: ':warning:'
    path: tests/judge/mkthnum.cpp
    title: tests/judge/mkthnum.cpp
  - icon: ':warning:'
    path: tests/judge/mkthnum_jonas.cpp
    title: tests/judge/mkthnum_jonas.cpp
  - icon: ':warning:'
    path: tests/judge/psegtree.cpp
    title: tests/judge/psegtree.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Segtree.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace seg {\nstruct LeafBuilder {\n  template\
    \ <typename Node> void operator()(Node &no, int i) const {}\n  inline pair<int,\
    \ int> range() const { return {0, 0}; }\n  bool should_build() const { return\
    \ true; }\n};\n\nstruct EmptyLeafBuilder : LeafBuilder {\n  int n;\n  explicit\
    \ EmptyLeafBuilder(int n) : n(n) {}\n  inline pair<int, int> range() const { return\
    \ {0, n - 1}; }\n  bool should_build() const { return true; }\n};\n\nstruct ImplicitBuilder\
    \ : LeafBuilder {\n  int L, R;\n  explicit ImplicitBuilder(int L, int R) : L(L),\
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
    \ namespace seg\n}  // namespace lib\n\n\n"
  code: "#ifndef _LIB_SEGTREE\n#define _LIB_SEGTREE\n#include <bits/stdc++.h>\n\n\
    namespace lib {\nusing namespace std;\nnamespace seg {\nstruct LeafBuilder {\n\
    \  template <typename Node> void operator()(Node &no, int i) const {}\n  inline\
    \ pair<int, int> range() const { return {0, 0}; }\n  bool should_build() const\
    \ { return true; }\n};\n\nstruct EmptyLeafBuilder : LeafBuilder {\n  int n;\n\
    \  explicit EmptyLeafBuilder(int n) : n(n) {}\n  inline pair<int, int> range()\
    \ const { return {0, n - 1}; }\n  bool should_build() const { return true; }\n\
    };\n\nstruct ImplicitBuilder : LeafBuilder {\n  int L, R;\n  explicit ImplicitBuilder(int\
    \ L, int R) : L(L), R(R) {}\n  inline pair<int, int> range() const { return {L,\
    \ R}; }\n  bool should_build() const { return false; }\n};\n\n// TODO: NOT IMPLEMENTED\n\
    template <typename DefaultNode>\nstruct ImplicitWithDefaultBuilder : LeafBuilder\
    \ {\n  int L, R;\n  DefaultNode default_node;\n  explicit ImplicitWithDefaultBuilder(int\
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
    \ no, int l, int r, \n                  Node* ln, Node* rn) const {}\n};\n}  //\
    \ namespace seg\n}  // namespace lib\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: Segtree.cpp
  requiredBy:
  - SegtreeHLD.cpp
  - SegtreeLazy.cpp
  - SegtreeBeats.cpp
  - SegtreeSplash.cpp
  - SegtreeFast.cpp
  - HLD.cpp
  - SegtreeNormal.cpp
  - tests/judge/concat.cpp
  - tests/judge/mkthnum.cpp
  - tests/judge/minimos.cpp
  - tests/judge/hld.cpp
  - tests/judge/gorgonzola.cpp
  - tests/judge/child.cpp
  - tests/judge/psegtree.cpp
  - tests/judge/mkthnum_jonas.cpp
  - tests/judge/horrible.cpp
  timestamp: '2020-10-16 14:02:48-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Segtree.cpp
layout: document
redirect_from:
- /library/Segtree.cpp
- /library/Segtree.cpp.html
title: Segtree.cpp
---
