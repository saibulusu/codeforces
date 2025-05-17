#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;

  string name;
  int score;

  for (int i = 0; i < n; ++i) {
    cin >> name >> score;
    cout << name << " " << score << endl;
  }

  return 0;
}
