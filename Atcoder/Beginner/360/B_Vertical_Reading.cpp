#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <vector>

using namespace std;

void solution() {
  std::string s, t;
  cin >> s >> t;

  bool yes = false;
  for (size_t w = 1; w < s.length(); w++) {
    for (size_t c = 0; c < w; c++) {
      size_t equalCount = 0;
      for (size_t i = 0; i <= s.length() / w; i++) {
        if (i * w + c >= s.length()) break;
        if (t[i] == s[i * w + c])
          equalCount++;
        else
          break;
      }

      if (equalCount == t.length())
        yes = true;
    }
  }
  // for (size_t c = 0; c < t.length(); c++) {
  //     if (s[c] != t[0]) continue;
  //     // cout << c << endl;
  //     for (size_t w = c; w < t.length(); w++) {
  //         if (w >= s.length()) break;
  //         bool equal = true;
  //         for (size_t i = 0; equal && i < min(s.length() / w, c); i++) {
  //             if (t[i] != s[i * w + c])
  //                 equal = false;
  //         }

  //         if (equal)
  //             yes = true;
  //     }
  // }

  if (yes)
    cout << "Yes";
  else
    cout << "No";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}