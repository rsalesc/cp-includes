---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: FHT.cpp
    title: FHT.cpp
  - icon: ':heavy_check_mark:'
    path: Graph.cpp
    title: Graph.cpp
  - icon: ':warning:'
    path: HLD.cpp
    title: HLD.cpp
  - icon: ':warning:'
    path: Lambda.cpp
    title: Lambda.cpp
  - icon: ':heavy_check_mark:'
    path: LinearRecurrence.cpp
    title: LinearRecurrence.cpp
  - icon: ':warning:'
    path: Maxflow.cpp
    title: Maxflow.cpp
  - icon: ':heavy_check_mark:'
    path: NTT.cpp
    title: NTT.cpp
  - icon: ':heavy_check_mark:'
    path: PolynomialRing.cpp
    title: PolynomialRing.cpp
  - icon: ':heavy_check_mark:'
    path: PowerSeries.cpp
    title: PowerSeries.cpp
  - icon: ':warning:'
    path: RollingHash.cpp
    title: RollingHash.cpp
  - icon: ':warning:'
    path: SegtreeHLD.cpp
    title: SegtreeHLD.cpp
  - icon: ':heavy_check_mark:'
    path: TwoSat.cpp
    title: TwoSat.cpp
  - icon: ':heavy_check_mark:'
    path: VectorN.cpp
    title: VectorN.cpp
  - icon: ':warning:'
    path: matroid/CographicMatroid.cpp
    title: matroid/CographicMatroid.cpp
  - icon: ':warning:'
    path: matroid/ColorMatroid.cpp
    title: matroid/ColorMatroid.cpp
  - icon: ':warning:'
    path: matroid/Compose.cpp
    title: matroid/Compose.cpp
  - icon: ':warning:'
    path: matroid/GraphicMatroid.cpp
    title: matroid/GraphicMatroid.cpp
  - icon: ':warning:'
    path: matroid/Matroid.cpp
    title: matroid/Matroid.cpp
  - icon: ':warning:'
    path: matroid/MatroidIntersection.cpp
    title: matroid/MatroidIntersection.cpp
  - icon: ':warning:'
    path: matroid/v2/BinaryMatroid.cpp
    title: matroid/v2/BinaryMatroid.cpp
  - icon: ':warning:'
    path: matroid/v2/ColorMatroid.cpp
    title: matroid/v2/ColorMatroid.cpp
  - icon: ':warning:'
    path: matroid/v2/ContractionMatroid.cpp
    title: matroid/v2/ContractionMatroid.cpp
  - icon: ':warning:'
    path: matroid/v2/EdgeFinder.cpp
    title: matroid/v2/EdgeFinder.cpp
  - icon: ':warning:'
    path: matroid/v2/GraphicMatroid.cpp
    title: matroid/v2/GraphicMatroid.cpp
  - icon: ':warning:'
    path: matroid/v2/Matroid.cpp
    title: matroid/v2/Matroid.cpp
  - icon: ':warning:'
    path: matroid/v2/MatroidIntersection.cpp
    title: matroid/v2/MatroidIntersection.cpp
  - icon: ':warning:'
    path: pbds/TreeUpdater.cpp
    title: pbds/TreeUpdater.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/MultipointEvaluation.cpp
    title: polynomial/MultipointEvaluation.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/MultipointEvaluation.cpp
    title: polynomial/MultipointEvaluation.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/2sat.test.cpp
    title: tests/yosupo/2sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/fht-convolution.test.cpp
    title: tests/yosupo/fht-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/find-lr.test.cpp
    title: tests/yosupo/find-lr.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/fps-inv.test.cpp
    title: tests/yosupo/fps-inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/fps-power.test.cpp
    title: tests/yosupo/fps-power.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/kth-term-lr.test.cpp
    title: tests/yosupo/kth-term-lr.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/multipoint.test.cpp
    title: tests/yosupo/multipoint.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/multipoint.test.cpp
    title: tests/yosupo/multipoint.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/subset-sum.test.cpp
    title: tests/yosupo/subset-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Traits.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace traits {\n\ntemplate <typename...> struct\
    \ make_void { using type = void; };\n\ntemplate <typename... T> using void_t =\
    \ typename make_void<T...>::type;\n\n/// keep caide\ntemplate <typename Iterator>\n\
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
    } // namespace traits\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_TRAITS\n#define _LIB_TRAITS\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace traits {\n\ntemplate <typename...> struct\
    \ make_void { using type = void; };\n\ntemplate <typename... T> using void_t =\
    \ typename make_void<T...>::type;\n\n/// keep caide\ntemplate <typename Iterator>\n\
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
    } // namespace traits\n} // namespace lib\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: Traits.cpp
  requiredBy:
  - PolynomialRing.cpp
  - RollingHash.cpp
  - LinearRecurrence.cpp
  - SegtreeHLD.cpp
  - Maxflow.cpp
  - polynomial/MultipointEvaluation.cpp
  - polynomial/MultipointEvaluation.cpp
  - HLD.cpp
  - TwoSat.cpp
  - PowerSeries.cpp
  - matroid/v2/EdgeFinder.cpp
  - matroid/v2/ContractionMatroid.cpp
  - matroid/v2/GraphicMatroid.cpp
  - matroid/v2/ColorMatroid.cpp
  - matroid/v2/Matroid.cpp
  - matroid/v2/MatroidIntersection.cpp
  - matroid/v2/BinaryMatroid.cpp
  - matroid/GraphicMatroid.cpp
  - matroid/ColorMatroid.cpp
  - matroid/Compose.cpp
  - matroid/Matroid.cpp
  - matroid/CographicMatroid.cpp
  - matroid/MatroidIntersection.cpp
  - Lambda.cpp
  - FHT.cpp
  - Graph.cpp
  - VectorN.cpp
  - pbds/TreeUpdater.cpp
  - NTT.cpp
  timestamp: '2021-01-26 16:28:00-03:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/fps-power.test.cpp
  - tests/yosupo/fht-convolution.test.cpp
  - tests/yosupo/subset-sum.test.cpp
  - tests/yosupo/multipoint.test.cpp
  - tests/yosupo/multipoint.test.cpp
  - tests/yosupo/kth-term-lr.test.cpp
  - tests/yosupo/fps-inv.test.cpp
  - tests/yosupo/2sat.test.cpp
  - tests/yosupo/find-lr.test.cpp
documentation_of: Traits.cpp
layout: document
redirect_from:
- /library/Traits.cpp
- /library/Traits.cpp.html
title: Traits.cpp
---
