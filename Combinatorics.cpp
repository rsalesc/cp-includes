#ifndef _LIB_COMBINATORICS
#define _LIB_COMBINATORICS
#include <bits/stdc++.h>
#include "BitTricks.cpp"

namespace lib {
using namespace std;
template<typename T>
struct Combinatorics {
    static vector<T> fat;
    static vector<T> inv;
    static vector<T> ifat;

    static T factorial(int i) {
        ensure_fat(next_power_of_two(i));
        return fat[i];
    }

    static T inverse(int i) {
        ensure_inv(next_power_of_two(i));
        return inv[i];
    }

    static T ifactorial(int i) {
        ensure_ifat(next_power_of_two(i));
        return ifat[i];
    }

    static T nCr(int n, int K) {
        if(K > n) return 0;
        ensure_fat(next_power_of_two(n));
        ensure_ifat(next_power_of_two(n));
        return fat[n] * ifat[n-K] * ifat[K];
    }

    static T arrangement(int n, int K) {
        return nCr(n, K) * factorial(n);
    }

    static T nCr_rep(int n, int K) {
        return interpolate(n - 1, K);
    }

    static T interpolate(int a, int b) {
        return nCr(a+b, b);
    }

    static void ensure_fat(int i) {
        int o = fat.size();
        if(i < o) return;
        fat.resize(i+1);
        for(int j = o; j <= i; j++) fat[j] = fat[j-1]*j;
    }

    static void ensure_inv(int i) {
        int o = inv.size();
        if(i < o) return;
        inv.resize(i+1);
        for(int j = o; j <= i; j++) inv[j] = -(inv[T::mod%j] * (T::mod/j));
    }

    static void ensure_ifat(int i) {
        int o = ifat.size();
        if(i < o) return;
        ifat.resize(i+1);
        ensure_inv(i);
        for(int j = o; j <= i; j++) ifat[j] = ifat[j-1]*inv[j];
    }
};

template<typename T>
vector<T> Combinatorics<T>::fat = vector<T>(1, T(1));
template<typename T>
vector<T> Combinatorics<T>::inv = vector<T>(2, T(1));
template<typename T>
vector<T> Combinatorics<T>::ifat = vector<T>(1, T(1));
} // namespace lib

#endif
