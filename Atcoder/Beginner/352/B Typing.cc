#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

void solution()
{
    string s;
    string t;
    getline(cin, s);
    getline(cin, t);

    size_t i = 0;
    for (char ch : s) {
        if (i > 0) cout << " ";
        for (; i < t.length(); i++) {
            if (ch == t[i])
                break;
        }

        i++;
        cout << i;
    }

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
    test::check_solution(R"(atcoder
atcoder)",
                         R"(1 2 3 4 5 6 7)");
}

#endif
