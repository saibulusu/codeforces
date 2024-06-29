#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;

  int groups = 0;
  string prev = "00";

  for (int i = 0; i < n; ++i) {
    string cur;
    cin >> cur;

    if (prev != cur) {
      ++groups;
      prev = cur;
    }
  }

  cout << groups << endl;

  return 0;
}
