#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int m;
    int64_t x;
    cin >> m >> x;

    std::vector<pair<int64_t, int>> costHappiness(m + 1);

    for (int i = 1; i <= m; i++) {
      cin >> costHappiness[i].first >> costHappiness[i].second;
    }

    std::map<int, int64_t> prev, current;

    prev[0] = 0;

    for (int i = 1; i <= m; i++) {
      for (auto &[happy, money] : prev) {
        if (money + x > current[happy]) {
          current[happy] = money + x;
        }
        if (money >= costHappiness[i].first) {
          int nextHapy = happy + costHappiness[i].second;
          int64_t nextMoney = money - costHappiness[i].first + x;
          if (nextMoney > current[nextHapy])
            current[nextHapy] = nextMoney;
        }
      }

      std::swap(prev, current);
      current.clear();
    }

    int maxHappy = 0;
    for (auto &[happy, money] : prev) {
      maxHappy = max(maxHappy, happy);
    }

    std::cout << maxHappy << std::endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}