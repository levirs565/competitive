#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory.h>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
  i64 xc, yc;
  cin >> xc >> yc;

  int N;
  cin >> N;

  vector<i64> distances;

  for (int i = 0; i < N; i++) {
    i64 x, y;
    cin >> x >> y;
    i64 dx = x - xc, dy = y - yc;
    distances.push_back(dx * dx + dy * dy);
  }

  sort(distances.begin(), distances.end());

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    i64 r;
    cin >> r;
    r *= r;
    cout << upper_bound(distances.begin(), distances.end(), r) - distances.begin() << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}