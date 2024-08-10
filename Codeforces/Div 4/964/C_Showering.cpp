#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int n, s, m;
    cin >> n >> s >> m;
    vector<pair<int, int>> tasks(n);

    for (auto &[l, r] : tasks)
      cin >> l >> r;

    int last = 0;
    int freeTime = 0;
    for (auto [l, r] : tasks) {
      if (last < l) {
        freeTime = max(freeTime, l - last);
      }

      last = r;
    }
    freeTime = max(freeTime, m - last);

    if (freeTime >= s)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}