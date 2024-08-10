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

  i64 result = 0;
  for (int grey = 0; grey <= n; grey++) {
    if (grey == n) {
      result++;
    } else {
      for (int red = 3; red <= n - grey; red++) {
        result += f(n - grey - red - 1);
      }
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