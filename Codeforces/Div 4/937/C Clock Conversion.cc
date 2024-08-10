#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>

using namespace std;

void solution()
{
    int t;
    cin >> t;
    while (t--)
    {
        int hour;
        int minute;

        cin >> hour;
        if (cin.get() != ':')
            cout << "Aneh" << endl;

        cin >> minute;
        bool isAm = false;
        if (hour >= 0 && hour < 12)
            isAm = true;
        hour %= 12;

        if (hour == 0)
            hour = 12;

        cout << setw(2) << setfill('0') << hour << ":" << setw(2) << minute << " " << (isAm ? "AM" : "PM") << endl;
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
09:41
18:06
12:14
00:59
00:00
14:34
01:01
19:07
11:59
12:00
21:37
)",
                         R"(09:41 AM
06:06 PM
12:14 PM
12:59 AM
12:00 AM
02:34 PM
01:01 AM
07:07 PM
11:59 AM
12:00 PM
09:37 PM)");
}

#endif
