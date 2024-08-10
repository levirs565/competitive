#include <algorithm>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ranges>
#include <set>
#include <vector>
#include <iomanip>

using namespace std;

using i64 = int64_t;

struct Point {
  i64 x, y;

  Point operator-(const Point &other) { return {x - other.x, y - other.y}; }

  i64 cross(const Point &other) { return x * other.y - y * other.x; }
};

struct Line {
  Point a, b;
};

bool intersect(Line a, Line b) {
  auto a1 = a.a;
  auto a2 = b.a;
  auto d1 = a.b - a.a;
  auto d2 = b.b - b.a;

  auto ta = (a2 - a1).cross(d2);
  auto tb = d1.cross(d2);

  if (ta == 0 && tb == 0)
    return true;
  if (tb == 0)
    return false;

  auto ua = (a1 - a2).cross(d1);
  auto ub = d2.cross(d1);

  if (ua == 0 && ub == 0)
    return true;
  if (ub == 0)
    return false;

  double t = double(ta) / tb;
  double u = double(ua) / ub;

  if (t > 0 && t < 1 && u > 0 && u < 1)
    return true;

  return false;
}

void solution() {
  Point S, F;
  cin >> S.x >> S.y >> F.x >> F.y;

  int N;
  cin >> N;
  vector<Line> lines(N);
  vector<Point> P;

  P.push_back(S);

  for (auto &L : lines) {
    cin >> L.a.x >> L.a.y >> L.b.x >> L.b.y;
    P.push_back(L.a);
    P.push_back(L.b);
  }

  P.push_back(F);
  vector<vector<int>> E(P.size());

  for (int i = 0; i < P.size(); i++) {
    for (int j = i + 1; j < P.size(); j++) {
      Line nl{P[i], P[j]};
      bool can = true;
      for (auto l : lines) {
        if (intersect(nl, l)) {
          can = false;
          break;
        }
      }

      if (can) {
        // cout << "Can from " << nl.a.x << "," << nl.a.y << " to " << nl.b.x
        //      << "," << nl.b.y << endl;
        E[i].push_back(j);
        E[j].push_back(i);
      }
    }
  }

    vector<bool> visited(P.size(), false);
    vector<double> cost(P.size(), std::numeric_limits<double>::max());

    cost[0] = 0;

    using Item = pair<i64, int>; // cost, index
    priority_queue<Item, vector<Item>, greater<Item>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int i = pq.top().second;
        pq.pop();

        if (visited[i]) continue;
        visited[i] = true;

        for (auto j : E[i]) {
            i64 dx = P[j].x - P[i].x;
            i64 dy = P[j].y - P[i].y;
            double nc = cost[i] + sqrt(dx*dx + dy*dy);

            if (nc < cost[j]) {
                cost[j] = nc;
                if (!visited[j]) {
                    pq.push({nc, j});
                }
            }
        }
    }

    cout << fixed << setprecision(2) << cost.back() << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}