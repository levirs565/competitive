#include <algorithm>
#include <array>
#include <climits>
#include <exception>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;
using i64 = int64_t;

int main() {
  int N, Q;
  cin >> N >> Q;

  deque<pair<int, bool>> state;
  state.emplace_back(N, false);

  while (Q--) {
    int T, V;
    cin >> T >> V;
    if (T == 2) {
      auto a =
          lower_bound(state.begin(), state.end(), pair<int, bool>(V, false));
      if (a->second)
        cout << "open" << endl;
      else
        cout << "close" << endl;
    } else {
      bool newState = T == 1 ? true : false;
      // cout << "--" << endl;
      int prev = 0;
      while (!state.empty()) {
        auto a = state.front();
        if (a.second != newState) {
          int count = a.first - prev;
          if (V >= count) {
            V -= count;
            state.pop_front();
          } else {
            count = V;
            V = 0;
          }
          prev = prev + count;
          if (V == 0)
            break;
        } else {
          prev = a.first;
          state.pop_front();
        }
      }

      if (state.empty() || state.front().second != newState)
        state.push_front({prev, newState});

      // cout << "prev " << prev << endl;

      // for (auto [i, s] : state)
        // cout << i << " " << (s ? 'y' : 'n') << endl;
    }
  }

  return 0;
}