#ifndef _LIB_POLYNOMIAL_MULTIPOINT_EVALUATION
#define _LIB_POLYNOMIAL_MULTIPOINT_EVALUATION
#include <bits/stdc++.h>
#include "../PolynomialRing.cpp"
#include "../Traits.cpp"

namespace lib {
  using namespace std;
namespace math {
    namespace {
        /// keep caide
        using traits::IsInputIterator;
        /// keep caide
        using traits::HasInputIterator;
    
    } 
    template<typename Poly>
    struct MultipointEvaluation {
        using field = typename Poly::field;
        vector<field> w, fw;
        vector<vector<Poly>> sub;

        template<
            typename Iterator,
            typename enable_if<IsInputIterator<Iterator>::value>::type* = nullptr>
        MultipointEvaluation(Iterator begin, Iterator end) : w(distance(begin, end)) {
            int i = 0;
            for(auto it = begin; it != end; ++it, ++i)
                w[i] = *it;
            build();
        }

        template<
            typename Container,
            typename enable_if<HasInputIterator<Container>::value>::type* = nullptr>
        MultipointEvaluation(const Container& container) 
            : MultipointEvaluation(container.begin(), container.end()) {}

        void build() {
            if(w.size() <= 1) return;
            sub.emplace_back();
            for(const auto& wi : w) {
                sub.back().push_back(Poly::from_root(wi));
            }

            while(sub.back().size() > 2) {
                sub.emplace_back();
                vector<Poly>& nxt = sub.back();
                vector<Poly>& old = sub[(int)sub.size() - 2];
                for(int i = 0; 2*i < old.size(); i++) {
                    if(2*i+1 >= old.size())
                        nxt.push_back(old[2*i]);
                    else nxt.push_back(old[2*i] * old[2*i+1]);
                }
            }
        }

        void dc(const Poly& p, int L, int i) {
            if(L == 0) {
                fw[i] = p[0];
                return;
            }
            dc(p % sub[L-1][2*i], L-1, 2*i);
            if(2*i+1 < sub[L-1].size())
                dc(p % sub[L-1][2*i+1], L-1, 2*i+1);
        }

        vector<field> eval(const Poly& p) {
            if(w.size() <= 1) {
                vector<field> res(w.size());
                for(int i = 0; i < w.size(); i++)
                    res[i] = p(w[i]);
                return res;
            }
            fw = vector<field>(w.size());
            dc(p, sub.size(), 0);
            return fw;
        }
    };
}  // namespace math
}  // namespace lib

#endif
