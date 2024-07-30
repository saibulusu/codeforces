#include <iostream>

using namespace std;

int main() {
  int s[4];

  int colors = 0;
  for (int i = 0; i < 4; ++i) {
    cin >> s[i];

    bool unique = true;
    for (int j = 0; j < i; ++j) {
      if (s[i] == s[j]) {
        unique = false;
      }
    }
    colors += unique ? 1 : 0;
  }

  cout << 4 - colors << endl;

  return 0;
}
