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
  int N;
  cin >> N;

  vector<string> A(N);

  for (auto& a : A) cin >> a;

  for (int i = 0; i < N - 2; i++) {
    if (A[i] == "sweet" && A[i + 1] == "sweet") {
        cout << "No" << endl;
        return;
    }
  }

  cout << "Yes" << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}