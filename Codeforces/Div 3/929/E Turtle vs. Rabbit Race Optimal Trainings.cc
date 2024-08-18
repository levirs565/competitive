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
        vector<int> a(n);
        vector<int> s(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s[i] = a[i];
            if (i > 0)
                s[i] += s[i - 1];
        }

        int q;
        cin >> q;
        while (q--)
        {
            int l;
            int u;
            cin >> l;
            cin >> u;

            int lowerStep = (l >= 2 ? s[l - 2] : 0);
            int possibleMax = upper_bound(s.begin(), s.end(), lowerStep + u) - s.begin();

            if (possibleMax == n)
                cout << n << " ";
            else if (possibleMax == l - 1)
                cout << l << " ";
            else
            {
                int right = possibleMax;
                long long current = s[possibleMax - 1] - lowerStep;
                long long next = s[possibleMax] - lowerStep;
                if (1ll * current * u - (current) * (current - 1) / 2 >= 1ll * next * u - (next) * (next - 1) / 2)
                    right = possibleMax - 1;

                cout << right + 1 << " ";
            }
        }
        cout << endl;
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
    test::check_solution(R"(5
6
3 1 4 1 5 9
3
1 8
2 7
5 9
1
10
1
1 1
9
5 10 9 6 8 3 10 7 3
5
8 56
1 12
9 3
1 27
5 45
5
7 9 2 5 2
10
1 37
2 9
3 33
4 32
4 15
2 2
4 2
2 19
3 7
2 7
10
9 1 6 7 6 3 10 7 3 10
5
10 43
3 23
9 3
6 8
5 14
)",
                         R"(3 4 5 
1 
9 2 9 4 9 
5 2 5 5 5 2 4 5 4 2 
10 6 9 7 7 )");
}

#endif
