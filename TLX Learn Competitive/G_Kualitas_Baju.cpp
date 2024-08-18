#include <array>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
using i64 = int64_t;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (auto& a : A) cin >> a;

  sort(A.begin(), A.end());
  int half = N / 2;
  double med = N % 2 == 1 ? A[half] : (double(A[half - 1]) + A[half]) / 2.0;

  cout << fixed << setprecision(1) << med << endl;

  return 0;
}