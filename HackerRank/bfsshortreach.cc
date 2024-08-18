#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <limits>
#include <numeric>
#include <queue>

using namespace std;

void single() {
    int N, M;
    cin >> N;
    cin >> M;

    std::vector<std::vector<int>> adjacentList(N + 1);

    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;

        adjacentList[a].push_back(b);
        adjacentList[b].push_back(a);
    }

    int start;
    cin >> start;

    std::vector<int> cost(N + 1, -1);
    std::vector<bool> isVisited(N + 1, false);
    std::queue<int> queue;

    cost[start] = 0;
    isVisited[start] = true;
    queue.push(start);

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();

        for (int n : adjacentList[current]) {
            if (!isVisited[n]) {
                cost[n] = cost[current] + 6;
                queue.push(n);
                isVisited[n] = true;
            }
        }
    }

    for (int i = 1; i <= N; i++)
        if (i != start)
            cout << cost[i] << " ";
    cout << endl;
}

void solution()
{
    int q;
    cin >> q;
    while (q--) {
        single();
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
    test::check_solution(R"(2
4 2
1 2
1 3
1
3 1
2 3
2
)",
                         R"(6 6 -1
-1 6)");
}

#endif
