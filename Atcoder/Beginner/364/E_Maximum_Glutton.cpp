#include <algorithm>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
  int N;
  cin >> N;
  int X, Y;
  cin >> X >> Y;

  vector<pair<int, int>> A(N);

  for (auto &a : A)
    cin >> a.first >> a.second;

  int dp[N + 1][10'000 + 1]; // minimal second for X and count

  for (auto [fa, sa] : A) {
                
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}