#include <algorithm>
#include <array>
#include <climits>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using i64 = int64_t;

vector<pair<int, int>> input() {
  int N;
  cin >> N;
  vector<pair<int, int>> p(N);

  for (auto &[prime, pow] : p)
    cin >> prime;

  for (auto &[prime, pow] : p)
    cin >> pow;

  return p;
}

i64 mod = 998244353;

i64 binpow(i64 a, i64 b) {
  if (b == 0)
    return 1;
  if (b % 2 == 1) {
    return (binpow(a, b - 1) * a) % mod;
  }
  i64 result = binpow(a, b / 2);
  return (result * result) % mod;
}

int main() {
  auto X = input(), Y = input();

  // lcm = X gcd = Y
  // gcd Y berarti keduanya harus bisa dibagi Y
  // lcm X berarti keduanya dapat membagi X

  for (auto &[prime, pow] : Y) {
    auto a = lower_bound(X.begin(), X.end(), pair<int, int>(prime, 0));
    if (a->first != prime) {
      cout << "0" << endl;
      return 0;
    }
    a->second -= pow;
    if (a->second < 0) {
      cout << "0" << endl;
      return 0;
    }
  }

  i64 power = 0;

  for (auto &[prime, pow] : X) {
    if (pow > 0) {
      power++;
    }
  }

  cout << binpow(2, power) << endl;

  return 0;
}