#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

using i64 = int64_t;

i64 mod = 1e9 + 7;

i64 binpow(i64 a, int b) {
    if (b == 0) return 1;
    if (b % 2 == 1) {
        return (binpow(a, b - 1) * a) % mod;
    }

    i64 r = binpow(a, b / 2);
    return (r * r) % mod;
}

void solution()
{
    int n;
    cin >> n;

    vector<i64> A(n + 1);

    A[0] = 0;

    for (int i = 0; i < n; i++) {
        i64 j;
        cin >> j;
        A[i + 1] = A[i] + j;
    }

    i64 P = 0;

    for (int i = 0; i < n; i++) {
        i64 j = A[i + 1] - A[i];
        j %= mod;
        i64 k = A[n] - A[i + 1];
        k %= mod;
        P += (j * k) % mod;
        P %= mod; 
    }

    i64 Q = i64(n) * (n - 1) / 2;
    Q %= mod;

    // cout << P << " " << Q << " " << binpow(Q, mod - 2) << endl;

    i64 res = (P * binpow(Q, mod - 2)) % mod;

    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}