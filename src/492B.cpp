#include <bits/stdc++.h>
#include <iomanip>
#include <iostream>

using namespace std;

long lights[10000];

int main() {
  int n;
  long l;
  cin >> n >> l;

  for (int i = 0; i < n; ++i) {
    cin >> lights[i];
  }

  sort(begin(lights), begin(lights) + n);

  long maxDiff = 0;
  for (int i = 1; i < n; ++i) {
    maxDiff = max(maxDiff, lights[i] - lights[i - 1]);
  }

  double splash = (double)maxDiff / 2.0;
  double first = lights[0], last = l - lights[n - 1];

  double res = max(max(first, last), splash);

  cout << fixed << setprecision(10) << res << endl;

  return 0;
}
