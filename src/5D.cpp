#include <iomanip>
#include <iostream>
#include <tgmath.h>

using namespace std;

int main() {
  bool debug = false;

  double a, v, l, d, w;
  cin >> a >> v >> l >> d >> w;

  w = min(w, v);
  double t = 0.0;

  if (w == v || d <= w * w / (2 * a)) {
    // if point d limit is irrelevant or reaching speed w after point d
    if (debug) {
      cout << "case 1" << endl;
    }

    double t1 = v / a;
    double x1 = a * t1 * t1 / 2;

    if (l < x1) {
      // if reaching speed v after l, consider distance
      t = sqrt(2.0 * l / a);
    } else if (l == x1) {
      // if reaching speed v at l
      t = t1;
    } else {
      // if reaching speed v before l, consider extra distance moving at speed v
      t = t1 + (l - x1) / v;
    }
  } else {
    if (debug) {
      cout << "case 2" << endl;
    }

    // if reaching speed w before point d
    double t1 = w / a;
    double x1 = w / 2.0 * t1;
    t += t1;

    double x2 = d - x1;
    double t2 = (v - w) / a;

    if (debug) {
      cout << "t1 = " << t1 << ", x1 = " << x1 << endl;
      cout << "t2 = " << t2 << ", x2 = " << x2 << endl;
    }

    if (x2 >= (w + v) * t2) {
      // if reaching d after reaching speed w
      t += 2.0 * t2 + (x2 - (w + v) * t2) / v;
    } else {
      // if reaching d before speed w
      t += 2.0 * (sqrt(w * w + a * x2) - w) / a;
    }

    double t3 = (v - w) / a;
    double x3 = w * t3 + a * t3 * t3 / 2.0;

    if (x3 > l - d) {
      // if reaching speed v after l
      t += (sqrt(w * w + 2.0 * a * (l - d)) - w) / a;
    } else {
      // if reaching speed v before l
      t += t3 + (l - d - x3) / v;
    }
  }

  cout << fixed << setprecision(5) << t << endl;

  return 0;
}
