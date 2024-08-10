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

  vector<i64> A(N);

  for (auto &a : A)
    cin >> a;

  vector<i64> dp(N);
  i64 ans = LONG_LONG_MIN;

  for (int i = 0; i < M; i++) {
    dp[i] = i > 0 ? max(dp[i - 1], A[i]) : A[i];
    ans = max(ans, dp[i]);
  }

  for (int i = M; i < N; i++) {
    dp[i] = max({dp[i - 1], dp[i - M] + A[i], A[i]});
    ans = max(ans, dp[i]);
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}