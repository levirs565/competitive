#include <iostream>
#include <set>
#include <iomanip>

using namespace std;

using ll = int64_t;

ll pre[8][8] = {
    {0, 1, 2, 3, 4, 5, 6, 7},
    {1, 0, 3, 2, 5, 4, 7, 6},
    {2, 3, 0, 1, 6, 7, 4, 5},
    {3, 2, 1, 0, 7, 6, 5, 4},
    {4, 5, 6, 7, 0, 1, 2, 3},
    {5, 4, 7, 6, 1, 0, 3, 2},
    {6, 7, 4, 5, 2, 3, 0, 1},
    {7, 6, 5, 4, 3, 2, 1, 0}};

ll getpower(ll num) {
    ll count = 0;

    while (num) {
        count++;
        num >>= 1;
    }

    return count - 1;
}

ll g(ll x, ll y)
{
    if (y > x)
    {
        return g(y, x);
    }

    if (x < 8) {
        return pre[x][y];
    }

    ll m = x / 8;
    ll pm = getpower(m);
    ll pembatas = 8 * (1 << pm);

    if (y >= pembatas) {
        return g(x % pembatas, y % pembatas);
    } else {
        return pembatas + g(x % pembatas, y);
    }
}

void kiriAtas()
{
    int X = 100;
    int Y = 100;

    // baris ke x, kolom ke y
    ll G[X + 1][Y + 1];

    G[0][0] = 0;

    // bisa ke kiri, kiri atas
    for (int x = 0; x <= X; x++)
    {
        for (int y = 0; y <= Y; y++)
        {
            if (x == 0 && y == 0)
            {
                cout << setw(2) << 0 << " ";
                continue;
            }

            set<int> A;
            for (int k = 0; k < y; k++)
            {
                A.insert(G[x][k]);
            }

            for (int k = 0; k < x; k++)
            {
                A.insert(G[k][y]);
            }

            int mex = 0;
            for (mex = 0; A.count(mex) != 0; mex++)
            {
            }

            G[x][y] = mex;

            cout << setw(2) << G[x][y] << " ";
        }
        cout << endl;
    }

    // cout << getpower(7) << endl;
    // cout << g(24, 0) << endl;

    for (int x = 0; x <= X; x++)
    {
        for (int y = 0; y <= Y; y++)
        {
            if (G[x][y] != g(x, y))
            {
                cout << "Salah " << x << "," << y << " " << G[x][y] << " " << g(x, y) << endl;
            }
        }
    }
}

void kiriKiriAtas()
{
    int X = 9;
    int Y = 9;

    // baris ke x, kolom ke y
    ll G[X + 1][Y + 1];

    G[0][0] = 0;

    // bisa ke kiri, kiri atas
    for (int x = 0; x <= X; x++)
    {
        for (int y = 0; y <= Y; y++)
        {
            if (x == 0 && y == 0)
            {
                cout << 0 << " ";
                continue;
            }

            set<int> A;
            for (int k = 0; k < y; k++)
            {
                A.insert(G[x][k]);
            }

            for (int k = min(x, y); k > 0; k--)
            {
                A.insert(G[x - k][y - k]);
            }

            int mex = 0;
            for (mex = 0; A.count(mex) != 0; mex++)
            {
            }

            G[x][y] = mex;

            cout << G[x][y] << " ";
        }
        cout << endl;
    }
}

void atasKiriAtas()
{
    int X = 9;
    int Y = 9;

    // baris ke x, kolom ke y
    ll G[X + 1][Y + 1];

    G[0][0] = 0;

    // bisa ke atas, kiri atas

    for (int x = 0; x <= X; x++)
    {
        for (int y = 0; y <= Y; y++)
        {
            if (x == 0 && y == 0)
            {
                continue;
            }

            set<int> A;
            for (int k = 0; k < x; k++)
            {
                A.insert(G[k][y]);
            }

            for (int k = min(x, y); k > 0; k--)
            {
                A.insert(G[x - k][y - k]);
            }

            int mex = 0;
            for (mex = 0; A.count(mex) != 0; mex++)
            {
            }

            G[x][y] = mex;
        }
    }

    for (int x = 0; x <= X; x++)
    {
        for (int y = 0; y <= Y; y++)
        {
            cout << G[x][y] << " ";
        }
        cout << endl;
    }
}

void solution()
{
    cout << "Kiri dan Atas" << endl;
    kiriAtas();
    cout << "Kiri dan Kiri Atas" << endl;
    kiriKiriAtas();
    cout << "Atas dan Kiri Atas" << endl;
    atasKiriAtas();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}