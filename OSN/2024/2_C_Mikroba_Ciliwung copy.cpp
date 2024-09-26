#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <algorithm>
#include <tuple>

using namespace std;

using i64 = long long;

int readMat(vector<vector<int>> &mat)
{
    int cnt = 0;
    for (auto &r : mat)
    {
        string s;
        cin >> s;
        for (int i = 0; i < (int)s.size(); i++)
        {
            r[i] = s[i] - '0';
            if (r[i] == 1)
                cnt++;
        }
    }

    return cnt;
}

void solution()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> mat(N, vector<int>(M, 0)), matC(N, vector<int>(M, 0));

    int cnt = readMat(mat);

    while (cnt > 0)
    {
        cout << "AKSELERASI " << 1000 << endl
             << flush;

        cnt = readMat(matC);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (!matC[i][j])
                    continue;
                int prevCol = (j - 1000 + 1000 * M) % M;
                int prevRow = ()
                if (mat[i][prevCol])
                    continue;

                cout << "EKSPERIMEN " << i + 1 << " " << j + 1 << endl
                     << flush;

                int d;
                cin >> d;
                if (d > 0)
                {
                    cnt--;
                }
            }
        }

        swap(matC, mat);
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