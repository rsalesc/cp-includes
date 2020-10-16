#ifndef _LIB_TRAITS
#define _LIB_TRAITS
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace traits {

template <typename...> struct make_void { using type = void; };

template <typename... T> using void_t = typename make_void<T...>::type;

/// keep caide
template <typename Iterator>
using IteratorCategory = typename iterator_traits<Iterator>::iterator_category;

/// keep caide
template <typename Container>
using IteratorCategoryOf = IteratorCategory<typename Container::iterator>;

/// keep caide
template <typename Iterator>
using IsRandomIterator =
    is_base_of<random_access_iterator_tag, IteratorCategory<Iterator>>;

/// keep caide
template <typename Iterator>
using IsInputIterator =
    is_base_of<input_iterator_tag, IteratorCategory<Iterator>>;

/// keep caide
template <typename Iterator>
using IsBidirectionalIterator =
    is_base_of<bidirectional_iterator_tag, IteratorCategory<Iterator>>;

/// keep caide
template <typename Container>
using HasRandomIterator =
    is_base_of<random_access_iterator_tag, IteratorCategoryOf<Container>>;

/// keep caide
template <typename Container>
using HasInputIterator =
    is_base_of<input_iterator_tag, IteratorCategoryOf<Container>>;

/// keep caide
template <typename Container>
using HasBidirectionalIterator =
    is_base_of<bidirectional_iterator_tag, IteratorCategoryOf<Container>>;
} // namespace traits
} // namespace lib

#endif
