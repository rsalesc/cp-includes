#ifndef _LIB_BITSET
#define _LIB_BITSET
#include <bits/stdc++.h>

namespace lib {
using namespace std;

namespace {
template <typename T> T maskout(size_t cnt, size_t n, T x) {
  size_t trailing = cnt - n;
  return x & ((~0) >> trailing);
}
} // namespace

template <typename T = uint64_t> struct Bitset {
  const static size_t B = sizeof(T) << 3;
  const static size_t BUCKET_SIZE = B;
  const static size_t SHIFT = 31 - __builtin_clz(B);
  const static size_t MASK = B - 1;

  size_t n, bucket_cnt;
  vector<T> v;

  Bitset(size_t n) : n(n), bucket_cnt((n + B - 1) >> SHIFT), v(bucket_cnt) {
    assert(bucket_cnt > 0);
  }

  void maskout_last() {
    size_t trailing = (bucket_cnt << SHIFT) - n;
    v.back() &= (~0) >> trailing;
  }

  void resize(size_t n) {
    this->n = n;
    size_t new_bucket_cnt = (n + B - 1) >> SHIFT;
    if (new_bucket_cnt != bucket_cnt)
      v.resize(new_bucket_cnt);
    bucket_cnt = new_bucket_cnt;
    maskout_last();
    assert(bucket_cnt > 0);
  }

  void extend_to(size_t nw) {
    return;
    if (nw > n)
      resize(nw);
  }

  inline int size() const { return n; }

  inline bool operator[](int pos) const { return test(pos); }

  inline bool test(size_t pos) const {
    return (v[pos >> SHIFT] >> (pos & MASK)) & (T)1;
  }

  Bitset<T> &set() {
    for (T &x : v)
      x = ~0;
    maskout_last();
    return *this;
  }

  Bitset<T> &reset() {
    for (T &x : v)
      x = 0;
    return *this;
  }

  Bitset<T> &flip() {
    for (T &x : v)
      x = ~x;
    maskout_last();
    return *this;
  }

  Bitset<T> &set(size_t pos) {
    assert(pos < n);
    v[pos >> SHIFT] |= ((T)1 << (pos & MASK));
    return *this;
  }

  Bitset<T> &reset(size_t pos) {
    assert(pos < n);
    v[pos >> SHIFT] &= ~((T)1 << (pos & MASK));
    return *this;
  }

  Bitset<T> &set(size_t pos, bool value) {
    if (!value)
      reset(pos);
    else
      set(pos);
    return *this;
  }

  Bitset<T> &flip(size_t pos) {
    assert(pos < n);
    v[pos >> SHIFT] ^= ((T)1 << (pos & MASK));
    return *this;
  }

  int count() const {
    size_t res = 0;
    for (size_t i = 0; i < bucket_cnt; i++)
      res += __builtin_popcountll((uint64_t)v[i]);
    return res;
  }

  bool any() const {
    for (size_t i = 0; i < bucket_cnt; i++)
      if (v[i])
        return true;
    return false;
  }

  bool none() const { return !any(); }

  bool all() const { return (~*this).none(); }

  Bitset<T> &operator|=(const Bitset<T> &rhs) {
    assert(n >= rhs.n);
    for (size_t i = 0; i < rhs.bucket_cnt; i++)
      v[i] |= rhs.v[i];
    return *this;
  }

  Bitset<T> &operator^=(const Bitset<T> &rhs) {
    assert(n >= rhs.n);
    for (size_t i = 0; i < rhs.bucket_cnt; i++)
      v[i] ^= rhs.v[i];
    return *this;
  }

  Bitset<T> &operator&=(const Bitset<T> &rhs) {
    assert(n >= rhs.n);
    for (size_t i = 0; i < rhs.bucket_cnt; i++)
      v[i] &= rhs.v[i];
    return *this;
  }

  void do_left_shift(size_t shift) {
    if (bucket_cnt == 0)
      return;
    int wshift = min(shift >> SHIFT, bucket_cnt);
    if (wshift < bucket_cnt) {
      int offset = shift & MASK;
      if (offset == 0) {
        for (int i = (int)bucket_cnt - 1; i >= wshift; i--) {
          v[i] = v[i - wshift];
        }
      } else {
        int sub_offset = B - offset;
        for (int i = (int)bucket_cnt - 1; i > wshift; i--) {
          v[i] =
              ((v[i - wshift] << offset) | (v[i - wshift - 1] >> sub_offset));
        }
        v[wshift] = v[0] << offset;
      }
    }
    fill(v.begin(), v.begin() + wshift, (T)0);
    maskout_last();
  }

  void do_right_shift(size_t shift) {
    if (bucket_cnt == 0)
      return;
    int wshift = min(shift >> SHIFT, bucket_cnt);
    int limit = (int)bucket_cnt - wshift - 1;

    if (wshift < bucket_cnt) {
      int offset = shift & MASK;

      if (offset == 0) {
        for (int i = 0; i <= limit; i++)
          v[i] = v[i + wshift];
      } else {
        int sub_offset = (int)B - offset;
        for (int i = 0; i < limit; i++) {
          v[i] =
              ((v[i + wshift] >> offset) | (v[i + wshift + 1] << sub_offset));
        }
        v[limit] = v[bucket_cnt - 1] >> offset;
      }
    }

    fill(v.begin() + (limit + 1), v.end(), (T)0);
  }

  Bitset<T> &operator<<=(size_t shift) {
    do_left_shift(shift);
    return *this;
  }

  Bitset<T> &operator>>=(size_t shift) {
    do_right_shift(shift);
    return *this;
  }

  Bitset<T> operator~() const {
    Bitset<T> res = *this;
    for (size_t i = 0; i < bucket_cnt; i++)
      res.v[i] = ~res.v[i];
    res.maskout_last();
    return res;
  }

  bool operator==(const Bitset<T> &rhs) const {
    if (n != rhs.n)
      return false;
    for (size_t i = 0; i < bucket_cnt; i++)
      if (v[i] != rhs.v[i])
        return false;
    return true;
  }

  bool operator!=(const Bitset<T> &rhs) const { return !(*this == rhs); }

  bool operator<(const Bitset<T>& rhs) const {
    int b = min(bucket_cnt, rhs.bucket_cnt);
    for(int i = 0; i < b; i++) {
      if(v[i] != rhs.v[i])
        return v[i] < rhs.v[i];
    }
    return n < rhs.n;
  }

  Bitset<T> operator|(const Bitset<T> &rhs) const {
    if (rhs.n > n)
      return Bitset<T>(rhs) |= *this;
    return Bitset<T>(*this) |= rhs;
  }

  Bitset<T> operator^(const Bitset<T> &rhs) const {
    if (rhs.n > n)
      return Bitset<T>(rhs) ^= *this;
    return Bitset<T>(*this) ^= rhs;
  }

  Bitset<T> operator&(const Bitset<T> &rhs) const {
    if (rhs.n > n)
      return Bitset<T>(rhs) &= *this;
    return Bitset<T>(*this) &= rhs;
  }

  Bitset<T> operator<<(size_t shift) const {
    return Bitset<T>(*this) <<= shift;
  }

  Bitset<T> operator>>(size_t shift) const {
    return Bitset<T>(*this) >>= shift;
  }

  friend ostream &operator<<(ostream &output, const Bitset<T> &rhs) {
    for (int i = (int)rhs.n - 1; i >= 0; i--)
      output << rhs[i];
    return output;
  }

  static Bitset<T> from_int(T x) {
    auto b = Bitset<T>(B);
    b.v[0] = x;
    return b;
  }
  
  T to_int() const {
    return v[0];
  }
};

using Bitset64 = Bitset<uint64_t>;
using Bitset32 = Bitset<uint32_t>;
} // namespace lib

#endif
