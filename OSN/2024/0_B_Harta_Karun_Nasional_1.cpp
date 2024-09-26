#include <iostream>
#include <iomanip>

using namespace std;

void solution()
{
    int N = 256;
    for (int i = 1; i <= N; i++)
    {
        cout << "TANYA " << N - 1 << endl;
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                continue;
            cout << j << " ";
        }
        cout << endl
             << flush;

        int hasil;
        cin >> hasil;

        if (hasil == 1)
        {
            cout << "JAWAB " << i << endl
                 << flush;
            return;
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