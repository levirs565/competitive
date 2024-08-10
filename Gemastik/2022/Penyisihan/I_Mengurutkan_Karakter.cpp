#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory.h>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
  int N;
  cin >> N;
  string a, b;
  cin >> a >> b;

  int count = 0;
  bool active = false;
  for (int i = 0; i < N; i++) {
    if (a[i] > b[i]) {
      if (!active) {
        count++;
        active = true;
      }
    } else if (a[i] == b[i]) {
      // nop
    } else {
      if (active)
        active = false;
    }
  }

  cout << count << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}