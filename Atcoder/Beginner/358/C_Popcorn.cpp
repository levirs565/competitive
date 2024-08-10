#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <bitset>

using namespace std;

void solution() {
    int n, k;
    cin >> n >> k;
    
    std::vector<std::bitset<10>> stands(n, std::bitset<10>(0));

    for (auto& s : stands) {
        string a;
        cin >> a;
        for (int i = 0; i < k; i++) {
            s.set(i, a[i] == 'o');
        }
    }

    int minCount = std::numeric_limits<int>::max();

    for (int i = 0; i < (1 << n); i++) {
        std::bitset<10> visited(0);
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                visited |= stands[j];
                count++;
            }
        }

        if (visited.count() == k) {
            minCount = min(minCount, count);
        }
    }

    std::cout << minCount << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}