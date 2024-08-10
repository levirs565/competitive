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

  vector<i64> A(N);

  for (auto &a : A)
    cin >> a;

  vector<i64> B = A;

  i64 count = 0;
  vector<i64> factorSum(N, 0);
  vector<i64> incCount(N, 0);

  for (int i = 0; i < N; i++) {
    int idx = i + 1;
    i64 diff = 0;
    if (A[i] < factorSum[i]) {
      diff = factorSum[i] - A[i];
      incCount[i] = diff;
      count += diff;
    }
    for (int j = 2 * idx; j <= N; j += idx) {
      factorSum[j - 1] += A[i] + diff;
    }
  }

  cout << count << " ";

  bool zero = count == 0;
  for (int K = 1; K < N; K++) {
    if (count != 0) {
      vector<i64> factorDiff(N + 1, 0);
      factorDiff[K] = A[K - 1];

      for (int i = 1; i <= N / K; i++) {
        if (factorDiff[i * K] == 0) {
          continue;
        }
        for (int j = 2 * K * i; j <= N; j += K * i) {
          factorSum[j - 1] -= factorDiff[i * K];
          i64 decCount = min(incCount[j - 1], factorDiff[i * K]);
          count -= decCount;
          incCount[j - 1] -= decCount;
          factorDiff[j] += decCount;
        }
      }
    }

    cout << count << " ";
    zero = count == 0;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}