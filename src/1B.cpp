#include <cmath>
#include <iostream>
#include <string>

using namespace std;

string toXY(string input);
string toRC(string input);

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    string input;
    cin >> input;

    int rLoc = input.find('R'), cLoc = input.find('C');

    if (rLoc != string::npos && cLoc != string::npos) {
      if (rLoc < cLoc && 48 <= (int)input[rLoc + 1] &&
          (int)input[rLoc + 1] <= 57) {
        cout << toXY(input) << endl;
      } else {
        cout << toRC(input) << endl;
      }
    } else {
      cout << toRC(input) << endl;
    }
  }

  return 0;
}

string toRC(string input) {
  string theColumn = "", theRow = "";

  for (int i = 0; i < input.size(); ++i) {
    if (48 <= input[i] && input[i] <= 57) {
      theRow += input[i];
    } else {
      theColumn += input[i];
    }
  }

  long col = 0, row = stoul(theRow);

  for (int i = theColumn.size() - 1; i >= 0; i--) {
    col += pow(26, theColumn.size() - i - 1) * (theColumn[i] - 'A' + 1);
  }
  theColumn = to_string(col);
  theRow = to_string(row);

  return "R" + theRow + "C" + theColumn;
}

string toXY(string input) {
  long row = stoul(input.substr(1, input.find('C')));
  long col = stoul(input.substr(input.find('C') + 1));

  string theRow = to_string(row);
  string theCol = "";

  long array[6];

  for (int i = 5; i >= 0; i--) {
    array[i] = col / (long)(pow(26, i));
    col %= (long)(pow(26, i));
  }

  for (int i = 0; i < 5; i++) {
    if (array[i] == 0 && array[i + 1] != 0) {
      int j = i;
      while (j >= 0) {
        if (array[j] == 0 && array[j + 1] != 0) {
          array[j] = 26;
          array[j + 1]--;
        } else {
          break;
        }
        j--;
      }
    }
  }

  for (int i = 5; i >= 0; i--) {
    if (array[i] != 0) {
      theCol += (char)(array[i] + 'A' - 1);
    }
  }

  return theCol + theRow;
}
