#include <iostream>

int main () {
  long long int n;
  std::cin >> n;

  long long int f = n % 2 == 0 ? (n + 1) / 2 : -1 * (n + 1) / 2;

  std::cout << f << std::endl;

  return 0;
}
