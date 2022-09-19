---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: BitTricks.cpp
    title: BitTricks.cpp
  - icon: ':heavy_check_mark:'
    path: Combinatorics.cpp
    title: Combinatorics.cpp
  - icon: ':heavy_check_mark:'
    path: Combinatorics.cpp
    title: Combinatorics.cpp
  - icon: ':heavy_check_mark:'
    path: Lagrange.cpp
    title: Lagrange.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/exp-sum-limit.test.cpp
    title: tests/yosupo/exp-sum-limit.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/exp-sum.test.cpp
    title: tests/yosupo/exp-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"polynomial/ExponentialSum.cpp\"\n\n\n#include <bits/stdc++.h>\n\
    #line 1 \"Combinatorics.cpp\"\n\n\n#line 1 \"BitTricks.cpp\"\n\n\n#line 4 \"BitTricks.cpp\"\
    \n\nnamespace lib {\nlong long next_power_of_two(long long n) {\n  return 1LL\
    \ << (sizeof(long long) * 8 - 1 - __builtin_clzll(n) +\n                 ((n &\
    \ (n - 1LL)) != 0));\n}\n} // namespace lib\n\n\n#line 5 \"Combinatorics.cpp\"\
    \n\nnamespace lib {\nusing namespace std;\ntemplate<typename T>\nstruct Combinatorics\
    \ {\n    static vector<T> fat;\n    static vector<T> inv;\n    static vector<T>\
    \ ifat;\n\n    static T factorial(int i) {\n        ensure_fat(next_power_of_two(i));\n\
    \        return fat[i];\n    }\n\n    static T inverse(int i) {\n        ensure_inv(next_power_of_two(i));\n\
    \        return inv[i];\n    }\n\n    static T ifactorial(int i) {\n        ensure_ifat(next_power_of_two(i));\n\
    \        return ifat[i];\n    }\n\n    static T nCr(int n, int K) {\n        if(K\
    \ > n) return 0;\n        ensure_fat(next_power_of_two(n));\n        ensure_ifat(next_power_of_two(n));\n\
    \        return fat[n] * ifat[n-K] * ifat[K];\n    }\n\n    static T arrangement(int\
    \ n, int K) {\n        return nCr(n, K) * factorial(n);\n    }\n\n    static T\
    \ nCr_rep(int n, int K) {\n        return interpolate(n - 1, K);\n    }\n\n  \
    \  static T interpolate(int a, int b) {\n        return nCr(a+b, b);\n    }\n\n\
    \    static void ensure_fat(int i) {\n        int o = fat.size();\n        if(i\
    \ < o) return;\n        fat.resize(i+1);\n        for(int j = o; j <= i; j++)\
    \ fat[j] = fat[j-1]*j;\n    }\n\n    static void ensure_inv(int i) {\n       \
    \ int o = inv.size();\n        if(i < o) return;\n        inv.resize(i+1);\n \
    \       for(int j = o; j <= i; j++) inv[j] = -(inv[T::mod%j] * (T::mod/j));\n\
    \    }\n\n    static void ensure_ifat(int i) {\n        int o = ifat.size();\n\
    \        if(i < o) return;\n        ifat.resize(i+1);\n        ensure_inv(i);\n\
    \        for(int j = o; j <= i; j++) ifat[j] = ifat[j-1]*inv[j];\n    }\n};\n\n\
    template<typename T>\nvector<T> Combinatorics<T>::fat = vector<T>(1, T(1));\n\
    template<typename T>\nvector<T> Combinatorics<T>::inv = vector<T>(2, T(1));\n\
    template<typename T>\nvector<T> Combinatorics<T>::ifat = vector<T>(1, T(1));\n\
    } // namespace lib\n\n\n#line 1 \"Lagrange.cpp\"\n\n\n#line 5 \"Lagrange.cpp\"\
    \n\nnamespace lib {\nusing namespace std;\nnamespace linalg {\ntemplate <typename\
    \ Field> struct PrefixLagrange {\n  vector<Field> pref, suf;\n  PrefixLagrange()\
    \ {}\n\n  void ensure(int n) {\n    int o = pref.size();\n    if (n <= o)\n  \
    \    return;\n    pref.resize(n), suf.resize(n);\n  }\n\n  template <typename\
    \ T> Field eval(const vector<Field> &v, T x) {\n    using C = Combinatorics<Field>;\n\
    \    assert(!v.empty());\n    int d = (int)v.size() - 1;\n    if (x <= d)\n  \
    \    return v[x];\n\n    ensure(d + 1);\n\n    Field a = x;\n    pref[0] = suf[d]\
    \ = 1;\n    for (T i = 0; i < d; i++)\n      pref[i + 1] = pref[i] * a, a -= 1;\n\
    \    for (T i = d; i; i--)\n      suf[i - 1] = suf[i] * a, a += 1;\n\n    Field\
    \ ans = 0;\n    for (int i = 0; i <= d; i++) {\n      Field l = pref[i] * suf[i]\
    \ * C::ifactorial(i) * C::ifactorial(d-i) * v[i];\n      if ((d + i) & 1)\n  \
    \      l = -l;\n      ans += l;\n    }\n    return ans;\n  }\n};\n\ntemplate<typename\
    \ T, typename U>\nT lagrange_iota(const vector<T>& f, U n) {\n  static PrefixLagrange<T>\
    \ lag;\n  return lag.eval(f, n);\n}\n\ntemplate<typename T, typename U>\nT lagrange_iota_sum(const\
    \ vector<T>& f, U n) {\n  int m = f.size();\n  vector<T> g(m + 1);\n  for(int\
    \ i = 1; i <= m; i++)\n      g[i] = g[i-1] + f[i-1];\n  return lagrange_iota(g,\
    \ n);\n}\n} // namespace linalg\n} // namespace lib\n\n\n#line 6 \"polynomial/ExponentialSum.cpp\"\
    \n\nnamespace lib {\nusing namespace std;\n\n// given  : f(0)...f(k) (deg(f) =\
    \ k), a\n// return : \\sum_{i=0...infty} a^i f(i)\ntemplate<typename Field>\n\
    Field exponential_sum_limit(const vector<Field>& f, Field a) {\n  if(a == 0) return\
    \ f[0];\n  assert(a != 1);\n  int m = f.size();\n  vector<Field> g(m);\n  Field\
    \ acc = 1;\n  for(int i = 0; i < m; i++) g[i] = f[i] * acc, acc *= a;\n  for(int\
    \ i = 1; i < m; i++) g[i] += g[i-1];\n  Field c = 0;\n  acc = 1;\n  for(int i\
    \ = 0; i < m; i++) {\n    c += Combinatorics<Field>::nCr(m, i) * acc * g[m - i\
    \ - 1];\n    acc *= -a;\n  }\n  c /= (1 - a)^m;\n  return c;\n}\n\n// given  :\
    \ f(0)...f(k) (deg(f) = k), a, n\n// return : \\sum_{i=0...n-1} a^i f(i)\ntemplate<typename\
    \ Field>\nField exponential_sum(const vector<Field>& f, Field a, int64_t n) {\n\
    \  if(n == 0) return 0;\n  if(a == 0) return f[0];\n  if(a == 1) {\n    // Interpolate\
    \ polynomial of deg == k + 1\n    return linalg::lagrange_iota_sum(f, n);\n  }\n\
    \  int m = f.size();\n  vector<Field> g(m);\n  auto c = exponential_sum_limit(f,\
    \ a);\n  Field acc = 1;\n  for(int i = 0; i < m; i++) g[i] = f[i] * acc, acc *=\
    \ a;\n  for(int i = 1; i < m; i++) g[i] += g[i-1];\n  auto ai = Field(1) / a;\n\
    \  acc = 1;\n  for(int i = 0; i < m; i++) {\n    g[i] = (g[i] - c) * acc;\n  \
    \  acc *= ai;\n  }\n  // Interpolate polynomial of deg == k\n  auto tn = linalg::lagrange_iota(g,\
    \ n - 1);\n  return c + (a^(n-1)) * tn;\n}\n\n// given  : p, n\n// return : (0^p,\
    \ 1^p, ... , n^p)\ntemplate <typename Field>\nvector<Field> monomials(int p, int\
    \ n) {\n  vector<Field> f(n + 1, Field(0));\n  if (!p) {\n    f[0] = 1;\n    return\
    \ std::move(f);\n  }\n  f[1] = 1;\n  vector<bool> sieve(n + 1, false);\n  vector<int>\
    \ ps;\n  for (int i = 2; i <= n; i++) {\n    if (!sieve[i]) {\n      f[i] = Field(i)^p;\n\
    \      ps.push_back(i);\n    }\n    for (int j = 0; j < (int)ps.size() && i *\
    \ ps[j] <= n; j++) {\n      sieve[i * ps[j]] = 1;\n      f[i * ps[j]] = f[i] *\
    \ f[ps[j]];\n      if (i % ps[j] == 0) break;\n    }\n  }\n  return std::move(f);\n\
    }\n} // namespace lib\n\n\n"
  code: "#ifndef _LIB_EXPONENTIAL_SUM\n#define _LIB_EXPONENTIAL_SUM\n#include <bits/stdc++.h>\n\
    #include \"../Combinatorics.cpp\"\n#include \"../Lagrange.cpp\"\n\nnamespace lib\
    \ {\nusing namespace std;\n\n// given  : f(0)...f(k) (deg(f) = k), a\n// return\
    \ : \\sum_{i=0...infty} a^i f(i)\ntemplate<typename Field>\nField exponential_sum_limit(const\
    \ vector<Field>& f, Field a) {\n  if(a == 0) return f[0];\n  assert(a != 1);\n\
    \  int m = f.size();\n  vector<Field> g(m);\n  Field acc = 1;\n  for(int i = 0;\
    \ i < m; i++) g[i] = f[i] * acc, acc *= a;\n  for(int i = 1; i < m; i++) g[i]\
    \ += g[i-1];\n  Field c = 0;\n  acc = 1;\n  for(int i = 0; i < m; i++) {\n   \
    \ c += Combinatorics<Field>::nCr(m, i) * acc * g[m - i - 1];\n    acc *= -a;\n\
    \  }\n  c /= (1 - a)^m;\n  return c;\n}\n\n// given  : f(0)...f(k) (deg(f) = k),\
    \ a, n\n// return : \\sum_{i=0...n-1} a^i f(i)\ntemplate<typename Field>\nField\
    \ exponential_sum(const vector<Field>& f, Field a, int64_t n) {\n  if(n == 0)\
    \ return 0;\n  if(a == 0) return f[0];\n  if(a == 1) {\n    // Interpolate polynomial\
    \ of deg == k + 1\n    return linalg::lagrange_iota_sum(f, n);\n  }\n  int m =\
    \ f.size();\n  vector<Field> g(m);\n  auto c = exponential_sum_limit(f, a);\n\
    \  Field acc = 1;\n  for(int i = 0; i < m; i++) g[i] = f[i] * acc, acc *= a;\n\
    \  for(int i = 1; i < m; i++) g[i] += g[i-1];\n  auto ai = Field(1) / a;\n  acc\
    \ = 1;\n  for(int i = 0; i < m; i++) {\n    g[i] = (g[i] - c) * acc;\n    acc\
    \ *= ai;\n  }\n  // Interpolate polynomial of deg == k\n  auto tn = linalg::lagrange_iota(g,\
    \ n - 1);\n  return c + (a^(n-1)) * tn;\n}\n\n// given  : p, n\n// return : (0^p,\
    \ 1^p, ... , n^p)\ntemplate <typename Field>\nvector<Field> monomials(int p, int\
    \ n) {\n  vector<Field> f(n + 1, Field(0));\n  if (!p) {\n    f[0] = 1;\n    return\
    \ std::move(f);\n  }\n  f[1] = 1;\n  vector<bool> sieve(n + 1, false);\n  vector<int>\
    \ ps;\n  for (int i = 2; i <= n; i++) {\n    if (!sieve[i]) {\n      f[i] = Field(i)^p;\n\
    \      ps.push_back(i);\n    }\n    for (int j = 0; j < (int)ps.size() && i *\
    \ ps[j] <= n; j++) {\n      sieve[i * ps[j]] = 1;\n      f[i * ps[j]] = f[i] *\
    \ f[ps[j]];\n      if (i % ps[j] == 0) break;\n    }\n  }\n  return std::move(f);\n\
    }\n} // namespace lib\n\n#endif\n"
  dependsOn:
  - Combinatorics.cpp
  - BitTricks.cpp
  - Lagrange.cpp
  - Combinatorics.cpp
  isVerificationFile: false
  path: polynomial/ExponentialSum.cpp
  requiredBy: []
  timestamp: '2021-02-12 00:21:13-03:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/exp-sum.test.cpp
  - tests/yosupo/exp-sum-limit.test.cpp
documentation_of: polynomial/ExponentialSum.cpp
layout: document
title: Exponential Sum
---

**Problem 1**: Given $a$ ($a \neq 1$) and a sequence $f(0), \dots, f(k)$ compute $\sum_{i=0}^{\infty} a^i f(i)$, where $f$ is a polynomial with $deg(f) \leq k$, all in $\mathbb{Z}_{p}$.

**Problem 2**: Given $a, n$ and a sequence $f(0), \dots, f(k)$ compute $\sum_{i=0}^{n-1} a^i f(i)$, where $f$ is a polynomial with $deg(f) \leq k$, all in $\mathbb{Z}_{p}$.

We can use Problem 1 as a subprocedure for Problem 2.

---

### Problem 1 - Memo

We can first look at the generating function for $f$. Let it be $G_f$. Then:

$$
G_f(x) = \sum_i f(i) x^i
$$

One can show $G_f(x)$ is

$$
G_f(x) = \frac{P_f(x)}{(1 - x)^{k+1}},
$$

where $P_f$ is a polynomial of degree $k$ or less.

> **Proof:**  A polynomial can be represented as a linear combination of [Newton basis polynomials](https://en.wikipedia.org/wiki/Newton_polynomial). The generating function for them is:
>
> $$\frac{i! x^i}{(1-x)^{i+1}}$$
> We can see that the highest degree of a polynomial in $n(i)$ in the linear combination is $k$.

We can get the generating sequence for the terms in the summation in our answer by doing:

$$
\sum_i a^i f(i) x^i = \frac{P_f(x)}{(1 - ax)^{k+1}}
$$

If we look at these as power series, and we do $x = 1$, we know that the left-hand side converges (TODO: prove this, although we can infer this from the statement).

$$
\sum_{i=0}^{\infty} a^i f(i) = \frac{P_f(1)}{(1 - a)^{k+1}}
$$

If we are able to evaluate $P_f(1)$, we can figure out the limit of the power series for the given $a$ through substitution. We can seek for $P_f$ coefficients by looking at this again as generating functions.

$$
(1 - ax)^{k+1} \sum_i a^i f(i) x^i = P_f(x) \\
\Rightarrow 
[x^N]P_f(x) = \sum_{i=0}^{N} \binom{k+1}{N-i} (-a)^{N-i} a^i f(i) \\
\Rightarrow
P_f(1) = \sum_{j=0}^{k} [x^j]P_f(x) =
\sum_{j=0}^{k} \sum_{i=0}^j \binom{k+1}{j-i} (-a)^{j-i} a^i f(i)
$$

> **Note:** Series expansion above comes from the cheat sheet.

With proper reindexing and precomputation, this 2D sum can be computed in linear time (see code). Now that we could compute $P_f(1)$ efficiently, we can find the limit, and thus we have the answer.

---

### Problem 2 - Memo

Let's consider cases where $a \leq 1$ separately. Zero can be solved trivially, one reduces to simple Lagrange Interpolation of polynomial partial sum. Thus, for the rest of this, let's assume $a > 2$.

We'll use Problem 1 to solve Problem 2. Throughout this note, let $c$ be the answer for Problem 1 using the same parameters. Now on to the solution.

Let's look again at the generating function for $h(x) = a^x f(x)$. Let's call it $G_h(x)$.

$$
G_h(x) = \frac{P_f(x)}{(1 - ax)^{k+1}}
$$

Now what we really want is the prefix sum of the terms of $G_h$.

$$
\frac{G_h(x)}{1 - x} = \frac{P_f(x)}{(1-x) (1 - ax)^{k+1}}
$$

Let's dive deeper into how a term of this GF looks like.

$$
[x^N]\frac{G_h(x)}{1-x} = \sum_{i=0}^{N} a^i f(i)
$$

Thus, the $(n-1)$-th term is exactly our answer, but we can't really figure it out yet. Let's try to reduce to Problem 1. What if we reflect each term around $c$ (which, remember, is the answer to Problem 1)?

$$
[x^N]\frac{c - G_h(x)}{1-x} = c - \sum_{i=0}^N a^i f(i) \\
= \sum_{i=0}^{\infty} a^i f(i) - \sum_{i=0}^{N} a^i f(i)
= \sum_{i=N}^{\infty} a^i f(i)
$$

This last summation is very similar to Problem 1, except that we start from $N$ instead of zero. It's almost like we're transforming prefix sum into an infinite sufix sum problem.

Let's change the GF even more to make them look more alike: what if we divide every $N$-th term by $a^N$?

$$
[x^N]\frac{c - G_h(x)}{a^N (1-x)} = a^{-N} \sum_{i=N}^{\infty} a^i f(i) \\
= \sum_{i=0}^{\infty} a^i f(i+N)
$$

Now it's actually identical to the generating function in Problem 1. It seems different just because our polynomial is shifted. But this shifted polynomial -- for a fixed $N$ -- is in fact another polynomial of same degree as $f$. Thus, every trick we did in Problem 1 applies here.

We can't really solve it like we did with Problem 1, though, exactly because we don't know  how to evaluate this shifted polynomial fast.

But we can reuse the same tricks. We can write the generating function:

$$
\sum_{i=0}^\infty a^i f(i+N) x^i = \frac{S(x)}{(1-ax)^{k+1}}
$$

where $S(x)$ is some polynomial of degree $k$ or less.

Then, again, we can see what happens when $x = 1$.

$$
\sum_{i=0}^\infty a^i f(i+N) = \frac{S(1)}{(1-a)^{k+1}}
$$

And now we can try to figure out $S(1)$. Refer to Problem 1 on how to do this. It's not hard to see that, if we allow $N$ to vary, $S(1)$ will be a polynomial on $N$ of degree $k$ or less, and thus that the limit of the power series will be a polynomial on $N$ as well. Let it be $t(N)$. Thus,

$$
[x^N]\frac{c - G_h(x)}{a^N (1-x)} =
\sum_{i=0}^{\infty} a^i f(i+N) = t(N)
$$

and then

$$
[x^N]\frac{G_h(x)}{1-x} = c + a^N t(N)
$$

The answer will be $c + a^{n-1} t(n-1)$. Now we just need to find $t(n-1)$ fast. If we can find $t(0), \dots, t(k)$ fast, we can use Lagrange interpolation to find $t(n-1)$. Although it might seem hard to evaluate $t$ since we don't know it's coefficients, we can find the $k + 1$ values from the generating function above.

$$
[x^N]\frac{G_h(x)}{1-x} = c + a^N t(N) = \sum_{i=0}^{N} a^i f(i) \\
\Rightarrow
t(N) = \frac{-c + \sum_{i=0}^{N} a^i f(i)}{a^N}
$$