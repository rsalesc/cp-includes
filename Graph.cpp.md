---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Traits.cpp
    title: Traits.cpp
  - icon: ':heavy_check_mark:'
    path: utils/Wrappers.cpp
    title: utils/Wrappers.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: HLD.cpp
    title: HLD.cpp
  - icon: ':warning:'
    path: Maxflow.cpp
    title: Maxflow.cpp
  - icon: ':warning:'
    path: SegtreeHLD.cpp
    title: SegtreeHLD.cpp
  - icon: ':heavy_check_mark:'
    path: TwoSat.cpp
    title: TwoSat.cpp
  - icon: ':heavy_check_mark:'
    path: graphs/BlockCut.cpp
    title: graphs/BlockCut.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/2sat.test.cpp
    title: tests/yosupo/2sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/biconnected-components.test.cpp
    title: tests/yosupo/biconnected-components.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/chordal.test.cpp
    title: tests/yosupo/chordal.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph.cpp\"\n\n\n#line 1 \"Traits.cpp\"\n\n\n#include <bits/stdc++.h>\n\
    \nnamespace lib {\nusing namespace std;\nnamespace traits {\n\ntemplate <typename...>\
    \ struct make_void { using type = void; };\n\ntemplate <typename... T> using void_t\
    \ = typename make_void<T...>::type;\n\n/// keep caide\ntemplate <typename Iterator>\n\
    using IteratorCategory = typename iterator_traits<Iterator>::iterator_category;\n\
    \n/// keep caide\ntemplate <typename Container>\nusing IteratorCategoryOf = IteratorCategory<typename\
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
    \ Graph<V, E> {\n  typedef RootedForest<V, E> self_type;\n  using typename Graph<V,\
    \ E>::adj_list;\n  using typename Graph<V, E>::edge_type;\n  using Graph<V, E>::Graph;\n\
    \  using Graph<V, E>::adj;\n  using Graph<V, E>::edge;\n  vector<int> p, pe;\n\
    \n  void build_parents() {\n    if ((int)p.size() == this->size())\n      return;\n\
    \n    int n = this->size();\n    stack<int> st;\n    vector<bool> vis(n);\n  \
    \  p.assign(n, -1), pe.assign(n, -1);\n    for (int i = 0; i < n; i++) {\n   \
    \   if (!vis[i]) {\n        st.push(i);\n        vis[i] = true;\n        while\
    \ (!st.empty()) {\n          int u = st.top();\n          st.pop();\n\n      \
    \    for (int k : adj[u]) {\n            int v = edge(k).to;\n            vis[v]\
    \ = true;\n            st.push(v), pe[v] = k, p[v] = u;\n          }\n       \
    \ }\n      }\n    }\n  }\n\n  inline int parent(int i) const {\n    const_cast<self_type\
    \ *>(this)->build_parents();\n    return p[i];\n  }\n\n  inline bool is_root(int\
    \ i) const { return parent(i) != -1; }\n\n  inline edge_type &parent_edge(int\
    \ i) {\n    build_parents();\n    return edge(pe[i]);\n  }\n  inline edge_type\
    \ &parent_edge(int i) const {\n    const_cast<self_type *>(this)->build_parents();\n\
    \    return edge(pe[i]);\n  }\n\n  vector<int> roots() const {\n    vector<int>\
    \ res;\n    const_cast<self_type *>(this)->build_parents();\n    int n = this->size();\n\
    \n    for (int i = 0; i < n; i++)\n      if (p[i] == -1)\n        res.push_back(i);\n\
    \    return res;\n  }\n};\n\ntemplate <typename V = void, typename E = void>\n\
    struct RootedTree : public RootedForest<V, E> {\n  using typename RootedForest<V,\
    \ E>::adj_list;\n  int root;\n\n  RootedTree(int n, int root) : RootedForest<V,\
    \ E>(n) {\n    assert(n > 0);\n    assert(root < n);\n    this->root = root;\n\
    \  }\n\n  RootedTree(const adj_list &adj, int root) : RootedForest<V, E>(adj)\
    \ {\n    assert(adj.size() > 0);\n    assert(root < adj.size());\n    this->root\
    \ = root;\n  }\n};\n\nnamespace builders {\nnamespace {\ntemplate <typename F,\
    \ typename G>\nvoid dfs_rooted_forest(F &forest, const G &graph, int u, vector<bool>\
    \ &vis) {\n  vis[u] = true;\n  for (const auto &ed : graph.n_edges(u)) {\n   \
    \ int v = ed.to;\n    if (!vis[v]) {\n      forest.add_edge(u, v);\n      dfs_rooted_forest(forest,\
    \ graph, v, vis);\n    }\n  }\n}\n\ntemplate <typename A, typename B>\nRootedForest<A,\
    \ B> make_rooted_forest(const Graph<A, B> &graph,\n                          \
    \            const vector<int> &roots) {\n  RootedForest<A, B> res(graph.size());\n\
    \  vector<bool> vis(graph.size());\n  for (int i : roots)\n    if (!vis[i])\n\
    \      dfs_rooted_forest(res, graph, i, vis);\n  for (int i = 0; i < graph.size();\
    \ i++)\n    if (!vis[i])\n      dfs_rooted_forest(res, graph, i, vis);\n  return\
    \ res;\n}\n} // namespace\n} // namespace builders\n} // namespace graph\n} //\
    \ namespace lib\n\n\n"
  code: "#ifndef _LIB_GRAPH\n#define _LIB_GRAPH\n#include \"Traits.cpp\"\n#include\
    \ \"utils/Wrappers.cpp\"\n#include <bits/stdc++.h>\n\nnamespace lib {\nusing namespace\
    \ std;\nnamespace graph {\ntemplate <typename V = void, typename E = void, bool\
    \ Directed = false>\nstruct GraphImpl {\n  typedef GraphImpl<V, E> self_type;\n\
    \  typedef vector<vector<int>> adj_list;\n  typedef Edge<E> edge_type;\n  typedef\
    \ VertexWrapper<V> vertex_type;\n\n  const static bool directed = Directed;\n\n\
    \  vector<edge_type> edges;\n  adj_list adj;\n\n  vector<vertex_type> vertices;\n\
    \n  class iterator {\n  public:\n    typedef iterator self_type;\n    typedef\
    \ edge_type value_type;\n    typedef edge_type &reference;\n    typedef edge_type\
    \ *pointer;\n    typedef std::forward_iterator_tag iterator_category;\n    typedef\
    \ int difference_type;\n    iterator(vector<int> *adj, vector<edge_type> *edges,\
    \ int ptr = 0)\n        : adj_(adj), edges_(edges), ptr_(ptr) {}\n    self_type\
    \ operator++() {\n      ptr_++;\n      return *this;\n    }\n    self_type operator++(int\
    \ junk) {\n      self_type i = *this;\n      ptr_++;\n      return i;\n    }\n\
    \    reference operator*() { return (*edges_)[(*adj_)[ptr_]]; }\n    pointer operator->()\
    \ { return &(*edges_)[(*adj_)[ptr_]]; }\n    bool operator==(const self_type &rhs)\
    \ const {\n      return adj_ == rhs.adj_ && ptr_ == rhs.ptr_;\n    }\n    bool\
    \ operator!=(const self_type &rhs) const { return !(*this == rhs); }\n\n  private:\n\
    \    vector<int> *adj_;\n    vector<edge_type> *edges_;\n    int ptr_;\n  };\n\
    \n  class const_iterator {\n  public:\n    typedef const_iterator self_type;\n\
    \    typedef edge_type value_type;\n    typedef edge_type &reference;\n    typedef\
    \ edge_type *pointer;\n    typedef std::forward_iterator_tag iterator_category;\n\
    \    typedef int difference_type;\n    const_iterator(vector<int> *adj, vector<edge_type>\
    \ *edges, int ptr = 0)\n        : adj_(adj), edges_(edges), ptr_(ptr) {}\n   \
    \ self_type operator++() {\n      ptr_++;\n      return *this;\n    }\n    self_type\
    \ operator++(int junk) {\n      self_type i = *this;\n      ptr_++;\n      return\
    \ i;\n    }\n    const value_type &operator*() { return (*edges_)[(*adj_)[ptr_]];\
    \ }\n    const value_type *operator->() { return &(*edges_)[(*adj_)[ptr_]]; }\n\
    \    bool operator==(const self_type &rhs) const {\n      return adj_ == rhs.adj_\
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
    \ Graph<V, E> {\n  typedef RootedForest<V, E> self_type;\n  using typename Graph<V,\
    \ E>::adj_list;\n  using typename Graph<V, E>::edge_type;\n  using Graph<V, E>::Graph;\n\
    \  using Graph<V, E>::adj;\n  using Graph<V, E>::edge;\n  vector<int> p, pe;\n\
    \n  void build_parents() {\n    if ((int)p.size() == this->size())\n      return;\n\
    \n    int n = this->size();\n    stack<int> st;\n    vector<bool> vis(n);\n  \
    \  p.assign(n, -1), pe.assign(n, -1);\n    for (int i = 0; i < n; i++) {\n   \
    \   if (!vis[i]) {\n        st.push(i);\n        vis[i] = true;\n        while\
    \ (!st.empty()) {\n          int u = st.top();\n          st.pop();\n\n      \
    \    for (int k : adj[u]) {\n            int v = edge(k).to;\n            vis[v]\
    \ = true;\n            st.push(v), pe[v] = k, p[v] = u;\n          }\n       \
    \ }\n      }\n    }\n  }\n\n  inline int parent(int i) const {\n    const_cast<self_type\
    \ *>(this)->build_parents();\n    return p[i];\n  }\n\n  inline bool is_root(int\
    \ i) const { return parent(i) != -1; }\n\n  inline edge_type &parent_edge(int\
    \ i) {\n    build_parents();\n    return edge(pe[i]);\n  }\n  inline edge_type\
    \ &parent_edge(int i) const {\n    const_cast<self_type *>(this)->build_parents();\n\
    \    return edge(pe[i]);\n  }\n\n  vector<int> roots() const {\n    vector<int>\
    \ res;\n    const_cast<self_type *>(this)->build_parents();\n    int n = this->size();\n\
    \n    for (int i = 0; i < n; i++)\n      if (p[i] == -1)\n        res.push_back(i);\n\
    \    return res;\n  }\n};\n\ntemplate <typename V = void, typename E = void>\n\
    struct RootedTree : public RootedForest<V, E> {\n  using typename RootedForest<V,\
    \ E>::adj_list;\n  int root;\n\n  RootedTree(int n, int root) : RootedForest<V,\
    \ E>(n) {\n    assert(n > 0);\n    assert(root < n);\n    this->root = root;\n\
    \  }\n\n  RootedTree(const adj_list &adj, int root) : RootedForest<V, E>(adj)\
    \ {\n    assert(adj.size() > 0);\n    assert(root < adj.size());\n    this->root\
    \ = root;\n  }\n};\n\nnamespace builders {\nnamespace {\ntemplate <typename F,\
    \ typename G>\nvoid dfs_rooted_forest(F &forest, const G &graph, int u, vector<bool>\
    \ &vis) {\n  vis[u] = true;\n  for (const auto &ed : graph.n_edges(u)) {\n   \
    \ int v = ed.to;\n    if (!vis[v]) {\n      forest.add_edge(u, v);\n      dfs_rooted_forest(forest,\
    \ graph, v, vis);\n    }\n  }\n}\n\ntemplate <typename A, typename B>\nRootedForest<A,\
    \ B> make_rooted_forest(const Graph<A, B> &graph,\n                          \
    \            const vector<int> &roots) {\n  RootedForest<A, B> res(graph.size());\n\
    \  vector<bool> vis(graph.size());\n  for (int i : roots)\n    if (!vis[i])\n\
    \      dfs_rooted_forest(res, graph, i, vis);\n  for (int i = 0; i < graph.size();\
    \ i++)\n    if (!vis[i])\n      dfs_rooted_forest(res, graph, i, vis);\n  return\
    \ res;\n}\n} // namespace\n} // namespace builders\n} // namespace graph\n} //\
    \ namespace lib\n\n#endif\n"
  dependsOn:
  - Traits.cpp
  - utils/Wrappers.cpp
  isVerificationFile: false
  path: Graph.cpp
  requiredBy:
  - HLD.cpp
  - graphs/BlockCut.cpp
  - TwoSat.cpp
  - Maxflow.cpp
  - SegtreeHLD.cpp
  timestamp: '2022-09-22 01:23:11-03:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/2sat.test.cpp
  - tests/yosupo/biconnected-components.test.cpp
  - tests/yosupo/chordal.test.cpp
documentation_of: Graph.cpp
layout: document
redirect_from:
- /library/Graph.cpp
- /library/Graph.cpp.html
title: Graph.cpp
---
