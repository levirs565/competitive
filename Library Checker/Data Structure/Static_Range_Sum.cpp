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
  int N, Q;
  cin >> N >> Q;

  vector<i64> prefix;
  prefix.push_back(0);

  for (int i = 0; i < N; i++) {
    i64 a;
    cin >> a;
    prefix.push_back(prefix.back() + a);
  }

  while (Q--) {
    int l, r;
    cin >> l >> r;
    cout << prefix[r] - prefix[l] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}