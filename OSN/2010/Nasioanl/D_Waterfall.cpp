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
  int V, H;

  cin >> V >> H;
  vector<vector<int>> grid(V, vector<int>(H, -1));

  int N;
  cin >> N;

  vector<pair<int, int>> batu(N);
  for (int i = 0; i < N; i++) {
    int v1, h1, v2, h2;
    cin >> v1 >> h1 >> v2 >> h2;
    v1--;
    h1--;
    v2--;
    h2--;
    batu[i] = {h1, h2};
    for (int v = v1; v <= v2; v++) {
      for (int h = h1; h <= h2; h++) {
        grid[v][h] = i;
      }
    }
  }

  vector<vector<i64>> dp(V + 1, vector<i64>(H, 0));

  for (int v = V - 1; v >= 0; v--) {
    for (int h = 0; h < H; h++) {
      // Sekarang batu
      if (v > 0 && grid[v - 1][h] != -1)
        continue;

      // Di atas batu
      if (grid[v][h] != -1) {
        auto [bh1, bh2] = batu[grid[v][h]];
        dp[v][h] = 1;

        if (bh1 - 1 >= 0) {
          dp[v][h] += dp[v + 1][bh1 - 1];
        }

        if (bh2 + 1 < H) {
          dp[v][h] += dp[v + 1][bh2 + 1];
        }
      } else {
        dp[v][h] = dp[v + 1][h];
      }
    }
  }

  i64 maxValue = 0;
  for (int h = 0; h < H; h++) {
    maxValue = max(maxValue, dp[0][h]);
  }

  cout << maxValue << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}