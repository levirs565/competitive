#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;

const int mod = 1e9 + 7;

void solution()
{
    int n;
    cin >> n;
    int x;
    cin >> x;

    vector<pair<int, int>> books(n);

    for (int i = 0; i < n; i++)
        cin >> books[i].first;

    for (int i = 0; i < n; i++)
        cin >> books[i].second;

    vector<int> currentMaxPages(x + 1, 0);

    for (const pair<int, int> &book : books)
    {
        for (int i = x; i >= book.first; i--)
        {
            currentMaxPages[i] = max(currentMaxPages[i], book.second + currentMaxPages[i - book.first]);
        }
    }

    cout << currentMaxPages[x] << endl;
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
    test::check_solution(R"(4 10
4 8 5 3
5 12 8 1
)",
                         "13");
}

#endif
