#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

using i64 = long long;

void solution()
{
    int N;
    cin >> N;

    vector<vector<int>> E(N);

    for (int i = 1; i < N; i++)
    {
        int P;
        cin >> P;
        P--;
        E[P].push_back(i);
    }

    vector<i64> W(N);
    for (auto &w : W)
        cin >> w;

    vector<int> D(N);
    for (auto &d : D)
        cin >> d;

    // W diff max saat saya setuju
    auto dfs = [&](auto self, int u) -> pair<i64, i64>
    {
        // cout << "Visit " << u << endl;
        if (E[u].size() == 0)
        {
            return {W[u], W[u]};
        }

        vector<pair<i64, i64>> cr;
        for (auto v : E[u])
        {
            cr.push_back(self(self, v));
        }

        // for (auto c : cr)
        //     cout << c << " ";
        // cout << endl;
        // cout << D[u] << endl;

        sort(cr.begin(), cr.end(), [](auto a, auto b)
             {
                 if (max(a.first, a.second) == max(b.first, b.second)) {
                    if (min(a.first, a.second) != max(b.first, b.second)) {
                     return min(a.first, a.second) < max(b.first, b.second); }
                     else {
                       return min(a.first, a.second) < min(b.first, b.second);
                     }}
                 return max(a.first, a.second) < max(b.first, b.second); });
        i64 maxSum = LLONG_MIN;
        i64 minSum = LLONG_MAX;
        int j = 0;

        do
        {
            i64 sum1 = 0;
            i64 sum2 = 0;
            for (int i = 0; i < (int)cr.size(); i++)
            {
                if (i < D[u])
                {
                    sum1 = max(sum1 + cr[i].first, sum1 + cr[i].second);
                    sum2 = min(sum2 + cr[i].first, sum2 + cr[i].second);
                }
                else
                {
                    sum1 = max(sum1 - cr[i].first, sum1 - cr[i].second);
                    sum2 = min(sum2 - cr[i].first, sum2 - cr[i].second);
                }
            }
            maxSum = max(maxSum, sum1);
            minSum = min(minSum, sum2);
            j++;
            reverse(cr.begin(), cr.end());
        } while (j < 2);

        return {W[u] - maxSum, W[u] - minSum};
    };

    auto [a, b] = dfs(dfs, 0);

    cout << max(abs(a), abs(b)) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}