---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tests/judge/lagrange.pre.cpp\"\n#include <bits/stdc++.h>\n\
    #ifndef _LIB_LAGRANGE\n#define _LIB_LAGRANGE\n#line 5 \"tests/judge/lagrange.pre.cpp\"\
    \n\nnamespace lib {\n  using namespace std;\nnamespace linalg {\n  template<typename\
    \ Field>\n  struct PrefixLagrange {\n    vector<Field> fat, ifat, pref, suf;\n\
    \    PrefixLagrange() {\n      fat = {1};\n      ifat = {1};\n    }\n\n    void\
    \ ensure(int n) {\n      int o = fat.size();\n      if(n + 1 <= o) return;\n \
    \     fat.resize(n + 1), ifat.resize(n + 1);\n      pref.resize(n + 5), suf.resize(n\
    \ + 5);\n\n      for(int i = o; i <= n; i++)\n        fat[i] = fat[i-1] * i;\n\
    \n      ifat.back() = Field(1) / fat.back();\n      for(int i = n-1; i >= o; i--)\n\
    \        ifat[i] = ifat[i + 1] * (i + 1);\n    }\n\n    template<typename T>\n\
    \    Field eval(const vector<Field>& v, T x) {\n      assert(!v.empty());\n  \
    \    int d = (int)v.size() - 1;\n      if(x <= d) return v[x];\n\n      ensure(d\
    \ + 1);\n\n      pref[0] = suf[d] = 1;\n      for(int i = 0; i < d; i++)\n   \
    \     pref[i + 1] = pref[i] * (x - i);\n      for(int i = d; i; i--)\n       \
    \ suf[i - 1] = suf[i] * (x - i);\n\n      Field ans = 0;\n      for(int i = 0;\
    \ i <= d; i++) {\n        Field l = pref[i] * suf[i] * ifat[i] * ifat[d-i];\n\
    \        if((d+i)&1) l = -l;\n        ans += l * v[i];\n      }\n      return\
    \ ans;\n    }\n  };\n}  // namespace linalg\n}  // namespace lib\n\n#endif\n#ifndef\
    \ _LIB_MODULAR_INTEGER\n#define _LIB_MODULAR_INTEGER\n#line 61 \"tests/judge/lagrange.pre.cpp\"\
    \n#ifndef _LIB_NUMBER_THEORY\n#define _LIB_NUMBER_THEORY\n#line 64 \"tests/judge/lagrange.pre.cpp\"\
    \n\nnamespace lib {\n  using namespace std;\nnamespace nt {\n  int64_t inverse(int64_t\
    \ a, int64_t b) {\n    long long b0 = b, t, q;\n    long long x0 = 0, x1 = 1;\n\
    \    if (b == 1) return 1;\n    while (a > 1) {\n      q = a / b;\n      t = b,\
    \ b = a % b, a = t;\n      t = x0, x0 = x1 - q * x0, x1 = t;\n    }\n    if (x1\
    \ < 0) x1 += b0;\n    return x1;\n  }\n}\n}  // namespace lib\n\n#endif\n\n#if\
    \ __cplusplus < 201300\n#error required(c++14)\n#endif\n\nnamespace lib {\n  using\
    \ namespace std;\nnamespace {\n  template<typename T, T ...Mods>\n  struct ModularIntegerBase\
    \ {\n    typedef ModularIntegerBase<T, Mods...> type;\n\n    T x[sizeof...(Mods)];\n\
    \    friend ostream& operator<<(ostream& output, const type& var) {\n      output\
    \ << \"(\";\n      for(int i = 0; i < sizeof...(Mods); i++) {\n        if(i) output\
    \ << \", \";\n        output << var.x[i];\n      }\n      return output << \"\
    )\";\n    }\n  };\n\n  template<typename T, T Mod>\n  struct ModularIntegerBase<T,\
    \ Mod> {\n    typedef ModularIntegerBase<T, Mod> type;\n\n    T x[1];\n\n    explicit\
    \ operator int() const { return this->x[0]; }\n    explicit operator long long()\
    \ const { return this->x[0]; }\n    explicit operator double() const { return\
    \ this->x[0]; }\n    explicit operator long double() const { return this->x[0];\
    \ }\n    friend ostream& operator<<(ostream& output, const type& var) {\n    \
    \  return output << var.x[0];\n    }\n  };\n\n\n  template<typename T, class Enable,\
    \ T ...Mods>\n  struct ModularIntegerImpl : ModularIntegerBase<T, Mods...> {\n\
    \    typedef ModularIntegerImpl<T, Enable, Mods...> type;\n    typedef T type_int;\n\
    \    typedef int64_t large_int;\n    const static size_t n_mods = sizeof...(Mods);\n\
    \n    struct Less {\n      bool operator()(const type& lhs, const type& rhs) const\
    \ {\n        for(size_t i = 0; i < sizeof...(Mods); i++)\n          if(lhs.x[i]\
    \ != rhs.x[i])\n            return lhs.x[i] < rhs.x[i];\n        return false;\n\
    \      };\n    };\n    typedef Less less;\n\n    constexpr static T mods[sizeof...(Mods)]\
    \ = {Mods...};\n    using ModularIntegerBase<T, Mods...>::x;\n\n    ModularIntegerImpl()\
    \ {\n      for(size_t i = 0; i < sizeof...(Mods); i++)\n        x[i] = T();\n\
    \    }\n    ModularIntegerImpl(large_int y) {\n      for(size_t i = 0; i < sizeof...(Mods);\
    \ i++) {\n        x[i] = y % mods[i];\n        if(x[i] < 0) x[i] += mods[i];\n\
    \      }\n    }\n    static type with_remainders(T y[sizeof...(Mods)]) {\n   \
    \   type res;\n      for(size_t i = 0; i < sizeof...(Mods); i++)\n        res.x[i]\
    \ = y[i];\n      res.normalize();\n      return res;\n    }\n\n    void normalize()\
    \ {\n      for(size_t i = 0; i < sizeof...(Mods); i++)\n        if((x[i] %= mods[i])\
    \ < 0)\n          x[i] += mods[i];\n    }\n\n    inline T operator[](int i) const\
    \ { return x[i]; }\n\n    inline T multiply(T a, T b, T mod) const {\n      return\
    \ (large_int)a*b % mod;\n    }\n\n    inline T inv(T a, T mod) const {\n     \
    \ return static_cast<T>(nt::inverse(a, mod));\n    }\n\n    type inverse() const\
    \ {\n      T res[sizeof...(Mods)];\n      for(size_t i = 0; i < sizeof...(Mods);\
    \ i++)\n        res[i] = inv(x[i], mods[i]);\n      return type::with_remainders(res);\n\
    \    }\n    \n    template<typename U>\n    T power_(T a, U p, T mod) {\n    \
    \  if(mod == 1) return T();\n      if(p < 0) {\n        if(a == 0)\n         \
    \ throw domain_error(\"0^p with negative p is invalid\");\n        p = -p;\n \
    \       a = inv(a, mod);\n      }\n      if(p == 0) return T(1);\n      if(p ==\
    \ 1) return a;\n      T res = 1;\n      while(p > 0) {\n        if(p&1)\n    \
    \      res = multiply(res, a, mod);\n        p >>= 1;\n        a = multiply(a,\
    \ a, mod);\n      }\n      return res;\n    }\n \n    type& operator+=(const type&\
    \ rhs) {\n      for(size_t i = 0; i < sizeof...(Mods); i++)\n        (x[i] +=\
    \ rhs.x[i]) %= mods[i];\n      return *this;\n    }\n    type& operator-=(const\
    \ type& rhs) {\n      for(size_t i = 0; i < sizeof...(Mods); i++)\n        if((x[i]\
    \ -= rhs.x[i]) < 0)\n          x[i] += mods[i];\n      return *this;\n    }\n\
    \    type& operator*=(const type& rhs) {\n      for(size_t i = 0; i < sizeof...(Mods);\
    \ i++)\n        x[i] = multiply(x[i], rhs.x[i], mods[i]);\n      return *this;\n\
    \    }\n    type& operator/=(const type& rhs) {\n      for(size_t i = 0; i < sizeof...(Mods);\
    \ i++)\n        x[i] = multiply(x[i], inv(rhs.x[i], mods[i]), mods[i]);\n    \
    \  return *this;\n    }\n\n    type& operator+=(T rhs) {\n      for(size_t i =\
    \ 0; i < sizeof...(Mods); i++)\n        x[i] += rhs;\n      normalize();\n   \
    \   return *this;\n    }\n    \n    type& operator-=(T rhs) {\n      for(size_t\
    \ i = 0; i < sizeof...(Mods); i++)\n        x[i] -= rhs;\n      normalize();\n\
    \      return *this;\n    }\n\n    type& operator*=(T rhs) {\n      for(size_t\
    \ i = 0; i < sizeof...(Mods); i++)\n        x[i] = multiply(x[i], rhs, mods[i]);\n\
    \      return *this;\n    }\n\n    type& operator/=(T rhs) {\n      for(size_t\
    \ i = 0; i < sizeof...(Mods); i++)\n        x[i] = multiply(inv(rhs, mods[i]),\
    \ x[i], mods[i]);\n      return *this;\n    }\n\n    type& operator^=(large_int\
    \ p) {\n      for(size_t i = 0; i < sizeof...(Mods); i++)\n        x[i] = power_(x[i],\
    \ p, mods[i]);\n      return *this;\n    }\n\n    type& operator++() {\n     \
    \ for(size_t i = 0; i < sizeof...(Mods); i++)\n        if((++x[i]) >= mods[i])\n\
    \          x[i] -= mods[i];\n      return *this;\n    }\n    type& operator--()\
    \ {\n      for(size_t i = 0; i < sizeof...(Mods); i++)\n        if((--x[i]) <\
    \ 0)\n          x[i] += mods[i];\n      return *this;\n    }\n    type& operator++(int\
    \ unused) { type res = *this; ++(*this); return res; }\n    type& operator--(int\
    \ unused) { type res = *this; --(*this); return res; }\n\n    friend type operator+(const\
    \ type& lhs, const type& rhs) {\n      type res = lhs;\n      return res += rhs;\n\
    \    }\n    friend type operator-(const type& lhs, const type& rhs) {\n      type\
    \ res = lhs;\n      return res -= rhs;\n    }\n    friend type operator*(const\
    \ type& lhs, const type& rhs) {\n      type res = lhs;\n      return res *= rhs;\n\
    \    }\n    friend type operator/(const type& lhs, const type& rhs) {\n      type\
    \ res = lhs;\n      return res /= rhs;\n    }\n\n    friend type operator+(const\
    \ type& lhs, T rhs) {\n      type res = lhs;\n      return res += rhs;\n    }\n\
    \    \n    friend type operator-(const type& lhs, T rhs) {\n      type res = lhs;\n\
    \      return res -= rhs;\n    }\n\n    friend type operator*(const type& lhs,\
    \ T rhs) {\n      type res = lhs;\n      return res *= rhs;\n    }\n    \n   \
    \ friend type operator/(const type& lhs, T rhs) {\n      type res = lhs;\n   \
    \   return res /= rhs;\n    }\n\n    friend type operator^(const type& lhs, large_int\
    \ rhs) {\n      type res = lhs;\n      return res ^= rhs;\n    }\n\n    friend\
    \ type power(const type& lhs, large_int rhs) {\n      return lhs ^ rhs;\n    }\n\
    \n    type operator-() const {\n      type res = *this;\n      for(size_t i =\
    \ 0; i < sizeof...(Mods); i++)\n        if(res.x[i])\n          res.x[i] = mods[i]\
    \ - res.x[i];\n      return res;\n    }\n\n    friend bool operator==(const type&\
    \ lhs, const type& rhs) {\n      for(size_t i = 0; i < sizeof...(Mods); i++)\n\
    \        if(lhs.x[i] != rhs.x[i])\n          return false;\n      return true;\n\
    \    }\n    friend bool operator!=(const type& lhs, const type& rhs) {\n     \
    \ return !(lhs == rhs);\n    }\n \n    friend istream& operator>>(istream& input,\
    \ type& var) {\n      T y; cin >> y;\n      var = y;\n      return input;\n  \
    \  }\n  };\n}\n\n  // Explicitly make constexpr available for linkage.\n  template<typename\
    \ T, class Enable, T ...Mods>\n  constexpr T ModularIntegerImpl<T, Enable, Mods...>::mods[];\n\
    \ \n  template<typename T, T ...Mods>\n  using ModularInteger = \n    ModularIntegerImpl<T,\n\
    \                       typename enable_if<is_integral<T>::value>::type,\n   \
    \                    Mods...>;\n \n  template<int32_t ...Mods>\n  using Mint32\
    \ = ModularInteger<int32_t, Mods...>;\n\n  template<int64_t ...Mods>\n  using\
    \ Mint64 = ModularInteger<int64_t, Mods...>;\n}  // namespace lib\n\n#endif\n\n\
    using namespace std;\nconst int MOD = (int)1e9+7;\nusing Field = lib::Mint32<MOD>;\n\
    \nlib::linalg::PrefixLagrange<Field> lagrange;\n\nconst int N = 3010;\nint n;\n\
    Field dp[N][N];\nvector<int> adj[N];\n\nvoid dfs(int u) {\n  for(int i = 0; i\
    \ <= n; i++) dp[u][i] = 1;\n  for(int v : adj[u]) {\n    dfs(v);\n    Field acc\
    \ = 0;\n    for(int i = 0; i <= n; i++) {\n      acc += dp[v][i];\n      dp[u][i]\
    \ *= acc;\n    }\n  }\n}\n\nint32_t main() {\n  int X;\n  cin >> n >> X;\n\n \
    \ for(int i = 1; i < n; i++) {\n    int p; cin >> p;\n    --p;\n    adj[p].push_back(i);\n\
    \  }\n\n  dfs(0);\n  vector<Field> p(n + 1);\n  p[0] = dp[0][0];\n  for(int i\
    \ = 1; i <= n; i++) p[i] = p[i-1] + dp[0][i];\n  cout << lagrange.eval(p, --X)\
    \ << endl;\n}\n"
  code: "#include <bits/stdc++.h>\n#ifndef _LIB_LAGRANGE\n#define _LIB_LAGRANGE\n\
    #include <bits/stdc++.h>\n\nnamespace lib {\n  using namespace std;\nnamespace\
    \ linalg {\n  template<typename Field>\n  struct PrefixLagrange {\n    vector<Field>\
    \ fat, ifat, pref, suf;\n    PrefixLagrange() {\n      fat = {1};\n      ifat\
    \ = {1};\n    }\n\n    void ensure(int n) {\n      int o = fat.size();\n     \
    \ if(n + 1 <= o) return;\n      fat.resize(n + 1), ifat.resize(n + 1);\n     \
    \ pref.resize(n + 5), suf.resize(n + 5);\n\n      for(int i = o; i <= n; i++)\n\
    \        fat[i] = fat[i-1] * i;\n\n      ifat.back() = Field(1) / fat.back();\n\
    \      for(int i = n-1; i >= o; i--)\n        ifat[i] = ifat[i + 1] * (i + 1);\n\
    \    }\n\n    template<typename T>\n    Field eval(const vector<Field>& v, T x)\
    \ {\n      assert(!v.empty());\n      int d = (int)v.size() - 1;\n      if(x <=\
    \ d) return v[x];\n\n      ensure(d + 1);\n\n      pref[0] = suf[d] = 1;\n   \
    \   for(int i = 0; i < d; i++)\n        pref[i + 1] = pref[i] * (x - i);\n   \
    \   for(int i = d; i; i--)\n        suf[i - 1] = suf[i] * (x - i);\n\n      Field\
    \ ans = 0;\n      for(int i = 0; i <= d; i++) {\n        Field l = pref[i] * suf[i]\
    \ * ifat[i] * ifat[d-i];\n        if((d+i)&1) l = -l;\n        ans += l * v[i];\n\
    \      }\n      return ans;\n    }\n  };\n}  // namespace linalg\n}  // namespace\
    \ lib\n\n#endif\n#ifndef _LIB_MODULAR_INTEGER\n#define _LIB_MODULAR_INTEGER\n\
    #include <bits/stdc++.h>\n#ifndef _LIB_NUMBER_THEORY\n#define _LIB_NUMBER_THEORY\n\
    #include <bits/stdc++.h>\n\nnamespace lib {\n  using namespace std;\nnamespace\
    \ nt {\n  int64_t inverse(int64_t a, int64_t b) {\n    long long b0 = b, t, q;\n\
    \    long long x0 = 0, x1 = 1;\n    if (b == 1) return 1;\n    while (a > 1) {\n\
    \      q = a / b;\n      t = b, b = a % b, a = t;\n      t = x0, x0 = x1 - q *\
    \ x0, x1 = t;\n    }\n    if (x1 < 0) x1 += b0;\n    return x1;\n  }\n}\n}  //\
    \ namespace lib\n\n#endif\n\n#if __cplusplus < 201300\n#error required(c++14)\n\
    #endif\n\nnamespace lib {\n  using namespace std;\nnamespace {\n  template<typename\
    \ T, T ...Mods>\n  struct ModularIntegerBase {\n    typedef ModularIntegerBase<T,\
    \ Mods...> type;\n\n    T x[sizeof...(Mods)];\n    friend ostream& operator<<(ostream&\
    \ output, const type& var) {\n      output << \"(\";\n      for(int i = 0; i <\
    \ sizeof...(Mods); i++) {\n        if(i) output << \", \";\n        output <<\
    \ var.x[i];\n      }\n      return output << \")\";\n    }\n  };\n\n  template<typename\
    \ T, T Mod>\n  struct ModularIntegerBase<T, Mod> {\n    typedef ModularIntegerBase<T,\
    \ Mod> type;\n\n    T x[1];\n\n    explicit operator int() const { return this->x[0];\
    \ }\n    explicit operator long long() const { return this->x[0]; }\n    explicit\
    \ operator double() const { return this->x[0]; }\n    explicit operator long double()\
    \ const { return this->x[0]; }\n    friend ostream& operator<<(ostream& output,\
    \ const type& var) {\n      return output << var.x[0];\n    }\n  };\n\n\n  template<typename\
    \ T, class Enable, T ...Mods>\n  struct ModularIntegerImpl : ModularIntegerBase<T,\
    \ Mods...> {\n    typedef ModularIntegerImpl<T, Enable, Mods...> type;\n    typedef\
    \ T type_int;\n    typedef int64_t large_int;\n    const static size_t n_mods\
    \ = sizeof...(Mods);\n\n    struct Less {\n      bool operator()(const type& lhs,\
    \ const type& rhs) const {\n        for(size_t i = 0; i < sizeof...(Mods); i++)\n\
    \          if(lhs.x[i] != rhs.x[i])\n            return lhs.x[i] < rhs.x[i];\n\
    \        return false;\n      };\n    };\n    typedef Less less;\n\n    constexpr\
    \ static T mods[sizeof...(Mods)] = {Mods...};\n    using ModularIntegerBase<T,\
    \ Mods...>::x;\n\n    ModularIntegerImpl() {\n      for(size_t i = 0; i < sizeof...(Mods);\
    \ i++)\n        x[i] = T();\n    }\n    ModularIntegerImpl(large_int y) {\n  \
    \    for(size_t i = 0; i < sizeof...(Mods); i++) {\n        x[i] = y % mods[i];\n\
    \        if(x[i] < 0) x[i] += mods[i];\n      }\n    }\n    static type with_remainders(T\
    \ y[sizeof...(Mods)]) {\n      type res;\n      for(size_t i = 0; i < sizeof...(Mods);\
    \ i++)\n        res.x[i] = y[i];\n      res.normalize();\n      return res;\n\
    \    }\n\n    void normalize() {\n      for(size_t i = 0; i < sizeof...(Mods);\
    \ i++)\n        if((x[i] %= mods[i]) < 0)\n          x[i] += mods[i];\n    }\n\
    \n    inline T operator[](int i) const { return x[i]; }\n\n    inline T multiply(T\
    \ a, T b, T mod) const {\n      return (large_int)a*b % mod;\n    }\n\n    inline\
    \ T inv(T a, T mod) const {\n      return static_cast<T>(nt::inverse(a, mod));\n\
    \    }\n\n    type inverse() const {\n      T res[sizeof...(Mods)];\n      for(size_t\
    \ i = 0; i < sizeof...(Mods); i++)\n        res[i] = inv(x[i], mods[i]);\n   \
    \   return type::with_remainders(res);\n    }\n    \n    template<typename U>\n\
    \    T power_(T a, U p, T mod) {\n      if(mod == 1) return T();\n      if(p <\
    \ 0) {\n        if(a == 0)\n          throw domain_error(\"0^p with negative p\
    \ is invalid\");\n        p = -p;\n        a = inv(a, mod);\n      }\n      if(p\
    \ == 0) return T(1);\n      if(p == 1) return a;\n      T res = 1;\n      while(p\
    \ > 0) {\n        if(p&1)\n          res = multiply(res, a, mod);\n        p >>=\
    \ 1;\n        a = multiply(a, a, mod);\n      }\n      return res;\n    }\n \n\
    \    type& operator+=(const type& rhs) {\n      for(size_t i = 0; i < sizeof...(Mods);\
    \ i++)\n        (x[i] += rhs.x[i]) %= mods[i];\n      return *this;\n    }\n \
    \   type& operator-=(const type& rhs) {\n      for(size_t i = 0; i < sizeof...(Mods);\
    \ i++)\n        if((x[i] -= rhs.x[i]) < 0)\n          x[i] += mods[i];\n     \
    \ return *this;\n    }\n    type& operator*=(const type& rhs) {\n      for(size_t\
    \ i = 0; i < sizeof...(Mods); i++)\n        x[i] = multiply(x[i], rhs.x[i], mods[i]);\n\
    \      return *this;\n    }\n    type& operator/=(const type& rhs) {\n      for(size_t\
    \ i = 0; i < sizeof...(Mods); i++)\n        x[i] = multiply(x[i], inv(rhs.x[i],\
    \ mods[i]), mods[i]);\n      return *this;\n    }\n\n    type& operator+=(T rhs)\
    \ {\n      for(size_t i = 0; i < sizeof...(Mods); i++)\n        x[i] += rhs;\n\
    \      normalize();\n      return *this;\n    }\n    \n    type& operator-=(T\
    \ rhs) {\n      for(size_t i = 0; i < sizeof...(Mods); i++)\n        x[i] -= rhs;\n\
    \      normalize();\n      return *this;\n    }\n\n    type& operator*=(T rhs)\
    \ {\n      for(size_t i = 0; i < sizeof...(Mods); i++)\n        x[i] = multiply(x[i],\
    \ rhs, mods[i]);\n      return *this;\n    }\n\n    type& operator/=(T rhs) {\n\
    \      for(size_t i = 0; i < sizeof...(Mods); i++)\n        x[i] = multiply(inv(rhs,\
    \ mods[i]), x[i], mods[i]);\n      return *this;\n    }\n\n    type& operator^=(large_int\
    \ p) {\n      for(size_t i = 0; i < sizeof...(Mods); i++)\n        x[i] = power_(x[i],\
    \ p, mods[i]);\n      return *this;\n    }\n\n    type& operator++() {\n     \
    \ for(size_t i = 0; i < sizeof...(Mods); i++)\n        if((++x[i]) >= mods[i])\n\
    \          x[i] -= mods[i];\n      return *this;\n    }\n    type& operator--()\
    \ {\n      for(size_t i = 0; i < sizeof...(Mods); i++)\n        if((--x[i]) <\
    \ 0)\n          x[i] += mods[i];\n      return *this;\n    }\n    type& operator++(int\
    \ unused) { type res = *this; ++(*this); return res; }\n    type& operator--(int\
    \ unused) { type res = *this; --(*this); return res; }\n\n    friend type operator+(const\
    \ type& lhs, const type& rhs) {\n      type res = lhs;\n      return res += rhs;\n\
    \    }\n    friend type operator-(const type& lhs, const type& rhs) {\n      type\
    \ res = lhs;\n      return res -= rhs;\n    }\n    friend type operator*(const\
    \ type& lhs, const type& rhs) {\n      type res = lhs;\n      return res *= rhs;\n\
    \    }\n    friend type operator/(const type& lhs, const type& rhs) {\n      type\
    \ res = lhs;\n      return res /= rhs;\n    }\n\n    friend type operator+(const\
    \ type& lhs, T rhs) {\n      type res = lhs;\n      return res += rhs;\n    }\n\
    \    \n    friend type operator-(const type& lhs, T rhs) {\n      type res = lhs;\n\
    \      return res -= rhs;\n    }\n\n    friend type operator*(const type& lhs,\
    \ T rhs) {\n      type res = lhs;\n      return res *= rhs;\n    }\n    \n   \
    \ friend type operator/(const type& lhs, T rhs) {\n      type res = lhs;\n   \
    \   return res /= rhs;\n    }\n\n    friend type operator^(const type& lhs, large_int\
    \ rhs) {\n      type res = lhs;\n      return res ^= rhs;\n    }\n\n    friend\
    \ type power(const type& lhs, large_int rhs) {\n      return lhs ^ rhs;\n    }\n\
    \n    type operator-() const {\n      type res = *this;\n      for(size_t i =\
    \ 0; i < sizeof...(Mods); i++)\n        if(res.x[i])\n          res.x[i] = mods[i]\
    \ - res.x[i];\n      return res;\n    }\n\n    friend bool operator==(const type&\
    \ lhs, const type& rhs) {\n      for(size_t i = 0; i < sizeof...(Mods); i++)\n\
    \        if(lhs.x[i] != rhs.x[i])\n          return false;\n      return true;\n\
    \    }\n    friend bool operator!=(const type& lhs, const type& rhs) {\n     \
    \ return !(lhs == rhs);\n    }\n \n    friend istream& operator>>(istream& input,\
    \ type& var) {\n      T y; cin >> y;\n      var = y;\n      return input;\n  \
    \  }\n  };\n}\n\n  // Explicitly make constexpr available for linkage.\n  template<typename\
    \ T, class Enable, T ...Mods>\n  constexpr T ModularIntegerImpl<T, Enable, Mods...>::mods[];\n\
    \ \n  template<typename T, T ...Mods>\n  using ModularInteger = \n    ModularIntegerImpl<T,\n\
    \                       typename enable_if<is_integral<T>::value>::type,\n   \
    \                    Mods...>;\n \n  template<int32_t ...Mods>\n  using Mint32\
    \ = ModularInteger<int32_t, Mods...>;\n\n  template<int64_t ...Mods>\n  using\
    \ Mint64 = ModularInteger<int64_t, Mods...>;\n}  // namespace lib\n\n#endif\n\n\
    using namespace std;\nconst int MOD = (int)1e9+7;\nusing Field = lib::Mint32<MOD>;\n\
    \nlib::linalg::PrefixLagrange<Field> lagrange;\n\nconst int N = 3010;\nint n;\n\
    Field dp[N][N];\nvector<int> adj[N];\n\nvoid dfs(int u) {\n  for(int i = 0; i\
    \ <= n; i++) dp[u][i] = 1;\n  for(int v : adj[u]) {\n    dfs(v);\n    Field acc\
    \ = 0;\n    for(int i = 0; i <= n; i++) {\n      acc += dp[v][i];\n      dp[u][i]\
    \ *= acc;\n    }\n  }\n}\n\nint32_t main() {\n  int X;\n  cin >> n >> X;\n\n \
    \ for(int i = 1; i < n; i++) {\n    int p; cin >> p;\n    --p;\n    adj[p].push_back(i);\n\
    \  }\n\n  dfs(0);\n  vector<Field> p(n + 1);\n  p[0] = dp[0][0];\n  for(int i\
    \ = 1; i <= n; i++) p[i] = p[i-1] + dp[0][i];\n  cout << lagrange.eval(p, --X)\
    \ << endl;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: tests/judge/lagrange.pre.cpp
  requiredBy: []
  timestamp: '2018-11-02 19:02:10-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tests/judge/lagrange.pre.cpp
layout: document
redirect_from:
- /library/tests/judge/lagrange.pre.cpp
- /library/tests/judge/lagrange.pre.cpp.html
title: tests/judge/lagrange.pre.cpp
---
