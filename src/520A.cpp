#include <cstring>
#include <iostream>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  bool map[26];
  memset(map, false, 26 * sizeof(bool));

  for (int i = 0; i < n; ++i) {
    if ((int)s[i] >= 97) {
      map[(int)s[i] - 97] = true;
    } else {
      map[(int)s[i] - 65] = true;
    }
  }

  bool covered = true;
  for (int i = 0; i < 26; ++i) {
    covered &= map[i];
  }

  if (covered) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
