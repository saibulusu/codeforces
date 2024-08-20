#include <iostream>

using namespace std;

unsigned long long int heights[40][40];

unsigned long long int max(unsigned long long int a, unsigned long long int b) {
  return a >= b ? a : b;
}

int main() {
  bool debug = false;

  int n, h;
  cin >> n >> h;

  for (int i = 0; i < 40; ++i) {
    for (int j = 0; j < 40; ++j) {
      heights[i][j] = 0;
    }
  }

  heights[0][0] = 1, heights[1][1] = 1;

  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      int left = j - 1, right = i - j;
      if (debug) {
        cout << "i = " << i << ", j = " << j << ", left = " << left
             << ", right = " << right << endl;
      }

      for (int l = 0; l <= left; ++l) {
        for (int r = 0; r <= right; ++r) {
          if (l >= r && l > 0) {
            heights[i][l + 1] += heights[left][l] * heights[right][r];
          } else if (r > l && r > 0) {
            heights[i][r + 1] += heights[left][l] * heights[right][r];
          }
          if (debug) {
            cout << "l = " << l << ", r = " << r << ", heights[" << left << "]["
                 << l << "] = " << heights[left][l] << ", heights[" << right
                 << "][" << r << "] = " << heights[right][r] << endl;
          }
        }
      }
    }
  }

  if (debug) {
    for (int i = 1; i <= n; ++i) {
      cout << i << ": ";
      for (int j = 1; j <= i; ++j) {
        cout << heights[i][j] << " ";
      }
      cout << endl;
    }
  }

  unsigned long long int res = 0;
  for (int j = h; j <= n; ++j) {
    res += heights[n][j];
  }

  cout << res << endl;

  return 0;
}
