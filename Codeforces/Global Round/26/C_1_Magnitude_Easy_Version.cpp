#include <algorithm>
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

    vector<int64_t> a(n);
    for (int64_t &i : a)
      cin >> i;

    vector<int64_t> prev, current;
    prev.push_back(0);

    for (int64_t i : a) {
      int64_t minNext = i + prev[0], maxNext = i + prev[0];
      for (int64_t p : prev) {
        int64_t c = i + p;
        int64_t c_2 = abs(c);

        minNext = min({c, c_2, minNext});
        maxNext = max({c, c_2, maxNext});
      }

      current.clear();
      current.push_back(minNext);
      if (minNext != maxNext)
        current.push_back(maxNext);

      std::swap(prev, current);
    }

    int64_t result = std::numeric_limits<int64_t>::min();
    for (int64_t i : prev) {
      result = max(result, i);
    }

    std::cout << result << std::endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}