#include <algorithm>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ranges>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
    int N, R, K;
    cin >> N >> R >> K;

    vector<pair<int, int>> a(N);

    for (auto& i : a) cin >> i.first;
    for (auto& i : a) cin >> i.second;

    int sum = 0;
    for (auto [n, p] : a) {
        sum += i64(p) * n / 100;
    }

    if (sum >= R) cout << "PASS";
    else cout << "NOT PASS";
    cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}