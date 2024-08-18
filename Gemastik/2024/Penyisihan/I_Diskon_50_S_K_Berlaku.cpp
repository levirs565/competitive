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
  int N, Q;
  cin >> N >> Q;

  vector<int> A(N);
  for (auto &a : A)
    cin >> a;

  while (Q--) {
    int x;
    cin >> x;

    cout << "Start " << x << endl;
    sort(A.begin(), A.end());
    i64 res = LONG_LONG_MAX;
    vector<int> B;

    do {
      priority_queue<int, vector<int>, greater<int>> q;
      i64 total = 0;
      for (auto a : A) {
        q.push(a);

        if (q.size() == x) {
          total += q.top() - q.top() / 2;
          q.pop();

          while (!q.empty()) {
            total += q.top();
            q.pop();
          }
        }
      }
      while (!q.empty()) {
        total += q.top();
        q.pop();
      }

      if (total <= res) {
        B = A;
        res = total;
      }
    } while (next_permutation(A.begin(), A.end()));

    cout << x << " " << res << endl;
    for (auto &b : B)
      cout << b << " ";
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}