#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string n, m;
  cin >> n >> m;

  sort(n.begin(), n.end());

  int i;
  for (i = 0; i < n.size(); ++i) {
    if (n[i] != '0') {
      break;
    }
  }
  if (i != 0 && i != n.size()) {
    n[0] = n[i];
    n[i] = '0';
  }

  if (n == m) {
    cout << "OK" << endl;
  } else {
    cout << "WRONG_ANSWER" << endl;
  }

  return 0;
}
