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

  vector<int> A(N);

  for (auto &i : A) {
    cin >> i;
  }

  vector<int> dp(N + 2, INT_MIN);
  vector<int> prefixMax(N + 1, 0);
  vector<int> maxByDiff(N + 1, 0);

  for (int i = 1; i <= N; i++) {
    if (A[i - 1] > i) {
      dp[i] = dp[i - 1];
    } else {
      dp[i] = max(1, maxByDiff[i - A[i - 1]]);
      if (i - A[i - 1] >= 0) {
        dp[i] = max(dp[i], prefixMax[i - A[i - 1]]);
      }
      maxByDiff[i - A[i - 1]] = max(maxByDiff[i - A[i - 1]], dp[i] + 1);
    }
    prefixMax[i] = max(prefixMax[i - 1], dp[i] + 1);
  }

  int a = INT_MIN;
  for (int i = 1; i <= N; i++) {
    a = max(a, dp[i]);
  }

  cout << N - a << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}