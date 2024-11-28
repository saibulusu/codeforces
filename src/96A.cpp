#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;

  char curChar = s[0];
  int curLen = 0;

  for (int i = 0; i < s.size(); ++i) {
    if (curLen == 7) {
      cout << "YES" << endl;
      return 0;
    }

    if (s[i] == curChar) {
      ++curLen;
    } else {
      curLen = 1;
      curChar = s[i];
    }
  }
  if (curLen == 7) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
