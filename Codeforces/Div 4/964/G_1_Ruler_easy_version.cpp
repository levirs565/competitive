#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int l = 2, r = 999;
    int ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      cout << "? 1 " << mid << endl;
      cout << flush;
      int result;
      cin >> result;
      if (result == -1)
        break;
      // Incorrect
      if (mid < result) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    cout << "! " << ans << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}