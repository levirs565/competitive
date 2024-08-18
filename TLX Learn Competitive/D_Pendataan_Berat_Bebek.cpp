#include <array>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;
using i64 = int64_t;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (auto& a : A) cin >> a;

  int Q;
  cin >> Q;
  while (Q--) {
    int L, R;
    cin >> L >> R;
    auto l = upper_bound(A.begin(), A.end(), L);
    auto u = upper_bound(A.begin(), A.end(), R);
    cout << u - l << endl;
  }

  return 0;
}