#include <algorithm>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
  int n, x;
  cin >> n >> x;

  vector<pair<int, int>> a(n);

  for (auto &i : a)
    cin >> i.first;
  for (int i = 0; i < n; i++)
    a[i].second = i;

  sort(a.begin(), a.end());

  int m, l, r;
  bool found = false;

  for (m = 1; m < n - 1; m++) {
    int target = x - a[m].first;

    l = 0;
    r = n - 1;

    while (l < r && l != m && r != m) {
      int sum = a[l].first + a[r].first;
      if (sum == target) {
        found = true;
        break;
      } else if (sum > target) {
        r--;
      } else {
        l++;
      }
    }

    if (found)
      break;
  }

  if (!found)
    cout << "IMPOSSIBLE" << endl;
  else {
    array<int, 3> result = {
        {a[l].second + 1, a[r].second + 1, a[m].second + 1}};
    sort(result.begin(), result.end());
    cout << result[0] << " " << result[1] << " " << result[2] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}