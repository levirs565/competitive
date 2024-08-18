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
  int n, t;
  cin >> n >> t;
  vector<int> a(n);

  for (int &i : a)
    cin >> i;

  int l = 0, r = 0, count = 0;
  int result = 0;

  while (l < n && r < n) {
    while (r < n) {
        count += a[r];
        if (count > t) { 
            count -= a[r];
            break;
        } else {
            r++;
        }
    }
    result = max(result, r - l);
    count -= a[l];
    l++;
  }

  cout << result << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}