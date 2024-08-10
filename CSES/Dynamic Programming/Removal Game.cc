#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

void solution()
{
    int n;
    cin >> n;
    vector<int64_t> array(n);
    int64_t sum = 0;
    for (int64_t &a : array)
    {
        cin >> a;
        sum += a;
    }

    vector<vector<int64_t>> diff(n, vector<int64_t>(n));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
                diff[i][j] = array[i];
            else
                diff[i][j] = max(
                    array[i] - diff[i + 1][j],
                    array[j] - diff[i][j - 1]);
        }
    }

    cout << (sum + diff[0][n - 1]) / 2 << endl;
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
4 5 1 3
)",
                         R"(8)");
}

#endif
