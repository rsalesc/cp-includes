---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy:
  - icon: ':warning:'
    path: matroid/CographicMatroid.cpp
    title: matroid/CographicMatroid.cpp
  - icon: ':warning:'
    path: matroid/GraphicMatroid.cpp
    title: matroid/GraphicMatroid.cpp
  - icon: ':warning:'
    path: matroid/MatroidIntersection.cpp
    title: matroid/MatroidIntersection.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utils/FastAdj.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\n  using namespace std;\ntemplate<typename T>\nstruct FastAdj {\n  int\
    \ n;\n  vector<T> edges;\n  vector<int> head, next;\n  FastAdj(int n, int cap\
    \ = 0) : n(n), edges(), head(), next() {\n    edges.reserve(cap);\n    next.reserve(cap);\n\
    \    head.assign(n, -1);\n  }\n  int size() const {\n    return n;\n  }\n  int\
    \ edge_size() const {\n    return edges.size();\n  }\n  void reserve(int c) {\n\
    \    edges.reserve(c);\n    next.reserve(c);\n  }\n  void clear() {\n    edges.clear();\n\
    \    next.clear();\n    head.assign(n, -1);\n  }\n  T& add(int u) {\n    int K\
    \ = edges.size();\n    next.push_back(head[u]);\n    head[u] = K;\n    edges.emplace_back();\n\
    \    return edges.back();\n  }\n  void add(int u, T v) {\n    int K = edges.size();\n\
    \    next.push_back(head[u]);\n    head[u] = K;\n    edges.push_back(v);\n  }\n\
    \n  class iterator {\n  public:\n    typedef iterator self_type;\n    typedef\
    \ T value_type;\n    typedef T &reference;\n    typedef T *pointer;\n    typedef\
    \ std::forward_iterator_tag iterator_category;\n    typedef int difference_type;\n\
    \    iterator(vector<int> *next, vector<T> *edges, int ptr)\n        : next_(next),\
    \ edges_(edges), ptr_(ptr) {}\n    self_type operator++() {\n      ptr_ = (*next_)[ptr_];\n\
    \      return *this;\n    }\n    self_type operator++(int junk) {\n      self_type\
    \ i = *this;\n      ptr_ = (*next_)[ptr_];\n      return i;\n    }\n    reference\
    \ operator*() { return (*edges_)[ptr_]; }\n    pointer operator->() { return &(*edges_)[ptr_];\
    \ }\n    bool operator==(const self_type &rhs) const {\n      return ptr_ == rhs.ptr_;\n\
    \    }\n    bool operator!=(const self_type &rhs) const { return !(*this == rhs);\
    \ }\n\n  private:\n    vector<int> *next_;\n    vector<T> *edges_;\n    int ptr_;\n\
    \  };\n\n  class const_iterator {\n  public:\n    typedef const_iterator self_type;\n\
    \    typedef T value_type;\n    typedef T &reference;\n    typedef T *pointer;\n\
    \    typedef std::forward_iterator_tag iterator_category;\n    typedef int difference_type;\n\
    \    const_iterator(vector<int> *next, vector<T> *edges, int ptr)\n        : next_(next_),\
    \ edges_(edges), ptr_(ptr) {}\n    self_type operator++() {\n      ptr_ = (*next_)[ptr_];\n\
    \      return *this;\n    }\n    self_type operator++(int junk) {\n      self_type\
    \ i = *this;\n      ptr_ = (*next_)[ptr_];\n      return i;\n    }\n    const\
    \ value_type &operator*() { return (*edges_)[ptr_]; }\n    const value_type *operator->()\
    \ { return &(*edges_)[ptr_]; }\n    bool operator==(const self_type &rhs) const\
    \ {\n      return ptr_ == rhs.ptr_;\n    }\n    bool operator!=(const self_type\
    \ &rhs) const { return !(*this == rhs); }\n\n  private:\n    vector<int> *next_;\n\
    \    vector<T> *edges_;\n    int ptr_;\n  };\n\n  struct iterable {\n    vector<int>\
    \ *next_;\n    vector<T> *edges_;\n    int head_;\n\n    iterable(vector<int>\
    \ *next, vector<T> *edges, int head)\n        : next_(next), edges_(edges), head_(head)\
    \ {}\n\n    inline iterator begin() { return iterator(next_, edges_, head_); }\n\
    \    inline iterator end() { return iterator(next_, edges_, -1); }\n\n    inline\
    \ const_iterator cbegin() const {\n      return const_iterator(next_, edges_,\
    \ head_);\n    }\n    inline const_iterator cend() const {\n      return const_iterator(next_,\
    \ edges_, -1);\n    }\n\n    inline const_iterator begin() const { return cbegin();\
    \ }\n    inline const_iterator end() const { return cend(); }\n  };\n\n  inline\
    \ iterable n_edges(int i) { return iterable(&next, &edges, head[i]); }\n  inline\
    \ const iterable n_edges(int i) const {\n    return iterable(const_cast<vector<int>\
    \ *>(&next),\n                    const_cast<vector<T> *>(&edges),\n         \
    \           head[i]);\n  }\n};\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_FAST_ADJ\n#define _LIB_FAST_ADJ\n#include <bits/stdc++.h>\n\n\
    namespace lib {\n  using namespace std;\ntemplate<typename T>\nstruct FastAdj\
    \ {\n  int n;\n  vector<T> edges;\n  vector<int> head, next;\n  FastAdj(int n,\
    \ int cap = 0) : n(n), edges(), head(), next() {\n    edges.reserve(cap);\n  \
    \  next.reserve(cap);\n    head.assign(n, -1);\n  }\n  int size() const {\n  \
    \  return n;\n  }\n  int edge_size() const {\n    return edges.size();\n  }\n\
    \  void reserve(int c) {\n    edges.reserve(c);\n    next.reserve(c);\n  }\n \
    \ void clear() {\n    edges.clear();\n    next.clear();\n    head.assign(n, -1);\n\
    \  }\n  T& add(int u) {\n    int K = edges.size();\n    next.push_back(head[u]);\n\
    \    head[u] = K;\n    edges.emplace_back();\n    return edges.back();\n  }\n\
    \  void add(int u, T v) {\n    int K = edges.size();\n    next.push_back(head[u]);\n\
    \    head[u] = K;\n    edges.push_back(v);\n  }\n\n  class iterator {\n  public:\n\
    \    typedef iterator self_type;\n    typedef T value_type;\n    typedef T &reference;\n\
    \    typedef T *pointer;\n    typedef std::forward_iterator_tag iterator_category;\n\
    \    typedef int difference_type;\n    iterator(vector<int> *next, vector<T> *edges,\
    \ int ptr)\n        : next_(next), edges_(edges), ptr_(ptr) {}\n    self_type\
    \ operator++() {\n      ptr_ = (*next_)[ptr_];\n      return *this;\n    }\n \
    \   self_type operator++(int junk) {\n      self_type i = *this;\n      ptr_ =\
    \ (*next_)[ptr_];\n      return i;\n    }\n    reference operator*() { return\
    \ (*edges_)[ptr_]; }\n    pointer operator->() { return &(*edges_)[ptr_]; }\n\
    \    bool operator==(const self_type &rhs) const {\n      return ptr_ == rhs.ptr_;\n\
    \    }\n    bool operator!=(const self_type &rhs) const { return !(*this == rhs);\
    \ }\n\n  private:\n    vector<int> *next_;\n    vector<T> *edges_;\n    int ptr_;\n\
    \  };\n\n  class const_iterator {\n  public:\n    typedef const_iterator self_type;\n\
    \    typedef T value_type;\n    typedef T &reference;\n    typedef T *pointer;\n\
    \    typedef std::forward_iterator_tag iterator_category;\n    typedef int difference_type;\n\
    \    const_iterator(vector<int> *next, vector<T> *edges, int ptr)\n        : next_(next_),\
    \ edges_(edges), ptr_(ptr) {}\n    self_type operator++() {\n      ptr_ = (*next_)[ptr_];\n\
    \      return *this;\n    }\n    self_type operator++(int junk) {\n      self_type\
    \ i = *this;\n      ptr_ = (*next_)[ptr_];\n      return i;\n    }\n    const\
    \ value_type &operator*() { return (*edges_)[ptr_]; }\n    const value_type *operator->()\
    \ { return &(*edges_)[ptr_]; }\n    bool operator==(const self_type &rhs) const\
    \ {\n      return ptr_ == rhs.ptr_;\n    }\n    bool operator!=(const self_type\
    \ &rhs) const { return !(*this == rhs); }\n\n  private:\n    vector<int> *next_;\n\
    \    vector<T> *edges_;\n    int ptr_;\n  };\n\n  struct iterable {\n    vector<int>\
    \ *next_;\n    vector<T> *edges_;\n    int head_;\n\n    iterable(vector<int>\
    \ *next, vector<T> *edges, int head)\n        : next_(next), edges_(edges), head_(head)\
    \ {}\n\n    inline iterator begin() { return iterator(next_, edges_, head_); }\n\
    \    inline iterator end() { return iterator(next_, edges_, -1); }\n\n    inline\
    \ const_iterator cbegin() const {\n      return const_iterator(next_, edges_,\
    \ head_);\n    }\n    inline const_iterator cend() const {\n      return const_iterator(next_,\
    \ edges_, -1);\n    }\n\n    inline const_iterator begin() const { return cbegin();\
    \ }\n    inline const_iterator end() const { return cend(); }\n  };\n\n  inline\
    \ iterable n_edges(int i) { return iterable(&next, &edges, head[i]); }\n  inline\
    \ const iterable n_edges(int i) const {\n    return iterable(const_cast<vector<int>\
    \ *>(&next),\n                    const_cast<vector<T> *>(&edges),\n         \
    \           head[i]);\n  }\n};\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: utils/FastAdj.cpp
  requiredBy:
  - matroid/CographicMatroid.cpp
  - matroid/GraphicMatroid.cpp
  - matroid/MatroidIntersection.cpp
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/FastAdj.cpp
layout: document
redirect_from:
- /library/utils/FastAdj.cpp
- /library/utils/FastAdj.cpp.html
title: utils/FastAdj.cpp
---
