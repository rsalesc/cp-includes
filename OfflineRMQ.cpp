#ifndef _LIB_OFFLINE_RMQ
#define _LIB_OFFLINE_RMQ
#include <bits/stdc++.h>
#include "DSU.cpp"

namespace lib {
using namespace std;

// O(n + qlogn)
template<typename T, typename U = T>
vector<T> offline_rmq(const vector<T>& v, const vector<pair<U, U>>& qrs) {
  int n = v.size();
  vector<vector<pair<U, int>>> cont(n);
  for(int i = 0; i < (int)qrs.size(); i++) {
    auto p = qrs[i];
    cont[p.second].push_back({p.first, i});
  }
  vector<T> ans(qrs.size());

  CompressedDSU dsu(n);
  vector<U> s;
  for(int i = 0; i < n; i++) {
    while(!s.empty() && v[s.back()] > v[i]) {
      dsu.parent(s.back()) = i;
      s.pop_back();
    }
    s.push_back(i);
    for(auto p : cont[i]) {
      ans[p.second] = v[dsu[p.first]];
    }
  }
  return ans;
}
} // namespace lib

#endif

