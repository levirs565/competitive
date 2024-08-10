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

// len(a) == len(b)
string diff(string a, string b) {
  if (a < b) swap(a, b);
  string result;
  int carry = 0;
  for (int i = a.size() - 1; i >= 0; i--) {
    int sub = (a[i] - b[i]) - carry;

    if (sub < 0) {
      sub += 10;
      carry = 1;
    } else {
      carry = 0;
    }

    result.push_back(sub + '0');
  }

  reverse(result.begin(), result.end());

  return result;
}

void solution() {
  string s;
  cin >> s;

  string n = s;
  next_permutation(n.begin(), n.end());
  string p = s;
  prev_permutation(p.begin(), p.end());

  string result = min(diff(n, s), diff(s, p));

  result.erase(0, result.find_first_not_of('0'));

  cout << result << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}