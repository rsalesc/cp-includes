---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: DSU.cpp
    title: DSU.cpp
  - icon: ':warning:'
    path: Lambda.cpp
    title: Lambda.cpp
  - icon: ':warning:'
    path: Traits.cpp
    title: Traits.cpp
  - icon: ':warning:'
    path: matroid/v2/Matroid.cpp
    title: matroid/v2/Matroid.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"matroid/v2/GraphicMatroid.cpp\"\n\n\n#include <bits/stdc++.h>\n\
    #line 1 \"matroid/v2/Matroid.cpp\"\n\n\n#line 1 \"Lambda.cpp\"\n\n\n#line 1 \"\
    Traits.cpp\"\n\n\n#line 4 \"Traits.cpp\"\n\nnamespace lib {\nusing namespace std;\n\
    namespace traits {\n\ntemplate <typename...> struct make_void { using type = void;\
    \ };\n\ntemplate <typename... T> using void_t = typename make_void<T...>::type;\n\
    \n/// keep caide\ntemplate <typename Iterator>\nusing IteratorCategory = typename\
    \ iterator_traits<Iterator>::iterator_category;\n\n/// keep caide\ntemplate <typename\
    \ Container>\nusing IteratorCategoryOf = IteratorCategory<typename Container::iterator>;\n\
    \n/// keep caide\ntemplate <typename Iterator>\nusing IteratorValue = typename\
    \ iterator_traits<Iterator>::value_type;\n\n/// keep caide\ntemplate <typename\
    \ Container>\nusing IteratorValueOf = IteratorValue<typename Container::iterator>;\n\
    \n/// keep caide\ntemplate <typename Iterator>\nusing IsRandomIterator =\n   \
    \ is_base_of<random_access_iterator_tag, IteratorCategory<Iterator>>;\n\n/// keep\
    \ caide\ntemplate <typename Iterator>\nusing IsInputIterator =\n    is_base_of<input_iterator_tag,\
    \ IteratorCategory<Iterator>>;\n\n/// keep caide\ntemplate <typename Iterator>\n\
    using IsBidirectionalIterator =\n    is_base_of<bidirectional_iterator_tag, IteratorCategory<Iterator>>;\n\
    \n/// keep caide\ntemplate <typename Container>\nusing HasRandomIterator =\n \
    \   is_base_of<random_access_iterator_tag, IteratorCategoryOf<Container>>;\n\n\
    /// keep caide\ntemplate <typename Container>\nusing HasInputIterator =\n    is_base_of<input_iterator_tag,\
    \ IteratorCategoryOf<Container>>;\n\n/// keep caide\ntemplate <typename Container>\n\
    using HasBidirectionalIterator =\n    is_base_of<bidirectional_iterator_tag, IteratorCategoryOf<Container>>;\n\
    } // namespace traits\n} // namespace lib\n\n\n#line 5 \"Lambda.cpp\"\n\nnamespace\
    \ lib {\n  using namespace std;\nnamespace lambda {\n  using namespace traits;\n\
    \nconst auto identity = [](int i) -> int { return i; };\nconst auto all = [](int\
    \ i) -> bool { return true; };\nconst auto none = [](int i) -> bool { return false;\
    \ };\n\nauto first_n(int n) {\n  return [n](int i) -> bool { return i < n; };\n\
    }\n\ntemplate<typename F, typename I = int>\nusing ValueType = decltype(declval<F>()(declval<I>()));\n\
    \ntemplate<typename T>\nstruct Map {\n  std::function<T(int)> f;\n  Map() {}\n\
    \  template<typename F>\n  Map(const F& f_) : f(f_) {}\n  T operator()(int i)\
    \ const {\n    return f(i);\n  }\n};\n\nstruct Subset;\n\ntemplate<typename T>\n\
    struct SubsetMap : Map<T> {\n  using Map<T>::operator();\n  using Map<T>::f;\n\
    \n  int n;\n  SubsetMap() : Map<T>(), n(0) {}\n  template<typename F>\n  SubsetMap(int\
    \ n, F && f_) : Map<T>(f_), n(n) {}\n  int size() const { return n; }\n  int count()\
    \ const {\n    int cnt = 0;\n    for(int i = 0; i < n; i++)\n      cnt += f(i)\
    \ != 0;\n    return cnt;\n  }\n  vector<T> operator()() const {\n    vector<T>\
    \ res(n);\n    for(int i = 0; i < n; i++)\n      res[i] = f(i);\n    return res;\n\
    \  }\n\n  Subset as_subset() const;\n\n  template<typename U = T,\n          \
    \ enable_if_t<is_same<U, bool>::value>* = nullptr>\n  SubsetMap<T> operator!()\
    \ const {\n    return SubsetMap<T>(n, [f=f](int i) { return !f(i); });\n  }\n\n\
    \  template<typename U = T,\n           enable_if_t<is_same<U, bool>::value>*\
    \ = nullptr>\n  SubsetMap<T> operator|(const SubsetMap<T>& rhs) const {\n    return\
    \ SubsetMap<T>(n, [f=f, g=rhs.f](int i) { return f(i) || g(i); });\n  }\n\n  SubsetMap<T>\
    \ operator+(const SubsetMap<T>& rhs) const {\n    int N = size() + rhs.size();\n\
    \    return SubsetMap<T>(N, [n=n, f=f, g=rhs.f](int i) {\n      return i >= n\
    \ ? g(i - n) : f(i);\n    });\n  }\n\n  SubsetMap<T> operator*(const SubsetMap<T>&\
    \ rhs) const {\n    return SubsetMap<T>(n, [f=f, g=rhs.f](int i) {\n      return\
    \ f(g(i));\n    });\n  }\n};\n\nstruct Subset {\n  mutable vector<int> map;\n\
    \  Subset() {}\n  Subset(const vector<int>& map_) : map(map_) {\n  }\n  void add(int\
    \ i) {\n    map.push_back(i);\n  }\n  void pop() { map.pop_back(); }\n  void clear()\
    \ { map.clear(); }\n  int size() const { return map.size(); }\n  int operator()(int\
    \ i) const { return map[i]; }\n  vector<int> items() const { return map; }\n\n\
    \  template<typename F>\n  SubsetMap<ValueType<F>> take_from(F && g) const {\n\
    \    using T = ValueType<F>;\n    auto map_ = map;\n    return SubsetMap<T>(map.size(),\
    \ [g, map_](int i) -> T {\n      return g(map_[i]);\n    });\n  }\n\n  Subset\
    \ take_subset(const Subset& s) const {\n    vector<int> res;\n    for(int i :\
    \ items()) {\n      res.push_back(s(i));\n    }\n    return Subset(res);\n  }\n\
    \n  SubsetMap<int> take_indices() const {\n    return take_from(identity);\n \
    \ }\n\n  SubsetMap<int> take_inverse(int def = -1) const {\n    int n = 0;\n \
    \   auto it = max_element(map.begin(), map.end());\n    if(it != map.end()) n\
    \ = *it + 1;\n    vector<int> inv(n, def);\n    for(int i = 0; i < map.size();\
    \ i++)\n      inv[map[i]] = i;\n    return SubsetMap<int>(n, [inv](int i) -> int\
    \ {\n      return inv[i];\n    });\n  }\n\n  void sort() const {\n    std::sort(map.begin(),\
    \ map.end());\n  }\n\n  Subset operator|(const Subset& rhs) const {\n    sort();\n\
    \    rhs.sort();\n    vector<int> res;\n    res.reserve(size() + rhs.size());\n\
    \    merge(map.begin(), map.end(), rhs.map.begin(), rhs.map.end(), back_inserter(res));\n\
    \    auto it = unique(res.begin(), res.end());\n    res.resize(it - res.begin());\n\
    \    return res;\n  }\n};\n\ntemplate<>\nstruct Map<bool> {\n    std::function<bool(int)>\
    \ f;\n    Map() {}\n    template<typename F>\n    Map(const F& f_) : f(f_) {}\n\
    \    bool operator()(int i) const {\n      return f(i);\n    }\n\n    template\
    \ <\n      typename Iterator,\n      typename enable_if<IsInputIterator<Iterator>::value>::type\
    \ * = nullptr>\n    vector<IteratorValue<Iterator>> operator()(Iterator begin,\
    \ Iterator end) const {\n      vector<IteratorValue<Iterator>> res;\n      int\
    \ i = 0;\n      for(auto it = begin; it != end; ++it, ++i) {\n        if(f(i))\
    \ res.push_back(*it);\n      }\n      return res;\n    }\n    template <\n   \
    \   typename Container,\n      typename enable_if<HasInputIterator<Container>::value>::type\
    \ * = nullptr>\n    vector<IteratorValueOf<Container>> operator()(const Container&\
    \ c) const {\n      return (*this)(c.begin(), c.end());\n    }\n\n    Subset subset(int\
    \ n) const {\n      Subset map;\n      for(int i = 0; i < n; i++)\n        if(f(i))\
    \ map.add(i);\n      return map;\n    }\n\n    template<typename F>\n    SubsetMap<ValueType<F>>\
    \ subset(int n, F && g) const {\n      return subset(SubsetMap<ValueType<F>>(n,\
    \ g));\n    }\n\n    template<typename T>\n    SubsetMap<T> subset(const SubsetMap<T>&\
    \ g) const {\n      return subset(g.size()).take_from(g);\n    }\n};\n\nnamespace\
    \ {\ntemplate<typename T,\n         enable_if_t<is_same<T, bool>::value>* = nullptr>\n\
    Subset as_subset_(const SubsetMap<T>& rhs) {\n  Subset map;\n  for(int i = 0;\
    \ i < rhs.size(); i++)\n    if(rhs(i)) map.add(i);\n  return map;\n}\ntemplate<typename\
    \ T,\n         enable_if_t<!is_same<T, bool>::value>* = nullptr>\nSubset as_subset_(const\
    \ SubsetMap<T>& rhs) {\n  Subset map;\n  for(int i = 0; i < rhs.size(); i++)\n\
    \    map.add(rhs(i));\n  return map;\n}\n}\n\n\ntemplate<typename T>\nSubset SubsetMap<T>::as_subset()\
    \ const {\n  return as_subset_(*this);\n  \n}\n\nusing Filter = Map<bool>;\nusing\
    \ SubsetFilter = SubsetMap<bool>;\n\ntemplate<typename T>\nSubsetMap<T> from_vector(const\
    \ vector<T>& v) {\n  return SubsetMap<T>(v.size(), [v](int i) -> T {\n    return\
    \ v[i];\n  });\n}\n\ntemplate<typename U, typename F, typename T = ValueType<F,\
    \ U>>\nSubsetMap<T> map_from_vector(const vector<U>& v, const F& f) {\n  return\
    \ SubsetMap<T>(v.size(), [v, f](int i) -> T {\n    return f(v[i]);\n  });\n}\n\
    \ntemplate<typename T>\nSubsetFilter filter_from_vector(const vector<T>& v) {\n\
    \  return SubsetFilter(v.size(), [v](int i) -> bool {\n    return v[i];\n  });\n\
    }\n\ntemplate<typename T>\nSubsetFilter filter_from_sparse_vector(const vector<T>&\
    \ v) {\n  return SubsetFilter(v.size(), [v](int i) -> bool {\n    return v[i];\n\
    \  });\n}\n} // namespace lambda\n} // namespace lib\n\n\n#line 5 \"matroid/v2/Matroid.cpp\"\
    \n\nnamespace lib {\n  using namespace std;\nstruct Matroid {\n  int matroid_size_;\n\
    \  Matroid() {}\n  Matroid(int n) : matroid_size_(n) {}\n  void set_ground(int\
    \ n) { matroid_size_ = n; }\n  int size() const { return matroid_size_; }\n  virtual\
    \ int rank(const lambda::Subset&, const lambda::SubsetFilter&) = 0;\n  virtual\
    \ void clear() = 0;\n  virtual void add(int i) = 0;\n  virtual bool check(int\
    \ i) = 0;\n\n  int rank() {\n    lambda::SubsetFilter f(size(), lambda::all);\n\
    \    return rank(f.as_subset(), f);\n  }\n\n  vector<int> basis(const lambda::Subset&\
    \ s) {\n    clear();\n    vector<int> res;\n    for(int i : s.items()) {\n   \
    \   if(check(i)) {\n        res.push_back(i);\n        add(i);\n      }\n    }\n\
    \    return res;\n  }\n  vector<int> basis() {\n    return basis(lambda::Filter(lambda::all).subset(size()));\n\
    \  }\n};\n\nstruct IncrementalMatroid : Matroid {\n  int rank(const lambda::Subset&\
    \ s, const lambda::SubsetFilter&) override {\n    clear();\n    int ans = 0;\n\
    \    for(int i : s.items())\n      if(check(i)) add(i), ans++;\n    return ans;\n\
    \  }\n};\n\nstruct RankMatroid : Matroid {\n  lambda::Subset sI;\n  vector<int>\
    \ vI;\n  void clear() override { vI.assign(size(), 0), sI.clear(); }\n  void add(int\
    \ i) override { vI[i] = true, sI.add(i); }\n  bool check(int i) override {\n \
    \   if(vI[i]) return true;\n    vI[i] = true;\n    sI.add(i);\n    bool ok = rank(sI,\
    \ lambda::filter_from_sparse_vector(vI)) >= sI.size();\n    vI[i] = false;\n \
    \   sI.pop();\n    return ok;\n  }\n};\n\nnamespace matroid {\ntemplate<typename\
    \ M>\nusing IsRank = is_base_of<RankMatroid, M>;\n\ntemplate<typename M>\nusing\
    \ IsIncremental = is_base_of<IncrementalMatroid, M>;\n} // namespace matroid\n\
    } // namespace lib\n\n\n#line 1 \"DSU.cpp\"\n\n\n#line 4 \"DSU.cpp\"\n\nnamespace\
    \ lib {\nusing namespace std;\n\nstruct DSU {\n  vector<int> p, ptime, sz;\n \
    \ int tempo = 0;\n  int merges = 0;\n\n  DSU(int n = 0) : p(n), ptime(n), sz(n,\
    \ 1) { iota(p.begin(), p.end(), 0); }\n\n  int make_node() {\n    int i = p.size();\n\
    \    p.emplace_back(i);\n    ptime.emplace_back(0);\n    sz.emplace_back(1);\n\
    \    return 1;\n  }\n\n  int get(int i, int at) const {\n    return p[i] == i\
    \ ? i : (at >= ptime[i] ? get(p[i], at) : i);\n  }\n\n  int operator[](int i)\
    \ const { return get(i, tempo); }\n\n  int merge(int u, int v) {\n    u = (*this)[u],\
    \ v = (*this)[v];\n    if (u == v)\n      return 0;\n    if (sz[u] < sz[v])\n\
    \      swap(u, v);\n    p[v] = u;\n    ptime[v] = ++tempo;\n    sz[u] += sz[v];\n\
    \    merges++;\n    return 1;\n  }\n\n  int n_comps() const { return (int)p.size()\
    \ - merges; }\n};\n\nstruct CompressedDSU {\n  vector<int> p;\n  CompressedDSU(int\
    \ n = 0) : p(n) { iota(p.begin(), p.end(), 0); }\n  int get(int i) {\n    return\
    \ p[i] == i ? i : p[i] = get(p[i]);\n  }\n  int operator[](int i) { return get(i);\
    \ }\n  int& parent(int i) { return p[i]; }\n};\n\nstruct FastDSU {\n  vector<int>\
    \ p, sz;\n  int merges = 0;\n  FastDSU(int n = 0) : p(n), sz(n, 1) { iota(p.begin(),\
    \ p.end(), 0); }\n\n  int get(int i) {\n    return p[i] == i ? i : p[i] = get(p[i]);\n\
    \  }\n  int operator[](int i) { return get(i); }\n\n  int merge(int u, int v)\
    \ {\n    u = get(u), v = get(v);\n    if(u == v) return 0;\n    if(sz[u] < sz[v])\n\
    \      swap(u, v);\n    p[v] = u;\n    sz[u] += sz[v];\n    merges++;\n    return\
    \ 1;\n  }\n\n  int n_comps() const { return (int)p.size() - merges; }\n};\n} //\
    \ namespace lib\n\n\n#line 6 \"matroid/v2/GraphicMatroid.cpp\"\n\nnamespace lib\
    \ {\n  using namespace std;\nstruct GraphicMatroid : IncrementalMatroid {\n  using\
    \ Edge = pair<int, int>;\n  FastDSU dsu;\n  int g_sz;\n  lambda::Map<pair<int,\
    \ int>> edge_fn;\n  GraphicMatroid() {}\n  GraphicMatroid(int n, const lambda::SubsetMap<pair<int,\
    \ int>>& fn) \n    : IncrementalMatroid(), g_sz(n), edge_fn(fn), dsu(n) {\n  \
    \    set_ground(fn.size());\n  }\n  void clear() override {\n    dsu = FastDSU(g_sz);\n\
    \  }\n  void add(int i) override {\n    auto p = edge_fn(i);\n    dsu.merge(p.first,\
    \ p.second);\n  }\n  bool check(int i) override {\n    auto p = edge_fn(i);\n\
    \    return dsu.get(p.first) != dsu.get(p.second);\n  }\n};\n} // namespace lib\n\
    \n\n"
  code: "#ifndef _LIB_GRAPHIC_MATROID\n#define _LIB_GRAPHIC_MATROID\n#include <bits/stdc++.h>\n\
    #include \"Matroid.cpp\"\n#include \"../../DSU.cpp\"\n\nnamespace lib {\n  using\
    \ namespace std;\nstruct GraphicMatroid : IncrementalMatroid {\n  using Edge =\
    \ pair<int, int>;\n  FastDSU dsu;\n  int g_sz;\n  lambda::Map<pair<int, int>>\
    \ edge_fn;\n  GraphicMatroid() {}\n  GraphicMatroid(int n, const lambda::SubsetMap<pair<int,\
    \ int>>& fn) \n    : IncrementalMatroid(), g_sz(n), edge_fn(fn), dsu(n) {\n  \
    \    set_ground(fn.size());\n  }\n  void clear() override {\n    dsu = FastDSU(g_sz);\n\
    \  }\n  void add(int i) override {\n    auto p = edge_fn(i);\n    dsu.merge(p.first,\
    \ p.second);\n  }\n  bool check(int i) override {\n    auto p = edge_fn(i);\n\
    \    return dsu.get(p.first) != dsu.get(p.second);\n  }\n};\n} // namespace lib\n\
    \n#endif\n"
  dependsOn:
  - matroid/v2/Matroid.cpp
  - Lambda.cpp
  - Traits.cpp
  - DSU.cpp
  isVerificationFile: false
  path: matroid/v2/GraphicMatroid.cpp
  requiredBy: []
  timestamp: '2021-02-03 01:52:23-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matroid/v2/GraphicMatroid.cpp
layout: document
redirect_from:
- /library/matroid/v2/GraphicMatroid.cpp
- /library/matroid/v2/GraphicMatroid.cpp.html
title: matroid/v2/GraphicMatroid.cpp
---
