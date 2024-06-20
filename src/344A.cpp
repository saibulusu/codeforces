#include <iostream>
#include <string>

int main() {
  int n;
  std::cin >> n;

  int groups = 0;
  std::string prev = "00";

  for (int i = 0; i < n; ++i) {
    std::string cur;
    std::cin >> cur;

    if (prev != cur) {
      ++groups;
      prev = cur;
    }
  }

  std::cout << groups << std::endl;

  return 0;
}
