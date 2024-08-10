#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
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
  int N;
  cin >> N;
  set<vector<pair<int, int>>> all;

  vector<int> nums;
  for (int i = 1; i <= N; i++) {
    nums.push_back(i);
    nums.push_back(i);
  }

  int permutation = 0;
  do {
    permutation++;
    vector<pair<int, int>> a;
    for (int i = 0; i < nums.size() - 1; i += 2) {
    //   if (i > 0)
        // cout << ",";
      int f = nums[i], s = nums[i + 1];
    //   cout << f << "," << s;
      a.push_back(make_pair(min(f, s), max(f, s)));
    }
    // cout << endl;
    all.insert(a);
  } while (next_permutation(nums.begin(), nums.end()));

    for (auto &a : all) {
      bool first = true;
      for (auto &[f, s] : a) {
        if (!first)
          cout << ",";
        cout << "(" << f << "," << s << ")";
        first = false;
      }
      cout << endl;
    }

  cout << permutation << endl;
  cout << all.size() << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}