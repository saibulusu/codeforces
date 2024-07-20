#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    string s;
    cin >> s;

    int res = 0;
    bool counting = false;
    for (int j = 0; j < s.size(); ++j) {
      if (s[j] == '0') {
        if (!counting) {
          counting = true;
          ++res;
        }
      } else {
        counting = false;
      }
    }

    res = min(res, 2);
    cout << res << endl;
  }

  return 0;
}
