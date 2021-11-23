---
documentation_of: //polynomial/ExponentialSum.cpp
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