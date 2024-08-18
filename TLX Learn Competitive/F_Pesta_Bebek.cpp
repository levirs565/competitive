#include <array>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;
using i64 = int64_t;

int main() {
  int N;
  cin >> N;

  vector<string> A;
  while (N--) {
    string a;
    cin >> a;
    auto pos = lower_bound(A.begin(), A.end(), a);

    cout << pos - A.begin() + 1 << endl;
    A.insert(pos, a);
  }

  return 0;
}