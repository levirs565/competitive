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

  vector<string> A(N);
  for (auto& a : A) cin >> a;

  sort(A.begin(), A.end(), [] (auto& a, auto& b) {
    if (a.size() != b.size()) return a.size() < b.size();

    return a < b;
  });

  for (auto& a : A) cout << a << endl;

  return 0;
}