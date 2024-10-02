#include <iostream>

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

ll getpower(ll num)
{
    ll count = 0;

    while (num)
    {
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

    if (x < 8)
    {
        return pre[x][y];
    }

    ll m = x / 8;
    ll pm = getpower(m);
    ll pembatas = 8 * (1 << pm);

    if (y >= pembatas)
    {
        return g(x % pembatas, y % pembatas);
    }
    else
    {
        return pembatas + g(x % pembatas, y);
    }
}

void solution()
{
    int N;

    cin >> N;

    ll nimber = 0;

    while (N--)
    {
        char T;
        int X, Y;
        cin >> T >> X >> Y;

        if (T == 'D')
        {
            nimber ^= g(X, Y);
        }
        else if (T == 'K')
        {
            nimber ^= X;
        }
        else
        {
            nimber ^= Y;
        }
    }

    if (nimber == 0)
    {
        cout << "Astik" << endl;
    }
    else
    {
        cout << "Gema" << endl;
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