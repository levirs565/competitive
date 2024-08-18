#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

inline int64_t sq(int64_t a) {
    return a * a;
}

void solution()
{
    int N;
    cin >> N;

    std::vector<int64_t> height(N + 1);

    for (int i = 1; i <= N; i++) cin >> height[i];

    std::vector<int64_t> cost(N + 1, 0);

    for (int i = 2; i <= N; i++) {
        cost[i] = cost[i - 1] + sq(height[i] - height[i - 1]);
        if (i > 2) {
            int64_t superCost = 3 * sq(height[i] - height[i - 2]);
            cost[i] = min(cost[i], cost[i - 2] + superCost);
            cost[i] = min(cost[i], cost[i - 1] + sq(height[i - 1] - height[i - 2]) + superCost);
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
    test::check_solution(R"(5
3 4 6 2 5
)",
                         R"(8)");
}

#endif
