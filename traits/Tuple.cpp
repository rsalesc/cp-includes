#ifndef _LIB_TRAITS_TUPLE
#define _LIB_TRAITS_TUPLE
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace traits {
    template <class Tuple, class T, std::size_t Index = 0>
    struct find_first;

    template <std::size_t Index, bool Valid>
    struct find_first_final_test
        : public std::integral_constant<std::size_t, Index>
    {
    };

    template <std::size_t Index>
    struct find_first_final_test<Index, false>
    {
        static_assert(Index == -1, "Type not found in find_first");
    };

    template <class Head, class T, std::size_t Index>
    struct find_first<std::tuple<Head>, T, Index>
        : public find_first_final_test<Index, std::is_same<Head, T>::value>
    {
    };

    template <class Head, class ...Rest, class T, std::size_t Index>
    struct find_first<std::tuple<Head, Rest...>, T, Index>
        : public std::conditional<std::is_same<Head, T>::value,
                        std::integral_constant<std::size_t, Index>,
                        find_first<std::tuple<Rest...>, T, Index+1>>::type
    {
    };
}
}

#endif