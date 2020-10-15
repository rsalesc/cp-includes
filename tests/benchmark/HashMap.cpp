#include "../../HashMap.cpp"

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int N = 4000000;
int64_t keys[N];

template <typename _Map> void test(const char *name) {
  srand(97);
  for (size_t i = 0; i < N; i++)
    keys[i] = (static_cast<int64_t>(rand()) << 48) ^
              (static_cast<int64_t>(rand()) << 32) ^ (rand() << 16) ^ rand();

  clock_t start_clock = clock();

  _Map m;

  for (size_t i = 0; i < N; i++)
    m[keys[i]] = keys[i] * keys[i];

  for (size_t i = 0; i < N; i++)
    assert(keys[i] * keys[i] == m[keys[i]]);

  for (size_t i = 0; i < N; i++) {
    m[keys[i]]++;
    // assert(m.count(keys[i] + 1) == 0);
  }

  cout << name << " takes "
       << ((clock() - start_clock) * 1000.0 / CLOCKS_PER_SEC) << endl;
}

template <typename _Map> void test2(const char *name) {
  srand(44);

  for (size_t i = 0; i < N; i++)
    keys[i] = (static_cast<int64_t>(rand()) << 48) ^
              (static_cast<int64_t>(rand()) << 32) ^ (rand() << 16) ^ rand();

  vector<int> p(2 * N);
  vector<bool> seen(N);
  iota(p.begin(), p.begin() + N, 0);
  iota(p.begin() + N, p.end(), 0);

  random_shuffle(p.begin(), p.end());

  clock_t start_clock = clock();
  _Map m;
  for (size_t i = 0; i < 2 * N; i++) {
    int x = p[i];
    if (!seen[x]) {
      seen[x] = true;
      m[keys[x]] = keys[x] * keys[x];
    } else {
      assert(m.erase(keys[x]));
      // assert(m.count(keys[x]) == 0);
    }
  }

  cout << name << " takes "
       << ((clock() - start_clock) * 1000.0 / CLOCKS_PER_SEC) << endl;
}

int main() {

  cout << "testing insertions" << endl;
  test<map<int64_t, int64_t>>("std::map");
  test<unordered_map<int64_t, int64_t>>("std::unordered_map");
  test<lib::GoldenMap<int64_t, int64_t>>("GoldenMap");
  test<lib::GpHashMap<int64_t>>("gp_hash_table");

  cout << endl;
  cout << "testing deletions" << endl;
  test2<map<int64_t, int64_t>>("std::map");
  test2<unordered_map<int64_t, int64_t>>("std::unordered_map");
  test2<lib::GoldenMap<int64_t, int64_t>>("GoldenMap");
  test2<lib::GpHashMap<int64_t>>("gp_hash_table");
}
