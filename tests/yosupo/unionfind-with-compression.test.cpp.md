---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Template.cpp
    title: Template.cpp
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  - icon: ':heavy_check_mark:'
    path: dsu/Compress.cpp
    title: dsu/Compress.cpp
  - icon: ':heavy_check_mark:'
    path: dsu/DSU.cpp
    title: dsu/DSU.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"tests/yosupo/unionfind-with-compression.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#line 1 \"dsu/DSU.cpp\"\
    \n\n\n#include <bits/stdc++.h>\n\nnamespace lib {\nusing namespace std;\nnamespace\
    \ dsu {\nstruct RankDSU {\n  mutable vector<int> r, sz;\n  pair<int, int> last_merge_\
    \ = {-1, -1};\n  bool last_swapped_ = false;\n  int merges = 0;\n  RankDSU() {}\n\
    \  RankDSU(int n) : r(n), sz(n, 1) {\n    iota(r.begin(), r.end(), 0);\n  }\n\
    \  virtual void clear() {\n    iota(r.begin(), r.end(), 0);\n    fill(sz.begin(),\
    \ sz.end(), 1);\n    last_merge_ = {-1, -1};\n    merges = 0;\n  }\n  virtual\
    \ int get(int i) const {\n    return r[i] == i ? i : get(r[i]);\n  }\n  int operator[](int\
    \ i) const {\n    return get(i);\n  }\n  pair<int, int> last_merge() const {\n\
    \    return last_merge_;\n  }\n  int n_comps() const { return (int)r.size() -\
    \ merges; }\n  virtual void merged(int u, int v) {}\n  virtual int merge(int u,\
    \ int v) {\n    u = get(u), v = get(v);\n    if(u == v) return 0;\n    last_swapped_\
    \ = false;\n    if(sz[u] > sz[v]) swap(u, v), last_swapped_ = true;\n    r[u]\
    \ = v;\n    sz[v] += sz[u];\n    last_merge_ = {u, v};\n    merges++;\n    merged(u,\
    \ v);\n    return 1;\n  }\n};\n\ntemplate<template<class> class ...Ts>\nstruct\
    \ ByRankImpl;\n\ntemplate<template<class> class T, template<class> class ...Ts>\n\
    struct ByRankImpl<T, Ts...> {\n  using type = T<typename ByRankImpl<Ts...>::type>;\n\
    };\n\ntemplate<>\nstruct ByRankImpl<> {\n  using type = RankDSU;\n};\n\ntemplate<template<class>\
    \ class ...Ts>\nusing ByRank = typename ByRankImpl<Ts...>::type;\n} // namespace\
    \ dsu\n} // namespace lib\n\n\n\n#line 1 \"dsu/Compress.cpp\"\n\n\n#line 4 \"\
    dsu/Compress.cpp\"\n\nnamespace lib {\nusing namespace std;\nnamespace dsu {\n\
    \ntemplate<typename D>\nstruct Compress : public D {\n  using D::r;\n\n  Compress()\
    \ : D() {}\n  Compress(int n) : D(n) {}\n\n  virtual int get(int i) const override\
    \ {\n    return r[i] == i ? i : r[i] = get(r[i]);\n  }\n};\n} // namespace dsu\n\
    } // namespace lib\n\n\n\n#line 4 \"tests/yosupo/unionfind-with-compression.test.cpp\"\
    \n\n#line 2 \"Template.cpp\"\n#define int long long\nusing namespace std;\n \n\
    #define mp make_pair\n#define mt make_tuple\n#define pb push_back\n#define ms(v,\
    \ x) memset((v), (x), sizeof(v))\n#define all(v) (v).begin(), (v).end()\n#define\
    \ ff first\n#define ss second\n#define iopt ios::sync_with_stdio(false); cin.tie(0)\n\
    #define untie(p, a, b) decltype(p.first) a = p.first, decltype(p.second) b = p.second\n\
    \ \nint gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }\n \ntypedef pair<int,\
    \ int> ii;\ntypedef long double LD;\ntypedef vector<int> vi;\n#line 6 \"tests/yosupo/unionfind-with-compression.test.cpp\"\
    \n\nint32_t main() {\n  iopt;\n\n  int n, Q;\n  cin >> n >> Q;\n\n  using UF =\
    \ lib::dsu::ByRank<lib::dsu::Compress>;\n\n  UF uf(n);\n\n  for(int i = 0; i <\
    \ Q; i++) {\n    int t, a, b;\n    cin >> t >> a >> b;\n    if(t == 0) uf.merge(a,\
    \ b);\n    else cout << (int)(uf[a] == uf[b]) << endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    dsu/DSU.cpp\"\n#include \"dsu/Compress.cpp\"\n\n#include \"Template.cpp\"\n\n\
    int32_t main() {\n  iopt;\n\n  int n, Q;\n  cin >> n >> Q;\n\n  using UF = lib::dsu::ByRank<lib::dsu::Compress>;\n\
    \n  UF uf(n);\n\n  for(int i = 0; i < Q; i++) {\n    int t, a, b;\n    cin >>\
    \ t >> a >> b;\n    if(t == 0) uf.merge(a, b);\n    else cout << (int)(uf[a] ==\
    \ uf[b]) << endl;\n  }\n}"
  dependsOn:
  - dsu/DSU.cpp
  - bits/stdc++.h
  - dsu/Compress.cpp
  - Template.cpp
  isVerificationFile: true
  path: tests/yosupo/unionfind-with-compression.test.cpp
  requiredBy: []
  timestamp: '2023-02-21 13:50:33-03:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/yosupo/unionfind-with-compression.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/unionfind-with-compression.test.cpp
- /verify/tests/yosupo/unionfind-with-compression.test.cpp.html
title: tests/yosupo/unionfind-with-compression.test.cpp
---
