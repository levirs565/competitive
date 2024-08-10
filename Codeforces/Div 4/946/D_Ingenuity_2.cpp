#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int l;
    cin >> l;

    std::string command;
    cin.ignore();
    getline(cin, command);

    int x = 0, y = 0;
    for (const char &c : command) {
      if (c == 'N') {
        y++;
      } else if (c == 'S') {
        y--;
      } else if (c == 'E') {
        x++;
      } else if (c == 'W') {
        x--;
      }
    }

    if (x % 2 != 0 || y % 2 != 0 || (x == 0 && y == 0 && l == 2))
      std::cout << "NO" << std::endl;
    else {
      std::vector<char> result(l, 'R');

      if (x == 0 && y == 0) {
        std::map<char, char> inv = {
            {'N', 'S'}, {'S', 'N'}, {'E', 'W'}, {'W', 'E'}};
        result[find(command.begin(), command.end(), inv[command[0]]) -
               command.begin()] = 'H';
        result[0] = 'H';
      } else {
        // Why the diff is 2 not 1
        // Imagine current helicoper's position is h and rover position's is r
        // current delta position = h - r
        // After: helicoper's position is h - 1 and rover position's is r + 1
        // current delta position = h - 1 - (r + 1) = h - r - 2
        // Note that: x and y is actually delta position
        // In start, all the command added to x and y
        // because all command is taken by rover
        // Its mean, helicopter is not moving 
        for (size_t i = 0; i < command.size(); i++) {
          const char &ch = command[i];
          if (ch == 'N' && y > 0) {
            y -= 2;
            result[i] = 'H';
          } else if (ch == 'S' && y < 0) {
            y += 2;
            result[i] = 'H';
          } else if (ch == 'E' && x > 0) {
            x -= 2;
            result[i] = 'H';
          } else if (ch == 'W' && x < 0) {
            x += 2;
            result[i] = 'H';
          }
        }
      }

      int rX = 0, rY = 0, hX = 0, hY = 0;
      for (size_t i = 0; i < command.size(); i++) {
        char c = command[i];
        bool rover = result[i] == 'R';

        if (c == 'N') {
          if (rover) {
            rY += 1;
          } else {
            hY += 1;
          }
        } else if (c == 'S') {
          if (rover) {
            rY -= 1;
          } else {
            hY -= 1;
          }
        } else if (c == 'E') {
          if (rover) {
            rX += 1;
          } else {
            hX += 1;
          }
        } else if (c == 'W') {
          if (rover) {
            rX -= 1;
          } else {
            hX -= 1;
          }
        }
      }

      if (rX == hX && hY == rY) {
        for (const char &ch : result)
          std::cout << ch;
        std::cout << std::endl;
      } else {
        std::cout << "NO" << std::endl;
      }
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