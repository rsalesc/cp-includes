#ifndef _LIB_LAMBDA
#define _LIB_LAMBDA
#include <bits/stdc++.h>
#include "Traits.cpp"

namespace lib {
  using namespace std;
namespace lambda {
  using namespace traits;

const auto identity = [](int i) -> int { return i; };

template<typename F>
using ValueType = decltype(declval<F>()(0));

template<typename T>
struct Map {
  std::function<T(int)> f;
  Map() {}
  template<typename F>
  Map(const F& f_) : f(f_) {}
  T operator()(int i) const {
    return f(i);
  }
};

template<typename T>
struct SubsetMap : Map<T> {
  using Map<T>::operator();
  using Map<T>::f;

  int n;
  SubsetMap() : Map<T>(), n(0) {}
  template<typename F>
  SubsetMap(int n, F && f_) : Map<T>(f_), n(n) {}
  int size() const { return n; }
  vector<T> operator()() const {
    vector<T> res(n);
    for(int i = 0; i < n; i++)
      res[i] = f(i);
    return res;
  }

  template<typename U = T,
           enable_if<is_same<U, bool>::value>* = nullptr>
  SubsetMap<T> operator!() const {
    auto g = f;
    return SubsetMap<T>(n, [g](int i) { return !g(i); });
  }
};

struct Subset {
  vector<int> map;
  void add(int i) {
    map.push_back(i);
  }
  int size() const { return map.size(); }

  template<typename F>
  SubsetMap<ValueType<F>> take_from(F && g) const {
    using T = ValueType<F>;
    auto map_ = map;
    return SubsetMap<T>(map.size(), [g, map_](int i) -> T {
      return g(map_[i]);
    });
  }

  SubsetMap<int> take_indices() const {
    return take_from(identity);
  }

  SubsetMap<int> take_inverse(int def = -1) const {
    int n = 0;
    auto it = max_element(map.begin(), map.end());
    if(it != map.end()) n = *it + 1;
    vector<int> inv(n, def);
    for(int i = 0; i < map.size(); i++)
      inv[map[i]] = i;
    return SubsetMap<int>(n, [inv](int i) -> int {
      return inv[i];
    });
  }
};

template<>
struct Map<bool> {
    std::function<bool(int)> f;
    Map() {}
    template<typename F>
    Map(const F& f_) : f(f_) {}
    bool operator()(int i) const {
      return f(i);
    }

    template <
      typename Iterator,
      typename enable_if<IsInputIterator<Iterator>::value>::type * = nullptr>
    vector<IteratorValue<Iterator>> operator()(Iterator begin, Iterator end) const {
      vector<IteratorValue<Iterator>> res;
      int i = 0;
      for(auto it = begin; it != end; ++it, ++i) {
        if(f(i)) res.push_back(*it);
      }
      return res;
    }
    template <
      typename Container,
      typename enable_if<HasInputIterator<Container>::value>::type * = nullptr>
    vector<IteratorValueOf<Container>> operator()(const Container& c) const {
      return (*this)(c.begin(), c.end());
    }

    Subset subset(int n) const {
      Subset map;
      for(int i = 0; i < n; i++)
        if(f(i)) map.add(i);
      return map;
    }

    template<typename F>
    SubsetMap<ValueType<F>> subset(int n, F && g) const {
      return subset(SubsetMap<ValueType<F>>(n, g));
    }

    template<typename T>
    SubsetMap<T> subset(const SubsetMap<T>& g) const {
      return subset(g.size()).take_from(g);
    }
};

// template<>
// Map<bool>::Map(Map<bool> && m) : f(move(m)) {}

using Filter = Map<bool>;
using SubsetFilter = SubsetMap<bool>;
} // namespace lambda
} // namespace lib

#endif
