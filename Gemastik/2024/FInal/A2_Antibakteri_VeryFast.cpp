#include <iostream>

using namespace std;

using ll = int64_t;

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
            nimber ^= X ^ Y;
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