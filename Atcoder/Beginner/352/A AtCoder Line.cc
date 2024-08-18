#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

void solution()
{
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    if (X > Y)
        swap(X, Y);

    bool y = false;
    y = Z > X && Z < Y;

    if (y)
        cout << "Yes";
    else
        cout << "No";
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
    test::check_solution(R"(100 23 67 45)",
                         R"(Yes)");
}

#endif
