#ifndef _LIB_MATROID
#define _LIB_MATROID
#include <bits/stdc++.h>
#include "../../Lambda.cpp"

namespace lib {
  using namespace std;
struct Matroid {
  int matroid_size_;
  lambda::SubsetMap<int> ground_map_;
  int F(int i) const { return ground_map_(i); }
  const lambda::SubsetMap<int>& map() { return ground_map_; }
  int size() const { return matroid_size_; }
  void build(const lambda::SubsetMap<int>& s) {
    matroid_size_ = s.size();
    ground_map_ = s;
    build_deps();
  }
  void build(int n) {
    build(lambda::SubsetMap<int>(n, lambda::identity));
  }
  virtual void build_deps() {}
  virtual int rank(const lambda::Subset&, const lambda::SubsetFilter&) = 0;
  virtual void clear() = 0;
  virtual void add(int i) = 0;
  virtual bool check(int i) = 0;

  int rank() {
    lambda::SubsetFilter f(size(), lambda::all);
    return rank(f.as_subset(), f);
  }

  vector<int> basis(const lambda::Subset& s) {
    clear();
    vector<int> res;
    for(int i : s.items()) {
      if(check(i)) {
        res.push_back(i);
        add(i);
      }
    }
    return res;
  }
  vector<int> basis() {
    return basis(lambda::Filter(lambda::all).subset(size()));
  }
};

struct IncrementalMatroid : Matroid {
  int rank(const lambda::Subset& s, const lambda::SubsetFilter&) override {
    clear();
    int ans = 0;
    for(int i : s.items())
      if(check(i)) add(i), ans++;
    return ans;
  }
};

struct RankMatroid : Matroid {
  lambda::Subset sI;
  vector<int> vI;
  void clear() override { vI.assign(size(), 0), sI.clear(); }
  void add(int i) override { vI[i] = true, sI.add(i); }
  bool check(int i) override {
    if(vI[i]) return true;
    vI[i] = true;
    sI.add(i);
    bool ok = rank(sI, lambda::filter_from_sparse_vector(vI)) >= sI.size();
    vI[i] = false;
    sI.pop();
    return ok;
  }
};

namespace matroid {
template<typename M>
using IsRank = is_base_of<RankMatroid, M>;

template<typename M>
using IsIncremental = is_base_of<IncrementalMatroid, M>;
} // namespace matroid
} // namespace lib

#endif
