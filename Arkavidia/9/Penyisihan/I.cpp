#include <iostream>

using namespace std;

void solution()
{
    int N, K;
    cin >> N >> K;

    if (K < 0)
    {
        N -= 2;
        if (N < 0)
        {
            cout << "NO" << endl;
            return;
        }
        K *= -1;
    }
    if (K <= N)
    {
        int sisa = N - K;
        if (sisa % 2 == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
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