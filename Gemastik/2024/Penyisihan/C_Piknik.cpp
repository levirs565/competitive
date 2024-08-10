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

void solution() {
  int N, M;

  cin >> N >> M;

  vector<vector<int>> E(N);

  for (int i = 0; i < M; i++) {
    int a;
    int b;
    cin >> a >> b;
    a--;
    b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  vector<bool> visited(N, false);
  int size = 0;
  auto dfs = [&](auto self, int n) -> void {
    visited[n] = true;
    size++;

    for (auto e : E[n]) {
      if (!visited[e]) {
        self(self, e);
      }
    }
  };

  int count = 0;
  int hasDewe = 0;
  for (int i = 0; i < N; i++) {
    if (!visited[i]) {
      size = 0;
      dfs(dfs, i);
      if (size == 1) {
        hasDewe++;
      } else {
        count++;
      }
    }
  }

  if (hasDewe > 1)
    count++;

  cout << count << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}