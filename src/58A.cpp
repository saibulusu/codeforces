#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;

  string hello = "hello";
  int j = 0;

  for (int i = 0; i < s.size(); ++i) {
    if (hello[j] == s[i]) {
      ++j;
      if (j == 5) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }

  cout << "NO" << endl;

  return 0;
}
