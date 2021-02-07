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
  bundledCode: "#line 1 \"tests/judge/inlined.cpp\"\n#include <bits/stdc++.h>\n#ifndef\
    \ _LIB_GRAPH\n#define _LIB_GRAPH\n\n#ifndef _LIB_TRAITS\n#define _LIB_TRAITS\n\
    \n\nnamespace lib {\n  using namespace std;\nnamespace traits {\n\n  template<typename\
    \ Iterator>\n  using IteratorCategory =\n    typename iterator_traits<Iterator>::iterator_category;\n\
    \n  template<typename Container>\n  using IteratorCategoryOf = IteratorCategory<typename\
    \ Container::iterator>;\n\n  template<typename Iterator>\n  using IsRandomIterator\
    \ =\n    is_base_of<random_access_iterator_tag, IteratorCategory<Iterator>>;\n\
    \n  template<typename Iterator>\n  using IsInputIterator =\n    is_base_of<input_iterator_tag,\
    \ IteratorCategory<Iterator>>;\n\n  template<typename Iterator>\n  using IsBidirectionalIterator\
    \ =\n    is_base_of<bidirectional_iterator_tag, IteratorCategory<Iterator>>;\n\
    \n  template<typename Container>\n  using HasRandomIterator =\n    is_base_of<random_access_iterator_tag,\
    \ IteratorCategoryOf<Container>>;\n\n  template<typename Container>\n  using HasInputIterator\
    \ =\n    is_base_of<input_iterator_tag, IteratorCategoryOf<Container>>;\n\n  template<typename\
    \ Container>\n  using HasBidirectionalIterator =\n    is_base_of<bidirectional_iterator_tag,\
    \ IteratorCategoryOf<Container>>;\n}\n}\n\n#endif\n\n\nnamespace lib {\n  using\
    \ namespace std;\nnamespace graph {\n  template<typename T>\n  struct Edge {\n\
    \    const int from, to;\n    T data;\n  };\n\n  template<>\n  struct Edge<void>\
    \ { const int from, to; };\n\n  template<typename T>\n  struct VertexWrapper {\
    \ T data; };\n\n  template<>\n  struct VertexWrapper<void> {};\n\n  template<typename\
    \ V = void, \n           typename E = void>\n  struct Graph {\n    typedef Graph<V,\
    \ E> self_type;\n    typedef vector<vector<int>> adj_list;\n    typedef Edge<E>\
    \ edge_type;\n    typedef VertexWrapper<V> vertex_type;\n\n    vector<edge_type>\
    \ edges;\n    adj_list adj;\n\n    vector<vertex_type> vertices;\n\n    class\
    \ iterator\n    {\n      public:\n            typedef iterator self_type;\n  \
    \          typedef edge_type value_type;\n            typedef edge_type& reference;\n\
    \            typedef edge_type* pointer;\n            typedef std::forward_iterator_tag\
    \ iterator_category;\n            typedef int difference_type;\n            iterator(vector<int>*\
    \ adj, vector<edge_type>* edges, int ptr = 0)\n              : adj_(adj), edges_(edges),\
    \ ptr_(ptr) { }\n            self_type operator++() { ptr_++; return *this; }\n\
    \            self_type operator++(int junk) { self_type i = *this; ptr_++; return\
    \ i; }\n            reference operator*() { return (*edges_)[(*adj_)[ptr_]]; }\n\
    \            pointer operator->() { return &(*edges_)[(*adj_)[ptr_]]; }\n    \
    \        bool operator==(const self_type& rhs) const { \n              return\
    \ adj_ == rhs.adj_ && ptr_ == rhs.ptr_;\n            }\n            bool operator!=(const\
    \ self_type& rhs) const { return !(*this == rhs); }\n        private:\n      \
    \      vector<int>* adj_;\n            vector<edge_type>* edges_;\n          \
    \  int ptr_;\n    };\n\n    class const_iterator\n    {\n      public:\n     \
    \       typedef const_iterator self_type;\n            typedef edge_type value_type;\n\
    \            typedef edge_type& reference;\n            typedef edge_type* pointer;\n\
    \            typedef std::forward_iterator_tag iterator_category;\n          \
    \  typedef int difference_type;\n            const_iterator(vector<int>* adj,\
    \ vector<edge_type>* edges, int ptr = 0) \n              : adj_(adj), edges_(edges),\
    \ ptr_(ptr) { }\n            self_type operator++() { ptr_++; return *this; }\n\
    \            self_type operator++(int junk) { self_type i = *this; ptr_++; return\
    \ i; }\n            const value_type& operator*() { return (*edges_)[(*adj_)[ptr_]];\
    \ }\n            const value_type* operator->() { return &(*edges_)[(*adj_)[ptr_]];\
    \ }\n            bool operator==(const self_type& rhs) const { \n            \
    \  return adj_ == rhs.adj_ && ptr_ == rhs.ptr_;\n            }\n            bool\
    \ operator!=(const self_type& rhs) const { return !(*this == rhs); }\n       \
    \ private:\n            vector<int>* adj_;\n            vector<edge_type>* edges_;\n\
    \            int ptr_;\n    };\n\n    struct iterable {\n      vector<int>* adj_;\n\
    \      vector<edge_type>* edges_;\n\n      iterable(vector<int>* adj, vector<edge_type>*\
    \ edges)\n        : adj_(adj), edges_(edges) {}\n\n      inline iterator begin()\
    \ { return iterator(adj_, edges_); }\n      inline iterator end() { return iterator(adj_,\
    \ edges_, adj_->size()); }\n\n      inline const_iterator cbegin() const { return\
    \ const_iterator(adj_, edges_); }\n      inline const_iterator cend() const {\
    \ return const_iterator(adj_, edges_, adj_->size()); }\n\n      inline const_iterator\
    \ begin() const { return cbegin(); }\n      inline const_iterator end() const\
    \ { return cend(); }\n\n      inline edge_type& operator[](int i) { return (*edges_)[(*adj_)[i]];\
    \ }\n      inline const edge_type& operator[](int i) const { return (*edges_)[(*adj_)[i]];\
    \ }\n\n      inline int size() const { return adj_->size(); }\n    };\n\n    Graph()\
    \ {}\n\n    template<typename S = V, typename enable_if<is_void<S>::value>::type*\
    \ = nullptr>\n    Graph(size_t n) : adj(n) {}\n\n    template<typename S = V,\
    \ typename enable_if<!is_void<S>::value>::type* = nullptr>\n    Graph(size_t n)\
    \ : adj(n), vertices(n) {}\n\n    inline iterable n_edges(int i) { return iterable(&adj[i],\
    \ &edges); }\n    inline const iterable n_edges(int i) const { \n      return\
    \ iterable(const_cast<vector<int>*>(&adj[i]), \n                      const_cast<vector<edge_type>*>(&edges));\
    \ \n    }\n\n    inline int size() const { return adj.size(); }\n    inline edge_type&\
    \ edge(int i) { return edges[i]; }\n    inline edge_type edge(int i) const { return\
    \ edges[i]; }\n\n    inline vector<edge_type> all_edges() const { return edges;\
    \ }\n\n    template<typename S = V, typename enable_if<!is_void<S>::value>::type*\
    \ = nullptr>\n    inline S& vertex(int i) { return vertices[i]; }\n\n    template<typename\
    \ S = V, typename enable_if<!is_void<S>::value>::type* = nullptr>\n    inline\
    \ V vertex(int i) const { return vertices[i]; }\n\n    template<typename S = V,\
    \ typename enable_if<is_void<S>::value>::type* = nullptr>\n    inline void add_vertex()\
    \ { adj.emplace_back(); }\n\n    template<typename S = V, typename enable_if<!is_void<S>::value>::type*\
    \ = nullptr>\n    inline S& add_vertex() {\n      adj.emplace_back();\n      return\
    \ vertices.emplace_back().data;\n    }\n\n    template<typename S = E, typename\
    \ enable_if<is_void<S>::value>::type* = nullptr>\n    inline void add_edge(int\
    \ u, int v) {\n      adj[u].push_back(edges.size());\n      edges.push_back({u,\
    \ v});\n    }\n    \n    template<typename S = E, typename enable_if<!is_void<S>::value>::type*\
    \ = nullptr>\n    inline S& add_edge(int u, int v) {\n      adj[u].push_back(edges.size());\n\
    \      edges.push_back({u, v});\n      return edges.back();\n    }\n\n    void\
    \ add_2edge(int u, int v) {\n      add_edge(u, v);\n      add_edge(v, u);\n  \
    \  }\n\n    template<typename S = E, typename enable_if<!is_void<S>::value>::type*\
    \ = nullptr>\n    inline void add_2edge(int u, int v, const S& data) {\n     \
    \ add_edge(u, v).data = data;\n      add_edge(v, u).data = data;\n    }\n  };\n\
    \n  template<typename V = void, typename E = void>\n  struct RootedForest : public\
    \ Graph<V, E> {\n    typedef RootedForest<V, E> self_type;\n    using typename\
    \ Graph<V, E>::adj_list;\n    using typename Graph<V, E>::edge_type;\n    using\
    \ Graph<V, E>::Graph;\n    using Graph<V, E>::adj;\n    using Graph<V, E>::edge;\n\
    \    vector<int> p, pe;\n\n    void build_parents() {\n      if((int)p.size()\
    \ == this->size()) return;\n\n      int n = this->size();\n      stack<int> st;\n\
    \      vector<bool> vis(n);\n      p.assign(n, -1), pe.assign(n, -1);\n      for(int\
    \ i = 0; i < n; i++) {\n        if(!vis[i]) {\n          st.push(i);\n       \
    \   vis[i] = true;\n          while(!st.empty()) {\n            int u = st.top();\n\
    \            st.pop();\n\n            for(int k : adj[u]) {\n              int\
    \ v = edge(k).to;\n              vis[v] = true;\n              st.push(v), pe[v]\
    \ = k, p[v] = u;\n            }\n          }\n        }\n      }\n    }\n\n  \
    \  inline int parent(int i) const {\n      const_cast<self_type*>(this)->build_parents();\n\
    \      return p[i]; \n    }\n\n    inline bool is_root(int i) const { return parent(i)\
    \ != -1; }\n\n    inline edge_type& parent_edge(int i) { \n      build_parents();\n\
    \      return edge(pe[i]); \n    }\n    inline edge_type& parent_edge(int i) const\
    \ { \n      const_cast<self_type*>(this)->build_parents();\n      return edge(pe[i]);\
    \ \n    }\n\n    vector<int> roots() const {\n      vector<int> res;\n      const_cast<self_type*>(this)->build_parents();\n\
    \      int n = this->size();\n\n      for(int i = 0; i < n; i++)\n        if(p[i]\
    \ == -1) res.push_back(i);\n      return res;\n    }\n  };\n\n  template<typename\
    \ V = void, typename E = void>\n  struct RootedTree : public RootedForest<V, E>\
    \ {\n    using typename RootedForest<V, E>::adj_list;\n    int root;\n\n    RootedTree(int\
    \ n, int root) : RootedForest<V, E>(n) {\n      assert(n > 0);\n      assert(root\
    \ < n);\n      this->root = root;\n    }\n\n    RootedTree(const adj_list& adj,\
    \ int root) : RootedForest<V, E>(adj) {\n      assert(adj.size() > 0);\n     \
    \ assert(root < adj.size());\n      this->root = root;\n    }\n  };\n\n  namespace\
    \ builders {\n    namespace {\n      template<typename F, typename G>\n      void\
    \ dfs_rooted_forest(F& forest, const G& graph, int u, vector<bool>& vis) {\n \
    \       vis[u] = true;\n        for(const auto& ed : graph.n_edges(u)) {\n   \
    \       int v = ed.to;\n          if(!vis[v]) {\n            forest.add_edge(u,\
    \ v);\n            dfs_rooted_forest(forest, graph, v, vis);\n          }\n  \
    \      }\n      }\n\n      template<typename A, typename B>\n      RootedForest<A,\
    \ B> make_rooted_forest(const Graph<A, B>& graph,\n                          \
    \                  const vector<int>& roots) {\n        RootedForest<A, B> res(graph.size());\n\
    \        vector<bool> vis(graph.size());\n        for(int i : roots)\n       \
    \   if(!vis[i])\n            dfs_rooted_forest(res, graph, i, vis);\n        for(int\
    \ i = 0; i < graph.size(); i++)\n          if(!vis[i])\n            dfs_rooted_forest(res,\
    \ graph, i, vis);\n        return res;\n      }\n    }\n  }  // namespace builders\n\
    }  // namespace graph\n}  // namespace lib\n\n#endif\n\n#ifndef _LIB_RANGE_HLD\n\
    #define _LIB_RANGE_HLD\n\n#ifndef _LIB_HLD\n#define _LIB_HLD\n\n\n#ifndef _LIB_SEGTREE\n\
    #define _LIB_SEGTREE\n\n\nnamespace lib {\n  using namespace std;\nnamespace seg\
    \ {\n  struct LeafBuilder {\n    template<typename Node>\n    void operator()(Node&\
    \ no, int i) const {}\n    inline pair<int, int> range() const { return {0, 0};\
    \ }\n  };\n\n  struct EmptyLeafBuilder : LeafBuilder {\n    int n;\n    explicit\
    \ EmptyLeafBuilder(int n) : n(n) {}\n    inline pair<int, int> range() const {\
    \ return {0, n-1}; }\n  };\n\n  template<typename RandomIterator>\n  struct RangeLeafBuilder\
    \ : LeafBuilder {\n    RandomIterator begin, end;\n    explicit RangeLeafBuilder(RandomIterator\
    \ begin, RandomIterator end)\n      : begin(begin), end(end) {}\n\n    template<typename\
    \ Node>\n    inline void operator()(Node& no, int i) const { no = *(begin + i);\
    \ }\n\n    inline pair<int, int> range() const { return {0, end-begin-1}; }\n\
    \  };\n\n  EmptyLeafBuilder make_builder(int n) { return EmptyLeafBuilder(n);\
    \ }\n\n  template<typename RandomIterator>\n  RangeLeafBuilder<RandomIterator>\
    \ make_builder(RandomIterator begin, \n                                      \
    \          RandomIterator end) {\n    return RangeLeafBuilder<RandomIterator>(begin,\
    \ end);\n  }\n\n  template<typename T>\n  RangeLeafBuilder<typename vector<T>::const_iterator>\n\
    \  make_builder(const vector<T>& v) {\n    return RangeLeafBuilder<typename vector<T>::const_iterator>(v.begin(),\
    \ \n                                                                v.end());\n\
    \  }\n\n  template<typename T>\n  struct CombineFolder {\n    inline T operator()()\
    \ const { return T(); }\n\n    template<typename Node>\n    inline T operator()(const\
    \ Node& no) const { return T(no); }\n\n    inline T operator()(const T& a, const\
    \ T& b) const { return a + b; }\n  };\n\n  template<typename T>\n  struct EmptyFolder\
    \ : CombineFolder<T> {\n    using CombineFolder<T>::operator();\n\n    template<typename\
    \ Node>\n    inline T operator()(const Node& no) const { return T(); }\n    inline\
    \ T operator()(const T& a, const T& b) const { return T(); }\n  };\n\n  template<typename\
    \ T>\n  struct SumFolder : CombineFolder<T> {};\n  \n  template<typename T>\n\
    \  struct MaxFolder : CombineFolder<T> {\n    using CombineFolder<T>::operator();\n\
    \    inline T operator()() const { return numeric_limits<T>::min(); }\n    inline\
    \ T operator()(const T& a, const T& b) const { return max(a, b); }\n  };\n\n \
    \ template<typename T>\n  struct MinFolder : CombineFolder<T> {\n    using CombineFolder<T>::operator();\n\
    \    inline T operator()() const { return numeric_limits<T>::max(); }\n    inline\
    \ T operator()(const T& a, const T& b) const { return min(a, b); }\n  };\n\n \
    \ template<typename T>\n  struct SingleValueUpdater {\n    T value;\n    explicit\
    \ SingleValueUpdater(T val) : value(val) {}\n  };\n\n  template<typename T>\n\
    \  struct SetUpdater : SingleValueUpdater<T> {\n    using SingleValueUpdater<T>::SingleValueUpdater;\n\
    \n    template<typename Node>\n    inline void operator()(Node& no) const { no\
    \ = this->value; }\n  };\n\n  template<typename T>\n  struct AddUpdater: SingleValueUpdater<T>\
    \ {\n    using SingleValueUpdater<T>::SingleValueUpdater;\n\n    template<typename\
    \ Node>\n    inline void operator()(Node& no) const { no += this->value; }\n \
    \ };\n\n  struct EmptyPushdown {\n    template<typename Node>\n    inline void\
    \ operator()(Node& no, int l, int r, \n                    Node* ln, Node* rn)\
    \ const {}\n  };\n}  // namespace seg\n}  // namespace lib\n\n#endif\n\n\n\nnamespace\
    \ lib {\n  using namespace std;\nnamespace graph {\n  namespace {\n    void empty_lifter(int\
    \ a, int b) {}\n  }\n\n  template<typename G>\n  struct HLD {\n    G graph;\n\
    \    vector<int> in, out, rin;\n    vector<int> L, sz, ch;\n    int tempo;\n\n\
    \    HLD(const G& g) \n      : graph(g), in(g.size()), out(g.size()), rin(g.size()),\
    \ L(g.size()),\n        sz(g.size()), ch(g.size()) {\n        build();\n    }\n\
    \n    inline int size() const { return graph.size(); }\n\n    void dfs0(int u)\
    \ {\n      sz[u] = 1;\n      for(auto& k : graph.adj[u]) {\n        int v = graph.edge(k).to;\n\
    \        L[v] = L[u] + 1;\n        dfs0(v);\n        if(sz[v] > sz[graph.edge(graph.adj[u][0]).to])\n\
    \          swap(k, graph.adj[u][0]);\n        sz[u] += sz[v];\n      }\n    }\n\
    \n    void dfs1(int u) {\n      in[u] = tempo++;\n      rin[in[u]] = u;\n\n  \
    \    if(graph.adj[u].size() > 0) {\n        int v = graph.edge(graph.adj[u][0]).to;\n\
    \        ch[v] = ch[u];\n        dfs1(v);\n        for(size_t i = 1; i < graph.adj[u].size();\
    \ i++) {\n          v = graph.edge(graph.adj[u][i]).to;\n          ch[v] = v;\n\
    \          dfs1(v);\n        }\n      }\n      out[u] = tempo;\n    }\n\n    void\
    \ build() {\n      vector<int> roots = graph.roots();\n      for(int i : roots)\
    \ dfs0(i);\n      tempo = 0;\n      for(int i : roots) dfs1(i);\n    }\n\n   \
    \ template<typename Lifter>\n    inline void operate_on_subtree(int u, Lifter&\
    \ lifter) {\n      lifter(in[u], out[u]-1, false);\n    }\n\n    template<typename\
    \ T, typename QueryIssuer>\n    inline T query_on_subtree(int u, const QueryIssuer&\
    \ issuer) {\n      return issuer(in[u], out[u]-1);\n    }\n\n    template<typename\
    \ Lifter>\n    inline void operate_on_subtree_edges(int u, Lifter& lifter) {\n\
    \      if(in[u]+2 <= out[u]) lifter(in[u]+1, out[u]-1, false);\n    }\n\n    template<typename\
    \ T, typename QueryIssuer>\n    inline void query_on_subtree_edges(int u, const\
    \ QueryIssuer& issuer) {\n      assert(in[u]+2 <= out[u]);\n      return issuer(in[u]+1,\
    \ out[u]-1);\n    }\n\n    template<bool is_edge, typename Lifter>\n    int _query_path(int\
    \ u, int v, Lifter& lifter) {\n      int inv = 0;\n      for(; ch[u] != ch[v];\
    \ u = graph.parent(ch[u])) {\n        if(L[ch[u]] < L[ch[v]])\n          swap(u,\
    \ v), inv ^= 1;\n        lifter(in[ch[u]], in[u], (bool)inv);\n      }\n     \
    \ if(L[u] > L[v]) swap(u, v), inv ^= 1;\n      inv ^= 1;\n      if(is_edge &&\
    \ in[u]+1 <= in[v])\n        lifter(in[u]+1, in[v], (bool)inv);\n      else if(!is_edge)\n\
    \        lifter(in[u], in[v], (bool)inv);\n      return u;\n    }\n\n    template<typename\
    \ Lifter>\n    inline int operate_on_path(int u, int v, Lifter& lifter) {\n  \
    \    return _query_path<false>(u, v, lifter);\n    }\n\n    template<typename\
    \ Lifter>\n    inline int operate_on_path_edges(int u, int v, Lifter& lifter)\
    \ {\n      return _query_path<true>(u, v, lifter);\n    }\n\n    template<typename\
    \ Op>\n    inline void operate_on_vertex(int u, Op& op) {\n      op(in[u]);\n\
    \    }\n\n    template<typename T, typename QueryIssuer>\n    inline T query_on_vertex(int\
    \ u, const QueryIssuer& issuer) {\n      return issuer(in[u]);\n    }\n\n    inline\
    \ int lca(int u, int v) {\n      return _query_path<false>(u, v, empty_lifter);\n\
    \    }\n  };\n\n  template<typename G>\n  HLD<G> make_hld(const G& graph) {\n\
    \    return HLD<G>(graph);\n  }\n}  // namespace graph\n}  // namespace lib\n\n\
    #endif\n\n\nnamespace lib {\n  using namespace std;\nnamespace graph {\nnamespace\
    \ range {\n  template<typename Builder, \n           typename H>\n  struct BuilderWrapper\
    \ {\n    H* hld;\n    Builder builder;\n\n    explicit BuilderWrapper(H* hld,\
    \ const Builder& builder) \n      : hld(hld), builder(builder) {}\n\n    template<typename\
    \ Node>\n    void operator()(Node& no, int i) const { \n      builder(no, hld->rin[i]);\
    \ \n    }\n\n    pair<int, int> range() const { return {0, hld->size() - 1}; }\n\
    \  };\n\n  template<typename Builder, typename H>\n  struct RebuilderWrapper :\
    \ BuilderWrapper<Builder, H> {\n    using BuilderWrapper<Builder, H>::BuilderWrapper;\n\
    \    using BuilderWrapper<Builder, H>::builder;\n    template<typename Node>\n\
    \    void operator()(Node& no, const Node& left, const Node& right) const {\n\
    \      builder(no, left, right);\n    }\n  };\n\n  template<typename S, typename\
    \ T, typename Folder>\n  struct QueryIssuer {\n    S& seg;\n    const Folder&\
    \ folder;\n    QueryIssuer(S& seg, const Folder& folder) : seg(seg), folder(folder)\
    \ {}\n    T operator()(int i) const {\n      seg.template query_element<T>(i,\
    \ folder);\n    }\n    T operator()(int i, int j) const {\n      return seg.template\
    \ query<T>(i, j, folder);\n    }\n  };\n\n  template<typename S, typename T, typename\
    \ Folder>\n  struct QueryLifter {\n    QueryIssuer<S, T, Folder> issuer;\n   \
    \ T res;\n    QueryLifter(S& seg, const Folder& folder) \n      : issuer(seg,\
    \ folder), res(folder()) {}\n    void operator()(int i, int j, bool) {\n     \
    \ res = issuer.folder(res, issuer(i, j));\n    }\n    T result() const { return\
    \ res; }\n  };\n\n  template<typename S, typename T, typename Folder>\n  struct\
    \ OrderedQueryLifter : QueryLifter<S, T, Folder> {\n    using QueryLifter<S, T,\
    \ Folder>::issuer;\n    T resl, resr;\n\n    OrderedQueryLifter(S& seg, const\
    \ Folder& folder)\n      : QueryLifter<S, T, Folder>(seg, folder), \n        resl(folder()),\
    \ resr(folder()) {}\n    \n    void operator()(int i, int j, bool right) {\n \
    \     if(right)\n        resr = issuer.folder(issuer(i, j), resr);\n      else\n\
    \        resl = issuer.folder(resl, issuer(i, j));\n    }\n    T result() const\
    \ { return issuer.folder(resl, resr); }\n  };\n\n  template<typename S, typename\
    \ Updater>\n  struct UpdateIssuer {\n    S& seg;\n    const Updater& updater;\n\
    \    UpdateIssuer(S& seg, const Updater& updater)\n      : seg(seg), updater(updater)\
    \ {}\n    void operator()(int i, int j) { seg.update(i, j, updater); }\n    void\
    \ operator()(int i, int j, bool) { (*this)(i, j); }\n  };\n\n  template<typename\
    \ S, typename Updater>\n  struct SplashIssuer {\n    S& seg;\n    const Updater&\
    \ updater;\n    SplashIssuer(S& seg, const Updater& updater)\n      : seg(seg),\
    \ updater(updater) {}\n    void operator()(int i, int j) { seg.splash(i, j, updater);\
    \ }\n    void operator()(int i, int j, bool) { (*this)(i, j); }\n  };\n\n  template<typename\
    \ S, typename Beater>\n  struct BeatIssuer {\n    S& seg;\n    const Beater& beater;\n\
    \    BeatIssuer(S& seg, const Beater& beater)\n      : seg(seg), beater(beater)\
    \ {}\n    void operator()(int i, int j) { seg.beat(i, j, beater); }\n    void\
    \ operator()(int i, int j, bool) { (*this)(i, j); }\n  };\n}  // namespace range\n\
    \n  template<typename S,\n           typename G>\n  struct RangeHLD : HLD<G> {\n\
    \    typedef seg::EmptyLeafBuilder empty_builder;\n\n    template<typename Builder>\n\
    \    using builder_wrapper = range::BuilderWrapper<Builder, HLD<G>>;\n    template<typename\
    \ Rebuilder>\n    using rebuilder_wrapper = range::RebuilderWrapper<Rebuilder,\
    \ HLD<G>>;\n\n    S seg;\n\n    explicit RangeHLD(const G& graph) \n      : HLD<G>(graph),\n\
    \        seg(builder_wrapper<empty_builder>(this, empty_builder(this->size())))\
    \ {}\n\n    template<typename Builder>\n    RangeHLD(const G& graph, const Builder&\
    \ builder)\n      : HLD<G>(graph), \n        seg(builder_wrapper<Builder>(this,\
    \ builder)) {}\n\n    template<typename Builder>\n    void build(const Builder&\
    \ builder) {\n      seg.build(builder_wrapper<Builder>(builder));\n    }\n   \
    \ \n    template<typename Rebuilder>\n    void rebuild(const Rebuilder& rebuilder)\
    \ {\n      seg.rebuild(rebuilder_wrapper<Rebuilder>(rebuilder));\n    }\n\n  \
    \  template<typename T, typename Folder>\n    inline T query_subtree(int u, const\
    \ Folder& folder) {\n      return this->template \n        query_on_subtree<T>(u,\
    \ range::QueryIssuer<S, T, Folder>(seg, folder));\n    }\n\n    template<typename\
    \ T, typename Folder>\n    inline T query_subtree_edges(int u, const Folder& folder)\
    \ {\n      return this->template\n        query_on_subtree_edges(u, range::QueryIssuer<S,\
    \ T, Folder>(seg, folder));\n    }\n\n    template<typename T, typename Folder>\n\
    \    inline T query_vertex(int u, const Folder& folder) {\n      return this->template\n\
    \        query_on_vertex(u, range::QueryIssuer<S, T, Folder>(seg, folder));\n\
    \    }\n\n    template<typename T, typename Folder>\n    T query_path(int u, int\
    \ v, const Folder& folder) {\n      auto lifter = range::OrderedQueryLifter<S,\
    \ T, Folder>(seg, folder);\n      this->template\n        operate_on_path(u, v,\
    \ lifter);\n      return lifter.result();\n    }\n\n    template<typename T, typename\
    \ Folder>\n    T query_path_edges(int u, int v, const Folder& folder) {\n    \
    \  auto lifter = range::OrderedQueryLifter<S, T, Folder>(seg, folder);\n     \
    \ this->template\n        operate_on_path_edges(u, v, lifter);\n      return lifter.result();\n\
    \    }\n\n    template<typename Updater>\n    inline void update_subtree(int u,\
    \ const Updater& updater) {\n      auto issuer = range::UpdateIssuer<S, Updater>(seg,\
    \ updater);\n      this->template operate_on_subtree(u, issuer);\n    }\n\n  \
    \  template<typename Updater>\n    inline void update_subtree_edges(int u, const\
    \ Updater& updater) {\n      auto issuer = range::UpdateIssuer<S, Updater>(seg,\
    \ updater);\n      this->template operate_on_subtree_edges(u, issuer);\n    }\n\
    \n    template<typename Updater>\n    inline void update_path(int u, int v, const\
    \ Updater& updater) {\n      auto issuer = range::UpdateIssuer<S, Updater>(seg,\
    \ updater);\n      this->template operate_on_path(u, v, issuer);\n    }\n\n  \
    \  template<typename Updater>\n    inline void update_path_edges(int u, int v,\
    \ const Updater& updater) {\n      auto issuer = range::UpdateIssuer<S, Updater>(seg,\
    \ updater);\n      this->template operate_on_path_edges(u, v, issuer);\n    }\n\
    \n    template<typename Beater>\n    inline void beat_subtree(int u, const Beater&\
    \ beater) {\n      auto issuer = range::BeatIssuer<S, Beater>(seg, beater);\n\
    \      this->template operate_on_subtree(u, issuer);\n    }\n\n    template<typename\
    \ Beater>\n    inline void beat_subtree_edges(int u, const Beater& beater) {\n\
    \      auto issuer = range::BeatIssuer<S, Beater>(seg, beater);\n      this->template\
    \ operate_on_subtree_edges(u, issuer);\n    }\n\n    template<typename Beater>\n\
    \    inline void beat_path(int u, int v, const Beater& beater) {\n      auto issuer\
    \ = range::BeatIssuer<S, Beater>(seg, beater);\n      this->template operate_on_path(u,\
    \ v, issuer);\n    }\n\n    template<typename Beater>\n    inline void beat_path_edges(int\
    \ u, int v, const Beater& beater) {\n      auto issuer = range::BeatIssuer<S,\
    \ Beater>(seg, beater);\n      this->template operate_on_path_edges(u, v, issuer);\n\
    \    }\n\n    // FIX THOSE \n    template<typename Updater>\n    inline void update_element(int\
    \ idx, const Updater& updater) {\n      seg.update_element(idx, updater);\n  \
    \  }\n\n    template<typename Updater>\n    inline void splash(int i, int j, const\
    \ Updater& updater) {\n      seg.splash(i, j, updater);\n    }\n  };\n\n  template<typename\
    \ S, typename G>\n  RangeHLD<S, G> make_range_hld(const G& graph) {\n    return\
    \ RangeHLD<S, G>(graph);\n  }\n\n  template<typename S, typename G, typename Builder>\n\
    \  RangeHLD<S, G> make_range_hld(const G& graph, const Builder& builder) {\n \
    \   return RangeHLD<S, G>(graph, builder);\n  }\n\n}  // namespace graph\n}  //\
    \ namespace lib\n\n#endif\n\n\n#ifndef _LIB_SEGTREE_BEATS\n#define _LIB_SEGTREE_BEATS\n\
    \n\n\nnamespace lib {\n  using namespace std;\nnamespace seg { \n  struct DefaultBreakCond\
    \ {\n    template<typename Node>\n    inline bool operator()(const Node& no, int\
    \ l, int r, int i, int j) const {\n      return i > r || j < l;\n    }\n  };\n\
    \n  struct DefaultTagCond {\n    template<typename Node>\n    inline bool operator()(const\
    \ Node& no, int l, int r, int i, int j) const {\n      return i <= l && r <= j;\n\
    \    }\n  };\n\n  template<typename Node, \n           typename CombinerFn = EmptyFolder<int>,\n\
    \           typename PushdownFn = EmptyPushdown, \n           typename BreakCond\
    \ = DefaultBreakCond, \n           typename TagCond = DefaultTagCond>\n  struct\
    \ SegtreeBeats {\n    const static int ROOT = 1;\n    const static int MULTIPLIER\
    \ = 4;\n    const static int SHIFT = 0;\n\n\n    CombinerFn combiner_fn;\n   \
    \ PushdownFn pushdown_fn;\n    BreakCond break_cond;\n    TagCond tag_cond;\n\n\
    \    vector<Node> t;\n    int L, R;\n\n    template<typename Builder>\n    explicit\
    \ SegtreeBeats(const Builder& builder) {\n      pair<int, int> range = builder.range();\n\
    \      L = range.first;\n      R = range.second;\n      assert(L >= 0 && L <=\
    \ R);\n      t = vector<Node>(size() * MULTIPLIER + SHIFT);\n      build(builder);\n\
    \    }\n\n    template<typename Builder>\n    void build(const Builder& builder,\
    \ int no, int l, int r) {\n      if(l == r) {\n        builder(t[no], l);\n  \
    \    } else {\n        int mid = (l+r)/2;\n        build(builder, no<<1, l, mid);\n\
    \        build(builder, no<<1|1, mid+1, r);\n        t[no] = combiner_fn(t[no<<1],\
    \ t[no<<1|1]);\n      }\n    }\n\n    template<typename Builder>\n    void build(const\
    \ Builder& builder) {\n      return build(builder, ROOT, L, R);\n    }\n\n   \
    \ inline int size() const { return R-L+1; }\n\n    void push(int no, int l, int\
    \ r) {\n      Node* left = l == r ? 0 : &t[no<<1];\n      Node* right = l == r\
    \ ? 0 : &t[no<<1|1];\n      pushdown_fn(t[no], l, r, left, right);\n    }\n\n\
    \    template<typename T, typename Folder>\n    T query(int no, int l, int r,\
    \ int i, int j, const Folder& folder) {\n      if(j < l || i > r) return folder();\n\
    \      push(no, l, r);\n      if(i <= l && r <= j) return folder(t[no]);\n   \
    \   int mid = (l+r)/2;\n      return folder(\n          query<T>(no<<1, l, mid,\
    \ i, j, folder),\n          query<T>(no<<1|1, mid+1, r, i, j, folder)\n      );\n\
    \    }\n\n    template<typename T, typename Folder>\n    inline T query(int i,\
    \ int j, const Folder& folder) {\n      return query<T>(ROOT, L, R, i, j, folder);\n\
    \    }\n\n    template<typename Updater>\n    void update(int no, int l, int r,\
    \ int i, int j, const Updater& updater) {\n      push(no, l, r);\n      if(break_cond(t[no],\
    \ l, r, i, j)) {\n        return;\n      }\n      if(tag_cond(t[no], l, r, i,\
    \ j)) {\n        updater(t[no]);\n        push(no, l, r);\n        return;\n \
    \     }\n      int mid = (l+r)/2;\n      update(no<<1, l, mid, i, j, updater);\n\
    \      update(no<<1|1, mid+1, r, i, j, updater);\n      t[no] = combiner_fn(t[no<<1],\
    \ t[no<<1|1]);\n    }\n\n    template<typename Updater>\n    inline void update(int\
    \ i, int j, const Updater& updater) {\n      update(ROOT, L, R, i, j, updater);\n\
    \    }\n\n    template<typename Beater>\n    void beat(int no, int l, int r, int\
    \ i, int j, const Beater& beater) {\n      push(no, l, r);\n      if(break_cond(t[no],\
    \ l, r, i, j) || beater.stop(t[no], l, r, i, j)) {\n        return;\n      }\n\
    \      if(tag_cond(t[no], l, r, i, j) && beater.tag(t[no], l, r, i, j)) {\n  \
    \      beater(t[no]);\n        push(no, l, r);\n        return;\n      }\n   \
    \   int mid = (l+r)/2;\n      beat(no<<1, l, mid, i, j, beater);\n      beat(no<<1|1,\
    \ mid+1, r, i, j, beater);\n      t[no] = combiner_fn(t[no<<1], t[no<<1|1]);\n\
    \    }\n\n    template<typename Beater>\n    inline void beat(int i, int j, const\
    \ Beater& beater) {\n      beat(ROOT, L, R, i, j, beater);\n    } \n  };\n\n \
    \ template<typename Node, typename CombinerFn>\n  struct SegtreeNormal : SegtreeBeats<Node,\
    \ CombinerFn> {\n    typedef SegtreeBeats<Node, CombinerFn> Base;\n    using SegtreeBeats<Node,\
    \ CombinerFn>::SegtreeBeats;\n    using Base::ROOT;\n    using Base::combiner_fn;\n\
    \    using Base::L;\n    using Base::R;\n    using Base::t;\n\n    template<typename\
    \ Updater>\n    void update_element(int no, int l, int r, int idx, const Updater&\
    \ updater) {\n      if(l == r)\n        updater(t[no]);\n      else {\n      \
    \  int mid = (l+r)/2;\n        if(idx <= mid)\n          update_element(no<<1,\
    \ l, mid, idx, updater);\n        else\n          update_element(no<<1|1, mid+1,\
    \ r, idx, updater);\n        t[no] = combiner_fn(t[no<<1], t[no<<1|1]);\n    \
    \  }\n    }\n    \n    template<typename Updater>\n    inline void update_element(int\
    \ idx, const Updater& updater) {\n      update_element(ROOT, L, R, idx, updater);\n\
    \    }\n  };\n\n  template<typename Node>\n  struct SegtreeSplash : SegtreeBeats<Node,\
    \ EmptyFolder<void>> {\n    typedef SegtreeBeats<Node, EmptyFolder<void>> Base;\n\
    \    using Base::SegtreeBeats;\n    using Base::ROOT;\n    using Base::L;\n  \
    \  using Base::R;\n    using Base::t;\n\n    template<typename T, typename Folder>\n\
    \    T query_element(int no, int l, int r, int idx, const Folder& folder) {\n\
    \      T res = folder(t[no]);\n      if(l != r) {\n        int mid = (l+r)/2;\n\
    \        if(idx <= mid)\n          res = folder(res, query_element<T>(no<<1, l,\
    \ mid, idx, folder));\n        else\n          res = folder(res, query_element<T>(no<<1|1,\
    \ mid+1, r, idx, folder));\n      }\n      return res;\n    }\n\n    template<typename\
    \ T, typename Folder>\n    inline T query_element(int idx, const Folder& folder)\
    \ {\n      return query_element<T>(ROOT, L, R, idx, folder);\n    }\n\n    template<typename\
    \ Updater>\n    void splash(int no, int l, int r, int i, int j, const Updater&\
    \ updater) {\n      if(break_cond(t[no], l, r, i, j)) {\n        return;\n   \
    \   }\n      if(tag_cond(t[no], l, r, i, j)) {\n        updater(t[no]);\n    \
    \    return;\n      }\n      int mid = (l+r)/2;\n      splash(no<<1, l, mid, i,\
    \ j, updater);\n      splash(no<<1|1, mid+1, r, i, j, updater);\n    }\n\n   \
    \ template<typename Updater>\n    inline void splash(int i, int j, const Updater&\
    \ updater) {\n      splash(ROOT, L, R, i, j, updater);\n    }\n  };\n}  // namespace\
    \ seg\n}  // namespace lib\n\n#endif\n\n\nusing namespace std;\nusing namespace\
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
    \  solve();\n}\n\n"
  code: "#include <bits/stdc++.h>\n#ifndef _LIB_GRAPH\n#define _LIB_GRAPH\n\n#ifndef\
    \ _LIB_TRAITS\n#define _LIB_TRAITS\n\n\nnamespace lib {\n  using namespace std;\n\
    namespace traits {\n\n  template<typename Iterator>\n  using IteratorCategory\
    \ =\n    typename iterator_traits<Iterator>::iterator_category;\n\n  template<typename\
    \ Container>\n  using IteratorCategoryOf = IteratorCategory<typename Container::iterator>;\n\
    \n  template<typename Iterator>\n  using IsRandomIterator =\n    is_base_of<random_access_iterator_tag,\
    \ IteratorCategory<Iterator>>;\n\n  template<typename Iterator>\n  using IsInputIterator\
    \ =\n    is_base_of<input_iterator_tag, IteratorCategory<Iterator>>;\n\n  template<typename\
    \ Iterator>\n  using IsBidirectionalIterator =\n    is_base_of<bidirectional_iterator_tag,\
    \ IteratorCategory<Iterator>>;\n\n  template<typename Container>\n  using HasRandomIterator\
    \ =\n    is_base_of<random_access_iterator_tag, IteratorCategoryOf<Container>>;\n\
    \n  template<typename Container>\n  using HasInputIterator =\n    is_base_of<input_iterator_tag,\
    \ IteratorCategoryOf<Container>>;\n\n  template<typename Container>\n  using HasBidirectionalIterator\
    \ =\n    is_base_of<bidirectional_iterator_tag, IteratorCategoryOf<Container>>;\n\
    }\n}\n\n#endif\n\n\nnamespace lib {\n  using namespace std;\nnamespace graph {\n\
    \  template<typename T>\n  struct Edge {\n    const int from, to;\n    T data;\n\
    \  };\n\n  template<>\n  struct Edge<void> { const int from, to; };\n\n  template<typename\
    \ T>\n  struct VertexWrapper { T data; };\n\n  template<>\n  struct VertexWrapper<void>\
    \ {};\n\n  template<typename V = void, \n           typename E = void>\n  struct\
    \ Graph {\n    typedef Graph<V, E> self_type;\n    typedef vector<vector<int>>\
    \ adj_list;\n    typedef Edge<E> edge_type;\n    typedef VertexWrapper<V> vertex_type;\n\
    \n    vector<edge_type> edges;\n    adj_list adj;\n\n    vector<vertex_type> vertices;\n\
    \n    class iterator\n    {\n      public:\n            typedef iterator self_type;\n\
    \            typedef edge_type value_type;\n            typedef edge_type& reference;\n\
    \            typedef edge_type* pointer;\n            typedef std::forward_iterator_tag\
    \ iterator_category;\n            typedef int difference_type;\n            iterator(vector<int>*\
    \ adj, vector<edge_type>* edges, int ptr = 0)\n              : adj_(adj), edges_(edges),\
    \ ptr_(ptr) { }\n            self_type operator++() { ptr_++; return *this; }\n\
    \            self_type operator++(int junk) { self_type i = *this; ptr_++; return\
    \ i; }\n            reference operator*() { return (*edges_)[(*adj_)[ptr_]]; }\n\
    \            pointer operator->() { return &(*edges_)[(*adj_)[ptr_]]; }\n    \
    \        bool operator==(const self_type& rhs) const { \n              return\
    \ adj_ == rhs.adj_ && ptr_ == rhs.ptr_;\n            }\n            bool operator!=(const\
    \ self_type& rhs) const { return !(*this == rhs); }\n        private:\n      \
    \      vector<int>* adj_;\n            vector<edge_type>* edges_;\n          \
    \  int ptr_;\n    };\n\n    class const_iterator\n    {\n      public:\n     \
    \       typedef const_iterator self_type;\n            typedef edge_type value_type;\n\
    \            typedef edge_type& reference;\n            typedef edge_type* pointer;\n\
    \            typedef std::forward_iterator_tag iterator_category;\n          \
    \  typedef int difference_type;\n            const_iterator(vector<int>* adj,\
    \ vector<edge_type>* edges, int ptr = 0) \n              : adj_(adj), edges_(edges),\
    \ ptr_(ptr) { }\n            self_type operator++() { ptr_++; return *this; }\n\
    \            self_type operator++(int junk) { self_type i = *this; ptr_++; return\
    \ i; }\n            const value_type& operator*() { return (*edges_)[(*adj_)[ptr_]];\
    \ }\n            const value_type* operator->() { return &(*edges_)[(*adj_)[ptr_]];\
    \ }\n            bool operator==(const self_type& rhs) const { \n            \
    \  return adj_ == rhs.adj_ && ptr_ == rhs.ptr_;\n            }\n            bool\
    \ operator!=(const self_type& rhs) const { return !(*this == rhs); }\n       \
    \ private:\n            vector<int>* adj_;\n            vector<edge_type>* edges_;\n\
    \            int ptr_;\n    };\n\n    struct iterable {\n      vector<int>* adj_;\n\
    \      vector<edge_type>* edges_;\n\n      iterable(vector<int>* adj, vector<edge_type>*\
    \ edges)\n        : adj_(adj), edges_(edges) {}\n\n      inline iterator begin()\
    \ { return iterator(adj_, edges_); }\n      inline iterator end() { return iterator(adj_,\
    \ edges_, adj_->size()); }\n\n      inline const_iterator cbegin() const { return\
    \ const_iterator(adj_, edges_); }\n      inline const_iterator cend() const {\
    \ return const_iterator(adj_, edges_, adj_->size()); }\n\n      inline const_iterator\
    \ begin() const { return cbegin(); }\n      inline const_iterator end() const\
    \ { return cend(); }\n\n      inline edge_type& operator[](int i) { return (*edges_)[(*adj_)[i]];\
    \ }\n      inline const edge_type& operator[](int i) const { return (*edges_)[(*adj_)[i]];\
    \ }\n\n      inline int size() const { return adj_->size(); }\n    };\n\n    Graph()\
    \ {}\n\n    template<typename S = V, typename enable_if<is_void<S>::value>::type*\
    \ = nullptr>\n    Graph(size_t n) : adj(n) {}\n\n    template<typename S = V,\
    \ typename enable_if<!is_void<S>::value>::type* = nullptr>\n    Graph(size_t n)\
    \ : adj(n), vertices(n) {}\n\n    inline iterable n_edges(int i) { return iterable(&adj[i],\
    \ &edges); }\n    inline const iterable n_edges(int i) const { \n      return\
    \ iterable(const_cast<vector<int>*>(&adj[i]), \n                      const_cast<vector<edge_type>*>(&edges));\
    \ \n    }\n\n    inline int size() const { return adj.size(); }\n    inline edge_type&\
    \ edge(int i) { return edges[i]; }\n    inline edge_type edge(int i) const { return\
    \ edges[i]; }\n\n    inline vector<edge_type> all_edges() const { return edges;\
    \ }\n\n    template<typename S = V, typename enable_if<!is_void<S>::value>::type*\
    \ = nullptr>\n    inline S& vertex(int i) { return vertices[i]; }\n\n    template<typename\
    \ S = V, typename enable_if<!is_void<S>::value>::type* = nullptr>\n    inline\
    \ V vertex(int i) const { return vertices[i]; }\n\n    template<typename S = V,\
    \ typename enable_if<is_void<S>::value>::type* = nullptr>\n    inline void add_vertex()\
    \ { adj.emplace_back(); }\n\n    template<typename S = V, typename enable_if<!is_void<S>::value>::type*\
    \ = nullptr>\n    inline S& add_vertex() {\n      adj.emplace_back();\n      return\
    \ vertices.emplace_back().data;\n    }\n\n    template<typename S = E, typename\
    \ enable_if<is_void<S>::value>::type* = nullptr>\n    inline void add_edge(int\
    \ u, int v) {\n      adj[u].push_back(edges.size());\n      edges.push_back({u,\
    \ v});\n    }\n    \n    template<typename S = E, typename enable_if<!is_void<S>::value>::type*\
    \ = nullptr>\n    inline S& add_edge(int u, int v) {\n      adj[u].push_back(edges.size());\n\
    \      edges.push_back({u, v});\n      return edges.back();\n    }\n\n    void\
    \ add_2edge(int u, int v) {\n      add_edge(u, v);\n      add_edge(v, u);\n  \
    \  }\n\n    template<typename S = E, typename enable_if<!is_void<S>::value>::type*\
    \ = nullptr>\n    inline void add_2edge(int u, int v, const S& data) {\n     \
    \ add_edge(u, v).data = data;\n      add_edge(v, u).data = data;\n    }\n  };\n\
    \n  template<typename V = void, typename E = void>\n  struct RootedForest : public\
    \ Graph<V, E> {\n    typedef RootedForest<V, E> self_type;\n    using typename\
    \ Graph<V, E>::adj_list;\n    using typename Graph<V, E>::edge_type;\n    using\
    \ Graph<V, E>::Graph;\n    using Graph<V, E>::adj;\n    using Graph<V, E>::edge;\n\
    \    vector<int> p, pe;\n\n    void build_parents() {\n      if((int)p.size()\
    \ == this->size()) return;\n\n      int n = this->size();\n      stack<int> st;\n\
    \      vector<bool> vis(n);\n      p.assign(n, -1), pe.assign(n, -1);\n      for(int\
    \ i = 0; i < n; i++) {\n        if(!vis[i]) {\n          st.push(i);\n       \
    \   vis[i] = true;\n          while(!st.empty()) {\n            int u = st.top();\n\
    \            st.pop();\n\n            for(int k : adj[u]) {\n              int\
    \ v = edge(k).to;\n              vis[v] = true;\n              st.push(v), pe[v]\
    \ = k, p[v] = u;\n            }\n          }\n        }\n      }\n    }\n\n  \
    \  inline int parent(int i) const {\n      const_cast<self_type*>(this)->build_parents();\n\
    \      return p[i]; \n    }\n\n    inline bool is_root(int i) const { return parent(i)\
    \ != -1; }\n\n    inline edge_type& parent_edge(int i) { \n      build_parents();\n\
    \      return edge(pe[i]); \n    }\n    inline edge_type& parent_edge(int i) const\
    \ { \n      const_cast<self_type*>(this)->build_parents();\n      return edge(pe[i]);\
    \ \n    }\n\n    vector<int> roots() const {\n      vector<int> res;\n      const_cast<self_type*>(this)->build_parents();\n\
    \      int n = this->size();\n\n      for(int i = 0; i < n; i++)\n        if(p[i]\
    \ == -1) res.push_back(i);\n      return res;\n    }\n  };\n\n  template<typename\
    \ V = void, typename E = void>\n  struct RootedTree : public RootedForest<V, E>\
    \ {\n    using typename RootedForest<V, E>::adj_list;\n    int root;\n\n    RootedTree(int\
    \ n, int root) : RootedForest<V, E>(n) {\n      assert(n > 0);\n      assert(root\
    \ < n);\n      this->root = root;\n    }\n\n    RootedTree(const adj_list& adj,\
    \ int root) : RootedForest<V, E>(adj) {\n      assert(adj.size() > 0);\n     \
    \ assert(root < adj.size());\n      this->root = root;\n    }\n  };\n\n  namespace\
    \ builders {\n    namespace {\n      template<typename F, typename G>\n      void\
    \ dfs_rooted_forest(F& forest, const G& graph, int u, vector<bool>& vis) {\n \
    \       vis[u] = true;\n        for(const auto& ed : graph.n_edges(u)) {\n   \
    \       int v = ed.to;\n          if(!vis[v]) {\n            forest.add_edge(u,\
    \ v);\n            dfs_rooted_forest(forest, graph, v, vis);\n          }\n  \
    \      }\n      }\n\n      template<typename A, typename B>\n      RootedForest<A,\
    \ B> make_rooted_forest(const Graph<A, B>& graph,\n                          \
    \                  const vector<int>& roots) {\n        RootedForest<A, B> res(graph.size());\n\
    \        vector<bool> vis(graph.size());\n        for(int i : roots)\n       \
    \   if(!vis[i])\n            dfs_rooted_forest(res, graph, i, vis);\n        for(int\
    \ i = 0; i < graph.size(); i++)\n          if(!vis[i])\n            dfs_rooted_forest(res,\
    \ graph, i, vis);\n        return res;\n      }\n    }\n  }  // namespace builders\n\
    }  // namespace graph\n}  // namespace lib\n\n#endif\n\n#ifndef _LIB_RANGE_HLD\n\
    #define _LIB_RANGE_HLD\n\n#ifndef _LIB_HLD\n#define _LIB_HLD\n\n\n#ifndef _LIB_SEGTREE\n\
    #define _LIB_SEGTREE\n\n\nnamespace lib {\n  using namespace std;\nnamespace seg\
    \ {\n  struct LeafBuilder {\n    template<typename Node>\n    void operator()(Node&\
    \ no, int i) const {}\n    inline pair<int, int> range() const { return {0, 0};\
    \ }\n  };\n\n  struct EmptyLeafBuilder : LeafBuilder {\n    int n;\n    explicit\
    \ EmptyLeafBuilder(int n) : n(n) {}\n    inline pair<int, int> range() const {\
    \ return {0, n-1}; }\n  };\n\n  template<typename RandomIterator>\n  struct RangeLeafBuilder\
    \ : LeafBuilder {\n    RandomIterator begin, end;\n    explicit RangeLeafBuilder(RandomIterator\
    \ begin, RandomIterator end)\n      : begin(begin), end(end) {}\n\n    template<typename\
    \ Node>\n    inline void operator()(Node& no, int i) const { no = *(begin + i);\
    \ }\n\n    inline pair<int, int> range() const { return {0, end-begin-1}; }\n\
    \  };\n\n  EmptyLeafBuilder make_builder(int n) { return EmptyLeafBuilder(n);\
    \ }\n\n  template<typename RandomIterator>\n  RangeLeafBuilder<RandomIterator>\
    \ make_builder(RandomIterator begin, \n                                      \
    \          RandomIterator end) {\n    return RangeLeafBuilder<RandomIterator>(begin,\
    \ end);\n  }\n\n  template<typename T>\n  RangeLeafBuilder<typename vector<T>::const_iterator>\n\
    \  make_builder(const vector<T>& v) {\n    return RangeLeafBuilder<typename vector<T>::const_iterator>(v.begin(),\
    \ \n                                                                v.end());\n\
    \  }\n\n  template<typename T>\n  struct CombineFolder {\n    inline T operator()()\
    \ const { return T(); }\n\n    template<typename Node>\n    inline T operator()(const\
    \ Node& no) const { return T(no); }\n\n    inline T operator()(const T& a, const\
    \ T& b) const { return a + b; }\n  };\n\n  template<typename T>\n  struct EmptyFolder\
    \ : CombineFolder<T> {\n    using CombineFolder<T>::operator();\n\n    template<typename\
    \ Node>\n    inline T operator()(const Node& no) const { return T(); }\n    inline\
    \ T operator()(const T& a, const T& b) const { return T(); }\n  };\n\n  template<typename\
    \ T>\n  struct SumFolder : CombineFolder<T> {};\n  \n  template<typename T>\n\
    \  struct MaxFolder : CombineFolder<T> {\n    using CombineFolder<T>::operator();\n\
    \    inline T operator()() const { return numeric_limits<T>::min(); }\n    inline\
    \ T operator()(const T& a, const T& b) const { return max(a, b); }\n  };\n\n \
    \ template<typename T>\n  struct MinFolder : CombineFolder<T> {\n    using CombineFolder<T>::operator();\n\
    \    inline T operator()() const { return numeric_limits<T>::max(); }\n    inline\
    \ T operator()(const T& a, const T& b) const { return min(a, b); }\n  };\n\n \
    \ template<typename T>\n  struct SingleValueUpdater {\n    T value;\n    explicit\
    \ SingleValueUpdater(T val) : value(val) {}\n  };\n\n  template<typename T>\n\
    \  struct SetUpdater : SingleValueUpdater<T> {\n    using SingleValueUpdater<T>::SingleValueUpdater;\n\
    \n    template<typename Node>\n    inline void operator()(Node& no) const { no\
    \ = this->value; }\n  };\n\n  template<typename T>\n  struct AddUpdater: SingleValueUpdater<T>\
    \ {\n    using SingleValueUpdater<T>::SingleValueUpdater;\n\n    template<typename\
    \ Node>\n    inline void operator()(Node& no) const { no += this->value; }\n \
    \ };\n\n  struct EmptyPushdown {\n    template<typename Node>\n    inline void\
    \ operator()(Node& no, int l, int r, \n                    Node* ln, Node* rn)\
    \ const {}\n  };\n}  // namespace seg\n}  // namespace lib\n\n#endif\n\n\n\nnamespace\
    \ lib {\n  using namespace std;\nnamespace graph {\n  namespace {\n    void empty_lifter(int\
    \ a, int b) {}\n  }\n\n  template<typename G>\n  struct HLD {\n    G graph;\n\
    \    vector<int> in, out, rin;\n    vector<int> L, sz, ch;\n    int tempo;\n\n\
    \    HLD(const G& g) \n      : graph(g), in(g.size()), out(g.size()), rin(g.size()),\
    \ L(g.size()),\n        sz(g.size()), ch(g.size()) {\n        build();\n    }\n\
    \n    inline int size() const { return graph.size(); }\n\n    void dfs0(int u)\
    \ {\n      sz[u] = 1;\n      for(auto& k : graph.adj[u]) {\n        int v = graph.edge(k).to;\n\
    \        L[v] = L[u] + 1;\n        dfs0(v);\n        if(sz[v] > sz[graph.edge(graph.adj[u][0]).to])\n\
    \          swap(k, graph.adj[u][0]);\n        sz[u] += sz[v];\n      }\n    }\n\
    \n    void dfs1(int u) {\n      in[u] = tempo++;\n      rin[in[u]] = u;\n\n  \
    \    if(graph.adj[u].size() > 0) {\n        int v = graph.edge(graph.adj[u][0]).to;\n\
    \        ch[v] = ch[u];\n        dfs1(v);\n        for(size_t i = 1; i < graph.adj[u].size();\
    \ i++) {\n          v = graph.edge(graph.adj[u][i]).to;\n          ch[v] = v;\n\
    \          dfs1(v);\n        }\n      }\n      out[u] = tempo;\n    }\n\n    void\
    \ build() {\n      vector<int> roots = graph.roots();\n      for(int i : roots)\
    \ dfs0(i);\n      tempo = 0;\n      for(int i : roots) dfs1(i);\n    }\n\n   \
    \ template<typename Lifter>\n    inline void operate_on_subtree(int u, Lifter&\
    \ lifter) {\n      lifter(in[u], out[u]-1, false);\n    }\n\n    template<typename\
    \ T, typename QueryIssuer>\n    inline T query_on_subtree(int u, const QueryIssuer&\
    \ issuer) {\n      return issuer(in[u], out[u]-1);\n    }\n\n    template<typename\
    \ Lifter>\n    inline void operate_on_subtree_edges(int u, Lifter& lifter) {\n\
    \      if(in[u]+2 <= out[u]) lifter(in[u]+1, out[u]-1, false);\n    }\n\n    template<typename\
    \ T, typename QueryIssuer>\n    inline void query_on_subtree_edges(int u, const\
    \ QueryIssuer& issuer) {\n      assert(in[u]+2 <= out[u]);\n      return issuer(in[u]+1,\
    \ out[u]-1);\n    }\n\n    template<bool is_edge, typename Lifter>\n    int _query_path(int\
    \ u, int v, Lifter& lifter) {\n      int inv = 0;\n      for(; ch[u] != ch[v];\
    \ u = graph.parent(ch[u])) {\n        if(L[ch[u]] < L[ch[v]])\n          swap(u,\
    \ v), inv ^= 1;\n        lifter(in[ch[u]], in[u], (bool)inv);\n      }\n     \
    \ if(L[u] > L[v]) swap(u, v), inv ^= 1;\n      inv ^= 1;\n      if(is_edge &&\
    \ in[u]+1 <= in[v])\n        lifter(in[u]+1, in[v], (bool)inv);\n      else if(!is_edge)\n\
    \        lifter(in[u], in[v], (bool)inv);\n      return u;\n    }\n\n    template<typename\
    \ Lifter>\n    inline int operate_on_path(int u, int v, Lifter& lifter) {\n  \
    \    return _query_path<false>(u, v, lifter);\n    }\n\n    template<typename\
    \ Lifter>\n    inline int operate_on_path_edges(int u, int v, Lifter& lifter)\
    \ {\n      return _query_path<true>(u, v, lifter);\n    }\n\n    template<typename\
    \ Op>\n    inline void operate_on_vertex(int u, Op& op) {\n      op(in[u]);\n\
    \    }\n\n    template<typename T, typename QueryIssuer>\n    inline T query_on_vertex(int\
    \ u, const QueryIssuer& issuer) {\n      return issuer(in[u]);\n    }\n\n    inline\
    \ int lca(int u, int v) {\n      return _query_path<false>(u, v, empty_lifter);\n\
    \    }\n  };\n\n  template<typename G>\n  HLD<G> make_hld(const G& graph) {\n\
    \    return HLD<G>(graph);\n  }\n}  // namespace graph\n}  // namespace lib\n\n\
    #endif\n\n\nnamespace lib {\n  using namespace std;\nnamespace graph {\nnamespace\
    \ range {\n  template<typename Builder, \n           typename H>\n  struct BuilderWrapper\
    \ {\n    H* hld;\n    Builder builder;\n\n    explicit BuilderWrapper(H* hld,\
    \ const Builder& builder) \n      : hld(hld), builder(builder) {}\n\n    template<typename\
    \ Node>\n    void operator()(Node& no, int i) const { \n      builder(no, hld->rin[i]);\
    \ \n    }\n\n    pair<int, int> range() const { return {0, hld->size() - 1}; }\n\
    \  };\n\n  template<typename Builder, typename H>\n  struct RebuilderWrapper :\
    \ BuilderWrapper<Builder, H> {\n    using BuilderWrapper<Builder, H>::BuilderWrapper;\n\
    \    using BuilderWrapper<Builder, H>::builder;\n    template<typename Node>\n\
    \    void operator()(Node& no, const Node& left, const Node& right) const {\n\
    \      builder(no, left, right);\n    }\n  };\n\n  template<typename S, typename\
    \ T, typename Folder>\n  struct QueryIssuer {\n    S& seg;\n    const Folder&\
    \ folder;\n    QueryIssuer(S& seg, const Folder& folder) : seg(seg), folder(folder)\
    \ {}\n    T operator()(int i) const {\n      seg.template query_element<T>(i,\
    \ folder);\n    }\n    T operator()(int i, int j) const {\n      return seg.template\
    \ query<T>(i, j, folder);\n    }\n  };\n\n  template<typename S, typename T, typename\
    \ Folder>\n  struct QueryLifter {\n    QueryIssuer<S, T, Folder> issuer;\n   \
    \ T res;\n    QueryLifter(S& seg, const Folder& folder) \n      : issuer(seg,\
    \ folder), res(folder()) {}\n    void operator()(int i, int j, bool) {\n     \
    \ res = issuer.folder(res, issuer(i, j));\n    }\n    T result() const { return\
    \ res; }\n  };\n\n  template<typename S, typename T, typename Folder>\n  struct\
    \ OrderedQueryLifter : QueryLifter<S, T, Folder> {\n    using QueryLifter<S, T,\
    \ Folder>::issuer;\n    T resl, resr;\n\n    OrderedQueryLifter(S& seg, const\
    \ Folder& folder)\n      : QueryLifter<S, T, Folder>(seg, folder), \n        resl(folder()),\
    \ resr(folder()) {}\n    \n    void operator()(int i, int j, bool right) {\n \
    \     if(right)\n        resr = issuer.folder(issuer(i, j), resr);\n      else\n\
    \        resl = issuer.folder(resl, issuer(i, j));\n    }\n    T result() const\
    \ { return issuer.folder(resl, resr); }\n  };\n\n  template<typename S, typename\
    \ Updater>\n  struct UpdateIssuer {\n    S& seg;\n    const Updater& updater;\n\
    \    UpdateIssuer(S& seg, const Updater& updater)\n      : seg(seg), updater(updater)\
    \ {}\n    void operator()(int i, int j) { seg.update(i, j, updater); }\n    void\
    \ operator()(int i, int j, bool) { (*this)(i, j); }\n  };\n\n  template<typename\
    \ S, typename Updater>\n  struct SplashIssuer {\n    S& seg;\n    const Updater&\
    \ updater;\n    SplashIssuer(S& seg, const Updater& updater)\n      : seg(seg),\
    \ updater(updater) {}\n    void operator()(int i, int j) { seg.splash(i, j, updater);\
    \ }\n    void operator()(int i, int j, bool) { (*this)(i, j); }\n  };\n\n  template<typename\
    \ S, typename Beater>\n  struct BeatIssuer {\n    S& seg;\n    const Beater& beater;\n\
    \    BeatIssuer(S& seg, const Beater& beater)\n      : seg(seg), beater(beater)\
    \ {}\n    void operator()(int i, int j) { seg.beat(i, j, beater); }\n    void\
    \ operator()(int i, int j, bool) { (*this)(i, j); }\n  };\n}  // namespace range\n\
    \n  template<typename S,\n           typename G>\n  struct RangeHLD : HLD<G> {\n\
    \    typedef seg::EmptyLeafBuilder empty_builder;\n\n    template<typename Builder>\n\
    \    using builder_wrapper = range::BuilderWrapper<Builder, HLD<G>>;\n    template<typename\
    \ Rebuilder>\n    using rebuilder_wrapper = range::RebuilderWrapper<Rebuilder,\
    \ HLD<G>>;\n\n    S seg;\n\n    explicit RangeHLD(const G& graph) \n      : HLD<G>(graph),\n\
    \        seg(builder_wrapper<empty_builder>(this, empty_builder(this->size())))\
    \ {}\n\n    template<typename Builder>\n    RangeHLD(const G& graph, const Builder&\
    \ builder)\n      : HLD<G>(graph), \n        seg(builder_wrapper<Builder>(this,\
    \ builder)) {}\n\n    template<typename Builder>\n    void build(const Builder&\
    \ builder) {\n      seg.build(builder_wrapper<Builder>(builder));\n    }\n   \
    \ \n    template<typename Rebuilder>\n    void rebuild(const Rebuilder& rebuilder)\
    \ {\n      seg.rebuild(rebuilder_wrapper<Rebuilder>(rebuilder));\n    }\n\n  \
    \  template<typename T, typename Folder>\n    inline T query_subtree(int u, const\
    \ Folder& folder) {\n      return this->template \n        query_on_subtree<T>(u,\
    \ range::QueryIssuer<S, T, Folder>(seg, folder));\n    }\n\n    template<typename\
    \ T, typename Folder>\n    inline T query_subtree_edges(int u, const Folder& folder)\
    \ {\n      return this->template\n        query_on_subtree_edges(u, range::QueryIssuer<S,\
    \ T, Folder>(seg, folder));\n    }\n\n    template<typename T, typename Folder>\n\
    \    inline T query_vertex(int u, const Folder& folder) {\n      return this->template\n\
    \        query_on_vertex(u, range::QueryIssuer<S, T, Folder>(seg, folder));\n\
    \    }\n\n    template<typename T, typename Folder>\n    T query_path(int u, int\
    \ v, const Folder& folder) {\n      auto lifter = range::OrderedQueryLifter<S,\
    \ T, Folder>(seg, folder);\n      this->template\n        operate_on_path(u, v,\
    \ lifter);\n      return lifter.result();\n    }\n\n    template<typename T, typename\
    \ Folder>\n    T query_path_edges(int u, int v, const Folder& folder) {\n    \
    \  auto lifter = range::OrderedQueryLifter<S, T, Folder>(seg, folder);\n     \
    \ this->template\n        operate_on_path_edges(u, v, lifter);\n      return lifter.result();\n\
    \    }\n\n    template<typename Updater>\n    inline void update_subtree(int u,\
    \ const Updater& updater) {\n      auto issuer = range::UpdateIssuer<S, Updater>(seg,\
    \ updater);\n      this->template operate_on_subtree(u, issuer);\n    }\n\n  \
    \  template<typename Updater>\n    inline void update_subtree_edges(int u, const\
    \ Updater& updater) {\n      auto issuer = range::UpdateIssuer<S, Updater>(seg,\
    \ updater);\n      this->template operate_on_subtree_edges(u, issuer);\n    }\n\
    \n    template<typename Updater>\n    inline void update_path(int u, int v, const\
    \ Updater& updater) {\n      auto issuer = range::UpdateIssuer<S, Updater>(seg,\
    \ updater);\n      this->template operate_on_path(u, v, issuer);\n    }\n\n  \
    \  template<typename Updater>\n    inline void update_path_edges(int u, int v,\
    \ const Updater& updater) {\n      auto issuer = range::UpdateIssuer<S, Updater>(seg,\
    \ updater);\n      this->template operate_on_path_edges(u, v, issuer);\n    }\n\
    \n    template<typename Beater>\n    inline void beat_subtree(int u, const Beater&\
    \ beater) {\n      auto issuer = range::BeatIssuer<S, Beater>(seg, beater);\n\
    \      this->template operate_on_subtree(u, issuer);\n    }\n\n    template<typename\
    \ Beater>\n    inline void beat_subtree_edges(int u, const Beater& beater) {\n\
    \      auto issuer = range::BeatIssuer<S, Beater>(seg, beater);\n      this->template\
    \ operate_on_subtree_edges(u, issuer);\n    }\n\n    template<typename Beater>\n\
    \    inline void beat_path(int u, int v, const Beater& beater) {\n      auto issuer\
    \ = range::BeatIssuer<S, Beater>(seg, beater);\n      this->template operate_on_path(u,\
    \ v, issuer);\n    }\n\n    template<typename Beater>\n    inline void beat_path_edges(int\
    \ u, int v, const Beater& beater) {\n      auto issuer = range::BeatIssuer<S,\
    \ Beater>(seg, beater);\n      this->template operate_on_path_edges(u, v, issuer);\n\
    \    }\n\n    // FIX THOSE \n    template<typename Updater>\n    inline void update_element(int\
    \ idx, const Updater& updater) {\n      seg.update_element(idx, updater);\n  \
    \  }\n\n    template<typename Updater>\n    inline void splash(int i, int j, const\
    \ Updater& updater) {\n      seg.splash(i, j, updater);\n    }\n  };\n\n  template<typename\
    \ S, typename G>\n  RangeHLD<S, G> make_range_hld(const G& graph) {\n    return\
    \ RangeHLD<S, G>(graph);\n  }\n\n  template<typename S, typename G, typename Builder>\n\
    \  RangeHLD<S, G> make_range_hld(const G& graph, const Builder& builder) {\n \
    \   return RangeHLD<S, G>(graph, builder);\n  }\n\n}  // namespace graph\n}  //\
    \ namespace lib\n\n#endif\n\n\n#ifndef _LIB_SEGTREE_BEATS\n#define _LIB_SEGTREE_BEATS\n\
    \n\n\nnamespace lib {\n  using namespace std;\nnamespace seg { \n  struct DefaultBreakCond\
    \ {\n    template<typename Node>\n    inline bool operator()(const Node& no, int\
    \ l, int r, int i, int j) const {\n      return i > r || j < l;\n    }\n  };\n\
    \n  struct DefaultTagCond {\n    template<typename Node>\n    inline bool operator()(const\
    \ Node& no, int l, int r, int i, int j) const {\n      return i <= l && r <= j;\n\
    \    }\n  };\n\n  template<typename Node, \n           typename CombinerFn = EmptyFolder<int>,\n\
    \           typename PushdownFn = EmptyPushdown, \n           typename BreakCond\
    \ = DefaultBreakCond, \n           typename TagCond = DefaultTagCond>\n  struct\
    \ SegtreeBeats {\n    const static int ROOT = 1;\n    const static int MULTIPLIER\
    \ = 4;\n    const static int SHIFT = 0;\n\n\n    CombinerFn combiner_fn;\n   \
    \ PushdownFn pushdown_fn;\n    BreakCond break_cond;\n    TagCond tag_cond;\n\n\
    \    vector<Node> t;\n    int L, R;\n\n    template<typename Builder>\n    explicit\
    \ SegtreeBeats(const Builder& builder) {\n      pair<int, int> range = builder.range();\n\
    \      L = range.first;\n      R = range.second;\n      assert(L >= 0 && L <=\
    \ R);\n      t = vector<Node>(size() * MULTIPLIER + SHIFT);\n      build(builder);\n\
    \    }\n\n    template<typename Builder>\n    void build(const Builder& builder,\
    \ int no, int l, int r) {\n      if(l == r) {\n        builder(t[no], l);\n  \
    \    } else {\n        int mid = (l+r)/2;\n        build(builder, no<<1, l, mid);\n\
    \        build(builder, no<<1|1, mid+1, r);\n        t[no] = combiner_fn(t[no<<1],\
    \ t[no<<1|1]);\n      }\n    }\n\n    template<typename Builder>\n    void build(const\
    \ Builder& builder) {\n      return build(builder, ROOT, L, R);\n    }\n\n   \
    \ inline int size() const { return R-L+1; }\n\n    void push(int no, int l, int\
    \ r) {\n      Node* left = l == r ? 0 : &t[no<<1];\n      Node* right = l == r\
    \ ? 0 : &t[no<<1|1];\n      pushdown_fn(t[no], l, r, left, right);\n    }\n\n\
    \    template<typename T, typename Folder>\n    T query(int no, int l, int r,\
    \ int i, int j, const Folder& folder) {\n      if(j < l || i > r) return folder();\n\
    \      push(no, l, r);\n      if(i <= l && r <= j) return folder(t[no]);\n   \
    \   int mid = (l+r)/2;\n      return folder(\n          query<T>(no<<1, l, mid,\
    \ i, j, folder),\n          query<T>(no<<1|1, mid+1, r, i, j, folder)\n      );\n\
    \    }\n\n    template<typename T, typename Folder>\n    inline T query(int i,\
    \ int j, const Folder& folder) {\n      return query<T>(ROOT, L, R, i, j, folder);\n\
    \    }\n\n    template<typename Updater>\n    void update(int no, int l, int r,\
    \ int i, int j, const Updater& updater) {\n      push(no, l, r);\n      if(break_cond(t[no],\
    \ l, r, i, j)) {\n        return;\n      }\n      if(tag_cond(t[no], l, r, i,\
    \ j)) {\n        updater(t[no]);\n        push(no, l, r);\n        return;\n \
    \     }\n      int mid = (l+r)/2;\n      update(no<<1, l, mid, i, j, updater);\n\
    \      update(no<<1|1, mid+1, r, i, j, updater);\n      t[no] = combiner_fn(t[no<<1],\
    \ t[no<<1|1]);\n    }\n\n    template<typename Updater>\n    inline void update(int\
    \ i, int j, const Updater& updater) {\n      update(ROOT, L, R, i, j, updater);\n\
    \    }\n\n    template<typename Beater>\n    void beat(int no, int l, int r, int\
    \ i, int j, const Beater& beater) {\n      push(no, l, r);\n      if(break_cond(t[no],\
    \ l, r, i, j) || beater.stop(t[no], l, r, i, j)) {\n        return;\n      }\n\
    \      if(tag_cond(t[no], l, r, i, j) && beater.tag(t[no], l, r, i, j)) {\n  \
    \      beater(t[no]);\n        push(no, l, r);\n        return;\n      }\n   \
    \   int mid = (l+r)/2;\n      beat(no<<1, l, mid, i, j, beater);\n      beat(no<<1|1,\
    \ mid+1, r, i, j, beater);\n      t[no] = combiner_fn(t[no<<1], t[no<<1|1]);\n\
    \    }\n\n    template<typename Beater>\n    inline void beat(int i, int j, const\
    \ Beater& beater) {\n      beat(ROOT, L, R, i, j, beater);\n    } \n  };\n\n \
    \ template<typename Node, typename CombinerFn>\n  struct SegtreeNormal : SegtreeBeats<Node,\
    \ CombinerFn> {\n    typedef SegtreeBeats<Node, CombinerFn> Base;\n    using SegtreeBeats<Node,\
    \ CombinerFn>::SegtreeBeats;\n    using Base::ROOT;\n    using Base::combiner_fn;\n\
    \    using Base::L;\n    using Base::R;\n    using Base::t;\n\n    template<typename\
    \ Updater>\n    void update_element(int no, int l, int r, int idx, const Updater&\
    \ updater) {\n      if(l == r)\n        updater(t[no]);\n      else {\n      \
    \  int mid = (l+r)/2;\n        if(idx <= mid)\n          update_element(no<<1,\
    \ l, mid, idx, updater);\n        else\n          update_element(no<<1|1, mid+1,\
    \ r, idx, updater);\n        t[no] = combiner_fn(t[no<<1], t[no<<1|1]);\n    \
    \  }\n    }\n    \n    template<typename Updater>\n    inline void update_element(int\
    \ idx, const Updater& updater) {\n      update_element(ROOT, L, R, idx, updater);\n\
    \    }\n  };\n\n  template<typename Node>\n  struct SegtreeSplash : SegtreeBeats<Node,\
    \ EmptyFolder<void>> {\n    typedef SegtreeBeats<Node, EmptyFolder<void>> Base;\n\
    \    using Base::SegtreeBeats;\n    using Base::ROOT;\n    using Base::L;\n  \
    \  using Base::R;\n    using Base::t;\n\n    template<typename T, typename Folder>\n\
    \    T query_element(int no, int l, int r, int idx, const Folder& folder) {\n\
    \      T res = folder(t[no]);\n      if(l != r) {\n        int mid = (l+r)/2;\n\
    \        if(idx <= mid)\n          res = folder(res, query_element<T>(no<<1, l,\
    \ mid, idx, folder));\n        else\n          res = folder(res, query_element<T>(no<<1|1,\
    \ mid+1, r, idx, folder));\n      }\n      return res;\n    }\n\n    template<typename\
    \ T, typename Folder>\n    inline T query_element(int idx, const Folder& folder)\
    \ {\n      return query_element<T>(ROOT, L, R, idx, folder);\n    }\n\n    template<typename\
    \ Updater>\n    void splash(int no, int l, int r, int i, int j, const Updater&\
    \ updater) {\n      if(break_cond(t[no], l, r, i, j)) {\n        return;\n   \
    \   }\n      if(tag_cond(t[no], l, r, i, j)) {\n        updater(t[no]);\n    \
    \    return;\n      }\n      int mid = (l+r)/2;\n      splash(no<<1, l, mid, i,\
    \ j, updater);\n      splash(no<<1|1, mid+1, r, i, j, updater);\n    }\n\n   \
    \ template<typename Updater>\n    inline void splash(int i, int j, const Updater&\
    \ updater) {\n      splash(ROOT, L, R, i, j, updater);\n    }\n  };\n}  // namespace\
    \ seg\n}  // namespace lib\n\n#endif\n\n\nusing namespace std;\nusing namespace\
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
    \  solve();\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: tests/judge/inlined.cpp
  requiredBy: []
  timestamp: '2018-08-21 15:55:26-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tests/judge/inlined.cpp
layout: document
redirect_from:
- /library/tests/judge/inlined.cpp
- /library/tests/judge/inlined.cpp.html
title: tests/judge/inlined.cpp
---
