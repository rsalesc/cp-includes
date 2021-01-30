#ifndef _LIB_EDGE_FINDER
#define _LIB_EDGE_FINDER
#include <bits/stdc++.h>
#include "Matroid.cpp"
#include "../../Lambda.cpp"

namespace lib {
  using namespace std;
namespace matroid {
template<typename F>
auto edge_finder(
  IncrementalMatroid& m,
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
} // namespace matroid
} // namespace lib

#endif
