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

constexpr int maxN = 2 * 1e5 + 1;
i64 cache[maxN][26];
bool cached[maxN][26];

i64 solve(int N, string &action, char last) {
  if (N == 0)
    return 0;

  if (cached[N][last - 'A'])
    return cache[N][last - 'A'];

  char aoki = action[N - 1];
  i64 result = 0;
  if (last != 'R' && aoki != 'P') {
    result = (aoki == 'S') + solve(N - 1, action, 'R');
  }
  if (last != 'P' && aoki != 'S') {
    result = max(result, (aoki == 'R') + solve(N - 1, action, 'P'));
  }
  if (last != 'S' && aoki != 'R') {
    result = max(result, (aoki == 'P') + solve(N - 1, action, 'S'));
  }

  cached[N][last - 'A'] = true;
  cache[N][last - 'A'] = result;

  return result;
}

void solution() {
  int N;
  cin >> N;

  string action;
  cin >> action;

  cout << solve(N, action, ' ') << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}