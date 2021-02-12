---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/StaticRMQ.cpp
    title: ds/StaticRMQ.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"tests/yosupo/static-rmq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#include <bits/stdc++.h>\n#line 1 \"ds/StaticRMQ.cpp\"\n\n\n#line 4 \"ds/StaticRMQ.cpp\"\
    \n\nnamespace lib {\nusing namespace std;\nnamespace {\n  inline int lsb(int x)\
    \ { return x&-x; }\n}\n\n// Credits: hly1204\ntemplate<typename T, typename Cmp\
    \ = std::less<T>>\nstruct StaticRMQ {\n  Cmp cmp;\n  vector<T> t1, t2, a;\n\n\
    \  StaticRMQ(const vector<T>& a)\n    : t1(a.size() + 1), t2(a.size() + 1), a(a)\
    \ {\n    copy(a.begin(), a.end(), t1.begin() + 1);\n    copy(a.begin(), a.end(),\
    \ t2.begin() + 1);\n    build();\n  }\n\n  int size() const { return (int)t1.size()\
    \ - 1; }\n\n  void build() {\n    int n = size();\n    for(int i = 1; i <= n;\
    \ i++) {\n      int b = lsb(i);\n      if(i + b <= n) t1[i + b] = min(t1[i + b],\
    \ t1[i]);\n    }\n    for(int i = n; i; i--) {\n      int b = lsb(i);\n      t2[i\
    \ - b] = min(t2[i - b], t2[i]);\n    }\n  }\n\n  // [l, r], 0-indexed\n  T query(int\
    \ l, int r) const {\n    if(l == r) return a[l];\n    ++l, ++r;\n    T ans = min(a[l-1],\
    \ a[r-1]);\n    T x = l;\n    for(; x + lsb(x) - 1 <= r; x += lsb(x))\n      ans\
    \ = min(ans, t2[x]);\n    for(T y = r; y != 0 && y - lsb(y) + 1 >= l; y -= lsb(y))\n\
    \      ans = min(ans, t1[y]);\n    if(x <= r)\n      ans = min(ans, a[x-1]);\n\
    \    return ans;\n  }\n};\n} // namespace lib\n\n\n\n#line 5 \"tests/yosupo/static-rmq.test.cpp\"\
    \n#define int long long\nusing namespace std;\n \n#define mp make_pair\n#define\
    \ mt make_tuple\n#define pb push_back\n#define ms(v, x) memset((v), (x), sizeof(v))\n\
    #define all(v) (v).begin(), (v).end()\n#define ff first\n#define ss second\n#define\
    \ iopt ios::sync_with_stdio(false); cin.tie(0)\n#define untie(p, a, b) decltype(p.first)\
    \ a = p.first, decltype(p.second) b = p.second\n \nint gcd(int a, int b) { return\
    \ b == 0 ? a : gcd(b, a%b); }\nint power(int x, int p, int MOD) {\n    if(p ==\
    \ 0) return 1%MOD;\n    if(p == 1) return x%MOD;\n    int res = power(x, p/2,\
    \ MOD);\n    res = (long long)res*res%MOD;\n    if(p&1) res = (long long)res*x%MOD;\n\
    \    return res;\n}\n \ntypedef pair<int, int> ii;\ntypedef long double LD;\n\
    typedef vector<int> vi;\n\nusing namespace lib;\n\nint32_t main(){\n    // Scanner\
    \ sc(stdin);\n    // Printer pr(stdout);\n    iopt;\n\n    int n, Q;\n    cin\
    \ >> n >> Q;\n    vector<int> a(n);\n    for(int i = 0; i < n; i++) cin >> a[i];\n\
    \n    StaticRMQ<int> rmq(a);\n\n    while(Q--) {\n      int l, r;\n      cin >>\
    \ l >> r;\n      --r;\n      cout << rmq.query(l, r) << \"\\n\";\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <bits/stdc++.h>\n#include \"ds/StaticRMQ.cpp\"\n#define int long long\nusing\
    \ namespace std;\n \n#define mp make_pair\n#define mt make_tuple\n#define pb push_back\n\
    #define ms(v, x) memset((v), (x), sizeof(v))\n#define all(v) (v).begin(), (v).end()\n\
    #define ff first\n#define ss second\n#define iopt ios::sync_with_stdio(false);\
    \ cin.tie(0)\n#define untie(p, a, b) decltype(p.first) a = p.first, decltype(p.second)\
    \ b = p.second\n \nint gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }\n\
    int power(int x, int p, int MOD) {\n    if(p == 0) return 1%MOD;\n    if(p ==\
    \ 1) return x%MOD;\n    int res = power(x, p/2, MOD);\n    res = (long long)res*res%MOD;\n\
    \    if(p&1) res = (long long)res*x%MOD;\n    return res;\n}\n \ntypedef pair<int,\
    \ int> ii;\ntypedef long double LD;\ntypedef vector<int> vi;\n\nusing namespace\
    \ lib;\n\nint32_t main(){\n    // Scanner sc(stdin);\n    // Printer pr(stdout);\n\
    \    iopt;\n\n    int n, Q;\n    cin >> n >> Q;\n    vector<int> a(n);\n    for(int\
    \ i = 0; i < n; i++) cin >> a[i];\n\n    StaticRMQ<int> rmq(a);\n\n    while(Q--)\
    \ {\n      int l, r;\n      cin >> l >> r;\n      --r;\n      cout << rmq.query(l,\
    \ r) << \"\\n\";\n    }\n    return 0;\n}\n"
  dependsOn:
  - ds/StaticRMQ.cpp
  isVerificationFile: true
  path: tests/yosupo/static-rmq.test.cpp
  requiredBy: []
  timestamp: '2021-02-12 02:28:44-03:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/yosupo/static-rmq.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/static-rmq.test.cpp
- /verify/tests/yosupo/static-rmq.test.cpp.html
title: tests/yosupo/static-rmq.test.cpp
---
