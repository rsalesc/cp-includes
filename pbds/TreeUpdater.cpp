#ifndef _LIB_PBDS_TREE_UPDATER
#define _LIB_PBDS_TREE_UPDATER
#include <bits/stdc++.h>
#include <ext/pb_ds/detail/type_utils.hpp>
#include <ext/pb_ds/detail/branch_policy/branch_policy.hpp>
#include "../traits/Tuple.cpp"
#include "../Traits.cpp"

#define PBDS_TREE_UPDATER_TYPENAMES \
    typename Node_CItr, typename Node_Itr, typename Cmp_Fn, \
    typename _Alloc

#define PBDS_TREE_UPDATER_TYPES \
    Node_CItr, Node_Itr, Cmp_Fn, _Alloc


namespace lib {
  using namespace std;
  using namespace __gnu_pbds;
namespace pbds {

    template<typename ...Ts>
    struct TupleTraits : tuple<typename Ts::metadata_type...> {
        using metadata_key = tuple<Ts...>;
    };

    template<PBDS_TREE_UPDATER_TYPENAMES, typename Enable, template <typename...> class Tuple, typename ...Ts>
    struct MultiUpdaterImpl;

    template<PBDS_TREE_UPDATER_TYPENAMES, template<typename...> class Tuple, typename ...Ts>
    struct MultiUpdaterImpl<PBDS_TREE_UPDATER_TYPES, traits::void_t<>, Tuple, Ts...> {
        using metadata_type = TupleTraits<typename Ts::template type<PBDS_TREE_UPDATER_TYPES>...>;
    };

    template<PBDS_TREE_UPDATER_TYPENAMES, typename ...Ts>
    struct MultiUpdaterImpl<PBDS_TREE_UPDATER_TYPES, traits::void_t<typename Node_Itr::metadata_type>, Ts...>
     : public Ts::template type<PBDS_TREE_UPDATER_TYPES>... {
        using metadata_type = TupleTraits<typename Ts::template type<PBDS_TREE_UPDATER_TYPES>...>;

        MultiUpdaterImpl() : Ts::template type<PBDS_TREE_UPDATER_TYPES>()... {}

        // const K& extract_key(Node_Itr no) const {
        //     return this->extract_key(*(*no));
        // }

        // const K& extract_key(Node_CItr no) const {
        //     return this->extract_key(*(*no));
        // }
    };

    template<typename ...Ts>
    struct MultiUpdater {
        template<PBDS_TREE_UPDATER_TYPENAMES>
        using type = MultiUpdaterImpl<PBDS_TREE_UPDATER_TYPES, Ts...>;
    };

    template<PBDS_TREE_UPDATER_TYPENAMES>
    struct BaseUpdater {
        using base_type = detail::branch_policy<Node_CItr, Node_Itr, _Alloc>;
        using node_iterator = Node_Itr;
        using const_node_iterator = Node_CItr;
        using iterator = typename Node_Itr::value_type;
        using const_iterator = typename Node_CItr::value_type;
        using cmp_fn = Cmp_Fn;

        using _metadata_type = typename Node_Itr::metadata_type;
        using _metadata_key = typename _metadata_type::metadata_key;

        template<typename K>
        tuple_element_t<traits::find_first<_metadata_key, K>::value, _metadata_type>& get_metadata_of(Node_Itr no) const {
            return get<traits::find_first<_metadata_key, K>::value>(no.get_metadata());
        }

        template<typename K>
        const tuple_element_t<traits::find_first<_metadata_key, K>::value, _metadata_type>& get_metadata_of(Node_CItr no) const {
            return get<traits::find_first<_metadata_key, K>::value>(no.get_metadata());
        }

        const_iterator end_iterator() const {
            return base_type::end_iterator();
        }

        virtual const_node_iterator
        node_begin() const = 0;
        virtual node_iterator
        node_begin() = 0;
        virtual const_node_iterator
        node_end() const = 0;
        virtual node_iterator
        node_end() = 0;

        virtual cmp_fn& 
        get_cmp_fn() = 0;
    };

    template<PBDS_TREE_UPDATER_TYPENAMES>
    struct KthOrderUpdaterImpl : BaseUpdater<PBDS_TREE_UPDATER_TYPES> {
        // using BaseUpdater<PBDS_TREE_UPDATER_TYPES>::get_metadata_of;
        using metadata_type = size_t;
        using type = KthOrderUpdaterImpl<PBDS_TREE_UPDATER_TYPES>;
        using node_iterator = typename BaseUpdater<PBDS_TREE_UPDATER_TYPES>::node_iterator;
        using const_node_iterator = typename BaseUpdater<PBDS_TREE_UPDATER_TYPES>::const_node_iterator;
        using const_iterator = typename BaseUpdater<PBDS_TREE_UPDATER_TYPES>::const_iterator;

        const_iterator find_by_order(size_t order) {
            node_iterator it = this->node_begin();
            node_iterator end_it = this->node_end();
            while (it != end_it) {
                node_iterator l_it = it.get_l_child();
                const size_t o = (l_it == end_it)? 0 : this->template get_metadata_of<type>(l_it);
                if (order == o)
                    return *it;
                else if (order < o)
                    it = l_it;
                else {
                    order -= o + 1;
                    it = it.get_r_child();
                }
            }
            return this->end_iterator();
        }

        void operator()(node_iterator node_it, const_node_iterator end_nd_it) const {
            node_iterator l_it = node_it.get_l_child();
            const size_t l_rank = (l_it == end_nd_it) ? 0 : this->template get_metadata_of<type>(l_it);
            node_iterator r_it = node_it.get_r_child();
            const size_t r_rank = (r_it == end_nd_it) ? 0 : this->template get_metadata_of<type>(r_it);
            (this->template get_metadata_of<type>(node_it)) = 1 + l_rank + r_rank;
        }
    };

    struct KthOrderUpdater {
        template<PBDS_TREE_UPDATER_TYPENAMES>
        using type = KthOrderUpdaterImpl<PBDS_TREE_UPDATER_TYPES>;
    };
}
}

#endif