#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int div3zero(int n) {
  int result = 0;
  while (n > 0) {
    result++;
    n /= 3;
  }
  return result;
}

void solution() {
  constexpr int maxN = 2 * 1e5;
  int d3z[maxN + 1];
  int d3zPrefix[maxN + 1];

  d3z[0] = 0;
  d3zPrefix[0] = 0;
  for (int i = 1; i <= maxN; i++) {
    d3z[i] = div3zero(i);
    d3zPrefix[i] = d3zPrefix[i - 1] + d3z[i];
  }

  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int result = d3zPrefix[r] - d3zPrefix[l - 1] + d3z[l];
    cout << result << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}