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
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

i64 mod = 1e9 + 7;
int h;

i64 cache[101][10'001];

i64 f(int n, int w) {
  if (w == 0 || n == 0)
    return 1;

  i64 result = 0;

  if (cache[w][n] != -1)
    return cache[w][n];

  for (int i = 0; i <= min(n, h); i++) {
    result += f(n - i, w - 1) % mod;
    result %= mod;
  }

  cache[w][n] = result;
  return result;
}

void solution() {
  int n, w;
  cin >> n >> w >> h;

  fill(&cache[0][0], &cache[100][10'000] + 1, -1);
  i64 result = f(n, w);
  i64 flat = 1;

  for (int i = 1; i <= h; i++) {
    int filled = n / i;
    if (filled >= w)
      flat++;
    flat %= mod;
  }

  cout << (result - flat) % mod << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}