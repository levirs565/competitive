#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt[(size_t)1e6 + 1];

void solution()
{
    int Q;
    cin >> Q;

    int all = 0;

    while (Q--)
    {
        int a;
        cin >> a;

        if (a == 1)
        {
            int x;
            cin >> x;
            cnt[x]++;
            if (cnt[x] == 1) {
                all++;
            }
        } else if (a == 2) {
            int x;
            cin >> x;
            cnt[x]--;
            if (cnt[x] == 0) {
                all--;
            }
        } else {
            cout << all << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}