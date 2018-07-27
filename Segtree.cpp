#ifndef _LIB_SEGTREE
#define _LIB_SEGTREE
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace seg {
  struct LeafBuilder {
    template<typename Node>
    void operator()(Node& no, int i) const {}
    pair<int, int> range() const { return {0, 0}; }
  };

  struct EmptyLeafBuilder : LeafBuilder {
    int n;
    explicit EmptyLeafBuilder(int n) : n(n) {}
    pair<int, int> range() const { return {0, n-1}; }
  };

  template<typename RandomIterator>
  struct RangeLeafBuilder : LeafBuilder {
    RandomIterator begin, end;
    explicit RangeLeafBuilder(RandomIterator begin, RandomIterator end)
      : begin(begin), end(end) {}

    template<typename Node>
    void operator()(Node& no, int i) const { no = *(begin + i); }

    pair<int, int> range() const { return {0, end-begin-1}; }
  };

  EmptyLeafBuilder make_builder(int n) { return EmptyLeafBuilder(n); }

  template<typename RandomIterator>
  RangeLeafBuilder<RandomIterator> make_builder(RandomIterator begin, 
                                                RandomIterator end) {
    return RangeLeafBuilder<RandomIterator>(begin, end);
  }

  template<typename T>
  RangeLeafBuilder<typename vector<T>::const_iterator>
  make_builder(const vector<T>& v) {
    return RangeLeafBuilder<typename vector<T>::const_iterator>(v.begin(), 
                                                                v.end());
  }

  template<typename T>
  struct CombineFolder {
    T operator()() const { return T(); }

    template<typename Node>
    T operator()(const Node& no) const { return T(no); }

    T operator()(const T& a, const T& b) const { return a + b; }
  };

  template<typename T>
  struct EmptyFolder : CombineFolder<T> {
    using CombineFolder<T>::operator();

    template<typename Node>
    T operator()(const Node& no) const { return T(); }
    T operator()(const T& a, const T& b) const { return T(); }
  };

  template<typename T>
  struct SumFolder : CombineFolder<T> {};
  
  template<typename T>
  struct MaxFolder : CombineFolder<T> {
    using CombineFolder<T>::operator();
    T operator()() const { return numeric_limits<T>::min(); }
    T operator()(const T& a, const T& b) const { return max(a, b); }
  };

  template<typename T>
  struct MinFolder : CombineFolder<T> {
    using CombineFolder<T>::operator();
    T operator()() const { return numeric_limits<T>::max(); }
    T operator()(const T& a, const T& b) const { return min(a, b); }
  };

  template<typename T>
  struct SingleValueUpdater {
    T value;
    explicit SingleValueUpdater(T val) : value(val) {}
  };

  template<typename T>
  struct SetUpdater : SingleValueUpdater<T> {
    using SingleValueUpdater<T>::SingleValueUpdater;

    template<typename Node>
    void operator()(Node& no) const { no = this->value; }
  };

  template<typename T>
  struct AddUpdater: SingleValueUpdater<T> {
    using SingleValueUpdater<T>::SingleValueUpdater;

    template<typename Node>
    void operator()(Node& no) const { no += this->value; }
  };

  struct EmptyPushdown {
    template<typename Node>
    void operator()(Node& no, int l, int r, 
                    Node* ln, Node* rn) const {}
  };
}  // namespace seg
}  // namespace lib

#endif
