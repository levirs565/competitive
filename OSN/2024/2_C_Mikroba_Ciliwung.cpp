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

void prod(int& a, int m)
{
    if (a * m <= 1000) {
        a *= m;
    }
}

void solution()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> mat(N, vector<int>(M, 0)), matC(N, vector<int>(M, 0));

    int an = N;
    int am = M;

    int cnt = readMat(mat);

    auto removeK = [&]()
    {
        an = N * (M - 1);
        cout << "AKSELERASI " << an << endl
             << flush;

        cnt = readMat(matC);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (!matC[i][j])
                    continue;
                if (!mat[i][j])
                {
                   continue;
                }
                int prevCol = (j - an + 1000 * M) % M;
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

        prod(an, N);
    };

    auto removeB = [&]()
    {
        am = M * (N - 1);
        cout << "AKSELERASI " << am << endl
             << flush;

        cnt = readMat(matC);

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (!matC[i][j])
                    continue;
                if (!mat[i][j])
                {
                    continue;
                }
                int prevRow = (i - am + 1000 * N) % N;
                if (mat[prevRow][j])
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
        prod(am, M);
    };

    while (cnt > 0)
    {
        if (am > an)
        {
            removeB();

            if (cnt > 0)
            {
                removeK();
            }
        }
        else
        {
            removeK();
            if (cnt > 0)
            {
                removeB();
            }
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