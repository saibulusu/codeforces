#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;

    if (c == '1') {
      cout << "HARD" << endl;
      return 0;
    }
  }

  cout << "EASY" << endl;

  return 0;
}
