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
        int a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;

        if (a < b && b < c)
            cout << "STAIR" << endl;
        else if (a < b && b > c)
            cout << "PEAK" << endl;
        else
            cout << "NONE" << endl;
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
    test::check_solution(R"(7
1 2 3
3 2 1
1 5 3
3 4 1
0 0 0
4 1 7
4 5 7
)",
                         R"(STAIR
NONE
PEAK
PEAK
NONE
NONE
STAIR)");
}

#endif
