#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;

    int sIndex = 0, tIndex = 0;

    while (sIndex < s.size() && tIndex < t.size()) {
      if (s[sIndex] == t[tIndex]) {
        sIndex++;
        tIndex++;
      } else if (s[sIndex] == '?') {
        s[sIndex] = t[tIndex];
        sIndex++;
        tIndex++;
      } else {
        sIndex++;
      }
    }

    if (sIndex >= s.size() && tIndex < t.size()) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;

      for (auto &c : s)
        if (c == '?')
          c = 'a';

      cout << s << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}