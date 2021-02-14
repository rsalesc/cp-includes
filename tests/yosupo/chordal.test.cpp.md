---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph.cpp
    title: Graph.cpp
  - icon: ':heavy_check_mark:'
    path: Traits.cpp
    title: Traits.cpp
  - icon: ':heavy_check_mark:'
    path: graphs/Chordal.cpp
    title: graphs/Chordal.cpp
  - icon: ':heavy_check_mark:'
    path: utils/FastList.cpp
    title: utils/FastList.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/chordal_graph_recognition
    links:
    - https://judge.yosupo.jp/problem/chordal_graph_recognition
  bundledCode: "#line 1 \"tests/yosupo/chordal.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/chordal_graph_recognition\"\
    \n\n#include <bits/stdc++.h>\n#line 1 \"Graph.cpp\"\n\n\n#line 1 \"Traits.cpp\"\
    \n\n\n#line 4 \"Traits.cpp\"\n\nnamespace lib {\nusing namespace std;\nnamespace\
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
    \ namespace lib\n\n\n#line 1 \"graphs/Chordal.cpp\"\n\n\n#line 1 \"utils/FastList.cpp\"\
    \n\n\n#line 4 \"utils/FastList.cpp\"\n\nnamespace lib {\n  using namespace std;\n\
    namespace list {\ntemplate<typename T>\nstruct Node {\n  T val;\n  Node *next\
    \ = nullptr, *prev = nullptr;\n  Node() {}\n  Node(T v) : val(v) {}\n\n  void\
    \ clear_links() {\n    if(next != nullptr) next->prev = prev;\n    if(prev !=\
    \ nullptr) prev->next = next;\n    next = prev = nullptr;\n  }\n};\n\ntemplate<typename\
    \ T>\nvoid remove(Node<T>* no) {\n  if(no != nullptr) no->clear_links();\n}\n\n\
    template<typename T>\nvoid append(Node<T>* no, Node<T>* nw) {\n  assert(no !=\
    \ nullptr);\n  remove(nw);\n  if(no->next != nullptr) no->next->prev = nw;\n \
    \ if(nw != nullptr) {\n    nw->next = no->next;\n    nw->prev = no;\n  }\n  no->next\
    \ = nw;\n}\n\ntemplate<typename T>\nvoid prepend(Node<T>* no, Node<T>* nw) {\n\
    \  assert(no != nullptr);\n  remove(nw);\n  if(no->prev != nullptr) no->prev->next\
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
    } // namespace graph\n} // namespace lib\n\n\n#line 6 \"tests/yosupo/chordal.test.cpp\"\
    \n#define int long long\nusing namespace std;\n \n#define mp make_pair\n#define\
    \ mt make_tuple\n#define pb push_back\n#define ms(v, x) memset((v), (x), sizeof(v))\n\
    #define all(v) (v).begin(), (v).end()\n#define ff first\n#define ss second\n#define\
    \ iopt ios::sync_with_stdio(false); cin.tie(0)\n#define untie(p, a, b) decltype(p.first)\
    \ a = p.first, decltype(p.second) b = p.second\n \nint gcd(int a, int b) { return\
    \ b == 0 ? a : gcd(b, a%b); }\nint power(int x, int p, int MOD) {\n    if(p ==\
    \ 0) return 1%MOD;\n    if(p == 1) return x%MOD;\n    int res = power(x, p/2,\
    \ MOD);\n    res = (long long)res*res%MOD;\n    if(p&1) res = (long long)res*x%MOD;\n\
    \    return res;\n}\n \ntypedef pair<int, int> ii;\ntypedef long double LD;\n\
    typedef vector<int> vi;\n\nusing namespace lib;\n\nint32_t main(){\n    // Scanner\
    \ sc(stdin);\n    // Printer pr(stdout);\n    iopt;\n\n    int n, m;\n    cin\
    \ >> n >> m;\n    graph::Graph<> g(n);\n\n    for(int i = 0; i < m; i++) {\n \
    \     int a, b;\n      cin >> a >> b;\n      g.add_2edge(a, b);\n    }\n\n   \
    \ auto ch = graph::make_chordal(g);\n    if(ch.is_valid()) {\n      cout << \"\
    YES\" << endl;\n      for(int x : ch.order) cout << x << \" \";\n      cout <<\
    \ endl;\n    } else {\n      cout << \"NO\" << endl;\n      cout << ch.induced_cycle().size()\
    \ << endl;\n      for(int x : ch.induced_cycle()) cout << x << \" \";\n      cout\
    \ << endl;\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/chordal_graph_recognition\"\
    \n\n#include <bits/stdc++.h>\n#include \"Graph.cpp\"\n#include \"graphs/Chordal.cpp\"\
    \n#define int long long\nusing namespace std;\n \n#define mp make_pair\n#define\
    \ mt make_tuple\n#define pb push_back\n#define ms(v, x) memset((v), (x), sizeof(v))\n\
    #define all(v) (v).begin(), (v).end()\n#define ff first\n#define ss second\n#define\
    \ iopt ios::sync_with_stdio(false); cin.tie(0)\n#define untie(p, a, b) decltype(p.first)\
    \ a = p.first, decltype(p.second) b = p.second\n \nint gcd(int a, int b) { return\
    \ b == 0 ? a : gcd(b, a%b); }\nint power(int x, int p, int MOD) {\n    if(p ==\
    \ 0) return 1%MOD;\n    if(p == 1) return x%MOD;\n    int res = power(x, p/2,\
    \ MOD);\n    res = (long long)res*res%MOD;\n    if(p&1) res = (long long)res*x%MOD;\n\
    \    return res;\n}\n \ntypedef pair<int, int> ii;\ntypedef long double LD;\n\
    typedef vector<int> vi;\n\nusing namespace lib;\n\nint32_t main(){\n    // Scanner\
    \ sc(stdin);\n    // Printer pr(stdout);\n    iopt;\n\n    int n, m;\n    cin\
    \ >> n >> m;\n    graph::Graph<> g(n);\n\n    for(int i = 0; i < m; i++) {\n \
    \     int a, b;\n      cin >> a >> b;\n      g.add_2edge(a, b);\n    }\n\n   \
    \ auto ch = graph::make_chordal(g);\n    if(ch.is_valid()) {\n      cout << \"\
    YES\" << endl;\n      for(int x : ch.order) cout << x << \" \";\n      cout <<\
    \ endl;\n    } else {\n      cout << \"NO\" << endl;\n      cout << ch.induced_cycle().size()\
    \ << endl;\n      for(int x : ch.induced_cycle()) cout << x << \" \";\n      cout\
    \ << endl;\n    }\n    return 0;\n}\n"
  dependsOn:
  - Graph.cpp
  - Traits.cpp
  - utils/Wrappers.cpp
  - graphs/Chordal.cpp
  - utils/FastList.cpp
  isVerificationFile: true
  path: tests/yosupo/chordal.test.cpp
  requiredBy: []
  timestamp: '2021-02-13 23:55:16-03:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/yosupo/chordal.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/chordal.test.cpp
- /verify/tests/yosupo/chordal.test.cpp.html
title: tests/yosupo/chordal.test.cpp
---
