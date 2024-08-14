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
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &a : A)
    cin >> a;

  auto getCost = [&](int to) {
    i64 result = 0;
    for (auto a : A)
      result += abs(a - to);
    return result;
  };

  int l = *min_element(A.begin(), A.end());
  int r = *max_element(A.begin(), A.end());

  while (r - l >= 3) {
    int x1 = (2 * i64(l) + i64(r)) / 3;
    int x2 = (i64(l) + 2 * i64(r)) / 3;

    i64 v1 = getCost(x1);
    i64 v2 = getCost(x2);

    if (v1 <= v2) {
      r = x2;
    } else {
      l = x1;
    }
  }

  i64 ans = min(getCost(l), getCost(r));
  if (r - l == 2) {
    ans = min(ans, getCost(l + 1));
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}