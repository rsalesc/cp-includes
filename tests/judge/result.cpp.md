---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tests/judge/result.cpp\"\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\n\nnamespace graph {\ntemplate <typename T> struct\
    \ Edge {};\n\ntemplate <> struct Edge<void> { const int from, to; };\n\ntemplate\
    \ <typename T> struct VertexWrapper {};\n\ntemplate <> struct VertexWrapper<void>\
    \ {};\n\ntemplate <typename V = void, typename E = void> struct Graph {\n\n  typedef\
    \ vector<vector<int>> adj_list;\n  typedef Edge<E> edge_type;\n  typedef VertexWrapper<V>\
    \ vertex_type;\n\n  vector<edge_type> edges;\n  adj_list adj;\n\n  vector<vertex_type>\
    \ vertices;\n\n  class const_iterator {\n  public:\n    typedef const_iterator\
    \ self_type;\n    typedef edge_type value_type;\n\n    const_iterator(vector<int>\
    \ *adj, vector<edge_type> *edges, int ptr = 0)\n        : adj_(adj), edges_(edges),\
    \ ptr_(ptr) {}\n    self_type operator++() {\n      ptr_++;\n      return *this;\n\
    \    }\n\n    const value_type &operator*() { return (*edges_)[(*adj_)[ptr_]];\
    \ }\n\n    bool operator==(const self_type &rhs) const {\n      return adj_ ==\
    \ rhs.adj_ && ptr_ == rhs.ptr_;\n    }\n    bool operator!=(const self_type &rhs)\
    \ const { return !(*this == rhs); }\n\n  private:\n    vector<int> *adj_;\n  \
    \  vector<edge_type> *edges_;\n    int ptr_;\n  };\n\n  struct iterable {\n  \
    \  vector<int> *adj_;\n    vector<edge_type> *edges_;\n\n    iterable(vector<int>\
    \ *adj, vector<edge_type> *edges)\n        : adj_(adj), edges_(edges) {}\n\n \
    \   inline const_iterator cbegin() const {\n      return const_iterator(adj_,\
    \ edges_);\n    }\n    inline const_iterator cend() const {\n      return const_iterator(adj_,\
    \ edges_, adj_->size());\n    }\n\n    inline const_iterator begin() const { return\
    \ cbegin(); }\n    inline const_iterator end() const { return cend(); }\n  };\n\
    \n  template <typename S = V,\n            typename enable_if<is_void<S>::value>::type\
    \ * = nullptr>\n  Graph(size_t n) : adj(n) {}\n\n  inline const iterable n_edges(int\
    \ i) const {\n    return iterable(const_cast<vector<int> *>(&adj[i]),\n      \
    \              const_cast<vector<edge_type> *>(&edges));\n  }\n\n  inline int\
    \ size() const { return adj.size(); }\n  inline edge_type &edge(int i) { return\
    \ edges[i]; }\n\n  template <typename S = E,\n            typename enable_if<is_void<S>::value>::type\
    \ * = nullptr>\n  inline void add_edge(int u, int v) {\n    adj[u].push_back(edges.size());\n\
    \    edges.push_back({u, v});\n  }\n\n  void add_2edge(int u, int v) {\n    add_edge(u,\
    \ v);\n    add_edge(v, u);\n  }\n};\n\ntemplate <typename V = void, typename E\
    \ = void>\nstruct RootedForest : public Graph<V, E> {\n  typedef RootedForest<V,\
    \ E> self_type;\n  using typename Graph<V, E>::adj_list;\n  using typename Graph<V,\
    \ E>::edge_type;\n  using Graph<V, E>::Graph;\n  using Graph<V, E>::adj;\n  using\
    \ Graph<V, E>::edge;\n  vector<int> p, pe;\n\n  void build_parents() {\n    if\
    \ ((int)p.size() == this->size())\n      return;\n\n    int n = this->size();\n\
    \    stack<int> st;\n    vector<bool> vis(n);\n    p.assign(n, -1), pe.assign(n,\
    \ -1);\n    for (int i = 0; i < n; i++) {\n      if (!vis[i]) {\n        st.push(i);\n\
    \        vis[i] = true;\n        while (!st.empty()) {\n          int u = st.top();\n\
    \          st.pop();\n\n          for (int k : adj[u]) {\n            int v =\
    \ edge(k).to;\n            vis[v] = true;\n            st.push(v), pe[v] = k,\
    \ p[v] = u;\n          }\n        }\n      }\n    }\n  }\n\n  inline int parent(int\
    \ i) const {\n    const_cast<self_type *>(this)->build_parents();\n    return\
    \ p[i];\n  }\n\n  vector<int> roots() const {\n    vector<int> res;\n    const_cast<self_type\
    \ *>(this)->build_parents();\n    int n = this->size();\n\n    for (int i = 0;\
    \ i < n; i++)\n      if (p[i] == -1)\n        res.push_back(i);\n    return res;\n\
    \  }\n};\n\nnamespace builders {\nnamespace {\ntemplate <typename F, typename\
    \ G>\nvoid dfs_rooted_forest(F &forest, const G &graph, int u, vector<bool> &vis)\
    \ {\n  vis[u] = true;\n  for (const auto &ed : graph.n_edges(u)) {\n    int v\
    \ = ed.to;\n    if (!vis[v]) {\n      forest.add_edge(u, v);\n      dfs_rooted_forest(forest,\
    \ graph, v, vis);\n    }\n  }\n}\n\ntemplate <typename A, typename B>\nRootedForest<A,\
    \ B> make_rooted_forest(const Graph<A, B> &graph,\n                          \
    \            const vector<int> &roots) {\n  RootedForest<A, B> res(graph.size());\n\
    \  vector<bool> vis(graph.size());\n  for (int i : roots)\n    if (!vis[i])\n\
    \      dfs_rooted_forest(res, graph, i, vis);\n  for (int i = 0; i < graph.size();\
    \ i++)\n    if (!vis[i])\n      dfs_rooted_forest(res, graph, i, vis);\n  return\
    \ res;\n}\n} // namespace\n} // namespace builders\n} // namespace graph\n  //\
    \ namespace lib\n\nnamespace seg {\nstruct LeafBuilder {\n  template <typename\
    \ Node> void operator()(Node &no, int i) const {}\n};\n\nstruct EmptyLeafBuilder\
    \ : LeafBuilder {\n  int n;\n  explicit EmptyLeafBuilder(int n) : n(n) {}\n};\n\
    \ntemplate <typename T> struct CombineFolder {\n\n  template <typename Node> inline\
    \ T operator()(const Node &no) const {\n    return T(no);\n  }\n\n  inline T operator()(const\
    \ T &a, const T &b) const { return a + b; }\n};\n\ntemplate <typename T> struct\
    \ EmptyFolder : CombineFolder<T> {\n  using CombineFolder<T>::operator();\n};\n\
    \ntemplate <typename T> struct MaxFolder : CombineFolder<T> {\n  using CombineFolder<T>::operator();\n\
    \  inline T operator()() const { return numeric_limits<T>::min(); }\n  inline\
    \ T operator()(const T &a, const T &b) const { return max(a, b); }\n};\n\ntemplate\
    \ <typename T> struct SingleValueUpdater {\n  T value;\n  explicit SingleValueUpdater(T\
    \ val) : value(val) {}\n};\n\ntemplate <typename T> struct AddUpdater : SingleValueUpdater<T>\
    \ {\n  using SingleValueUpdater<T>::SingleValueUpdater;\n\n  template <typename\
    \ Node> inline void operator()(Node &no) const {\n    no += this->value;\n  }\n\
    };\n\nstruct EmptyPushdown {};\n} // namespace seg\n  // namespace lib\n\nnamespace\
    \ graph {\n\ntemplate <typename G> struct HLD {\n  G graph;\n  vector<int> in,\
    \ out, rin;\n  vector<int> L, sz, ch;\n  int tempo;\n\n  HLD(const G &g)\n   \
    \   : graph(g), in(g.size()), out(g.size()), rin(g.size()), L(g.size()),\n   \
    \     sz(g.size()), ch(g.size()) {\n    build();\n  }\n\n  inline int size() const\
    \ { return graph.size(); }\n\n  void dfs0(int u) {\n    sz[u] = 1;\n    for (auto\
    \ &k : graph.adj[u]) {\n      int v = graph.edge(k).to;\n      L[v] = L[u] + 1;\n\
    \      dfs0(v);\n      if (sz[v] > sz[graph.edge(graph.adj[u][0]).to])\n     \
    \   swap(k, graph.adj[u][0]);\n      sz[u] += sz[v];\n    }\n  }\n\n  void dfs1(int\
    \ u) {\n    in[u] = tempo++;\n    rin[in[u]] = u;\n\n    if (graph.adj[u].size()\
    \ > 0) {\n      int v = graph.edge(graph.adj[u][0]).to;\n      ch[v] = ch[u];\n\
    \      dfs1(v);\n      for (size_t i = 1; i < graph.adj[u].size(); i++) {\n  \
    \      v = graph.edge(graph.adj[u][i]).to;\n        ch[v] = v;\n        dfs1(v);\n\
    \      }\n    }\n    out[u] = tempo;\n  }\n\n  void build() {\n    vector<int>\
    \ roots = graph.roots();\n    for (int i : roots)\n      dfs0(i);\n    tempo =\
    \ 0;\n    for (int i : roots)\n      dfs1(i);\n  }\n\n  template <typename Lifter>\n\
    \  inline void operate_on_subtree(int u, Lifter &lifter) {\n    lifter(in[u],\
    \ out[u] - 1, false);\n  }\n\n  template <bool is_edge, typename Lifter>\n  int\
    \ _query_path(int u, int v, Lifter &lifter) {\n    int inv = 0;\n    for (; ch[u]\
    \ != ch[v]; u = graph.parent(ch[u])) {\n      if (L[ch[u]] < L[ch[v]])\n     \
    \   swap(u, v), inv ^= 1;\n      lifter(in[ch[u]], in[u], (bool)inv);\n    }\n\
    \    if (L[u] > L[v])\n      swap(u, v), inv ^= 1;\n    inv ^= 1;\n    if (is_edge\
    \ && in[u] + 1 <= in[v])\n      lifter(in[u] + 1, in[v], (bool)inv);\n    else\
    \ if (!is_edge)\n      lifter(in[u], in[v], (bool)inv);\n    return u;\n  }\n\n\
    \  template <typename Lifter>\n  inline int operate_on_path(int u, int v, Lifter\
    \ &lifter) {\n    return _query_path<false>(u, v, lifter);\n  }\n};\n\n// namespace\
    \ graph\n// namespace lib\n\nnamespace range {\ntemplate <typename Builder, typename\
    \ H> struct BuilderWrapper {\n  H *hld;\n  Builder builder;\n\n  explicit BuilderWrapper(H\
    \ *hld, const Builder &builder)\n      : hld(hld), builder(builder) {}\n\n  template\
    \ <typename Node> void operator()(Node &no, int i) const {\n    builder(no, hld->rin[i]);\n\
    \  }\n\n  pair<int, int> range() const { return {0, hld->size() - 1}; }\n};\n\n\
    template <typename S, typename T, typename Folder> struct QueryIssuer {\n  S &seg;\n\
    \  const Folder &folder;\n  QueryIssuer(S &seg, const Folder &folder) : seg(seg),\
    \ folder(folder) {}\n\n  T operator()(int i, int j) const {\n    return seg.template\
    \ query<T>(i, j, folder);\n  }\n};\n\ntemplate <typename S, typename T, typename\
    \ Folder> struct QueryLifter {\n  QueryIssuer<S, T, Folder> issuer;\n  T res;\n\
    \  QueryLifter(S &seg, const Folder &folder)\n      : issuer(seg, folder), res(folder())\
    \ {}\n};\n\ntemplate <typename S, typename T, typename Folder>\nstruct OrderedQueryLifter\
    \ : QueryLifter<S, T, Folder> {\n  using QueryLifter<S, T, Folder>::issuer;\n\
    \  T resl, resr;\n\n  OrderedQueryLifter(S &seg, const Folder &folder)\n     \
    \ : QueryLifter<S, T, Folder>(seg, folder), resl(folder()), resr(folder()) {\n\
    \  }\n\n  void operator()(int i, int j, bool right) {\n    if (right)\n      resr\
    \ = issuer.folder(issuer(i, j), resr);\n    else\n      resl = issuer.folder(resl,\
    \ issuer(i, j));\n  }\n  T result() const { return issuer.folder(resl, resr);\
    \ }\n};\n\ntemplate <typename S, typename Updater> struct UpdateIssuer {\n  S\
    \ &seg;\n  const Updater &updater;\n  UpdateIssuer(S &seg, const Updater &updater)\
    \ : seg(seg), updater(updater) {}\n  void operator()(int i, int j) { seg.update(i,\
    \ j, updater); }\n  void operator()(int i, int j, bool) { (*this)(i, j); }\n};\n\
    \n} // namespace range\n\ntemplate <typename S, typename G> struct RangeHLD :\
    \ HLD<G> {\n  typedef seg::EmptyLeafBuilder empty_builder;\n\n  template <typename\
    \ Builder>\n  using builder_wrapper = range::BuilderWrapper<Builder, HLD<G>>;\n\
    \n  S seg;\n\n  explicit RangeHLD(const G &graph)\n      : HLD<G>(graph),\n  \
    \      seg(builder_wrapper<empty_builder>(this, empty_builder(this->size())))\
    \ {\n  }\n\n  template <typename T, typename Folder>\n  T query_path(int u, int\
    \ v, const Folder &folder) {\n    auto lifter = range::OrderedQueryLifter<S, T,\
    \ Folder>(seg, folder);\n    this->template operate_on_path(u, v, lifter);\n \
    \   return lifter.result();\n  }\n\n  template <typename Updater>\n  inline void\
    \ update_subtree(int u, const Updater &updater) {\n    auto issuer = range::UpdateIssuer<S,\
    \ Updater>(seg, updater);\n    this->template operate_on_subtree(u, issuer);\n\
    \  }\n\n  // FIX THOSE\n};\n\ntemplate <typename S, typename G>\nRangeHLD<S, G>\
    \ make_range_hld(const G &graph) {\n  return RangeHLD<S, G>(graph);\n}\n\n} //\
    \ namespace graph\n  // namespace lib\n\nnamespace seg {\nstruct DefaultBreakCond\
    \ {\n  template <typename Node>\n  inline bool operator()(const Node &no, int\
    \ l, int r, int i, int j) const {\n    return i > r || j < l;\n  }\n};\n\nstruct\
    \ DefaultTagCond {\n  template <typename Node>\n  inline bool operator()(const\
    \ Node &no, int l, int r, int i, int j) const {\n    return i <= l && r <= j;\n\
    \  }\n};\n\ntemplate <typename Node, typename CombinerFn = EmptyFolder<int>,\n\
    \          typename PushdownFn = EmptyPushdown,\n          typename BreakCond\
    \ = DefaultBreakCond,\n          typename TagCond = DefaultTagCond>\nstruct SegtreeBeats\
    \ {\n  const static int ROOT = 1;\n  const static int MULTIPLIER = 4;\n  const\
    \ static int SHIFT = 0;\n\n  CombinerFn combiner_fn;\n  PushdownFn pushdown_fn;\n\
    \  BreakCond break_cond;\n  TagCond tag_cond;\n\n  vector<Node> t;\n  int L, R;\n\
    \n  template <typename Builder> explicit SegtreeBeats(const Builder &builder)\
    \ {\n    pair<int, int> range = builder.range();\n    L = range.first;\n    R\
    \ = range.second;\n    assert(L >= 0 && L <= R);\n    t = vector<Node>(size()\
    \ * MULTIPLIER + SHIFT);\n    build(builder);\n  }\n\n  template <typename Builder>\n\
    \  void build(const Builder &builder, int no, int l, int r) {\n    if (l == r)\
    \ {\n      builder(t[no], l);\n    } else {\n      int mid = (l + r) / 2;\n  \
    \    build(builder, no << 1, l, mid);\n      build(builder, no << 1 | 1, mid +\
    \ 1, r);\n      t[no] = combiner_fn(t[no << 1], t[no << 1 | 1]);\n    }\n  }\n\
    \n  template <typename Builder> void build(const Builder &builder) {\n    return\
    \ build(builder, ROOT, L, R);\n  }\n\n  inline int size() const { return R - L\
    \ + 1; }\n\n  void push(int no, int l, int r) {\n    Node *left = l == r ? 0 :\
    \ &t[no << 1];\n    Node *right = l == r ? 0 : &t[no << 1 | 1];\n    pushdown_fn(t[no],\
    \ l, r, left, right);\n  }\n\n  template <typename T, typename Folder>\n  T query(int\
    \ no, int l, int r, int i, int j, const Folder &folder) {\n    if (j < l || i\
    \ > r)\n      return folder();\n    push(no, l, r);\n    if (i <= l && r <= j)\n\
    \      return folder(t[no]);\n    int mid = (l + r) / 2;\n    return folder(query<T>(no\
    \ << 1, l, mid, i, j, folder),\n                  query<T>(no << 1 | 1, mid +\
    \ 1, r, i, j, folder));\n  }\n\n  template <typename T, typename Folder>\n  inline\
    \ T query(int i, int j, const Folder &folder) {\n    return query<T>(ROOT, L,\
    \ R, i, j, folder);\n  }\n\n  template <typename Updater>\n  void update(int no,\
    \ int l, int r, int i, int j, const Updater &updater) {\n    push(no, l, r);\n\
    \    if (break_cond(t[no], l, r, i, j)) {\n      return;\n    }\n    if (tag_cond(t[no],\
    \ l, r, i, j)) {\n      updater(t[no]);\n      push(no, l, r);\n      return;\n\
    \    }\n    int mid = (l + r) / 2;\n    update(no << 1, l, mid, i, j, updater);\n\
    \    update(no << 1 | 1, mid + 1, r, i, j, updater);\n    t[no] = combiner_fn(t[no\
    \ << 1], t[no << 1 | 1]);\n  }\n\n  template <typename Updater>\n  inline void\
    \ update(int i, int j, const Updater &updater) {\n    update(ROOT, L, R, i, j,\
    \ updater);\n  }\n};\n\n} // namespace seg\n} // namespace lib\n\nusing namespace\
    \ std;\nusing namespace lib;\nusing lib::graph::Graph;\nusing lib::graph::HLD;\n\
    using lib::seg::SegtreeBeats;\n\nstruct Node {\n  int mx = 0, lz = 0;\n  Node()\
    \ {}\n  Node(int mx) : mx(mx) {}\n  operator int() const { return mx; }\n  Node\
    \ &operator+=(const int rhs) {\n    lz += rhs;\n    return *this;\n  }\n  Node\
    \ operator+(const Node &rhs) const { return Node(max(mx, rhs.mx)); }\n};\n\nstruct\
    \ Pushdown {\n  void operator()(Node &no, int l, int r, Node *lf, Node *rt) const\
    \ {\n    if (no.lz != 0) {\n      no.mx += no.lz;\n      if (l != r) {\n     \
    \   lf->lz += no.lz;\n        rt->lz += no.lz;\n      }\n      no.lz = 0;\n  \
    \  }\n  }\n};\n\nvoid solve() {\n  int n;\n  cin >> n;\n\n  Graph<> g(n);\n  for\
    \ (int i = 1; i < n; i++) {\n    int x, y;\n    cin >> x >> y;\n    x--, y--;\n\
    \    g.add_2edge(x, y);\n  }\n\n  auto f = graph::builders::make_rooted_forest(g,\
    \ {0});\n  auto hld = graph::make_range_hld<\n      SegtreeBeats<Node, seg::CombineFolder<Node>,\
    \ Pushdown>>(f);\n\n  int Q;\n  cin >> Q;\n  while (Q--) {\n    string t;\n  \
    \  cin >> t;\n    if (t == \"add\") {\n      int u, x;\n      cin >> u >> x;\n\
    \      u--;\n      auto updater = seg::AddUpdater<int>(x);\n      hld.update_subtree(u,\
    \ updater);\n    } else {\n      int x, y;\n      cin >> x >> y;\n      x--, y--;\n\
    \      auto folder = seg::MaxFolder<int>();\n      cout << hld.query_path<int>(x,\
    \ y, folder) << endl;\n    }\n  }\n}\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(0);\n  solve();\n}\n"
  code: "#include <bits/stdc++.h>\n\nnamespace lib {\nusing namespace std;\n\nnamespace\
    \ graph {\ntemplate <typename T> struct Edge {};\n\ntemplate <> struct Edge<void>\
    \ { const int from, to; };\n\ntemplate <typename T> struct VertexWrapper {};\n\
    \ntemplate <> struct VertexWrapper<void> {};\n\ntemplate <typename V = void, typename\
    \ E = void> struct Graph {\n\n  typedef vector<vector<int>> adj_list;\n  typedef\
    \ Edge<E> edge_type;\n  typedef VertexWrapper<V> vertex_type;\n\n  vector<edge_type>\
    \ edges;\n  adj_list adj;\n\n  vector<vertex_type> vertices;\n\n  class const_iterator\
    \ {\n  public:\n    typedef const_iterator self_type;\n    typedef edge_type value_type;\n\
    \n    const_iterator(vector<int> *adj, vector<edge_type> *edges, int ptr = 0)\n\
    \        : adj_(adj), edges_(edges), ptr_(ptr) {}\n    self_type operator++()\
    \ {\n      ptr_++;\n      return *this;\n    }\n\n    const value_type &operator*()\
    \ { return (*edges_)[(*adj_)[ptr_]]; }\n\n    bool operator==(const self_type\
    \ &rhs) const {\n      return adj_ == rhs.adj_ && ptr_ == rhs.ptr_;\n    }\n \
    \   bool operator!=(const self_type &rhs) const { return !(*this == rhs); }\n\n\
    \  private:\n    vector<int> *adj_;\n    vector<edge_type> *edges_;\n    int ptr_;\n\
    \  };\n\n  struct iterable {\n    vector<int> *adj_;\n    vector<edge_type> *edges_;\n\
    \n    iterable(vector<int> *adj, vector<edge_type> *edges)\n        : adj_(adj),\
    \ edges_(edges) {}\n\n    inline const_iterator cbegin() const {\n      return\
    \ const_iterator(adj_, edges_);\n    }\n    inline const_iterator cend() const\
    \ {\n      return const_iterator(adj_, edges_, adj_->size());\n    }\n\n    inline\
    \ const_iterator begin() const { return cbegin(); }\n    inline const_iterator\
    \ end() const { return cend(); }\n  };\n\n  template <typename S = V,\n      \
    \      typename enable_if<is_void<S>::value>::type * = nullptr>\n  Graph(size_t\
    \ n) : adj(n) {}\n\n  inline const iterable n_edges(int i) const {\n    return\
    \ iterable(const_cast<vector<int> *>(&adj[i]),\n                    const_cast<vector<edge_type>\
    \ *>(&edges));\n  }\n\n  inline int size() const { return adj.size(); }\n  inline\
    \ edge_type &edge(int i) { return edges[i]; }\n\n  template <typename S = E,\n\
    \            typename enable_if<is_void<S>::value>::type * = nullptr>\n  inline\
    \ void add_edge(int u, int v) {\n    adj[u].push_back(edges.size());\n    edges.push_back({u,\
    \ v});\n  }\n\n  void add_2edge(int u, int v) {\n    add_edge(u, v);\n    add_edge(v,\
    \ u);\n  }\n};\n\ntemplate <typename V = void, typename E = void>\nstruct RootedForest\
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
    \ *>(this)->build_parents();\n    return p[i];\n  }\n\n  vector<int> roots() const\
    \ {\n    vector<int> res;\n    const_cast<self_type *>(this)->build_parents();\n\
    \    int n = this->size();\n\n    for (int i = 0; i < n; i++)\n      if (p[i]\
    \ == -1)\n        res.push_back(i);\n    return res;\n  }\n};\n\nnamespace builders\
    \ {\nnamespace {\ntemplate <typename F, typename G>\nvoid dfs_rooted_forest(F\
    \ &forest, const G &graph, int u, vector<bool> &vis) {\n  vis[u] = true;\n  for\
    \ (const auto &ed : graph.n_edges(u)) {\n    int v = ed.to;\n    if (!vis[v])\
    \ {\n      forest.add_edge(u, v);\n      dfs_rooted_forest(forest, graph, v, vis);\n\
    \    }\n  }\n}\n\ntemplate <typename A, typename B>\nRootedForest<A, B> make_rooted_forest(const\
    \ Graph<A, B> &graph,\n                                      const vector<int>\
    \ &roots) {\n  RootedForest<A, B> res(graph.size());\n  vector<bool> vis(graph.size());\n\
    \  for (int i : roots)\n    if (!vis[i])\n      dfs_rooted_forest(res, graph,\
    \ i, vis);\n  for (int i = 0; i < graph.size(); i++)\n    if (!vis[i])\n     \
    \ dfs_rooted_forest(res, graph, i, vis);\n  return res;\n}\n} // namespace\n}\
    \ // namespace builders\n} // namespace graph\n  // namespace lib\n\nnamespace\
    \ seg {\nstruct LeafBuilder {\n  template <typename Node> void operator()(Node\
    \ &no, int i) const {}\n};\n\nstruct EmptyLeafBuilder : LeafBuilder {\n  int n;\n\
    \  explicit EmptyLeafBuilder(int n) : n(n) {}\n};\n\ntemplate <typename T> struct\
    \ CombineFolder {\n\n  template <typename Node> inline T operator()(const Node\
    \ &no) const {\n    return T(no);\n  }\n\n  inline T operator()(const T &a, const\
    \ T &b) const { return a + b; }\n};\n\ntemplate <typename T> struct EmptyFolder\
    \ : CombineFolder<T> {\n  using CombineFolder<T>::operator();\n};\n\ntemplate\
    \ <typename T> struct MaxFolder : CombineFolder<T> {\n  using CombineFolder<T>::operator();\n\
    \  inline T operator()() const { return numeric_limits<T>::min(); }\n  inline\
    \ T operator()(const T &a, const T &b) const { return max(a, b); }\n};\n\ntemplate\
    \ <typename T> struct SingleValueUpdater {\n  T value;\n  explicit SingleValueUpdater(T\
    \ val) : value(val) {}\n};\n\ntemplate <typename T> struct AddUpdater : SingleValueUpdater<T>\
    \ {\n  using SingleValueUpdater<T>::SingleValueUpdater;\n\n  template <typename\
    \ Node> inline void operator()(Node &no) const {\n    no += this->value;\n  }\n\
    };\n\nstruct EmptyPushdown {};\n} // namespace seg\n  // namespace lib\n\nnamespace\
    \ graph {\n\ntemplate <typename G> struct HLD {\n  G graph;\n  vector<int> in,\
    \ out, rin;\n  vector<int> L, sz, ch;\n  int tempo;\n\n  HLD(const G &g)\n   \
    \   : graph(g), in(g.size()), out(g.size()), rin(g.size()), L(g.size()),\n   \
    \     sz(g.size()), ch(g.size()) {\n    build();\n  }\n\n  inline int size() const\
    \ { return graph.size(); }\n\n  void dfs0(int u) {\n    sz[u] = 1;\n    for (auto\
    \ &k : graph.adj[u]) {\n      int v = graph.edge(k).to;\n      L[v] = L[u] + 1;\n\
    \      dfs0(v);\n      if (sz[v] > sz[graph.edge(graph.adj[u][0]).to])\n     \
    \   swap(k, graph.adj[u][0]);\n      sz[u] += sz[v];\n    }\n  }\n\n  void dfs1(int\
    \ u) {\n    in[u] = tempo++;\n    rin[in[u]] = u;\n\n    if (graph.adj[u].size()\
    \ > 0) {\n      int v = graph.edge(graph.adj[u][0]).to;\n      ch[v] = ch[u];\n\
    \      dfs1(v);\n      for (size_t i = 1; i < graph.adj[u].size(); i++) {\n  \
    \      v = graph.edge(graph.adj[u][i]).to;\n        ch[v] = v;\n        dfs1(v);\n\
    \      }\n    }\n    out[u] = tempo;\n  }\n\n  void build() {\n    vector<int>\
    \ roots = graph.roots();\n    for (int i : roots)\n      dfs0(i);\n    tempo =\
    \ 0;\n    for (int i : roots)\n      dfs1(i);\n  }\n\n  template <typename Lifter>\n\
    \  inline void operate_on_subtree(int u, Lifter &lifter) {\n    lifter(in[u],\
    \ out[u] - 1, false);\n  }\n\n  template <bool is_edge, typename Lifter>\n  int\
    \ _query_path(int u, int v, Lifter &lifter) {\n    int inv = 0;\n    for (; ch[u]\
    \ != ch[v]; u = graph.parent(ch[u])) {\n      if (L[ch[u]] < L[ch[v]])\n     \
    \   swap(u, v), inv ^= 1;\n      lifter(in[ch[u]], in[u], (bool)inv);\n    }\n\
    \    if (L[u] > L[v])\n      swap(u, v), inv ^= 1;\n    inv ^= 1;\n    if (is_edge\
    \ && in[u] + 1 <= in[v])\n      lifter(in[u] + 1, in[v], (bool)inv);\n    else\
    \ if (!is_edge)\n      lifter(in[u], in[v], (bool)inv);\n    return u;\n  }\n\n\
    \  template <typename Lifter>\n  inline int operate_on_path(int u, int v, Lifter\
    \ &lifter) {\n    return _query_path<false>(u, v, lifter);\n  }\n};\n\n// namespace\
    \ graph\n// namespace lib\n\nnamespace range {\ntemplate <typename Builder, typename\
    \ H> struct BuilderWrapper {\n  H *hld;\n  Builder builder;\n\n  explicit BuilderWrapper(H\
    \ *hld, const Builder &builder)\n      : hld(hld), builder(builder) {}\n\n  template\
    \ <typename Node> void operator()(Node &no, int i) const {\n    builder(no, hld->rin[i]);\n\
    \  }\n\n  pair<int, int> range() const { return {0, hld->size() - 1}; }\n};\n\n\
    template <typename S, typename T, typename Folder> struct QueryIssuer {\n  S &seg;\n\
    \  const Folder &folder;\n  QueryIssuer(S &seg, const Folder &folder) : seg(seg),\
    \ folder(folder) {}\n\n  T operator()(int i, int j) const {\n    return seg.template\
    \ query<T>(i, j, folder);\n  }\n};\n\ntemplate <typename S, typename T, typename\
    \ Folder> struct QueryLifter {\n  QueryIssuer<S, T, Folder> issuer;\n  T res;\n\
    \  QueryLifter(S &seg, const Folder &folder)\n      : issuer(seg, folder), res(folder())\
    \ {}\n};\n\ntemplate <typename S, typename T, typename Folder>\nstruct OrderedQueryLifter\
    \ : QueryLifter<S, T, Folder> {\n  using QueryLifter<S, T, Folder>::issuer;\n\
    \  T resl, resr;\n\n  OrderedQueryLifter(S &seg, const Folder &folder)\n     \
    \ : QueryLifter<S, T, Folder>(seg, folder), resl(folder()), resr(folder()) {\n\
    \  }\n\n  void operator()(int i, int j, bool right) {\n    if (right)\n      resr\
    \ = issuer.folder(issuer(i, j), resr);\n    else\n      resl = issuer.folder(resl,\
    \ issuer(i, j));\n  }\n  T result() const { return issuer.folder(resl, resr);\
    \ }\n};\n\ntemplate <typename S, typename Updater> struct UpdateIssuer {\n  S\
    \ &seg;\n  const Updater &updater;\n  UpdateIssuer(S &seg, const Updater &updater)\
    \ : seg(seg), updater(updater) {}\n  void operator()(int i, int j) { seg.update(i,\
    \ j, updater); }\n  void operator()(int i, int j, bool) { (*this)(i, j); }\n};\n\
    \n} // namespace range\n\ntemplate <typename S, typename G> struct RangeHLD :\
    \ HLD<G> {\n  typedef seg::EmptyLeafBuilder empty_builder;\n\n  template <typename\
    \ Builder>\n  using builder_wrapper = range::BuilderWrapper<Builder, HLD<G>>;\n\
    \n  S seg;\n\n  explicit RangeHLD(const G &graph)\n      : HLD<G>(graph),\n  \
    \      seg(builder_wrapper<empty_builder>(this, empty_builder(this->size())))\
    \ {\n  }\n\n  template <typename T, typename Folder>\n  T query_path(int u, int\
    \ v, const Folder &folder) {\n    auto lifter = range::OrderedQueryLifter<S, T,\
    \ Folder>(seg, folder);\n    this->template operate_on_path(u, v, lifter);\n \
    \   return lifter.result();\n  }\n\n  template <typename Updater>\n  inline void\
    \ update_subtree(int u, const Updater &updater) {\n    auto issuer = range::UpdateIssuer<S,\
    \ Updater>(seg, updater);\n    this->template operate_on_subtree(u, issuer);\n\
    \  }\n\n  // FIX THOSE\n};\n\ntemplate <typename S, typename G>\nRangeHLD<S, G>\
    \ make_range_hld(const G &graph) {\n  return RangeHLD<S, G>(graph);\n}\n\n} //\
    \ namespace graph\n  // namespace lib\n\nnamespace seg {\nstruct DefaultBreakCond\
    \ {\n  template <typename Node>\n  inline bool operator()(const Node &no, int\
    \ l, int r, int i, int j) const {\n    return i > r || j < l;\n  }\n};\n\nstruct\
    \ DefaultTagCond {\n  template <typename Node>\n  inline bool operator()(const\
    \ Node &no, int l, int r, int i, int j) const {\n    return i <= l && r <= j;\n\
    \  }\n};\n\ntemplate <typename Node, typename CombinerFn = EmptyFolder<int>,\n\
    \          typename PushdownFn = EmptyPushdown,\n          typename BreakCond\
    \ = DefaultBreakCond,\n          typename TagCond = DefaultTagCond>\nstruct SegtreeBeats\
    \ {\n  const static int ROOT = 1;\n  const static int MULTIPLIER = 4;\n  const\
    \ static int SHIFT = 0;\n\n  CombinerFn combiner_fn;\n  PushdownFn pushdown_fn;\n\
    \  BreakCond break_cond;\n  TagCond tag_cond;\n\n  vector<Node> t;\n  int L, R;\n\
    \n  template <typename Builder> explicit SegtreeBeats(const Builder &builder)\
    \ {\n    pair<int, int> range = builder.range();\n    L = range.first;\n    R\
    \ = range.second;\n    assert(L >= 0 && L <= R);\n    t = vector<Node>(size()\
    \ * MULTIPLIER + SHIFT);\n    build(builder);\n  }\n\n  template <typename Builder>\n\
    \  void build(const Builder &builder, int no, int l, int r) {\n    if (l == r)\
    \ {\n      builder(t[no], l);\n    } else {\n      int mid = (l + r) / 2;\n  \
    \    build(builder, no << 1, l, mid);\n      build(builder, no << 1 | 1, mid +\
    \ 1, r);\n      t[no] = combiner_fn(t[no << 1], t[no << 1 | 1]);\n    }\n  }\n\
    \n  template <typename Builder> void build(const Builder &builder) {\n    return\
    \ build(builder, ROOT, L, R);\n  }\n\n  inline int size() const { return R - L\
    \ + 1; }\n\n  void push(int no, int l, int r) {\n    Node *left = l == r ? 0 :\
    \ &t[no << 1];\n    Node *right = l == r ? 0 : &t[no << 1 | 1];\n    pushdown_fn(t[no],\
    \ l, r, left, right);\n  }\n\n  template <typename T, typename Folder>\n  T query(int\
    \ no, int l, int r, int i, int j, const Folder &folder) {\n    if (j < l || i\
    \ > r)\n      return folder();\n    push(no, l, r);\n    if (i <= l && r <= j)\n\
    \      return folder(t[no]);\n    int mid = (l + r) / 2;\n    return folder(query<T>(no\
    \ << 1, l, mid, i, j, folder),\n                  query<T>(no << 1 | 1, mid +\
    \ 1, r, i, j, folder));\n  }\n\n  template <typename T, typename Folder>\n  inline\
    \ T query(int i, int j, const Folder &folder) {\n    return query<T>(ROOT, L,\
    \ R, i, j, folder);\n  }\n\n  template <typename Updater>\n  void update(int no,\
    \ int l, int r, int i, int j, const Updater &updater) {\n    push(no, l, r);\n\
    \    if (break_cond(t[no], l, r, i, j)) {\n      return;\n    }\n    if (tag_cond(t[no],\
    \ l, r, i, j)) {\n      updater(t[no]);\n      push(no, l, r);\n      return;\n\
    \    }\n    int mid = (l + r) / 2;\n    update(no << 1, l, mid, i, j, updater);\n\
    \    update(no << 1 | 1, mid + 1, r, i, j, updater);\n    t[no] = combiner_fn(t[no\
    \ << 1], t[no << 1 | 1]);\n  }\n\n  template <typename Updater>\n  inline void\
    \ update(int i, int j, const Updater &updater) {\n    update(ROOT, L, R, i, j,\
    \ updater);\n  }\n};\n\n} // namespace seg\n} // namespace lib\n\nusing namespace\
    \ std;\nusing namespace lib;\nusing lib::graph::Graph;\nusing lib::graph::HLD;\n\
    using lib::seg::SegtreeBeats;\n\nstruct Node {\n  int mx = 0, lz = 0;\n  Node()\
    \ {}\n  Node(int mx) : mx(mx) {}\n  operator int() const { return mx; }\n  Node\
    \ &operator+=(const int rhs) {\n    lz += rhs;\n    return *this;\n  }\n  Node\
    \ operator+(const Node &rhs) const { return Node(max(mx, rhs.mx)); }\n};\n\nstruct\
    \ Pushdown {\n  void operator()(Node &no, int l, int r, Node *lf, Node *rt) const\
    \ {\n    if (no.lz != 0) {\n      no.mx += no.lz;\n      if (l != r) {\n     \
    \   lf->lz += no.lz;\n        rt->lz += no.lz;\n      }\n      no.lz = 0;\n  \
    \  }\n  }\n};\n\nvoid solve() {\n  int n;\n  cin >> n;\n\n  Graph<> g(n);\n  for\
    \ (int i = 1; i < n; i++) {\n    int x, y;\n    cin >> x >> y;\n    x--, y--;\n\
    \    g.add_2edge(x, y);\n  }\n\n  auto f = graph::builders::make_rooted_forest(g,\
    \ {0});\n  auto hld = graph::make_range_hld<\n      SegtreeBeats<Node, seg::CombineFolder<Node>,\
    \ Pushdown>>(f);\n\n  int Q;\n  cin >> Q;\n  while (Q--) {\n    string t;\n  \
    \  cin >> t;\n    if (t == \"add\") {\n      int u, x;\n      cin >> u >> x;\n\
    \      u--;\n      auto updater = seg::AddUpdater<int>(x);\n      hld.update_subtree(u,\
    \ updater);\n    } else {\n      int x, y;\n      cin >> x >> y;\n      x--, y--;\n\
    \      auto folder = seg::MaxFolder<int>();\n      cout << hld.query_path<int>(x,\
    \ y, folder) << endl;\n    }\n  }\n}\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(0);\n  solve();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: tests/judge/result.cpp
  requiredBy: []
  timestamp: '2020-10-15 12:03:07-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tests/judge/result.cpp
layout: document
redirect_from:
- /library/tests/judge/result.cpp
- /library/tests/judge/result.cpp.html
title: tests/judge/result.cpp
---
