#include <iostream>

using namespace std;

using i64 = int64_t;

constexpr int maxN = 100'000 + 1;
constexpr i64 mod = 1e9 + 7;
char op[maxN];
bool cached[maxN][2];
i64 cache[maxN][2];

i64 solve(int i, int c)
{
    if (i < 0)
        return 1;

    if (cached[i][c]) {
        return cache[i][c];
    }

    i64 res = 0;
    if (op[i] == 'A')
    {
        if (c == 1)
        {
            res = solve(i - 1, 1);
        }
        else
        {
            res = ((2 * solve(i - 1, 0)) % mod + solve(i - 1, 1)) % mod;
        }
    }
    else if (op[i] == 'O')
    {
        if (c == 1)
        {
            res = (solve(i - 1, 0) + (2 * solve(i - 1, 1)) % mod) % mod;
        }
        else
        {
            res = solve(i - 1, 0);
        }
    }
    else if (op[i] == 'X')
    {
        res = (solve(i - 1, 1) + solve(i - 1, 0)) % mod;
    }

    cached[i][c] = true;
    cache[i][c] = res;

    return res;
}

void solution()
{
    int N, c;
    cin >> N >> c;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        op[i] = str[0];
    }

    cout << solve(N - 1, c) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}