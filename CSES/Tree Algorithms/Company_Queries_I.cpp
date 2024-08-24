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
#include <cmath>

using namespace std;

using i64 = int64_t;

constexpr int logK = 20;

void solution()
{
  int N, Q;
  cin >> N >> Q;

  vector<vector<int>> P(N, vector<int>(logK, -1));
  for (int u = 1; u < N; u++)
  {
    cin >> P[u][0];
    P[u][0]--;
  }

  for (int i = 1; i < logK; i++)
  {
    for (int u = 0; u < N; u++)
    {
      if (P[u][i - 1] != -1)
        P[u][i] = P[P[u][i - 1]][i - 1];
    }
  }

  while (Q--)
  {
    int x, k;
    cin >> x >> k;
    x--;

    int curr = x;

    for (int i = 0; i < logK; i++) {
      if (k & (1 << i) && curr != -1) {
        curr = P[curr][i];
      }
    }

    if (curr != -1)
      curr++;

    cout << curr << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}