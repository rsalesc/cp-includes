#ifndef _LIB_SUFFIX_ARRAY
#define _LIB_SUFFIX_ARRAY
#include <bits/stdc++.h>

namespace lib {
using namespace std;
template<typename C>
struct SuffixArray {
  int n, block;
  vector<C> s;
  vector<int> sa, rnk, tmp, aux, lcp_;
  vector<vector<int>> T;

  void init(int h) {
    h = max(h, n);
    sa = vector<int>(h+3), rnk = vector<int>(h+3),
      tmp = vector<int>(h+3), aux = vector<int>(h+3),
      lcp_ = vector<int>(h+3);
    T = vector<vector<int>>(n + 3, vector<int>(__lg(n) + 1));
  }

  SuffixArray(vector<C> s_) : s(s_), n(s_.size()) { build(); }
  SuffixArray(string s_) {
    s = vector<C>(s_.size());
    n = s_.size();
    for(int i = 0; i < n; i++) s[i] = s_[i];
    build();
  }

  bool suffix_cmp(int i, int j) {
    if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
    i += block, j += block;
    if (i >= n) i -= n;
    if (j >= n) j -= n;
    return rnk[i] < rnk[j];
  }
  void suffix_sort(int h) {
    for (int i = 0; i < n; i++) {
      aux[i] = sa[i] - block;
      if (aux[i] < 0) aux[i] += n;
    }
    for (int i = 0; i < h; i++) tmp[i] = 0;
    for (int i = 0; i < n; i++) tmp[rnk[aux[i]]]++;
    for (int i = 0; i < h - 1; i++) tmp[i + 1] += tmp[i];
    for (int i = n - 1; i >= 0; i--) sa[--tmp[rnk[aux[i]]]] = aux[i];
    tmp[0] = 0;
    for (int i = 0; i < n - 1; i++) tmp[i + 1] = tmp[i] + suffix_cmp(sa[i], sa[i + 1]);
    for (int i = 0; i < n; i++) rnk[sa[i]] = tmp[i];
  }
  void build() {
    n++; // consider additional '\0' character
    s.push_back(0);
    int h = (int)(*max_element(s.begin(), s.end())) + 1;
    init(h);
    for (int i = 0; i < n; i++) sa[i] = i, rnk[i] = s[i], tmp[i] = 0;
    block = 0;
    suffix_sort(h);
    for (block = 1; tmp[n - 1] != n - 1; block *= 2) suffix_sort(tmp[n - 1] + 1);
    n--;
    sa.erase(sa.begin());
    build_lcp_();
  }

  void build_lcp_() {
		for (int i = 0; i < n; i++) rnk[sa[i]] = i, lcp_[i] = 0;
		int last = 0; // last lcp_
		for (int i = 0; i < n; i++, last = max(lcp_[rnk[i - 1]] - 1, 0)) {
			if (rnk[i] == n - 1) continue;
			int j = sa[rnk[i] + 1]; // next suffix pos in suffix array
			while (i + last < n && j + last < n && s[i + last] == s[j + last]) last++;
			lcp_[rnk[i]] = last;
		}

		for(int i = 0; i < n; i++)
			T[i][0] = lcp_[i];
		for(int j = 1; j < 20; j++){
			for(int i = 0; i+(1<<j) <= n; i++){
				T[i][j] = min(T[i][j-1], T[i+(1<<(j-1))][j-1]);
			}
		}
	}

  int lcp(int i, int j){
		if(i > j) swap(i,j);
		if(i == j) return n-sa[i];
    if(j == n) return 0;

		j--;
		int k = __builtin_clz(1) - __builtin_clz(j-i+1);
		return min(T[i][k], T[j-(1<<k)+1][k]);
	}

  int operator[](int i) const {
    return sa[i];
  }

  int length(int i) const {
    return n - sa[i];
  }

  int lcp(int i) const {
    return lcp_[i];
  }

  pair<int,int> range(int i, int sz){
    pair<int, int> res;
    {
      int l = 0, r = i+1;
      while(l < r){
        int mid = (l+r)/2;
        if(lcp(mid, i) >= sz) r = mid;
        else l = mid+1;
      }
      res.first = l;
    }
    {
      int l = i, r = n-1;
      while(l < r){
        int mid = (l+r+1)/2;
        if(lcp(mid, i) >= sz) l = mid;
        else r = mid-1;
      }
      res.second = l;
    }
    return res;
  }

  pair<int, int> range(int i) {
    return range(i, length(i));
  }
};
} // namespace lib

#endif
