#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstring>
#include <exception>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;
using i64 = int64_t;

int main() {
  int N, K, T;
  cin >> N >> K >> T;

  vector<bool> bomb(N, false);

  for (int i = 0; i < K; i++) {
    int j;
    cin >> j;
    j--;
    bomb[j] = true;
  }

  vector<vector<pair<int, int>>> E(N);

  for (int i = 0; i < N - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    E[u].emplace_back(v, w);
    E[v].emplace_back(u, w);
  }

  // dp[n][k], pada saat mengunjuki n dan menemukan k bomb berapa waktu minimal
  vector<vector<i64>> dp(N, vector<i64>(K + 1, LONG_LONG_MAX));

  function<void(int, int)> dfs = [&](int u, int p) {
    for (auto &[v, w] : E[u]) {
      if (v == p)
        continue;

      // Maju
      for (int i = 0; i < K + !bomb[v]; i++) {
        if (dp[u][i] == LONG_LONG_MAX)
          continue;
        dp[v][i + bomb[v]] = min(dp[v][i + bomb[v]], dp[u][i] + w);
      }

      dfs(v, u);

      // Mundur
      for (int i = 0; i <= K; i++) {
        if (dp[v][i] == LONG_LONG_MAX)
          continue;
        dp[u][i] = min(dp[u][i], dp[v][i] + w);
      }
    }
  };

  dp[0][bomb[0]] = 0;
  dfs(0, -1);

  int maxCount = 0;
  for (int i = 0; i < N; i++) {
    // cout << "n = " << i << " ";
    for (int j = 0; j <= K; j++) {
      if (dp[i][j] == LONG_LONG_MAX) {
        // cout << "INFTY" << ",";
        continue;
      }
    //   cout << dp[i][j] << ",";
      if (dp[i][j] <= T)
        maxCount = max(maxCount, j);
    }
    // cout << endl;
  }

  cout << maxCount << endl;

  return 0;
}