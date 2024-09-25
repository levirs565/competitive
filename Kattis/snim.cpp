#include <iostream>
#include <set>
#include <vector>

using namespace std;

using ll = int64_t;

void solution() {
    int k;
    cin >> k;

    vector<int> S(k);
    for (auto& s : S) cin >> s;

    constexpr int maxA = 10000;
    ll g[maxA + 1];
    g[0] = 0;

    for (int i = 1; i <= maxA; i++) {
        set<int> numbers;

        for (auto s : S) {
            if (i - s >= 0) {
                numbers.insert(g[i - s]);
            }
        } 

        int mex = 0;
        for (; numbers.count(mex) != 0; mex++) {}

        g[i] = mex;
    }

    int m;
    cin >> m;
    while (m--) {
        int l;
        cin >> l;
        
        int res = 0;

        while (l--) {
            int h;
            cin >> h;
            res ^= g[h];
        }

        if (res == 0) cout << "L";
        else cout << "W";
    }

    cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}