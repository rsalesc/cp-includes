#include <bits/stdc++.h>
#include "../../Bitset.cpp"

using namespace std;

typedef lib::Bitset32 Bitset;

template<int N>
bool compare(const bitset<N>& std_bs, const Bitset& lib_bs) {
  for(int i = 0; i < N; i++)
    if(std_bs[i] != lib_bs[i])
      return false;
  return true;
}

template<int N>
pair<bitset<N>, Bitset> random() {
  bitset<N> std_bs;
  Bitset lib_bs(N);
  
  for(int i = 0; i < N; i++) {
    int x = rand()%2;
    std_bs.set(i, x);
    lib_bs.set(i, x);
  }

  if(!compare<N>(std_bs, lib_bs))
    throw logic_error("difference in assignment");

  return {std_bs, lib_bs};
}

template<typename A>
void benchmark_one(const A& bs, int n) {
  A a = bs;
  a = bs ^ (bs >> (n/2));
  a = bs | (bs << (n/2));
  a = bs ^ bs;
  a = bs | bs;
  a = bs & bs;
  a <<= (n/16);
  a >>= (n/16);
  a = ~bs;

  for(int i = 0; i < n; i += 2)
    bool x = a[i];
  for(int i = 1; i < n; i += 3)
    a.reset(i);
  for(int i = 2; i < n; i += 5)
    a.set(i);

  int x = a.count();
  bool y = a.any();
  bool z = a.none();
  bool w = a.all();
  a = a.flip();
  a = a.set();
  a = a.reset();
}

template<typename A>
void benchmark_all(const vector<A>& v, int n, string name) {
  clock_t start_clock = clock();
  for(const A& a : v)
    benchmark_one(a, n);
  cout << name << " takes " << ((clock() - start_clock) * 1000.0 / CLOCKS_PER_SEC) << endl;
}

template<int N>
void benchmark(int samples) {
  cout << "Benchmarking for n = " << N << endl;

  vector<bitset<N>> va;
  vector<Bitset> vb;
  for(int i = 0; i < samples; i++) {
    auto p = random<N>();
    va.push_back(p.first);
    vb.push_back(p.second);
  }

  benchmark_all(va, N, "bitset<>");
  benchmark_all(vb, N, "lib::Bitset64");
}

template<int N>
void test() {
  for(int i = 0; i < 50; i++) {
    auto p = random<N>();
    auto q = random<N>();

    if(!compare<N>(p.first ^ q.first, p.second ^ q.second))
      throw logic_error("difference in binary xor");

    if(!compare<N>(p.first | q.first, p.second | q.second))
      throw logic_error("difference in binary or");

    if(!compare<N>(p.first & q.first, p.second & q.second))
      throw logic_error("difference in binary and");

    if(!compare<N>(~p.first, ~p.second))
      throw logic_error("difference in unary negation");

    for(int j = 0; j < 7; j++) {
      int sz = rand() % (2*N);
      if(!compare<N>(p.first << sz, p.second << sz))
        throw logic_error("difference on left shift");

      if(!compare<N>(p.first >> sz, p.second >> sz))
        throw logic_error("difference on right shift");
    }
  }
}

int main() {
  test<1>();
  test<2>();
  test<4>();
  test<8>();
  test<(1<<16)>();
  test<129831>();
  
  benchmark<129831>(10000);
}
