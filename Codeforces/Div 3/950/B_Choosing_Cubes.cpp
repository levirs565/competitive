#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int n, f, k;
    cin >> n >> f >> k;

    std::vector<int> a(n);

    for (int &item : a)
      cin >> item;

    int favorite = a[f - 1];

    std::sort(a.begin(), a.end(), std::greater<int>());

    if ((a[k - 1] == favorite) && k < n && a[k] == favorite)
      std::cout << "MAYBE" << endl;
    else if (a[k - 1] < favorite || a[k - 1] == favorite)
      std::cout << "YES" << endl;
    else
      std::cout << "NO" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}