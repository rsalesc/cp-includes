---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: SegtreeImplicit.cpp
    title: SegtreeImplicit.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"SegtreePersistent.cpp\"\n\n\n#line 1 \"SegtreeImplicit.cpp\"\
    \n\n\n#include <bits/stdc++.h>\n\nnamespace lib {\nusing namespace std;\nnamespace\
    \ seg {\n\ntemplate <typename Node> struct ImplicitNodeManager {\n  struct NodeWrapper\
    \ {\n    Node no;\n    NodeWrapper *left = nullptr;\n    NodeWrapper *right =\
    \ nullptr;\n  };\n\n  struct VirtualNode {\n    NodeWrapper *cur = nullptr, **edge\
    \ = nullptr;\n  };\n\n  typedef VirtualNode vnode;\n\n  vnode r = {new NodeWrapper()};\n\
    \n  template <typename Builder> void initialize(const Builder &builder) {}\n\n\
    \  inline bool has(vnode no) const { return no.cur; }\n  inline vnode root() {\
    \ return r; }\n  inline vnode new_root(vnode no) { return r = no; }\n  inline\
    \ vnode left(vnode no) { return {no.cur->left, &(no.cur->left)}; }\n  inline vnode\
    \ right(vnode no) { return {no.cur->right, &(no.cur->right)}; }\n  inline Node\
    \ &ref(vnode no) { return no.cur->no; }\n  inline Node *ptr(vnode no) { return\
    \ &(no.cur->no); }\n  inline Node value(vnode no) { return no.cur->no; }\n\n \
    \ inline vnode persist(vnode no) {\n    if (no.cur)\n      return no;\n    vnode\
    \ res = no;\n    res.cur = *res.edge = new NodeWrapper();\n    return res;\n \
    \ }\n  inline void ensure_left(vnode no) {\n    if (!no.cur->left)\n      no.cur->left\
    \ = new NodeWrapper();\n  }\n  inline void ensure_right(vnode no) {\n    if (!no.cur->right)\n\
    \      no.cur->right = new NodeWrapper();\n  }\n};\n\ntemplate <typename Node>\
    \ using Implicit = ImplicitNodeManager<Node>;\n} // namespace seg\n} // namespace\
    \ lib\n\n\n#line 5 \"SegtreePersistent.cpp\"\n\nnamespace lib {\nusing namespace\
    \ std;\nnamespace seg {\n\ntemplate <typename Node>\nstruct PersistentNodeManager\
    \ : ImplicitNodeManager<Node> {\n  using typename ImplicitNodeManager<Node>::vnode;\n\
    \  using typename ImplicitNodeManager<Node>::NodeWrapper;\n\n  inline vnode persist(vnode\
    \ no) {\n    vnode res = no;\n    res.cur = no.cur ? new NodeWrapper(*no.cur)\
    \ : new NodeWrapper();\n    if (res.edge)\n      *res.edge = res.cur;\n    return\
    \ res;\n  }\n};\n\ntemplate <typename Node> using Persistent = PersistentNodeManager<Node>;\n\
    } // namespace seg\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_SEGTREE_PERSISTENT\n#define _LIB_SEGTREE_PERSISTENT\n#include\
    \ \"SegtreeImplicit.cpp\"\n#include <bits/stdc++.h>\n\nnamespace lib {\nusing\
    \ namespace std;\nnamespace seg {\n\ntemplate <typename Node>\nstruct PersistentNodeManager\
    \ : ImplicitNodeManager<Node> {\n  using typename ImplicitNodeManager<Node>::vnode;\n\
    \  using typename ImplicitNodeManager<Node>::NodeWrapper;\n\n  inline vnode persist(vnode\
    \ no) {\n    vnode res = no;\n    res.cur = no.cur ? new NodeWrapper(*no.cur)\
    \ : new NodeWrapper();\n    if (res.edge)\n      *res.edge = res.cur;\n    return\
    \ res;\n  }\n};\n\ntemplate <typename Node> using Persistent = PersistentNodeManager<Node>;\n\
    } // namespace seg\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - SegtreeImplicit.cpp
  isVerificationFile: false
  path: SegtreePersistent.cpp
  requiredBy: []
  timestamp: '2020-10-15 12:03:07-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegtreePersistent.cpp
layout: document
redirect_from:
- /library/SegtreePersistent.cpp
- /library/SegtreePersistent.cpp.html
title: SegtreePersistent.cpp
---
