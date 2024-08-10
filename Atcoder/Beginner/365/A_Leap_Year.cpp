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

void solution() {
  int y;
  cin >> y;
  if (y % 4 != 0) {
    cout << "365" << endl;
  } else if (y % 100 != 0) {
    cout << "366" << endl;
  } else if (y % 400 != 0) {
    cout << "365" << endl;
  } else {
    cout << "366" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}