#include <iostream>
#include <set>

using namespace std;

int main() {
  string s;
  cin >> s;

  set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y',
                      'A', 'E', 'I', 'O', 'U', 'Y'};

  for (int i = 0; i < s.size(); ++i) {
    if (vowels.count(s[i]) == 0) {
      cout << ".";
      if ((int)s[i] < 91) {
        cout << (char)((int)s[i] + 32);
      } else {
        cout << s[i];
      }
    }
  }
  cout << endl;
}
