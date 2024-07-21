// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

string solve() {
  int n;
  cin >> n;

  vector<int> c;
  for (int i = 0; i < n; ++i) {
    int element;
    cin >> element;

    c.push_back(element);
  }

  sort(c.begin(), c.end());

  if (c[0] != 1) {
    return "NO";
  } else {
    long long sum = c[0];
    for (int i = 1; i < n; ++i) {
      if (sum < c[i]) {
        return "NO";
      }
      sum += c[i];
    }

    return "YES";
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
