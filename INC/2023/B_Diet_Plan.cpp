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
  int N, M, K;
  cin >> N >> M >> K;

  vector<int> P(N);
  for (auto &i : P)
    cin >> i;

  vector<vector<int>> dp(N + 1, vector<int>(K + 1, INT_MAX));
  dp[0][0] = 0;

  for (int d = 0; d < N; d++) {
    for (int i = K; i >= 0; i--) {
      if (dp[d][i] == INT_MAX)
        continue;

      // makan biskuit
      if (i + 1 <= K)
        dp[d + 1][i + 1] = min(dp[d + 1][i + 1], dp[d][i]);
      // minum susu
      dp[d + 1][i] = min(dp[d + 1][i], dp[d][i] + P[d]);
    }
  }

  int day = 0;
  for (int d = N; d >= 1; d--) {
    for (int i = K; i >= 0; i--) {
      if (dp[d][i] <= M)
        day = max(day, d);
    }
  }

  cout << day << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}