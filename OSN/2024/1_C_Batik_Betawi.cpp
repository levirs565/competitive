#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

using i64 = long long;

void solution()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));

    for (auto &r : grid)
    {
        for (auto &c : r)
        {
            cin >> c;
        }
    }

    int Q;
    cin >> Q;

    int totalShift = 0;

    while (Q--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            r1--;
            c1--;
            r2--;
            c2--;
            swap(grid[r1][c1], grid[r2][c2]);
        }
        else if (a == 2)
        {
            int w;
            cin >> w;
            totalShift += w;
            totalShift %= N * M;
        }
        else if (a == 3)
        {

            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            r1--;
            c1--;
            r2--;
            c2--;

            if (r1 == 0 && c1 == 0 && r2 == N - 1 && c2 == M - 1)
            {
                cout << -1 << endl;
                continue;
            }

            vector<int> s;
            for (int r = r1; r <= r2; r++)
            {
                for (int c = c1; c <= c2; c++)
                {
                    s.push_back((grid[r][c] + totalShift) % (N * M));
                }
            }

            sort(s.begin(), s.end());

            int l = -1;
            for (int r : s)
            {
                if (r != l + 1)
                    break;
                l = r;
            }

            if (l + 1 == N * M)
            {
                cout << -1 << endl;
            }
            else
                cout << l + 1 << endl;
        }
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