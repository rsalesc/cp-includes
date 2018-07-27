#ifndef _LIB_MODULAR_INTEGER
#define _LIB_MODULAR_INTEGER
#include <bits/stdc++.h>
#include "NumberTheory.cpp"

namespace lib {
  using namespace std;

  template<typename T, T ...Mods>
  struct ModularIntegerBase {
    typedef ModularIntegerBase<T, Mods...> type;

    T x[sizeof...(Mods)];
  };

  template<typename T, T Mod>
  struct ModularIntegerBase<T, Mod> {
    typedef ModularIntegerBase<T, Mod> type;

    T x[1];

    operator T() const { return this->x[0]; }
    friend ostream& operator<<(ostream& output, const type& var) {
      return output << var.x[0];
    }
  };


  template<typename T, T ...Mods>
  struct ModularInteger : ModularIntegerBase<T, Mods...> {
    typedef ModularInteger<T, Mods...> type;
    typedef int64_t large_int;

    constexpr static T mods[sizeof...(Mods)] = {Mods...};
    using ModularIntegerBase<T, Mods...>::x;

    ModularInteger() {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] = T();
    }
    ModularInteger(T y) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] = y;
      normalize();
    }

    void normalize() {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        if((x[i] %= mods[i]) < 0)
          x[i] += mods[i];
    }
    T multiply(T x, T y, T mod) {
      return (large_int)x*y % mod;
    }
    
    template<typename U>
    T power(T x, U p, T mod) {
      if(mod == 1) return T();
      if(p < 0) {
        if(x == 0)
          throw domain_error("0^p with negative p is invalid");
        p = -p, x = inv(x, mod);
      }
      if(p == 0) return 1;
      if(p == 1) return x;
      T res = 1;
      while(p > 0) {
        if(p&1)
          res = multiply(res, x, mod);
        p >>= 1;
        x = multiply(x, x, mod);
      }
      return res;
    }

    T inv(T x, T mod) {
      return nt::inverse(x, mod);
    }

    type operator+=(const type& rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        (x[i] += rhs.x[i]) %= mods[i];
      return *this;
    }
    type operator-=(const type& rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        if((x[i] -= rhs.x[i]) < 0)
          x[i] += mods[i];
      return *this;
    }
    type operator*=(const type& rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] = multiply(x[i], rhs.x[i], mods[i]);
      return *this;
    }
    type operator/=(const type& rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] = multiply(x[i], inv(rhs.x[i], mods[i]), mods[i]);
      return *this;
    }

    template<typename U>
    type operator+=(U rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] += rhs;
      normalize();
      return *this;
    }
    template<typename U>
    type operator-=(U rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] -= rhs;
      normalize();
      return *this;
    }
    template<typename U>
    type operator*=(U rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] = multiply(x[i], rhs, mods[i]);
      return *this;
    }
    template<typename U>
    type operator/=(U rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] = multiply(inv(rhs, mods[i]), rhs, mods[i]);
      return *this;
    }

    template<typename U>
    type operator^=(U p) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] = power(x[i], p, mods[i]);
      return *this;
    }

    type operator++() {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        if((++x[i]) >= mods[i])
          x[i] -= mods[i];
      return *this;
    }
    type operator--() {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        if((--x[i]) < 0)
          x[i] += mods[i];
      return *this;
    }
    type operator++(int unused) { type res = *this; ++(*this); return res; }
    type operator--(int unused) { type res = *this; --(*this); return res; }

    friend type operator+(const type& lhs, const type& rhs) {
      return type(lhs) += rhs;
    }
    friend type operator-(const type& lhs, const type& rhs) {
      return type(lhs) -= rhs;
    }
    friend type operator*(const type& lhs, const type& rhs) {
      return type(lhs) *= rhs;
    }
    friend type operator/(const type& lhs, const type& rhs) {
      return type(lhs) /= rhs;
    }

    template<typename U>
    friend type operator+(const type& lhs, U rhs) {
      return type(lhs) += rhs;
    }
    template<typename U>
    friend type operator-(const type& lhs, U rhs) {
      return type(lhs) -= rhs;
    }
    template<typename U>
    friend type operator*(const type& lhs, U rhs) {
      return type(lhs) *= rhs;
    }
    template<typename U>
    friend type operator/(const type& lhs, U rhs) {
      return type(lhs) /= rhs;
    }
    template<typename U>
    friend type operator^(const type& lhs, U rhs) {
      return type(lhs) ^= rhs;
    }

    friend type operator==(const type& lhs, const type& rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        if(lhs.x[i] != rhs.x[i])
          return false;
      return true;
    }
    friend type operator!=(const type& lhs, const type& rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        if(lhs.x[i] != rhs.x[i])
          return true;
      return false;
    }
    friend type operator<(const type& lhs, const type& rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        if(lhs.x[i] != rhs.x[i])
          return lhs.x[i] < rhs.x[i];
      return false;
    }

    friend istream& operator>>(istream& input, type& var) {
      T y; cin >> y;
      var = y;
      return input;
    }
  };
  
  template<int32_t ...Mods>
  using Mint32 = ModularInteger<int32_t, Mods...>;

  template<int64_t ...Mods>
  using Mint64 = ModularInteger<int64_t, Mods...>;
}  // namespace lib

#endif
