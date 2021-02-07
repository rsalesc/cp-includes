---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Lambda.cpp
    title: Lambda.cpp
  - icon: ':heavy_check_mark:'
    path: Traits.cpp
    title: Traits.cpp
  - icon: ':warning:'
    path: matroid/v2/EdgeFinder.cpp
    title: matroid/v2/EdgeFinder.cpp
  - icon: ':warning:'
    path: matroid/v2/Matroid.cpp
    title: matroid/v2/Matroid.cpp
  - icon: ':warning:'
    path: utils/FastQueue.cpp
    title: utils/FastQueue.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"matroid/v2/MatroidIntersection.cpp\"\n\n\n#include <bits/stdc++.h>\n\
    #line 1 \"matroid/v2/EdgeFinder.cpp\"\n\n\n#line 1 \"matroid/v2/Matroid.cpp\"\n\
    \n\n#line 1 \"Lambda.cpp\"\n\n\n#line 1 \"Traits.cpp\"\n\n\n#line 4 \"Traits.cpp\"\
    \n\nnamespace lib {\nusing namespace std;\nnamespace traits {\n\ntemplate <typename...>\
    \ struct make_void { using type = void; };\n\ntemplate <typename... T> using void_t\
    \ = typename make_void<T...>::type;\n\n/// keep caide\ntemplate <typename Iterator>\n\
    using IteratorCategory = typename iterator_traits<Iterator>::iterator_category;\n\
    \n/// keep caide\ntemplate <typename Container>\nusing IteratorCategoryOf = IteratorCategory<typename\
    \ Container::iterator>;\n\n/// keep caide\ntemplate <typename Iterator>\nusing\
    \ IteratorValue = typename iterator_traits<Iterator>::value_type;\n\n/// keep\
    \ caide\ntemplate <typename Container>\nusing IteratorValueOf = IteratorValue<typename\
    \ Container::iterator>;\n\n/// keep caide\ntemplate <typename Iterator>\nusing\
    \ IsRandomIterator =\n    is_base_of<random_access_iterator_tag, IteratorCategory<Iterator>>;\n\
    \n/// keep caide\ntemplate <typename Iterator>\nusing IsInputIterator =\n    is_base_of<input_iterator_tag,\
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
    } // namespace lib\n\n\n#line 6 \"matroid/v2/EdgeFinder.cpp\"\n\nnamespace lib\
    \ {\n  using namespace std;\nnamespace matroid {\n\ntemplate<typename M, typename\
    \ F>\nauto incremental_edge_finder(\n  M& m,\n  const lambda::Subset& sI,\n  const\
    \ lambda::SubsetFilter& I,\n  int v,\n  F && test) {\n  return [&, v, test, done=0,\
    \ ans=vector<int>()] () mutable {\n    if(v < I.size() && !I(v)) {\n      // CASE\
    \ 1: v is an element not in IS.\n      // In this case, should add v and remove\
    \ a neighbor.\n      m.clear();\n      // First of all, add v.\n      if(!m.check(v))\
    \ return -1;\n      m.add(v);\n      // Now add IS elements that aren't in B.\
    \ These can't be removed.\n      for(int i : sI.items()) {\n        if(test(i))\
    \ continue;\n        if(!m.check(i)) return -1;\n        m.add(i);\n      }\n\
    \      // Finally, add IS elements that ARE in B. \n      for(int i : sI.items())\
    \ {\n        if(!test(i)) continue;\n        if(!m.check(i)) {\n          // Introducing\
    \ i and every element that comes next\n          // makes this a circuit, that\
    \ can be made independent by removing i.\n          return i;\n        }\n   \
    \     m.add(i);\n      }\n      // Element can be added directly, with no exchange.\n\
    \      return I.size();\n    }\n    // CASE 2: v is source or an element in IS.\n\
    \    if(!done) {\n      // In this case, we should try adding elements after removing\
    \ v.\n      m.clear();\n      for(int i : sI.items())\n        if(i != v) m.add(i);\n\
    \      for(int i = 0; i < I.size(); i++)\n        if(!I(i) && test(i) && m.check(i))\n\
    \          ans.push_back(i);\n    }\n    if(done < ans.size()) return ans[done++];\n\
    \    return -1;\n  };\n}\n\ntemplate<typename M, typename F>\nauto rank_edge_finder(\n\
    \  M& m,\n  const lambda::Subset& sI,\n  const lambda::SubsetFilter& I,\n  int\
    \ v,\n  F && test) {\n\n  // Fast SubsetFilter.\n  static vector<int> mask(1);\n\
    \  int n = mask.size();\n  while(n < I.size()) n *= 2;\n  mask.assign(n, 0);\n\
    \n  auto filter = lambda::SubsetFilter(I.size(), [](int i) {\n    return mask[i];\n\
    \  });\n  const static auto subset_mask = [](const lambda::Subset& s) {\n    for(int\
    \ i : s.items())\n      mask[i] = true;\n  };\n  const static auto clear_mask\
    \ = [](const lambda::Subset& s) {\n    for(int i : s.items())\n      mask[i] =\
    \ false;\n  };\n\n  return [&, v, test, filter, sub=lambda::Subset()] () mutable\
    \ {\n    vector<int> need, extra;\n    if(v < I.size() && !I(v)) {\n      // CASE\
    \ 1: v NOT in IS.\n      // `need` will be v + elements that are in IS\n     \
    \ // but are not in B. Thus, they can't be part of\n      // an exchange.\n  \
    \    // `extra` will be elements of IS that are in B.\n      need.push_back(v);\n\
    \      for(auto i : sI.items())\n        if(!test(i)) need.push_back(i);\n   \
    \     else extra.push_back(i);\n\n      auto check = [&](int mid) {\n        need.insert(need.end(),\
    \ extra.begin(), extra.begin() + mid);\n        swap(sub.map, need);\n       \
    \ subset_mask(sub);\n        int res = m.rank(sub, filter);\n        clear_mask(sub);\n\
    \        swap(sub.map, need);\n        need.erase(need.end() - mid, need.end());\n\
    \        return res == need.size() + mid;\n      };\n\n      // Binary search\
    \ on element that makes up the circuit.\n      if(!check(0)) return -1;\n    \
    \  if(check(extra.size())) return I.size();\n      int l = 0, r = extra.size()\
    \ + 1;\n      while(l < r) {\n        int mid = (l+r)/2;\n        if(!check(mid))\n\
    \          r = mid;\n        else l = mid + 1;\n      }\n      if(l == extra.size()\
    \ + 1) return I.size();\n      return extra[l-1];\n    }\n\n    // CASE 2: v in\
    \ IS.\n    for(int i : sI.items())\n      if(i != v) need.push_back(i);\n    for(int\
    \ i = 0; i < I.size(); i++)\n      if(!I(i) && test(i)) extra.push_back(i);\n\
    \    auto check = [&](int l, int r) {\n      need.insert(need.end(), extra.begin()\
    \ + l, extra.begin() + r);\n      swap(sub.map, need);\n      subset_mask(sub);\n\
    \      int res = m.rank(sub, filter);\n      clear_mask(sub);\n      swap(sub.map,\
    \ need);\n      need.erase(need.end() - (r - l), need.end());\n      return res\
    \ > need.size();\n    };\n\n    int l = 0, r = extra.size();\n    if(!check(l,\
    \ r)) return -1;\n    while(l < r) {\n      int mid = (l+r)/2;\n      if(check(l,\
    \ mid+1))\n        r = mid;\n      else l = mid + 1;\n    }\n    return extra[l];\n\
    \  };\n}\n\n} // namespace matroid\n} // namespace lib\n\n\n#line 1 \"utils/FastQueue.cpp\"\
    \n\n\n#line 4 \"utils/FastQueue.cpp\"\n\nnamespace lib {\n  using namespace std;\n\
    template<typename T>\nstruct FastQueue {\n  vector<T> v;\n  int L = 0, R = 0;\n\
    \  FastQueue(int cap) : v(cap) {}\n\n  void push(const T& no) {\n    if(R >= v.size())\
    \ v.emplace_back();\n    v[R++] = no;\n  }\n  T& front() {\n    return v[L];\n\
    \  }\n  T front() const {\n    return v[L];\n  }\n  T pop() {\n    return v[L++];\n\
    \  }\n  bool empty() const {\n    return L >= R;\n  }\n  int size() const {\n\
    \    return max(R - L, 0);\n  }\n  void clear() {\n    L = 0, R = 0;\n  }\n};\n\
    } // namespace lib\n\n\n#line 7 \"matroid/v2/MatroidIntersection.cpp\"\n\nnamespace\
    \ lib {\ntemplate<typename M1, typename M2>\nstruct MatroidIntersection {\n  int\
    \ n;\n  M1 m1;\n  M2 m2;\n\n  bool rank1 = false, rank2 = false;\n\n  // aux vectors\n\
    \  vector<int> vI;\n  vector<int> I;\n  FastQueue<int> q;\n  vector<int> dist;\n\
    \n  lambda::Subset sI_;\n  lambda::SubsetFilter I_;\n\n  MatroidIntersection()\
    \ : q(1) { init (); }\n  MatroidIntersection(const M1& m1, const M2& m2) : m1(m1),\
    \ m2(m2), n(m1.size()), q(m1.size()) {\n    assert(m1.size() == m2.size());\n\
    \    n = m1.size();\n    init();\n  }\n  void use_rank(bool i1, bool i2) {\n \
    \   rank1 = i1, rank2 = i2;\n  }\n  int size() const { return n; }\n  void init()\
    \ {\n    vI.clear();\n    vI.reserve(n);\n    I.assign(n, false);\n  }\n  void\
    \ clear() { init(); }\n  void setup_set() {\n    vI.clear();\n    for(int i =\
    \ 0; i < n; i++) {\n      if(I[i]) vI.push_back(i);\n    }\n    I_ = lambda::SubsetFilter(n,\
    \ [this](int i) -> bool { return in_I(i); });\n    sI_ = I_.subset(n);\n  }\n\
    \  template<typename M>\n  std::function<int()> edge_finder(M& mat, int u, int\
    \ d, bool rank) {\n    if(rank)\n      return matroid::rank_edge_finder(mat, sI_,\
    \ I_, u, [this, d](int i) { return dist[i] == d; });\n    return matroid::incremental_edge_finder(mat,\
    \ sI_, I_, u, [this, d](int i) { return dist[i] == d; });\n  }\n  bool dfs(int\
    \ u, int du) {\n    int v;\n    auto forward_edge = edge_finder(m2, u, du - 1,\
    \ rank2);\n    auto backward_edge = edge_finder(m1, u, du - 1, rank1);\n    while((v\
    \ = (du&1) ? backward_edge() : forward_edge()) >= 0) {\n      if(v == n) return\
    \ true;\n      dist[v] = -1;\n      if(dfs(v, du - 1))\n        return I[v] ^=\
    \ 1, true;\n    }\n    return false;\n  }\n  bool augment(bool single = true)\
    \ {\n    setup_set();\n    q.clear();\n    dist.assign(n+2, -1);\n    dist[n+1]\
    \ = 0;\n    q.push(n+1);\n    while(dist[n] == -1 && !q.empty()) {\n      int\
    \ u = q.pop();\n      auto forward_edge = edge_finder(m1, u, -1, rank1);\n   \
    \   auto backward_edge = edge_finder(m2, u, -1, rank2);\n      int v;\n      while(dist[n]\
    \ == -1 && (v = (dist[u]&1) ? backward_edge() : forward_edge()) >= 0) {\n    \
    \    q.push(v), dist[v] = dist[u]+1;\n      }\n    }\n    if(dist[n] == -1) return\
    \ false;\n    while(dfs(n, dist[n])) {\n      setup_set();\n      if(single) break;\n\
    \    }\n    return true;\n  }\n  vector<int> solve() {\n    m1.clear(), m2.clear();\n\
    \    for(int i = 0; i < n; i++) {\n      if(m1.check(i) && m2.check(i)) {\n  \
    \      m1.add(i), m2.add(i), I[i] = true;\n      }\n    }\n    while(augment(false));\n\
    \    return I;\n  }\n  int cardinality() const {\n    int res = 0;\n    for(int\
    \ i = 0; i < n; i++)\n      res += I[i];\n    return res;\n  }\n  bool in_I(int\
    \ i) const {\n    return I[i];\n  }\n  const vector<int>& get_I() const {\n  \
    \  return I;\n  }\n};\n\ntemplate<typename M1, typename M2>\nshared_ptr<MatroidIntersection<M1,\
    \ M2>> make_matroid_intersection(const M1& m1, const M2& m2) {\n  return make_shared<MatroidIntersection<M1,\
    \ M2>>(m1, m2);\n}\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_MATROID_INTERSECTION_V2\n#define _LIB_MATROID_INTERSECTION_V2\n\
    #include <bits/stdc++.h>\n#include \"EdgeFinder.cpp\"\n#include \"../../utils/FastQueue.cpp\"\
    \n#include \"../../Lambda.cpp\"\n\nnamespace lib {\ntemplate<typename M1, typename\
    \ M2>\nstruct MatroidIntersection {\n  int n;\n  M1 m1;\n  M2 m2;\n\n  bool rank1\
    \ = false, rank2 = false;\n\n  // aux vectors\n  vector<int> vI;\n  vector<int>\
    \ I;\n  FastQueue<int> q;\n  vector<int> dist;\n\n  lambda::Subset sI_;\n  lambda::SubsetFilter\
    \ I_;\n\n  MatroidIntersection() : q(1) { init (); }\n  MatroidIntersection(const\
    \ M1& m1, const M2& m2) : m1(m1), m2(m2), n(m1.size()), q(m1.size()) {\n    assert(m1.size()\
    \ == m2.size());\n    n = m1.size();\n    init();\n  }\n  void use_rank(bool i1,\
    \ bool i2) {\n    rank1 = i1, rank2 = i2;\n  }\n  int size() const { return n;\
    \ }\n  void init() {\n    vI.clear();\n    vI.reserve(n);\n    I.assign(n, false);\n\
    \  }\n  void clear() { init(); }\n  void setup_set() {\n    vI.clear();\n    for(int\
    \ i = 0; i < n; i++) {\n      if(I[i]) vI.push_back(i);\n    }\n    I_ = lambda::SubsetFilter(n,\
    \ [this](int i) -> bool { return in_I(i); });\n    sI_ = I_.subset(n);\n  }\n\
    \  template<typename M>\n  std::function<int()> edge_finder(M& mat, int u, int\
    \ d, bool rank) {\n    if(rank)\n      return matroid::rank_edge_finder(mat, sI_,\
    \ I_, u, [this, d](int i) { return dist[i] == d; });\n    return matroid::incremental_edge_finder(mat,\
    \ sI_, I_, u, [this, d](int i) { return dist[i] == d; });\n  }\n  bool dfs(int\
    \ u, int du) {\n    int v;\n    auto forward_edge = edge_finder(m2, u, du - 1,\
    \ rank2);\n    auto backward_edge = edge_finder(m1, u, du - 1, rank1);\n    while((v\
    \ = (du&1) ? backward_edge() : forward_edge()) >= 0) {\n      if(v == n) return\
    \ true;\n      dist[v] = -1;\n      if(dfs(v, du - 1))\n        return I[v] ^=\
    \ 1, true;\n    }\n    return false;\n  }\n  bool augment(bool single = true)\
    \ {\n    setup_set();\n    q.clear();\n    dist.assign(n+2, -1);\n    dist[n+1]\
    \ = 0;\n    q.push(n+1);\n    while(dist[n] == -1 && !q.empty()) {\n      int\
    \ u = q.pop();\n      auto forward_edge = edge_finder(m1, u, -1, rank1);\n   \
    \   auto backward_edge = edge_finder(m2, u, -1, rank2);\n      int v;\n      while(dist[n]\
    \ == -1 && (v = (dist[u]&1) ? backward_edge() : forward_edge()) >= 0) {\n    \
    \    q.push(v), dist[v] = dist[u]+1;\n      }\n    }\n    if(dist[n] == -1) return\
    \ false;\n    while(dfs(n, dist[n])) {\n      setup_set();\n      if(single) break;\n\
    \    }\n    return true;\n  }\n  vector<int> solve() {\n    m1.clear(), m2.clear();\n\
    \    for(int i = 0; i < n; i++) {\n      if(m1.check(i) && m2.check(i)) {\n  \
    \      m1.add(i), m2.add(i), I[i] = true;\n      }\n    }\n    while(augment(false));\n\
    \    return I;\n  }\n  int cardinality() const {\n    int res = 0;\n    for(int\
    \ i = 0; i < n; i++)\n      res += I[i];\n    return res;\n  }\n  bool in_I(int\
    \ i) const {\n    return I[i];\n  }\n  const vector<int>& get_I() const {\n  \
    \  return I;\n  }\n};\n\ntemplate<typename M1, typename M2>\nshared_ptr<MatroidIntersection<M1,\
    \ M2>> make_matroid_intersection(const M1& m1, const M2& m2) {\n  return make_shared<MatroidIntersection<M1,\
    \ M2>>(m1, m2);\n}\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - matroid/v2/EdgeFinder.cpp
  - matroid/v2/Matroid.cpp
  - Lambda.cpp
  - Traits.cpp
  - utils/FastQueue.cpp
  isVerificationFile: false
  path: matroid/v2/MatroidIntersection.cpp
  requiredBy: []
  timestamp: '2021-02-03 01:52:23-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matroid/v2/MatroidIntersection.cpp
layout: document
redirect_from:
- /library/matroid/v2/MatroidIntersection.cpp
- /library/matroid/v2/MatroidIntersection.cpp.html
title: matroid/v2/MatroidIntersection.cpp
---
