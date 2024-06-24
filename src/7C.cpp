#include <iostream>

#define ll long long

using namespace std;

// Extended Euclidean Algorithm for Bezout's identity
ll gcd(ll a, ll b, ll *x, ll *y) {
  if (a == 0) {
    *x = 0, *y = 1;

    return b;
  } else {
    ll x1, y1;
    ll g = gcd(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1, *y = x1;

    return g;
  }
}

int main() {
  ll a, b, c;
  cin >> a >> b >> c;

  ll x, y;
  ll g = gcd(a, b, &x, &y);

  if (c % g == 0) {
    // if g divides c
    x *= (-c / g), y *= (-c / g);
    cout << x << " " << y << endl;
  } else {
    // if g doesn't divide c
    cout << "-1" << endl;
  }

  return 0;
}
