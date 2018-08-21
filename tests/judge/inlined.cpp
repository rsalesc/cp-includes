#include <bits/stdc++.h>
#ifndef _LIB_GRAPH
#define _LIB_GRAPH

#ifndef _LIB_TRAITS
#define _LIB_TRAITS


namespace lib {
  using namespace std;
namespace traits {

  template<typename Iterator>
  using IteratorCategory =
    typename iterator_traits<Iterator>::iterator_category;

  template<typename Container>
  using IteratorCategoryOf = IteratorCategory<typename Container::iterator>;

  template<typename Iterator>
  using IsRandomIterator =
    is_base_of<random_access_iterator_tag, IteratorCategory<Iterator>>;

  template<typename Iterator>
  using IsInputIterator =
    is_base_of<input_iterator_tag, IteratorCategory<Iterator>>;

  template<typename Iterator>
  using IsBidirectionalIterator =
    is_base_of<bidirectional_iterator_tag, IteratorCategory<Iterator>>;

  template<typename Container>
  using HasRandomIterator =
    is_base_of<random_access_iterator_tag, IteratorCategoryOf<Container>>;

  template<typename Container>
  using HasInputIterator =
    is_base_of<input_iterator_tag, IteratorCategoryOf<Container>>;

  template<typename Container>
  using HasBidirectionalIterator =
    is_base_of<bidirectional_iterator_tag, IteratorCategoryOf<Container>>;
}
}

#endif


namespace lib {
  using namespace std;
namespace graph {
  template<typename T>
  struct Edge {
    const int from, to;
    T data;
  };

  template<>
  struct Edge<void> { const int from, to; };

  template<typename T>
  struct VertexWrapper { T data; };

  template<>
  struct VertexWrapper<void> {};

  template<typename V = void, 
           typename E = void>
  struct Graph {
    typedef Graph<V, E> self_type;
    typedef vector<vector<int>> adj_list;
    typedef Edge<E> edge_type;
    typedef VertexWrapper<V> vertex_type;

    vector<edge_type> edges;
    adj_list adj;

    vector<vertex_type> vertices;

    class iterator
    {
      public:
            typedef iterator self_type;
            typedef edge_type value_type;
            typedef edge_type& reference;
            typedef edge_type* pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef int difference_type;
            iterator(vector<int>* adj, vector<edge_type>* edges, int ptr = 0)
              : adj_(adj), edges_(edges), ptr_(ptr) { }
            self_type operator++() { ptr_++; return *this; }
            self_type operator++(int junk) { self_type i = *this; ptr_++; return i; }
            reference operator*() { return (*edges_)[(*adj_)[ptr_]]; }
            pointer operator->() { return &(*edges_)[(*adj_)[ptr_]]; }
            bool operator==(const self_type& rhs) const { 
              return adj_ == rhs.adj_ && ptr_ == rhs.ptr_;
            }
            bool operator!=(const self_type& rhs) const { return !(*this == rhs); }
        private:
            vector<int>* adj_;
            vector<edge_type>* edges_;
            int ptr_;
    };

    class const_iterator
    {
      public:
            typedef const_iterator self_type;
            typedef edge_type value_type;
            typedef edge_type& reference;
            typedef edge_type* pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef int difference_type;
            const_iterator(vector<int>* adj, vector<edge_type>* edges, int ptr = 0) 
              : adj_(adj), edges_(edges), ptr_(ptr) { }
            self_type operator++() { ptr_++; return *this; }
            self_type operator++(int junk) { self_type i = *this; ptr_++; return i; }
            const value_type& operator*() { return (*edges_)[(*adj_)[ptr_]]; }
            const value_type* operator->() { return &(*edges_)[(*adj_)[ptr_]]; }
            bool operator==(const self_type& rhs) const { 
              return adj_ == rhs.adj_ && ptr_ == rhs.ptr_;
            }
            bool operator!=(const self_type& rhs) const { return !(*this == rhs); }
        private:
            vector<int>* adj_;
            vector<edge_type>* edges_;
            int ptr_;
    };

    struct iterable {
      vector<int>* adj_;
      vector<edge_type>* edges_;

      iterable(vector<int>* adj, vector<edge_type>* edges)
        : adj_(adj), edges_(edges) {}

      inline iterator begin() { return iterator(adj_, edges_); }
      inline iterator end() { return iterator(adj_, edges_, adj_->size()); }

      inline const_iterator cbegin() const { return const_iterator(adj_, edges_); }
      inline const_iterator cend() const { return const_iterator(adj_, edges_, adj_->size()); }

      inline const_iterator begin() const { return cbegin(); }
      inline const_iterator end() const { return cend(); }

      inline edge_type& operator[](int i) { return (*edges_)[(*adj_)[i]]; }
      inline const edge_type& operator[](int i) const { return (*edges_)[(*adj_)[i]]; }

      inline int size() const { return adj_->size(); }
    };

    Graph() {}

    template<typename S = V, typename enable_if<is_void<S>::value>::type* = nullptr>
    Graph(size_t n) : adj(n) {}

    template<typename S = V, typename enable_if<!is_void<S>::value>::type* = nullptr>
    Graph(size_t n) : adj(n), vertices(n) {}

    inline iterable n_edges(int i) { return iterable(&adj[i], &edges); }
    inline const iterable n_edges(int i) const { 
      return iterable(const_cast<vector<int>*>(&adj[i]), 
                      const_cast<vector<edge_type>*>(&edges)); 
    }

    inline int size() const { return adj.size(); }
    inline edge_type& edge(int i) { return edges[i]; }
    inline edge_type edge(int i) const { return edges[i]; }

    inline vector<edge_type> all_edges() const { return edges; }

    template<typename S = V, typename enable_if<!is_void<S>::value>::type* = nullptr>
    inline S& vertex(int i) { return vertices[i]; }

    template<typename S = V, typename enable_if<!is_void<S>::value>::type* = nullptr>
    inline V vertex(int i) const { return vertices[i]; }

    template<typename S = V, typename enable_if<is_void<S>::value>::type* = nullptr>
    inline void add_vertex() { adj.emplace_back(); }

    template<typename S = V, typename enable_if<!is_void<S>::value>::type* = nullptr>
    inline S& add_vertex() {
      adj.emplace_back();
      return vertices.emplace_back().data;
    }

    template<typename S = E, typename enable_if<is_void<S>::value>::type* = nullptr>
    inline void add_edge(int u, int v) {
      adj[u].push_back(edges.size());
      edges.push_back({u, v});
    }
    
    template<typename S = E, typename enable_if<!is_void<S>::value>::type* = nullptr>
    inline S& add_edge(int u, int v) {
      adj[u].push_back(edges.size());
      edges.push_back({u, v});
      return edges.back();
    }

    void add_2edge(int u, int v) {
      add_edge(u, v);
      add_edge(v, u);
    }

    template<typename S = E, typename enable_if<!is_void<S>::value>::type* = nullptr>
    inline void add_2edge(int u, int v, const S& data) {
      add_edge(u, v).data = data;
      add_edge(v, u).data = data;
    }
  };

  template<typename V = void, typename E = void>
  struct RootedForest : public Graph<V, E> {
    typedef RootedForest<V, E> self_type;
    using typename Graph<V, E>::adj_list;
    using typename Graph<V, E>::edge_type;
    using Graph<V, E>::Graph;
    using Graph<V, E>::adj;
    using Graph<V, E>::edge;
    vector<int> p, pe;

    void build_parents() {
      if((int)p.size() == this->size()) return;

      int n = this->size();
      stack<int> st;
      vector<bool> vis(n);
      p.assign(n, -1), pe.assign(n, -1);
      for(int i = 0; i < n; i++) {
        if(!vis[i]) {
          st.push(i);
          vis[i] = true;
          while(!st.empty()) {
            int u = st.top();
            st.pop();

            for(int k : adj[u]) {
              int v = edge(k).to;
              vis[v] = true;
              st.push(v), pe[v] = k, p[v] = u;
            }
          }
        }
      }
    }

    inline int parent(int i) const {
      const_cast<self_type*>(this)->build_parents();
      return p[i]; 
    }

    inline bool is_root(int i) const { return parent(i) != -1; }

    inline edge_type& parent_edge(int i) { 
      build_parents();
      return edge(pe[i]); 
    }
    inline edge_type& parent_edge(int i) const { 
      const_cast<self_type*>(this)->build_parents();
      return edge(pe[i]); 
    }

    vector<int> roots() const {
      vector<int> res;
      const_cast<self_type*>(this)->build_parents();
      int n = this->size();

      for(int i = 0; i < n; i++)
        if(p[i] == -1) res.push_back(i);
      return res;
    }
  };

  template<typename V = void, typename E = void>
  struct RootedTree : public RootedForest<V, E> {
    using typename RootedForest<V, E>::adj_list;
    int root;

    RootedTree(int n, int root) : RootedForest<V, E>(n) {
      assert(n > 0);
      assert(root < n);
      this->root = root;
    }

    RootedTree(const adj_list& adj, int root) : RootedForest<V, E>(adj) {
      assert(adj.size() > 0);
      assert(root < adj.size());
      this->root = root;
    }
  };

  namespace builders {
    namespace {
      template<typename F, typename G>
      void dfs_rooted_forest(F& forest, const G& graph, int u, vector<bool>& vis) {
        vis[u] = true;
        for(const auto& ed : graph.n_edges(u)) {
          int v = ed.to;
          if(!vis[v]) {
            forest.add_edge(u, v);
            dfs_rooted_forest(forest, graph, v, vis);
          }
        }
      }

      template<typename A, typename B>
      RootedForest<A, B> make_rooted_forest(const Graph<A, B>& graph,
                                            const vector<int>& roots) {
        RootedForest<A, B> res(graph.size());
        vector<bool> vis(graph.size());
        for(int i : roots)
          if(!vis[i])
            dfs_rooted_forest(res, graph, i, vis);
        for(int i = 0; i < graph.size(); i++)
          if(!vis[i])
            dfs_rooted_forest(res, graph, i, vis);
        return res;
      }
    }
  }  // namespace builders
}  // namespace graph
}  // namespace lib

#endif

#ifndef _LIB_RANGE_HLD
#define _LIB_RANGE_HLD

#ifndef _LIB_HLD
#define _LIB_HLD


#ifndef _LIB_SEGTREE
#define _LIB_SEGTREE


namespace lib {
  using namespace std;
namespace seg {
  struct LeafBuilder {
    template<typename Node>
    void operator()(Node& no, int i) const {}
    inline pair<int, int> range() const { return {0, 0}; }
  };

  struct EmptyLeafBuilder : LeafBuilder {
    int n;
    explicit EmptyLeafBuilder(int n) : n(n) {}
    inline pair<int, int> range() const { return {0, n-1}; }
  };

  template<typename RandomIterator>
  struct RangeLeafBuilder : LeafBuilder {
    RandomIterator begin, end;
    explicit RangeLeafBuilder(RandomIterator begin, RandomIterator end)
      : begin(begin), end(end) {}

    template<typename Node>
    inline void operator()(Node& no, int i) const { no = *(begin + i); }

    inline pair<int, int> range() const { return {0, end-begin-1}; }
  };

  EmptyLeafBuilder make_builder(int n) { return EmptyLeafBuilder(n); }

  template<typename RandomIterator>
  RangeLeafBuilder<RandomIterator> make_builder(RandomIterator begin, 
                                                RandomIterator end) {
    return RangeLeafBuilder<RandomIterator>(begin, end);
  }

  template<typename T>
  RangeLeafBuilder<typename vector<T>::const_iterator>
  make_builder(const vector<T>& v) {
    return RangeLeafBuilder<typename vector<T>::const_iterator>(v.begin(), 
                                                                v.end());
  }

  template<typename T>
  struct CombineFolder {
    inline T operator()() const { return T(); }

    template<typename Node>
    inline T operator()(const Node& no) const { return T(no); }

    inline T operator()(const T& a, const T& b) const { return a + b; }
  };

  template<typename T>
  struct EmptyFolder : CombineFolder<T> {
    using CombineFolder<T>::operator();

    template<typename Node>
    inline T operator()(const Node& no) const { return T(); }
    inline T operator()(const T& a, const T& b) const { return T(); }
  };

  template<typename T>
  struct SumFolder : CombineFolder<T> {};
  
  template<typename T>
  struct MaxFolder : CombineFolder<T> {
    using CombineFolder<T>::operator();
    inline T operator()() const { return numeric_limits<T>::min(); }
    inline T operator()(const T& a, const T& b) const { return max(a, b); }
  };

  template<typename T>
  struct MinFolder : CombineFolder<T> {
    using CombineFolder<T>::operator();
    inline T operator()() const { return numeric_limits<T>::max(); }
    inline T operator()(const T& a, const T& b) const { return min(a, b); }
  };

  template<typename T>
  struct SingleValueUpdater {
    T value;
    explicit SingleValueUpdater(T val) : value(val) {}
  };

  template<typename T>
  struct SetUpdater : SingleValueUpdater<T> {
    using SingleValueUpdater<T>::SingleValueUpdater;

    template<typename Node>
    inline void operator()(Node& no) const { no = this->value; }
  };

  template<typename T>
  struct AddUpdater: SingleValueUpdater<T> {
    using SingleValueUpdater<T>::SingleValueUpdater;

    template<typename Node>
    inline void operator()(Node& no) const { no += this->value; }
  };

  struct EmptyPushdown {
    template<typename Node>
    inline void operator()(Node& no, int l, int r, 
                    Node* ln, Node* rn) const {}
  };
}  // namespace seg
}  // namespace lib

#endif



namespace lib {
  using namespace std;
namespace graph {
  namespace {
    void empty_lifter(int a, int b) {}
  }

  template<typename G>
  struct HLD {
    G graph;
    vector<int> in, out, rin;
    vector<int> L, sz, ch;
    int tempo;

    HLD(const G& g) 
      : graph(g), in(g.size()), out(g.size()), rin(g.size()), L(g.size()),
        sz(g.size()), ch(g.size()) {
        build();
    }

    inline int size() const { return graph.size(); }

    void dfs0(int u) {
      sz[u] = 1;
      for(auto& k : graph.adj[u]) {
        int v = graph.edge(k).to;
        L[v] = L[u] + 1;
        dfs0(v);
        if(sz[v] > sz[graph.edge(graph.adj[u][0]).to])
          swap(k, graph.adj[u][0]);
        sz[u] += sz[v];
      }
    }

    void dfs1(int u) {
      in[u] = tempo++;
      rin[in[u]] = u;

      if(graph.adj[u].size() > 0) {
        int v = graph.edge(graph.adj[u][0]).to;
        ch[v] = ch[u];
        dfs1(v);
        for(size_t i = 1; i < graph.adj[u].size(); i++) {
          v = graph.edge(graph.adj[u][i]).to;
          ch[v] = v;
          dfs1(v);
        }
      }
      out[u] = tempo;
    }

    void build() {
      vector<int> roots = graph.roots();
      for(int i : roots) dfs0(i);
      tempo = 0;
      for(int i : roots) dfs1(i);
    }

    template<typename Lifter>
    inline void operate_on_subtree(int u, Lifter& lifter) {
      lifter(in[u], out[u]-1, false);
    }

    template<typename T, typename QueryIssuer>
    inline T query_on_subtree(int u, const QueryIssuer& issuer) {
      return issuer(in[u], out[u]-1);
    }

    template<typename Lifter>
    inline void operate_on_subtree_edges(int u, Lifter& lifter) {
      if(in[u]+2 <= out[u]) lifter(in[u]+1, out[u]-1, false);
    }

    template<typename T, typename QueryIssuer>
    inline void query_on_subtree_edges(int u, const QueryIssuer& issuer) {
      assert(in[u]+2 <= out[u]);
      return issuer(in[u]+1, out[u]-1);
    }

    template<bool is_edge, typename Lifter>
    int _query_path(int u, int v, Lifter& lifter) {
      int inv = 0;
      for(; ch[u] != ch[v]; u = graph.parent(ch[u])) {
        if(L[ch[u]] < L[ch[v]])
          swap(u, v), inv ^= 1;
        lifter(in[ch[u]], in[u], (bool)inv);
      }
      if(L[u] > L[v]) swap(u, v), inv ^= 1;
      inv ^= 1;
      if(is_edge && in[u]+1 <= in[v])
        lifter(in[u]+1, in[v], (bool)inv);
      else if(!is_edge)
        lifter(in[u], in[v], (bool)inv);
      return u;
    }

    template<typename Lifter>
    inline int operate_on_path(int u, int v, Lifter& lifter) {
      return _query_path<false>(u, v, lifter);
    }

    template<typename Lifter>
    inline int operate_on_path_edges(int u, int v, Lifter& lifter) {
      return _query_path<true>(u, v, lifter);
    }

    template<typename Op>
    inline void operate_on_vertex(int u, Op& op) {
      op(in[u]);
    }

    template<typename T, typename QueryIssuer>
    inline T query_on_vertex(int u, const QueryIssuer& issuer) {
      return issuer(in[u]);
    }

    inline int lca(int u, int v) {
      return _query_path<false>(u, v, empty_lifter);
    }
  };

  template<typename G>
  HLD<G> make_hld(const G& graph) {
    return HLD<G>(graph);
  }
}  // namespace graph
}  // namespace lib

#endif


namespace lib {
  using namespace std;
namespace graph {
namespace range {
  template<typename Builder, 
           typename H>
  struct BuilderWrapper {
    H* hld;
    Builder builder;

    explicit BuilderWrapper(H* hld, const Builder& builder) 
      : hld(hld), builder(builder) {}

    template<typename Node>
    void operator()(Node& no, int i) const { 
      builder(no, hld->rin[i]); 
    }

    pair<int, int> range() const { return {0, hld->size() - 1}; }
  };

  template<typename Builder, typename H>
  struct RebuilderWrapper : BuilderWrapper<Builder, H> {
    using BuilderWrapper<Builder, H>::BuilderWrapper;
    using BuilderWrapper<Builder, H>::builder;
    template<typename Node>
    void operator()(Node& no, const Node& left, const Node& right) const {
      builder(no, left, right);
    }
  };

  template<typename S, typename T, typename Folder>
  struct QueryIssuer {
    S& seg;
    const Folder& folder;
    QueryIssuer(S& seg, const Folder& folder) : seg(seg), folder(folder) {}
    T operator()(int i) const {
      seg.template query_element<T>(i, folder);
    }
    T operator()(int i, int j) const {
      return seg.template query<T>(i, j, folder);
    }
  };

  template<typename S, typename T, typename Folder>
  struct QueryLifter {
    QueryIssuer<S, T, Folder> issuer;
    T res;
    QueryLifter(S& seg, const Folder& folder) 
      : issuer(seg, folder), res(folder()) {}
    void operator()(int i, int j, bool) {
      res = issuer.folder(res, issuer(i, j));
    }
    T result() const { return res; }
  };

  template<typename S, typename T, typename Folder>
  struct OrderedQueryLifter : QueryLifter<S, T, Folder> {
    using QueryLifter<S, T, Folder>::issuer;
    T resl, resr;

    OrderedQueryLifter(S& seg, const Folder& folder)
      : QueryLifter<S, T, Folder>(seg, folder), 
        resl(folder()), resr(folder()) {}
    
    void operator()(int i, int j, bool right) {
      if(right)
        resr = issuer.folder(issuer(i, j), resr);
      else
        resl = issuer.folder(resl, issuer(i, j));
    }
    T result() const { return issuer.folder(resl, resr); }
  };

  template<typename S, typename Updater>
  struct UpdateIssuer {
    S& seg;
    const Updater& updater;
    UpdateIssuer(S& seg, const Updater& updater)
      : seg(seg), updater(updater) {}
    void operator()(int i, int j) { seg.update(i, j, updater); }
    void operator()(int i, int j, bool) { (*this)(i, j); }
  };

  template<typename S, typename Updater>
  struct SplashIssuer {
    S& seg;
    const Updater& updater;
    SplashIssuer(S& seg, const Updater& updater)
      : seg(seg), updater(updater) {}
    void operator()(int i, int j) { seg.splash(i, j, updater); }
    void operator()(int i, int j, bool) { (*this)(i, j); }
  };

  template<typename S, typename Beater>
  struct BeatIssuer {
    S& seg;
    const Beater& beater;
    BeatIssuer(S& seg, const Beater& beater)
      : seg(seg), beater(beater) {}
    void operator()(int i, int j) { seg.beat(i, j, beater); }
    void operator()(int i, int j, bool) { (*this)(i, j); }
  };
}  // namespace range

  template<typename S,
           typename G>
  struct RangeHLD : HLD<G> {
    typedef seg::EmptyLeafBuilder empty_builder;

    template<typename Builder>
    using builder_wrapper = range::BuilderWrapper<Builder, HLD<G>>;
    template<typename Rebuilder>
    using rebuilder_wrapper = range::RebuilderWrapper<Rebuilder, HLD<G>>;

    S seg;

    explicit RangeHLD(const G& graph) 
      : HLD<G>(graph),
        seg(builder_wrapper<empty_builder>(this, empty_builder(this->size()))) {}

    template<typename Builder>
    RangeHLD(const G& graph, const Builder& builder)
      : HLD<G>(graph), 
        seg(builder_wrapper<Builder>(this, builder)) {}

    template<typename Builder>
    void build(const Builder& builder) {
      seg.build(builder_wrapper<Builder>(builder));
    }
    
    template<typename Rebuilder>
    void rebuild(const Rebuilder& rebuilder) {
      seg.rebuild(rebuilder_wrapper<Rebuilder>(rebuilder));
    }

    template<typename T, typename Folder>
    inline T query_subtree(int u, const Folder& folder) {
      return this->template 
        query_on_subtree<T>(u, range::QueryIssuer<S, T, Folder>(seg, folder));
    }

    template<typename T, typename Folder>
    inline T query_subtree_edges(int u, const Folder& folder) {
      return this->template
        query_on_subtree_edges(u, range::QueryIssuer<S, T, Folder>(seg, folder));
    }

    template<typename T, typename Folder>
    inline T query_vertex(int u, const Folder& folder) {
      return this->template
        query_on_vertex(u, range::QueryIssuer<S, T, Folder>(seg, folder));
    }

    template<typename T, typename Folder>
    T query_path(int u, int v, const Folder& folder) {
      auto lifter = range::OrderedQueryLifter<S, T, Folder>(seg, folder);
      this->template
        operate_on_path(u, v, lifter);
      return lifter.result();
    }

    template<typename T, typename Folder>
    T query_path_edges(int u, int v, const Folder& folder) {
      auto lifter = range::OrderedQueryLifter<S, T, Folder>(seg, folder);
      this->template
        operate_on_path_edges(u, v, lifter);
      return lifter.result();
    }

    template<typename Updater>
    inline void update_subtree(int u, const Updater& updater) {
      auto issuer = range::UpdateIssuer<S, Updater>(seg, updater);
      this->template operate_on_subtree(u, issuer);
    }

    template<typename Updater>
    inline void update_subtree_edges(int u, const Updater& updater) {
      auto issuer = range::UpdateIssuer<S, Updater>(seg, updater);
      this->template operate_on_subtree_edges(u, issuer);
    }

    template<typename Updater>
    inline void update_path(int u, int v, const Updater& updater) {
      auto issuer = range::UpdateIssuer<S, Updater>(seg, updater);
      this->template operate_on_path(u, v, issuer);
    }

    template<typename Updater>
    inline void update_path_edges(int u, int v, const Updater& updater) {
      auto issuer = range::UpdateIssuer<S, Updater>(seg, updater);
      this->template operate_on_path_edges(u, v, issuer);
    }

    template<typename Beater>
    inline void beat_subtree(int u, const Beater& beater) {
      auto issuer = range::BeatIssuer<S, Beater>(seg, beater);
      this->template operate_on_subtree(u, issuer);
    }

    template<typename Beater>
    inline void beat_subtree_edges(int u, const Beater& beater) {
      auto issuer = range::BeatIssuer<S, Beater>(seg, beater);
      this->template operate_on_subtree_edges(u, issuer);
    }

    template<typename Beater>
    inline void beat_path(int u, int v, const Beater& beater) {
      auto issuer = range::BeatIssuer<S, Beater>(seg, beater);
      this->template operate_on_path(u, v, issuer);
    }

    template<typename Beater>
    inline void beat_path_edges(int u, int v, const Beater& beater) {
      auto issuer = range::BeatIssuer<S, Beater>(seg, beater);
      this->template operate_on_path_edges(u, v, issuer);
    }

    // FIX THOSE 
    template<typename Updater>
    inline void update_element(int idx, const Updater& updater) {
      seg.update_element(idx, updater);
    }

    template<typename Updater>
    inline void splash(int i, int j, const Updater& updater) {
      seg.splash(i, j, updater);
    }
  };

  template<typename S, typename G>
  RangeHLD<S, G> make_range_hld(const G& graph) {
    return RangeHLD<S, G>(graph);
  }

  template<typename S, typename G, typename Builder>
  RangeHLD<S, G> make_range_hld(const G& graph, const Builder& builder) {
    return RangeHLD<S, G>(graph, builder);
  }

}  // namespace graph
}  // namespace lib

#endif


#ifndef _LIB_SEGTREE_BEATS
#define _LIB_SEGTREE_BEATS



namespace lib {
  using namespace std;
namespace seg { 
  struct DefaultBreakCond {
    template<typename Node>
    inline bool operator()(const Node& no, int l, int r, int i, int j) const {
      return i > r || j < l;
    }
  };

  struct DefaultTagCond {
    template<typename Node>
    inline bool operator()(const Node& no, int l, int r, int i, int j) const {
      return i <= l && r <= j;
    }
  };

  template<typename Node, 
           typename CombinerFn = EmptyFolder<int>,
           typename PushdownFn = EmptyPushdown, 
           typename BreakCond = DefaultBreakCond, 
           typename TagCond = DefaultTagCond>
  struct SegtreeBeats {
    const static int ROOT = 1;
    const static int MULTIPLIER = 4;
    const static int SHIFT = 0;


    CombinerFn combiner_fn;
    PushdownFn pushdown_fn;
    BreakCond break_cond;
    TagCond tag_cond;

    vector<Node> t;
    int L, R;

    template<typename Builder>
    explicit SegtreeBeats(const Builder& builder) {
      pair<int, int> range = builder.range();
      L = range.first;
      R = range.second;
      assert(L >= 0 && L <= R);
      t = vector<Node>(size() * MULTIPLIER + SHIFT);
      build(builder);
    }

    template<typename Builder>
    void build(const Builder& builder, int no, int l, int r) {
      if(l == r) {
        builder(t[no], l);
      } else {
        int mid = (l+r)/2;
        build(builder, no<<1, l, mid);
        build(builder, no<<1|1, mid+1, r);
        t[no] = combiner_fn(t[no<<1], t[no<<1|1]);
      }
    }

    template<typename Builder>
    void build(const Builder& builder) {
      return build(builder, ROOT, L, R);
    }

    inline int size() const { return R-L+1; }

    void push(int no, int l, int r) {
      Node* left = l == r ? 0 : &t[no<<1];
      Node* right = l == r ? 0 : &t[no<<1|1];
      pushdown_fn(t[no], l, r, left, right);
    }

    template<typename T, typename Folder>
    T query(int no, int l, int r, int i, int j, const Folder& folder) {
      if(j < l || i > r) return folder();
      push(no, l, r);
      if(i <= l && r <= j) return folder(t[no]);
      int mid = (l+r)/2;
      return folder(
          query<T>(no<<1, l, mid, i, j, folder),
          query<T>(no<<1|1, mid+1, r, i, j, folder)
      );
    }

    template<typename T, typename Folder>
    inline T query(int i, int j, const Folder& folder) {
      return query<T>(ROOT, L, R, i, j, folder);
    }

    template<typename Updater>
    void update(int no, int l, int r, int i, int j, const Updater& updater) {
      push(no, l, r);
      if(break_cond(t[no], l, r, i, j)) {
        return;
      }
      if(tag_cond(t[no], l, r, i, j)) {
        updater(t[no]);
        push(no, l, r);
        return;
      }
      int mid = (l+r)/2;
      update(no<<1, l, mid, i, j, updater);
      update(no<<1|1, mid+1, r, i, j, updater);
      t[no] = combiner_fn(t[no<<1], t[no<<1|1]);
    }

    template<typename Updater>
    inline void update(int i, int j, const Updater& updater) {
      update(ROOT, L, R, i, j, updater);
    }

    template<typename Beater>
    void beat(int no, int l, int r, int i, int j, const Beater& beater) {
      push(no, l, r);
      if(break_cond(t[no], l, r, i, j) || beater.stop(t[no], l, r, i, j)) {
        return;
      }
      if(tag_cond(t[no], l, r, i, j) && beater.tag(t[no], l, r, i, j)) {
        beater(t[no]);
        push(no, l, r);
        return;
      }
      int mid = (l+r)/2;
      beat(no<<1, l, mid, i, j, beater);
      beat(no<<1|1, mid+1, r, i, j, beater);
      t[no] = combiner_fn(t[no<<1], t[no<<1|1]);
    }

    template<typename Beater>
    inline void beat(int i, int j, const Beater& beater) {
      beat(ROOT, L, R, i, j, beater);
    } 
  };

  template<typename Node, typename CombinerFn>
  struct SegtreeNormal : SegtreeBeats<Node, CombinerFn> {
    typedef SegtreeBeats<Node, CombinerFn> Base;
    using SegtreeBeats<Node, CombinerFn>::SegtreeBeats;
    using Base::ROOT;
    using Base::combiner_fn;
    using Base::L;
    using Base::R;
    using Base::t;

    template<typename Updater>
    void update_element(int no, int l, int r, int idx, const Updater& updater) {
      if(l == r)
        updater(t[no]);
      else {
        int mid = (l+r)/2;
        if(idx <= mid)
          update_element(no<<1, l, mid, idx, updater);
        else
          update_element(no<<1|1, mid+1, r, idx, updater);
        t[no] = combiner_fn(t[no<<1], t[no<<1|1]);
      }
    }
    
    template<typename Updater>
    inline void update_element(int idx, const Updater& updater) {
      update_element(ROOT, L, R, idx, updater);
    }
  };

  template<typename Node>
  struct SegtreeSplash : SegtreeBeats<Node, EmptyFolder<void>> {
    typedef SegtreeBeats<Node, EmptyFolder<void>> Base;
    using Base::SegtreeBeats;
    using Base::ROOT;
    using Base::L;
    using Base::R;
    using Base::t;

    template<typename T, typename Folder>
    T query_element(int no, int l, int r, int idx, const Folder& folder) {
      T res = folder(t[no]);
      if(l != r) {
        int mid = (l+r)/2;
        if(idx <= mid)
          res = folder(res, query_element<T>(no<<1, l, mid, idx, folder));
        else
          res = folder(res, query_element<T>(no<<1|1, mid+1, r, idx, folder));
      }
      return res;
    }

    template<typename T, typename Folder>
    inline T query_element(int idx, const Folder& folder) {
      return query_element<T>(ROOT, L, R, idx, folder);
    }

    template<typename Updater>
    void splash(int no, int l, int r, int i, int j, const Updater& updater) {
      if(break_cond(t[no], l, r, i, j)) {
        return;
      }
      if(tag_cond(t[no], l, r, i, j)) {
        updater(t[no]);
        return;
      }
      int mid = (l+r)/2;
      splash(no<<1, l, mid, i, j, updater);
      splash(no<<1|1, mid+1, r, i, j, updater);
    }

    template<typename Updater>
    inline void splash(int i, int j, const Updater& updater) {
      splash(ROOT, L, R, i, j, updater);
    }
  };
}  // namespace seg
}  // namespace lib

#endif


using namespace std;
using namespace lib;
using lib::graph::Graph;
using lib::graph::HLD;
using lib::seg::SegtreeBeats;

struct Node {
  int mx = 0, lz = 0;
  Node() {}
  Node(int mx) : mx(mx) {}
  operator int() const { return mx; }
  Node& operator+=(const int rhs) {
    lz += rhs;
    return *this;
  }
  Node operator+(const Node& rhs) const {
    return Node(max(mx, rhs.mx));
  }
};

struct Pushdown {
  void operator()(Node& no, int l, int r, Node* lf, Node* rt) const {
    if(no.lz != 0) {
      no.mx += no.lz;
      if(l != r) {
        lf->lz += no.lz;
        rt->lz += no.lz;
      }
      no.lz = 0;
    }
  }
};

void solve() {
  int n;
  cin >> n;

  Graph<> g(n);
  for(int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g.add_2edge(x, y);
  }

  auto f = graph::builders::make_rooted_forest(g, {0});
  auto hld = graph::make_range_hld<SegtreeBeats<Node, seg::CombineFolder<Node>, Pushdown>>(f);

  int Q;
  cin >> Q;
  while(Q--) {
    string t;
    cin >> t;
    if(t == "add") {
      int u, x;
      cin >> u >> x; u--;
      auto updater = seg::AddUpdater<int>(x);
      hld.update_subtree(u, updater);
    } else {
      int x, y;
      cin >> x >> y;
      x--, y--;
      auto folder = seg::MaxFolder<int>();
      cout << hld.query_path<int>(x, y, folder) << endl;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}

