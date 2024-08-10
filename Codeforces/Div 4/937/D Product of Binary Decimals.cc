#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>

using namespace std;

void generateNumber(set<int> &numbers, string lastNumber)
{
    int i = stoi(lastNumber);
    if (i >= 1000000)
        return;

    numbers.insert(i);
    string a = lastNumber + '0';
    generateNumber(numbers, a);
    string b = lastNumber + '1';
    generateNumber(numbers, b);
}

void solution()
{
    set<int> dividerList;
    generateNumber(dividerList, "1");
    dividerList.erase(1);

    // for (const int &c : dividerList)

    //     cout << c << " ";

    // cout << endl;
    int t;
    cin >> t;
    while (t--)
    {
        int number;

        cin >> number;

        // set<int> factor;

        // int divider = 10;

        // while (divider <= number)
        // {
        //     int d = divider + 1;
        //     int d2 = 0;
        //     int d3 = divider + 1;

        //     while ((d + d2) <= number || d3 <= number)
        //     {
        //         if (number % (d + d2) == 0)
        //         {
        //             factor.insert(d + d2);
        //         }
        //         if (number % d3 == 0)
        //             factor.insert(d3);
        //         if (d2 == 0)
        //             d2 = 1;
        //         d2 *= 10;
        //         d3 += d2;
        //     }

        //     divider *= 10;
        // }

        for (set<int>::reverse_iterator r = dividerList.rbegin(); r != dividerList.rend(); r++)
        {
            while (number % *r == 0)
            {
                number /= *r;
            }
        }

        // for (set<int>::iterator r = factor.begin(); r != factor.end(); r++)
        // {
        //     while (number % *r == 0)
        //     {
        //         number /= *r;
        //     }
        // }

        while (number % 10 == 0)
        {
            number /= 10;
        }

        if (number == 1 || dividerList.count(number) > 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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
    test::check_solution(R"(11
121
1
14641
12221
10110
100000
99
112
2024
12421
1001
)",
                         R"(YES
YES
YES
YES
YES
YES
NO
NO
NO
NO
YES)");
}

#endif
