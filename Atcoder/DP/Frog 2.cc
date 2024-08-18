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

    int K;
    cin >> K;

    std::vector<int> height(N + 1);

    for (int i = 1; i <= N; i++) cin >> height[i];

    std::vector<int> cost(N + 1, 0);

    for (int i = 2; i <= N; i++) {
        cost[i] = cost[i - 1] + abs(height[i] - height[i - 1]);
        for (int j = 2; j <= K; j++) {
            if (i - j <= 0) break;

            cost[i] = min(cost[i], cost[i - j] + abs(height[i] - height[i - j]));
        }
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
    test::check_solution(R"(5 3
10 30 40 50 20
)",
                         R"(30)");
}

TEST_CASE("second")
{
    test::check_solution(R"(3 1
10 20 10
)",
                         R"(20)");
}

TEST_CASE("third")
{
    test::check_solution(R"(2 100
10 10
)",
                         R"(0)");
}

TEST_CASE("fourth")
{
    test::check_solution(R"(10 4
40 10 20 70 80 10 20 70 80 60
)",
                         R"(40)");
}

#endif
