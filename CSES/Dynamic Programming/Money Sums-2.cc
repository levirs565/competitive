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
    vector<int> coint(n);
    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> coint[i];
        maxSum += coint[i];
    }

    vector<int> canSum(maxSum + 1, 0);
    canSum[0] = true;

    for (const int &c : coint)
    {
        for (int i = maxSum; i >= c; i--)
        {
            canSum[i] = canSum[i] || canSum[i - c];
        }
    }

    int count = 0;
    for (int i = 1; i <= maxSum; i++)
        if (canSum[i])
            count++;
    cout << count << endl;
    for (int i = 1; i <= maxSum; i++)
        if (canSum[i])
            cout << i << " ";
    cout << endl;
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
4 2 5 2
)",
                         R"(9
2 4 5 6 7 8 9 11 13)");
}

#endif
