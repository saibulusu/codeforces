#include <iostream>

using namespace std;

int power(int x, int exp) {
  if (x == 0) {
    return -1;
  }
  int res = 0;
  while (x % exp == 0) {
    ++res;
    x /= exp;
  }

  return res;
}

int main() {
  bool debug = false;

  int n;
  cin >> n;

  int dp[n][n][2];
  pair<int, int> fallBack = make_pair(-1, -1);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int number;
      cin >> number;

      if (number == 0) {
        fallBack.first = i, fallBack.second = j;
      }

      int pow2 = power(number, 2), pow5 = power(number, 5);
      dp[i][j][0] = pow2, dp[i][j][1] = pow5;

      if (i > 0 && j == 0) {
        if (dp[i - 1][j][0] == -1) {
          dp[i][j][0] = -1, dp[i][j][1] = -1;
        } else {
          dp[i][j][0] += dp[i - 1][j][0], dp[i][j][1] += dp[i - 1][j][1];
        }
      } else if (i == 0 && j > 0) {
        if (dp[i][j - 1][0] == -1) {
          dp[i][j][0] = -1, dp[i][j][1] = -1;
        } else {
          dp[i][j][0] += dp[i][j - 1][0], dp[i][j][1] += dp[i][j - 1][1];
        }
      } else if (i > 0 && j > 0) {
        if (dp[i][j - 1][0] == -1 && dp[i - 1][j][0] == -1) {
          dp[i][j][0] = -1, dp[i][j][1] = -1;
        } else if (dp[i - 1][j][0] == -1) {
          dp[i][j][0] += dp[i - 1][j][0], dp[i][j][1] += dp[i - 1][j][1];
        } else if (dp[i][j - 1][0] == -1) {
          dp[i][j][0] += dp[i][j - 1][0], dp[i][j][1] += dp[i][j - 1][1];
        } else {
          if (dp[i - 1][j][0] <= dp[i][j - 1][0]) {
            dp[i][j][0] += dp[i - 1][j][0];
          } else {
            dp[i][j][0] += dp[i][j - 1][0];
          }

          if (dp[i - 1][j][1] <= dp[i][j - 1][1]) {
            dp[i][j][1] += dp[i - 1][j][1];
          } else {
            dp[i][j][1] += dp[i][j - 1][1];
          }
        }
      }
    }
  }

  if (debug) {
    cout << "dp" << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << dp[i][j][0] << "," << dp[i][j][1] << " ";
      }
      cout << endl;
    }
  }

  if (dp[n - 1][n - 1][0] == -1 ||
      (fallBack.first != -1 && dp[n - 1][n - 1][0] > 1 &&
       dp[n - 1][n - 1][1] > 1)) {
    cout << 1 << endl;
    for (int i = 0; i < fallBack.first; ++i) {
      cout << "D";
    }
    for (int j = 0; j < fallBack.second; ++j) {
      cout << "R";
    }
    for (int i = 0; i < n - 1 - fallBack.first; ++i) {
      cout << "D";
    }
    for (int j = 0; j < n - 1 - fallBack.second; ++j) {
      cout << "R";
    }
    cout << endl;
  } else {
    int lower;
    if (dp[n - 1][n - 1][0] <= dp[n - 1][n - 1][1]) {
      lower = 0;
    } else {
      lower = 1;
    }

    if (debug) {
      cout << "lower = " << lower << endl;
    }

    cout << dp[n - 1][n - 1][lower] << endl;

    char res[2 * (n - 1)];
    int cur = 2 * (n - 1) - 1;
    int i = n - 1, j = n - 1;
    while (cur >= 0) {
      if (i == 0) {
        res[cur] = 'R';
        --j;
      } else if (j == 0) {
        res[cur] = 'D';
        --i;
      } else {
        if (dp[i - 1][j][lower] <= dp[i][j - 1][lower]) {
          res[cur] = 'D';
          --i;
        } else {
          res[cur] = 'R';
          --j;
        }
      }
      --cur;
    }

    for (int k = 0; k < 2 * (n - 1); ++k) {
      cout << res[k];
    }
    cout << endl;
  }

  return 0;
}
