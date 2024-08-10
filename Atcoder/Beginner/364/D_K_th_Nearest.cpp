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

void solution() {
  int N, Q;
  cin >> N >> Q;

  vector<int> A(N);

  for (auto &a : A)
    cin >> a;

  sort(A.begin(), A.end());

  while (Q--) {
    int b, k;
    cin >> b >> k;

    int l = 0;
    int r = N - k;

    while (l < r) {
      int m = (l + r) / 2;

      if (b - A[m] > A[m + k] - b) {
        l = m + 1;
      } else {
        r = m;
      }
    }

    int d1 = abs(b - A[l]);
    int d2 = abs(A[l + k - 1] - b);
    // cout << l << " " << l + k << " " << d1 << " " << d2 << endl;
    cout << max(d1, d2) << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}