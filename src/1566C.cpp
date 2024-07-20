#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    int i = 0;
    int res = 0;

    while (true) {
      if (i >= n) {
        break;
      }

      if ((a[i] == '0' && b[i] == '1') || (a[i] == '0' && b[i] == '1')) {
        res += 2;
      } else if (a[i] == '0' && b[i] == '0') {
        if (i + 1 < n && a[i + 1] == '1' && b[i + 1] == '1') {
          res += 2;
          ++i;
        } else {
          res += 1;
        }
      } else {
        while (i < n && a[i] == '1' && b[i] == '1') {
          ++i;
        }
        if (i < n) {
          res += 2;
        }
      }
      ++i;
    }

    cout << res << endl;
  }

  return 0;
}
