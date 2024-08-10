#include <algorithm>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ranges>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

i64 mod = 1e9 + 7;

using Matrix = vector<vector<i64>>;

Matrix operator*(const Matrix &a, const Matrix &b) {
  Matrix result;

  for (int i = 0; i < a.size(); i++) {
    result.push_back({});
    for (int j = 0; j < b[0].size(); j++) {
      i64 curr = 0;
      for (int k = 0; k < a[0].size(); k++) {
        curr += (a[i][k] * b[k][j]) % mod;
        curr %= mod;
        curr += mod;
        curr %= mod;
      }
      result.back().push_back(curr);
    }
  }

  return result;
}

ostream &operator<<(ostream &o, const Matrix &a) {
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[i].size(); j++) {
      if (j > 0)
        cout << ",";
      cout << a[i][j];
    }
    cout << endl;
  }
  return o;
}

Matrix matpow(const Matrix &a, i64 b) {
  if (b == 0) {
    Matrix res;
    for (int i = 0; i < a.size(); i++) {
      res.push_back({});
      for (int j = 0; j < a[i].size(); j++) {
        res.back().push_back(i == j ? 1 : 0);
      }
    }
    return res;
  }
  if (b % 2 == 1) {
    return matpow(a, b - 1) * a;
  }
  Matrix res = matpow(a, b / 2);
  return res * res;
}

i64 full(i64 n);

i64 min1(i64 n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  return (full(n - 1) + min1(n - 2)) % mod;
}

i64 full(i64 n) {
  if (n == 0)
    return 1;
  if (n == 1)
    return 0;
  return (full(n - 2) + (2 * min1(n - 1)) % mod) % mod;
}

void solution() {
  i64 N;
  cin >> N;

  if (N % 2 == 1) {
    cout << "0" << endl;
    return;
  }

  Matrix base;
  base.push_back({0, 1, 1, 0});
  Matrix m;
  m.push_back({0, 1, 1, 0});
  m.push_back({1, 0, 0, 0});
  m.push_back({2, 0, 0, 1});
  m.push_back({0, 0, 1, 0});

  Matrix result = base * matpow(m, N - 1);
  cout << result[0][0] % mod << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}