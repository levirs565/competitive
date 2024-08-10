#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;

const int mod = 1e9 + 7;

void solution()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<long long>> count(n, vector<long long>(m + 1, 0));

    for (int i = 0; i < n; i++)
    {
        int minCurrent = 1;
        int maxCurrent = m;
        if (a[i] != 0)
        {
            minCurrent = maxCurrent = a[i];
        }
        for (int j = minCurrent; j <= maxCurrent; j++)
        {
            if (i == 0)
            {
                count[i][j] = 1;
                continue;
            }
            int minPrev = max(1, j - 1);
            int maxPrev = min(m, j + 1);
            for (int k = minPrev; k <= maxPrev; k++)
            {
                count[i][j] = (count[i][j] + count[i - 1][k]) % mod;
            }
        }
    }

    long long sum = 0;
    for (int i = 1; i <= m; i++)
        sum = (sum + count[n - 1][i]) % mod;

    cout << sum << endl;
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
2 0 2
)",
                         "3");
}

TEST_CASE("second")
{
    test::check_solution(R"(4 5
2 0 0 2
)",
                         "7");
}

#endif
