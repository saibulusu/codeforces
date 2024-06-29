#include <iostream>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  char president;
  cin >> n >> m >> president;

  vector<vector<char>> room;

  for (int i = 0; i < n; ++i) {
    vector<char> row;
    for (int j = 0; j < m; ++j) {
      char cur;
      cin >> cur;
      row.push_back(cur);
    }
    room.push_back(row);
  }

  int colors[26] = {};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (room[i][j] == president) {
        if (i > 0) {
          ++colors[room[i - 1][j] - 65];
        }
        if (j > 0) {
          ++colors[room[i][j - 1] - 65];
        }
        if (i < n - 1) {
          ++colors[room[i + 1][j] - 65];
        }
        if (j < m - 1) {
          ++colors[room[i][j + 1] - 65];
        }
      }
    }
  }

  int count = 0;
  for (int k = 0; k < 26; ++k) {
    if (president - 65 != k && colors[k] > 0) {
      ++count;
    }
  }

  cout << count << endl;

  return 0;
}
