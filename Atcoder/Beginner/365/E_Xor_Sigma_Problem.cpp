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
  vector<i64> prefixXor;
  prefixXor.push_back(0);

  for (auto &a : A) {
    cin >> a;
    prefixXor.push_back(prefixXor.back() ^ a);
  }

  i64 result = 0;
  for (int i = 1; i <= N - 1; i++) {
    for (int j = i + 1; j <= N; j++) {
      result += prefixXor[j] ^ prefixXor[i - 1];
    }
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