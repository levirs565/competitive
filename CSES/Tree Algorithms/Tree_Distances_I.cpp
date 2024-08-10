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
  int N;
  cin >> N;

  vector<vector<int>> E(N);

  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  vector<int> dist(N, 0);

  function<pair<int, int>(int, int, int)> dfs = [&](int u, int p, int d) {
    pair<int, int> result = {d, u};
    dist[u] = max(dist[u], d);

    for (auto v : E[u]) {
      if (v == p)
        continue;

      result = max(result, dfs(v, u, d + 1));
    }

    return result;
  };

  auto [wa, a] = dfs(0, -1, 0);
  auto [wb, b] = dfs(a, -1, 0);
  dfs(b, -1, 0);

  for (auto d : dist)
    cout << d << " ";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}