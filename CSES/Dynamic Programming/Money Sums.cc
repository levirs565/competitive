#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

void solution()
{
    int n;
    cin >> n;
    vector<int> coint(n);
    for (int i = 0; i < n; i++)
        cin >> coint[i];

    set<int> prevSum;
    set<int> sum;

    for (const int &c : coint)
    {
        sum.insert(c);
        for (const int &s : prevSum)
        {
            sum.insert(s + c);
        }

        prevSum = sum;
    }

    cout << sum.size() << endl;
    for (const int &s : sum)
        cout << s << " ";
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
