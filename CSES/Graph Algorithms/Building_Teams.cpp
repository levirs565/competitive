#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

using i64 = int64_t;

int N, M;
vector<bool> visited;
vector<vector<int>> E;
vector<int> team;

bool dfs(int at, int parent, int t) {
  team[at] = t;
  visited[at] = true;
  for (auto to : E[at]) {
    if (to == parent)
      continue;

    if (!visited[to]) {
      if (!dfs(to, at, (t + 1) % 2)) {
        return false;
      }
    } else if (team[to] == t) {
      return false;
    }
  }

  return true;
}

void solution() {
  cin >> N >> M;
  visited.resize(N);
  visited.assign(N, false);
  team.resize(N, -1);
  E.resize(N);

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  for (int i = 0; i < N; i++) {
    if (!visited[i]) {
      if (!dfs(i, -1, 0)) {
        cout << "IMPOSSIBLE" << endl;
        return;
      }
    }
  }

  for (auto t : team)
    cout << t + 1 << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}