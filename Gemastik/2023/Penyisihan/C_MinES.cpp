#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory.h>
#include <queue>
#include <set>
#include <vector>

using namespace std;

char table1[4][4][3] = {{"AB", "DC", "CC", "CB"},
                        {"CA", "DA", "CD", "DD"},
                        {"BC", "AA", "BA", "DB"},
                        {"BD", "AD", "BB", "AC"}};

char table2[4][4][3] = {{"CD", "BB", "AC", "CC"},
                        {"CB", "DB", "AD", "DD"},
                        {"DA", "DC", "BC", "BD"},
                        {"AA", "BA", "CA", "AB"}};

char tableInv1[4][4][3];
char tableInv2[4][4][3];
char tableInv[4][4][3];

template <typename T>
void genInv(T from, T to) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      auto a = from[i][j];
      to[a[0] - 'A'][a[1] - 'A'][0] = 'A' + i;
      to[a[0] - 'A'][a[1] - 'A'][1] = 'A' + j;
      to[a[0] - 'A'][a[1] - 'A'][2] = 0;
    }
  }
}

void solution() {
  genInv(table1, tableInv1);
  genInv(table2, tableInv2);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
        auto a = tableInv2[i][j];
        auto b = tableInv1[a[0] - 'A'][a[1] - 'A'];
        tableInv[i][j][0] = b[0];
        tableInv[i][j][1] = b[1];
        tableInv[i][j][2] = 0;
    }
  }

  string s;
  cin >> s;

  string r;

  for (int i = 0; i < s.size(); i += 2) {
    r += tableInv[s[i] - 'A'][s[i + 1] - 'A'];
  }

  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}