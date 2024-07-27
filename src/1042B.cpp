#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> A, B, C, AB, BC, CA, ABC;
  for (int i = 0; i < n; ++i) {
    int c;
    string s;

    cin >> c >> s;

    if (s.size() == 3) {
      ABC.push_back(c);

    } else if (s.size() == 2 && s.find('C') == string::npos) {
      AB.push_back(c);
    } else if (s.size() == 2 && s.find('B') == string::npos) {
      CA.push_back(c);
    } else if (s.size() == 2 && s.find('A') == string::npos) {
      BC.push_back(c);
    } else if (s.find('A') != string::npos) {
      A.push_back(c);
    } else if (s.find('B') != string::npos) {
      B.push_back(c);
    } else {
      C.push_back(c);
    }
  }

  int res = INT_MAX;
  for (int abc = 0; abc < ABC.size(); ++abc) {
    res = min(res, ABC[abc]);
  }
  for (int ab = 0; ab < AB.size(); ++ab) {
    for (int c = 0; c < C.size(); ++c) {
      res = min(res, AB[ab] + C[c]);
    }
  }
  for (int bc = 0; bc < BC.size(); ++bc) {
    for (int a = 0; a < A.size(); ++a) {
      res = min(res, BC[bc] + A[a]);
    }
  }
  for (int ca = 0; ca < CA.size(); ++ca) {
    for (int b = 0; b < B.size(); ++b) {
      res = min(res, CA[ca] + B[b]);
    }
  }
  for (int a = 0; a < A.size(); ++a) {
    for (int b = 0; b < B.size(); ++b) {
      for (int c = 0; c < C.size(); ++c) {
        res = min(res, A[a] + B[b] + C[c]);
      }
    }
  }
  for (int ca = 0; ca < CA.size(); ++ca) {
    for (int ab = 0; ab < AB.size(); ++ab) {
      res = min(res, CA[ca] + AB[ab]);
    }
  }
  for (int ca = 0; ca < CA.size(); ++ca) {
    for (int bc = 0; bc < BC.size(); ++bc) {
      res = min(res, CA[ca] + BC[bc]);
    }
  }
  for (int ab = 0; ab < AB.size(); ++ab) {
    for (int bc = 0; bc < BC.size(); ++bc) {
      res = min(res, AB[ab] + BC[bc]);
    }
  }

  res = res == INT_MAX ? -1 : res;
  cout << res << endl;

  return 0;
}
