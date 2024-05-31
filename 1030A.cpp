#include <string>
#include <iostream>
#include <map>
#include <vector>

int main () {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    char c;
    std::cin >> c;

    if (c == '1') {
      std::cout << "HARD" << std::endl;
      return 0;
    }
  }
      
  std::cout << "EASY" << std::endl;

  return 0;
}
