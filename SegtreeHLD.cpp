#ifndef _LIB_RANGE_HLD
#define _LIB_RANGE_HLD
#include <bits/stdc++.h>
#include "HLD.cpp"

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

