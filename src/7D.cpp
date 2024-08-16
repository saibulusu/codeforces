#include <iostream>
#include <string>

using namespace std;

int main() {
  bool debug = false;

  string s;
  cin >> s;

  int dp[s.size() + 1];
  dp[0] = 0;
  int res = 0;

  long long modulo = 1e9 + 7, prime = 107;
  long long msb = 1;
  long long forwardHash = 0, backwardHash = 0;

  for (long long i = 1; i <= s.size(); ++i) {
    forwardHash = (forwardHash * prime + s[i - 1]) % modulo;
    backwardHash = (backwardHash + msb * s[i - 1]) % modulo;
    msb = (msb * prime) % modulo;

    if (debug) {
      cout << "i: " << i << ": " << forwardHash << " " << backwardHash << endl;
    }

    dp[i] = forwardHash == backwardHash ? dp[i / 2] + 1 : 0;
    res += dp[i];
  }

  if (debug) {
    for (int i = 0; i <= s.size(); ++i) {
      cout << "i = " << i << ", dp[" << i << "] = " << dp[i] << endl;
    }
  }

  cout << res << endl;

  return 0;
}
