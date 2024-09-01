#include <iostream>

using namespace std;

using i64 = int64_t;

i64 C[63][64];

void precompute()
{
    for (int n = 0; n < 63; n++)
    {
        C[n][0] = 1;
        for (int k = 1; k <= n; k++)
        {
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
        }
    }
}

void solution()
{
    precompute();

    int N;
    i64 K;
    cin >> N >> K;

    string result(63, '0');

    for (int i = 0; i < 63 && N > 0; i++)
    {
        if (K > C[63 - i - 1][N])
        {
            K -= C[63 - i - 1][N];
            N--;
            result[i] = '1';
        }
    }

    result.erase(result.begin(), result.begin() + result.find_first_of('1'));

    cout << result << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}