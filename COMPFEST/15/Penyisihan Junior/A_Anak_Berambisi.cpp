#include <algorithm>
#include <array>
#include <climits>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using i64 = int64_t;

int main() {
  int N;
  cin >> N;

  int m = INT_MAX;
  while (N--) {
    int a;
    cin >> a;
    m = min(abs(a), m);
  }

  cout << m << endl;

  return 0;
}