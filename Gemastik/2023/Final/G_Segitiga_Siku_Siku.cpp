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

void normalizeSlopeSign(int &dy, int &dx) {
  if (dx < 0) {
    dy *= -1;
    dx *= -1;
  }
  if (dx == 0) {
    dy = 1;
  }
  if (dy == 0) {
    dx = 1;
  }
}

void normalizeSlope(int &dy, int &dx) {
  int g = gcd(abs(dy), abs(dx));
  if (g != 0) {
    dy /= g;
    dx /= g;
  }

  normalizeSlopeSign(dy, dx);
}

void solution() {
  int N;
  cin >> N;

  vector<pair<int, int>> points(N);

  for (auto &[f, s] : points)
    cin >> f >> s;

  int allCount = 0;
  constexpr int indexShift = 200;
  for (int i = 0; i < N; i++) {
    auto slopeCount = vector(401, vector<int>(401, 0)); // [dy][dx]

    for (int j = 0; j < N; j++) {
      if (i == j)
        continue;

      auto [ax, ay] = points[i];
      auto [bx, by] = points[j];

      int dy = by - ay;
      int dx = bx - ax;
      normalizeSlope(dy, dx);

      int pdy = -dx;
      int pdx = dy;
      normalizeSlopeSign(pdy, pdx);

      allCount += slopeCount[pdy + indexShift][pdx + indexShift];

      slopeCount[dy + indexShift][dx + indexShift]++;
    }
  }

  cout << allCount << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}