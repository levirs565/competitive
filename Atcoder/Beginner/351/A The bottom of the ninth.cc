#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

void solution()
{
    int runA = 0;
    for (int i = 0; i < 9; i++) {
        int a;
        cin >> a;
        runA += a;
    }

    int runB = 0;
    for (int i = 0; i < 8; i++) {
        int b;
        cin >> b;
        runB += b;
    }

    cout << (runA + 1 - runB) << endl;
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
    test::check_solution(R"(0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
)",
                         R"(1)");
}

#endif
