#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  int a, b;

  while (t--) {
    cin >> a >> b;

    if (a % b == 0) {
      cout << 0 << endl;
    } else {
      int lower = a / b;
      cout << (lower + 1) * b - a << endl;
    }
  }
}
