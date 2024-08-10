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

i64 fastXor(i64 target) {
  if (target % 4 == 0)
    return target;
  if (target % 4 == 1)
    return 1;
  if (target % 4 == 2)
    return 1 + target;
  if (target % 4 == 3)
    return 0;
  return 0;
}

void solution() {
  i64 N, K, M;
  cin >> N >> K >> M;

  if (M % 2 == 0) {
    cout << "Kedua" << endl;
  } else {
    i64 nimSum = fastXor(N - 1) ^ fastXor(N - K - 1);
    if (nimSum == 0) {
      cout << "Kedua" << endl;
    } else {
      cout << "Pertama" << endl;
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