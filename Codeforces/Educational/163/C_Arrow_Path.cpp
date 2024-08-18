#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <vector>

using namespace std;

std::array<pair<int, int>, 4> moves = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};

void visit(std::vector<std::vector<bool>> &dp, std::string *grid, int i, int j,
           int n) {
  dp[i][j] = true;
  for (auto move : moves) {
    int ni = i + move.first;
    int nj = j + move.second;

    if (ni < 0 || ni >= 2)
      continue;
    if (nj < 0 || nj >= n)
      continue;

    nj += grid[ni][nj] == '>' ? 1 : -1;

    if (!dp[ni][nj]) {
        visit(dp, grid, ni, nj, n);
    }
  }
}

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    std::string grid[2];

    cin.ignore();
    for (int i = 0; i < 2; i++)
      getline(cin, grid[i]);

    // apakah dapat berada di situ
    std::vector<std::vector<bool>> dp(2, std::vector<bool>(n, false));

    visit(dp, grid, 0, 0, n);

    if (dp[1][n - 1])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}