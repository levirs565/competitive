#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory.h>
#include <queue>
#include <ranges>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

// prinsip sarang merpati

void solution() {
  int maxN = 1e7 + 1;
  vector<int> primes_of(maxN, 0);

  for (int i = 2; i * i < maxN; i++) {
    if (primes_of[i] != 0)
      continue;
    for (int j = i * i; j < maxN; j += i)
      if (primes_of[j] == 0)
        primes_of[j] = i;
  }

  int N;
  cin >> N;

  set<int> nums;

  for (int i = 0; i < N; i++) {
    int j;
    cin >> j;
    // cout << j << endl;

    map<int, int> factor;
    while (primes_of[j] != 0) {
        factor[primes_of[j]]++;
        j /= primes_of[j];
    }

    // cout << j << endl;
    if (j > 1)
      factor[j]++;

    int num = 1;
    for (auto [p, c] : factor) {
    //   cout << "p=" << p << " c=" << c << endl;
      if (c % 2 == 1)
        num *= p;
    }

    nums.insert(num);
  }

  if (nums.size() == N)
    cout << "-1" << endl;
  else
    cout << nums.size() + 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}