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

  function<pair<int, int>(int, int)> dfs = [&](int u, int p) {
    pair<int, int> result = {0, u};

    for (auto v : E[u]) {
      if (v == p)
        continue;

      auto [w, n] = dfs(v, u);
      result = max(result, {1 + w, n});
    }

    return result;
  };

  auto [wa, a] = dfs(0, -1);
  auto [wb, b] = dfs(a, -1);

  cout << wb << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}