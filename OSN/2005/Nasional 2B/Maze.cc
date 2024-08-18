#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <limits>
#include <numeric>
#include <queue>

using namespace std;

using Vec2 = std::pair<int, int>;

struct Node {
    Vec2 pos;
    int value;
    int cost = std::numeric_limits<int>::max();
    bool isClosed;

    bool isWalkable() {
        return value == 0;
    }

    bool operator > (const Node& other) const {
        return cost > other.cost;
    }
};

void solution()
{
    Vec2 size;
    cin >> size.first >> size.second;

    std::vector<std::vector<Node>> grid(size.first + 1, std::vector<Node>(size.second + 1));
    std::vector<Vec2> closeGates;

    for (int i = 1; i <= size.first; i++) {
        for (int j = 1; j <= size.second; j++) {
            grid[i][j].pos = Vec2(i, j);
            grid[i][j].isClosed = false;
            cin >> grid[i][j].value;

            if ((i == 1 || i == size.first || j == 1 || j == size.second) && grid[i][j].isWalkable())
                closeGates.push_back(grid[i][j].pos);
        }
    }

    Vec2 initialPos;
    cin >> initialPos.first >> initialPos.second;

    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> openList;

    grid[initialPos.first][initialPos.second].cost = 0;
    
    openList.push(grid[initialPos.first][initialPos.second]);

    std::array<Vec2, 4> edges = {{{1,0},{-1,0}, {0, 1}, {0, -1}}};

    while (!openList.empty()) {
        Vec2 current = openList.top().pos;
        openList.pop();

        Node& currentNode = grid[current.first][current.second];

        currentNode.isClosed = true; 

        for (auto edge : edges) {
            Vec2 next = {current.first + edge.first, current.second + edge.second};

            if (next.first <= 0 || next.first > size.first) continue;
            if (next.second <= 0 || next.second > size.second) continue;

            Node& nextNode = grid[next.first][next.second];

            if (nextNode.isClosed) continue;
            if (!nextNode.isWalkable()) continue;

            int newCost = currentNode.cost + 1;

            if (nextNode.cost > newCost) {
                nextNode.cost = newCost;
                openList.push(nextNode);
            }
        }
    }

    int minCost = std::numeric_limits<int>::max();

    for (Vec2 pos : closeGates) {
        int currentCost = grid[pos.first][pos.second].cost;
        if (currentCost < minCost)
            minCost = currentCost;
    }

    std::cout << minCost + 1 << std::endl;
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
    test::check_solution(R"(8 10
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
-1 0 0 0 0 0 -1 0 0 0
-1 0 0 -1 -1 0 0 0 -1 -1
-1 -1 0 0 -1 -1 -1 0 0 -1
-1 0 0 0 -1 0 -1 -1 -1 -1
-1 0 -1 0 -1 0 -1 0 0 -1
-1 0 -1 0 0 0 0 0 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
7 5
)",
                         R"(17)");
}

#endif
