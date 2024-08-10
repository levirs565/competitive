#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

using Mask = std::bitset<16>;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    std::vector<pair<string, string>> list(n);
    std::vector<string> hashIndex;

    for (auto &item : list) {
      cin >> item.first >> item.second;
      hashIndex.push_back(item.first);
      hashIndex.push_back(item.second);
    }

    std::vector<pair<int, int>> listHash(n);

    sort(hashIndex.begin(), hashIndex.end());
    hashIndex.erase(unique(hashIndex.begin(), hashIndex.end()), hashIndex.end());

    transform(list.begin(), list.end(), listHash.begin(), [&](auto &item) {
      return pair(lower_bound(hashIndex.begin(), hashIndex.end(), item.first) -
                      hashIndex.begin(),
                  lower_bound(hashIndex.begin(), hashIndex.end(), item.second) -
                      hashIndex.begin());
    });

    std::vector<std::vector<bool>> canTransition(1 << n,
                                                 std::vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
      canTransition[1 << i][i] = true;
    }

    for (int mask = 0; mask < (1 << n); mask++) {
      Mask m(mask);
      for (int last = 0; last < n; last++) {
        if (!canTransition[mask][last])
          continue;
        for (int next = 0; next < n; next++) {
          if (m.test(next))
            continue;

          if (listHash[last].first == listHash[next].first ||
              listHash[last].second == listHash[next].second) {
            Mask nMask(m);
            nMask.set(next, true);
            canTransition[nMask.to_ulong()][next] =
                canTransition[mask][last] ||
                canTransition[nMask.to_ulong()][next];
          }
        }
      }
    }

    int answer = 0;

    for (int mask = 0; mask < 1 << n; mask++) {
      for (int last = 0; last < n; last++) {
        if (canTransition[mask][last]) {
          answer = max(answer, int(Mask(mask).count()));
        }
      }
    }

    std::cout << n - answer << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}