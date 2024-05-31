#include <string>
#include <iostream>
#include <map>
#include <vector>

int main () {
  int n;
  std::cin >> n;

  int res = 0;
  for (int i = 0; i < n; ++i) {
    int p, q;
    std::cin >> p >> q;

    if (p + 2 <= q) {
      ++res;
    }
  }

  std::cout << res << std::endl;
  return 0;
}
