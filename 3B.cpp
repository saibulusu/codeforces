// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  bool debug = false;

  // n - vehicle count, v - truck volume
  int n, v;
  cin >> n >> v;

  vector<pair<int, int>> kayaks, catamarans;

  // fill kayaks & catamarans vectors
  for (int id = 1; id <= n; id += 1) {
    int t, p;
    cin >> t >> p;

    if (t == 1) {
      kayaks.push_back(make_pair(id, p));
    } else {
      catamarans.push_back(make_pair(id, p));
    }
  }

  // sort vectors in descending order by capacity
  sort(kayaks.begin(), kayaks.end(),
       [](const pair<int, int> &a, const pair<int, int> &b) {
         return a.second > b.second;
       });
  sort(catamarans.begin(), catamarans.end(),
       [](const pair<int, int> &a, const pair<int, int> &b) {
         return a.second > b.second;
       });

  if (debug) {
    cout << "kayaks: ";
    for (int i = 0; i < kayaks.size(); i += 1) {
      cout << "(id " << kayaks[i].first << " capacity " << kayaks[i].second
           << ") ";
    }
    cout << endl << "catmarans: ";

    for (int i = 0; i < catamarans.size(); i += 1) {
      cout << "(id " << catamarans[i].first << " capacity "
           << catamarans[i].second << ") ";
    }
    cout << endl;
  }

  // res - optimal set, optimalCapacity - total optimal capacity
  vector<int> res;
  int optimalCapacity = 0;

  // debug values
  int optimalNumKayaks = 0, optimalNumCatamarans = 0;

  // i moves through kayaks, j moves through catamarans
  int i = 0, j = 0;

  if (v % 2 == 1 && kayaks.size() >= 1) {
    optimalCapacity += kayaks[0].second;
    optimalNumKayaks += 1;
    res.push_back(kayaks[0].first);
    i += 1;
    v -= 1;
  }

  // 2 kayaks & 1 catamaran
  while (v > 0 && i + 1 < kayaks.size() && j < catamarans.size()) {
    if (v < 2) {
      break;
    }

    int doubleKayak = kayaks[i].second + kayaks[i + 1].second;
    int singleCatamaran = catamarans[j].second;
    if (doubleKayak >= singleCatamaran) {
      res.push_back(kayaks[i].first);
      res.push_back(kayaks[i + 1].first);
      optimalCapacity += doubleKayak;
      optimalNumKayaks += 2;
      if (debug)
        cout << "selecting " << kayaks[i].first << " " << kayaks[i + 1].first
             << " optimalCapacity = " << optimalCapacity << endl;
      i += 2;
      v -= 2;
    } else {
      res.push_back(catamarans[j].first);
      optimalCapacity += singleCatamaran;
      optimalNumCatamarans += 1;
      if (debug)
        cout << "selecting " << catamarans[j].first
             << " optimalCapacity = " << optimalCapacity << endl;
      j += 1;
      v -= 2;
    }
  }

  // 1 kayak & 1 catamaran
  while (v > 0 && i < kayaks.size() && j < catamarans.size()) {
    int singleKayak = kayaks[i].second;
    int singleCatamaran = catamarans[j].second;
    if (singleKayak >= singleCatamaran && v >= 1) {
      res.push_back(kayaks[i].first);
      optimalCapacity += singleKayak;
      optimalNumKayaks += 1;
      if (debug)
        cout << "selecting " << kayaks[i].first
             << " optimalCapacity = " << optimalCapacity << endl;
      i += 1;
      v -= 1;
    } else if (singleCatamaran > singleKayak && v >= 2) {
      if (debug)
        cout << "selecting " << catamarans[j].first << endl;
      res.push_back(catamarans[j].first);
      optimalCapacity += singleCatamaran;
      optimalNumCatamarans += 1;
      j += 1;
      v -= 2;
    } else {
      break;
    }
  }

  // 1 kayak
  while (v > 0 && i < kayaks.size()) {
    if (v >= 1) {
      res.push_back(kayaks[i].first);
      optimalCapacity += kayaks[i].second;
      optimalNumKayaks += 1;
      if (debug)
        cout << "selecting " << kayaks[i].first
             << " optimalCapacity = " << optimalCapacity << endl;
      v -= 1;
    }
    i += 1;
  }

  // 1 catamaran
  while (v > 0 && j < catamarans.size()) {
    if (v >= 2) {
      res.push_back(catamarans[j].first);
      optimalCapacity += catamarans[j].second;
      optimalNumCatamarans += 1;
      if (debug)
        cout << "selecting " << catamarans[j].first
             << " optimalCapacity = " << optimalCapacity << endl;
      v -= 2;
    }
    j += 1;
  }

  cout << optimalCapacity << endl;

  for (int i = 0; i < res.size(); i += 1) {
    cout << res[i] << " ";
  }
  cout << endl;

  if (debug) {
    cout << "num kayaks: " << optimalNumKayaks << endl;
    cout << "num catamarans: " << optimalNumCatamarans << endl;
  }

  return 0;
}
