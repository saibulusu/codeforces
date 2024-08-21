#include <iostream>

using namespace std;

int n, k;
int seats[100][100];
int taken[100][100];

void processRequest(int m) {
  int res = INT_MAX;
  int optX = -1, optY = -1;

  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= k; ++j) {
      if (j + m - 1 <= k) {
        int value = 0;
        bool valid = true;
        for (int z = j; z <= j + m - 1; ++z) {
          value += seats[i][z];
          valid = valid && taken[i][z];
        }

        if (valid && value < res) {
          res = value;
          optX = i, optY = j;
        }
      }
    }
  }

  if (optX == -1) {
    cout << "-1" << endl;
  } else {
    for (int j = optY; j <= (optY + m - 1); ++j) {
      taken[optX][j] = false;
    }
    cout << optX << " " << optY << " " << (optY + m - 1) << endl;
  }
}

int main() {
  cin >> n >> k;

  int xc = (k + 1) / 2, yc = xc;
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= k; ++j) {
      seats[i][j] = abs(i - xc) + abs(j - yc);
      taken[i][j] = true;
    }
  }

  int m;
  for (int i = 0; i < n; ++i) {
    cin >> m;

    processRequest(m);
  }

  return 0;
}
