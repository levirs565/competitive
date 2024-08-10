#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> tin, low;
vector<int> sizes;
int timer;
vector<pair<int, int>> bridges;

void IS_BRIDGE(int v, int to) { bridges.push_back({v, to}); }

void dfs(int v, int p) {
  visited[v] = true;
  tin[v] = low[v] = timer++;
  sizes[v] = 1;
  for (int to : adj[v]) {
    if (to == p) {
      continue;
    }
    if (visited[to]) {
      low[v] = min(low[v], tin[to]);
    } else {
      dfs(to, v);
      sizes[v] += sizes[to];
      low[v] = min(low[v], low[to]);
      if (low[to] > tin[v])
        IS_BRIDGE(v, to);
    }
  }
};

void find_bridges() {
  timer = 0;
  visited.assign(n, false);
  tin.assign(n, -1);
  low.assign(n, -1);
  for (int i = 0; i < n; ++i) {
    if (!visited[i])
      dfs(i, -1);
  }
}

void solution() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;

    adj.resize(n);
    visited.resize(n);
    tin.resize(n);
    low.resize(n);
    sizes.resize(n);
    bridges.clear();

    timer = 0;
    adj.assign(n, {});
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    sizes.assign(n, 0);

    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    find_bridges();

    int64_t minResult = int64_t(n) * (n - 1) / 2;
    for (int i = 0; i < n; i++) {
        if (tin[i] == low[i]) {
            int64_t sz = sizes[i];
            minResult = min(minResult,
                sz * (sz - 1) / 2 + (n - sz) * (n - sz - 1) / 2
            );
        }
    }

    cout << minResult << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}