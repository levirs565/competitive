#include <algorithm>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

// i64 cache[5000][5000] = {};
// bool cached[5000][5000] = {};

// i64 findMax(vector<int> &sum, int L, int R) {
//   if (L >= R)
//     return 0;

//   if (cached[L][R])
//     return cache[L][R];
//   i64 result = 0;
//   for (int i = L; i < R; i++) {
//     i64 kiri = sum[i] - sum[L - 1];
//     i64 kanan = sum[R] - sum[i];
//     if (kiri > kanan) {
//       result = max(result, kanan + findMax(sum, i + 1, R));
//     } else if (kanan > kiri) {
//       result = max(result, kiri + findMax(sum, L, i));
//     } else {
//       result = max(
//           {result, kanan + findMax(sum, i + 1, R), kiri + findMax(sum, L,
//           i)});
//     }
//   }
//   cache[L][R] = result;
//   cached[L][R] = true;

//   return result;
// }

i64 dp[5001][5001];
i64 maxLeft[5001][5001];

void solution() {
  int N;
  cin >> N;
  vector<i64> W(N);

  for (i64 &i : W)
    cin >> i;

  vector<i64> prefixSum;
  prefixSum.push_back(0);

  for (i64 &i : W)
    prefixSum.push_back(prefixSum.back() + i);

  auto getSum = [&](int l, int r) -> i64 {
    if (l > r || l == 0)
      return 0;
    return prefixSum[r] - prefixSum[l - 1];
  };

  maxLeft[1][1] = getSum(1, 1);
  for (int r = 2; r <= N; r++) {
    int midLeft = r - 1;
    int midRight = r - 1;
    i64 maxValue = 0;
    for (int l = r - 1; l >= 1; l--) {
      if (l - r == 1) {
        maxValue = min(W[l - 1], W[r - 1]);
        dp[l][r] = maxValue;
      } else {
        if (getSum(midRight + 1, r) <= getSum(l, midRight))
          maxValue =
              max(maxValue, dp[midRight + 1][r] + getSum(midRight + 1, r));
        while (midRight - 1 >= l &&
               getSum(midRight, r) <= getSum(l, midRight - 1)) {
          maxValue = max(maxValue, dp[midRight][r] + getSum(midRight, r));
          midRight--;
        }

        // slow way
        // i64 aya = 0;
        // for (int mL = r - 1; mL >= l; mL--) {
        //   if (getSum(mL + 1, r) > getSum(l, mL))
        //     break;
        //   aya = max(aya, dp[mL + 1][r] + getSum(mL + 1, r));
        // }

        dp[l][r] = maxValue;

        midLeft = min(midLeft, midRight);

        while (midLeft - 1 >= l &&
               getSum(l, midLeft) > getSum(midLeft + 1, r)) {
          midLeft--;
        }

        if (midLeft >= l && getSum(l, midLeft) <= getSum(midLeft + 1, r))
          dp[l][r] = max(dp[l][r], maxLeft[l][midLeft]);

        // Slow way

        // for (int mL = l; mL < r; mL++) {
        //   if (getSum(l, mL) > getSum(mL + 1, r))
        //     break;
        //   aya = max(aya, dp[l][mL] + getSum(l, mL));
        // }
      }
    }
    for (int l = 1; l <= r; l++) {
      if (l == r) {
        maxLeft[l][r] = getSum(l, r);
      } else {
        maxLeft[l][r] = max(maxLeft[l][r - 1], dp[l][r] + getSum(l, r));
      }
    }
  }

  cout << dp[1][N] << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}