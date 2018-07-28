#ifndef _LIB_TRAITS
#define _LIB_TRAITS
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace traits {

  template<typename Iterator>
  using IteratorCategory =
    typename iterator_traits<Iterator>::iterator_category;

  template<typename Container>
  using IteratorCategoryOf = IteratorCategory<typename Container::iterator>;

  template<typename Iterator>
  using IsRandomIterator =
    is_base_of<random_access_iterator_tag, IteratorCategory<Iterator>>;

  template<typename Iterator>
  using IsInputIterator =
    is_base_of<input_iterator_tag, IteratorCategory<Iterator>>;

  template<typename Iterator>
  using IsBidirectionalIterator =
    is_base_of<bidirectional_iterator_tag, IteratorCategory<Iterator>>;

  template<typename Container>
  using HasRandomIterator =
    is_base_of<random_access_iterator_tag, IteratorCategoryOf<Container>>;

  template<typename Container>
  using HasInputIterator =
    is_base_of<input_iterator_tag, IteratorCategoryOf<Container>>;

  template<typename Container>
  using HasBidirectionalIterator =
    is_base_of<bidirectional_iterator_tag, IteratorCategoryOf<Container>>;
}
}

#endif
