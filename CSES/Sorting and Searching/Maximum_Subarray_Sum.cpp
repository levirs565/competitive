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
  int N;
  cin >> N;
  vector<i64> A(N);
  for (auto &a : A)
    cin >> a;

  vector<i64> dp(N, LONG_LONG_MIN);
  dp[0] = A[0];
  i64 result = dp[0];
  for (int i = 1; i < N; i++) {
    dp[i] = max(dp[i - 1] + A[i], A[i]);
    result = max(result, dp[i]);
  }

  cout << result << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}