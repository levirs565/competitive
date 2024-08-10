#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
  int s, e;
  vector<pair<int, int>> event;
  cin >> s >> e;
  event.push_back({s, 1});
  event.push_back({e, -1});
  cin >> s >> e;
  event.push_back({s, 2});
  event.push_back({e, -2});
  cin >> s >> e;
  event.push_back({s, 3});
  event.push_back({e, -3});
  cin >> s >> e;
  event.push_back({s, 4});
  event.push_back({e, -4});

  sort(event.begin(), event.end());

  set<int> activeSet;

  int soloDuration = 0;
  int lastTime = 0;
  for (auto [x, t] : event) {
    if (x != lastTime && activeSet.size() == 1 && *activeSet.begin() == 3) {
      soloDuration += x - lastTime;
    }
    lastTime = x;
    if (t < 0) {
      activeSet.erase(-t);
    } else {
      activeSet.insert(t);
    }
  }

  if (soloDuration > 0)
    cout << "Guitar solo (" << soloDuration << " sec.)" << endl;
  else
    cout << "No guitar solo :(" << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}