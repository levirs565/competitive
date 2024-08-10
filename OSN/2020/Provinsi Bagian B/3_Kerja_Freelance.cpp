#include <algorithm>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
  int M;
  cin >> M;

  vector<tuple<int, int, i64>> pekerjaan(M); // e, s, p

  for (auto &[e, s, p] : pekerjaan)
    cin >> s >> e >> p;

  sort(pekerjaan.begin(), pekerjaan.end());

  int maxTime = get<0>(pekerjaan.back());

  vector<i64> dp(maxTime + 1, 0);

  for (auto &[e, s, p] : pekerjaan) {
    i64 newProfit = p;
    if (s - 1 >= 0)
      newProfit += dp[s - 1];

    for (int i = e; i <= maxTime; i++) {
      dp[i] = max(dp[i], newProfit);
    }
  }

  cout << dp[maxTime] << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}