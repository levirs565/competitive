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
vector<vector<pair<int, int>>> E;

vector<bool> visited;
vector<pair<int, int>> pe;
vector<int> cycleNode, cycleEdge;

bool dfs(int at, int edge, int parent) {
  pe[at] = {parent, edge};
  visited[at] = true;
  bool visitParent = false;
  for (auto [to, edge] : E[at]) {
    if (!visitParent && to == parent) {
      visitParent = true;
      continue;
    }

    if (visited[to]) {
      int current = at;

      while (current != to) {
        cycleNode.push_back(current);
        cycleEdge.push_back(pe[current].second);
        current = pe[current].first;
      }
      cycleNode.push_back(to);
      cycleEdge.push_back(edge);

      cout << cycleNode.size() << endl;
      for (auto n : cycleNode) {
        cout << n << " ";
      }
      cout << endl;
      for (auto e : cycleEdge) {
        cout << e << " ";
      }
      cout << endl;

      return true;
    }

    if (dfs(to, edge, at)) {
      return true;
    }
  }
  return false;
}

void solution() {
  cin >> N >> M;
  E.resize(N);
  visited.resize(N);
  visited.assign(N, false);
  pe.resize(N);

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    E[u].push_back({v, i});
    E[v].push_back({u, i});
  }

  for (int i = 0; i < N; i++) {
    if (!visited[i] && dfs(i, -1, -1)) {
      return;
    }
  }
  cout << "-1" << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}