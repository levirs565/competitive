#include <iostream>
#include <vector>

using namespace std;

int main() {
  int R, C;
  cin >> R >> C;
  vector<string> grid(R);
  for (auto &r : grid)
    cin >> r;

  string penuh, kosong;

  for (int i = 0; i < C; i++) {
    penuh += "1";
    kosong += "0";
  }

  bool runtuh = false;
  do {
    runtuh = false;

    int first = -1;
    for (int i = 0; i < grid.size(); i++) {
      if (grid[i] == penuh) {
        grid[i] = kosong;
        runtuh = true;
        first = i;
        i--;
      }
    }

    if (first >= 0) {
      vector<int> count(C, 0);
      for (int i = first; i >= 0; i--) {
        for (int j = 0; j < C; j++)
          if (grid[i][j] == '1') {
            grid[i][j] = '0';
            count[j]++;
          }
      }

      vector<int> ground(C, grid.size() - 1);
      for (int i = 0; i < C; i++) {
        for (int j = 0; j < grid.size(); j++) {
          if (grid[j][i] == '1') {
            ground[i] = j - 1;
            break;
          }
        }
      }

        for (int i = 0; i < C; i++) {
            for (int j = ground[i]; count[i] > 0; count[i]--, j--) {
                grid[j][i] = '1';
            }
        }
    }
  } while (runtuh);

  for (auto &r : grid)
    cout << r << endl;

  return 0;
}