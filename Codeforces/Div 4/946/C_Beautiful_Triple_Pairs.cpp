#include <algorithm>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>

using namespace std;

void solution() {
  int t;
  cin >> t;

  while (t--) {
    int l;
    cin >> l;

    std::vector<int> values(l);
    for (int i = 0; i < l; i++) {
      cin >> values[i];
    }

    std::map<pair<int, int>, int64_t> ne1, ne2, ne3;
    std::map<std::tuple<int, int, int>, int64_t> countEqual;

    for (size_t i = 0; i < values.size() - 2; i++) {
      int a1 = values[i];
      int a2 = values[i + 1];
      int a3 = values[i + 2];

      ne1[std::make_pair(a2, a3)]++;
      ne2[std::make_pair(a1, a3)]++;
      ne3[std::make_pair(a1, a2)]++;
      countEqual[std::make_tuple(a1, a2, a3)]++;
    }

    // c*(c - 1)/2 = jumlah sisi graf lengkap dengan n-1 node
    // kalau ada c = 3, berarti ada c*(c-1)/2 pasangan yang dihasilkan

    int64_t sum = 0;
    for (const auto &c : ne1)
      sum += c.second * (c.second - 1) / 2;
    for (const auto &c : ne2)
      sum += c.second * (c.second - 1) / 2;
    for (const auto &c : ne3)
      sum += c.second * (c.second - 1) / 2;
    // Kalau ada 1 pasangan terduplikat, maka ada terhitung 3 kali
    // karena pasangan terdapat di ne1 ne2 dan ne3
    for (const auto &c : countEqual)
      sum -= 3 * c.second * (c.second - 1) / 2;

    std::cout << sum << std::endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}