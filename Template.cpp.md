---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/associative-array.test.cpp
    title: tests/yosupo/associative-array.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/biconnected-components.test.cpp
    title: tests/yosupo/biconnected-components.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/unionfind-with-compression.test.cpp
    title: tests/yosupo/unionfind-with-compression.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/unionfind.test.cpp
    title: tests/yosupo/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Template.cpp\"\n#include <bits/stdc++.h>\n#define int long\
    \ long\nusing namespace std;\n \n#define mp make_pair\n#define mt make_tuple\n\
    #define pb push_back\n#define ms(v, x) memset((v), (x), sizeof(v))\n#define all(v)\
    \ (v).begin(), (v).end()\n#define ff first\n#define ss second\n#define iopt ios::sync_with_stdio(false);\
    \ cin.tie(0)\n#define untie(p, a, b) decltype(p.first) a = p.first, decltype(p.second)\
    \ b = p.second\n#define TESTCASE(tn) cout << \"Case #\" << tn << \": \"\n \nint\
    \ gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }\n\nint floor2(int x,\
    \ int y);\nint ceil2(int x, int y) {\n  if(y < 0) return ceil2(-x, -y);\n  return\
    \ x < 0 ? -floor2(-x, y) : (x + y - 1) / y;\n}\nint floor2(int x, int y) {\n \
    \ if(y < 0) return floor2(-x, -y);\n  return x < 0 ? -ceil2(-x, y) : x / y;\n\
    }\n \ntypedef pair<int, int> ii;\ntypedef long double LD;\ntypedef vector<int>\
    \ vi;\n\n#define TC_MAIN int32_t main() { iopt; int T; cin >> T; for(int i = 1;\
    \ i <= T; i++) solve(i); }\n"
  code: "#include <bits/stdc++.h>\n#define int long long\nusing namespace std;\n \n\
    #define mp make_pair\n#define mt make_tuple\n#define pb push_back\n#define ms(v,\
    \ x) memset((v), (x), sizeof(v))\n#define all(v) (v).begin(), (v).end()\n#define\
    \ ff first\n#define ss second\n#define iopt ios::sync_with_stdio(false); cin.tie(0)\n\
    #define untie(p, a, b) decltype(p.first) a = p.first, decltype(p.second) b = p.second\n\
    #define TESTCASE(tn) cout << \"Case #\" << tn << \": \"\n \nint gcd(int a, int\
    \ b) { return b == 0 ? a : gcd(b, a%b); }\n\nint floor2(int x, int y);\nint ceil2(int\
    \ x, int y) {\n  if(y < 0) return ceil2(-x, -y);\n  return x < 0 ? -floor2(-x,\
    \ y) : (x + y - 1) / y;\n}\nint floor2(int x, int y) {\n  if(y < 0) return floor2(-x,\
    \ -y);\n  return x < 0 ? -ceil2(-x, y) : x / y;\n}\n \ntypedef pair<int, int>\
    \ ii;\ntypedef long double LD;\ntypedef vector<int> vi;\n\n#define TC_MAIN int32_t\
    \ main() { iopt; int T; cin >> T; for(int i = 1; i <= T; i++) solve(i); }"
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: Template.cpp
  requiredBy: []
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/unionfind.test.cpp
  - tests/yosupo/biconnected-components.test.cpp
  - tests/yosupo/associative-array.test.cpp
  - tests/yosupo/unionfind-with-compression.test.cpp
documentation_of: Template.cpp
layout: document
redirect_from:
- /library/Template.cpp
- /library/Template.cpp.html
title: Template.cpp
---
