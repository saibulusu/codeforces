#include <iostream>

using namespace std;

int powers[513];

void fillPowers() {
  powers[0] = 0, powers[1] = 1;
  int base = 10;
  int j = 2;

  while (base < 1000000000) {
    int i = 0;
    for (; i < j; ++i) {
      powers[j + i] = base + powers[i];
    }

    j += i;
    base *= 10;
  }

  powers[512] = 1000000000;
}

int main() {
  int n;
  cin >> n;

  fillPowers();

  int i = 0;
  for (; i < 513; ++i) {
    if (powers[i] > n) {
      break;
    }
  }
  cout << i - 1 << endl;

  return 0;
}
