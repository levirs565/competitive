#include <algorithm>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>
#include <limits>

using namespace std;

using Mask = bitset<20>;

void solution() {
  int n, x;
  cin >> n >> x;

  std::vector<int> weight(n + 1);

  for (int i = 1; i <= n; i++)
    cin >> weight[i];

  const int maskCount = 1 << n;
  std::vector<std::pair<int, int>> rideAndWeight(maskCount);

  rideAndWeight[0] = {1, 0};
  for (int mask = 1; mask < maskCount; mask++) {
    std::pair<int, int> bestRW{std::numeric_limits<int>::max(), 0};
    for (int i = 1; i <= n; i++) {
      Mask bMask(mask);

      if (bMask.test(i - 1)) {
        Mask bMaskNot(bMask);
        bMaskNot.flip(i - 1);

        std::pair<int, int> rw = rideAndWeight[bMaskNot.to_ulong()];
        if (rw.second + weight[i] > x) {
          rw.first++;
          rw.second = weight[i];
        } else {
          rw.second += weight[i];
        }

        if (rw.first < bestRW.first || (rw.first == bestRW.first && rw.second < bestRW.second)) {
          bestRW = rw;
        }
      }
    }

    rideAndWeight[mask] = bestRW;
  }

  std::cout << rideAndWeight[maskCount - 1].first << std::endl;
}

#ifndef LOCAL
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}
#else
#define TEST_NO_DIFF
#include "test.h"

TEST_CASE("first") {
  test::check_solution(R"(4 10
4 8 6 1
)",
                       R"(2)");
}

TEST_CASE("second") {
  test::check_solution(R"(10 100
36 16 7 33 2 53 25 48 32 11
)",
                       R"(3)");
}

#endif
