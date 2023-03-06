---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/suffix-array.test.cpp
    title: tests/yosupo/suffix-array.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"SuffixArray.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\ntemplate<typename C>\nstruct SuffixArray {\n  int\
    \ n, block;\n  vector<C> s;\n  vector<int> sa, rnk, tmp, aux, lcp_;\n  vector<vector<int>>\
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
    \n\n"
  code: "#ifndef _LIB_SUFFIX_ARRAY\n#define _LIB_SUFFIX_ARRAY\n#include <bits/stdc++.h>\n\
    \nnamespace lib {\nusing namespace std;\ntemplate<typename C>\nstruct SuffixArray\
    \ {\n  int n, block;\n  vector<C> s;\n  vector<int> sa, rnk, tmp, aux, lcp_;\n\
    \  vector<vector<int>> T;\n\n  void init(int h) {\n    h = max(h, n);\n    sa\
    \ = vector<int>(h+3), rnk = vector<int>(h+3),\n      tmp = vector<int>(h+3), aux\
    \ = vector<int>(h+3),\n      lcp_ = vector<int>(h+3);\n    T = vector<vector<int>>(n\
    \ + 3, vector<int>(__lg(n) + 1));\n  }\n\n  SuffixArray(vector<C> s_) : s(s_),\
    \ n(s_.size()) { build(); }\n  SuffixArray(string s_) {\n    s = vector<C>(s_.size());\n\
    \    n = s_.size();\n    for(int i = 0; i < n; i++) s[i] = s_[i];\n    build();\n\
    \  }\n\n  bool suffix_cmp(int i, int j) {\n    if (rnk[i] != rnk[j]) return rnk[i]\
    \ < rnk[j];\n    i += block, j += block;\n    if (i >= n) i -= n;\n    if (j >=\
    \ n) j -= n;\n    return rnk[i] < rnk[j];\n  }\n  void suffix_sort(int h) {\n\
    \    for (int i = 0; i < n; i++) {\n      aux[i] = sa[i] - block;\n      if (aux[i]\
    \ < 0) aux[i] += n;\n    }\n    for (int i = 0; i < h; i++) tmp[i] = 0;\n    for\
    \ (int i = 0; i < n; i++) tmp[rnk[aux[i]]]++;\n    for (int i = 0; i < h - 1;\
    \ i++) tmp[i + 1] += tmp[i];\n    for (int i = n - 1; i >= 0; i--) sa[--tmp[rnk[aux[i]]]]\
    \ = aux[i];\n    tmp[0] = 0;\n    for (int i = 0; i < n - 1; i++) tmp[i + 1] =\
    \ tmp[i] + suffix_cmp(sa[i], sa[i + 1]);\n    for (int i = 0; i < n; i++) rnk[sa[i]]\
    \ = tmp[i];\n  }\n  void build() {\n    n++; // consider additional '\\0' character\n\
    \    s.push_back(0);\n    int h = (int)(*max_element(s.begin(), s.end())) + 1;\n\
    \    init(h);\n    for (int i = 0; i < n; i++) sa[i] = i, rnk[i] = s[i], tmp[i]\
    \ = 0;\n    block = 0;\n    suffix_sort(h);\n    for (block = 1; tmp[n - 1] !=\
    \ n - 1; block *= 2) suffix_sort(tmp[n - 1] + 1);\n    n--;\n    sa.erase(sa.begin());\n\
    \    build_lcp_();\n  }\n\n  void build_lcp_() {\n\t\tfor (int i = 0; i < n; i++)\
    \ rnk[sa[i]] = i, lcp_[i] = 0;\n\t\tint last = 0; // last lcp_\n\t\tfor (int i\
    \ = 0; i < n; i++, last = max(lcp_[rnk[i - 1]] - 1, 0)) {\n\t\t\tif (rnk[i] ==\
    \ n - 1) continue;\n\t\t\tint j = sa[rnk[i] + 1]; // next suffix pos in suffix\
    \ array\n\t\t\twhile (i + last < n && j + last < n && s[i + last] == s[j + last])\
    \ last++;\n\t\t\tlcp_[rnk[i]] = last;\n\t\t}\n\n\t\tfor(int i = 0; i < n; i++)\n\
    \t\t\tT[i][0] = lcp_[i];\n\t\tfor(int j = 1; j < 20; j++){\n\t\t\tfor(int i =\
    \ 0; i+(1<<j) <= n; i++){\n\t\t\t\tT[i][j] = min(T[i][j-1], T[i+(1<<(j-1))][j-1]);\n\
    \t\t\t}\n\t\t}\n\t}\n\n  int lcp(int i, int j){\n\t\tif(i > j) swap(i,j);\n\t\t\
    if(i == j) return n-sa[i];\n    if(j == n) return 0;\n\n\t\tj--;\n\t\tint k =\
    \ __builtin_clz(1) - __builtin_clz(j-i+1);\n\t\treturn min(T[i][k], T[j-(1<<k)+1][k]);\n\
    \t}\n\n  int operator[](int i) const {\n    return sa[i];\n  }\n\n  int length(int\
    \ i) const {\n    return n - sa[i];\n  }\n\n  int lcp(int i) const {\n    return\
    \ lcp_[i];\n  }\n\n  pair<int,int> range(int i, int sz){\n    pair<int, int> res;\n\
    \    {\n      int l = 0, r = i+1;\n      while(l < r){\n        int mid = (l+r)/2;\n\
    \        if(lcp(mid, i) >= sz) r = mid;\n        else l = mid+1;\n      }\n  \
    \    res.first = l;\n    }\n    {\n      int l = i, r = n-1;\n      while(l <\
    \ r){\n        int mid = (l+r+1)/2;\n        if(lcp(mid, i) >= sz) l = mid;\n\
    \        else r = mid-1;\n      }\n      res.second = l;\n    }\n    return res;\n\
    \  }\n\n  pair<int, int> range(int i) {\n    return range(i, length(i));\n  }\n\
    };\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: SuffixArray.cpp
  requiredBy: []
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/suffix-array.test.cpp
documentation_of: SuffixArray.cpp
layout: document
redirect_from:
- /library/SuffixArray.cpp
- /library/SuffixArray.cpp.html
title: SuffixArray.cpp
---
