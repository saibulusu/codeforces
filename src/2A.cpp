#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;

  // name -> score
  map<string, int> mp;

  // get names and scores in order to replay
  string names[n];
  int scores[n];

  for (int i = 0; i < n; ++i) {
    string name;
    int score;

    cin >> name;
    cin >> score;
    names[i] = name;
    scores[i] = score;

    mp[name] += score;
  }

  // get max score
  int maxScore = -1;
  map<string, int>::iterator it = mp.begin();
  while (it != mp.end()) {
    maxScore = max(maxScore, it->second);
    ++it;
  }

  // name -> score
  map<string, int> mp2;
  for (int i = 0; i < n; ++i) {
    mp2[names[i]] += scores[i];

    if (mp2[names[i]] >= maxScore && mp[names[i]] == maxScore) {
      cout << names[i] << endl;
      return 0;
    }
  }

  return 0;
}
