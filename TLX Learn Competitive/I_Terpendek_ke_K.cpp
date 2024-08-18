#include <algorithm>
#include <array>
#include <climits>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using i64 = int64_t;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> A(N);

  for (auto& a : A) cin >> a;

  sort(A.begin(), A.end());

  cout << A[K - 1] << endl;

  return 0;
}