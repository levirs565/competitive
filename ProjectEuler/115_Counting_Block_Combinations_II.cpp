#include <algorithm>
#include <exception>
#include <iostream>

using namespace std;

using i64 = int64_t;

int m;
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
      for (int red = m; red <= n - grey; red++) {
        result += f(n - grey - red - 1);
      }
    }
  }

  cache[n] = result;
  return result;
}

int main() {
  int type;
  cin >> type >> m;
  fill(cache, cache + 1000, -1);

  if (type == 1) {
    int n;
    cin >> n;

    cout << f(n) << endl;
  } else if (type == 2) {
    int n = 1;
    while (f(n) <= 1'000'000) {
      n++;
    }

    cout << "n = " << n << endl;
    cout << "f(n) = " << f(n) << endl;
  }

  return 0;
}