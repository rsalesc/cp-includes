---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/line-add-get-min.test.cpp
    title: tests/yosupo/line-add-get-min.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/segment-add-get-min.test.cpp
    title: tests/yosupo/segment-add-get-min.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/LiChaoTree.cpp\"\n\n\n\n#include <bits/stdc++.h>\n\n\
    namespace lib {\nusing namespace std;\n\ntemplate <typename D, typename T> struct\
    \ LiChaoTree {\n  inline constexpr static T inf = numeric_limits<T>::max();\n\n\
    \  using Fn = function<T(D)>;\n  vector<Fn> fns;\n  vector<D> xs;\n  vector<int>\
    \ t;\n\n  template <typename U = D,\n            typename enable_if<is_integral<U>::value>::type\
    \ = nullptr>\n  LiChaoTree(D left, D right) {\n    assert(right > left);\n   \
    \ xs = vector<D>(right - left);\n    iota(xs.begin(), xs.end(), left);\n    init();\n\
    \  }\n\n  LiChaoTree(const vector<D>& xs_) : xs(xs_) {\n    sort(xs.begin(), xs.end());\n\
    \    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());\n    init();\n  }\n\
    \n  void init() {\n    t = vector<int>(xs.size() * 4);\n    fns.clear();\n   \
    \ fns.push_back([](D x) { return numeric_limits<T>::max(); });\n  }\n\n  void\
    \ add(const Fn &fn) {\n    int i = fns.size();\n    fns.push_back(fn);\n    add(i,\
    \ 1, 0, xs.size());\n  }\n\n  // r is exclusive\n  void add(int i, int no, int\
    \ l, int r) {\n    while (1) {\n      int mid = (l + r) / 2;\n      bool l_wins\
    \ = fns[i](xs[l]) < fns[t[no]](xs[l]);\n      bool r_wins = fns[i](xs[r-1]) <\
    \ fns[t[no]](xs[r-1]);\n      if (l_wins == r_wins) {\n        if (l_wins) swap(i,\
    \ t[no]);\n        return;\n      }\n      bool mid_wins = fns[i](xs[mid]) < fns[t[no]](xs[mid]);\n\
    \      if (mid_wins)\n        swap(i, t[no]);\n      if (l + 1 == r)\n       \
    \ return;\n      if (l_wins != mid_wins)\n        no = 2 * no, r = mid;\n    \
    \  else\n        no = 2 * no + 1, l = mid;\n    }\n  }\n\n  int seg_l, seg_r,\
    \ seg_idx;\n  void add_segment(int no, int l, int r) {\n    if (seg_l >= r ||\
    \ seg_r <= l) return;\n    if (seg_l <= l && r <= seg_r) add(seg_idx, no, l, r);\n\
    \    else {\n      int mid = (l+r)/2;\n      add_segment(2*no, l, mid);\n    \
    \  add_segment(2*no+1, mid, r);\n    }\n  }\n\n  void add_segment(const Fn& fn,\
    \ D a, D b) {\n    int i = fns.size();\n    fns.push_back(fn);\n    int l = lower_bound(xs.begin(),\
    \ xs.end(), a) - xs.begin();\n    int r = lower_bound(xs.begin(), xs.end(), b)\
    \ - xs.begin();\n    if (l == r) return;\n    seg_idx = i, seg_l = l, seg_r =\
    \ r;\n    add_segment(1, 0, xs.size());\n  }\n\n  T query(D x, int no, int l,\
    \ int r) const {\n    auto res = inf;\n    while (1) {\n      res = min(res, fns[t[no]](x));\n\
    \      if (l + 1 == r)\n        return res;\n      int mid = (l + r) / 2;\n  \
    \    if (x < xs[mid])\n        no = 2 * no, r = mid;\n      else\n        no =\
    \ 2 * no + 1, l = mid;\n    }\n  }\n\n  T query(D x) const { return query(x, 1,\
    \ 0, xs.size()); }\n};\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_LI_CHAO_TREE\n#define _LIB_LI_CHAO_TREE\n\n#include <bits/stdc++.h>\n\
    \nnamespace lib {\nusing namespace std;\n\ntemplate <typename D, typename T> struct\
    \ LiChaoTree {\n  inline constexpr static T inf = numeric_limits<T>::max();\n\n\
    \  using Fn = function<T(D)>;\n  vector<Fn> fns;\n  vector<D> xs;\n  vector<int>\
    \ t;\n\n  template <typename U = D,\n            typename enable_if<is_integral<U>::value>::type\
    \ = nullptr>\n  LiChaoTree(D left, D right) {\n    assert(right > left);\n   \
    \ xs = vector<D>(right - left);\n    iota(xs.begin(), xs.end(), left);\n    init();\n\
    \  }\n\n  LiChaoTree(const vector<D>& xs_) : xs(xs_) {\n    sort(xs.begin(), xs.end());\n\
    \    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());\n    init();\n  }\n\
    \n  void init() {\n    t = vector<int>(xs.size() * 4);\n    fns.clear();\n   \
    \ fns.push_back([](D x) { return numeric_limits<T>::max(); });\n  }\n\n  void\
    \ add(const Fn &fn) {\n    int i = fns.size();\n    fns.push_back(fn);\n    add(i,\
    \ 1, 0, xs.size());\n  }\n\n  // r is exclusive\n  void add(int i, int no, int\
    \ l, int r) {\n    while (1) {\n      int mid = (l + r) / 2;\n      bool l_wins\
    \ = fns[i](xs[l]) < fns[t[no]](xs[l]);\n      bool r_wins = fns[i](xs[r-1]) <\
    \ fns[t[no]](xs[r-1]);\n      if (l_wins == r_wins) {\n        if (l_wins) swap(i,\
    \ t[no]);\n        return;\n      }\n      bool mid_wins = fns[i](xs[mid]) < fns[t[no]](xs[mid]);\n\
    \      if (mid_wins)\n        swap(i, t[no]);\n      if (l + 1 == r)\n       \
    \ return;\n      if (l_wins != mid_wins)\n        no = 2 * no, r = mid;\n    \
    \  else\n        no = 2 * no + 1, l = mid;\n    }\n  }\n\n  int seg_l, seg_r,\
    \ seg_idx;\n  void add_segment(int no, int l, int r) {\n    if (seg_l >= r ||\
    \ seg_r <= l) return;\n    if (seg_l <= l && r <= seg_r) add(seg_idx, no, l, r);\n\
    \    else {\n      int mid = (l+r)/2;\n      add_segment(2*no, l, mid);\n    \
    \  add_segment(2*no+1, mid, r);\n    }\n  }\n\n  void add_segment(const Fn& fn,\
    \ D a, D b) {\n    int i = fns.size();\n    fns.push_back(fn);\n    int l = lower_bound(xs.begin(),\
    \ xs.end(), a) - xs.begin();\n    int r = lower_bound(xs.begin(), xs.end(), b)\
    \ - xs.begin();\n    if (l == r) return;\n    seg_idx = i, seg_l = l, seg_r =\
    \ r;\n    add_segment(1, 0, xs.size());\n  }\n\n  T query(D x, int no, int l,\
    \ int r) const {\n    auto res = inf;\n    while (1) {\n      res = min(res, fns[t[no]](x));\n\
    \      if (l + 1 == r)\n        return res;\n      int mid = (l + r) / 2;\n  \
    \    if (x < xs[mid])\n        no = 2 * no, r = mid;\n      else\n        no =\
    \ 2 * no + 1, l = mid;\n    }\n  }\n\n  T query(D x) const { return query(x, 1,\
    \ 0, xs.size()); }\n};\n} // namespace lib\n\n#endif"
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: ds/LiChaoTree.cpp
  requiredBy: []
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/segment-add-get-min.test.cpp
  - tests/yosupo/line-add-get-min.test.cpp
documentation_of: ds/LiChaoTree.cpp
layout: document
redirect_from:
- /library/ds/LiChaoTree.cpp
- /library/ds/LiChaoTree.cpp.html
title: ds/LiChaoTree.cpp
---
