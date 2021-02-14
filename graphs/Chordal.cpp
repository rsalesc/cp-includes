#ifndef _LIB_CHORDAL
#define _LIB_CHORDAL
#include <bits/stdc++.h>
#include "../utils/FastList.cpp"

namespace lib {
  using namespace std;
namespace graph {
namespace {
  using Elements = pair<vector<int>, int>;
  using SetList = lib::list::Node<Elements>;
  shared_ptr<SetList> make_set_list(int n = 0) {
    return make_shared<SetList>(Elements(vector<int>(n), 0));
  }
}
// No parallel edges or self-loops.
template<typename Graph>
vector<int> lex_bfs(const Graph& g) {
  int n = g.size();
  vector<int> res(n);
  vector<int> vis(n);
  vector<pair<shared_ptr<SetList>, int>> inv(n);
  auto data = make_set_list(n);
  for(int i = 0; i < n; i++) {
    data->val.first[i] = i;
    inv[i] = make_pair(data, i);
  }

  auto head = make_set_list();
  list::append(head.get(), data.get());

  for(int i = 0; i < n; i++) {
    auto no = head->next;
    assert(no != nullptr);
    assert(!no->val.first.empty());
    const int u = res[i] = no->val.first.back();
    no->val.first.pop_back();
    if(no->val.first.empty()) list::remove(no);
    vis[u] = 1;

    // Partition
    for(const auto& e : g.n_edges(u)) {
      int v = e.to;
      if(vis[v]) continue;
      auto st = inv[v].first;
      int sz = st->val.first.size();
      if(sz == 1) continue;
      auto idx = inv[v].second;
      swap(st->val.first[idx], st->val.first[sz - 1 - st->val.second]);
      swap(inv[v].second, inv[st->val.first[idx]].second);
      st->val.second++;
    }

    for(const auto& e : g.n_edges(u)) {
      int v = e.to;
      if(vis[v]) continue;
      auto st = inv[v].first;
      int st_sz = st->val.first.size();
      int size_new = st->val.second;
      assert(size_new <= st_sz);
      if(size_new == 0 || size_new == st_sz) {
        st->val.second = 0;
        continue;
      }
      auto new_data = make_set_list(size_new);
      for(int i = 0; i < size_new; i++) {
        new_data->val.first[i] = st->val.first[st_sz - size_new + i];
        inv[new_data->val.first[i]] = {new_data, i};
      }

      st->val.first.resize(st_sz - size_new);
      st->val.second = 0;

      // both st and new_data should have size > 0 at this point
      list::prepend(st.get(), new_data.get());
    }
  }

  return res;
}

template<typename Graph>
struct Chordal {
  mutable vector<int> vis, par;
  mutable vector<int> cyc;

  Graph g;
  vector<int> order, inv;
  mutable bool was_tested = false;
  Chordal(Graph g) : g(g) {
    order = lex_bfs(g);
    reverse(order.begin(), order.end());
    int n = g.size();
    inv = vector<int>(n);
    for(int i = 0; i < n; i++) inv[order[i]] = i;
  }

  bool is_valid() const {
    if(was_tested) return cyc.empty();
    int n = g.size();

    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++) {
      for(const auto& e : g.n_edges(i)) {
        adj[i].push_back(e.to);
      }
      sort(adj[i].begin(), adj[i].end());
    }

    for(int k = n-2; k >= 0; k--) {
      int i = order[k];
      pair<int, int> best = {1e9, -1};
      for(const auto& e : g.n_edges(i)) {
        if(inv[e.to] > k)
          best = min(best, {inv[e.to], e.to});
      }
      auto v = best.second;
      if(v == -1) continue;
      for(const auto& e : g.n_edges(i)) {
        if(inv[e.to] > inv[v])
          if(!binary_search(adj[v].begin(), adj[v].end(), e.to)) {
            was_tested = true;
            par.assign(n, -1), vis.assign(n, 0);
            queue<int> q;
            vis[e.to] = 1;
            q.push(e.to);
            while(!q.empty()) {
              int x = q.front(); q.pop();
              for(const auto& e2 : g.n_edges(x)) {
                int y = e2.to;
                if(vis[y]) continue;
                if(y == i) continue;
                if(y != v && binary_search(adj[i].begin(), adj[i].end(), y)) continue;
                vis[y] = 1;
                q.push(y);
                par[y] = x;
              }
            }
            cyc.clear();
            cyc.push_back(e.to);
            cyc.push_back(i);
            assert(vis[v]);
            for(auto x = v; x != e.to; x = par[x]) cyc.push_back(x);
            return false;
          }
      }
    }
    was_tested = true;
    return true;
  }

  vector<int> induced_cycle() const { return cyc; }

  vector<int> max_independent_set() const {
    int n = g.size();
    vis.assign(n, 0);

    vector<int> res;
    for(int i : order) {
      if(vis[i]) continue;
      res.push_back(i);
      for(const auto& e : g.n_edges(i)) {
        vis[e.to] = 1;
      }
    }
    return res;
  }
};

template<typename Graph>
Chordal<Graph> make_chordal(const Graph& g) {
  return Chordal<Graph>(g);
}
} // namespace graph
} // namespace lib

#endif