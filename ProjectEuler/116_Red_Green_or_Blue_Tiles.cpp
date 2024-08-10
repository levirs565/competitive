#include <algorithm>
#include <exception>
#include <iostream>

using namespace std;

using i64 = int64_t;

i64 cache[1000];

// red, grey
i64 f(int m, int n, bool first) {
  if (n == 0 || n == -1)
    return 1;
  if (n < 0) {
    throw domain_error("bad argument " + to_string(n));
  }

  if (cache[n] != -1)
    return cache[n];

  i64 result = 0;
  for (int grey = 0; grey <= n; grey++) {
    if (grey == n) {
      if (!first) {
        result++;
      }
    } else if (n - grey >= m) {
      result += f(m, n - grey - m, false);
    }
  }

  cache[n] = result;
  return result;
}

int main() {
  int n;
  cin >> n;

  i64 result = 0;
  fill(cache, cache + 1000, -1);
  result += f(2, n, true);
  fill(cache, cache + 1000, -1);
  result += f(3, n, true);
  fill(cache, cache + 1000, -1);
  result += f(4, n, true);

  cout << result << endl;

  return 0;
}