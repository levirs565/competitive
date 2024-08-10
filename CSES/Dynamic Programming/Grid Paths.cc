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

    vector<vector<bool>> hasTrap(n, vector(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            if (c == '*')
                hasTrap[i][j] = true;
        }
    }

    vector<vector<long long>> pathCount(n, vector<long long>(n, 0));

    if (!hasTrap[0][0])
        pathCount[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < n - 1 && !hasTrap[i + 1][j])
                pathCount[i + 1][j] = (pathCount[i + 1][j] + pathCount[i][j]) % mod;
            if (j < n - 1 && !hasTrap[i][j + 1])
                pathCount[i][j + 1] = (pathCount[i][j + 1] + pathCount[i][j]) % mod;
        }
    }

    cout << pathCount[n - 1][n - 1] << endl;
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
    test::check_solution(R"(4
....
.*..
...*
*...
)",
                         "3");
}

#endif
