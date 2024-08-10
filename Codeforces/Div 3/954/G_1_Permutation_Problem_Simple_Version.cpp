#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <vector>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    std::vector<int> a(n);

    for (auto& i : a) cin >> i;

    int prevCount = 0;
    for (int i = 0; i < n; i++) {
        int num = a[i];
        if (num % i == 0)
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}