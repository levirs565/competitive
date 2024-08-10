#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;

const int mod = 1e9 + 7;

void solution()
{
    int n;
    int x;
    cin >> n;
    cin >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<long long> dp(x + 1, 0);
    for (const int &c : coins)
    {
        for (int i = c; i <= x; i++)
        {
            if (i == c)
                dp[i] += 1;
            else if (i > c)
                dp[i] += dp[i - c];

            dp[i] %= mod;
        }
    }

    cout << dp[x] << endl;
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
    test::check_solution(R"(3 9
2 3 5
)",
                         "3");
}

#endif
