#include <iostream>
#include <climits>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution()
{
    int N;
    cin >> N;

    auto A = vector(N, vector(N, vector(N, 0)));
    // A[x][y][z]

    for (auto &X : A)
    {
        for (auto &Y : X)
        {
            for (auto &z : Y)
            {
                cin >> z;
            }
        }
    }

    auto P = vector(N + 1, vector(N + 1, vector(N + 1, (i64)0)));

    for (int x = 1; x <= N; x++)
    {
        for (int y = 1; y <= N; y++)
        {
            for (int z = 1; z <= N; z++)
            {
                P[x][y][z] = P[x][y - 1][z] + (P[x - 1][y][z] - P[x - 1][y - 1][z]) + (P[x][y][z - 1] - P[x - 1][y][z - 1] - (P[x][y - 1][z - 1] - P[x - 1][y - 1][z - 1])) + A[x - 1][y - 1][z - 1];
            }
        }
    }

    int Q;
    cin >> Q;
    while (Q--)
    {
        int x1, x2, y1, y2, z1, z2;
        cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
        auto result = P[x2][y2][z2] - P[x2][y1 - 1][z2] - (P[x1 - 1][y2][z2] - P[x1 - 1][y1 - 1][z2]) - (P[x2][y2][z1 - 1] - P[x1 - 1][y2][z1 - 1] - (P[x2][y1 - 1][z1 - 1] - P[x1 - 1][y1 - 1][z1 - 1]));
        cout << result << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}