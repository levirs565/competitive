#include <algorithm>
#include <array>
#include <climits>
#include <exception>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
using i64 = int64_t;

int main() {
  int N;
  cin >> N;

  vector<pair<i64, i64>> P(N);

  for (auto &[i, j] : P) {
    i64 a, b;
    cin >> a >> b;
    i = a + b;
    j = a - b;
  }

  auto towerPositionBound = [&](i64 R) {
    i64 mLA = LONG_LONG_MIN, mUA = LONG_LONG_MAX;
    i64 mLB = LONG_LONG_MIN, mUB = LONG_LONG_MAX;
    for (auto &[i, j] : P) {
      i64 lA = i - R, uA = i + R;
      i64 lB = j - R, uB = j + R;
      if (uA < i || uB < j) {
        throw domain_error("integer overflow" );
      }
      mLA = max(mLA, lA);
      mUA = min(mUA, uA);
      mLB = max(mLB, lB);
      mUB = min(mUB, uB);
    }

    return make_tuple(mLA, mUA, mLB, mUB);
  };

  i64 kiri = 0, kanan = 1e13;
  while (kiri < kanan) {
    i64 R = (kiri + kanan) / 2;
    auto [mLA, mUA, mLB, mUB] = towerPositionBound(R);
    bool valid = mLA <= mUA && mLB <= mUB;

    if (valid) {
      kanan = R;
    } else {
      kiri = R + 1;
    }
  }

  cout << kiri << endl;

  auto [la, ua, lb, ub] = towerPositionBound(kiri);

  i64 x = ceil(double(la + lb) / 2.0);
  i64 y = max(la - x, x - ub);

  cout << x << " " << y << endl;

  return 0;
}