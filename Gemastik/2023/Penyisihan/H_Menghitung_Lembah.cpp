#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
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

i64 mod = 998'244'353;

i64 cache[1001][11];
bool cached[1001][11];

i64 count(int n, int k) {
  if (cached[n][k])
    return cache[n][k];

  cached[n][k] = true;
  if (n >= 1 && k == 0) {
    cache[n][k] = n == 1 ? 1 : (2 * count(n - 1, 0)) % mod;
  }
  if (n >= 2 && k >= 1 && k <= n)
    cache[n][k] = ((2 * k + 2) * count(n - 1, k) % mod +
                   (n - 2 * k) * count(n - 1, k - 1) % mod) %
                  mod;
  return cache[n][k];
}

void solution() {
  int N, K;
  cin >> N >> K;

  cout << count(N, K) << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}