#include <iostream>

using namespace std;

int main() {
  string matrix[3];
  cin >> matrix[0] >> matrix[1] >> matrix[2];

  if (matrix[0][0] != matrix[2][2] || matrix[0][1] != matrix[2][1] ||
      matrix[0][2] != matrix[2][0] || matrix[1][0] != matrix[1][2]) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }

  return 0;
}
