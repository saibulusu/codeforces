#include <iostream>
#include <cmath>

using namespace std;

#define llu unsigned long long int

int main() {
  llu n, m, a;
  cin >> n >> m >> a;

  cout << ((n + a - 1) / a) * ((m + a - 1) / a) << endl;

  return 0;
}
