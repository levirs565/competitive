#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    std::vector<int> a(n);

    for (int &item : a)
      cin >> item;

    int lastGCD = 0;
    int mistmatchIndex = -1;

    for (int left = 0; left < n - 1; left++) {
      int right = left + 1;
      int gcd = __gcd(a[left], a[right]);
      if (lastGCD > gcd) {
        mistmatchIndex = left;
        break;
      }
      lastGCD = gcd;
    }

    if (mistmatchIndex > -1) {
      std::array<int, 3> deleteIndex{mistmatchIndex - 1, mistmatchIndex,
                                     mistmatchIndex + 1};

      bool can = true;
      for (int index : deleteIndex) {
        if (index >= n || index < 0)
          continue;

        vector<int> b = a;
        b.erase(b.begin() + index);

        lastGCD = 0;
        can = true;
        for (int left = 0; left < n - 2; left++) {
          int right = left + 1;
          int gcd = __gcd(b[left], b[right]);
          if (lastGCD > gcd) {
            can = false;
            break;
          }
          lastGCD = gcd;
        }

        if (can)
          break;
      }

      if (can)
        std::cout << "YES" << std::endl;
      else
        std::cout << "NO" << std::endl;
    } else
      std::cout << "YES" << std::endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}