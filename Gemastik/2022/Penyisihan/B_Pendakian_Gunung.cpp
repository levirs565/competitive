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

vector<int> h;
int N, M;
vector<vector<int>> e;

void solution() {
  cin >> N >> M;

  h.resize(N);
  for (auto &i : h)
    cin >> i;

  e.assign(N, {});
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }

  using Item = pair<int, int>; // cost
  priority_queue<Item, vector<Item>, greater<Item>> q;
  vector<int> p(N, -1);
  vector<int> cost(N, INT_MAX);
  vector<bool> visited(N, false);

  cost[0] = 0;
  q.push({0, 0});

  while (!q.empty()) {
    auto [c, i] = q.top();
    q.pop();

    if (visited[i]) continue;

    visited[i] = true;
    cout << i << endl;
    for (auto t : e[i]) {
      int nc = c + abs(h[i] - h[t]);

      if (cost[t] > nc) {
        p[t] = i;
        cost[t] = nc;
        if (!visited[t]) {
          q.push({cost[t], t});
        }
      }
    }
  }

  for (int i = 0; i < N; i++) {
    i64 maxDelta = 0;

    int current = i;
    do {
        int parent = p[current];
        // when set c to p
        i64 delta = abs(h[current] - h[parent]);
        if (current != i) 
            delta += 
    } while (current != -1);
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}