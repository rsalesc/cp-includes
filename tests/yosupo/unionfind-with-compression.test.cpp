#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "dsu/DSU.cpp"
#include "dsu/Compress.cpp"

#include "Template.cpp"

int32_t main() {
  iopt;

  int n, Q;
  cin >> n >> Q;

  using UF = lib::dsu::ByRank<lib::dsu::Compress>;

  UF uf(n);

  for(int i = 0; i < Q; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    if(t == 0) uf.merge(a, b);
    else cout << (int)(uf[a] == uf[b]) << endl;
  }
}