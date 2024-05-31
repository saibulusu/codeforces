#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <sstream>
#include <bits/stdc++.h>

int main () {
  // get first row values
  int n, w, h;
  std::cin >> n >> w >> h;

  // create envelopes vector & push card as first envelope
  std::vector<std::tuple<int, int, int>> envelopes;
  envelopes.push_back(std::make_tuple(w, h, 0));

  // get all other envelopes and push them
  for (int i = 1; i <= n; ++i) {
    int w_i, h_i;
    std::cin >> w_i >> h_i;
    envelopes.push_back(std::make_tuple(w_i, h_i, i));
  }
  // sort all envelopes other than the card itself
  std::sort(envelopes.begin() + 1, envelopes.end());

  // the nth index shows the max solution for envelope n - 1
  std::vector<std::vector<int>> dp(n + 1);

  for (int i = n; i >= 0; --i) {
    std::vector<int> max;
    for (int j = i + 1; j <= n; ++j) {
      // only add envelope j, if envelope i fits into it AND this envelope j is optimal
      if (std::get<0>(envelopes[i]) < std::get<0>(envelopes[j]) && 
        std::get<1>(envelopes[i]) < std::get<1>(envelopes[j]) && 
        max.size() < dp[j].size()) {
          max = dp[j];
      }
    }

    max.push_back(std::get<2>(envelopes[i]));
    dp[i] = max;
  }

  // print output
  if (dp[0].size() == 1) {
    std::cout << "0" << std::endl;
  } else {
    std::cout << dp[0].size() - 1 << std::endl;
    for (int i = dp[0].size() - 2; i >= 0; --i) {
      std::cout << dp[0][i] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
