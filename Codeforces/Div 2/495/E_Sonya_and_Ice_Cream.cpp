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
  int N, K;
  cin >> N >> K;

  vector<vector<pair<int, int>>> E(N);

  for (int i = 1; i < N; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    E[u].push_back({v, w});
    E[v].push_back({u, w});
  }

  vector<int> parent(N, -1), depth(N);

  function<pair<int, int>(int, int, int)> dfs = [&](int u, int p, int d) {
    parent[u] = p;
    depth[u] = d;
    pair<int, int> result = {d, u};

    for (auto [v, w] : E[u]) {
      if (v == p)
        continue;

      result = max(result, dfs(v, u, d + w));
    }

    return result;
  };

  auto [wa, a] = dfs(0, -1, 0);
  auto [wb, b] = dfs(a, -1, 0);

  vector<int> path;

  for (int cur = b; cur != -1; cur = parent[cur])
    path.push_back(cur);

  reverse(path.begin(), path.end());
  vector<int> sizes;

  for (size_t i = 0; i < path.size(); i++) {
    int prevNode = i > 0 ? path[i - 1] : -1;
    int nextNode = i + 1 < path.size() ? path[i + 1] : -1;

    function<int(int, int, int)> getDepth = [&](int u, int p, int d) {
      int res = d;
      for (auto [v, w] : E[u]) {
        if (v == p || v == prevNode || v == nextNode)
          continue;
        res = max(res, getDepth(v, u, d + w));
      }
      return res;
    };

    sizes.push_back(getDepth(path[i], -1, 0));
  }

  int l = 0;
  int r = min(K, (int)path.size()) - 1;

  int maxSize = *max_element(sizes.begin(), sizes.begin() + r + 1);
  int res = max(depth[b] - depth[path[r]], sizes[l]);

  //   cout << l << " " << r << " " << res << endl;
  while (r < path.size() - 1) {
    l++;
    r++;

    // Sebenarnya menunjukkan depth max dari node-node path
    // mengapa sizes[l - 1] tidak dihapus?
    // Alasanya karena tidak menganggu perhitungan?
    // sizes[l - 1] jelas lebih kecil dari depth dari l sampai a
    // a = awal dari diameter tree
    
    maxSize = max(maxSize, sizes[r]);
    
    int a = max({depth[b] - depth[path[r]], depth[path[l]], maxSize});

    // cout << l << " " << r << " " << a << endl;
    res = min(res, a);
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