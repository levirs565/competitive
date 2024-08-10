#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory.h>
#include <queue>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

vector<bool> visited;
vector<vector<int>> E;
vector<int> H;

int cminH;
int csz;

void dfs(int i) {
  visited[i] = true;
  cminH = min(cminH, H[i]);
  csz++;

  for (auto n : E[i]) {
    if (visited[n])
      continue;

    dfs(n);
  }
}

void solution() {
  int N, K, Q;
  cin >> N >> K >> Q;

  H.assign(N, 0);
  for (auto &i : H)
    cin >> i;

  E.assign(N, {});
  for (int i = 0; i < K; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  vector<pair<int, int>> cmps; // min, count
  i64 sum = 0;

  visited.assign(N, false);
  for (int i = 0; i < N; i++) {
    if (!visited[i]) {
      csz = 0;
      cminH = INT_MAX;

      dfs(i);
      cmps.push_back({cminH, csz});

      sum += i64(cminH) * csz;
    }
  }

  sort(cmps.begin(), cmps.end());

  auto [minH, minHCount] = cmps.front();
  cmps.erase(cmps.begin());

  vector<int> decC;

  for (auto [m, c] : cmps) {
    decC.push_back((m - minH) * c);
  }

  sort(decC.begin(), decC.end(), std::greater<int>());

  for (int i = 0; i < min(int(decC.size()), Q); i++) {
    sum -= decC[i];
  }

  cout << sum << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}