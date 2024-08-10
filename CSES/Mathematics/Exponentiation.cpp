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
i64 mod = 1e9+7;

i64 binpow(i64 a, i64 b) {
    if (b == 0)
        return 1;
    if (b % 2 == 1) {
        return ((binpow(a, b - 1) % mod) * (a % mod)) % mod;
    }
    i64 res = binpow(a, b / 2) % mod;
    return (res * res) % mod;
}

void solution() {
    int N;
    cin >> N;
    while (N--) {
        int a, b;
        cin >> a >> b;
        cout << binpow(a, b) << endl;
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}