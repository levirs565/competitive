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

  vector<int> A(N);
  vector<int> prefixXor;

  i64 result = 0;
  for (auto &a : A) {
    cin >> a;
    prefixXor.push_back((prefixXor.empty() ? 0 : prefixXor.back()) ^ a);
    result -= a;
  }

  for (int i = 0; i <= 30; i++) {
    int oneCount = 0;

    for (auto p : prefixXor) {
      if (p & (1 << i)) {
        oneCount++;
      }
    }

    result += (i64) oneCount * (N - oneCount + 1) * (1 << i);
  }

  cout << result << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}