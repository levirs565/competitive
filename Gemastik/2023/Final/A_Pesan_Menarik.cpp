#include <algorithm>
#include <array>
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

constexpr i64 mod = 1e9 + 7;

i64 fact(i64 n) {
  i64 res = 1;
  for (i64 i = 1; i <= n; i++) {
    res *= i;
    res %= mod;
  }

  return res;
}

void solution() {
  i64 N;
  cin >> N;

  i64 evenCount = 0;
  i64 oddCount = 0;

  for (int i = 0; i < 10; i++) {
    int j;
    cin >> j;
    if (j == 0)
      evenCount++;
    else
      oddCount++;
  }

  if (oddCount % 2 != N % 2) {
    cout << "0" << endl;
  } else {
    auto calc = [&](i64 n) {
      auto calcInner = [&](auto self, i64 n) -> i64 {
        if (n < oddCount)
          return 0;
        if (n == oddCount) {
          return fact(oddCount);
        } else {
          i64 choose = n * (n - 1) / 2;
          // return (((self(self, n - 2) * (choose % mod)) % mod) * 10) % mod;
          return (self(self, n - 2) * choose * 10) % mod;
        }
      };

      return calcInner(calcInner, n);
    };

    cout << calc(N) << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}