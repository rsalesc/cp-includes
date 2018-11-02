#ifndef _LIB_GRAPH
#define _LIB_GRAPH
#include <bits/stdc++.h>
#include "Traits.cpp"
#include "utils/Wrappers.cpp"

namespace lib {
  using namespace std;
namespace graph {
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
    inline int edge_size() const { return edges.size(); }
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
      return edges.back().data;
    }

    void add_2edge(int u, int v) {
      add_edge(u, v);
      add_edge(v, u);
    }

    template<typename S = E, typename enable_if<!is_void<S>::value>::type* = nullptr>
    inline void add_2edge(int u, int v, const S& data) {
      add_edge(u, v) = data;
      add_edge(v, u) = data;
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
