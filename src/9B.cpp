#include <cmath>
#include <iostream>

using namespace std;

int stops[100];

double dist(long long x1, long long y1, long long x2, long long y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
  bool debug = false;

  long long n, vb, vs;
  cin >> n >> vb >> vs;

  for (int i = 0; i < n; ++i) {
    cin >> stops[i];
  }

  long long x, y;
  cin >> x >> y;

  int closest = 0;
  double optimalTime = (double)INT_MAX, optimalDist;

  for (int i = 1; i < n; ++i) {
    double curDist = dist(stops[i], 0, x, y);
    double time = dist(stops[i], 0, 0, 0) / (double)vb + curDist / (double)vs;

    if (time < optimalTime || (time == optimalTime && curDist < optimalDist)) {
      optimalTime = time;
      closest = i;
      optimalDist = curDist;
    }
  }

  cout << closest + 1 << endl;

  return 0;
}
