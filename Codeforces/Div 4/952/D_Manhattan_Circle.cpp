#include <iostream>
#include <vector>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    int minColumn = 1e6, minRow = 1e6;
    int maxColumn = 0, maxRow = 0;
    for (int row = 1; row <= n; row++) {
      for (int column = 1; column <= m; column++) {
        char c;
        cin >> c;
        if (c == '#') {
          minColumn = min(minColumn, column);
          maxColumn = max(maxColumn, column);
          minRow = min(minRow, row);
          maxRow = max(maxRow, row);
        }
      }
    }

    cout << minRow + (maxRow - minRow) / 2 << " "
         << minColumn + (maxColumn - minColumn) / 2 << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}