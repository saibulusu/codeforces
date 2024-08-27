#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int n, d;
  cin >> n >> d;

  int res = 0;
  int prev = 0, cur;
  for (int i = 0; i < n; ++i) {
    cin >> cur;

    if (cur <= prev) {
      int added = ceil((double)(prev + 1 - cur) / (double)d);
      cur += added * d;
      res += added;
    }
    prev = cur;
  }

  cout << res << endl;

  return 0;
}
