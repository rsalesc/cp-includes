---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: FHT.cpp
    title: FHT.cpp
  - icon: ':warning:'
    path: Graph.cpp
    title: Graph.cpp
  - icon: ':warning:'
    path: HLD.cpp
    title: HLD.cpp
  - icon: ':warning:'
    path: Lambda.cpp
    title: Lambda.cpp
  - icon: ':warning:'
    path: LinearRecurrence.cpp
    title: LinearRecurrence.cpp
  - icon: ':warning:'
    path: Maxflow.cpp
    title: Maxflow.cpp
  - icon: ':warning:'
    path: NTT.cpp
    title: NTT.cpp
  - icon: ':warning:'
    path: PolynomialRing.cpp
    title: PolynomialRing.cpp
  - icon: ':warning:'
    path: PowerSeries.cpp
    title: PowerSeries.cpp
  - icon: ':warning:'
    path: RollingHash.cpp
    title: RollingHash.cpp
  - icon: ':warning:'
    path: SegtreeHLD.cpp
    title: SegtreeHLD.cpp
  - icon: ':warning:'
    path: TwoSat.cpp
    title: TwoSat.cpp
  - icon: ':warning:'
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
  - icon: ':warning:'
    path: polynomial/MultipointEvaluation.cpp
    title: polynomial/MultipointEvaluation.cpp
  - icon: ':warning:'
    path: polynomial/MultipointEvaluation.cpp
    title: polynomial/MultipointEvaluation.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
  - SegtreeHLD.cpp
  - PowerSeries.cpp
  - TwoSat.cpp
  - pbds/TreeUpdater.cpp
  - Lambda.cpp
  - LinearRecurrence.cpp
  - PolynomialRing.cpp
  - FHT.cpp
  - matroid/Matroid.cpp
  - matroid/GraphicMatroid.cpp
  - matroid/Compose.cpp
  - matroid/MatroidIntersection.cpp
  - matroid/ColorMatroid.cpp
  - matroid/CographicMatroid.cpp
  - matroid/v2/EdgeFinder.cpp
  - matroid/v2/Matroid.cpp
  - matroid/v2/GraphicMatroid.cpp
  - matroid/v2/ContractionMatroid.cpp
  - matroid/v2/MatroidIntersection.cpp
  - matroid/v2/ColorMatroid.cpp
  - matroid/v2/BinaryMatroid.cpp
  - RollingHash.cpp
  - Maxflow.cpp
  - VectorN.cpp
  - HLD.cpp
  - NTT.cpp
  - polynomial/MultipointEvaluation.cpp
  - polynomial/MultipointEvaluation.cpp
  - Graph.cpp
  timestamp: '2021-01-26 16:28:00-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Traits.cpp
layout: document
redirect_from:
- /library/Traits.cpp
- /library/Traits.cpp.html
title: Traits.cpp
---
