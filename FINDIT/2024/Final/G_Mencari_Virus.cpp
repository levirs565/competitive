#include <algorithm>
#include <array>
#include <climits>
#include <exception>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;
using i64 = int64_t;

int main() {
  int N, M, U, V;
  cin >> N >> M >> U >> V;

  vector<pair<int, int>> jahat(U);

  for (auto &[i, j] : jahat) {
    cin >> i >> j;
    i--;
    j--;
  }

  vector<pair<int, int>> baik(V);

  for (auto &[i, j] : baik) {
    cin >> i >> j;
    i--;
    j--;
  }

  vector<vector<int>> type(N, vector(M, 0)); // 0 kosong, 1 baik, 2 jahat
  vector<vector<int>> dist(N, vector(M, INT_MAX));
  vector<vector<bool>> visited(N, vector(M, false));

  using Item = tuple<int, int, int>;
  priority_queue<Item, vector<Item>, greater<Item>> q;

  for (auto &[i, j] : baik) {
    type[i][j] = 1;
    dist[i][j] = 0;
    q.push({0, i, j});
  }

  for (auto &[i, j] : jahat) {
    type[i][j] = 2;
    dist[i][j] = 0;
    q.push({0, i, j});
  }

  array<pair<int, int>, 4> nlist = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

  while (!q.empty()) {
    auto [c, i, j] = q.top();
    q.pop();

    if (visited[i][j])
      continue;
    visited[i][j] = true;
    int ctype = type[i][j];

    for (auto &[di, dj] : nlist) {
      int ni = i + di, nj = j + dj;

      if (ni < 0 || nj < 0 || ni >= N || nj >= M) {
        continue;
      }

      int nc = dist[i][j] + 1;
      if (nc < dist[ni][nj]) {
        dist[ni][nj] = nc;
        type[ni][nj] = ctype;
        q.push({nc, ni, nj});
      } else if (nc == dist[ni][nj] && ctype == 1) {
        dist[ni][nj] = nc;
        type[ni][nj] = ctype;
        q.push({nc, ni, nj});
      }
    }
  }

  int baikC = 0, jahatC = 0;

  for (auto &r : type) {
    for (auto &c : r) {
      // cout << c << ",";
      if (c == 1)
        baikC++;
      else if (c == 2)
        jahatC++;
      else {
        throw logic_error("Do not know");
      }
    }
    // cout << endl;
  }

  // cout << baikC << " " << jahatC << endl;

  if (baikC == jahatC)
    cout << "TIE!" << endl;
  else if (baikC > jahatC)
    cout << "WIN! " << baikC - jahatC << endl;
  else
    cout << "LOSE! " << jahatC - baikC << endl;

  return 0;
}