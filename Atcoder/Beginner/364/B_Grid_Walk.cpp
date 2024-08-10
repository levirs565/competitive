#include <algorithm>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
  int H, W;
  cin >> H >> W;

  int Si, Sj;
  cin >> Si >> Sj;

  vector<string> A(H);
  for (auto &a : A) {
    cin >> a;
  }

  string X;
  cin >> X;

  int i = Si - 1, j = Sj - 1;

  for (char &ch : X) {
    if (ch == 'L') {
      if (j > 0 && A[i][j - 1] == '.') {
        j--;
      }
    } else if (ch == 'R') {
      if (j + 1 < W && A[i][j + 1] == '.') {
        j++;
      }
    } else if (ch == 'U') {
      if (i > 0 && A[i - 1][j] == '.') {
        i--;
      }
    } else if (ch == 'D') {
      if (i + 1 < H && A[i + 1][j] == '.') {
        i++;
      }
    }
  }

  cout << i + 1 << " " << j + 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}