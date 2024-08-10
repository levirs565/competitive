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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int row = 1; row <= n; row++)
        {
            for (int repeat = 1; repeat <= 2; repeat++)
            {
                for (int column = 1; column <= n; column++)
                {
                    if ((row % 2 == 1 && column % 2 == 1) || (row % 2 == 0 && column % 2 == 0))
                        cout << "##";
                    else
                        cout << "..";
                }
                cout << endl;
            }
        }
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
    test::check_solution(R"(4
1
2
3
4
)",
                         R"(##
##
##..
##..
..##
..##
##..##
##..##
..##..
..##..
##..##
##..##
##..##..
##..##..
..##..##
..##..##
##..##..
##..##..
..##..##
..##..##)");
}

#endif
