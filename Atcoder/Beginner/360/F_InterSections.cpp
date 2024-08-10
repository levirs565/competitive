#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <vector>

using namespace std;

constexpr int MAXN = 1e9 + 1;

class SegmentTree {
public:
  int N;
  vector<pair<int, int>> t;
  SegmentTree(int N) : N(N), t(4 * N + 1, {0, 0}) { build(); }

  pair<int, int> _combine(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first)
      return a;
    if (b.first > a.first)
      return b;
    return {a.first, min(a.second, b.second)};
  }

  void _build(int v, int tl, int tr) {
    if (tl == tr) {
      t[v] = make_pair(0, tl);
    } else {
      int tm = (tl + tr) / 2;
      _build(2 * v, tl, tm);
      _build(2 * v + 1, tm + 1, tr);
      t[v] = _combine(t[2 * v], t[2 * v + 1]);
    }
  }

  void build() { _build(1, 0, N - 1); }

  pair<int, int> _get(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return {INT_MIN, INT_MAX};
    if (l == tl && r == tr) {
      return t[v];
    } else {
      int tm = (tl + tr) / 2;
      return _combine(_get(2 * v, tl, tm, l, min(r, tm)),
                      _get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }
  }

  pair<int, int> get(int l, int r) { return _get(1, 0, N - 1, l, r); }

  void _updateDelta(int v, int tl, int tr, int i, int dx) {
    if (tl == tr) {
      t[v].first += dx;
    } else {
      int tm = (tl + tr) / 2;
      if (i <= tm)
        _updateDelta(2 * v, tl, tm, i, dx);
      else
        _updateDelta(2 * v + 1, tm + 1, tr, i, dx);
      t[v] = _combine(t[2 * v], t[2 * v + 1]);
    }
  }

  void _update(int v, int tl, int tr, int i, int x) {
    if (tl == tr) {
      t[v] = make_pair(x, tl);
    } else {
      int tm = (tl + tr) / 2;
      if (i <= tm)
        _update(2 * v, tl, tm, i, x);
      else
        _update(2 * v + 1, tm + 1, tr, i, x);
      t[v] = _combine(t[2 * v], t[2 * v + 1]);
    }
  }

  void update(int i, int x) { _update(1, 0, N - 1, i, x); }
  void updateDelta(int i, int dx) { _updateDelta(1, 0, N - 1, i, dx); }
};

void solution() {
  int n;
  cin >> n;

  vector<pair<int, int>> intervals(n);

  vector<int> points;

  for (auto &[f, s] : intervals) {
    cin >> f >> s;
    if (f > 0)
      points.push_back(f - 1);
    points.push_back(f);
    points.push_back(f + 1);
    points.push_back(s - 1);
    points.push_back(s);
    points.push_back(s + 1);
  }

  sort(points.begin(), points.end());
  points.erase(std::unique(points.begin(), points.end()), points.end());

  unordered_map<int, int> compress;

  for (size_t i = 0; i < points.size(); i++) {
    compress[points[i]] = i;
  }

  SegmentTree s(points.size());
  sort(intervals.begin(), intervals.end());

  int maxSize = INT_MIN;
  pair<int, int> result = {INT_MAX, INT_MAX};
  for (auto point : points) {
    s.build();

    int leftCount = 0;
    for (auto [l, r] : intervals) {
      if (l < point) {
        for (int i = compress[point], m = compress[r]; i <= m; i++) {
          s.updateDelta(i, -1);
        }
      }

      if (l < point && r > point) {
        leftCount++;
      }

      if (l > point)
        for (int i = compress[l + 1], m = compress[r - 1]; i <= m; i++) {
          s.updateDelta(i, 1);
        }
    }

    auto m = s.get(compress[point] + 1, points.size() - 1);
    int value = m.first + leftCount;
    if (value > maxSize) {
      maxSize = value;
      result = {point, points.at(m.second)};
    }
  }

  cout << result.first << " " << result.second << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}