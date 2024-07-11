#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

int n;
double a[19][19];
double dp[1 << 19];

double pMove(int prevMask, int j) {
  // get number of alive fish
  int k = __builtin_popcount(prevMask);

  double denominator = (double)k * ((double)k - 1) / 2;
  double numerator = 0.0;

  for (int fish = 0; fish < n; ++fish) {
    if ((1 << fish) & prevMask) {
      numerator += a[fish + 1][j + 1];
    }
  }

  return numerator / denominator;
}

double recurse(int bitMask) {
  // get number of alive fish (set bits)
  int alive = __builtin_popcount(bitMask);

  if (alive == n) {
    return dp[bitMask] = 1.0;
  }
  if (dp[bitMask] > -0.9) {
    return dp[bitMask];
  } else {
    double answer = 0.0;
    // for each dead fish, consider the probability of it dying one day ago
    for (int fish = 0; fish < n; ++fish) {
      if (!(bitMask & (1 << fish))) {
        int prevMask = bitMask ^ (1 << fish);
        double prevDay = recurse(prevMask);
        answer += prevDay * pMove(prevMask, fish);
      }
    }

    return dp[bitMask] = answer;
  }
}

int main() {
  cin >> n;

  memset(dp, -1.0, sizeof(dp));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << fixed << setprecision(6) << recurse(1 << i) << " ";
  }
  cout << endl;

  return 0;
}
