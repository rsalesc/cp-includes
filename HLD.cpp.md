---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph.cpp
    title: Graph.cpp
  - icon: ':warning:'
    path: Segtree.cpp
    title: Segtree.cpp
  - icon: ':question:'
    path: Traits.cpp
    title: Traits.cpp
  - icon: ':heavy_check_mark:'
    path: utils/Wrappers.cpp
    title: utils/Wrappers.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: SegtreeHLD.cpp
    title: SegtreeHLD.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"HLD.cpp\"\n\n\n#line 1 \"Graph.cpp\"\n\n\n#line 1 \"Traits.cpp\"\
    \n\n\n#include <bits/stdc++.h>\n\nnamespace lib {\nusing namespace std;\nnamespace\
    \ traits {\n\ntemplate <typename...> struct make_void { using type = void; };\n\
    \ntemplate <typename... T> using void_t = typename make_void<T...>::type;\n\n\
    /// keep caide\ntemplate <typename Iterator>\nusing IteratorCategory = typename\
    \ iterator_traits<Iterator>::iterator_category;\n\n/// keep caide\ntemplate <typename\
    \ Container>\nusing IteratorCategoryOf = IteratorCategory<typename Container::iterator>;\n\
    \n/// keep caide\ntemplate <typename Iterator>\nusing IteratorValue = typename\
    \ iterator_traits<Iterator>::value_type;\n\n/// keep caide\ntemplate <typename\
    \ Container>\nusing IteratorValueOf = IteratorValue<typename Container::iterator>;\n\
    \n/// keep caide\ntemplate <typename Iterator>\nusing IsRandomIterator =\n   \
    \ is_base_of<random_access_iterator_tag, IteratorCategory<Iterator>>;\n\n/// keep\
    \ caide\ntemplate <typename Iterator>\nusing IsInputIterator =\n    is_base_of<input_iterator_tag,\
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
    \ int degree(int i) { return adj[i].size(); }\n\n  inline int size() const { return\
    \ adj.size(); }\n  inline int edge_size() const { return edges.size(); }\n  inline\
    \ edge_type &edge(int i) { return edges[i]; }\n  inline edge_type edge(int i)\
    \ const { return edges[i]; }\n\n  inline vector<edge_type> all_edges() const {\
    \ return edges; }\n\n  template <typename S = V,\n            typename enable_if<!is_void<S>::value>::type\
    \ * = nullptr>\n  inline S &vertex(int i) {\n    return vertices[i];\n  }\n\n\
    \  template <typename S = V,\n            typename enable_if<!is_void<S>::value>::type\
    \ * = nullptr>\n  inline V vertex(int i) const {\n    return vertices[i];\n  }\n\
    \n  template <typename S = V,\n            typename enable_if<is_void<S>::value>::type\
    \ * = nullptr>\n  inline void add_vertex() {\n    adj.emplace_back();\n  }\n\n\
    \  template <typename S = V,\n            typename enable_if<!is_void<S>::value>::type\
    \ * = nullptr>\n  inline S &add_vertex() {\n    adj.emplace_back();\n    return\
    \ vertices.emplace_back().data;\n  }\n\n  template <typename S = E,\n        \
    \    typename enable_if<is_void<S>::value>::type * = nullptr>\n  inline void add_edge_(int\
    \ u, int v) {\n    adj[u].push_back(edges.size());\n    edges.push_back({u, v});\n\
    \  }\n\n  template <typename S = E,\n            typename enable_if<!is_void<S>::value>::type\
    \ * = nullptr>\n  inline S &add_edge_(int u, int v) {\n    adj[u].push_back(edges.size());\n\
    \    edges.push_back({u, v});\n    return edges.back().data;\n  }\n\n  void add_2edge(int\
    \ u, int v) {\n    add_edge_(u, v);\n    add_edge_(v, u);\n  }\n\n  template <typename\
    \ S = E,\n            typename enable_if<!is_void<S>::value>::type * = nullptr>\n\
    \  inline void add_2edge(int u, int v, const S &data) {\n    add_edge_(u, v) =\
    \ data;\n    add_edge_(v, u) = data;\n  }\n\n  template <typename S = E,\n   \
    \         typename enable_if<is_void<S>::value && Directed>::type * = nullptr>\n\
    \  inline void add_edge(int u, int v) {\n    adj[u].push_back(edges.size());\n\
    \    edges.push_back({u, v});\n  }\n\n  template <typename S = E,\n          \
    \  typename enable_if<!is_void<S>::value && Directed>::type * = nullptr>\n  inline\
    \ S &add_edge(int u, int v) {\n    adj[u].push_back(edges.size());\n    edges.push_back({u,\
    \ v});\n    return edges.back().data;\n  }\n};\n\ntemplate<typename V = void,\
    \ typename E = void>\nusing Graph = GraphImpl<V, E, false>;\n\ntemplate<typename\
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
    \ namespace lib\n\n\n#line 1 \"Segtree.cpp\"\n\n\n#line 4 \"Segtree.cpp\"\n\n\
    namespace lib {\nusing namespace std;\nnamespace seg {\nstruct LeafBuilder {\n\
    \  template <typename Node> void operator()(Node &no, int i) const {}\n  inline\
    \ pair<int, int> range() const { return {0, 0}; }\n  bool should_build() const\
    \ { return true; }\n};\n\nstruct EmptyLeafBuilder : LeafBuilder {\n  int n;\n\
    \  explicit EmptyLeafBuilder(int n) : n(n) {}\n  inline pair<int, int> range()\
    \ const { return {0, n - 1}; }\n  bool should_build() const { return true; }\n\
    };\n\nstruct ImplicitBuilder : LeafBuilder {\n  int L, R;\n  explicit ImplicitBuilder(int\
    \ L, int R) : L(L), R(R) {}\n  inline pair<int, int> range() const { return {L,\
    \ R}; }\n  bool should_build() const { return false; }\n};\n\n// TODO: NOT IMPLEMENTED\n\
    template <typename DefaultNode>\nstruct ImplicitWithDefaultBuilder : LeafBuilder\
    \ {\n  int L, R;\n  DefaultNode default_node;\n  explicit ImplicitWithDefaultBuilder(int\
    \ L, int R, DefaultNode def)\n      : L(L), R(R), default_node(def) {}\n\n  template\
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
    \ no, int l, int r, \n                  Node* ln, Node* rn) const {}\n};\n\ntemplate<typename\
    \ Node>\nstruct Active : public Node {\n  bool active_ = false;\n  Active& operator=(const\
    \ Node& no) {\n    Node::operator=(no);\n    return *this;\n  }\n  bool is_active()\
    \ const { return active_; }\n  Active& activate() {\n    active_ = true;\n   \
    \ return *this;\n  }\n  Active& deactivate() {\n    active_ = false;\n    return\
    \ *this;\n  }\n  void toggle() {\n    active_ = !active_;\n  }\n  friend Active<Node>\
    \ operator+(const Active<Node>& a, const Active<Node>& b) {\n    if(!a.active_)\
    \ return b;\n    else if(!b.active_) return a;\n    Active<Node> res;\n    res\
    \ = Node(a) + Node(b);\n    return res.activate();\n  }\n};\n\ntemplate <typename\
    \ T>\nstruct ActiveUpdater {\n  bool flag;\n\n  ActiveUpdater(bool f) : flag(f)\
    \ {}\n\n  template <typename Node> inline void operator()(Node &no) const {\n\
    \    no.active_ = flag;\n  }\n};\n}  // namespace seg\n}  // namespace lib\n\n\
    \n#line 7 \"HLD.cpp\"\n\nnamespace lib {\nusing namespace std;\nnamespace graph\
    \ {\nnamespace {\nvoid empty_lifter(int a, int b, bool inv) {}\n} // namespace\n\
    \ntemplate <typename G> struct HLD {\n  G graph;\n  vector<int> in, out, rin;\n\
    \  vector<int> L, sz, ch;\n  int tempo;\n\n  HLD(const G &g)\n      : graph(g),\
    \ in(g.size()), out(g.size()), rin(g.size()), L(g.size()),\n        sz(g.size()),\
    \ ch(g.size()) {\n    build();\n  }\n\n  inline int size() const { return graph.size();\
    \ }\n\n  void dfs0(int u) {\n    sz[u] = 1;\n    for (auto &k : graph.adj[u])\
    \ {\n      int v = graph.edge(k).to;\n      L[v] = L[u] + 1;\n      dfs0(v);\n\
    \      if (sz[v] > sz[graph.edge(graph.adj[u][0]).to])\n        swap(k, graph.adj[u][0]);\n\
    \      sz[u] += sz[v];\n    }\n  }\n\n  void dfs1(int u) {\n    in[u] = tempo++;\n\
    \    rin[in[u]] = u;\n\n    if (graph.adj[u].size() > 0) {\n      int v = graph.edge(graph.adj[u][0]).to;\n\
    \      ch[v] = ch[u];\n      dfs1(v);\n      for (size_t i = 1; i < graph.adj[u].size();\
    \ i++) {\n        v = graph.edge(graph.adj[u][i]).to;\n        ch[v] = v;\n  \
    \      dfs1(v);\n      }\n    }\n    out[u] = tempo;\n  }\n\n  void build() {\n\
    \    vector<int> roots = graph.roots();\n    for (int i : roots)\n      dfs0(i);\n\
    \    tempo = 0;\n    for (int i : roots)\n      dfs1(i);\n  }\n\n  template <typename\
    \ Lifter>\n  inline void operate_on_subtree(int u, Lifter &lifter) {\n    lifter(in[u],\
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
    \ // namespace lib\n\n\n"
  code: "#ifndef _LIB_HLD\n#define _LIB_HLD\n#include \"Graph.cpp\"\n#include \"Segtree.cpp\"\
    \n#include \"Traits.cpp\"\n#include <bits/stdc++.h>\n\nnamespace lib {\nusing\
    \ namespace std;\nnamespace graph {\nnamespace {\nvoid empty_lifter(int a, int\
    \ b, bool inv) {}\n} // namespace\n\ntemplate <typename G> struct HLD {\n  G graph;\n\
    \  vector<int> in, out, rin;\n  vector<int> L, sz, ch;\n  int tempo;\n\n  HLD(const\
    \ G &g)\n      : graph(g), in(g.size()), out(g.size()), rin(g.size()), L(g.size()),\n\
    \        sz(g.size()), ch(g.size()) {\n    build();\n  }\n\n  inline int size()\
    \ const { return graph.size(); }\n\n  void dfs0(int u) {\n    sz[u] = 1;\n   \
    \ for (auto &k : graph.adj[u]) {\n      int v = graph.edge(k).to;\n      L[v]\
    \ = L[u] + 1;\n      dfs0(v);\n      if (sz[v] > sz[graph.edge(graph.adj[u][0]).to])\n\
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
    \ // namespace lib\n\n#endif\n"
  dependsOn:
  - Graph.cpp
  - Traits.cpp
  - utils/Wrappers.cpp
  - Segtree.cpp
  isVerificationFile: false
  path: HLD.cpp
  requiredBy:
  - SegtreeHLD.cpp
  timestamp: '2021-02-17 20:36:53-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: HLD.cpp
layout: document
redirect_from:
- /library/HLD.cpp
- /library/HLD.cpp.html
title: HLD.cpp
---
