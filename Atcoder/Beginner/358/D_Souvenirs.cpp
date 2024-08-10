#include <algorithm>
#include <bitset>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

void solution() {
  int n, m;
  cin >> n >> m;

  std::vector<int> a(n);
  for (auto &i : a)
    cin >> i;

  std::vector<int> b(m);
  for (auto &i : b)
    cin >> i;

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  bool can = true;
  int64_t price = 0;
  size_t aIndex = 0;

  for (auto i : b) {
    while (a[aIndex] < i && aIndex < a.size()) {
      aIndex++;
    }

    if (aIndex == a.size()) {
      can = false;
      break;
    }

    price += int64_t(a[aIndex]);
    aIndex++;
  }

  if (can)
    std::cout << price << endl;
  else
    std::cout << -1 << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}