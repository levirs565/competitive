#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

uint64_t mod = 1e9 + 7;

void solution() {
  int n;
  cin >> n;

  int totalSum = n * (n + 1) / 2;
  int halfSum = totalSum / 2;

  if (totalSum % 2 == 1) {
    std::cout << 0 << std::endl;
    return;
  }

  std::vector<std::vector<int>> sumCount(n + 1,
                                         std::vector<int>(halfSum + 1, 0));

  sumCount[0][0] = 1;

  for (int i = 1; i <= n - 1; i++) {
    for (int j = 0; j <= halfSum; j++) {
      sumCount[i][j] = sumCount[i - 1][j];

      if (j - i >= 0) {
        sumCount[i][j] += sumCount[i-1][j-i] % mod;
        sumCount[i][j] %= mod;
      }
    }
  }

  std::cout << sumCount[n-1][halfSum] << std::endl;
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
  test::check_solution(R"(7
)",
                       R"(4)");
}


TEST_CASE("first") {
  test::check_solution(R"(431
)",
                       R"(754684998)");
}

#endif
