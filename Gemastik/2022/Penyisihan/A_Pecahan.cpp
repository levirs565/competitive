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
  i64 a, b, c, d;
  cin >> a >> b >> c >> d;

  i64 e = a * d;
  i64 f = c * b;

  if (e == f)
    cout << "sama";
  else if (e < f)
    cout << "lebih kecil";
  else
    cout << "lebih besar";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}