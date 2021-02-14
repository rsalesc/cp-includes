---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graphs/Chordal.cpp
    title: graphs/Chordal.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/chordal.test.cpp
    title: tests/yosupo/chordal.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utils/FastList.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\n  using namespace std;\nnamespace list {\ntemplate<typename T>\nstruct\
    \ Node {\n  T val;\n  Node *next = nullptr, *prev = nullptr;\n  Node() {}\n  Node(T\
    \ v) : val(v) {}\n\n  void clear_links() {\n    if(next != nullptr) next->prev\
    \ = prev;\n    if(prev != nullptr) prev->next = next;\n    next = prev = nullptr;\n\
    \  }\n};\n\ntemplate<typename T>\nvoid remove(Node<T>* no) {\n  if(no != nullptr)\
    \ no->clear_links();\n}\n\ntemplate<typename T>\nvoid append(Node<T>* no, Node<T>*\
    \ nw) {\n  assert(no != nullptr);\n  remove(nw);\n  if(no->next != nullptr) no->next->prev\
    \ = nw;\n  if(nw != nullptr) {\n    nw->next = no->next;\n    nw->prev = no;\n\
    \  }\n  no->next = nw;\n}\n\ntemplate<typename T>\nvoid prepend(Node<T>* no, Node<T>*\
    \ nw) {\n  assert(no != nullptr);\n  remove(nw);\n  if(no->prev != nullptr) no->prev->next\
    \ = nw;\n  if(nw != nullptr) {\n    nw->prev = no->prev;\n    nw->next = no;\n\
    \  }\n  no->prev = nw;\n}\n} // namespace list\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_FAST_LIST\n#define _LIB_FAST_LIST\n#include <bits/stdc++.h>\n\
    \nnamespace lib {\n  using namespace std;\nnamespace list {\ntemplate<typename\
    \ T>\nstruct Node {\n  T val;\n  Node *next = nullptr, *prev = nullptr;\n  Node()\
    \ {}\n  Node(T v) : val(v) {}\n\n  void clear_links() {\n    if(next != nullptr)\
    \ next->prev = prev;\n    if(prev != nullptr) prev->next = next;\n    next = prev\
    \ = nullptr;\n  }\n};\n\ntemplate<typename T>\nvoid remove(Node<T>* no) {\n  if(no\
    \ != nullptr) no->clear_links();\n}\n\ntemplate<typename T>\nvoid append(Node<T>*\
    \ no, Node<T>* nw) {\n  assert(no != nullptr);\n  remove(nw);\n  if(no->next !=\
    \ nullptr) no->next->prev = nw;\n  if(nw != nullptr) {\n    nw->next = no->next;\n\
    \    nw->prev = no;\n  }\n  no->next = nw;\n}\n\ntemplate<typename T>\nvoid prepend(Node<T>*\
    \ no, Node<T>* nw) {\n  assert(no != nullptr);\n  remove(nw);\n  if(no->prev !=\
    \ nullptr) no->prev->next = nw;\n  if(nw != nullptr) {\n    nw->prev = no->prev;\n\
    \    nw->next = no;\n  }\n  no->prev = nw;\n}\n} // namespace list\n} // namespace\
    \ lib\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: utils/FastList.cpp
  requiredBy:
  - graphs/Chordal.cpp
  timestamp: '2021-02-13 23:55:16-03:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/chordal.test.cpp
documentation_of: utils/FastList.cpp
layout: document
redirect_from:
- /library/utils/FastList.cpp
- /library/utils/FastList.cpp.html
title: utils/FastList.cpp
---
