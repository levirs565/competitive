#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void solution()
{
    int n;
    int x;
    cin >> n;
    cin >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (const int &c : coins)
        {
            if (i == c)
                dp[i] = 1;
            else if (i > c && dp[i - c] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }

    int result = dp[x];
    cout << (result == INT_MAX ? -1 : result) << endl;
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
    test::check_solution(R"(3 11
1 5 7
)",
                         "3");
}

TEST_CASE("second")
{
    test::check_solution(R"(100 1000
389 101 552 795 876 269 887 103 154 689 542 920 128 541 44 657 310 531 656 567 386 536 900 374 929 505 255 376 384 709 311 404 699 86 512 518 321 916 408 935 568 662 731 933 238 331 833 235 423 352 205 669 413 152 695 713 878 614 109 164 387 3 287 823 485 716 556 323 924 57 35 705 643 77 200 944 768 490 589 339 701 190 714 349 252 303 74 526 186 644 453 251 429 170 777 216 22 825 514 379
)",
                         "2");
}

TEST_CASE("third")
{
    test::check_solution(R"(10 200
2 3 4 8 9 11 14 16 17 19
)",
                         "11");
}

#endif
