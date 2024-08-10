#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;

void solution()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int i = n; i >= 0; i--)
    {
        if (dp[i] == INT_MAX)
            continue;
        for (int j = i; j > 0; j /= 10)
        {
            dp[i - j % 10] = min(dp[i - j % 10], dp[i] + 1);
        }
    }

    cout << dp[0] << endl;
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
    test::check_solution(R"(27
)",
                         "5");
}

#endif
