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
  int P, N, K;
  cin >> P >> N >> K;

  pair<i64, string> result = {INT_MAX, ""};

  while (P--) {
    string str;
    cin.ignore();
    getline(cin, str);

    vector<i64> h(N);

    for (auto &i : h)
      cin >> i;

    vector<i64> dp;
    dp.push_back(0);

    i64 minDiff = INT_MAX;
    for (auto i : h) {
      int sz = dp.size();

      for (int j = 0; j < sz; j++) {
        i64 diff = (dp[j] + i) - i64(K);
        if (diff > minDiff) continue;
        dp.push_back(dp[j] + i);
        minDiff = min(minDiff, abs(diff));
      }

      set s(dp.begin(), dp.end());
      dp.assign(s.begin(), s.end());
    }

    // cout << minDiff << endl;

    result = min(result, {minDiff, str});
  }

  cout << result.second << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}