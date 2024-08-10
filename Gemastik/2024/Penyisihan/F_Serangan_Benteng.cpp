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

int P, Q;

unordered_map<i64, i64> cache;

i64 solve(i64 A) {
  if (A == 0)
    return 0;

  if (cache.count(A) > 0)
    return cache[A];

  i64 result = A;

  if (A % 2 == 0) {
    result = min(result, P + solve(A / 2));
  } else {
    result = min(result, A % 2 + P + solve(A / 2));
  }

  if (A % 3 == 0) {
    result = min(result, Q + solve(A / 3));
  } else {
    result = min(result, A % 3 + Q + solve(A / 3));
  }

  cache[A] = result;

  return result;
}

void solution() {
  int N;
  cin >> N >> P >> Q;

  for (int i = 0; i < N; i++) {
    i64 A;
    cin >> A;
    cout << solve(A) << endl;
  }

  int a;
  cin >> a;

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}