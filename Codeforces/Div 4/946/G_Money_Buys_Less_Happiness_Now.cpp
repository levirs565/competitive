#include <cmath>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int m;
    int64_t x;
    cin >> m >> x;

    std::vector<int> cost(m + 1);

    for (int i = 1; i <= m; i++) {
      cin >> cost[i];
    }

    int64_t money = 0;
    std::priority_queue<int> queue;

    for (int i = 1; i <= m; i++) {
        if (money >= cost[i]) {
            queue.push(cost[i]);
            money -= cost[i];
        } else if (queue.size() > 0) {
            int top = queue.top();
            if (cost[i] < top) {
                queue.pop();
                queue.push(cost[i]);
                money += top - cost[i];
            }
        }

        money += x;
    }
    

    std::cout << queue.size() << std::endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}