---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: pbds/TreeUpdater.cpp
    title: pbds/TreeUpdater.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"traits/Tuple.cpp\"\n\n\n#include <bits/stdc++.h>\n\nnamespace\
    \ lib {\nusing namespace std;\nnamespace traits {\ntemplate <class Tuple, class\
    \ T, std::size_t Index = 0> struct find_first;\n\ntemplate <std::size_t Index,\
    \ bool Valid>\nstruct find_first_final_test\n    : public std::integral_constant<std::size_t,\
    \ Index> {};\n\ntemplate <std::size_t Index> struct find_first_final_test<Index,\
    \ false> {\n  static_assert(Index == -1, \"Type not found in find_first\");\n\
    };\n\ntemplate <class Head, class T, std::size_t Index>\nstruct find_first<std::tuple<Head>,\
    \ T, Index>\n    : public find_first_final_test<Index, std::is_same<Head, T>::value>\
    \ {};\n\ntemplate <class Head, class... Rest, class T, std::size_t Index>\nstruct\
    \ find_first<std::tuple<Head, Rest...>, T, Index>\n    : public std::conditional<\n\
    \          std::is_same<Head, T>::value,\n          std::integral_constant<std::size_t,\
    \ Index>,\n          find_first<std::tuple<Rest...>, T, Index + 1>>::type {};\n\
    } // namespace traits\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_TRAITS_TUPLE\n#define _LIB_TRAITS_TUPLE\n#include <bits/stdc++.h>\n\
    \nnamespace lib {\nusing namespace std;\nnamespace traits {\ntemplate <class Tuple,\
    \ class T, std::size_t Index = 0> struct find_first;\n\ntemplate <std::size_t\
    \ Index, bool Valid>\nstruct find_first_final_test\n    : public std::integral_constant<std::size_t,\
    \ Index> {};\n\ntemplate <std::size_t Index> struct find_first_final_test<Index,\
    \ false> {\n  static_assert(Index == -1, \"Type not found in find_first\");\n\
    };\n\ntemplate <class Head, class T, std::size_t Index>\nstruct find_first<std::tuple<Head>,\
    \ T, Index>\n    : public find_first_final_test<Index, std::is_same<Head, T>::value>\
    \ {};\n\ntemplate <class Head, class... Rest, class T, std::size_t Index>\nstruct\
    \ find_first<std::tuple<Head, Rest...>, T, Index>\n    : public std::conditional<\n\
    \          std::is_same<Head, T>::value,\n          std::integral_constant<std::size_t,\
    \ Index>,\n          find_first<std::tuple<Rest...>, T, Index + 1>>::type {};\n\
    } // namespace traits\n} // namespace lib\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: traits/Tuple.cpp
  requiredBy:
  - pbds/TreeUpdater.cpp
  timestamp: '2020-10-15 12:03:07-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: traits/Tuple.cpp
layout: document
redirect_from:
- /library/traits/Tuple.cpp
- /library/traits/Tuple.cpp.html
title: traits/Tuple.cpp
---
