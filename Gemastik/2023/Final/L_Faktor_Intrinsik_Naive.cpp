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

  for (int K = 0; K < N; K++) {
    if (K > 0)
      A[K - 1] = 0;
    vector<i64> factorSum(N, 0);
    for (int i = 0; i < N; i++) {
      int idx = i + 1;
      for (int j = 2 * idx; j <= N; j += idx) {
        factorSum[j - 1] += A[i];
      }
    }

    i64 count = 0;
    for (int i = 0; i < N; i++) {
      i64 sum = factorSum[i];
      if (A[i] < sum) {
        i64 diff = sum - A[i];
        count += diff;
        int idx = i + 1;
        for (int j = 2 * idx; j <= N; j += idx) {
          factorSum[j - 1] += diff;
        }
      }
    }
    cout << count << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}