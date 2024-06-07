#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  string path;
  cin >> path;

  // point -> id
  map<pair<int, int>, int> covered;

  int x = 0, y = 0;

  for (int i = 0; i < path.size(); ++i) {
    pair prev = make_pair(x, y);
    char move = path[i];

    if (move == 'U') {
      ++y;
    } else if (move == 'R') {
      ++x;
    } else if (move == 'D') {
      --y;
    } else if (move == 'L') {
      --x;
    }

    pair cur = make_pair(x, y);
    // if current point is covered, BUG
    if (covered.find(cur) != covered.end()) {
      cout << "BUG" << endl;
      return 0;
    }

    pair up = make_pair(x, y + 1);
    pair down = make_pair(x, y - 1);
    pair right = make_pair(x + 1, y);
    pair left = make_pair(x - 1, y);
    // if any surrounding point is covered, BUG
    if (covered.find(up) != covered.end() ||
        covered.find(down) != covered.end() ||
        covered.find(right) != covered.end() ||
        covered.find(left) != covered.end()) {
      cout << "BUG" << endl;
      return 0;
    }

    // add previous point to map now
    covered[prev] = i;
  }

  cout << "OK" << endl;
  return 0;
}
