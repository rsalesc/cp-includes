---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/FastList.cpp
    title: utils/FastList.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/chordal.test.cpp
    title: tests/yosupo/chordal.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graphs/Chordal.cpp\"\n\n\n#include <bits/stdc++.h>\n#line\
    \ 1 \"utils/FastList.cpp\"\n\n\n#line 4 \"utils/FastList.cpp\"\n\nnamespace lib\
    \ {\n  using namespace std;\nnamespace list {\ntemplate<typename T>\nstruct Node\
    \ {\n  T val;\n  Node *next = nullptr, *prev = nullptr;\n  Node() {}\n  Node(T\
    \ v) : val(v) {}\n\n  void clear_links() {\n    if(next != nullptr) next->prev\
    \ = prev;\n    if(prev != nullptr) prev->next = next;\n    next = prev = nullptr;\n\
    \  }\n};\n\ntemplate<typename T>\nvoid remove(Node<T>* no) {\n  if(no != nullptr)\
    \ no->clear_links();\n}\n\ntemplate<typename T>\nvoid append(Node<T>* no, Node<T>*\
    \ nw) {\n  assert(no != nullptr);\n  remove(nw);\n  if(no->next != nullptr) no->next->prev\
    \ = nw;\n  if(nw != nullptr) {\n    nw->next = no->next;\n    nw->prev = no;\n\
    \  }\n  no->next = nw;\n}\n\ntemplate<typename T>\nvoid prepend(Node<T>* no, Node<T>*\
    \ nw) {\n  assert(no != nullptr);\n  remove(nw);\n  if(no->prev != nullptr) no->prev->next\
    \ = nw;\n  if(nw != nullptr) {\n    nw->prev = no->prev;\n    nw->next = no;\n\
    \  }\n  no->prev = nw;\n}\n} // namespace list\n} // namespace lib\n\n\n#line\
    \ 5 \"graphs/Chordal.cpp\"\n\nnamespace lib {\n  using namespace std;\nnamespace\
    \ graph {\nnamespace {\n  using Elements = pair<vector<int>, int>;\n  using SetList\
    \ = lib::list::Node<Elements>;\n  shared_ptr<SetList> make_set_list(int n = 0)\
    \ {\n    return make_shared<SetList>(Elements(vector<int>(n), 0));\n  }\n}\n//\
    \ No parallel edges or self-loops.\ntemplate<typename Graph>\nvector<int> lex_bfs(const\
    \ Graph& g) {\n  int n = g.size();\n  vector<int> res(n);\n  vector<int> vis(n);\n\
    \  vector<pair<shared_ptr<SetList>, int>> inv(n);\n  auto data = make_set_list(n);\n\
    \  for(int i = 0; i < n; i++) {\n    data->val.first[i] = i;\n    inv[i] = make_pair(data,\
    \ i);\n  }\n\n  auto head = make_set_list();\n  list::append(head.get(), data.get());\n\
    \n  for(int i = 0; i < n; i++) {\n    auto no = head->next;\n    assert(no !=\
    \ nullptr);\n    assert(!no->val.first.empty());\n    const int u = res[i] = no->val.first.back();\n\
    \    no->val.first.pop_back();\n    if(no->val.first.empty()) list::remove(no);\n\
    \    vis[u] = 1;\n\n    // Partition\n    for(const auto& e : g.n_edges(u)) {\n\
    \      int v = e.to;\n      if(vis[v]) continue;\n      auto st = inv[v].first;\n\
    \      int sz = st->val.first.size();\n      if(sz == 1) continue;\n      auto\
    \ idx = inv[v].second;\n      swap(st->val.first[idx], st->val.first[sz - 1 -\
    \ st->val.second]);\n      swap(inv[v].second, inv[st->val.first[idx]].second);\n\
    \      st->val.second++;\n    }\n\n    for(const auto& e : g.n_edges(u)) {\n \
    \     int v = e.to;\n      if(vis[v]) continue;\n      auto st = inv[v].first;\n\
    \      int st_sz = st->val.first.size();\n      int size_new = st->val.second;\n\
    \      assert(size_new <= st_sz);\n      if(size_new == 0 || size_new == st_sz)\
    \ {\n        st->val.second = 0;\n        continue;\n      }\n      auto new_data\
    \ = make_set_list(size_new);\n      for(int i = 0; i < size_new; i++) {\n    \
    \    new_data->val.first[i] = st->val.first[st_sz - size_new + i];\n        inv[new_data->val.first[i]]\
    \ = {new_data, i};\n      }\n\n      st->val.first.resize(st_sz - size_new);\n\
    \      st->val.second = 0;\n\n      // both st and new_data should have size >\
    \ 0 at this point\n      list::prepend(st.get(), new_data.get());\n    }\n  }\n\
    \n  return res;\n}\n\ntemplate<typename Graph>\nstruct Chordal {\n  mutable vector<int>\
    \ vis, par;\n  mutable vector<int> cyc;\n\n  Graph g;\n  vector<int> order, inv;\n\
    \  mutable bool was_tested = false;\n  Chordal(Graph g) : g(g) {\n    order =\
    \ lex_bfs(g);\n    reverse(order.begin(), order.end());\n    int n = g.size();\n\
    \    inv = vector<int>(n);\n    for(int i = 0; i < n; i++) inv[order[i]] = i;\n\
    \  }\n\n  bool is_valid() const {\n    if(was_tested) return cyc.empty();\n  \
    \  int n = g.size();\n\n    vector<vector<int>> adj(n);\n    for(int i = 0; i\
    \ < n; i++) {\n      for(const auto& e : g.n_edges(i)) {\n        adj[i].push_back(e.to);\n\
    \      }\n      sort(adj[i].begin(), adj[i].end());\n    }\n\n    for(int k =\
    \ n-2; k >= 0; k--) {\n      int i = order[k];\n      pair<int, int> best = {1e9,\
    \ -1};\n      for(const auto& e : g.n_edges(i)) {\n        if(inv[e.to] > k)\n\
    \          best = min(best, {inv[e.to], e.to});\n      }\n      auto v = best.second;\n\
    \      if(v == -1) continue;\n      for(const auto& e : g.n_edges(i)) {\n    \
    \    if(inv[e.to] > inv[v])\n          if(!binary_search(adj[v].begin(), adj[v].end(),\
    \ e.to)) {\n            was_tested = true;\n            par.assign(n, -1), vis.assign(n,\
    \ 0);\n            queue<int> q;\n            vis[e.to] = 1;\n            q.push(e.to);\n\
    \            while(!q.empty()) {\n              int x = q.front(); q.pop();\n\
    \              for(const auto& e2 : g.n_edges(x)) {\n                int y = e2.to;\n\
    \                if(vis[y]) continue;\n                if(y == i) continue;\n\
    \                if(y != v && binary_search(adj[i].begin(), adj[i].end(), y))\
    \ continue;\n                vis[y] = 1;\n                q.push(y);\n       \
    \         par[y] = x;\n              }\n            }\n            cyc.clear();\n\
    \            cyc.push_back(e.to);\n            cyc.push_back(i);\n           \
    \ assert(vis[v]);\n            for(auto x = v; x != e.to; x = par[x]) cyc.push_back(x);\n\
    \            return false;\n          }\n      }\n    }\n    was_tested = true;\n\
    \    return true;\n  }\n\n  vector<int> induced_cycle() const { return cyc; }\n\
    \n  vector<int> max_independent_set() const {\n    int n = g.size();\n    vis.assign(n,\
    \ 0);\n\n    vector<int> res;\n    for(int i : order) {\n      if(vis[i]) continue;\n\
    \      res.push_back(i);\n      for(const auto& e : g.n_edges(i)) {\n        vis[e.to]\
    \ = 1;\n      }\n    }\n    return res;\n  }\n};\n\ntemplate<typename Graph>\n\
    Chordal<Graph> make_chordal(const Graph& g) {\n  return Chordal<Graph>(g);\n}\n\
    } // namespace graph\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_CHORDAL\n#define _LIB_CHORDAL\n#include <bits/stdc++.h>\n#include\
    \ \"../utils/FastList.cpp\"\n\nnamespace lib {\n  using namespace std;\nnamespace\
    \ graph {\nnamespace {\n  using Elements = pair<vector<int>, int>;\n  using SetList\
    \ = lib::list::Node<Elements>;\n  shared_ptr<SetList> make_set_list(int n = 0)\
    \ {\n    return make_shared<SetList>(Elements(vector<int>(n), 0));\n  }\n}\n//\
    \ No parallel edges or self-loops.\ntemplate<typename Graph>\nvector<int> lex_bfs(const\
    \ Graph& g) {\n  int n = g.size();\n  vector<int> res(n);\n  vector<int> vis(n);\n\
    \  vector<pair<shared_ptr<SetList>, int>> inv(n);\n  auto data = make_set_list(n);\n\
    \  for(int i = 0; i < n; i++) {\n    data->val.first[i] = i;\n    inv[i] = make_pair(data,\
    \ i);\n  }\n\n  auto head = make_set_list();\n  list::append(head.get(), data.get());\n\
    \n  for(int i = 0; i < n; i++) {\n    auto no = head->next;\n    assert(no !=\
    \ nullptr);\n    assert(!no->val.first.empty());\n    const int u = res[i] = no->val.first.back();\n\
    \    no->val.first.pop_back();\n    if(no->val.first.empty()) list::remove(no);\n\
    \    vis[u] = 1;\n\n    // Partition\n    for(const auto& e : g.n_edges(u)) {\n\
    \      int v = e.to;\n      if(vis[v]) continue;\n      auto st = inv[v].first;\n\
    \      int sz = st->val.first.size();\n      if(sz == 1) continue;\n      auto\
    \ idx = inv[v].second;\n      swap(st->val.first[idx], st->val.first[sz - 1 -\
    \ st->val.second]);\n      swap(inv[v].second, inv[st->val.first[idx]].second);\n\
    \      st->val.second++;\n    }\n\n    for(const auto& e : g.n_edges(u)) {\n \
    \     int v = e.to;\n      if(vis[v]) continue;\n      auto st = inv[v].first;\n\
    \      int st_sz = st->val.first.size();\n      int size_new = st->val.second;\n\
    \      assert(size_new <= st_sz);\n      if(size_new == 0 || size_new == st_sz)\
    \ {\n        st->val.second = 0;\n        continue;\n      }\n      auto new_data\
    \ = make_set_list(size_new);\n      for(int i = 0; i < size_new; i++) {\n    \
    \    new_data->val.first[i] = st->val.first[st_sz - size_new + i];\n        inv[new_data->val.first[i]]\
    \ = {new_data, i};\n      }\n\n      st->val.first.resize(st_sz - size_new);\n\
    \      st->val.second = 0;\n\n      // both st and new_data should have size >\
    \ 0 at this point\n      list::prepend(st.get(), new_data.get());\n    }\n  }\n\
    \n  return res;\n}\n\ntemplate<typename Graph>\nstruct Chordal {\n  mutable vector<int>\
    \ vis, par;\n  mutable vector<int> cyc;\n\n  Graph g;\n  vector<int> order, inv;\n\
    \  mutable bool was_tested = false;\n  Chordal(Graph g) : g(g) {\n    order =\
    \ lex_bfs(g);\n    reverse(order.begin(), order.end());\n    int n = g.size();\n\
    \    inv = vector<int>(n);\n    for(int i = 0; i < n; i++) inv[order[i]] = i;\n\
    \  }\n\n  bool is_valid() const {\n    if(was_tested) return cyc.empty();\n  \
    \  int n = g.size();\n\n    vector<vector<int>> adj(n);\n    for(int i = 0; i\
    \ < n; i++) {\n      for(const auto& e : g.n_edges(i)) {\n        adj[i].push_back(e.to);\n\
    \      }\n      sort(adj[i].begin(), adj[i].end());\n    }\n\n    for(int k =\
    \ n-2; k >= 0; k--) {\n      int i = order[k];\n      pair<int, int> best = {1e9,\
    \ -1};\n      for(const auto& e : g.n_edges(i)) {\n        if(inv[e.to] > k)\n\
    \          best = min(best, {inv[e.to], e.to});\n      }\n      auto v = best.second;\n\
    \      if(v == -1) continue;\n      for(const auto& e : g.n_edges(i)) {\n    \
    \    if(inv[e.to] > inv[v])\n          if(!binary_search(adj[v].begin(), adj[v].end(),\
    \ e.to)) {\n            was_tested = true;\n            par.assign(n, -1), vis.assign(n,\
    \ 0);\n            queue<int> q;\n            vis[e.to] = 1;\n            q.push(e.to);\n\
    \            while(!q.empty()) {\n              int x = q.front(); q.pop();\n\
    \              for(const auto& e2 : g.n_edges(x)) {\n                int y = e2.to;\n\
    \                if(vis[y]) continue;\n                if(y == i) continue;\n\
    \                if(y != v && binary_search(adj[i].begin(), adj[i].end(), y))\
    \ continue;\n                vis[y] = 1;\n                q.push(y);\n       \
    \         par[y] = x;\n              }\n            }\n            cyc.clear();\n\
    \            cyc.push_back(e.to);\n            cyc.push_back(i);\n           \
    \ assert(vis[v]);\n            for(auto x = v; x != e.to; x = par[x]) cyc.push_back(x);\n\
    \            return false;\n          }\n      }\n    }\n    was_tested = true;\n\
    \    return true;\n  }\n\n  vector<int> induced_cycle() const { return cyc; }\n\
    \n  vector<int> max_independent_set() const {\n    int n = g.size();\n    vis.assign(n,\
    \ 0);\n\n    vector<int> res;\n    for(int i : order) {\n      if(vis[i]) continue;\n\
    \      res.push_back(i);\n      for(const auto& e : g.n_edges(i)) {\n        vis[e.to]\
    \ = 1;\n      }\n    }\n    return res;\n  }\n};\n\ntemplate<typename Graph>\n\
    Chordal<Graph> make_chordal(const Graph& g) {\n  return Chordal<Graph>(g);\n}\n\
    } // namespace graph\n} // namespace lib\n\n#endif"
  dependsOn:
  - utils/FastList.cpp
  isVerificationFile: false
  path: graphs/Chordal.cpp
  requiredBy: []
  timestamp: '2021-02-13 23:55:16-03:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/chordal.test.cpp
documentation_of: graphs/Chordal.cpp
layout: document
redirect_from:
- /library/graphs/Chordal.cpp
- /library/graphs/Chordal.cpp.html
title: graphs/Chordal.cpp
---
