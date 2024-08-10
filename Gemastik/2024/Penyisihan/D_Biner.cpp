#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstring>
#include <exception>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;
using i64 = int64_t;

constexpr i64 maxN = 61;
i64 C[maxN][maxN];

void precompute() {
  C[0][0] = 1;
  for (int i = 1; i <= 60; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
}

i64 get(i64 m, i64 k) { return C[m][k]; }

int main() {
  precompute();
  i64 N = 30, K;
  cin >> K;

  string s = "";
  for (int a = 0; a <= 60; a++)
    s += "0";

  int last = -1;
  for (i64 i = 60; i >= 0 && N; --i) {
    if (get(i, N) > K)
      continue;
    else if (get(i, N) < K) {
      s[i] = '1';
      K -= get(i, N);
      N--;
    } else {
      last = i;
      break;
    }
  }

  for (int j = last - 1; j >= 0 && N; --j) {
    s[j] = '1';
    N--;
  }

  reverse(s.begin(), s.end());
  cout << strtoull(s.c_str(), 0, 2) << endl;
}