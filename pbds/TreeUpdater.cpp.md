---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Traits.cpp
    title: Traits.cpp
  - icon: ':question:'
    path: bits/stdc++.h
    title: bits/stdc++.h
  - icon: ':warning:'
    path: traits/Tuple.cpp
    title: traits/Tuple.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"pbds/TreeUpdater.cpp\"\n\n\n#line 1 \"Traits.cpp\"\n\n\n\
    #include <bits/stdc++.h>\n\nnamespace lib {\nusing namespace std;\nnamespace traits\
    \ {\n\ntemplate <typename...> struct make_void { using type = void; };\n\ntemplate\
    \ <typename... T> using void_t = typename make_void<T...>::type;\n\n/// keep caide\n\
    template <typename Iterator>\nusing IteratorCategory = typename iterator_traits<Iterator>::iterator_category;\n\
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
    } // namespace traits\n} // namespace lib\n\n\n#line 1 \"traits/Tuple.cpp\"\n\n\
    \n#line 4 \"traits/Tuple.cpp\"\n\nnamespace lib {\nusing namespace std;\nnamespace\
    \ traits {\ntemplate <class Tuple, class T, std::size_t Index = 0> struct find_first;\n\
    \ntemplate <std::size_t Index, bool Valid>\nstruct find_first_final_test\n   \
    \ : public std::integral_constant<std::size_t, Index> {};\n\ntemplate <std::size_t\
    \ Index> struct find_first_final_test<Index, false> {\n  static_assert(Index ==\
    \ -1, \"Type not found in find_first\");\n};\n\ntemplate <class Head, class T,\
    \ std::size_t Index>\nstruct find_first<std::tuple<Head>, T, Index>\n    : public\
    \ find_first_final_test<Index, std::is_same<Head, T>::value> {};\n\ntemplate <class\
    \ Head, class... Rest, class T, std::size_t Index>\nstruct find_first<std::tuple<Head,\
    \ Rest...>, T, Index>\n    : public std::conditional<\n          std::is_same<Head,\
    \ T>::value,\n          std::integral_constant<std::size_t, Index>,\n        \
    \  find_first<std::tuple<Rest...>, T, Index + 1>>::type {};\n} // namespace traits\n\
    } // namespace lib\n\n\n#line 6 \"pbds/TreeUpdater.cpp\"\n#include <ext/pb_ds/detail/branch_policy/branch_policy.hpp>\n\
    #include <ext/pb_ds/detail/type_utils.hpp>\n\n#define PBDS_TREE_UPDATER_TYPENAMES\
    \                                            \\\n  typename Node_CItr, typename\
    \ Node_Itr, typename Cmp_Fn, typename _Alloc\n\n#define PBDS_TREE_UPDATER_TYPES\
    \ Node_CItr, Node_Itr, Cmp_Fn, _Alloc\n\nnamespace lib {\nusing namespace std;\n\
    using namespace __gnu_pbds;\nnamespace pbds {\n\ntemplate <typename... Ts>\nstruct\
    \ TupleTraits : tuple<typename Ts::metadata_type...> {\n  using metadata_key =\
    \ tuple<Ts...>;\n};\n\ntemplate <PBDS_TREE_UPDATER_TYPENAMES, typename Enable,\n\
    \          template <typename...> class Tuple, typename... Ts>\nstruct MultiUpdaterImpl;\n\
    \ntemplate <PBDS_TREE_UPDATER_TYPENAMES, template <typename...> class Tuple,\n\
    \          typename... Ts>\nstruct MultiUpdaterImpl<PBDS_TREE_UPDATER_TYPES, traits::void_t<>,\
    \ Tuple,\n                        Ts...> {\n  using metadata_type =\n      TupleTraits<typename\
    \ Ts::template type<PBDS_TREE_UPDATER_TYPES>...>;\n};\n\ntemplate <PBDS_TREE_UPDATER_TYPENAMES,\
    \ typename... Ts>\nstruct MultiUpdaterImpl<PBDS_TREE_UPDATER_TYPES,\n        \
    \                traits::void_t<typename Node_Itr::metadata_type>, Ts...>\n  \
    \  : public Ts::template type<PBDS_TREE_UPDATER_TYPES>... {\n  using metadata_type\
    \ =\n      TupleTraits<typename Ts::template type<PBDS_TREE_UPDATER_TYPES>...>;\n\
    \n  MultiUpdaterImpl() : Ts::template type<PBDS_TREE_UPDATER_TYPES>()... {}\n\n\
    \  // const K& extract_key(Node_Itr no) const {\n  //     return this->extract_key(*(*no));\n\
    \  // }\n\n  // const K& extract_key(Node_CItr no) const {\n  //     return this->extract_key(*(*no));\n\
    \  // }\n};\n\ntemplate <typename... Ts> struct MultiUpdater {\n  template <PBDS_TREE_UPDATER_TYPENAMES>\n\
    \  using type = MultiUpdaterImpl<PBDS_TREE_UPDATER_TYPES, Ts...>;\n};\n\ntemplate\
    \ <PBDS_TREE_UPDATER_TYPENAMES> struct BaseUpdater {\n  using base_type = detail::branch_policy<Node_CItr,\
    \ Node_Itr, _Alloc>;\n  using node_iterator = Node_Itr;\n  using const_node_iterator\
    \ = Node_CItr;\n  using iterator = typename Node_Itr::value_type;\n  using const_iterator\
    \ = typename Node_CItr::value_type;\n  using cmp_fn = Cmp_Fn;\n\n  using _metadata_type\
    \ = typename Node_Itr::metadata_type;\n  using _metadata_key = typename _metadata_type::metadata_key;\n\
    \n  template <typename K>\n  tuple_element_t<traits::find_first<_metadata_key,\
    \ K>::value, _metadata_type> &\n  get_metadata_of(Node_Itr no) const {\n    return\
    \ get<traits::find_first<_metadata_key, K>::value>(no.get_metadata());\n  }\n\n\
    \  template <typename K>\n  const tuple_element_t<traits::find_first<_metadata_key,\
    \ K>::value,\n                        _metadata_type> &\n  get_metadata_of(Node_CItr\
    \ no) const {\n    return get<traits::find_first<_metadata_key, K>::value>(no.get_metadata());\n\
    \  }\n\n  const_iterator end_iterator() const { return base_type::end_iterator();\
    \ }\n\n  virtual const_node_iterator node_begin() const = 0;\n  virtual node_iterator\
    \ node_begin() = 0;\n  virtual const_node_iterator node_end() const = 0;\n  virtual\
    \ node_iterator node_end() = 0;\n\n  virtual cmp_fn &get_cmp_fn() = 0;\n};\n\n\
    template <PBDS_TREE_UPDATER_TYPENAMES>\nstruct KthOrderUpdaterImpl : BaseUpdater<PBDS_TREE_UPDATER_TYPES>\
    \ {\n  // using BaseUpdater<PBDS_TREE_UPDATER_TYPES>::get_metadata_of;\n  using\
    \ metadata_type = size_t;\n  using type = KthOrderUpdaterImpl<PBDS_TREE_UPDATER_TYPES>;\n\
    \  using node_iterator =\n      typename BaseUpdater<PBDS_TREE_UPDATER_TYPES>::node_iterator;\n\
    \  using const_node_iterator =\n      typename BaseUpdater<PBDS_TREE_UPDATER_TYPES>::const_node_iterator;\n\
    \  using const_iterator =\n      typename BaseUpdater<PBDS_TREE_UPDATER_TYPES>::const_iterator;\n\
    \n  const_iterator find_by_order(size_t order) {\n    node_iterator it = this->node_begin();\n\
    \    node_iterator end_it = this->node_end();\n    while (it != end_it) {\n  \
    \    node_iterator l_it = it.get_l_child();\n      const size_t o =\n        \
    \  (l_it == end_it) ? 0 : this->template get_metadata_of<type>(l_it);\n      if\
    \ (order == o)\n        return *it;\n      else if (order < o)\n        it = l_it;\n\
    \      else {\n        order -= o + 1;\n        it = it.get_r_child();\n     \
    \ }\n    }\n    return this->end_iterator();\n  }\n\n  void operator()(node_iterator\
    \ node_it, const_node_iterator end_nd_it) const {\n    node_iterator l_it = node_it.get_l_child();\n\
    \    const size_t l_rank =\n        (l_it == end_nd_it) ? 0 : this->template get_metadata_of<type>(l_it);\n\
    \    node_iterator r_it = node_it.get_r_child();\n    const size_t r_rank =\n\
    \        (r_it == end_nd_it) ? 0 : this->template get_metadata_of<type>(r_it);\n\
    \    (this->template get_metadata_of<type>(node_it)) = 1 + l_rank + r_rank;\n\
    \  }\n};\n\nstruct KthOrderUpdater {\n  template <PBDS_TREE_UPDATER_TYPENAMES>\n\
    \  using type = KthOrderUpdaterImpl<PBDS_TREE_UPDATER_TYPES>;\n};\n} // namespace\
    \ pbds\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_PBDS_TREE_UPDATER\n#define _LIB_PBDS_TREE_UPDATER\n#include\
    \ \"../Traits.cpp\"\n#include \"../traits/Tuple.cpp\"\n#include <bits/stdc++.h>\n\
    #include <ext/pb_ds/detail/branch_policy/branch_policy.hpp>\n#include <ext/pb_ds/detail/type_utils.hpp>\n\
    \n#define PBDS_TREE_UPDATER_TYPENAMES                                        \
    \    \\\n  typename Node_CItr, typename Node_Itr, typename Cmp_Fn, typename _Alloc\n\
    \n#define PBDS_TREE_UPDATER_TYPES Node_CItr, Node_Itr, Cmp_Fn, _Alloc\n\nnamespace\
    \ lib {\nusing namespace std;\nusing namespace __gnu_pbds;\nnamespace pbds {\n\
    \ntemplate <typename... Ts>\nstruct TupleTraits : tuple<typename Ts::metadata_type...>\
    \ {\n  using metadata_key = tuple<Ts...>;\n};\n\ntemplate <PBDS_TREE_UPDATER_TYPENAMES,\
    \ typename Enable,\n          template <typename...> class Tuple, typename...\
    \ Ts>\nstruct MultiUpdaterImpl;\n\ntemplate <PBDS_TREE_UPDATER_TYPENAMES, template\
    \ <typename...> class Tuple,\n          typename... Ts>\nstruct MultiUpdaterImpl<PBDS_TREE_UPDATER_TYPES,\
    \ traits::void_t<>, Tuple,\n                        Ts...> {\n  using metadata_type\
    \ =\n      TupleTraits<typename Ts::template type<PBDS_TREE_UPDATER_TYPES>...>;\n\
    };\n\ntemplate <PBDS_TREE_UPDATER_TYPENAMES, typename... Ts>\nstruct MultiUpdaterImpl<PBDS_TREE_UPDATER_TYPES,\n\
    \                        traits::void_t<typename Node_Itr::metadata_type>, Ts...>\n\
    \    : public Ts::template type<PBDS_TREE_UPDATER_TYPES>... {\n  using metadata_type\
    \ =\n      TupleTraits<typename Ts::template type<PBDS_TREE_UPDATER_TYPES>...>;\n\
    \n  MultiUpdaterImpl() : Ts::template type<PBDS_TREE_UPDATER_TYPES>()... {}\n\n\
    \  // const K& extract_key(Node_Itr no) const {\n  //     return this->extract_key(*(*no));\n\
    \  // }\n\n  // const K& extract_key(Node_CItr no) const {\n  //     return this->extract_key(*(*no));\n\
    \  // }\n};\n\ntemplate <typename... Ts> struct MultiUpdater {\n  template <PBDS_TREE_UPDATER_TYPENAMES>\n\
    \  using type = MultiUpdaterImpl<PBDS_TREE_UPDATER_TYPES, Ts...>;\n};\n\ntemplate\
    \ <PBDS_TREE_UPDATER_TYPENAMES> struct BaseUpdater {\n  using base_type = detail::branch_policy<Node_CItr,\
    \ Node_Itr, _Alloc>;\n  using node_iterator = Node_Itr;\n  using const_node_iterator\
    \ = Node_CItr;\n  using iterator = typename Node_Itr::value_type;\n  using const_iterator\
    \ = typename Node_CItr::value_type;\n  using cmp_fn = Cmp_Fn;\n\n  using _metadata_type\
    \ = typename Node_Itr::metadata_type;\n  using _metadata_key = typename _metadata_type::metadata_key;\n\
    \n  template <typename K>\n  tuple_element_t<traits::find_first<_metadata_key,\
    \ K>::value, _metadata_type> &\n  get_metadata_of(Node_Itr no) const {\n    return\
    \ get<traits::find_first<_metadata_key, K>::value>(no.get_metadata());\n  }\n\n\
    \  template <typename K>\n  const tuple_element_t<traits::find_first<_metadata_key,\
    \ K>::value,\n                        _metadata_type> &\n  get_metadata_of(Node_CItr\
    \ no) const {\n    return get<traits::find_first<_metadata_key, K>::value>(no.get_metadata());\n\
    \  }\n\n  const_iterator end_iterator() const { return base_type::end_iterator();\
    \ }\n\n  virtual const_node_iterator node_begin() const = 0;\n  virtual node_iterator\
    \ node_begin() = 0;\n  virtual const_node_iterator node_end() const = 0;\n  virtual\
    \ node_iterator node_end() = 0;\n\n  virtual cmp_fn &get_cmp_fn() = 0;\n};\n\n\
    template <PBDS_TREE_UPDATER_TYPENAMES>\nstruct KthOrderUpdaterImpl : BaseUpdater<PBDS_TREE_UPDATER_TYPES>\
    \ {\n  // using BaseUpdater<PBDS_TREE_UPDATER_TYPES>::get_metadata_of;\n  using\
    \ metadata_type = size_t;\n  using type = KthOrderUpdaterImpl<PBDS_TREE_UPDATER_TYPES>;\n\
    \  using node_iterator =\n      typename BaseUpdater<PBDS_TREE_UPDATER_TYPES>::node_iterator;\n\
    \  using const_node_iterator =\n      typename BaseUpdater<PBDS_TREE_UPDATER_TYPES>::const_node_iterator;\n\
    \  using const_iterator =\n      typename BaseUpdater<PBDS_TREE_UPDATER_TYPES>::const_iterator;\n\
    \n  const_iterator find_by_order(size_t order) {\n    node_iterator it = this->node_begin();\n\
    \    node_iterator end_it = this->node_end();\n    while (it != end_it) {\n  \
    \    node_iterator l_it = it.get_l_child();\n      const size_t o =\n        \
    \  (l_it == end_it) ? 0 : this->template get_metadata_of<type>(l_it);\n      if\
    \ (order == o)\n        return *it;\n      else if (order < o)\n        it = l_it;\n\
    \      else {\n        order -= o + 1;\n        it = it.get_r_child();\n     \
    \ }\n    }\n    return this->end_iterator();\n  }\n\n  void operator()(node_iterator\
    \ node_it, const_node_iterator end_nd_it) const {\n    node_iterator l_it = node_it.get_l_child();\n\
    \    const size_t l_rank =\n        (l_it == end_nd_it) ? 0 : this->template get_metadata_of<type>(l_it);\n\
    \    node_iterator r_it = node_it.get_r_child();\n    const size_t r_rank =\n\
    \        (r_it == end_nd_it) ? 0 : this->template get_metadata_of<type>(r_it);\n\
    \    (this->template get_metadata_of<type>(node_it)) = 1 + l_rank + r_rank;\n\
    \  }\n};\n\nstruct KthOrderUpdater {\n  template <PBDS_TREE_UPDATER_TYPENAMES>\n\
    \  using type = KthOrderUpdaterImpl<PBDS_TREE_UPDATER_TYPES>;\n};\n} // namespace\
    \ pbds\n} // namespace lib\n\n#endif"
  dependsOn:
  - Traits.cpp
  - bits/stdc++.h
  - traits/Tuple.cpp
  isVerificationFile: false
  path: pbds/TreeUpdater.cpp
  requiredBy: []
  timestamp: '2023-02-27 10:03:35-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: pbds/TreeUpdater.cpp
layout: document
redirect_from:
- /library/pbds/TreeUpdater.cpp
- /library/pbds/TreeUpdater.cpp.html
title: pbds/TreeUpdater.cpp
---
