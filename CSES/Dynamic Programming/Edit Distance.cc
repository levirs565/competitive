#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

void solution()
{
    string a;
    getline(cin, a);
    string b;
    getline(cin, b);

    vector<vector<int>> editDistance(a.length() + 1, vector<int>(b.length() + 1, 0));

    for (int j = 1; j <= b.length(); j++)
        editDistance[0][j] = j;

    for (size_t i = 1; i <= a.length(); i++)
    {
        editDistance[i][0] = i;
        for (size_t j = 1; j <= b.length(); j++)
        {
            editDistance[i][j] = min(
                {editDistance[i - 1][j] + 1,
                 editDistance[i][j - 1] + 1,
                 editDistance[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 0 : 1)});
        }
    }

    cout << editDistance[a.length()][b.length()] << endl;
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
    test::check_solution(R"(LOVE
MOVIE
)",
                         R"(2)");
}

#endif
