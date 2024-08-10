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

void solution() {
  int N, K;
  cin >> N >> K;

  vector<pair<int, int>> A(N);

  for (auto &a : A)
    cin >> a.first;
  for (auto &a : A)
    cin >> a.second;

  map<int, int> prev, curr;

  prev[0] = 0;

  for (auto &a : A) {
    for (auto [utuh, bagian] : prev) {
      // ambil utuh
      curr[utuh + a.first] =
          min(bagian,
              curr.count(utuh + a.first) == 0 ? INT_MAX : curr[utuh + a.first]);
      // ambil bagian
      curr[utuh] =
          min(bagian + a.second, curr.count(utuh) == 0 ? INT_MAX : curr[utuh]);
    }
    swap(prev, curr);
    curr.clear();
  }

  int potong = INT_MAX;
  for (auto [utuh, bagian] : prev) {
    if (utuh < K) {
      int sisa = K - utuh;
      int p = bagian / sisa;
      if (bagian % sisa != 0)
        p++;
      if (p <= 0)
        p = 1;
      potong = min(potong, p);
    } else if (utuh == K && bagian == 0) {
      potong = min(potong, 1);
    }
  }

  cout << potong << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}