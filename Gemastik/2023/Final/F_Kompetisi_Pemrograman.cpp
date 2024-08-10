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
  int N, M, K;
  cin >> N >> M >> K;

  vector<int> nilai(N);
  vector<int> provinsi(N);

  for (auto &i : nilai)
    cin >> i;
  for (auto &i : provinsi) {
    cin >> i;
    i--;
  }

  vector<pair<int, int>> finalis(M); // nilai, index

  for (int i = 0; i < N; i++) {
    finalis[provinsi[i]] = max(finalis[provinsi[i]], {nilai[i], i});
  }

  int count = M;

  while (K--) {
    int a;
    cin >> a;
    a--;
    if (finalis[provinsi[a]].second != a) {
      count++;
    }
  }

  cout << count << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}