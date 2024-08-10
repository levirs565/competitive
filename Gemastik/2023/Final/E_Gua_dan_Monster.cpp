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

int N, S, F;

int dp[3001][3001]; // dp[node][koin] = maxJumlahEmas
bool visited[3001];
bool hasCoin[3001];
int emas[3001];
vector<pair<int, int>> E[3001];

stack<int> topologySorted;

void topologySort(int node) {
  visited[node] = true;

  for (auto [other, _] : E[node]) {
    if (!visited[other])
      topologySort(other);
  }

  topologySorted.push(node);
}

void solution() {
  cin >> N >> S >> F;
  S--;
  F--;

  for (int i = 0; i < N; i++) {
    cin >> emas[i];
  }

  int K;
  cin >> K;
  while (K--) {
    int a, b, m;
    cin >> a >> b >> m;
    a--;
    b--;
    E[a].push_back({b, m});
  }

  int C;
  cin >> C;
  for (int i = 0; i < C; i++) {
    int a;
    cin >> a;
    a--;
    hasCoin[a] = true;
  }

  topologySort(S);

  dp[S][hasCoin[S]] = emas[S];

  while (!topologySorted.empty()) {
    auto node = topologySorted.top();
    topologySorted.pop();

    visited[node] = true;

    for (auto &[other, monster] : E[node]) {
      for (int koin = 0; koin <= C; koin++) {
        if (dp[node][koin] == 0)
          continue;
        if (monster && koin == 0)
          continue;
        int newKoin = koin + int(hasCoin[other]) - monster;
        if (newKoin > C || newKoin < 0)
          continue;
        int newEmas = dp[node][koin] + emas[other];
        if (newEmas > dp[other][newKoin]) {
          dp[other][newKoin] = newEmas;
        }
      }
    }
  }

  int maxEmas = -1;
  for (int koin = 0; koin <= C; koin++)
    if (dp[F][koin] != 0)
      maxEmas = max(dp[F][koin], maxEmas);

  cout << maxEmas << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}