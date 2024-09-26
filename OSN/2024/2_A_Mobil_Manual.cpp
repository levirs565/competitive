#include <iostream>
#include <climits>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <tuple>
#include <memory.h>

using namespace std;

using i64 = long long;

    bool dpa[100000 + 1][100000 + 1];
    int dp[100000 + 1][100000 + 1];

void solution()
{
    int N;
    cin >> N;

    vector<pair<int, int>> LR(N);

    for (auto &[a, b] : LR)
        cin >> a >> b;

    int M;
    cin >> M;

    vector<int> A(M);
    for (auto &a : A)
        cin >> a;

    // event:
    // gigi mulai (L, 1, index)
    // query gigi (A, 2, index)
    // gigi selesai(R, 3, index)

    vector<tuple<int, int, int>> events;

    for (int g = 0; auto [a, b] : LR)
    {
        events.push_back({a, 1, g});
        events.push_back({b, 3, g});
        g++;
    }

    for (int g = 0; auto a : A)
    {
        events.push_back({a, 2, g});
        g++;
    }

    sort(events.begin(), events.end());

    vector<vector<int>> gigis(M);
    {
        unordered_set<int> actives;
        for (auto [e, t, i] : events)
        {
            if (t == 1)
            {
                actives.insert(i);
            }
            else if (t == 3)
            {
                actives.erase(i);
            }
            else
            {
                gigis[i].assign(actives.begin(), actives.end());
            }
        }
    }

    // for (int i = 0; i < N; i++)
    // {
    //     dpa[0][i] = true;
    //     dp[0][i] = 0;
    // }

    // int prevMin = 0,currMin = INT_MAX;

    // for (int i = 0; i < M; i++)
    // {
    //     for (auto g : gigis[i])
    //     {
    //         dp[i + 1][g] = dpa[i][g] ? dp[i][g] : INT_MAX;
    //         dp[i + 1][g] = min(dp[i + 1][g], prevMin + 1);
    //         currMin = min(currMin, dp[i + 1][g]);
    //         dpa[i + 1][g] = dp[i + 1][g] != INT_MAX;
    //     }

    //     swap(prevMin, currMin);
    //     currMin = INT_MAX;

    //     if (prevMin == INT_MAX)
    //         break;
    // }

    // if (prevMin == INT_MAX)
    //     cout << -1 << endl;
    // else
    //     cout << prevMin << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}