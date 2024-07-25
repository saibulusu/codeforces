#include <iostream>

using namespace std;

int n;
int dp[1 << 15];
int angles[15];

int main() {
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> angles[i];
  }

  for (int bitMask = 0; bitMask < (1 << n); ++bitMask) {
    int sum = 0;
    for (int j = 0; j < n; ++j) {
      if (bitMask & (1 << j)) {
        sum -= angles[j];
      } else {
        sum += angles[j];
      }
    }

    sum %= 360;
    if (sum == 0) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  return 0;
}
