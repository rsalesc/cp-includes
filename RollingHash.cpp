#ifndef _LIB_ROLLING_HASH
#define _LIB_ROLLING_HASH
#include "ModularInteger.cpp"
#include "Random.cpp"
#include "Traits.cpp"
#include <bits/stdc++.h>

namespace lib {
using namespace std;
namespace hashing {
namespace {
using traits::HasBidirectionalIterator;
using traits::HasInputIterator;
using traits::IsBidirectionalIterator;
using traits::IsInputIterator;
using traits::IsRandomIterator;
} // namespace

const static int DEFAULT_MAX_POWERS = 1e6 + 5;
const static int GOOD_MOD1 = (int)1e9 + 7;
const static int GOOD_MOD2 = (int)1e9 + 9;

template <typename T, T... Mods> struct BaseProvider {
  typedef BaseProvider<T, Mods...> type;
  typedef ModularInteger<T, Mods...> mint_type;

  mint_type b;
  vector<mint_type> powers;
  int max_powers = 0;

  BaseProvider(T bases[sizeof...(Mods)]) : powers(1, 1) {
    b = mint_type::with_remainders(bases);
  }
  BaseProvider() : powers(1, 1) {
    T bases[sizeof...(Mods)];
    for (size_t i = 0; i < sizeof...(Mods); i++)
      bases[i] = rng::gen.uniform_int(mint_type::mods[i]);
    b = mint_type::with_remainders(bases);
  }

  void set_max_powers(int x) { max_powers = x; }

  inline operator mint_type() const { return b; }
  inline T operator()(int i) { return b[i]; }

  void ensure(int p) const {
    type *self = const_cast<type *>(this);
    int cur = powers.size();
    if (p > cur)
      self->powers.resize(max(2 * cur, p));
    else
      return;
    int nsz = powers.size();
    for (int i = cur; i < nsz; i++)
      self->powers[i] = powers[i - 1] * b;
  }

  mint_type power(int p) const {
    if (p >= max_powers)
      return b ^ p;
    ensure(p + 1);
    return powers[p];
  }
  T power(int p, int i) const { return power(p)[i]; }
};

template <typename T, T... Mods> struct RollingHash {
  typedef RollingHash<T, Mods...> type;
  typedef ModularInteger<T, Mods...> mint_type;
  typedef BaseProvider<T, Mods...> base_type;

  vector<mint_type> hs;

  struct Hash {
    mint_type x;
    int n;

    struct Less {
      typename mint_type::less mint_less;
      bool operator()(const Hash &lhs, const Hash &rhs) const {
        if (lhs.n == rhs.n)
          return mint_less(lhs.x, rhs.x);
        return lhs.n < rhs.n;
      }
    };
    typedef Less less;

    Hash() : n(0) {}
    explicit Hash(mint_type y) : x(y), n(1) {}
    Hash(mint_type y, int n) : x(y), n(n) { assert(n >= 0); }

    explicit operator mint_type() const { return x; }

    friend bool operator==(const Hash &lhs, const Hash &rhs) {
      return tie(lhs.n, lhs.x) == tie(rhs.n, rhs.x);
    }
    friend bool operator!=(const Hash &lhs, const Hash &rhs) {
      return !(lhs == rhs);
    }
    friend ostream &operator<<(ostream &output, const Hash &var) {
      return output << var.x << "{" << var.n << "}";
    }
  };

  struct Cat {
    shared_ptr<base_type> base;
    Cat(const shared_ptr<base_type> &base) : base(base) {}

    template <
        typename Iterator,
        typename enable_if<IsInputIterator<Iterator>::value>::type * = nullptr>
    Hash operator()(Iterator begin, Iterator end) {
      Hash res;
      for (auto it = begin; it != end; ++it) {
        res.n += it->n;
        res.x *= base->power(it->n);
        res.x += it->x;
      }
      return res;
    }

    Hash operator()(const initializer_list<Hash> &hashes) {
      return (*this)(hashes.begin(), hashes.end());
    }

    template <class... Args> Hash operator()(Args... args) {
      return (*this)({args...});
    }

    template <class... Args>
    pair<Hash, Hash> cat(const pair<Args, Args> &... args) {
      initializer_list<Hash> fwd_list = {args.first...};
      initializer_list<Hash> bwd_list = {args.second...};
      return {cat(fwd_list.begin(), fwd_list.end()),
              cat(bwd_list.rbegin(), bwd_list.rend())};
    }
  };

  Cat cat;

  RollingHash(const shared_ptr<base_type> &base) : hs(1), cat(base) {}

  template <
      typename Container,
      typename enable_if<HasInputIterator<Container>::value>::type * = nullptr>
  RollingHash(const Container &container, const shared_ptr<base_type> &base)
      : hs(1), cat(base) {
    (*this) += container;
  }

  template <
      typename Iterator,
      typename enable_if<IsInputIterator<Iterator>::value>::type * = nullptr>
  RollingHash(Iterator begin, Iterator end, const shared_ptr<base_type> &base)
      : hs(1), cat(base) {
    append(begin, end);
  }

  inline int size() const { return (int)hs.size() - 1; }

  template <
      typename Iterator,
      typename enable_if<IsRandomIterator<Iterator>::value>::type * = nullptr>
  void append(Iterator begin, Iterator end) {
    int i = hs.size();
    hs.resize(hs.size() + distance(begin, end));
    for (auto it = begin; it != end; ++it, ++i)
      hs[i] = hs[i - 1] * (*cat.base) + mint_type(*it);
  }

  template <
      typename Iterator,
      typename enable_if<!IsRandomIterator<Iterator>::value>::type * = nullptr>
  void append(Iterator begin, Iterator end) {
    for (auto it = begin; it != end; ++it)
      (*this) += *it;
  }

  template <typename U> void append(U rhs) { (*this) += rhs; }

  template <typename U,
            typename enable_if<is_integral<U>::value>::type * = nullptr>
  RollingHash &operator+=(U rhs) {
    hs.push_back(mint_type(rhs) + hs.back() * (*cat.base));
    return *this;
  }

  template <
      typename Container,
      typename enable_if<HasInputIterator<Container>::value>::type * = nullptr>
  RollingHash &operator+=(const Container &rhs) {
    append(rhs.begin(), rhs.end());
    return *this;
  }

  inline void pop() {
    assert(size() > 0);
    hs.pop_back();
  }

  Hash prefix(int n) const {
    n = min(n, size());
    return Hash(hs[n], n);
  }

  Hash operator()(int i, int j) const {
    return Hash(hs[j + 1] - hs[i] * (cat.base->power(j - i + 1)), j - i + 1);
  }

  Hash suffix(int n) const {
    int sz = size();
    n = min(n, sz);
    return (*this)(sz - n, sz - 1);
  }

  pair<Hash, Hash> border(int n) const { return {prefix(n), suffix(n)}; }

  Hash substr(int i) const {
    i = min(i, size());
    return (*this)(i, size() - 1);
  }

  Hash substr(int i, int j) const { return (*this)(i, j); }

  Hash all() const { return Hash(hs.back(), size()); }

  friend int lcp(const type &lhs, const type &rhs) {
    int l = 0, r = min(lhs.size(), rhs.size());
    while (l < r) {
      int mid = (l + r) / 2;
      if (lhs.hs[mid + 1] != rhs.hs[mid + 1])
        r = mid;
      else
        l = mid + 1;
    }
    return l;
  }

  friend bool operator<(const type &lhs, const type &rhs) {
    int l = lcp(lhs, rhs);
    if (l == min(lhs.size(), rhs.size()))
      return lhs.size() < rhs.size();
    return lhs(l, l) < rhs(l, l);
  }
};

template <typename T, T... Mods> struct BidirectionalRollingHash {
  typedef RollingHash<T, Mods...> type;
  using Hash = typename type::Hash;
  using base_type = typename type::base_type;
  using Cat = typename type::Cat;

  type fwd, bwd;
  typename type::Cat cat;

  template <typename Container,
            typename enable_if<HasBidirectionalIterator<Container>::value>::type
                * = nullptr>
  BidirectionalRollingHash(const Container &container,
                           const shared_ptr<base_type> &base)
      : BidirectionalRollingHash<T, Mods...>(container.begin(), container.end(),
                                             base) {}

  template <typename Iterator,
            typename enable_if<IsBidirectionalIterator<Iterator>::value>::type
                * = nullptr>
  BidirectionalRollingHash(Iterator begin, Iterator end,
                           const shared_ptr<base_type> &base)
      : fwd(begin, end, base),
        bwd(make_reverse_iterator(end), make_reverse_iterator(begin), base),
        cat(base) {}

  inline Hash forward(int i, int j) const { return fwd(i, j); }

  inline Hash backward(int i, int j) const {
    int n = fwd.size();
    return bwd(n - j - 1, n - i - 1);
  }

  inline pair<Hash, Hash> operator()(int i, int j) const {
    return {forward(i, j), backward(i, j)};
  }
};

template <typename R> struct HashProvider {
  typedef R Roll;
  typedef typename R::base_type base_type;
  typedef typename R::Hash Hash;

  typename R::Cat cat;
  HashProvider() : cat(make_shared<base_type>()) {}
  explicit HashProvider(base_type base) : cat(make_shared<base_type>(base)) {}

  template <class... Args> R operator()(Args... args) {
    return R(args..., cat.base);
  }
};

template <typename R> struct PowerHashProvider : HashProvider<R> {
  using typename HashProvider<R>::base_type;
  using HashProvider<R>::cat;

  PowerHashProvider() : PowerHashProvider<R>(base_type()) {}
  PowerHashProvider(base_type base) : HashProvider<R>(base) {
    cat.base->set_max_powers(DEFAULT_MAX_POWERS);
  }
};

template <int32_t... Mods> using Roll32 = RollingHash<int32_t, Mods...>;

template <int64_t... Mods> using Roll64 = RollingHash<int64_t, Mods...>;

template <int32_t... Mods>
using Biroll32 = BidirectionalRollingHash<int32_t, Mods...>;

template <int64_t... Mods>
using Biroll64 = BidirectionalRollingHash<int64_t, Mods...>;

using DefaultProvider = PowerHashProvider<Roll32<GOOD_MOD1, GOOD_MOD2>>;
using BiDefaultProvider = PowerHashProvider<Biroll32<GOOD_MOD1, GOOD_MOD2>>;
} // namespace hashing
} // namespace lib

#endif
