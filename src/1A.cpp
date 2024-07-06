#include <cmath>
#include <iostream>

using namespace std;

int main() {
  double n, m, a;
  cin >> n >> m >> a;

  long long int l = ceil(n / a);
  long long int w = ceil(m / a);

  cout << l * w << endl;

  return 0;
}
