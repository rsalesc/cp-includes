#ifndef _LIB_LAMBDA
#define _LIB_LAMBDA
#include <bits/stdc++.h>
#include "Traits.cpp"

namespace lib {
  using namespace std;
namespace lambda {
  using namespace traits;

const auto identity = [](int i) -> int { return i; };
const auto all = [](int i) -> bool { return true; };
const auto none = [](int i) -> bool { return false; };

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

struct Subset;

template<typename T>
struct SubsetMap : Map<T> {
  using Map<T>::operator();
  using Map<T>::f;

  int n;
  SubsetMap() : Map<T>(), n(0) {}
  template<typename F>
  SubsetMap(int n, F && f_) : Map<T>(f_), n(n) {}
  int size() const { return n; }
  int count() const {
    int cnt = 0;
    for(int i = 0; i < n; i++)
      cnt += f(i) != 0;
    return cnt;
  }
  vector<T> operator()() const {
    vector<T> res(n);
    for(int i = 0; i < n; i++)
      res[i] = f(i);
    return res;
  }

  Subset as_subset() const;

  template<typename U = T,
           enable_if<is_same<U, bool>::value>* = nullptr>
  SubsetMap<T> operator!() const {
    auto g = f;
    return SubsetMap<T>(n, [g](int i) { return !g(i); });
  }

  SubsetMap<T> operator+(const SubsetMap<T>& rhs) const {
    int N = size() + rhs.size();
    auto g = f;
    auto h = rhs.f;
    return SubsetMap<T>(N, [n, g, rhs.g](int i) {
      return i >= n ? h(i - n) : g(i);
    });
  }

  SubsetMap<T> operator*(const SubsetMap<T>& rhs) const {
    auto g = f;
    auto h = rhs.f;
    return SubsetMap<T>(n, [g, h](int i) {
      return g(h(i));
    });
  }
};

struct Subset {
  vector<int> map;
  Subset() {}
  Subset(const vector<int>& map_) : map(map_) {}
  void add(int i) {
    map.push_back(i);
  }
  void pop() { map.pop_back(); }
  void clear() { map.clear(); }
  int size() const { return map.size(); }
  int operator()(int i) const { return map[i]; }
  vector<int> items() const { return map; }

  template<typename F>
  SubsetMap<ValueType<F>> take_from(F && g) const {
    using T = ValueType<F>;
    auto map_ = map;
    return SubsetMap<T>(map.size(), [g, map_](int i) -> T {
      return g(map_[i]);
    });
  }

  Subset take_subset(const Subset& s) const {
    vector<int> res;
    for(int i : items()) {
      res.push_back(s(i));
    }
    return Subset(res);
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

template<typename T>
Subset SubsetMap<T>::as_subset() const {
  Subset map;
  for(int i = 0; i < n; i++)
    if(f(i)) map.add(i);
  return map;
}

using Filter = Map<bool>;
using SubsetFilter = SubsetMap<bool>;

template<typename T>
SubsetMap<T> from_vector(const vector<T>& v) {
  return SubsetMap<T>(v.size(), [v](int i) -> T {
    return v[i];
  });
}

template<typename T>
SubsetFilter filter_from_vector(const vector<T>& v) {
  return SubsetFilter(v.size(), [v](int i) -> bool {
    return v[i];
  });
}

template<typename T>
SubsetFilter filter_from_sparse_vector(const vector<T>& v) {
  return SubsetFilter(v.size(), [v](int i) -> bool {
    return v[i];
  });
}
} // namespace lambda
} // namespace lib

#endif
