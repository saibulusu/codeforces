#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int prices[100];
int counts[100];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> prices[i];
  }

  sort(prices, prices + n);

  map<string, int> mp;

  for (int i = 0; i < m; ++i) {
    string fruit;
    cin >> fruit;

    ++mp[fruit];
  }

  int j = 0;
  map<string, int>::iterator it;
  for (it = mp.begin(); it != mp.end(); ++it) {
    counts[j] = it->second;
    ++j;
  }

  sort(counts, counts + j);

  int min = 0, max = 0;
  for (int i = 0; i < j; ++i) {
    min += counts[j - i - 1] * prices[i];
    max += counts[j - i - 1] * prices[n - i - 1];
  }

  cout << min << " " << max << endl;
}
