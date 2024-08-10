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

  int l = 0, r = n - 1;
  bool found = false;

  while (l < r) {
    int sum = a[l].first + a[r].first;
    if (sum == x) {
      found = true;
      break;
    } else if (sum > x) {
      r--;
    } else {
      l++;
    }
  }

  if (!found)
    cout << "IMPOSSIBLE" << endl;
  else {
    int lI = a[l].second + 1, rI = a[r].second + 1;
    cout << min(lI, rI) << " " << max(lI, rI) << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}