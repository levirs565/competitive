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

  vector<pair<int, int>> A(N);

  for (int i = 0; auto &a : A) {
    cin >> a.first;
    a.second = i;
    i++;
  }

  sort(A.begin(), A.end(), std::greater<pair<int, int>>());

  cout << A[1].second + 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}