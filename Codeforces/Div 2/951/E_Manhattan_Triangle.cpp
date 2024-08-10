#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

int maxManhatan = 5 * 1e5;

void solution() {

  int n;
  i64 d;
  cin >> n >> d;

  std::vector<tuple<i64, i64, int>> pointsA(n), pointsB(n);

  for (int i = 0; i < n; i++) {
    auto &[a, b, j] = pointsA[i];
    i64 x, y;
    cin >> x >> y;
    a = x + y;
    b = x - y;
    j = i + 1;

    pointsB[i] = make_tuple(b, a, j);
  }

  sort(pointsA.begin(), pointsA.end());
  sort(pointsB.begin(), pointsB.end());

  for (auto [a1, b1, i1] : pointsA) {
    auto it =
        lower_bound(pointsA.begin(), pointsA.end(), make_tuple(a1, b1 + d, -1));
    if (it != pointsA.end()) {
      auto [a2, b2, i2] = *it;
      if (a2 == a1 && b2 == b1 + d) {
        auto it2 = lower_bound(pointsA.begin(), pointsA.end(),
                               make_tuple(a1 + d, b1, -1));
        if (it2 != pointsA.end()) {
          auto [a3, b3, i3] = *it2;
          if (a3 == a1 + d && b3 <= b1 + d) {
            cout << i1 << " " << i2 << " " << i3 << endl;
            return;
          }
        }

        it2 = lower_bound(pointsA.begin(), pointsA.end(),
                          make_tuple(a1 - d, b1, -1));
        if (it2 != pointsA.end()) {
          auto [a3, b3, i3] = *it2;
          if (a3 == a1 - d && b3 <= b1 + d) {
            cout << i1 << " " << i2 << " " << i3 << endl;
            return;
          }
        }
      }
    }

    it =
        lower_bound(pointsB.begin(), pointsB.end(), make_tuple(b1, a1 + d, -1));
    if (it != pointsB.end()) {
      auto [b2, a2, i2] = *it;
      if (b2 == b1 && a2 == a1 + d) {
        auto it2 = lower_bound(pointsB.begin(), pointsB.end(),
                               make_tuple(b1 + d, a1, -1));
        if (it2 != pointsB.end()) {
          auto [b3, a3, i3] = *it2;
          if (b3 == b1 + d && a3 <= a1 + d) {
            cout << i1 << " " << i2 << " " << i3 << endl;
            return;
          }
        }

        it2 = lower_bound(pointsB.begin(), pointsB.end(),
                          make_tuple(b1 - d, a1, -1));
        if (it2 != pointsB.end()) {
          auto [b3, a3, i3] = *it2;
          if (b3 == b1 - d && a3 <= a1 + d) {
            cout << i1 << " " << i2 << " " << i3 << endl;
            return;
          }
        }
      }
    }
  }

  cout << "0 0 0" << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}