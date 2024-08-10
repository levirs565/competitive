#include <algorithm>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

using Mask = bitset<10>;

constexpr int mod = 1e9 + 7;

void solution() {
  int n, m;
  cin >> n >> m;

  const int maskCount = 1 << n;

  std::vector<int> prevState(maskCount, 0), currentState(maskCount, 0);

  prevState[0] = 1;

  for (int col = 1; col <= m; col++) {
    for (int row = 1; row <= n; row++) {
      for (int mask = 0; mask < (1 << n); mask++) {
        {
          Mask hTile(mask);
          hTile.flip(row - 1);
          currentState[mask] = prevState[hTile.to_ulong()] % mod;
          currentState[mask] %= mod;
        }
        {
          Mask vTile(mask);
          if (row > 1 && !vTile.test(row - 1) && !vTile.test(row - 2)) {
            vTile.flip(row - 2);
            currentState[mask] += prevState[vTile.to_ulong()] % mod;
            currentState[mask] %= mod;
          }
        }
      }

      std::swap(prevState, currentState);
    }
  }

  std::cout << prevState[0] << std::endl;
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
  test::check_solution(R"(4 7
)",
                       R"(781)");
}

TEST_CASE("second") {
  test::check_solution(R"(7 50
)",
                       R"(217283915)");
}

#endif