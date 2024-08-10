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

i64 mod = 1000000;

i64 cache[1'001];
bool cached[1'001];

i64 get(int N) {
  if (N < 0)
    return 0;
  if (N == 0)
    return 1;
  if (N == 1)
    return 1;

  if (!cached[N]) {
    cache[N] = (get(N - 1) + get(N - 3)) % mod;
    cached[N] = true;
  }
  return cache[N];
}

void solution() {
  int N;
  cin >> N;
  cout << get(N) << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}