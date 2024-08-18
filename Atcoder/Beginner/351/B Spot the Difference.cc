#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

void solution()
{
    int N;
    cin >> N;

    cin.ignore();

    vector<string> a(N);
    vector<string> b(N);

    for (int i = 0; i < N; i++) {
        getline(cin, a[i]);
    }

    for (int i = 0; i < N; i++) {
        getline(cin, b[i]);
    }

    int mI = 0;
    int mJ = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] == b[i][j]) continue;
            
            mI = i;
            mJ = j;
            break;
        }
    }

    mI++;
    mJ++;

    cout << mI << " " << mJ << endl;
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
    test::check_solution(R"(3
abc
def
ghi
abc
bef
ghi
)",
                         R"(2 1)");
}

#endif
