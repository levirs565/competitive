#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;

const int mod = 1e9 + 7;
const int maxN = 1e6;

void solution()
{
#define LAST_SPLIT 0
#define LAST_JOIN 1
    vector<vector<long long>> count(maxN + 1, vector<long long>(2, 0));

    count[1][LAST_SPLIT] = 1;
    count[1][LAST_JOIN] = 1;

    for (int i = 2; i <= maxN; i++)
    {
        count[i][LAST_SPLIT] = (count[i - 1][LAST_JOIN] + 4 * count[i - 1][LAST_SPLIT]) % mod;
        count[i][LAST_JOIN] = (2 * count[i - 1][LAST_JOIN] + count[i - 1][LAST_SPLIT]) % mod;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << (count[n][LAST_JOIN] + count[n][LAST_SPLIT]) % mod << endl;
    }
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
2
6
1337
)",
                         R"(8
2864
640403945)");
}

#endif
