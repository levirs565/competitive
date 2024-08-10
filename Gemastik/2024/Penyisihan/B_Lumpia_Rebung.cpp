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
  i64 N, L;
  cin >> N >> L;

  vector<i64> panjang;
  panjang.push_back(L);

  for (int i = 0; i < N; i++) {
    int pos;
    cin >> pos;
    pos--;
    i64 p = panjang[pos];
    panjang[pos] = p / 2;
    panjang.insert(panjang.begin() + pos + 1, p / 2);
  }

  for (auto a : panjang)
    cout << a << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}