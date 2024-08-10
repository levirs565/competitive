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
  int N, Q;
  cin >> N >> Q;

  vector<vector<int>> E(N);
  for (int u = 1; u < N; u++) {
    int v;
    cin >> v;
    v--;

    E[v].push_back(u);
  }

  vector<int> P(N), D(N);
  auto dfs = [&](auto self, int u, int p, int d) -> void {
    P[u] = p;
    D[u] = d;
    for (auto v : E[u]) {
      self(self, v, u, d + 1);
    }
  };

  dfs(dfs, 0, -1, 0);

  while (Q--) {
    int x, k;
    cin >> x >> k;
    x--;

    int curr = x;

    if (D[curr] < k) {
      cout << -1 << endl;
      continue;
    }

    while (curr != -1 && k > 0) {
      curr = P[curr];
      k--;
    }

    if (curr != -1)
      curr++;

    cout << curr << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}