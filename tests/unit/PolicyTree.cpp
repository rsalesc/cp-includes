#include "../catch.hpp"
#include "../../pbds/TreeUpdater.cpp"

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace lib::pbds;
using namespace __gnu_pbds;

TEST_CASE("tree builds") {
    using Updater = MultiUpdater<KthOrderUpdater>;
    tree<
        int,
        null_type,
        std::less<int>,
        rb_tree_tag,
        Updater::type> ordered_set;

        ordered_set.insert(3);
        ordered_set.insert(1);
        ordered_set.insert(5);
        REQUIRE( *ordered_set.find_by_order(1) == 3 );
}