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

    std::vector<int> A(N);

    for (int& a : A) {
        cin >> a;
    }

    std::vector<int> S;
    for (int& a : A) {
        S.push_back(a);

        while (S.size() > 1 && S[S.size() - 1] == S[S.size() - 2]) {
            int b = S[S.size() - 1];
            S.erase(S.begin() + S.size() - 2, S.end());
            S.push_back(b + 1);
        }
    }

    cout << S.size() << endl;
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
    test::check_solution(R"(7
2 1 1 3 5 3 3
)",
                         R"(3)");
}

#endif
