#include <ios>
#include <iostream>

using namespace std;

int main() {
  string board[8];
  bool blackRows[8], blackCols[8];
  fill_n(blackRows, 8, true);
  fill_n(blackCols, 8, true);

  bool allBlack = true;

  for (int i = 0; i < 8; ++i) {
    cin >> board[i];
    for (int j = 0; j < 8; ++j) {
      if (board[i][j] == 'W') {
        blackRows[i] = false, blackCols[j] = false;
        allBlack = false;
      }
    }
  }

  int res = 0;
  for (int i = 0; i < 8; ++i) {
    res += blackRows[i];
    res += blackCols[i];
  }

  if (allBlack) {
    res = 8;
  }

  cout << res << endl;

  return 0;
}
