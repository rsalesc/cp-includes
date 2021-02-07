---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Graph.cpp
    title: Graph.cpp
  - icon: ':warning:'
    path: Graph.cpp
    title: Graph.cpp
  - icon: ':warning:'
    path: HLD.cpp
    title: HLD.cpp
  - icon: ':warning:'
    path: Segtree.cpp
    title: Segtree.cpp
  - icon: ':warning:'
    path: SegtreeBeats.cpp
    title: SegtreeBeats.cpp
  - icon: ':warning:'
    path: SegtreeHLD.cpp
    title: SegtreeHLD.cpp
  - icon: ':warning:'
    path: Traits.cpp
    title: Traits.cpp
  - icon: ':warning:'
    path: utils/Wrappers.cpp
    title: utils/Wrappers.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tests/judge/hld.cpp\"\n#include <bits/stdc++.h>\n#line 1\
    \ \"Graph.cpp\"\n\n\n#line 1 \"Traits.cpp\"\n\n\n#line 4 \"Traits.cpp\"\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace traits {\n\ntemplate <typename...> struct\
    \ make_void { using type = void; };\n\ntemplate <typename... T> using void_t =\
    \ typename make_void<T...>::type;\n\n/// keep caide\ntemplate <typename Iterator>\n\
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
    \ = void, typename E = void> struct Graph {\n  typedef Graph<V, E> self_type;\n\
    \  typedef vector<vector<int>> adj_list;\n  typedef Edge<E> edge_type;\n  typedef\
    \ VertexWrapper<V> vertex_type;\n\n  vector<edge_type> edges;\n  adj_list adj;\n\
    \n  vector<vertex_type> vertices;\n\n  class iterator {\n  public:\n    typedef\
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
    \ i) const {\n      return (*edges_)[(*adj_)[i]];\n    }\n\n    inline int size()\
    \ const { return adj_->size(); }\n  };\n\n  Graph() {}\n\n  template <typename\
    \ S = V,\n            typename enable_if<is_void<S>::value>::type * = nullptr>\n\
    \  Graph(size_t n) : adj(n) {}\n\n  template <typename S = V,\n            typename\
    \ enable_if<!is_void<S>::value>::type * = nullptr>\n  Graph(size_t n) : adj(n),\
    \ vertices(n) {}\n\n  inline iterable n_edges(int i) { return iterable(&adj[i],\
    \ &edges); }\n  inline const iterable n_edges(int i) const {\n    return iterable(const_cast<vector<int>\
    \ *>(&adj[i]),\n                    const_cast<vector<edge_type> *>(&edges));\n\
    \  }\n\n  inline int size() const { return adj.size(); }\n  inline int edge_size()\
    \ const { return edges.size(); }\n  inline edge_type &edge(int i) { return edges[i];\
    \ }\n  inline edge_type edge(int i) const { return edges[i]; }\n\n  inline vector<edge_type>\
    \ all_edges() const { return edges; }\n\n  template <typename S = V,\n       \
    \     typename enable_if<!is_void<S>::value>::type * = nullptr>\n  inline S &vertex(int\
    \ i) {\n    return vertices[i];\n  }\n\n  template <typename S = V,\n        \
    \    typename enable_if<!is_void<S>::value>::type * = nullptr>\n  inline V vertex(int\
    \ i) const {\n    return vertices[i];\n  }\n\n  template <typename S = V,\n  \
    \          typename enable_if<is_void<S>::value>::type * = nullptr>\n  inline\
    \ void add_vertex() {\n    adj.emplace_back();\n  }\n\n  template <typename S\
    \ = V,\n            typename enable_if<!is_void<S>::value>::type * = nullptr>\n\
    \  inline S &add_vertex() {\n    adj.emplace_back();\n    return vertices.emplace_back().data;\n\
    \  }\n\n  template <typename S = E,\n            typename enable_if<is_void<S>::value>::type\
    \ * = nullptr>\n  inline void add_edge(int u, int v) {\n    adj[u].push_back(edges.size());\n\
    \    edges.push_back({u, v});\n  }\n\n  template <typename S = E,\n          \
    \  typename enable_if<!is_void<S>::value>::type * = nullptr>\n  inline S &add_edge(int\
    \ u, int v) {\n    adj[u].push_back(edges.size());\n    edges.push_back({u, v});\n\
    \    return edges.back().data;\n  }\n\n  void add_2edge(int u, int v) {\n    add_edge(u,\
    \ v);\n    add_edge(v, u);\n  }\n\n  template <typename S = E,\n            typename\
    \ enable_if<!is_void<S>::value>::type * = nullptr>\n  inline void add_2edge(int\
    \ u, int v, const S &data) {\n    add_edge(u, v) = data;\n    add_edge(v, u) =\
    \ data;\n  }\n};\n\ntemplate <typename V = void, typename E = void>\nstruct RootedForest\
    \ : public Graph<V, E> {\n  typedef RootedForest<V, E> self_type;\n  using typename\
    \ Graph<V, E>::adj_list;\n  using typename Graph<V, E>::edge_type;\n  using Graph<V,\
    \ E>::Graph;\n  using Graph<V, E>::adj;\n  using Graph<V, E>::edge;\n  vector<int>\
    \ p, pe;\n\n  void build_parents() {\n    if ((int)p.size() == this->size())\n\
    \      return;\n\n    int n = this->size();\n    stack<int> st;\n    vector<bool>\
    \ vis(n);\n    p.assign(n, -1), pe.assign(n, -1);\n    for (int i = 0; i < n;\
    \ i++) {\n      if (!vis[i]) {\n        st.push(i);\n        vis[i] = true;\n\
    \        while (!st.empty()) {\n          int u = st.top();\n          st.pop();\n\
    \n          for (int k : adj[u]) {\n            int v = edge(k).to;\n        \
    \    vis[v] = true;\n            st.push(v), pe[v] = k, p[v] = u;\n          }\n\
    \        }\n      }\n    }\n  }\n\n  inline int parent(int i) const {\n    const_cast<self_type\
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
    \ namespace lib\n\n\n#line 1 \"SegtreeHLD.cpp\"\n\n\n#line 1 \"HLD.cpp\"\n\n\n\
    #line 1 \"Segtree.cpp\"\n\n\n#line 4 \"Segtree.cpp\"\n\nnamespace lib {\nusing\
    \ namespace std;\nnamespace seg {\nstruct LeafBuilder {\n  template <typename\
    \ Node> void operator()(Node &no, int i) const {}\n  inline pair<int, int> range()\
    \ const { return {0, 0}; }\n  bool should_build() const { return true; }\n};\n\
    \nstruct EmptyLeafBuilder : LeafBuilder {\n  int n;\n  explicit EmptyLeafBuilder(int\
    \ n) : n(n) {}\n  inline pair<int, int> range() const { return {0, n - 1}; }\n\
    \  bool should_build() const { return true; }\n};\n\nstruct ImplicitBuilder :\
    \ LeafBuilder {\n  int L, R;\n  explicit ImplicitBuilder(int L, int R) : L(L),\
    \ R(R) {}\n  inline pair<int, int> range() const { return {L, R}; }\n  bool should_build()\
    \ const { return false; }\n};\n\n// TODO: NOT IMPLEMENTED\ntemplate <typename\
    \ DefaultNode>\nstruct ImplicitWithDefaultBuilder : LeafBuilder {\n  int L, R;\n\
    \  DefaultNode default_node;\n  explicit ImplicitWithDefaultBuilder(int L, int\
    \ R, DefaultNode def)\n      : L(L), R(R), default_node(def) {}\n\n  template\
    \ <typename Node> inline void operator()(Node &no, int i) const {\n    no = default_node;\n\
    \  }\n\n  inline pair<int, int> range() const { return {L, R}; }\n  bool should_build()\
    \ const { return false; }\n};\n\ntemplate <typename RandomIterator> struct RangeLeafBuilder\
    \ : LeafBuilder {\n  RandomIterator begin, end;\n  explicit RangeLeafBuilder(RandomIterator\
    \ begin, RandomIterator end)\n      : begin(begin), end(end) {}\n\n  template\
    \ <typename Node> inline void operator()(Node &no, int i) const {\n    no = *(begin\
    \ + i);\n  }\n\n  inline pair<int, int> range() const { return {0, end - begin\
    \ - 1}; }\n};\n\nEmptyLeafBuilder make_builder(int n) { return EmptyLeafBuilder(n);\
    \ }\n\ntemplate <typename RandomIterator>\nRangeLeafBuilder<RandomIterator> make_builder(RandomIterator\
    \ begin,\n                                              RandomIterator end) {\n\
    \  return RangeLeafBuilder<RandomIterator>(begin, end);\n}\n\ntemplate <typename\
    \ T>\nRangeLeafBuilder<typename vector<T>::const_iterator>\nmake_builder(const\
    \ vector<T> &v) {\n  return RangeLeafBuilder<typename vector<T>::const_iterator>(v.begin(),\n\
    \                                                              v.end());\n}\n\n\
    template <typename T> struct CombineFolder {\n  inline T operator()() const {\
    \ return T(); }\n\n  template <typename Node> inline T operator()(const Node &no)\
    \ const {\n    return T(no);\n  }\n\n  inline T operator()(const T &a, const T\
    \ &b) const { return a + b; }\n};\n\ntemplate <typename T> struct EmptyFolder\
    \ : CombineFolder<T> {\n  using CombineFolder<T>::operator();\n\n  template <typename\
    \ Node> inline T operator()(const Node &no) const {\n    return T();\n  }\n  inline\
    \ T operator()(const T &a, const T &b) const { return T(); }\n};\n\ntemplate <typename\
    \ T> struct SumFolder : CombineFolder<T> {};\n\ntemplate <typename T> struct ProductFolder\
    \ : CombineFolder<T> {\n  using CombineFolder<T>::operator();\n  inline T operator()()\
    \ const { return T(1); }\n  inline T operator()(const T &a, const T &b) const\
    \ { return a * b; }\n};\n\ntemplate <typename T> struct MaxFolder : CombineFolder<T>\
    \ {\n  using CombineFolder<T>::operator();\n  inline T operator()() const { return\
    \ numeric_limits<T>::min(); }\n  inline T operator()(const T &a, const T &b) const\
    \ { return max(a, b); }\n};\n\ntemplate <typename T> struct MinFolder : CombineFolder<T>\
    \ {\n  using CombineFolder<T>::operator();\n  inline T operator()() const { return\
    \ numeric_limits<T>::max(); }\n  inline T operator()(const T &a, const T &b) const\
    \ { return min(a, b); }\n};\n\ntemplate <typename T> struct SingleValueUpdater\
    \ {\n  T value;\n  explicit SingleValueUpdater(T val) : value(val) {}\n};\n\n\
    template <typename T> struct SetUpdater : SingleValueUpdater<T> {\n  using SingleValueUpdater<T>::SingleValueUpdater;\n\
    \n  template <typename Node> inline void operator()(Node &no) const {\n    no\
    \ = this->value;\n  }\n};\n\ntemplate <typename T> struct AddUpdater : SingleValueUpdater<T>\
    \ {\n  using SingleValueUpdater<T>::SingleValueUpdater;\n\n  template <typename\
    \ Node> inline void operator()(Node &no) const {\n    no += this->value;\n  }\n\
    };\n\ntemplate <typename T> struct MultUpdater : SingleValueUpdater<T> {\n  using\
    \ SingleValueUpdater<T>::SingleValueUpdater;\n\n  template <typename Node> inline\
    \ void operator()(Node &no) const {\n    no *= this->value;\n  }\n};\n\nstruct\
    \ EmptyPushdown {\n  template<typename Node>\n  inline bool dirty(const Node&\
    \ no) const { return false; }\n\n  template<typename Node>\n  inline void operator()(Node&\
    \ no, int l, int r, \n                  Node* ln, Node* rn) const {}\n};\n}  //\
    \ namespace seg\n}  // namespace lib\n\n\n#line 7 \"HLD.cpp\"\n\nnamespace lib\
    \ {\nusing namespace std;\nnamespace graph {\nnamespace {\nvoid empty_lifter(int\
    \ a, int b, bool inv) {}\n} // namespace\n\ntemplate <typename G> struct HLD {\n\
    \  G graph;\n  vector<int> in, out, rin;\n  vector<int> L, sz, ch;\n  int tempo;\n\
    \n  HLD(const G &g)\n      : graph(g), in(g.size()), out(g.size()), rin(g.size()),\
    \ L(g.size()),\n        sz(g.size()), ch(g.size()) {\n    build();\n  }\n\n  inline\
    \ int size() const { return graph.size(); }\n\n  void dfs0(int u) {\n    sz[u]\
    \ = 1;\n    for (auto &k : graph.adj[u]) {\n      int v = graph.edge(k).to;\n\
    \      L[v] = L[u] + 1;\n      dfs0(v);\n      if (sz[v] > sz[graph.edge(graph.adj[u][0]).to])\n\
    \        swap(k, graph.adj[u][0]);\n      sz[u] += sz[v];\n    }\n  }\n\n  void\
    \ dfs1(int u) {\n    in[u] = tempo++;\n    rin[in[u]] = u;\n\n    if (graph.adj[u].size()\
    \ > 0) {\n      int v = graph.edge(graph.adj[u][0]).to;\n      ch[v] = ch[u];\n\
    \      dfs1(v);\n      for (size_t i = 1; i < graph.adj[u].size(); i++) {\n  \
    \      v = graph.edge(graph.adj[u][i]).to;\n        ch[v] = v;\n        dfs1(v);\n\
    \      }\n    }\n    out[u] = tempo;\n  }\n\n  void build() {\n    vector<int>\
    \ roots = graph.roots();\n    for (int i : roots)\n      dfs0(i);\n    tempo =\
    \ 0;\n    for (int i : roots)\n      dfs1(i);\n  }\n\n  template <typename Lifter>\n\
    \  inline void operate_on_subtree(int u, Lifter &lifter) {\n    lifter(in[u],\
    \ out[u] - 1, false);\n  }\n\n  template <typename T, typename QueryIssuer>\n\
    \  inline T query_on_subtree(int u, const QueryIssuer &issuer) {\n    return issuer(in[u],\
    \ out[u] - 1);\n  }\n\n  template <typename Lifter>\n  inline void operate_on_subtree_edges(int\
    \ u, Lifter &lifter) {\n    if (in[u] + 2 <= out[u])\n      lifter(in[u] + 1,\
    \ out[u] - 1, false);\n  }\n\n  template <typename T, typename QueryIssuer>\n\
    \  inline void query_on_subtree_edges(int u, const QueryIssuer &issuer) {\n  \
    \  assert(in[u] + 2 <= out[u]);\n    return issuer(in[u] + 1, out[u] - 1);\n \
    \ }\n\n  template <bool is_edge, typename Lifter>\n  int _query_path(int u, int\
    \ v, Lifter &lifter) {\n    int inv = 0;\n    for (; ch[u] != ch[v]; u = graph.parent(ch[u]))\
    \ {\n      if (L[ch[u]] < L[ch[v]])\n        swap(u, v), inv ^= 1;\n      lifter(in[ch[u]],\
    \ in[u], (bool)inv);\n    }\n    if (L[u] > L[v])\n      swap(u, v), inv ^= 1;\n\
    \    inv ^= 1;\n    if (is_edge && in[u] + 1 <= in[v])\n      lifter(in[u] + 1,\
    \ in[v], (bool)inv);\n    else if (!is_edge)\n      lifter(in[u], in[v], (bool)inv);\n\
    \    return u;\n  }\n\n  template <typename Lifter>\n  inline int operate_on_path(int\
    \ u, int v, Lifter &lifter) {\n    return _query_path<false>(u, v, lifter);\n\
    \  }\n\n  template <typename Lifter>\n  inline int operate_on_path_edges(int u,\
    \ int v, Lifter &lifter) {\n    return _query_path<true>(u, v, lifter);\n  }\n\
    \n  template <typename Op> inline void operate_on_vertex(int u, Op &op) {\n  \
    \  op(in[u]);\n  }\n\n  template <typename T, typename QueryIssuer>\n  inline\
    \ T query_on_vertex(int u, const QueryIssuer &issuer) {\n    return issuer(in[u]);\n\
    \  }\n\n  inline int lca(int u, int v) {\n    return _query_path<false>(u, v,\
    \ empty_lifter);\n  }\n\n  inline int dist(int u, int v) {\n    int uv = lca(u,\
    \ v);\n    return L[u] + L[v] - 2 * L[uv];\n  }\n};\n\ntemplate <typename G> HLD<G>\
    \ make_hld(const G &graph) { return HLD<G>(graph); }\n} // namespace graph\n}\
    \ // namespace lib\n\n\n#line 5 \"SegtreeHLD.cpp\"\n\nnamespace lib {\nusing namespace\
    \ std;\nnamespace graph {\nnamespace range {\ntemplate <typename Builder, typename\
    \ H> struct BuilderWrapper {\n  H *hld;\n  Builder builder;\n\n  explicit BuilderWrapper(H\
    \ *hld, const Builder &builder)\n      : hld(hld), builder(builder) {}\n\n  template\
    \ <typename Node> void operator()(Node &no, int i) const {\n    builder(no, hld->rin[i]);\n\
    \  }\n\n  pair<int, int> range() const { return {0, hld->size() - 1}; }\n};\n\n\
    template <typename Builder, typename H>\nstruct RebuilderWrapper : BuilderWrapper<Builder,\
    \ H> {\n  using BuilderWrapper<Builder, H>::BuilderWrapper;\n  using BuilderWrapper<Builder,\
    \ H>::builder;\n  template <typename Node>\n  void operator()(Node &no, const\
    \ Node &left, const Node &right) const {\n    builder(no, left, right);\n  }\n\
    };\n\ntemplate <typename S, typename T, typename Folder> struct QueryIssuer {\n\
    \  S &seg;\n  const Folder &folder;\n  QueryIssuer(S &seg, const Folder &folder)\
    \ : seg(seg), folder(folder) {}\n  T operator()(int i) const { seg.template query_element<T>(i,\
    \ folder); }\n  T operator()(int i, int j) const {\n    return seg.template query<T>(i,\
    \ j, folder);\n  }\n};\n\ntemplate <typename S, typename T, typename Folder> struct\
    \ QueryLifter {\n  QueryIssuer<S, T, Folder> issuer;\n  T res;\n  QueryLifter(S\
    \ &seg, const Folder &folder)\n      : issuer(seg, folder), res(folder()) {}\n\
    \  void operator()(int i, int j, bool) {\n    res = issuer.folder(res, issuer(i,\
    \ j));\n  }\n  T result() const { return res; }\n};\n\ntemplate <typename S, typename\
    \ T, typename Folder>\nstruct OrderedQueryLifter : QueryLifter<S, T, Folder> {\n\
    \  using QueryLifter<S, T, Folder>::issuer;\n  T resl, resr;\n\n  OrderedQueryLifter(S\
    \ &seg, const Folder &folder)\n      : QueryLifter<S, T, Folder>(seg, folder),\
    \ resl(folder()), resr(folder()) {\n  }\n\n  void operator()(int i, int j, bool\
    \ right) {\n    if (right)\n      resr = issuer.folder(issuer(i, j), resr);\n\
    \    else\n      resl = issuer.folder(resl, issuer(i, j));\n  }\n  T result()\
    \ const { return issuer.folder(resl, resr); }\n};\n\ntemplate <typename S, typename\
    \ Updater> struct UpdateIssuer {\n  S &seg;\n  const Updater &updater;\n  UpdateIssuer(S\
    \ &seg, const Updater &updater) : seg(seg), updater(updater) {}\n  void operator()(int\
    \ i, int j) { seg.update(i, j, updater); }\n  void operator()(int i, int j, bool)\
    \ { (*this)(i, j); }\n};\n\ntemplate <typename S, typename Updater> struct SplashIssuer\
    \ {\n  S &seg;\n  const Updater &updater;\n  SplashIssuer(S &seg, const Updater\
    \ &updater) : seg(seg), updater(updater) {}\n  void operator()(int i, int j) {\
    \ seg.splash(i, j, updater); }\n  void operator()(int i, int j, bool) { (*this)(i,\
    \ j); }\n};\n\ntemplate <typename S, typename Beater> struct BeatIssuer {\n  S\
    \ &seg;\n  const Beater &beater;\n  BeatIssuer(S &seg, const Beater &beater) :\
    \ seg(seg), beater(beater) {}\n  void operator()(int i, int j) { seg.beat(i, j,\
    \ beater); }\n  void operator()(int i, int j, bool) { (*this)(i, j); }\n};\n}\
    \ // namespace range\n\ntemplate <typename S, typename G> struct RangeHLD : HLD<G>\
    \ {\n  typedef seg::EmptyLeafBuilder empty_builder;\n\n  template <typename Builder>\n\
    \  using builder_wrapper = range::BuilderWrapper<Builder, HLD<G>>;\n  template\
    \ <typename Rebuilder>\n  using rebuilder_wrapper = range::RebuilderWrapper<Rebuilder,\
    \ HLD<G>>;\n\n  S seg;\n\n  explicit RangeHLD(const G &graph)\n      : HLD<G>(graph),\n\
    \        seg(builder_wrapper<empty_builder>(this, empty_builder(this->size())))\
    \ {\n  }\n\n  template <typename Builder>\n  RangeHLD(const G &graph, const Builder\
    \ &builder)\n      : HLD<G>(graph), seg(builder_wrapper<Builder>(this, builder))\
    \ {}\n\n  template <typename Builder> void build(const Builder &builder) {\n \
    \   seg.build(builder_wrapper<Builder>(builder));\n  }\n\n  template <typename\
    \ Rebuilder> void rebuild(const Rebuilder &rebuilder) {\n    seg.rebuild(rebuilder_wrapper<Rebuilder>(rebuilder));\n\
    \  }\n\n  template <typename T, typename Folder>\n  inline T query_subtree(int\
    \ u, const Folder &folder) {\n    return this->template query_on_subtree<T>(\n\
    \        u, range::QueryIssuer<S, T, Folder>(seg, folder));\n  }\n\n  template\
    \ <typename T, typename Folder>\n  inline T query_subtree_edges(int u, const Folder\
    \ &folder) {\n    return this->template query_on_subtree_edges(\n        u, range::QueryIssuer<S,\
    \ T, Folder>(seg, folder));\n  }\n\n  template <typename T, typename Folder>\n\
    \  inline T query_vertex(int u, const Folder &folder) {\n    return this->template\
    \ query_on_vertex(\n        u, range::QueryIssuer<S, T, Folder>(seg, folder));\n\
    \  }\n\n  template <typename T, typename Folder>\n  T query_path(int u, int v,\
    \ const Folder &folder) {\n    auto lifter = range::OrderedQueryLifter<S, T, Folder>(seg,\
    \ folder);\n    this->template operate_on_path(u, v, lifter);\n    return lifter.result();\n\
    \  }\n\n  template <typename T, typename Folder>\n  T query_path_edges(int u,\
    \ int v, const Folder &folder) {\n    auto lifter = range::OrderedQueryLifter<S,\
    \ T, Folder>(seg, folder);\n    this->template operate_on_path_edges(u, v, lifter);\n\
    \    return lifter.result();\n  }\n\n  template <typename Updater>\n  inline void\
    \ update_subtree(int u, const Updater &updater) {\n    auto issuer = range::UpdateIssuer<S,\
    \ Updater>(seg, updater);\n    this->template operate_on_subtree(u, issuer);\n\
    \  }\n\n  template <typename Updater>\n  inline void update_subtree_edges(int\
    \ u, const Updater &updater) {\n    auto issuer = range::UpdateIssuer<S, Updater>(seg,\
    \ updater);\n    this->template operate_on_subtree_edges(u, issuer);\n  }\n\n\
    \  template <typename Updater>\n  inline void update_path(int u, int v, const\
    \ Updater &updater) {\n    auto issuer = range::UpdateIssuer<S, Updater>(seg,\
    \ updater);\n    this->template operate_on_path(u, v, issuer);\n  }\n\n  template\
    \ <typename Updater>\n  inline void update_path_edges(int u, int v, const Updater\
    \ &updater) {\n    auto issuer = range::UpdateIssuer<S, Updater>(seg, updater);\n\
    \    this->template operate_on_path_edges(u, v, issuer);\n  }\n\n  template <typename\
    \ Beater>\n  inline void beat_subtree(int u, const Beater &beater) {\n    auto\
    \ issuer = range::BeatIssuer<S, Beater>(seg, beater);\n    this->template operate_on_subtree(u,\
    \ issuer);\n  }\n\n  template <typename Beater>\n  inline void beat_subtree_edges(int\
    \ u, const Beater &beater) {\n    auto issuer = range::BeatIssuer<S, Beater>(seg,\
    \ beater);\n    this->template operate_on_subtree_edges(u, issuer);\n  }\n\n \
    \ template <typename Beater>\n  inline void beat_path(int u, int v, const Beater\
    \ &beater) {\n    auto issuer = range::BeatIssuer<S, Beater>(seg, beater);\n \
    \   this->template operate_on_path(u, v, issuer);\n  }\n\n  template <typename\
    \ Beater>\n  inline void beat_path_edges(int u, int v, const Beater &beater) {\n\
    \    auto issuer = range::BeatIssuer<S, Beater>(seg, beater);\n    this->template\
    \ operate_on_path_edges(u, v, issuer);\n  }\n\n  // TODO: FIX THOSE\n  template\
    \ <typename Updater>\n  inline void update_element(int idx, const Updater &updater)\
    \ {\n    seg.update_element(idx, updater);\n  }\n\n  template <typename Updater>\n\
    \  inline void splash(int i, int j, const Updater &updater) {\n    seg.splash(i,\
    \ j, updater);\n  }\n};\n\ntemplate <typename S, typename G>\nRangeHLD<S, G> make_range_hld(const\
    \ G &graph) {\n  return RangeHLD<S, G>(graph);\n}\n\ntemplate <typename S, typename\
    \ G, typename Builder>\nRangeHLD<S, G> make_range_hld(const G &graph, const Builder\
    \ &builder) {\n  return RangeHLD<S, G>(graph, builder);\n}\n\n} // namespace graph\n\
    } // namespace lib\n\n\n#line 1 \"SegtreeBeats.cpp\"\n\n\n#line 5 \"SegtreeBeats.cpp\"\
    \n\nnamespace lib {\nusing namespace std;\nnamespace seg {\nstruct DefaultBreakCond\
    \ {\n  template <typename Node>\n  inline bool operator()(const Node &no, int\
    \ l, int r, int i, int j) const {\n    return i > r || j < l;\n  }\n};\n\nstruct\
    \ DefaultTagCond {\n  template <typename Node>\n  inline bool operator()(const\
    \ Node &no, int l, int r, int i, int j) const {\n    return i <= l && r <= j;\n\
    \  }\n};\n\ntemplate <typename T> struct SearchResult {\n  bool found;\n  int\
    \ pos;\n  T value;\n\n  static SearchResult<T> not_found(T acc = T()) { return\
    \ {false, 0, acc}; }\n};\n\nstruct PrefixSearch;\nstruct SuffixSearch;\n\ntemplate\
    \ <typename Direction> using IsSuffix = is_same<Direction, SuffixSearch>;\n\n\
    template <typename Node> struct InMemoryNodeManager {\n  typedef int vnode;\n\
    \  vector<Node> t;\n\n  template <typename Builder> void initialize(const Builder\
    \ &builder) {\n    int L, R;\n    tie(L, R) = builder.range();\n    t = vector<Node>(4\
    \ * (R - L + 1));\n  }\n\n  inline bool has(vnode no) { return true; }\n  inline\
    \ vnode root() { return 1; }\n  inline vnode new_root(vnode no) { return no; }\n\
    \  inline vnode left(vnode no) { return no << 1; }\n  inline vnode right(vnode\
    \ no) { return no << 1 | 1; }\n  inline Node &ref(vnode no) { return t[no]; }\n\
    \  inline Node *ptr(vnode no) { return &t[no]; }\n  inline Node value(vnode no)\
    \ { return t[no]; }\n\n  inline vnode persist(vnode no) { return no; }\n  inline\
    \ void ensure_left(vnode no) {}\n  inline void ensure_right(vnode no) {}\n};\n\
    \ntemplate <\n    typename Node, typename NodeManager, typename CombinerFn = EmptyFolder<int>,\n\
    \    typename PushdownFn = EmptyPushdown, typename BreakCond = DefaultBreakCond,\n\
    \    typename TagCond = DefaultTagCond>\nstruct SegtreeImpl {\n  typedef typename\
    \ NodeManager::vnode vnode;\n  constexpr static bool has_lazy = !is_same<PushdownFn,\
    \ EmptyPushdown>::value;\n  constexpr static bool is_implicit =\n      !is_same<NodeManager,\
    \ InMemoryNodeManager<Node>>::value;\n\n  CombinerFn combiner_fn;\n  PushdownFn\
    \ pushdown_fn;\n  BreakCond break_cond;\n  TagCond tag_cond;\n  NodeManager manager;\n\
    \n  int L, R;\n\n  template <typename Builder> explicit SegtreeImpl(const Builder\
    \ &builder) {\n    tie(L, R) = builder.range();\n    assert(L <= R);\n    manager.initialize(builder);\n\
    \    if (builder.should_build())\n      build(builder);\n  }\n\n  inline vnode\
    \ root() { return manager.root(); }\n  inline int split(int l, int r) { return\
    \ l + (r - l) / 2; }\n\n  template <typename Builder>\n  vnode build(const Builder\
    \ &builder, vnode no, int l, int r) {\n    no = manager.persist(no);\n    if (l\
    \ == r) {\n      builder(manager.ref(no), l);\n    } else {\n      int mid = split(l,\
    \ r);\n      build(builder, manager.left(no), l, mid);\n      build(builder, manager.right(no),\
    \ mid + 1, r);\n      manager.ref(no) = combiner_fn(manager.value(manager.left(no)),\n\
    \                                    manager.value(manager.right(no)));\n    }\n\
    \    return no;\n  }\n\n  template <typename Builder> vnode build(const Builder\
    \ &builder) {\n    return manager.new_root(build(builder, root(), L, R));\n  }\n\
    \n  inline int size() const { return R - L + 1; }\n\n  void push(vnode no, int\
    \ l, int r) {\n    if(!has_lazy) return;\n    if (!pushdown_fn.dirty(manager.ref(no)))\n\
    \      return;\n    if(l == r) {\n      pushdown_fn(manager.ref(no), l, r, nullptr,\
    \ nullptr);\n      return;\n    }\n    manager.ensure_left(no);\n    manager.ensure_right(no);\n\
    \    vnode lno = manager.persist(manager.left(no));\n    vnode rno = manager.persist(manager.right(no));\n\
    \    pushdown_fn(manager.ref(no), l, r, manager.ptr(lno), manager.ptr(rno));\n\
    \  }\n\n  template <typename T, typename Folder>\n  T query(vnode no, int l, int\
    \ r, int i, int j, const Folder &folder) {\n    if (!manager.has(no))\n      return\
    \ folder();\n    if (j < l || i > r)\n      return folder();\n    push(no, l,\
    \ r);\n    if (i <= l && r <= j)\n      return folder(manager.ref(no));\n    int\
    \ mid = split(l, r);\n    return folder(query<T>(manager.left(no), l, mid, i,\
    \ j, folder),\n                  query<T>(manager.right(no), mid + 1, r, i, j,\
    \ folder));\n  }\n\n  template <typename T, typename Folder>\n  inline T query(vnode\
    \ root, int i, int j, const Folder &folder) {\n    return query<T>(root, L, R,\
    \ i, j, folder);\n  }\n\n  template <typename T, typename Folder>\n  inline T\
    \ query(int i, int j, const Folder &folder) {\n    return query<T>(root(), i,\
    \ j, folder);\n  }\n\n  template <typename Updater>\n  vnode update(vnode no,\
    \ int l, int r, int i, int j, const Updater &updater) {\n    push(no, l, r);\n\
    \    if (break_cond(manager.ref(no), l, r, i, j)) {\n      return no;\n    }\n\
    \    no = manager.persist(no);\n    if (tag_cond(manager.ref(no), l, r, i, j))\
    \ {\n      updater(manager.ref(no));\n      push(no, l, r);\n      return no;\n\
    \    }\n    int mid = split(l, r);\n    update(manager.left(no), l, mid, i, j,\
    \ updater);\n    update(manager.right(no), mid + 1, r, i, j, updater);\n    manager.ref(no)\
    \ = combiner_fn(manager.value(manager.left(no)),\n                           \
    \       manager.value(manager.right(no)));\n    return no;\n  }\n\n  template\
    \ <typename Updater>\n  inline vnode update(vnode root, int i, int j, const Updater\
    \ &updater) {\n    return manager.new_root(update(root, L, R, i, j, updater));\n\
    \  }\n\n  template <typename Updater>\n  inline vnode update(int i, int j, const\
    \ Updater &updater) {\n    return update(root(), i, j, updater);\n  }\n\n  template\
    \ <typename Beater, typename U = NodeManager,\n            typename enable_if<\n\
    \                is_same<U, InMemoryNodeManager<Node>>::value>::type * = nullptr>\n\
    \  void beat(vnode no, int l, int r, int i, int j, const Beater &beater) {\n \
    \   push(no, l, r);\n    if (break_cond(manager.ref(no), l, r, i, j) ||\n    \
    \    beater.stop(manager.ref(no), l, r, i, j)) {\n      return;\n    }\n    if\
    \ (tag_cond(manager.ref(no), l, r, i, j) &&\n        beater.tag(manager.ref(no),\
    \ l, r, i, j)) {\n      beater(manager.ref(no));\n      push(no, l, r);\n    \
    \  return;\n    }\n    int mid = split(l, r);\n    beat(manager.left(no), l, mid,\
    \ i, j, beater);\n    beat(manager.right(no), mid + 1, r, i, j, beater);\n   \
    \ manager.ref(no) = combiner_fn(manager.value(manager.left(no)),\n           \
    \                       manager.value(manager.right(no)));\n  }\n\n  template\
    \ <typename Beater>\n  inline void beat(int i, int j, const Beater &beater) {\n\
    \    beat(root(), L, R, i, j, beater);\n  }\n\n  template <typename T, typename\
    \ Direction, typename Folder, typename Checker>\n  SearchResult<T> bsearch_first(vnode\
    \ no, int l, int r, int i, int j,\n                                const Folder\
    \ &folder, const Checker &checker,\n                                T acc) {\n\
    \    if (manager.has(no))\n      push(no, l, r);\n    if (j < l || i > r)\n  \
    \    return SearchResult<T>::not_found(folder());\n    if (!manager.has(no)) {\n\
    \      auto value = folder(acc, folder());\n      if (checker(value))\n      \
    \  return {true, IsSuffix<Direction>::value ? r : l, value};\n      else\n   \
    \     return SearchResult<T>::not_found(folder());\n    }\n    int mid = split(l,\
    \ r);\n    if (i <= l && r <= j) {\n      auto b_value = folder(acc, manager.value(no));\n\
    \      if (!checker(b_value))\n        return SearchResult<T>::not_found(manager.value(no));\n\
    \      if (l == r)\n        return {true, l, b_value};\n    }\n    if (!IsSuffix<Direction>::value)\
    \ {\n      auto res_left = bsearch_first<T, Direction>(manager.left(no), l, mid,\
    \ i,\n                                                  j, folder, checker, acc);\n\
    \      if (res_left.found)\n        return res_left;\n      return bsearch_first<T,\
    \ Direction>(manager.right(no), mid + 1, r, i, j,\n                          \
    \               folder, checker,\n                                         folder(acc,\
    \ res_left.value));\n    } else {\n      auto res_right = bsearch_first<T, Direction>(\n\
    \          manager.right(no), mid + 1, r, i, j, folder, checker, acc);\n     \
    \ if (res_right.found)\n        return res_right;\n      return bsearch_first<T,\
    \ Direction>(manager.left(no), l, mid, i, j, folder,\n                       \
    \                  checker, folder(acc, res_right.value));\n    }\n  }\n\n  template\
    \ <typename T, typename Direction, typename Folder, typename Checker>\n  inline\
    \ SearchResult<T> bsearch_first(vnode root, int i, int j,\n                  \
    \                     const Folder &folder,\n                                \
    \       const Checker &checker) {\n    auto res = bsearch_first<T, Direction>(root,\
    \ L, R, i, j, folder, checker,\n                                           folder());\n\
    \    if (!res.found)\n      res.pos = IsSuffix<Direction>::value ? i - 1 : j +\
    \ 1;\n    return res;\n  }\n\n  template <typename T, typename Direction, typename\
    \ Folder, typename Checker>\n  inline SearchResult<T> bsearch_first(int i, int\
    \ j, const Folder &folder,\n                                       const Checker\
    \ &checker) {\n    return bsearch_first<T, Direction>(root(), i, j, folder, checker);\n\
    \  }\n\n  template <typename T, typename Direction, typename Folder, typename\
    \ Checker>\n  inline SearchResult<T> bsearch_last(vnode root, int i, int j,\n\
    \                                      const Folder &folder,\n               \
    \                       const Checker &checker) {\n    auto res = bsearch_first<T,\
    \ Direction>(\n        root, i, j, folder, [&checker](T x) { return !checker(x);\
    \ });\n    if (!IsSuffix<Direction>::value) {\n      if (res.pos == i)\n     \
    \   res.found = false;\n      res.pos--;\n    } else {\n      if (res.pos == j)\n\
    \        res.found = false;\n      res.pos++;\n    }\n    return res;\n  }\n\n\
    \  template <typename T, typename Direction, typename Folder, typename Checker>\n\
    \  inline SearchResult<T> bsearch_last(int i, int j, const Folder &folder,\n \
    \                                     const Checker &checker) {\n    return bsearch_last<T,\
    \ Direction>(root(), i, j, folder, checker);\n  }\n};\n\ntemplate <typename Node,\
    \ typename CombinerFn = EmptyFolder<int>,\n          typename PushdownFn = EmptyPushdown,\n\
    \          typename BreakCond = DefaultBreakCond,\n          typename TagCond\
    \ = DefaultTagCond>\nstruct SegtreeBeats : SegtreeImpl<Node, InMemoryNodeManager<Node>,\
    \ CombinerFn,\n                                  PushdownFn, BreakCond, TagCond>\
    \ {\n\n  template <typename Builder>\n  explicit SegtreeBeats(const Builder &builder)\n\
    \      : SegtreeImpl<Node, InMemoryNodeManager<Node>, CombinerFn, PushdownFn,\n\
    \                    BreakCond, TagCond>(builder) {}\n};\n\ntemplate <typename\
    \ Node> using Explicit = InMemoryNodeManager<Node>;\n} // namespace seg\n} //\
    \ namespace lib\n\n\n#line 5 \"tests/judge/hld.cpp\"\n\nusing namespace std;\n\
    using namespace lib;\nusing lib::graph::Graph;\nusing lib::graph::HLD;\nusing\
    \ lib::seg::SegtreeBeats;\n\nstruct Node {\n  int mx = 0, lz = 0;\n  Node() {}\n\
    \  Node(int mx) : mx(mx) {}\n  operator int() const { return mx; }\n  Node& operator+=(const\
    \ int rhs) {\n    lz += rhs;\n    return *this;\n  }\n  Node operator+(const Node&\
    \ rhs) const {\n    return Node(max(mx, rhs.mx));\n  }\n};\n\nstruct Pushdown\
    \ {\n  void operator()(Node& no, int l, int r, Node* lf, Node* rt) const {\n \
    \   if(no.lz != 0) {\n      no.mx += no.lz;\n      if(l != r) {\n        lf->lz\
    \ += no.lz;\n        rt->lz += no.lz;\n      }\n      no.lz = 0;\n    }\n  }\n\
    };\n\nvoid solve() {\n  int n;\n  cin >> n;\n\n  Graph<> g(n);\n  for(int i =\
    \ 1; i < n; i++) {\n    int x, y;\n    cin >> x >> y;\n    x--, y--;\n    g.add_2edge(x,\
    \ y);\n  }\n\n  auto f = graph::builders::make_rooted_forest(g, {0});\n  auto\
    \ hld = graph::make_range_hld<SegtreeBeats<Node, seg::CombineFolder<Node>, Pushdown>>(f);\n\
    \n  int Q;\n  cin >> Q;\n  while(Q--) {\n    string t;\n    cin >> t;\n    if(t\
    \ == \"add\") {\n      int u, x;\n      cin >> u >> x; u--;\n      auto updater\
    \ = seg::AddUpdater<int>(x);\n      hld.update_subtree(u, updater);\n    } else\
    \ {\n      int x, y;\n      cin >> x >> y;\n      x--, y--;\n      auto folder\
    \ = seg::MaxFolder<int>();\n      cout << hld.query_path<int>(x, y, folder) <<\
    \ endl;\n    }\n  }\n}\n\nint main() {\n  ios::sync_with_stdio(false);\n  cin.tie(0);\n\
    \  solve();\n}\n"
  code: "#include <bits/stdc++.h>\n#include \"../../Graph.cpp\"\n#include \"../../SegtreeHLD.cpp\"\
    \n#include \"../../SegtreeBeats.cpp\"\n\nusing namespace std;\nusing namespace\
    \ lib;\nusing lib::graph::Graph;\nusing lib::graph::HLD;\nusing lib::seg::SegtreeBeats;\n\
    \nstruct Node {\n  int mx = 0, lz = 0;\n  Node() {}\n  Node(int mx) : mx(mx) {}\n\
    \  operator int() const { return mx; }\n  Node& operator+=(const int rhs) {\n\
    \    lz += rhs;\n    return *this;\n  }\n  Node operator+(const Node& rhs) const\
    \ {\n    return Node(max(mx, rhs.mx));\n  }\n};\n\nstruct Pushdown {\n  void operator()(Node&\
    \ no, int l, int r, Node* lf, Node* rt) const {\n    if(no.lz != 0) {\n      no.mx\
    \ += no.lz;\n      if(l != r) {\n        lf->lz += no.lz;\n        rt->lz += no.lz;\n\
    \      }\n      no.lz = 0;\n    }\n  }\n};\n\nvoid solve() {\n  int n;\n  cin\
    \ >> n;\n\n  Graph<> g(n);\n  for(int i = 1; i < n; i++) {\n    int x, y;\n  \
    \  cin >> x >> y;\n    x--, y--;\n    g.add_2edge(x, y);\n  }\n\n  auto f = graph::builders::make_rooted_forest(g,\
    \ {0});\n  auto hld = graph::make_range_hld<SegtreeBeats<Node, seg::CombineFolder<Node>,\
    \ Pushdown>>(f);\n\n  int Q;\n  cin >> Q;\n  while(Q--) {\n    string t;\n   \
    \ cin >> t;\n    if(t == \"add\") {\n      int u, x;\n      cin >> u >> x; u--;\n\
    \      auto updater = seg::AddUpdater<int>(x);\n      hld.update_subtree(u, updater);\n\
    \    } else {\n      int x, y;\n      cin >> x >> y;\n      x--, y--;\n      auto\
    \ folder = seg::MaxFolder<int>();\n      cout << hld.query_path<int>(x, y, folder)\
    \ << endl;\n    }\n  }\n}\n\nint main() {\n  ios::sync_with_stdio(false);\n  cin.tie(0);\n\
    \  solve();\n}\n"
  dependsOn:
  - Graph.cpp
  - Traits.cpp
  - utils/Wrappers.cpp
  - SegtreeHLD.cpp
  - HLD.cpp
  - Graph.cpp
  - Segtree.cpp
  - SegtreeBeats.cpp
  isVerificationFile: false
  path: tests/judge/hld.cpp
  requiredBy: []
  timestamp: '2021-01-26 16:28:00-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tests/judge/hld.cpp
layout: document
redirect_from:
- /library/tests/judge/hld.cpp
- /library/tests/judge/hld.cpp.html
title: tests/judge/hld.cpp
---
