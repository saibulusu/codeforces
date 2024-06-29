#include <iostream>

using namespace std;

int main() {
  long long int n;
  cin >> n;

  long long int f = n % 2 == 0 ? (n + 1) / 2 : -1 * (n + 1) / 2;

  cout << f << endl;

  return 0;
}
