#ifndef _LIB_EDGE_FINDER
#define _LIB_EDGE_FINDER
#include <bits/stdc++.h>
#include "Matroid.cpp"
#include "../../Lambda.cpp"

namespace lib {
  using namespace std;
namespace matroid {

template<typename M, typename F>
auto incremental_edge_finder(
  M& m,
  const lambda::Subset& sI,
  const lambda::SubsetFilter& I,
  int v,
  F && test) {
  return [&, v, test, done=0, ans=vector<int>()] () mutable {
    if(v < I.size() && !I(v)) {
      // CASE 1: v is an element not in IS.
      // In this case, should add v and remove a neighbor.
      m.clear();
      // First of all, add v.
      if(!m.check(v)) return -1;
      m.add(v);
      // Now add IS elements that aren't in B. These can't be removed.
      for(int i : sI.items()) {
        if(test(i)) continue;
        if(!m.check(i)) return -1;
        m.add(i);
      }
      // Finally, add IS elements that ARE in B. 
      for(int i : sI.items()) {
        if(!test(i)) continue;
        if(!m.check(i)) {
          // Introducing i and every element that comes next
          // makes this a circuit, that can be made independent by removing i.
          return i;
        }
        m.add(i);
      }
      // Element can be added directly, with no exchange.
      return I.size();
    }
    // CASE 2: v is source or an element in IS.
    if(!done) {
      // In this case, we should try adding elements after removing v.
      m.clear();
      for(int i : sI.items())
        if(i != v) m.add(i);
      for(int i = 0; i < I.size(); i++)
        if(!I(i) && test(i) && m.check(i))
          ans.push_back(i);
    }
    if(done < ans.size()) return ans[done++];
    return -1;
  };
}

template<typename M, typename F>
auto rank_edge_finder(
  M& m,
  const lambda::Subset& sI,
  const lambda::SubsetFilter& I,
  int v,
  F && test) {

  // Fast SubsetFilter.
  static vector<int> mask(1);
  int n = mask.size();
  while(n < I.size()) n *= 2;
  mask.assign(n, 0);

  auto filter = lambda::SubsetFilter(I.size(), [](int i) {
    return mask[i];
  });
  const static auto subset_mask = [](const lambda::Subset& s) {
    for(int i : s.items())
      mask[i] = true;
  };
  const static auto clear_mask = [](const lambda::Subset& s) {
    for(int i : s.items())
      mask[i] = false;
  };

  return [&, v, test, filter, sub=lambda::Subset()] () mutable {
    vector<int> need, extra;
    if(v < I.size() && !I(v)) {
      // CASE 1: v NOT in IS.
      // `need` will be v + elements that are in IS
      // but are not in B. Thus, they can't be part of
      // an exchange.
      // `extra` will be elements of IS that are in B.
      need.push_back(v);
      for(auto i : sI.items())
        if(!test(i)) need.push_back(i);
        else extra.push_back(i);

      auto check = [&](int mid) {
        need.insert(need.end(), extra.begin(), extra.begin() + mid);
        swap(sub.map, need);
        subset_mask(sub);
        int res = m.rank(sub, filter);
        clear_mask(sub);
        swap(sub.map, need);
        need.erase(need.end() - mid, need.end());
        return res == need.size() + mid;
      };

      // Binary search on element that makes up the circuit.
      if(!check(0)) return -1;
      if(check(extra.size())) return I.size();
      int l = 0, r = extra.size() + 1;
      while(l < r) {
        int mid = (l+r)/2;
        if(!check(mid))
          r = mid;
        else l = mid + 1;
      }
      if(l == extra.size() + 1) return I.size();
      return extra[l-1];
    }

    // CASE 2: v in IS.
    for(int i : sI.items())
      if(i != v) need.push_back(i);
    for(int i = 0; i < I.size(); i++)
      if(!I(i) && test(i)) extra.push_back(i);
    auto check = [&](int l, int r) {
      need.insert(need.end(), extra.begin() + l, extra.begin() + r);
      swap(sub.map, need);
      subset_mask(sub);
      int res = m.rank(sub, filter);
      clear_mask(sub);
      swap(sub.map, need);
      need.erase(need.end() - (r - l), need.end());
      return res > need.size();
    };

    int l = 0, r = extra.size();
    if(!check(l, r)) return -1;
    while(l < r) {
      int mid = (l+r)/2;
      if(check(l, mid+1))
        r = mid;
      else l = mid + 1;
    }
    return extra[l];
  };
}

} // namespace matroid
} // namespace lib

#endif
