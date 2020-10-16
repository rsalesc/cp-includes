#include "../../Treap.cpp"
#include <bits/stdc++.h>

using namespace std;
using namespace lib::treap;

using Treap = TreapManager<int>;
using vnode = Treap::vnode;

vnode insert(Treap &treap, vnode no, int x) {
  auto &manager = treap.manager;

  if (manager.has(no))
    cout << "EPA " << manager.value(no).key << endl;
  auto [left, right] = treap.split_on_key(no, x);
  if (manager.has(left))
    cout << "LEFT " << manager.value(left).key << endl;
  if (manager.has(right))
    cout << "RIGHT " << manager.value(right).key << endl;

  auto res = treap.merge(left, treap.make(x));
  return treap.merge(res, right);
}

int32_t main() {
  Treap treap;

  vnode root = treap.null();
  root = insert(treap, root, 3);
  root = insert(treap, root, 5);
  root = insert(treap, root, 8);
  root = insert(treap, root, 4);

  auto res =
      treap.bsearch_last(root, [](Treap::tnode no, Treap::tnode *,
                                  Treap::tnode *) { return no.key < 5; });

  cout << res.found << " " << res.node.key << endl;
}
