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
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
  i64 N, K;
  cin >> N >> K;

  i64 depth = floor(log(N * (K - 1) + 1) / log(K));
  i64 nodesToDepth = (pow(K, depth) - 1) / (K - 1);
  i64 nodeInDepth = pow(K, depth);
  i64 sisa = N - nodesToDepth;

  cout << sisa * K + nodeInDepth - sisa << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}