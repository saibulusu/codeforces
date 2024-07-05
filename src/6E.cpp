#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<pair<int, int>> tree;

void build(vector<int> *books, int v, int tl, int tr) {
  if (tl == tr) {
    tree[v] = make_pair((*books)[tl], (*books)[tl]);
  } else {
    int tm = (tl + tr) / 2;
    build(books, v * 2, tl, tm);
    build(books, v * 2 + 1, tm + 1, tr);
    pair<int, int> left = tree[v * 2];
    pair<int, int> right = tree[v * 2 + 1];
    tree[v] =
        make_pair(min(left.first, right.first), max(left.second, right.second));
  }
}

pair<int, int> range(int v, int tl, int tr, int l, int r) {
  if (l > r) {
    return make_pair(-1, 10000000);
  }
  if (l == tl && r == tr) {
    return tree[v];
  }
  int tm = (tl + tr) / 2;
  pair<int, int> left = range(v * 2, tl, tm, l, min(r, tm));
  pair<int, int> right = range(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);

  return make_pair(min(left.first, right.first),
                   max(left.second, right.second));
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> books;

  for (int i = 0; i < n; ++i) {
    int cur;
    cin >> cur;
    books.push_back(cur);
  }

  tree.reserve(4 * n);
  build(&books, 1, 0, n - 1);

  pair<int, int> res = range(1, 1, 2, 0, 2);
  cout << res.first << " " << res.second << endl;
}
