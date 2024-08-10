#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <vector>

using namespace std;

void solution() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    int first = 0;
    bool singleNumber = true;
    for (int &i : a) {
      cin >> i;
      if (first == 0)
        first = i;
      singleNumber = singleNumber && i == first;
    }

    vector<char> result(n, 'R');

    if (singleNumber) {
      std::cout << "NO" << std::endl;
      continue;
    } else if (0 != a[n - 1] - a[1]) {
      result[0] = 'B';
    } else if (0 != a[n - 2] - a[0]) {
      result[n - 1] = 'B';
    } else {
      int bigRange = a[n - 1] - a[0];
      int minIndex = n / 2;
      int maxIndex = minIndex;

      result[minIndex] = 'B';

      for (int i = 0; minIndex > 0 || maxIndex + 1 < n; i++) {
        if (i % 2 == 0 && minIndex > 0) {
          minIndex--;
          result[minIndex] = 'B';
        } else if (maxIndex + 1 < n) {
          maxIndex++;
          result[maxIndex] = 'B';
        }
        if (a[maxIndex] - a[minIndex] != bigRange) {
          break;
        }
      }
      if (a[maxIndex] - a[minIndex] == bigRange ||
          (minIndex == 0 && maxIndex + 1 == n)) {
        if (a[n - 2] - a[0] != 0) {
          result[n - 1] = 'R';
        } else if (a[n - 1] - a[1] != 0) {
          result[0] = 'R';
        } else {
          cout << "NO" << endl;
          continue;
        }
      }
    }

    cout << "YES" << endl;
    for (char ch : result)
      cout << ch;
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}