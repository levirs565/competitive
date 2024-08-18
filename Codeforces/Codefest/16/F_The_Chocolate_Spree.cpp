#include <algorithm>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
  int N;
  cin >> N;

  vector<i64> A(N);

  for (auto &i : A)
    cin >> i;

  vector<vector<int>> E(N);

  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  vector<int> P(N);
  vector<i64> D(N);
  auto dfs = [&](auto self, int u, int p, i64 d) -> pair<i64, int> {
    P[u] = p;
    D[u] = d;
    pair<i64, int> result = {d, u};

    for (auto v : E[u]) {
      if (v == p)
        continue;

      result = max(result, self(self, v, u, d + A[v]));
    }

    return result;
  };

  auto [wa, a] = dfs(dfs, 0, -1, A[0]);
  auto [wb, b] = dfs(dfs, a, -1, A[a]);

  vector<int> path;

  for (int curr = b; curr != -1; curr = P[curr])
    path.push_back(curr);

  reverse(path.begin(), path.end());

  vector<i64> maxComponent;

  i64 res = wb;

  for (size_t i = 0; i < path.size(); i++) {
    int currentNode = path[i];
    int prevNode = i > 0 ? path[i - 1] : -1;
    int nextNode = i < path.size() - 1 ? path[i + 1] : -1;

    auto dfs2 = [&](auto self, int u, int p, i64 d) -> pair<i64, int> {
      pair<i64, int> result = {d, u};

      for (auto v : E[u]) {
        if (v == p || v == prevNode || v == nextNode || v == currentNode)
          continue;

        result = max(result, self(self, v, u, d + A[v]));
      }

      return result;
    };

    auto [wc, c] = dfs2(dfs2, path[i], -1, 0);

    for (auto v : E[currentNode]) {
      if (v == prevNode || v == nextNode)
        continue;

      auto [wd, d] = dfs2(dfs2, v, -1, A[v]);
      auto [we, e] = dfs2(dfs2, d, -1, A[d]);

      res = max(res, wb + we);
    }

    maxComponent.push_back(wc);
  }

  vector<i64> prefix;

  for (size_t i = 0; i < path.size(); i++) {
    i64 current = D[path[i]] + maxComponent[i];
    prefix.push_back(max(current, prefix.empty() ? 0 : prefix.back()));
  }

  vector<i64> suffix;

  for (int i = int(path.size()) - 1; i >= 0; i--) {
    i64 sub = i > 0 ? D[path[i - 1]] : 0;
    i64 current = D[b] - sub + maxComponent[i];
    suffix.push_back(max(current, suffix.empty() ? 0 : suffix.back()));
  }

  reverse(suffix.begin(), suffix.end());

  for (int l = 0; l < path.size() - 1; l++) {
    i64 d = prefix[l] + suffix[l + 1];
    res = max(res, d);
  }

  cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}