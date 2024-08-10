#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

using i64 = int64_t;

constexpr int maxN = 2 * 1e5;
constexpr i64 mod = 1e9 + 7;

i64 binpow(i64 base, i64 to) {
  base %= mod;

  i64 result = 1;
  while (to) {
    if (to & 1) {
      result = result * base % mod;
    }

    base = base * base % mod;
    to /= 2;
  }

  return result;
}

i64 factorial[maxN + 1];
i64 inv[maxN + 1];

i64 C(int N, int K) { return (factorial[N] * inv[N - K] % mod) * inv[K] % mod; }

void solution() {
  factorial[0] = 1;
  for (int i = 1; i <= maxN; i++)
    factorial[i] = i * factorial[i - 1] % mod;

  inv[maxN] = binpow(factorial[maxN], mod - 2);
  for (int i = maxN; i >= 1; i--) {
    inv[i - 1] = inv[i] * i % mod;
  }

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    int count0 = 0, count1 = 0;

    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (a == 1)
        count1++;
      else
        count0++;
    }

    int minimal1 = k / 2 + 1;

    i64 result = 0;
    for (int i = minimal1; i <= min(count1, k); i++) {
      if (k - i > count0)
        continue;
      result += C(count1, i) * C(count0, k - i) % mod;
      result %= mod;
    }

    cout << result << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}