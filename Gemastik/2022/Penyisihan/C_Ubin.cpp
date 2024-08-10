#include <algorithm>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

i64 mod = 1e9 + 7;

i64 way(i64 n) {
  if (n < 0)
    return 0;
  if (n == 1 || n == 0)
    return 1;

  return way(n - 1) + way(n - 2);
}

using Matrix = array<array<i64, 2>, 2>;

Matrix operator*(const Matrix &a, const Matrix &b) {
  Matrix result = {{{0, 0}, {0, 0}}};

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        result[i][j] += (a[i][k] * b[k][j]) % mod;
        result[i][j] %= mod;
      }
    }
  }
  return result;
}

Matrix base = {{{1, 0}, {0, 1}}};

Matrix matpow(const Matrix &a, i64 b) {
  if (b == 0)
    return base;
  if (b % 2 == 1) {
    return matpow(a, b - 1) * a;
  }
  Matrix result = matpow(a, b / 2);
  return result * result;
}

void solution() {
  i64 N;
  cin >> N;

  //   i64 prev = 0, curr = 1;

  //   for (int i = 0; i < N; i++) {
  //     i64 t = (curr % mod) + (prev % mod);
  //     prev = curr;
  //     curr = t;
  //   }

  Matrix a = {{{1, 1}, {1, 0}}};
  Matrix m = matpow(a, N);

//   for (int i = 0; i < 2; i++) {
//     for (int j = 0; j < 2; j++) {
//       if (j > 0)
//         cout << ",";
//       cout << m[i][j];
//     }
//     cout << endl;
//   }
  i64 curr = m[0][0];
  cout << (curr * curr) % mod << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}