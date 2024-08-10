#include <algorithm>
#include <array>
#include <climits>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using i64 = int64_t;

i64 mod = 1e9 + 7;

i64 binpow(i64 a, i64 b) {
  if (b == 0)
    return 1;
  if (b % 2 == 1)
    return (binpow(a, b - 1) * a) % mod;
  i64 res = binpow(a, b / 2);
  return (res * res) % mod;
}

i64 modinv(i64 a) { return binpow(a, mod - 2); }

struct SafeNum {
  i64 x;

  SafeNum(i64 num) : x(num % mod) {}

  SafeNum operator+(const SafeNum &a) { return x + a.x; }

  void operator+=(const SafeNum &a) {
    x += a.x;
    x %= mod;
  }

  void operator-=(const SafeNum &a) {
    x -= a.x;
    x += mod;
    x %= mod;
  }

  SafeNum operator*(const SafeNum &a) { return x * a.x; }

  SafeNum operator/(i64 a) { return x * modinv(a); }
};

ostream &operator<<(ostream &o, const SafeNum &a) {
  o << a.x;
  return o;
}

int main() {
  i64 m, n;
  cin >> m >> n;

  SafeNum S = min(m, n) - 1;

  SafeNum res = 0;
  res += S * (S + 1) / 2 * n * m;
  res -= S * (S + 1) * (S * 2 + 1) / 6 * (n + m);
  res += S * S * (S + 1) * (S + 1) / 4;

  cout << res << endl;

  return 0;
}