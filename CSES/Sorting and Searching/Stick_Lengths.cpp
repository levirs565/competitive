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
  for (auto &a : A)
    cin >> a;

  auto getCost = [&](int to) {
    i64 result = 0;
    for (auto a : A)
      result += abs(a - to);
    return result;
  };

  sort(A.begin(), A.end());

  cout << min(getCost(A[N / 2]), getCost(A[N / 2 + 1])) << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}