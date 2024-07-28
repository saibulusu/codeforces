#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;

    int res = INT_MAX;
    for (int j = a; j < a + 16; ++j) {
      int zeroCount = min(16, __builtin_ctz(j));
      res = min(res, 16 - zeroCount + j - a);
    }
    cout << max(res - 1, 0) << " ";
  }
  cout << endl;

  return 0;
}
