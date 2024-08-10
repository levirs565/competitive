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

  vector<int> B(N);
  for (auto &b : B)
    cin >> b;
  vector<int> J(N);
  for (auto &j : J)
    cin >> j;

  vector<int> dp;

  int jual = 0;
  for (int i = 0; i < N; i++) {
    if (i == 0)
      dp.push_back(B[i]);
    else
      dp.push_back(min(B[i], dp.back()));

    if (i >= 2) {
      jual = max(J[i] - dp[i - 2], jual);
    }
  }

  if (jual == 0)
    cout << "tidak mungkin" << endl;
  else
    cout << jual << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}