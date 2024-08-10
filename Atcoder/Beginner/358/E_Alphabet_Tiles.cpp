#include <algorithm>
#include <bitset>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

constexpr int64_t mod = 998244353;

int64_t countCombination(int currentLength, int length, std::vector<int> &C) {
  if (currentLength == length)
    return 1;

  int64_t count = 0;
  for (size_t i = 0; i < C.size(); i++) {
    if (C[i] <= 0)
      continue;
    std::vector<int> C2 = C;
    C2[i]--;
    count += countCombination(currentLength + 1, length, C2);
    count %= mod;
  }

  return count;
}

void solution() {
  int k;
  cin >> k;

  std::vector<int> C(26);

  for (auto &i : C)
    cin >> i;

  int64_t count = 0;
  int64_t prev = 1;

  std::vector<std::vector<int64_t>> counts(k + 1, std::vector<int64_t>(27));
  counts[0][26] = 1;

  for (int i = 1; i <= k; i++) {
    // int64_t currentCount = countCombination(0, i, C);
    // cerr << i << " " << currentCount << endl;
    // count += currentCount;
    // count %= mod;
    // size_t nonZero =
    // count_if(C.begin(), C.end(), [](auto &a) { return a > 0; });
    for (size_t j = 0; j < 26; j++) {
      if (C[j] >= i) {
        counts[i][j] = counts[i - 1][26];
      } else if (C[j] > 0) {
        for (size_t k = 0; k < 26; k++) {
          if ((k != j && counts[i - 1][k] > 0)) {
            cout << i << " " << j << " " << k << " " << counts[i - 1][k] << " " << counts[i - 2][j] << endl;
            counts[i][j] += counts[i - 1][k] - counts[i - 2][j];
            counts[i][j] %= mod;
          }
        }
      }
      if (counts[i][j] > 0)
      cerr << i << " " << j << " " << counts[i][j] << endl;
      counts[i][26] += counts[i][j];
      counts[i][26] %= mod;
      if (counts[i][26] == 0) break;
    }
    cerr << i << " " << counts[i][26] << endl;
    count += counts[i][26];
    count %= mod;
  }

  cout << count << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}