#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <sstream>
//#include <bits/stdc++.h>

int main () {
  int n;
  std::cin >> n;

  std::vector<int> t;
  for (int i = 0; i < n; ++i) {
    int time;
    std::cin >> time;
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

  std::cout << alice << " " << bob << std::endl;
  return 0;
}
