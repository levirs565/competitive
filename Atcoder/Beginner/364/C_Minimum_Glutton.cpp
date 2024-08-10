#include <algorithm>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
  int N;
  cin >> N;
  i64 X, Y;
  cin >> X >> Y;

  vector<pair<i64, i64>> A(N);

  for (auto &a : A)
    cin >> a.first;

  for (auto &a : A)
    cin >> a.second;

  auto findMax = [&]() {
    i64 x = 0, y = 0;
    int count = 0;

    for (int i = 0; i < N; i++) {
      if (x <= X && y <= Y) {
        x += A[i].first;
        y += A[i].second;
        count++;
      } else {
        break;
      }
    }

    // cout << x << " " << y << endl;

    return count;
  };

  sort(A.begin(), A.end(), [](auto &l, auto &r) { return l.first > r.first; });
  int r1 = findMax();

  sort(A.begin(), A.end(),
       [](auto &l, auto &r) { return l.second > r.second; });
  int r2 = findMax();

  cout << min(r1, r2) << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}