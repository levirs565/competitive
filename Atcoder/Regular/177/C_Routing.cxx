#include <bits/stdc++.h>

using namespace std;

std::array<std::pair<int, int>, 4> edgeList{{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};

int solveColor(int N, std::vector<std::vector<char>>& colorList, char canColor, pair<int, int> from, pair<int, int> to) {
    using Item = tuple<int, int, int>;
    priority_queue<Item, vector<Item>, greater<Item>> openSet;
    int costList[N][N] ;
    vector<vector<bool>> closed(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) {
            costList[i][j] = INT_MAX;
        }
    }

    costList[from.first][from.second] = 0;
    openSet.push({0, from.first, from.second});

    while (!openSet.empty())
    {

        int row = get<1>(openSet.top());
        int column = get<2>(openSet.top());
        openSet.pop();

        if (closed[row][column]) continue;

        closed[row][column] = true;

        for (auto [deltaRow, deltaColumn] : edgeList)
        {
            int newRow = row + deltaRow;
            int newColumn = column + deltaColumn;

            if (newRow < 0 || newRow >= N || newColumn < 0 || newColumn >= N)
                continue;

            int newCost = ((colorList[newRow][newColumn] == canColor) ? 0 : 1);

            if (costList[newRow][newColumn] > costList[row][column] + newCost)
            {
                costList[newRow][newColumn] = costList[row][column] + newCost;
                openSet.push({costList[newRow][newColumn], newRow, newColumn});
            }

        }
    }

    return costList[to.first][to.second];
}

void solution()
{
    int N;
    cin >> N;

    std::vector<std::vector<char>> colorList(N, std::vector<char>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char c;
            cin >> c;

            colorList[i][j] = c;
        }
    }

    int a = solveColor(N, colorList, 'R', {0, 0}, {N - 1, N - 1});
    int b = solveColor(N, colorList, 'B', {0, N - 1}, {N - 1, 0});
    cout << a + b << endl;
}

int main()
{
    solution();
    return 0;
}