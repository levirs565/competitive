#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

void solution()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int count1 = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
                count1++;
        }

        if (count1 == 1)
        {
            cout << "YES" << endl;
        }
        else if (count1 > 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            int m = *min_element(a.begin(), a.end());
            if (count(a.begin(), a.end(), m) == 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                bool can = false;
                for (const int &elemen : a)
                {
                    if (elemen % m > 0)
                    {
                        can = true;
                        break;
                    }
                }

                if (can)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
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
    test::check_solution(R"(8
6
1 2 3 4 5 6
5
3 3 3 3 3
3
2 2 3
5
1 1 2 3 7
3
1 2 2
3
1 1 2
6
5 2 10 10 10 2
4
3 6 9 3
)",
                         R"(YES
NO
YES
NO
YES
NO
YES
NO)");
}

#endif
