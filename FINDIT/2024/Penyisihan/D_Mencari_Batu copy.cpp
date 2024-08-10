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
#include <ranges>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

i64 cache[5001][5001] = {};
bool cached[5001][5001] = {};

vector<vector<i64>> split;

void solution() {

  int N;
  cin >> N;
  vector<int> W(N);

  for (int &i : W)
    cin >> i;

  vector<int> prefixSum;
  prefixSum.push_back(0);

  for (int &i : W)
    prefixSum.push_back(prefixSum.back() + i);

  split = vector(N + 1, vector<i64>(N + 1, 0));

  function<i64(vector<int> &, int, int)> findMax = [&](vector<int> &sum, int L,
                                                       int R) -> i64 {
    if (L >= R)
      return 0;

    if (cached[L][R])
      return cache[L][R];
    tuple<i64, int, int> result = {0, 0, 1};
    for (int i = L; i < R; i++) {
      i64 kiri = sum[i] - sum[L - 1];
      i64 kanan = sum[R] - sum[i];
      if (kiri > kanan) {
        result = max(result, {kanan + findMax(sum, i + 1, R), i, 2});
      } else if (kanan > kiri) {
        result = max(result, {kiri + findMax(sum, L, i), i, 1});
      } else {
        result = max({result,
                      {kanan + findMax(sum, i + 1, R), i, 2},
                      {kiri + findMax(sum, L, i), i, 1}});
      }
    }

    auto [a, b, c] = result;
    cache[L][R] = a;
    cached[L][R] = true;

    split[L][R] = b;

    return a;
  };

  cout << findMax(prefixSum, 1, N) << endl;

  for (int L = 1; L <= N; L++) {
    for (int R = L + 1; R <= N; R++) {
      if (cached[L][R])
        cout << L << " " << R << " " << split[L][R] << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}