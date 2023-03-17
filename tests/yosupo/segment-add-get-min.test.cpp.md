---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  - icon: ':heavy_check_mark:'
    path: ds/LiChaoTree.cpp
    title: ds/LiChaoTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"tests/yosupo/segment-add-get-min.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\n#include <bits/stdc++.h>\n\
    #line 1 \"ds/LiChaoTree.cpp\"\n\n\n\n#line 5 \"ds/LiChaoTree.cpp\"\n\nnamespace\
    \ lib {\nusing namespace std;\n\ntemplate <typename D, typename T> struct LiChaoTree\
    \ {\n  inline constexpr static T inf = numeric_limits<T>::max();\n\n  using Fn\
    \ = function<T(D)>;\n  vector<Fn> fns;\n  vector<D> xs;\n  vector<int> t;\n\n\
    \  template <typename U = D,\n            typename enable_if<is_integral<U>::value>::type\
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
    \ 0, xs.size()); }\n};\n} // namespace lib\n\n\n#line 5 \"tests/yosupo/segment-add-get-min.test.cpp\"\
    \n#define int long long\nusing namespace std;\n \n#define mp make_pair\n#define\
    \ mt make_tuple\n#define pb push_back\n#define ms(v, x) memset((v), (x), sizeof(v))\n\
    #define all(v) (v).begin(), (v).end()\n#define ff first\n#define ss second\n#define\
    \ iopt ios::sync_with_stdio(false); cin.tie(0)\n#define untie(p, a, b) decltype(p.first)\
    \ a = p.first, decltype(p.second) b = p.second\n \nint gcd(int a, int b) { return\
    \ b == 0 ? a : gcd(b, a%b); }\nint power(int x, int p, int MOD) {\n    if(p ==\
    \ 0) return 1%MOD;\n    if(p == 1) return x%MOD;\n    int res = power(x, p/2,\
    \ MOD);\n    res = (long long)res*res%MOD;\n    if(p&1) res = (long long)res*x%MOD;\n\
    \    return res;\n}\n \ntypedef pair<int, int> ii;\ntypedef long double LD;\n\
    typedef vector<int> vi;\n\nstruct Query {\n  int type, a, b, l, r;\n};\n\nint32_t\
    \ main(){\n  iopt;\n  \n  int n, Q;\n  cin >> n >> Q;\n\n  vector<Query> queries;\n\
    \  vector<int> xs;\n\n  for(int i = 0; i < n; i++)  {\n    int a, b, l, r; cin\
    \ >> l >> r >> a >> b;\n    queries.push_back({0, a, b, l, r});\n  }\n\n  for(int\
    \ i = 0; i < Q; i++) {\n    int t; cin >> t;\n    if(t == 0) {\n      int a, b,\
    \ l, r; cin >> l >> r >> a >> b;\n      queries.push_back({t, a, b, l, r});\n\
    \    } else {\n      int x; cin >> x;\n      queries.push_back({t, x});\n    \
    \  xs.push_back(x);\n    }\n  }\n\n  lib::LiChaoTree<int, int> t(xs);\n\n  for(const\
    \ auto& q : queries) {\n    if (q.type == 0) {\n      t.add_segment([q](int x)\
    \ {\n        return q.a * x + q.b;\n      }, q.l, q.r);\n    } else {\n      auto\
    \ res = t.query(q.a);\n      if (res == decltype(t)::inf)\n        cout << \"\
    INFINITY\" << endl;\n      else\n        cout << res << endl;\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    \n#include <bits/stdc++.h>\n#include \"ds/LiChaoTree.cpp\"\n#define int long long\n\
    using namespace std;\n \n#define mp make_pair\n#define mt make_tuple\n#define\
    \ pb push_back\n#define ms(v, x) memset((v), (x), sizeof(v))\n#define all(v) (v).begin(),\
    \ (v).end()\n#define ff first\n#define ss second\n#define iopt ios::sync_with_stdio(false);\
    \ cin.tie(0)\n#define untie(p, a, b) decltype(p.first) a = p.first, decltype(p.second)\
    \ b = p.second\n \nint gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }\n\
    int power(int x, int p, int MOD) {\n    if(p == 0) return 1%MOD;\n    if(p ==\
    \ 1) return x%MOD;\n    int res = power(x, p/2, MOD);\n    res = (long long)res*res%MOD;\n\
    \    if(p&1) res = (long long)res*x%MOD;\n    return res;\n}\n \ntypedef pair<int,\
    \ int> ii;\ntypedef long double LD;\ntypedef vector<int> vi;\n\nstruct Query {\n\
    \  int type, a, b, l, r;\n};\n\nint32_t main(){\n  iopt;\n  \n  int n, Q;\n  cin\
    \ >> n >> Q;\n\n  vector<Query> queries;\n  vector<int> xs;\n\n  for(int i = 0;\
    \ i < n; i++)  {\n    int a, b, l, r; cin >> l >> r >> a >> b;\n    queries.push_back({0,\
    \ a, b, l, r});\n  }\n\n  for(int i = 0; i < Q; i++) {\n    int t; cin >> t;\n\
    \    if(t == 0) {\n      int a, b, l, r; cin >> l >> r >> a >> b;\n      queries.push_back({t,\
    \ a, b, l, r});\n    } else {\n      int x; cin >> x;\n      queries.push_back({t,\
    \ x});\n      xs.push_back(x);\n    }\n  }\n\n  lib::LiChaoTree<int, int> t(xs);\n\
    \n  for(const auto& q : queries) {\n    if (q.type == 0) {\n      t.add_segment([q](int\
    \ x) {\n        return q.a * x + q.b;\n      }, q.l, q.r);\n    } else {\n   \
    \   auto res = t.query(q.a);\n      if (res == decltype(t)::inf)\n        cout\
    \ << \"INFINITY\" << endl;\n      else\n        cout << res << endl;\n    }\n\
    \  }\n}\n"
  dependsOn:
  - bits/stdc++.h
  - ds/LiChaoTree.cpp
  isVerificationFile: true
  path: tests/yosupo/segment-add-get-min.test.cpp
  requiredBy: []
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/yosupo/segment-add-get-min.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/segment-add-get-min.test.cpp
- /verify/tests/yosupo/segment-add-get-min.test.cpp.html
title: tests/yosupo/segment-add-get-min.test.cpp
---