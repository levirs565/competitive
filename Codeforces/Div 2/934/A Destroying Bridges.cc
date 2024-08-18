#include <iostream>

using namespace std;

void solution()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int k;
        cin >> n;
        cin >> k;

        if (k >= n - 1)
        {
            cout << "1" << endl;
            continue;
        }

        cout << n << endl;
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
#include "../test.h"

TEST_CASE("first")
{
    test::check_solution(R"(6
2 0
2 1
4 1
5 10
5 3
4 4
)",
                         R"(2
1
4
1
5
1)");
}

#endif
