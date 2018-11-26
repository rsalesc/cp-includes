#include <bits/stdc++.h>
#include "../../SegtreeNormal.cpp"
using namespace std;

///////////////////////////////////////////// BEGIN OF MERGE SORT TREE ///////////////////////////////////////////
namespace {
    using namespace std;

    namespace seg {
        template<typename T>
        struct MergeCombiner {
            vector<T> operator()(const vector<T>&x, const vector<T>& y) {
                vector<T> result(x.size() + y.size());
                merge(x.begin(), x.end(), y.begin(), y.end(), result.begin());
                return result;
            }
        };
    }

    template<typename T>
    vector<vector<T>> to_singleton_vectors(const vector<T>& vec) {
        const size_t n = vec.size();
        vector<vector<T>> result(n);
        for (size_t i = 0; i < n; ++i)
            result[i].push_back(vec[i]);
        return result;
    }

    template<typename T>
    struct MergeSortTree {
        vector<T> sorted_vec;
        lib::seg::SegtreeNormal<vector<T>, seg::MergeCombiner<T>> segtree;
        explicit MergeSortTree(const vector<T>& vec)
            : sorted_vec(vec)
            , segtree(lib::seg::make_builder(to_singleton_vectors(vec)))
        {
            sort(sorted_vec.begin(), sorted_vec.end());
            sorted_vec.resize(unique(sorted_vec.begin(), sorted_vec.end()) - sorted_vec.begin());
        }

        struct Folder {
          const T x;
          explicit Folder(const T x) : x(x) {}

          size_t operator()(const vector<T>& node) const {
            return upper_bound(node.begin(), node.end(), x) - node.begin();
          }

          size_t operator()(const size_t a, const size_t b) const {
            return a + b;
          }
        };

        // Complexity: O(log^2 n)
        int count_lte(const int l, const int r, const T x) {
          return segtree.template query<size_t>(l, r, Folder(x));
        }

        // Complexity: O(log^2 n)
        int count_lt(const int l, const int r, const T x) {
            struct Folder {
                const T x;
                explicit Folder(const T x) : x(x) {}

                size_t operator()(const vector<T>& node) const {
                    return lower_bound(node.begin(), node.end(), x) - node.begin();
                }

                size_t operator()(const size_t a, const size_t b) const {
                    return a + b;
                }
            };

            return segtree.template query<size_t>(l, r, Folder(x));
        }

        // Complexity: O(log^2 n)
        int count_gte(const int l, const int r, const T x) {
            struct Folder {
                const T x;
                explicit Folder(const T x) : x(x) {}

                size_t operator()(const vector<T>& node) const {
                    return node.end() - lower_bound(node.begin(), node.end(), x);
                }

                size_t operator()(const size_t a, const size_t b) const {
                    return a + b;
                }
            };

            return segtree.template query<size_t>(l, r, Folder(x));
        }

        // Complexity: O(log^2 n)
        int count_gt(const int l, const int r, const T x) {
            struct Folder {
                const T x;
                explicit Folder(const T x) : x(x) {}

                size_t operator()(const vector<T>& node) const {
                    return node.end() - upper_bound(node.begin(), node.end(), x);
                }

                size_t operator()(const size_t a, const size_t b) const {
                    return a + b;
                }
            };

            return segtree.template query<size_t>(l, r, Folder(x));
        }

        typedef typename decltype(segtree)::vnode vnode;
        const T find_kth(vnode no, int l, int r, int i, int j, int k) {
          if(l == r) return segtree.manager.ref(no)[0];
          auto x = segtree.manager.ref(no)[k - 1];
          auto& left_value = segtree.manager.ref(segtree.manager.left(no));
          int mid = segtree.split(l, r);
          if(left_value.back() <= x)
            return find_kth(segtree.manager.left(no), l, mid, i, j, k);
          else {
            return find_kth(segtree.manager.right(no), mid+1, r, i, j,
                            k - (int)left_value.size());
          }
        }

        // Note: k is 1-indexed
        const T find_kth(const int i, const int j, const int k) {
            if (k < 1 || k > j-i+1) {
                return -1;
            }
            return find_kth(segtree.root(), segtree.L, segtree.R, i, j, k);
        }
    };
}
///////////////////////////////////////////// END OF MERGE SORT TREE ///////////////////////////////////////////

int32_t main() {
    int n, m;
    cin>>n>>m;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
        cin>>vec[i];
    MergeSortTree<int> mst(vec);
    for (int i = 0; i < m; ++i) {
        int l, r, k;
        cin>>l>>r>>k;
        --l;
        --r;
        const int result = mst.find_kth(l, r, k);
        assert(result != -1);
        cout << vec[result] << endl;
    }
}
