#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

void solution()
{
    int a, b;

    cin >> a;
    cin >> b;

    vector<vector<int>> dp(a + 1, vector<int>(b + 1, INT_MAX));

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == j)
                dp[i][j] = 0;
            else
            {
                for (int k = 1; k < i; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }

                for (int k = 1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }
            }
        }
    }

    cout << dp[a][b] << endl;
}

#ifndef LOCAL
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}
#else
#define TEST_NO_DIFF
#include "test.h"

TEST_CASE("first")
{
    test::check_solution(R"(3 5
)",
                         R"(3)");
}

#endif
