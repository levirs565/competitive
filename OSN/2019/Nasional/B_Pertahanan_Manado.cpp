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
  int N, M, S;

  cin >> N >> M >> S;

  vector<tuple<int, int, int>> paket(M); // end, start, price

  for (auto &[s, e, p] : paket)
    cin >> s >> e >> p;

  for (int i = 1; i <= N; i++)
    paket.push_back(make_tuple(i, i, S));

  vector<i64> dp(N + 1, LONG_LONG_MAX);
  sort(paket.begin(), paket.end());
  dp[0] = 0;

  using Item = pair<i64, int>; // Nilai, index

  priority_queue<Item, vector<Item>, greater<Item>> pq;
  pq.push({0, 0});

  int last = 1;
  for (auto [s, e, p] : paket) {
    while (!pq.empty() && pq.top().second < s - 1) {
      pq.pop();
    }
    dp[e] = min(dp[e], pq.top().first + (i64)p);
    pq.push({dp[e], e});
  }

  cout << dp[N] << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}