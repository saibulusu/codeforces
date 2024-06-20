#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

int main() {
  string input;
  getline(cin, input);

  bool debug = false;

  vector<pair<int, int>> ranges;
  vector<int> dp(input.size() + 1);
  dp[input.size()] = 0;

  map<int, int> mp;

  int maxSize = 0;

  for (int i = input.size() - 1; i >= 0; --i) {
    if (input[i] == ')') {
      // regular substring cannot start here
      dp[i] = 0;
    } else {
      if (i + 1 == input.size()) {
        // regular substring cannot start with last character
        dp[i] = 0;
      } else if (input[i + 1] == ')') {
        // append "()" to left of existing regular substring
        dp[i] = 2 + dp[i + 2];
      } else {
        if (dp[i + 1] + i + 1 < input.size() &&
            input[dp[i + 1] + i + 1] == ')') {
          // surround existing regular substring with "(" and ")"
          dp[i] = 2 + dp[i + 1];
          if (dp[i + 1] + i + 2 < input.size()) {
            // append to left of existing regular substring
            dp[i] += dp[dp[i + 1] + i + 2];
          }
        } else {
          dp[i] = 0;
        }
      }
    }

    maxSize = max(maxSize, dp[i]);
    ++mp[dp[i]];
  }

  mp[0] = 1;
  cout << maxSize << " " << mp[maxSize] << endl;

  return 0;
}
