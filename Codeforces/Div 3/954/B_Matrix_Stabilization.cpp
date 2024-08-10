#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <limits>
#include <set>
#include <vector>

using namespace std;

std::array<pair<int, int>, 4> neighborList = {
    {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}};

int maxNeighboar(std::vector<int> &matrix, int n, int m, int i, int j) {
  int r = 0;
  for (auto [di, dj] : neighborList) {
    int ni = i + di;
    int nj = j + dj;
    if (ni < 0 || nj < 0 || ni >= n || nj >= m)
      continue;

    int index = ni * m + nj;
    r = max(r, matrix.at(index));
  }

  return r;
}

bool check(std::vector<int> &matrix, int n, int m, int i, int j) {
  int currentIndex = i * m + j;
  for (auto [di, dj] : neighborList) {
    int ni = i + di;
    int nj = j + dj;
    if (ni < 0 || nj < 0 || ni >= n || nj >= m)
      continue;

    int index = ni * m + nj;
    // cout << matrix[currentIndex] << " " << matrix[index] << endl;
    if (matrix.at(currentIndex) <= matrix.at(index))
      return false;
  }

  return true;
}

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    std::vector<int> matrix(n * m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> matrix.at(i * m + j);

    // cout << n << " " << m << endl;

    std::set<std::pair<int, int>> queue;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (check(matrix, n, m, i, j))
          queue.insert({i, j});

    // cout << queue.size() << endl;
    while (queue.size() > 0) {
      auto [i, j] = *queue.begin();
      matrix.at(i * m + j) = maxNeighboar(matrix, n, m, i, j);

      if (!check(matrix, n, m, i, j))
        queue.erase(queue.begin());

      for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
          int ni = i + di;
          int nj = j + dj;
          if (ni < 0 || nj < 0 || ni >= n || nj >= m)
            continue;

          if (check(matrix, n, m, ni, nj))
            queue.insert({ni, nj});
          else {
            auto p = queue.find({ni, nj});
            if (p != queue.end())
              queue.erase(p);
          }
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cout << matrix.at(i * m + j) << " ";
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