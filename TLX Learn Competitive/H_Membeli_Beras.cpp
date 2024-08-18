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
  int N, X;
  cin >> N >> X;

  vector<tuple<double, int, int>> A(N); // per kg, semua, jumlah

  for (auto &[per, all, c] : A) {
    cin >> c;
  }

  for (auto &[per, all, c] : A) {
    cin >> all;
    per = (double)all / c;
  }

  sort(A.begin(), A.end(), std::greater());

  double result = 0;
  for (auto &[per, all, c] : A) {
    int ambil = min(X, c);
    result += per * ambil;
    X -= ambil;
  }

  cout << fixed << setprecision(5) << result << endl;

  return 0;
}