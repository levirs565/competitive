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
  int N, M;
  cin >> N >> M;

  vector<tuple<int, i64, bool>> obat(N);

  for (auto &[h, k, d] : obat)
    cin >> h >> k >> d;

  vector<i64> dp(M + 1, LONG_LONG_MIN);
  dp[0] = 0;

  for (auto &[h, k, d] : obat) {
    for (int harga = M; harga >= 0; harga--) {
      if (dp[harga] == LONG_LONG_MIN)
        continue;

      for (int newHarga = harga + h, cnt = 1; newHarga <= M;
           newHarga += h, cnt++) {
        dp[newHarga] = max(dp[newHarga], dp[harga] + i64(cnt) * k);

        if (d)
          break;
      }
    }
  }

  i64 maxVitamin = 0;
  for (int i = 0; i <= M; i++) {
    maxVitamin = max({maxVitamin, dp[i]});
  }

  cout << maxVitamin << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}