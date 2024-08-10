#include <iostream>

using namespace std;

const int maxN = 1e6;
const int mod = 1e9 + 7;

void solution()
{
    int n = 0;
    cin >> n;
    int dp[maxN + 1] = {};
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
            if (i - j >= 0)
            {
                dp[i] += dp[i - j];
                dp[i] %= mod;
            }
    }

    cout << dp[n] << endl;
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
    test::check_solution(R"(3
)",
                         "4");
}

#endif
