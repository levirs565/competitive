#include <algorithm>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n);

  for (auto &i : a)
    cin >> i;

  int l = 0, r = 0, sum = 0;
  int count = 0;

  while (l < n && r < n) {
    while (r < n) {
      sum += a[r];
      if (sum > x) {
        sum -= a[r];
        break;
      }
      r++;
    }
    if (sum == x) {
      count++;
    }
    sum -= a[l];
    l++;
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