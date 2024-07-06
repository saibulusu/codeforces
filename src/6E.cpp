#include <climits>
#include <iostream>
#include <map>

using namespace std;

int numNodes = 0;

// constructing a min-max segment tree
void constructTree(int input[], pair<int, int> tree[], int low, int high,
                   int pos) {
  ++numNodes;
  if (low == high) {
    tree[pos] = make_pair(input[low], input[low]);
  } else {
    int mid = (low + high) / 2;
    constructTree(input, tree, low, mid, 2 * pos + 1);
    constructTree(input, tree, mid + 1, high, 2 * pos + 2);
    tree[pos] =
        make_pair(min(tree[2 * pos + 1].first, tree[2 * pos + 2].first),
                  max(tree[2 * pos + 1].second, tree[2 * pos + 2].second));
  }
}

// query a range in the min-max segment tree
pair<int, int> rangeQuery(pair<int, int> tree[], int qLow, int qHigh, int low,
                          int high, int pos) {
  if (qLow <= low && high <= qHigh) {
    // total overlap
    return tree[pos];
  }
  if (qLow > high || qHigh < low) {
    // no overlap
    return make_pair(INT_MAX, INT_MIN);
  }
  // partial overlap
  int mid = (low + high) / 2;
  pair<int, int> left = rangeQuery(tree, qLow, qHigh, low, mid, 2 * pos + 1);
  pair<int, int> right =
      rangeQuery(tree, qLow, qHigh, mid + 1, high, 2 * pos + 2);
  return make_pair(min(left.first, right.first),
                   max(left.second, right.second));
}

int main() {
  bool debug = false;

  int n, k;
  cin >> n >> k;

  int books[n];

  // gather input
  for (int i = 0; i < n; ++i) {
    cin >> books[i];
  }

  // construct a min-max segment tree given the book heights
  pair<int, int> tree[4 * n];
  constructTree(books, tree, 0, n - 1, 0);

  if (debug) {
    cout << "segment tree contents: ";
    for (int i = 0; i < numNodes; ++i) {
      cout << tree[i].first << "," << tree[i].second << " ";
    }
    cout << endl;
  }

  // for each start point, find the furthest endpoint
  map<int, int> mp;
  int maxLength = 0;
  int res[n];

  for (int i = 0; i < n; ++i) {
    // using binay search for endpoint
    int j;
    int left = i, right = n;
    while (left <= right) {
      j = (left + right) / 2;
      if (j == i) {
        j = i + 1;
        break;
      }
      pair<int, int> prevRange = rangeQuery(tree, i, j - 1, 0, n - 1, 0);
      pair<int, int> curRange = make_pair(min(prevRange.first, books[j]),
                                          max(prevRange.second, books[j]));
      if (debug) {
        cout << "prevRange: " << i << " " << j - 1 << " " << prevRange.first
             << " " << prevRange.second << endl;
        cout << "curRange: " << i << " " << j << " " << curRange.first << " "
             << curRange.second << endl;
      }
      if (prevRange.second - prevRange.first > k) {
        right = j - 1;
      } else if (curRange.second - curRange.first <= k) {
        left = j + 1;
      } else {
        break;
      }
    }

    res[i] = j - i;
    ++mp[j - i];
    maxLength = max(maxLength, j - i);
  }

  cout << maxLength << " " << mp[maxLength] << endl;
  for (int i = 0; i < n; ++i) {
    if (res[i] == maxLength) {
      cout << (i + 1) << " " << (i + res[i]) << endl;
    }
  }

  return 0;
}
