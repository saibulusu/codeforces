#include <cstring>
#include <iostream>

using namespace std;

int x, y, n;
int coordinates[25][2];
int dp[1 << 25], res[1 << 25];

int dist(int x1, int y1, int x2, int y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int time(int handbag_x, int handbag_y, int x, int y) {
  return 2 * dist(handbag_x, handbag_y, x, y);
}

int time(int handbag_x, int handbag_y, int x1, int y1, int x2, int y2) {
  return dist(handbag_x, handbag_y, x1, y1) + dist(x1, y1, x2, y2) +
         dist(x2, y2, handbag_x, handbag_y);
}

int solve(int bitMask) {
  if (dp[bitMask] != -1) {
    return dp[bitMask];
  }

  int setBitsCount = __builtin_popcount(bitMask);
  if (setBitsCount == n) {
    // case 1: bitMask contains all points -> return 0
    res[bitMask] = bitMask;
    return dp[bitMask] = 0;
  } else {
    // case 2: recurse -> consider first object with any other or none
    int bestDP = INT_MAX, bestRes;
    int firstX = -1, firstY = -1, setFirstMask = -1;
    for (int object = 0; object < n; ++object) {
      if (!(bitMask & (1 << object))) {
        if (setFirstMask == -1) {
          firstX = coordinates[object + 1][0],
          firstY = coordinates[object + 1][1];
          // consider only using this object
          setFirstMask = bitMask | (1 << object);

          bestRes = setFirstMask;
          bestDP = solve(setFirstMask) + time(x, y, firstX, firstY);
        } else {
          // consider this object with the first
          int secondX = coordinates[object + 1][0],
              secondY = coordinates[object + 1][1];
          int setFirstSecondMask = setFirstMask | (1 << object);

          int thisDP = solve(setFirstSecondMask) +
                       time(x, y, firstX, firstY, secondX, secondY);
          if (thisDP < bestDP) {
            bestRes = setFirstSecondMask;
            bestDP = thisDP;
          }
        }
      }
    }

    res[bitMask] = bestRes;
    return dp[bitMask] = bestDP;
  }
}

int main() {
  cin >> x >> y >> n;

  memset(dp, -1, sizeof(dp));
  memset(res, -1, sizeof(res));
  for (int i = 1; i <= n; ++i) {
    cin >> coordinates[i][0] >> coordinates[i][1];
  }

  cout << solve(0) << endl;

  int prevMask = 0, curMask = res[prevMask];
  while (prevMask != curMask) {
    int setBitsMask = curMask ^ prevMask;
    cout << "0 ";
    for (int object = 0; object < n; ++object) {
      if ((setBitsMask & (1 << object))) {
        cout << object + 1 << " ";
      }
    }
    prevMask = curMask;
    curMask = res[curMask];
  }
  cout << "0" << endl;

  return 0;
}
