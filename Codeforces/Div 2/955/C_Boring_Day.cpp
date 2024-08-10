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

int maxWin(std::vector<int> &numbers, int round, int l, int r) {
  int result = 0;
  int64_t sum = 0;
  for (int i = round; i < int(numbers.size()); i++) {
    sum += numbers[i];
    result = max(maxWin(numbers, i + 1, l, r) + (sum >= l && sum <= r ? 1 : 0),
                 result);
  }
  return result;
}

int dpWay(std::vector<int> &numbers, int l, int r) {
  // dp = jumlah max win saat i kartu tersedian
  // transisi,  dp[i] = max(dp[i - k] + apakah dari i - k sampai i memenuhi )
  std::vector<int> dp(numbers.size() + 1, 0);
  dp[0] = 0;

  size_t prev = 1;
  int64_t sum = 0;
  for (size_t i = 1; i <= numbers.size(); i++) {
    dp[i] = dp[i - 1];

    sum += numbers[numbers.size() - i];

    cout << sum << ",";

    while (sum > r && prev < i) {
      if (prev > 0)
        sum -= numbers[numbers.size() - prev];
      prev++;
    }

    cout << sum << " ";

    if (sum >= l && prev < i) {
    //   for (size_t j = prev; j < i; j++) {
        dp[i] = max(dp[i], dp[prev - 1] + 1);
    //   }
    } else if (sum >= l && prev == i) {
        dp[i] = max(dp[i], dp[i - 1] + 1);
    }
    cout << "(" << i << "," << dp[i] << ") ";
  }

  return dp[numbers.size()];
}

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int n, l, r;
    cin >> n >> l >> r;
    std::vector<int> numbers(n);
    for (auto &i : numbers)
      cin >> i;

    cout << dpWay(numbers, l, r) << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}