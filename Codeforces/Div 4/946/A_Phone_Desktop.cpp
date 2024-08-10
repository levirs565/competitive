#include <iostream>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;

    constexpr int screenRow = 5;
    constexpr int screenColumn = 3;

    if (x == 0 && y == 0) {
        std::cout << 0 << std::endl;
        continue;
    }

    int screenCount = 1;
    int currentRow = 1;
    while (x > 0 || y > 0) {
        if (currentRow > screenRow) {
            screenCount++;
            currentRow = 1;
        }

        if (y > 0 && currentRow < 5) {
            y--;
            x -= 2;
            currentRow += 2;
        } else {
            x -= screenColumn;
            currentRow++;
        }
    }

    std::cout << screenCount << std::endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}