#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution()
{
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> R(n);

    for (auto &[a, b] : R)
    {
        cin >> a >> b;
    }

    // dp[n][k] = operasi minimal untuk mendapatkan k poin dengan n rectangle pertama
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++)
    {
        auto [a, b] = R[i];
        int maxPoint = a + b;
        int cost = 0;

        for (int newPoint = 0; newPoint <= maxPoint; newPoint++)
        {
            for (int j = 0; j + newPoint <= k; j++)
            {
                if (dp[i][j] == INT_MAX)
                    continue;

                dp[i + 1][j + newPoint] = min(dp[i + 1][j + newPoint], dp[i][j] + cost);
            }

            if (newPoint < maxPoint)
            {
                if (a >= b)
                {
                    a--;
                    cost += b;
                }
                else
                {
                    b--;
                    cost += a;
                }
            }
        }
    }

    cout << (dp[n][k] == INT_MAX ? -1 : dp[n][k]) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solution();
    return 0;
}