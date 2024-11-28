#include <iostream>

using namespace std;

int main() {
  int n, x, y, z;
  cin >> n;

  int X = 0, Y = 0, Z = 0;

  for (int i = 0; i < n; ++i) {
    cin >> x >> y >> z;
    X += x, Y += y, Z += z;
  }

  if (X == 0 && Y == 0 && Z == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
