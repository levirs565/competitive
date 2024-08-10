#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int l;
    cin >> l;

    std::string str;
    cin.ignore();
    getline(cin, str);

    int result = 0;
    for (int r = 1; r <= l; r++) {
      if (l % r != 0)
        continue;   

      for (int multiplier = 0; multiplier <= 1; multiplier++) {
        int startIndex = r * multiplier;

        int differ = 0;

        for (int i = 0; i < l; i++) {
          if (str[i] != str[i % r + startIndex])
            differ++;
          if (differ > 1)
            break;
        }

        if (differ <= 1) {
          result = r;
          break;
        }
      }

      if (result != 0)
        break;
    }

    std::cout << result << std::endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}