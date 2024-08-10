#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, n, m;
    cin >> a >> b >> n >> m;

    std::vector<std::pair<int, int>> horizontal(n);
    std::vector<std::pair<int, int>> vertical(n);

    for (int i = 0; i < n; i++) {
      cin >> vertical[i].first >> vertical[i].second;
      horizontal[i].first = vertical[i].second;
      horizontal[i].second = vertical[i].first;
    }

    std::sort(horizontal.begin(), horizontal.end());
    std::sort(vertical.begin(), vertical.end());

    std::set<std::pair<int, int>> deleted;

    int score[2] = {0, 0};

    int xStart = 1, xEnd = b;
    int yStart = 1, yEnd = a;

    int hStart = 0, hEnd = n - 1;
    int vStart = 0, vEnd = n - 1;

    for (int i = 0; i < m; i++) {
      char move;
      int count;
      cin >> move >> count;

      if (move == 'U') {
        yStart += count;
        while (vStart <= vEnd && vertical[vStart].first < yStart) {
          if (deleted.count(std::make_pair(vertical[vStart].second,
                                           vertical[vStart].first)) == 0) {
            score[i % 2]++;
            deleted.insert(std::make_pair(vertical[vStart].second,
                                          vertical[vStart].first));
          }
          vStart++;
        }
      } else if (move == 'D') {
        yEnd -= count;
        while (vStart <= vEnd && vertical[vEnd].first > yEnd) {
          if (deleted.count(std::make_pair(vertical[vEnd].second,
                                           vertical[vEnd].first)) == 0) {

            score[i % 2]++;
            deleted.insert(
                std::make_pair(vertical[vEnd].second, vertical[vEnd].first));
          }
          vEnd--;
        }
      } else if (move == 'L') {
        xStart += count;
        while (hStart <= hEnd && horizontal[hStart].first < xStart) {
          if (deleted.count(horizontal[hStart]) == 0) {
            score[i % 2]++;
            deleted.insert(horizontal[hStart]);
          }
          hStart++;
        }
      } else if (move == 'R') {
        xEnd -= count;
        while (hStart <= hEnd && horizontal[hEnd].first > xEnd) {
          if (deleted.count(horizontal[hEnd]) == 0) {
            score[i % 2]++;
            deleted.insert(horizontal[hEnd]);
          }
          hEnd--;
        }
      }
    }

    std::cout << score[0] << " " << score[1] << std::endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}