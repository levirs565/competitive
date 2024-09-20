#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using i64 = int64_t;

i64 mod = 1'000'000'007;

struct Matrix
{
    i64 data[11][11];

    Matrix()
    {
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                data[i][j] = 0;
            }
        }
    }
};

Matrix mult(Matrix a, Matrix b)
{
    Matrix c;

    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            for (int k = 0; k < 11; k++)
            {
                c.data[i][j] += (a.data[i][k] * b.data[k][j]) % mod;
                c.data[i][j] %= mod;
            }
        }
    }

    return c;
}

Matrix binpow(Matrix a, i64 exp)
{
    Matrix res;
    for (int i = 0; i < 11; i++)
    {
        res.data[i][i] = 1;
    }

    Matrix c = a;
    while (exp)
    {
        if (exp & 1)
        {
            res = mult(res, c);
        }

        c = mult(c, c);

        exp >>= 1;
    }

    return res;
}

void solution()
{
    i64 N;
    cin >> N;

    int oneCount = 0;

    for (int i = 0; i < 10; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            oneCount++;
        }
    }

    Matrix m;

    for (int i = 0; i <= 10; i++)
    {
        if (i != 0)
        {
            m.data[i][i - 1] = i;
        }
        if (i != 10)
        {
            m.data[i][i + 1] = 10 - i;
        }
    }

    Matrix r = binpow(m, N);
    cout << r.data[oneCount][0] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}