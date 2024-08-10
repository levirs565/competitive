#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
  int N;
  cin >> N;

  vector<int> A(N);

  for (auto &a : A)
    cin >> a;

  int shift = 0;
  int count = 0;
  for (int i = N - 1; i >= 0; i--) {
    int current = (A[i] + shift) % 2;
    if (current == 1) {
      count++;
      shift++;
      shift %= 2;
    }
  }

  cout << count << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}