#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int pascal[11][11];

void fill_pascal() {
  pascal[0][0] = 1;
  for (int row = 1; row <= 10; ++row) {
    pascal[row][0] = 1;
    for (int col = 1; col <= row; ++col) {
      pascal[row][col] = pascal[row - 1][col - 1] + pascal[row - 1][col];
    }
  }
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  fill_pascal();

  int expected = 0;
  for (int i = 0; i < s1.size(); ++i) {
    expected += s1[i] == '+' ? 1 : -1;
  }
  int actual = 0, q = 0;
  for (int i = 0; i < s2.size(); ++i) {
    if (s2[i] == '?') {
      ++q;
    } else {
      actual += s2[i] == '+' ? 1 : -1;
    }
  }

  // cout << "expected = " << expected << ", actual = " << actual << ", q = " <<
  // q << endl;

  double denom = 0.0, numer = 0.0;
  int choose = 0;
  for (int i = actual - q; i <= actual + q; i += 2) {
    int count = pascal[q][choose];
    denom += count;
    numer += expected == i ? count : 0;
    ++choose;

    // cout << "i = " << i << ", numer = " << numer << ", denom = " << denom <<
    // endl;
  }

  cout << std::fixed << std::setprecision(12) << numer / denom << endl;

  return 0;
}
