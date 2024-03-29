#ifndef _LIB_SEGTREE
#define _LIB_SEGTREE
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace seg {
struct LeafBuilder {
  template <typename Node> void operator()(Node &no, int i) const {}
  inline pair<int, int> range() const { return {0, 0}; }
  bool should_build() const { return true; }
};

struct EmptyLeafBuilder : LeafBuilder {
  int n;
  explicit EmptyLeafBuilder(int n) : n(n) {}
  inline pair<int, int> range() const { return {0, n - 1}; }
  bool should_build() const { return true; }
};

struct ImplicitBuilder : LeafBuilder {
  int L, R;
  explicit ImplicitBuilder(int L, int R) : L(L), R(R) {}
  inline pair<int, int> range() const { return {L, R}; }
  bool should_build() const { return false; }
};

// TODO: NOT IMPLEMENTED
template <typename DefaultNode>
struct ImplicitWithDefaultBuilder : LeafBuilder {
  int L, R;
  DefaultNode default_node;
  explicit ImplicitWithDefaultBuilder(int L, int R, DefaultNode def)
      : L(L), R(R), default_node(def) {}

  template <typename Node> inline void operator()(Node &no, int i) const {
    no = default_node;
  }

  inline pair<int, int> range() const { return {L, R}; }
  bool should_build() const { return false; }
};

template <typename RandomIterator> struct RangeLeafBuilder : LeafBuilder {
  RandomIterator begin, end;
  explicit RangeLeafBuilder(RandomIterator begin, RandomIterator end)
      : begin(begin), end(end) {}

  template <typename Node> inline void operator()(Node &no, int i) const {
    no = *(begin + i);
  }

  inline pair<int, int> range() const { return {0, end - begin - 1}; }
};

template <typename F> struct LambdaLeafBuilder : LeafBuilder {
  F f;
  pair<int, int> rng;
  explicit LambdaLeafBuilder(F f, pair<int, int> range)
      : f(f), rng(range) {}

  template <typename Node> inline void operator()(Node &no, int i) const {
    no = f(i);
  }

  inline pair<int, int> range() const { return rng; }
};

EmptyLeafBuilder make_builder(int n) { return EmptyLeafBuilder(n); }

template <typename RandomIterator>
RangeLeafBuilder<RandomIterator> make_builder(RandomIterator begin,
                                              RandomIterator end) {
  return RangeLeafBuilder<RandomIterator>(begin, end);
}

template <typename T>
RangeLeafBuilder<typename vector<T>::const_iterator>
make_builder(const vector<T> &v) {
  return RangeLeafBuilder<typename vector<T>::const_iterator>(v.begin(),
                                                              v.end());
}

template<typename T>
LambdaLeafBuilder<std::function<T(int)>>
make_builder(std::function<T(int)> f, pair<int, int> range) {
  return LambdaLeafBuilder<std::function<T(int)>>(f, range);
}

template <typename T> struct CombineFolder {
  inline T operator()() const { return T(); }

  template <typename Node> inline T operator()(const Node &no) const {
    return T(no);
  }

  inline T operator()(const T &a, const T &b) const { return a + b; }
};

template <typename T> struct EmptyFolder : CombineFolder<T> {
  using CombineFolder<T>::operator();

  template <typename Node> inline T operator()(const Node &no) const {
    return T();
  }
  inline T operator()(const T &a, const T &b) const { return T(); }
};

template <typename T> struct SumFolder : CombineFolder<T> {};

template <typename T> struct ProductFolder : CombineFolder<T> {
  using CombineFolder<T>::operator();
  inline T operator()() const { return T(1); }
  inline T operator()(const T &a, const T &b) const { return a * b; }
};

template <typename T> struct MaxFolder : CombineFolder<T> {
  using CombineFolder<T>::operator();
  inline T operator()() const { return numeric_limits<T>::min(); }
  inline T operator()(const T &a, const T &b) const { return max(a, b); }
};

template <typename T> struct MinFolder : CombineFolder<T> {
  using CombineFolder<T>::operator();
  inline T operator()() const { return numeric_limits<T>::max(); }
  inline T operator()(const T &a, const T &b) const { return min(a, b); }
};

template <typename T> struct SingleValueUpdater {
  T value;
  explicit SingleValueUpdater(T val) : value(val) {}
};

template <typename T> struct SetUpdater : SingleValueUpdater<T> {
  using SingleValueUpdater<T>::SingleValueUpdater;

  template <typename Node> inline void operator()(Node &no) const {
    no = this->value;
  }
};

template <typename T> struct AddUpdater : SingleValueUpdater<T> {
  using SingleValueUpdater<T>::SingleValueUpdater;

  template <typename Node> inline void operator()(Node &no) const {
    no += this->value;
  }
};

template <typename T> struct MultUpdater : SingleValueUpdater<T> {
  using SingleValueUpdater<T>::SingleValueUpdater;

  template <typename Node> inline void operator()(Node &no) const {
    no *= this->value;
  }
};

struct EmptyPushdown {
  template<typename Node>
  inline bool dirty(const Node& no) const { return false; }

  template<typename Node>
  inline void operator()(Node& no, int l, int r, 
                  Node* ln, Node* rn) const {}
};

template<typename Node>
struct Active : public Node {
  bool active_ = false;
  Active& operator=(const Node& no) {
    Node::operator=(no);
    return *this;
  }
  bool is_active() const { return active_; }
  Active& activate() {
    active_ = true;
    return *this;
  }
  Active& deactivate() {
    active_ = false;
    return *this;
  }
  void toggle() {
    active_ = !active_;
  }
  friend Active<Node> operator+(const Active<Node>& a, const Active<Node>& b) {
    if(!a.active_) return b;
    else if(!b.active_) return a;
    Active<Node> res;
    res = Node(a) + Node(b);
    return res.activate();
  }
};

template <typename T>
struct ActiveUpdater {
  bool flag;

  ActiveUpdater(bool f) : flag(f) {}

  template <typename Node> inline void operator()(Node &no) const {
    no.active_ = flag;
  }
};
}  // namespace seg
}  // namespace lib

#endif
