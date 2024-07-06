#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string flags, first, second;
  cin >> flags >> first >> second;

  bool forward = false, backward = false;

  size_t firstFound, secondFound;

  // considering forward
  firstFound = flags.find(first);

  if (firstFound == string::npos) {
    forward = false;
  } else {
    string flagSubstring = flags.substr(firstFound + first.size());
    secondFound = flagSubstring.find(second);
    forward = secondFound != string::npos;
  }

  // considering backward
  reverse(flags.begin(), flags.end());
  firstFound = flags.find(first);

  if (firstFound == string::npos) {
    backward = false;
  } else {
    string flagSubstring = flags.substr(firstFound + first.size());
    secondFound = flagSubstring.find(second);
    backward = secondFound != string::npos;
  }

  if (forward && backward) {
    cout << "both" << endl;
  } else if (forward) {
    cout << "forward" << endl;
  } else if (backward) {
    cout << "backward" << endl;
  } else {
    cout << "fantasy" << endl;
  }

  return 0;
}
