#ifndef _LIB_LAGRANGE
#define _LIB_LAGRANGE
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace linalg {
  template<typename Field>
  struct PrefixLagrange {
    vector<Field> fat, ifat, pref, suf;
    PrefixLagrange() {
      fat = {1};
      ifat = {1};
    }

    void ensure(int n) {
      int o = fat.size();
      if(n + 1 <= o) return;
      fat.resize(n + 1), ifat.resize(n + 1);
      pref.resize(n + 5), suf.resize(n + 5);

      for(int i = o; i <= n; i++)
        fat[i] = fat[i-1] * i;

      ifat.back() = Field(1) / fat.back();
      for(int i = n-1; i >= o; i--)
        ifat[i] = ifat[i + 1] * (i + 1);
    }

    template<typename T>
    Field eval(const vector<Field>& v, T x) {
      assert(!v.empty());
      int d = (int)v.size() - 1;
      if(x <= d) return v[x];

      ensure(d + 1);

      pref[0] = suf[d] = 1;
      for(int i = 0; i < d; i++)
        pref[i + 1] = pref[i] * (x - i);
      for(int i = d; i; i--)
        suf[i - 1] = suf[i] * (x - i);

      Field ans = 0;
      for(int i = 0; i <= d; i++) {
        Field l = pref[i] * suf[i] * ifat[i] * ifat[d-i];
        if((d+i)&1) l = -l;
        ans += l * v[i];
      }
      return ans;
    }
  };
}  // namespace linalg
}  // namespace lib

#endif
