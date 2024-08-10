#include <algorithm>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ranges>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
  i64 N, Q;
  cin >> N >> Q;

  vector<i64> W(N);
  for (auto &i : W)
    cin >> i;

  sort(W.begin(), W.end());
  
  vector<i64> P(N + 1);
  P[0] = 0;
  for (int i = 0; i < N; i++)
    P[i + 1] = P[i] + W[i];

  while (Q--) {
    i64 L, R;
    cin >> L >> R;

    i64 lc = lower_bound(W.begin(), W.end(), L) - W.begin();
    i64 rc = upper_bound(W.begin(), W.end(), R) - W.begin();

    i64 a = lc * L - P[lc];
    i64 b = P[N] - P[rc] - (N - rc) * R;
    cout << a + b << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}