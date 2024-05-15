#ifndef _LIB_TRAITS_OPERATORS
#define _LIB_TRAITS_OPERATORS
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace traits {
// false case
template <typename T, typename = void>
struct has_add_operator : std::false_type {};

// partial specialization
template <typename T>
struct has_add_operator<T, std::void_t<decltype((std::declval<T>() + std::declval<T>()))>> : std::true_type {};
} // namespace traits
} // namespace lib

#endif