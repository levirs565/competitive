#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory.h>
#include <queue>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
  int N;
  cin >> N;

  vector<int> a(N);
  for (auto &i : a) {
    cin >> i;
  }

  sort(a.begin(), a.end());

  vector<pair<int, int>> ranges;
  for (auto i : a) {
    if (!ranges.empty() && ranges.back().second + 1 == i) {
      ranges.back().second++;
    }
    if (ranges.empty() || i > ranges.back().second + 1)
      ranges.push_back({i, i});
  }

  bool f = true;
  for (auto [l, r] : ranges) {
    if (!f)
      cout << ",";
    if (l == r)
      cout << l;
    else
      cout << l << "-" << r;
    f = false;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}