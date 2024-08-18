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

    std::vector<int> height(N + 1);

    for (int i = 1; i <= N; i++) cin >> height[i];

    std::vector<int> cost(N + 1, 0);

    cost[2] = abs(height[2] - height[1]);
    for (int i = 3; i <= N; i++) {
        cost[i] = min(
            cost[i - 1] + abs(height[i] - height[i - 1]),
            cost[i - 2] + abs(height[i] - height[i - 2])
        );
    }

    std::cout << cost[N] << std::endl;
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
    test::check_solution(R"(4
10 30 40 20
)",
                         R"(30)");
}

TEST_CASE("second")
{
    test::check_solution(R"(2
10 10
)",
                         R"(0)");
}

TEST_CASE("third")
{
    test::check_solution(R"(6
30 10 60 10 60 50
)",
                         R"(40)");
}

#endif
