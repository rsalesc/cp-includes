#ifndef _LIB_TWO_SAT
#define _LIB_TWO_SAT
#include "Graph.cpp"
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace graph {
#define POS(x) (2*(x))
#define NEG(x) (2*(x)+1)

// TODO: reuse graph structure and extract tarjan
struct TwoSat {
  int n, sz;
  vector<vector<int>> adj;
  
  int tempo, cnt;
  vector<int> low, vis, from;
  stack<int> st;
  vector<bool> res;

  TwoSat(int n) : n(n), adj(2*n){}

  int add_dummy() { 
    int res = adj.size();
    for(int i = 0; i < 2; i++)
      adj.push_back(vector<int>());
    return res;
  }

  int convert(int x) const { return 2*x; }
  void add_edge(int a, int b) { adj[a].push_back(b); }
  void or_clause(int a, int b){
    add_edge(a^1, b);
    add_edge(b^1, a);
  }

  void implication_clause(int a, int b){
    or_clause(a^1, b);
  }

  void literal_clause(int x) { or_clause(x, x); }
  void and_clause(int a, int b){
    literal_clause(a);
    literal_clause(b);
  }

  void xor_clause(int a, int b){
    or_clause(a, b);
    or_clause(a^1, b^1);
  }

  void nand_clause(int a, int b){
    or_clause(a^1, b^1);
  }

  void nor_clause(int a, int b){
    literal_clause(a^1);
    literal_clause(b^1);
  }

  void equals(int a, int b){
    implication_clause(a, b);
    implication_clause(b, a);
  }

  void max_one_clause(const vector<int> & v){
    vector<int> p;
    for(int i = 0; i < v.size(); i++)
      p.push_back(add_dummy());

    for(int i = 0; i < v.size(); i++){
      implication_clause(v[i], p[i]);
      if(i+1 < v.size()){
        implication_clause(p[i], p[i+1]);
        implication_clause(p[i], v[i+1]^1);
      }
    }
  }

  void clear(){
    for(int i = 0; i < adj.size(); i++) 
      adj[i].clear();
  }

  void tarjan(int u){
    low[u] = vis[u] = ++tempo;
    st.push(u);

    for(int v : adj[u]){
      if(!vis[v]){
        tarjan(v);
        low[u] = min(low[u], low[v]);
      } else if(vis[v] > 0)
        low[u] = min(low[u], vis[v]);
    }

    if(low[u] == vis[u]){
      int k;
      do{
        k = st.top();
        st.pop();
        from[k] = cnt;
        vis[k] = -1;
      } while(k != u);
      cnt++;
    }
  }

  bool solve(){
    sz = adj.size();
    assert(sz%2 == 0);

    low.assign(sz, 0);
    vis.assign(sz, 0);
    tempo = 0;
    cnt = 0;
    from.assign(sz, -1);
    st = stack<int>();
    
    res.assign(n, true);

    for(int i = 0; i < sz; i++)
      if(!vis[i])
        tarjan(i);

    for(int i = 0; i < sz; i += 2){
      if(from[i] == from[i^1]) return false;
      else if(from[i] > from[i^1] && (i>>1) < n)
        res[i>>1] = false;
    }

    return true;
  }

  bool get(int i) const { return res[i]; }
};
} // namespace graph
} // namespace lib

#endif
