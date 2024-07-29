#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  double numer = 0.0, denom = n * 100.0;
  for (int i = 1; i <= n; ++i) {
    int cur;
    cin >> cur;

    numer += cur;
  }

  cout << fixed << setprecision(12) << 100.0 * numer / denom << endl;

  return 0;
}
