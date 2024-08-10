#include <algorithm>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <ranges>
#include <set>
#include <vector>
#include <numeric>

using namespace std;

using i64 = int64_t;

using point = pair<i64, i64>;

i64 orientation(point a, point b, point c) {
  return a.first * (b.second - c.second) + b.first * (c.second - a.second) +
         c.first * (a.second - b.second);
}

vector<point> lower_hull(vector<point> &p) {
  if (p.size() < 3)
    return p;

  vector<point> r;

  for (size_t i = 0; i < p.size(); i++) {
    while (r.size() >= 2 &&
           orientation(r[r.size() - 2], r[r.size() - 1], p[i]) <= 0)
      r.pop_back();
    r.push_back(p[i]);
  }

  return r;
}

vector<point> upper_hull(vector<point> &p) {
  reverse(p.begin(), p.end());
  if (p.size() < 3)
    return p;

  vector<point> r;
  for (size_t i = 0; i < p.size(); i++) {
    while (r.size() >= 2 &&
           orientation(r[r.size() - 2], r[r.size() - 1], p[i]) <= 0)
      r.pop_back();
    r.push_back(p[i]);
  }

  return r;
}

void normalize(i64 &gA, i64 &gB) {
  if (gA < 0 && gB < 0) {
    gA *= -1;
    gB *= -1;
  }

  if (gB < 0 && gA > 0) {
    gB *= -1;
    gA *= -1;
  }

  if (gA == 0) {
    gB = 1;
  }

  i64 g = gcd(gA, gB);
  gA /= g;
  gB /= g;
}

void solution() {
  int N;
  cin >> N;

  vector<point> lower(N), upper(N);

  for (int i = 0; i < N; i++) {
    lower[i].first = upper[i].first = i + 1;
    cin >> lower[i].second;
    cin >> upper[i].second;
  }

  auto uhull = lower_hull(upper), lhull = upper_hull(lower);

  //   cout << "Lower Hull: ";
  //   for (auto [first, second] : lhull)
  //     cout << "(" << first << "," << second << ") ";
  //   cout << endl;

  //   cout << "Upper Hull: ";
  //   for (auto [first, second] : uhull)
  //     cout << "(" << first << "," << second << ") ";
  //   cout << endl;

  bool found = false;
  size_t ui = 0, li = 0;

  while (ui < uhull.size() && li < lhull.size()) {
    if (ui + 1 < uhull.size() &&
        orientation(lhull[li], uhull[ui], uhull[ui + 1]) > 0)
      ui++;
    else if (li + 1 < lhull.size() &&
             orientation(uhull[ui], lhull[li], lhull[li + 1]) > 0)
      li++;
    else {
      found = true;
      break;
    }
  }

  if (!found)
    cout << "TIDAK" << endl;
  else {
    point p1 = lhull[li], p2 = uhull[ui];
    // cout << p1.first << " " << p1.second << endl;
    // cout << p2.first << " " << p2.second << endl;
    i64 dy = p1.second - p2.second;
    i64 dx = p1.first - p2.first;
    i64 gA = dy;
    i64 gB = dx;
    i64 tA = p1.second * dx - p1.first * dy;
    i64 tB = dx;

    // cout << dy << " " << dx << endl;

    normalize(gA, gB);
    normalize(tA, tB);

    if (tA < 0) {
      cout << "TIDAK" << endl;
    } else {
      cout << "BISA" << endl;
      cout << tA << " " << tB << endl;
      cout << gA << " " << gB << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}