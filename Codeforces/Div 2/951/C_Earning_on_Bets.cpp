#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
  int n;
  cin >> n;

  vector<int> X(n);

  for (auto &x : X) {
    cin >> x;
  }

  int l = 0, r = 1e9;

  while (l < r) {
    int mid = l + (r - l) / 2;
    i64 actualSum = 0;
    for (auto x : X) {
      int a = (mid / x) + 1;
      actualSum += a;
    }

    // cout << mid << " " << actualSum << endl;

    if (i64(mid) >= actualSum) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  if (r >= 1e9) {
    cout << "-1" << endl;
  } else {
    for (auto x : X) {
      int a = (r / x) + 1;
      cout << a << " ";
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}