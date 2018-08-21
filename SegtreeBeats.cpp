#ifndef _LIB_SEGTREE_BEATS
#define _LIB_SEGTREE_BEATS
#include <bits/stdc++.h>
#include "Segtree.cpp"

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
