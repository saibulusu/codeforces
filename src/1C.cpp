#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>

#define PI 3.141592;

using namespace std;

struct point {
  double x, y;
};

double gcd(double a, double b) {
  while (b != 0) {
    double temp = b;
    b = (int)a % (int)b;
    a = temp;
  }
  return a;
}

int main() {
  bool debug = true;

  point p1, p2, p3;
  cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

  double p1p2Length = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
  double p2p3Length = sqrt(pow(p2.x - p3.x, 2) + pow(p2.y - p3.y, 2));
  double p3p1Length = sqrt(pow(p3.x - p1.x, 2) + pow(p3.y - p1.y, 2));

  double sumLength = p1p2Length + p2p3Length + p3p1Length;
  double radius =
      p1p2Length * p2p3Length * p3p1Length /
      sqrt(sumLength * (sumLength - 2 * p1p2Length) *
           (sumLength - 2 * p2p3Length) * (sumLength - 2 * p3p1Length));

  if (debug) {
    cout << "p1p2Length = " << p1p2Length << endl;
    cout << "p2p3Length = " << p2p3Length << endl;
    cout << "p3p1Length = " << p3p1Length << endl;
    cout << "radius = " << radius << endl;
  }

  double p1p2Sin = p1p2Length / 2 / radius;
  double p2p3Sin = p2p3Length / 2 / radius;
  double p3p1Sin = p3p1Length / 2 / radius;

  double p1p2Angle = (int)p1p2Sin != 1 ? 2 * asin(p1p2Sin) : PI;
  double p2p3Angle = (int)p2p3Sin != 1 ? 2 * asin(p2p3Sin) : PI;
  double p3p1Angle = (int)p3p1Sin != 1 ? 2 * asin(p3p1Sin) : PI;

  if (p1p2Angle < 0)
    p1p2Angle += 2 * PI;
  if (p2p3Angle < 0)
    p2p3Angle += 2 * PI;
  if (p3p1Angle < 0)
    p3p1Angle += 2 * PI;

  if (debug) {
    cout << "p1p2Sin = " << p1p2Sin << endl;
    cout << "p2p3Sin = " << p2p3Sin << endl;
    cout << "p3p1Sin = " << p3p1Sin << endl;

    cout << "p1p2Angle = " << p1p2Angle << endl;
    cout << "p2p3Angle = " << p2p3Angle << endl;
    cout << "p3p1Angle = " << p3p1Angle << endl;
  }

  double n, theta;

  for (n = 3.0; n <= 100.0; n += 1.0) {
    theta = 2 / n * PI;
    double p1p2Divide = p1p2Angle / theta;
    double p2p3Divide = p2p3Angle / theta;
    double p3p1Divide = p3p1Angle / theta;
    if (floor(p1p2Divide) == p1p2Divide && floor(p2p3Divide) == p2p3Divide &&
        floor(p3p1Divide) == p3p1Divide) {
      break;
    }
  }

  if (debug) {
    cout << "theta = " << theta << endl;
    cout << "n = " << n << endl;
  }

  /*
  double n = 2 / theta * PI;
  double singleArea = radius * radius * cos(theta / 2) * sin(theta / 2);
  double totalArea = singleArea * n;

  if (debug) {
    cout << "n = " << n << endl;
    cout << "singleArea = " << singleArea << endl;
  }

  cout << fixed << setprecision(6) << totalArea << endl;
  */

  return 0;
}
