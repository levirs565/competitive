#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

using i64 = int64_t;
i64 mod = 1e9 + 7;

struct SafeInt {
  i64 value;

  SafeInt(i64 v) : value(v % mod) {}

  SafeInt operator*(const SafeInt &other) {
    return (value * other.value) % mod;
  }

  SafeInt operator+(const SafeInt &other) {
    return (value + other.value) % mod;
  }

  SafeInt operator-(const SafeInt &other) {
    SafeInt result = *this;
    result.value -= other.value;
    result.value += mod;
    result.value %= mod;
    if (result.value < 0)
      throw domain_error("aneh");
    return result;
  }

  SafeInt power(i64 n) {
    SafeInt result(1);
    SafeInt a = *this;

    while (n) {
      if (n & 1)
        result = result * a;

      a = a * a;

      n >>= 1;
    }
    return result;
  }

  SafeInt inv() { return power(mod - 2); }
};

void solution() {
  i64 a, k;
  cin >> a >> k;

  // harus di mod karena (mod + 1)^n = 1^n pada safe int
  // Ingat a = 1 tidak bekerja dengna rumus umum karena pembagian dengan 0
  a %= mod;

  if (a == 1) {
    SafeInt result = SafeInt(k) * SafeInt(k + 1) * SafeInt(2).inv();
    cout << result.value << endl;
    return;
  }

  SafeInt divisor = SafeInt(a - 1).inv();
  SafeInt power = SafeInt(a).power(k);
  SafeInt left = SafeInt(k) * power * a;
  SafeInt right = (power - 1) * a * divisor;
  SafeInt result = (left - right) * divisor;
  cout << result.value << endl;

  //   SafeInt left =
  //       SafeInt(k) * SafeInt(a).power(k + 1) * (SafeInt(a) -
  //       SafeInt(1)).inv();
  //   SafeInt right =
  //       (SafeInt(a).power(k + 1) - SafeInt(a)) * SafeInt(a -
  //       1).power(2).inv();
  //   SafeInt result = left - right;
  //   cout << result.value << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}