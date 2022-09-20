---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: SuffixArray.cpp
    title: SuffixArray.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"tests/yosupo/suffix-array.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/suffixarray\"\n\n#include <bits/stdc++.h>\n#line\
    \ 1 \"SuffixArray.cpp\"\n\n\n#line 4 \"SuffixArray.cpp\"\n\nnamespace lib {\n\
    using namespace std;\ntemplate<typename C>\nstruct SuffixArray {\n  int n, block;\n\
    \  vector<C> s;\n  vector<int> sa, rnk, tmp, aux, lcp_;\n  vector<vector<int>>\
    \ T;\n\n  void init(int h) {\n    h = max(h, n);\n    sa = vector<int>(h+3), rnk\
    \ = vector<int>(h+3),\n      tmp = vector<int>(h+3), aux = vector<int>(h+3),\n\
    \      lcp_ = vector<int>(h+3);\n    T = vector<vector<int>>(n + 3, vector<int>(__lg(n)\
    \ + 1));\n  }\n\n  SuffixArray(vector<C> s_) : s(s_), n(s_.size()) { build();\
    \ }\n  SuffixArray(string s_) {\n    s = vector<C>(s_.size());\n    n = s_.size();\n\
    \    for(int i = 0; i < n; i++) s[i] = s_[i];\n    build();\n  }\n\n  bool suffix_cmp(int\
    \ i, int j) {\n    if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];\n    i += block,\
    \ j += block;\n    if (i >= n) i -= n;\n    if (j >= n) j -= n;\n    return rnk[i]\
    \ < rnk[j];\n  }\n  void suffix_sort(int h) {\n    for (int i = 0; i < n; i++)\
    \ {\n      aux[i] = sa[i] - block;\n      if (aux[i] < 0) aux[i] += n;\n    }\n\
    \    for (int i = 0; i < h; i++) tmp[i] = 0;\n    for (int i = 0; i < n; i++)\
    \ tmp[rnk[aux[i]]]++;\n    for (int i = 0; i < h - 1; i++) tmp[i + 1] += tmp[i];\n\
    \    for (int i = n - 1; i >= 0; i--) sa[--tmp[rnk[aux[i]]]] = aux[i];\n    tmp[0]\
    \ = 0;\n    for (int i = 0; i < n - 1; i++) tmp[i + 1] = tmp[i] + suffix_cmp(sa[i],\
    \ sa[i + 1]);\n    for (int i = 0; i < n; i++) rnk[sa[i]] = tmp[i];\n  }\n  void\
    \ build() {\n    n++; // consider additional '\\0' character\n    s.push_back(0);\n\
    \    int h = (int)(*max_element(s.begin(), s.end())) + 1;\n    init(h);\n    for\
    \ (int i = 0; i < n; i++) sa[i] = i, rnk[i] = s[i], tmp[i] = 0;\n    block = 0;\n\
    \    suffix_sort(h);\n    for (block = 1; tmp[n - 1] != n - 1; block *= 2) suffix_sort(tmp[n\
    \ - 1] + 1);\n    n--;\n    sa.erase(sa.begin());\n    build_lcp_();\n  }\n\n\
    \  void build_lcp_() {\n\t\tfor (int i = 0; i < n; i++) rnk[sa[i]] = i, lcp_[i]\
    \ = 0;\n\t\tint last = 0; // last lcp_\n\t\tfor (int i = 0; i < n; i++, last =\
    \ max(lcp_[rnk[i - 1]] - 1, 0)) {\n\t\t\tif (rnk[i] == n - 1) continue;\n\t\t\t\
    int j = sa[rnk[i] + 1]; // next suffix pos in suffix array\n\t\t\twhile (i + last\
    \ < n && j + last < n && s[i + last] == s[j + last]) last++;\n\t\t\tlcp_[rnk[i]]\
    \ = last;\n\t\t}\n\n\t\tfor(int i = 0; i < n; i++)\n\t\t\tT[i][0] = lcp_[i];\n\
    \t\tfor(int j = 1; j < 20; j++){\n\t\t\tfor(int i = 0; i+(1<<j) <= n; i++){\n\t\
    \t\t\tT[i][j] = min(T[i][j-1], T[i+(1<<(j-1))][j-1]);\n\t\t\t}\n\t\t}\n\t}\n\n\
    \  int lcp(int i, int j){\n\t\tif(i > j) swap(i,j);\n\t\tif(i == j) return n-sa[i];\n\
    \    if(j == n) return 0;\n\n\t\tj--;\n\t\tint k = __builtin_clz(1) - __builtin_clz(j-i+1);\n\
    \t\treturn min(T[i][k], T[j-(1<<k)+1][k]);\n\t}\n\n  int operator[](int i) const\
    \ {\n    return sa[i];\n  }\n\n  int length(int i) const {\n    return n - sa[i];\n\
    \  }\n\n  int lcp(int i) const {\n    return lcp_[i];\n  }\n\n  pair<int,int>\
    \ range(int i, int sz){\n    pair<int, int> res;\n    {\n      int l = 0, r =\
    \ i+1;\n      while(l < r){\n        int mid = (l+r)/2;\n        if(lcp(mid, i)\
    \ >= sz) r = mid;\n        else l = mid+1;\n      }\n      res.first = l;\n  \
    \  }\n    {\n      int l = i, r = n-1;\n      while(l < r){\n        int mid =\
    \ (l+r+1)/2;\n        if(lcp(mid, i) >= sz) l = mid;\n        else r = mid-1;\n\
    \      }\n      res.second = l;\n    }\n    return res;\n  }\n\n  pair<int, int>\
    \ range(int i) {\n    return range(i, length(i));\n  }\n};\n} // namespace lib\n\
    \n\n#line 5 \"tests/yosupo/suffix-array.test.cpp\"\n#define int long long\nusing\
    \ namespace std;\n \n#define mp make_pair\n#define mt make_tuple\n#define pb push_back\n\
    #define ms(v, x) memset((v), (x), sizeof(v))\n#define all(v) (v).begin(), (v).end()\n\
    #define ff first\n#define ss second\n#define iopt ios::sync_with_stdio(false);\
    \ cin.tie(0)\n#define untie(p, a, b) decltype(p.first) a = p.first, decltype(p.second)\
    \ b = p.second\n \nint gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }\n\
    int power(int x, int p, int MOD) {\n    if(p == 0) return 1%MOD;\n    if(p ==\
    \ 1) return x%MOD;\n    int res = power(x, p/2, MOD);\n    res = (long long)res*res%MOD;\n\
    \    if(p&1) res = (long long)res*x%MOD;\n    return res;\n}\n \ntypedef pair<int,\
    \ int> ii;\ntypedef long double LD;\ntypedef vector<int> vi;\n\nint32_t main(){\n\
    \  iopt;\n  string s; cin >> s;\n\n  lib::SuffixArray<char> sa(s);\n\n  for(int\
    \ i = 0; i < s.size(); i++) cout << sa[i] << \" \";\n  cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#include\
    \ <bits/stdc++.h>\n#include \"SuffixArray.cpp\"\n#define int long long\nusing\
    \ namespace std;\n \n#define mp make_pair\n#define mt make_tuple\n#define pb push_back\n\
    #define ms(v, x) memset((v), (x), sizeof(v))\n#define all(v) (v).begin(), (v).end()\n\
    #define ff first\n#define ss second\n#define iopt ios::sync_with_stdio(false);\
    \ cin.tie(0)\n#define untie(p, a, b) decltype(p.first) a = p.first, decltype(p.second)\
    \ b = p.second\n \nint gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }\n\
    int power(int x, int p, int MOD) {\n    if(p == 0) return 1%MOD;\n    if(p ==\
    \ 1) return x%MOD;\n    int res = power(x, p/2, MOD);\n    res = (long long)res*res%MOD;\n\
    \    if(p&1) res = (long long)res*x%MOD;\n    return res;\n}\n \ntypedef pair<int,\
    \ int> ii;\ntypedef long double LD;\ntypedef vector<int> vi;\n\nint32_t main(){\n\
    \  iopt;\n  string s; cin >> s;\n\n  lib::SuffixArray<char> sa(s);\n\n  for(int\
    \ i = 0; i < s.size(); i++) cout << sa[i] << \" \";\n  cout << endl;\n}\n"
  dependsOn:
  - SuffixArray.cpp
  isVerificationFile: true
  path: tests/yosupo/suffix-array.test.cpp
  requiredBy: []
  timestamp: '2022-09-19 17:21:55-03:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/yosupo/suffix-array.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/suffix-array.test.cpp
- /verify/tests/yosupo/suffix-array.test.cpp.html
title: tests/yosupo/suffix-array.test.cpp
---
