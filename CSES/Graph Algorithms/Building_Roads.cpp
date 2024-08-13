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
vector<int> componentHead;

void dfs(int at, int parent) {
  visited[at] = true;
  for (auto to : E[at]) {
    if (!visited[to])
      dfs(to, at);
  }
}

void solution() {
  cin >> N >> M;
  visited.resize(N);
  visited.assign(N, false);
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
      componentHead.push_back(i);
      dfs(i, -1);
    }
  }

  cout << componentHead.size() - 1 << endl;

  for (int i = 1; i < (int)componentHead.size(); i++) {
    cout << componentHead[0] + 1 << " " << componentHead[i] + 1 << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}