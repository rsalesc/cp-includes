#include <bits/stdc++.h>
#include "../../SegtreeBeats.cpp"
#define int long long

using namespace std;
using namespace lib;

struct Data {
  int x, mx, mn, lz;
  Data() : lz(-1) {}
  Data(int x) : x(x), mx(x), mn(x), lz(-1) {}
};

struct Pushdown {
  void operator()(Data& no, int l, int r, Data* ln, Data* rn) const {
    if(no.lz == -1) return;
    if(l != r) {
      ln->lz = no.lz;
      rn->lz = no.lz;
    }
    no.mx = no.mn = no.lz;
    no.x = no.lz * (r-l+1);
    no.lz = -1;
  }
};

struct Combiner {
  Data operator()(const Data& a, const Data& b) const {
    Data data;
    data.x = a.x + b.x;
    data.mx = max(a.mx, b.mx);
    data.mn = min(a.mn, b.mn);
    return data;
  }
};

struct Folder : seg::CombineFolder<int> {
  using seg::CombineFolder<int>::operator();
  int operator()(const Data& no) const { return no.x; }
  int operator()(const Data& a, const Data& b) const { return a.x+b.x; }
};

struct ModBeater {
  int mod;
  bool stop(const Data& no, int l, int r, int i, int j) const {
    return no.mx < mod; 
  }
  bool tag(const Data& no, int l, int r, int i, int j) const {
    return no.mx == no.mn;
  }
  void operator()(Data& no) const {
    no.lz = no.mx % mod;
  }
};

struct SetTagger {
  int x;
  void operator()(Data& no) const {
    no.lz = x;
  }
};

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;

  vector<int> p;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    p.push_back(x);
  }

  seg::SegtreeBeats<Data, Combiner, Pushdown> tree(seg::make_builder(p));
  Folder folder;

  for(int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if(t == 1) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      cout << tree.query<int>(x, y, folder) << "\n";
    } else if(t == 2) {
      int x, y, mod;
      cin >> x >> y >> mod;
      x--, y--;
      ModBeater beater = {mod};
      tree.beat(x, y, beater);
    } else if(t == 3) {
      int x, v;
      cin >> x >> v;
      x--;
      SetTagger tagger = {v};
      tree.update(x, x, tagger);
    }
  }
}

