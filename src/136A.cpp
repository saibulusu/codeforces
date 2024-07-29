#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  int p[101];

  for (int i = 1; i <= n; ++i) {
    int cur;
    cin >> cur;

    p[cur] = i;
  }

  for (int i = 1; i <= n; ++i) {
    cout << p[i] << " ";
  }

  cout << endl;

  return 0;
}
