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
  int n, m;
  cin >> n >> m;

  vector<int> cell(n);

  for (int &c : cell)
    cin >> c;

  vector<int> tower(m);

  for (int &t : tower)
    cin >> t;

  vector<pair<int, int>> points;

  for (int c : cell)
    points.push_back({c, 0});
  for (int t : tower)
    points.push_back({t, 1});

  sort(points.begin(), points.end());

  auto check = [&](int r) -> bool {
    int l = 0;

    for (int i = 0; i < int(points.size()); i++) {
      if (points[i].second == 1) {
        if (points[i].first - points[l].first > r) {
          return false;
        }
        l = max(l, i + 1);
        while (l < points.size() && points[l].first - points[i].first <= r) {
          l++;
        }

        if (l == points.size())
          return true;
      }
    }

    return l >= points.size();
  };

  int L = 0, R = 4e9;

  while (L < R) {
    int mid = ((i64) L + R) / 2;
    if (check(mid)) {
      R = mid;
    } else {
      L = mid + 1;
    }
  }

  cout << L << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}