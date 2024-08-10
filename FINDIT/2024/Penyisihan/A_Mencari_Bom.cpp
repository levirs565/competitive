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
  vector<vector<vector<i64>>> dp(N,
                                 vector<vector<i64>>(K + 1, vector<i64>(2, 0)));

  function<void(int, int)> dfs = [&](int u, int p) {
    for (int i = 1; i <= K; i++) {
      dp[u][i][0] = dp[u][i][1] = INT_MAX;
    }

    bool isBomb = bomb[u];
    if (isBomb) {
      dp[u][1][0] = dp[u][1][1] = 0;
    }

    bool first = true;
    for (auto &[v, w] : E[u]) {
      if (v == p)
        continue;

      dfs(v, u);

      if (first) {
        first = false;
        for (int i = 1; i <= K; i++) {
          dp[u][i][0] = min(
            dp[u][i][0], 
            dp[v][i - isBomb][0] + 2 * w
          );
          dp[u][i][1] = min({
              dp[u][i][1],
              dp[v][i - isBomb][1] + w,
              dp[v][i - isBomb][0] + w,
          });
        }
      } else
        for (int i = K; i >= isBomb; i--) {
          for (int j = isBomb; j <= i; j++) {
            dp[u][i][0] = min(
              dp[u][i][0], 
              dp[u][j][0] + dp[v][i - j][0] + 2 * w);
            dp[u][i][1] = min({
              dp[u][i][1], 
              dp[u][j][0] + dp[v][i - j][1] + w,
              dp[u][j][1] + dp[v][i - j][0] + 2 * w
            });
          }
        }
    }
  };

  dfs(0, -1);

  int maxCount = 0;
  for (int i = 0; i <= K; i++) {
    // cout << dp[0][i][0] << " " << dp[0][i][1] << endl;
    if (dp[0][i][0] <= T || dp[0][i][1] <= T)
      maxCount = max(maxCount, i);
  }

  cout << maxCount << endl;

  return 0;
}