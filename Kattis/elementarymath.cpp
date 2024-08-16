#include <climits>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
  int N;
  cin >> N;

  vector<pair<int, int>> A(N);
  map<i64, int> resultSet;

  for (auto &[a, b] : A) {
    cin >> a >> b;
    resultSet.insert({a + b, 0});
    resultSet.insert({a - b, 0});
    resultSet.insert({(i64)a * b, 0});
  }

  int gN = 2 + N + resultSet.size();
  int s = 0, t = gN - 1;
  vector<vector<int>> gE(gN);
  vector<bool> visited(gN, false);
  vector<vector<pair<int, int>>> flow(gN, vector<pair<int, int>>(gN));
  vector<vector<char>> signs(gN, vector<char>(gN));

  int resultNodeIndex = N + 1;

  auto connect = [&](int from, int to) {
    gE[from].push_back(to);
    gE[to].push_back(from);

    flow[from][to] = {0, 1};
    flow[to][from] = {0, 0};
  };

  for (auto &[r, i] : resultSet) {
    i = resultNodeIndex;
    resultNodeIndex++;
    connect(i, t);
  }

  for (int i = 1; i <= N; i++) {
    auto [a, b] = A[i - 1];
    connect(s, i);
    connect(i, resultSet[a + b]);
    signs[i][resultSet[a + b]] = '+';
    connect(i, resultSet[a - b]);
    signs[i][resultSet[a - b]] = '-';
    connect(i, resultSet[(i64)a * b]);
    signs[i][resultSet[i64(a) * b]] = '*';
  }

  auto dfs = [&](auto self, int at, int bottleneck) {
    if (at == t)
      return bottleneck;

    visited[at] = true;

    for (auto to : gE[at]) {
      if (visited[to])
        continue;
      auto &[f, c] = flow[at][to];

      if (c - f == 0)
        continue;

      int newBottleneck = self(self, to, min(bottleneck, c - f));

      if (newBottleneck > 0) {
        f += newBottleneck;
        flow[to][at].first -= newBottleneck;

        return newBottleneck;
      }
    }

    return 0;
  };

  int bottleneck;
  int maxFlow = 0;

  do {
    visited.assign(N, false);
    bottleneck = dfs(dfs, s, INT_MAX);
    maxFlow += bottleneck;
  } while (bottleneck != 0);

  if (maxFlow < N) {
    cout << "impossible" << endl;
  } else {
    for (int i = 1; i <= N; i++) {
      auto [a, b] = A[i - 1];
      char sign;
      for (auto to : gE[i]) {
        if (to == s)
          continue;
        if (flow[i][to].first == 0)
          continue;

        sign = signs[i][to];
        break;
      }

      cout << a << " " << sign << " " << b << " = ";
      if (sign == '+')
        cout << a + b;
      else if (sign == '-')
        cout << a - b;
      else if (sign == '*')
        cout << (i64)a * b;
      cout << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}