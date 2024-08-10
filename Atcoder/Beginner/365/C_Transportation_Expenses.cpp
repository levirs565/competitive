#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
  i64 N, M;
  cin >> N >> M;

  vector<i64> A(N);

  i64 sum = 0;
  for (auto &a : A) {
    cin >> a;
    sum += a;
  }

  if (sum <= M) {
    cout << "infinite" << endl;
    return;
  }

  i64 L = 0, R = M + 1;
  i64 ans = 0;

  while (L <= R) {
    i64 mid = (L + R) / 2;
    i64 sub = 0;
    for (auto a : A)
      sub += min(a, mid);

    if (sub > M) {
      R = mid - 1;
    } else {
      ans = mid;
      L = mid + 1;
    }
  }
  if (ans >= M)
    cout << "infinite" << endl;
  else
    cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}