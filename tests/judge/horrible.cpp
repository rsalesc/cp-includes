#include <bits/stdc++.h>
#include "../../SegtreeBeats.cpp"
#define int long long

using namespace std;
using namespace lib;

struct Data {
  int x, lz;
  Data() : x(0), lz(0) {}
  Data(int x) : x(x), lz(0) {}
  Data& operator+=(int y) { this->lz += y; return *this; }
};

struct PushdownSum {
  void operator()(Data& no, int l, int r, Data* ln, Data* rn) const {
    if(l != r) {
      ln->lz += no.lz;
      rn->lz += no.lz;
    }
    no.x += no.lz * (r-l+1);
    no.lz = 0;
  }
};

Data operator+(const Data& a, const Data& b) {
  return {a.x + b.x};
}

int32_t main() {
  int T; cin >> T;
  while(T--) {
    int n;
    cin >> n;

    auto builder = seg::make_builder(n);
    seg::SegtreeBeats<Data, seg::SumFolder<Data>, PushdownSum> tree(builder);
    seg::SumFolder<Data> folder;

    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
      int t;
      cin >> t;
      if(t == 1) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        cout << tree.query<Data>(x, y, folder).x << endl;
      } else {
        int x, y, v;
        cin >> x >> y >> v;
        x--, y--;
        tree.update(x, y, seg::AddUpdater<int>(v));
      }
    }
  }
}

