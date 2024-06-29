#include <iostream>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> t;
  for (int i = 0; i < n; ++i) {
    int time;
    cin >> time;
    t.push_back(time);
  }

  int prevI = -1, prevJ = t.size();
  int i = 0, j = t.size() - 1;
  int alice = 0, bob = 0;

  while (true) {
    if (i > j) {
      break;
    } else if (i == j) {
      if (prevI != i && prevJ != j) {
        ++alice;
      }
      break;
    } else {
      if (prevI != i)
        ++alice;
      if (prevJ != j)
        ++bob;
      --t[i];
      --t[j];
      prevI = i;
      prevJ = j;
      if (t[i] == 0)
        ++i;
      if (t[j] == 0)
        --j;
    }
  }

  cout << alice << " " << bob << endl;
  return 0;
}
