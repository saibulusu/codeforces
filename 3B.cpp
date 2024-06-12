#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, v;
  cin >> n >> v;

  // t - vehicle size, p - carrying capacity
  vector<int> t(n), p(n);

  for (int i = 0; i < n; ++i) {
    cin >> t[i] >> p[i];
  }

  return 0;
}
