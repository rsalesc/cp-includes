---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph.cpp
    title: Graph.cpp
  - icon: ':heavy_check_mark:'
    path: Template.cpp
    title: Template.cpp
  - icon: ':question:'
    path: Traits.cpp
    title: Traits.cpp
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  - icon: ':heavy_check_mark:'
    path: graphs/BlockCut.cpp
    title: graphs/BlockCut.cpp
  - icon: ':heavy_check_mark:'
    path: utils/LazyArray.cpp
    title: utils/LazyArray.cpp
  - icon: ':heavy_check_mark:'
    path: utils/Wrappers.cpp
    title: utils/Wrappers.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/biconnected_components
    links:
    - https://judge.yosupo.jp/problem/biconnected_components
  bundledCode: "#line 1 \"tests/yosupo/biconnected-components.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/biconnected_components\"\n\n#line\
    \ 1 \"graphs/BlockCut.cpp\"\n\n\n#include <bits/stdc++.h>\n#line 1 \"Graph.cpp\"\
    \n\n\n#line 1 \"Traits.cpp\"\n\n\n#line 4 \"Traits.cpp\"\n\nnamespace lib {\n\
    using namespace std;\nnamespace traits {\n\ntemplate <typename...> struct make_void\
    \ { using type = void; };\n\ntemplate <typename... T> using void_t = typename\
    \ make_void<T...>::type;\n\n/// keep caide\ntemplate <typename Iterator>\nusing\
    \ IteratorCategory = typename iterator_traits<Iterator>::iterator_category;\n\n\
    /// keep caide\ntemplate <typename Container>\nusing IteratorCategoryOf = IteratorCategory<typename\
    \ Container::iterator>;\n\n/// keep caide\ntemplate <typename Iterator>\nusing\
    \ IteratorValue = typename iterator_traits<Iterator>::value_type;\n\n/// keep\
    \ caide\ntemplate <typename Container>\nusing IteratorValueOf = IteratorValue<typename\
    \ Container::iterator>;\n\n/// keep caide\ntemplate <typename Iterator>\nusing\
    \ IsRandomIterator =\n    is_base_of<random_access_iterator_tag, IteratorCategory<Iterator>>;\n\
    \n/// keep caide\ntemplate <typename Iterator>\nusing IsInputIterator =\n    is_base_of<input_iterator_tag,\
    \ IteratorCategory<Iterator>>;\n\n/// keep caide\ntemplate <typename Iterator>\n\
    using IsBidirectionalIterator =\n    is_base_of<bidirectional_iterator_tag, IteratorCategory<Iterator>>;\n\
    \n/// keep caide\ntemplate <typename Container>\nusing HasRandomIterator =\n \
    \   is_base_of<random_access_iterator_tag, IteratorCategoryOf<Container>>;\n\n\
    /// keep caide\ntemplate <typename Container>\nusing HasInputIterator =\n    is_base_of<input_iterator_tag,\
    \ IteratorCategoryOf<Container>>;\n\n/// keep caide\ntemplate <typename Container>\n\
    using HasBidirectionalIterator =\n    is_base_of<bidirectional_iterator_tag, IteratorCategoryOf<Container>>;\n\
    } // namespace traits\n} // namespace lib\n\n\n#line 1 \"utils/Wrappers.cpp\"\n\
    \n\n#line 4 \"utils/Wrappers.cpp\"\n\nnamespace lib {\nusing namespace std;\n\
    namespace graph {\ntemplate <typename T> struct Edge {\n  const int from, to;\n\
    \  T data;\n};\n\ntemplate <> struct Edge<void> { const int from, to; };\n\ntemplate\
    \ <typename T> struct VertexWrapper { T data; };\n\ntemplate <> struct VertexWrapper<void>\
    \ {};\n} // namespace graph\n} // namespace lib\n\n\n#line 6 \"Graph.cpp\"\n\n\
    namespace lib {\nusing namespace std;\nnamespace graph {\ntemplate <typename V\
    \ = void, typename E = void, bool Directed = false>\nstruct GraphImpl {\n  typedef\
    \ GraphImpl<V, E> self_type;\n  typedef vector<vector<int>> adj_list;\n  typedef\
    \ Edge<E> edge_type;\n  typedef VertexWrapper<V> vertex_type;\n\n  const static\
    \ bool directed = Directed;\n\n  vector<edge_type> edges;\n  adj_list adj;\n\n\
    \  vector<vertex_type> vertices;\n\n  class iterator {\n  public:\n    typedef\
    \ iterator self_type;\n    typedef edge_type value_type;\n    typedef edge_type\
    \ &reference;\n    typedef edge_type *pointer;\n    typedef std::forward_iterator_tag\
    \ iterator_category;\n    typedef int difference_type;\n    iterator(vector<int>\
    \ *adj, vector<edge_type> *edges, int ptr = 0)\n        : adj_(adj), edges_(edges),\
    \ ptr_(ptr) {}\n    self_type operator++() {\n      ptr_++;\n      return *this;\n\
    \    }\n    self_type operator++(int junk) {\n      self_type i = *this;\n   \
    \   ptr_++;\n      return i;\n    }\n    reference operator*() { return (*edges_)[(*adj_)[ptr_]];\
    \ }\n    pointer operator->() { return &(*edges_)[(*adj_)[ptr_]]; }\n    bool\
    \ operator==(const self_type &rhs) const {\n      return adj_ == rhs.adj_ && ptr_\
    \ == rhs.ptr_;\n    }\n    bool operator!=(const self_type &rhs) const { return\
    \ !(*this == rhs); }\n\n  private:\n    vector<int> *adj_;\n    vector<edge_type>\
    \ *edges_;\n    int ptr_;\n  };\n\n  class const_iterator {\n  public:\n    typedef\
    \ const_iterator self_type;\n    typedef edge_type value_type;\n    typedef edge_type\
    \ &reference;\n    typedef edge_type *pointer;\n    typedef std::forward_iterator_tag\
    \ iterator_category;\n    typedef int difference_type;\n    const_iterator(vector<int>\
    \ *adj, vector<edge_type> *edges, int ptr = 0)\n        : adj_(adj), edges_(edges),\
    \ ptr_(ptr) {}\n    self_type operator++() {\n      ptr_++;\n      return *this;\n\
    \    }\n    self_type operator++(int junk) {\n      self_type i = *this;\n   \
    \   ptr_++;\n      return i;\n    }\n    const value_type &operator*() { return\
    \ (*edges_)[(*adj_)[ptr_]]; }\n    const value_type *operator->() { return &(*edges_)[(*adj_)[ptr_]];\
    \ }\n    bool operator==(const self_type &rhs) const {\n      return adj_ == rhs.adj_\
    \ && ptr_ == rhs.ptr_;\n    }\n    bool operator!=(const self_type &rhs) const\
    \ { return !(*this == rhs); }\n\n  private:\n    vector<int> *adj_;\n    vector<edge_type>\
    \ *edges_;\n    int ptr_;\n  };\n\n  struct iterable {\n    vector<int> *adj_;\n\
    \    vector<edge_type> *edges_;\n\n    iterable(vector<int> *adj, vector<edge_type>\
    \ *edges)\n        : adj_(adj), edges_(edges) {}\n\n    inline iterator begin()\
    \ { return iterator(adj_, edges_); }\n    inline iterator end() { return iterator(adj_,\
    \ edges_, adj_->size()); }\n\n    inline const_iterator cbegin() const {\n   \
    \   return const_iterator(adj_, edges_);\n    }\n    inline const_iterator cend()\
    \ const {\n      return const_iterator(adj_, edges_, adj_->size());\n    }\n\n\
    \    inline const_iterator begin() const { return cbegin(); }\n    inline const_iterator\
    \ end() const { return cend(); }\n\n    inline edge_type &operator[](int i) {\
    \ return (*edges_)[(*adj_)[i]]; }\n    inline const edge_type &operator[](int\
    \ i) const {\n      return (*edges_)[(*adj_)[i]];\n    }\n\n    inline int index(int\
    \ i) const { return (*adj_)[i]; }\n    inline int size() const { return adj_->size();\
    \ }\n  };\n\n  GraphImpl() {}\n\n  template <typename S = V,\n            typename\
    \ enable_if<is_void<S>::value>::type * = nullptr>\n  GraphImpl(size_t n) : adj(n)\
    \ {}\n\n  template <typename S = V,\n            typename enable_if<!is_void<S>::value>::type\
    \ * = nullptr>\n  GraphImpl(size_t n) : adj(n), vertices(n) {}\n\n  inline iterable\
    \ n_edges(int i) { return iterable(&adj[i], &edges); }\n  inline const iterable\
    \ n_edges(int i) const {\n    return iterable(const_cast<vector<int> *>(&adj[i]),\n\
    \                    const_cast<vector<edge_type> *>(&edges));\n  }\n  inline\
    \ int degree(int i) const { return adj[i].size(); }\n\n  inline int size() const\
    \ { return adj.size(); }\n  inline int edge_size() const { return edges.size();\
    \ }\n  inline edge_type &edge(int i) { return edges[i]; }\n  inline edge_type\
    \ edge(int i) const { return edges[i]; }\n\n  inline vector<edge_type> all_edges()\
    \ const { return edges; }\n\n  template <typename S = V,\n            typename\
    \ enable_if<!is_void<S>::value>::type * = nullptr>\n  inline S &vertex(int i)\
    \ {\n    return vertices[i];\n  }\n\n  template <typename S = V,\n           \
    \ typename enable_if<!is_void<S>::value>::type * = nullptr>\n  inline V vertex(int\
    \ i) const {\n    return vertices[i];\n  }\n\n  template <typename S = V,\n  \
    \          typename enable_if<is_void<S>::value>::type * = nullptr>\n  inline\
    \ void add_vertex() {\n    adj.emplace_back();\n  }\n\n  template <typename S\
    \ = V,\n            typename enable_if<!is_void<S>::value>::type * = nullptr>\n\
    \  inline S &add_vertex() {\n    adj.emplace_back();\n    return vertices.emplace_back().data;\n\
    \  }\n\n  template <typename S = E,\n            typename enable_if<is_void<S>::value>::type\
    \ * = nullptr>\n  inline void add_edge_(int u, int v) {\n    adj[u].push_back(edges.size());\n\
    \    edges.push_back({u, v});\n  }\n\n  template <typename S = E,\n          \
    \  typename enable_if<!is_void<S>::value>::type * = nullptr>\n  inline S &add_edge_(int\
    \ u, int v) {\n    adj[u].push_back(edges.size());\n    edges.push_back({u, v});\n\
    \    return edges.back().data;\n  }\n\n  void add_2edge(int u, int v) {\n    add_edge_(u,\
    \ v);\n    add_edge_(v, u);\n  }\n\n  template <typename S = E,\n            typename\
    \ enable_if<!is_void<S>::value>::type * = nullptr>\n  inline void add_2edge(int\
    \ u, int v, const S &data) {\n    add_edge_(u, v) = data;\n    add_edge_(v, u)\
    \ = data;\n  }\n\n  template <typename S = E,\n            typename enable_if<is_void<S>::value\
    \ && Directed>::type * = nullptr>\n  inline void add_edge(int u, int v) {\n  \
    \  adj[u].push_back(edges.size());\n    edges.push_back({u, v});\n  }\n\n  template\
    \ <typename S = E,\n            typename enable_if<!is_void<S>::value && Directed>::type\
    \ * = nullptr>\n  inline S &add_edge(int u, int v) {\n    adj[u].push_back(edges.size());\n\
    \    edges.push_back({u, v});\n    return edges.back().data;\n  }\n};\n\ntemplate<typename\
    \ V = void, typename E = void>\nusing Graph = GraphImpl<V, E, false>;\n\ntemplate<typename\
    \ V = void, typename E = void>\nusing DirectedGraph = GraphImpl<V, E, true>;\n\
    \ntemplate <typename V = void, typename E = void>\nstruct RootedForest : public\
    \ DirectedGraph<V, E> {\n  typedef RootedForest<V, E> self_type;\n  using typename\
    \ DirectedGraph<V, E>::adj_list;\n  using typename DirectedGraph<V, E>::edge_type;\n\
    \  using DirectedGraph<V, E>::DirectedGraph;\n  using DirectedGraph<V, E>::adj;\n\
    \  using DirectedGraph<V, E>::edge;\n  vector<int> p, pe;\n\n  void build_parents()\
    \ {\n    if ((int)p.size() == this->size())\n      return;\n\n    int n = this->size();\n\
    \    stack<int> st;\n    vector<bool> vis(n);\n    p.assign(n, -1), pe.assign(n,\
    \ -1);\n    for (int i = 0; i < n; i++) {\n      if (!vis[i]) {\n        st.push(i);\n\
    \        vis[i] = true;\n        while (!st.empty()) {\n          int u = st.top();\n\
    \          st.pop();\n\n          for (int k : adj[u]) {\n            int v =\
    \ edge(k).to;\n            vis[v] = true;\n            st.push(v), pe[v] = k,\
    \ p[v] = u;\n          }\n        }\n      }\n    }\n  }\n\n  inline int parent(int\
    \ i) const {\n    const_cast<self_type *>(this)->build_parents();\n    return\
    \ p[i];\n  }\n\n  inline bool is_root(int i) const { return parent(i) != -1; }\n\
    \n  inline edge_type &parent_edge(int i) {\n    build_parents();\n    return edge(pe[i]);\n\
    \  }\n  inline edge_type &parent_edge(int i) const {\n    const_cast<self_type\
    \ *>(this)->build_parents();\n    return edge(pe[i]);\n  }\n\n  vector<int> roots()\
    \ const {\n    vector<int> res;\n    const_cast<self_type *>(this)->build_parents();\n\
    \    int n = this->size();\n\n    for (int i = 0; i < n; i++)\n      if (p[i]\
    \ == -1)\n        res.push_back(i);\n    return res;\n  }\n};\n\ntemplate <typename\
    \ V = void, typename E = void>\nstruct RootedTree : public RootedForest<V, E>\
    \ {\n  using typename RootedForest<V, E>::adj_list;\n  int root;\n\n  RootedTree(int\
    \ n, int root) : RootedForest<V, E>(n) {\n    assert(n > 0);\n    assert(root\
    \ < n);\n    this->root = root;\n  }\n\n  RootedTree(const adj_list &adj, int\
    \ root) : RootedForest<V, E>(adj) {\n    assert(adj.size() > 0);\n    assert(root\
    \ < adj.size());\n    this->root = root;\n  }\n};\n\nnamespace builders {\nnamespace\
    \ {\ntemplate <typename F, typename G>\nvoid dfs_rooted_forest(F &forest, const\
    \ G &graph, int u, vector<bool> &vis) {\n  vis[u] = true;\n  for (const auto &ed\
    \ : graph.n_edges(u)) {\n    int v = ed.to;\n    if (!vis[v]) {\n      forest.add_edge(u,\
    \ v);\n      dfs_rooted_forest(forest, graph, v, vis);\n    }\n  }\n}\n} // namespace\n\
    \ntemplate <typename A, typename B>\nRootedForest<A, B> make_rooted_forest(const\
    \ Graph<A, B> &graph,\n                                      const vector<int>\
    \ &roots) {\n  RootedForest<A, B> res(graph.size());\n  vector<bool> vis(graph.size());\n\
    \  for (int i : roots)\n    if (!vis[i])\n      dfs_rooted_forest(res, graph,\
    \ i, vis);\n  for (int i = 0; i < graph.size(); i++)\n    if (!vis[i])\n     \
    \ dfs_rooted_forest(res, graph, i, vis);\n  return res;\n}\n} // namespace builders\n\
    } // namespace graph\n} // namespace lib\n\n\n#line 1 \"utils/LazyArray.cpp\"\n\
    \n\n#line 4 \"utils/LazyArray.cpp\"\n\nnamespace lib {\n  using namespace std;\n\
    template<typename T>\nstruct LazyArray {\n  vector<T> v;\n  vector<int> lz;\n\
    \  T lz_v;\n  int tempo = 1;\n\n  LazyArray() {}\n  LazyArray(int n, T lz_v) :\
    \ v(n), lz(n), lz_v(lz_v) {}\n\n  int size() const { return v.size(); }\n  void\
    \ fill(T vv) { lz_v = vv, tempo++; }\n  void clear() {\n    fill(T());\n  }\n\
    \  T get(int i) const {\n    return tempo == lz[i] ? v[i] : lz_v;\n  }\n  T operator[](int\
    \ i) const {\n    return get(i);\n  }\n  T& operator[](int i) {\n    if(lz[i]\
    \ != tempo) {\n      lz[i] = tempo;\n      v[i] = lz_v;\n    }\n    return v[i];\n\
    \  }\n};\n} // namespace lib\n\n\n#line 6 \"graphs/BlockCut.cpp\"\n\nnamespace\
    \ lib {\n  using namespace std;\nnamespace graph {\ntemplate<typename V, typename\
    \ E>\nstruct BlockCut {\n  int n, m;\n  Graph<V, E> g;\n  int tempo = 0;\n  vector<int>\
    \ vis, low, seen;\n  vector<int> st;\n  LazyArray<char> seen_v;\n\n  Graph<V,\
    \ E> g2;\n  int n2 = 0;\n\n  BlockCut(const Graph<V, E>& g) : g(g) {\n    n =\
    \ g.size();\n    m = g.edge_size();\n    vis = low = vector<int>(n);\n    seen\
    \ = vector<int>(m);\n    st.reserve(m);\n    seen_v = LazyArray<char>(n, 0);\n\
    \n    g2 = Graph<V, E>(n);\n\n    for(int i = 0; i < n; i++) {\n      if(!vis[i])\
    \ {\n        tarjan(i, -1);\n        if (g.degree(i) == 0) {\n          // Vertex\
    \ is isolated, process separately.\n          g2.add_vertex();\n          g2.add_2edge(n\
    \ + n2, i);\n          n2++;\n        }\n      }\n    }\n  }\n  Graph<V, E> graph()\
    \ const { return g2; }\n\n  int n_components() const { return n2; }\n  vector<int>\
    \ component(int i) const {\n    vector<int> res;\n    for(const auto& v : g2.n_edges(n\
    \ + i))\n      if (v.to < n)\n        res.push_back(v.to);\n    return res;\n\
    \  }\n\n  vector<int> get_vertices_(const vector<int>& e) {\n    seen_v.clear();\n\
    \    vector<int> comp;\n    for(int kk : e) {\n      auto ed = g.edge(kk);\n \
    \     if(!seen_v.get(ed.from)) comp.push_back(ed.from), seen_v[ed.from] = true;\n\
    \      if(!seen_v.get(ed.to)) comp.push_back(ed.to), seen_v[ed.to] = true;\n \
    \   }\n    return comp;\n  }\n  void process_component_(int k) {\n    vector<int>\
    \ e;\n    int cur;\n    do {\n      cur = st.back(); st.pop_back();\n      e.push_back(cur);\n\
    \    } while(cur != k);\n    auto comp = get_vertices_(e);\n    g2.add_vertex();\n\
    \    for(int w : comp) {\n      g2.add_2edge(n + n2, w);\n    }\n    n2++;\n \
    \ }\n  void tarjan(int u, int p) {\n    vis[u] = low[u] = ++tempo;\n    auto nei\
    \ = g.n_edges(u);\n    for(int i = 0; i < nei.size(); i++) {\n      int k = nei.index(i);\n\
    \      int v = g.edge(k).to;\n\n      if(!seen[k]) {\n        seen[k] = seen[k^1]\
    \ = 1;\n        st.push_back(k);\n      }\n\n      if(!vis[v]) {\n        tarjan(v,\
    \ u);\n        low[u] = min(low[u], low[v]);\n\n        if(low[v] >= vis[u]) {\n\
    \          process_component_(k);\n        }\n      } else {\n        low[u] =\
    \ min(low[u], vis[v]);\n      }\n    }\n  }\n};\n\ntemplate<typename V, typename\
    \ E>\nBlockCut<V, E> make_block_cut(const Graph<V, E>& g) {\n  return BlockCut<V,\
    \ E>(g);\n}\n} // namespace graph\n} // namespace lib\n\n\n#line 2 \"Template.cpp\"\
    \n#define int long long\nusing namespace std;\n \n#define mp make_pair\n#define\
    \ mt make_tuple\n#define pb push_back\n#define ms(v, x) memset((v), (x), sizeof(v))\n\
    #define all(v) (v).begin(), (v).end()\n#define ff first\n#define ss second\n#define\
    \ iopt ios::sync_with_stdio(false); cin.tie(0)\n#define untie(p, a, b) decltype(p.first)\
    \ a = p.first, decltype(p.second) b = p.second\n#define TESTCASE(tn) cout << \"\
    Case #\" << tn << \": \"\n \nint gcd(int a, int b) { return b == 0 ? a : gcd(b,\
    \ a%b); }\n\nint floor2(int x, int y);\nint ceil2(int x, int y) {\n  if(y < 0)\
    \ return ceil2(-x, -y);\n  return x < 0 ? -floor2(-x, y) : (x + y - 1) / y;\n\
    }\nint floor2(int x, int y) {\n  if(y < 0) return floor2(-x, -y);\n  return x\
    \ < 0 ? -ceil2(-x, y) : x / y;\n}\n \ntypedef pair<int, int> ii;\ntypedef long\
    \ double LD;\ntypedef vector<int> vi;\n\n#define TC_MAIN int32_t main() { iopt;\
    \ int T; cin >> T; for(int i = 1; i <= T; i++) solve(i); }\n#line 5 \"tests/yosupo/biconnected-components.test.cpp\"\
    \n\nusing namespace lib;\n\nint32_t main() {\n  iopt;\n\n  int n, m; cin >> n\
    \ >> m;\n\n  graph::Graph<int> g(n);\n\n  for(int i = 0; i < m; i++) {\n    int\
    \ a, b;\n    cin >> a >> b;\n    g.add_2edge(a, b);\n  }\n\n  auto bct = graph::make_block_cut(g);\n\
    \n  cout << bct.n_components() << endl;\n  for(int i = 0; i < bct.n_components();\
    \ i++) {\n    const auto comp = bct.component(i);\n    cout << comp.size() <<\
    \ \" \";\n    for(const auto v : comp) cout << v << \" \";\n    cout << endl;\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/biconnected_components\"\
    \n\n#include \"graphs/BlockCut.cpp\"\n#include \"Template.cpp\"\n\nusing namespace\
    \ lib;\n\nint32_t main() {\n  iopt;\n\n  int n, m; cin >> n >> m;\n\n  graph::Graph<int>\
    \ g(n);\n\n  for(int i = 0; i < m; i++) {\n    int a, b;\n    cin >> a >> b;\n\
    \    g.add_2edge(a, b);\n  }\n\n  auto bct = graph::make_block_cut(g);\n\n  cout\
    \ << bct.n_components() << endl;\n  for(int i = 0; i < bct.n_components(); i++)\
    \ {\n    const auto comp = bct.component(i);\n    cout << comp.size() << \" \"\
    ;\n    for(const auto v : comp) cout << v << \" \";\n    cout << endl;\n  }\n}"
  dependsOn:
  - graphs/BlockCut.cpp
  - bits/stdc++.h
  - Graph.cpp
  - Traits.cpp
  - utils/Wrappers.cpp
  - utils/LazyArray.cpp
  - Template.cpp
  isVerificationFile: true
  path: tests/yosupo/biconnected-components.test.cpp
  requiredBy: []
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/yosupo/biconnected-components.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/biconnected-components.test.cpp
- /verify/tests/yosupo/biconnected-components.test.cpp.html
title: tests/yosupo/biconnected-components.test.cpp
---
