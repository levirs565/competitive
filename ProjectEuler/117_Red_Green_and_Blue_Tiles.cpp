#include <algorithm>
#include <exception>
#include <iostream>

using namespace std;

using i64 = int64_t;

i64 cache[1000];

// red, grey
i64 f(int n) {
  if (n == 0 || n == -1)
    return 1;
  if (n < 0) {
    throw domain_error("bad argument " + to_string(n));
  }

  if (cache[n] != -1)
    return cache[n];

  i64 result = 1;
  for (int grey = 0; grey <= n; grey++) {
    if (n - grey >= 2) {
      result += f(n - grey - 2);
    }
    if (n - grey >= 3) {
      result += f(n - grey - 3);
    }
    if (n - grey >= 4) {
      result += f(n - grey - 4);
    }
  }

  cache[n] = result;
  return result;
}

int main() {
  int n;
  cin >> n;

  fill(cache, cache + 1000, -1);
  cout << f(n) << endl;

  return 0;
}