#include <iostream>

using namespace std;

int main() {
  bool debug = false;

  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    pair<int, int> first = {0, 0};
    pair<int, int> second = {0, 0};

    int i;

    for (i = 0; i < 10; ++i) {
      pair<int, int> *cur, *other;
      if (i % 2 == 0) {
        cur = &first, other = &second;
      } else {
        other = &first, cur = &second;
      }

      if (s[i] == '1') {
        cur->first += 1, cur->second += 1;
      } else if (s[i] == '?') {
        cur->second += 1;
      }

      if (debug) {
        cout << "i = " << i << endl;
        cout << "cur = " << cur->first << "," << cur->second << endl;
        cout << "other = " << other->first << "," << other->second << endl;
      }

      int otherRemaining = (10 - i) / 2;
      int curRemaining = (9 - i) / 2;

      if (debug) {
        cout << "otherRemaining = " << otherRemaining << endl;
        cout << "curRemaining = " << curRemaining << endl;
        cout << endl;
      }

      if (cur->first + curRemaining < other->second ||
          other->first + otherRemaining < cur->second) {
        break;
      }
    }

    cout << min(10, i + 1) << endl;
  }

  return 0;
}
