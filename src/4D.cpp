#include <iostream>
#include <tuple>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;

int main() {
  // get first row values
  int n, w, h;
  cin >> n >> w >> h;

  // create envelopes vector & push card as first envelope
  vector<tuple<int, int, int>> envelopes;
  envelopes.push_back(make_tuple(w, h, 0));

  // get all other envelopes and push them
  for (int i = 1; i <= n; ++i) {
    int w_i, h_i;
    cin >> w_i >> h_i;
    envelopes.push_back(make_tuple(w_i, h_i, i));
  }
  // sort all envelopes other than the card itself
  sort(envelopes.begin() + 1, envelopes.end());

  // the nth index shows the max solution for envelope n - 1
  vector<vector<int>> dp(n + 1);

  for (int i = n; i >= 0; --i) {
    vector<int> max;
    for (int j = i + 1; j <= n; ++j) {
      // only add envelope j, if envelope i fits into it AND this envelope j is
      // optimal
      if (get<0>(envelopes[i]) < get<0>(envelopes[j]) &&
          get<1>(envelopes[i]) < get<1>(envelopes[j]) &&
          max.size() < dp[j].size()) {
        max = dp[j];
      }
    }

    max.push_back(get<2>(envelopes[i]));
    dp[i] = max;
  }

  // print output
  if (dp[0].size() == 1) {
    cout << "0" << endl;
  } else {
    cout << dp[0].size() - 1 << endl;
    for (int i = dp[0].size() - 2; i >= 0; --i) {
      cout << dp[0][i] << " ";
    }
    cout << endl;
  }

  return 0;
}
