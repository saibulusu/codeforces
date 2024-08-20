#include <iostream>

using namespace std;

int periods[100][2];

int main() {
  int n, p1, p2, p3, t1, t2;
  cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;

  int res = 0;

  for (int i = 0; i < n; ++i) {
    cin >> periods[i][0] >> periods[i][1];

    res += (periods[i][1] - periods[i][0]) * p1;
    if (i > 0) {
      if (periods[i - 1][1] + t1 + t2 <= periods[i][0]) {
        res += t1 * p1 + t2 * p2 +
               (periods[i][0] - periods[i - 1][1] - t1 - t2) * p3;
      } else if (periods[i - 1][1] + t1 <= periods[i][0]) {
        res += t1 * p1 + (periods[i][0] - periods[i - 1][1] - t1) * p2;
      } else {
        res += (periods[i][0] - periods[i - 1][1]) * p1;
      }
    }
  }

  cout << res << endl;

  return 0;
}
