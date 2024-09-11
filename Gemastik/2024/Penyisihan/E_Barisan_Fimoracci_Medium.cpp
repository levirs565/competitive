#include <iostream>
#include <vector>

using namespace std;

using i64 = int64_t;

i64 mod = 1'000'000'007;
i64 dpP[1001][1001];
i64 dpC[1001][1001];
i64 adder[1001][1001];

void solution()
{
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (auto &a : A)
        cin >> a;

    i64 result = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            dpP[i][j] = 1;
            if (K <= 2)
            {
                result += 1;
                result %= mod;
            }
        }
    }

    for (int len = 3; len <= N; len++)
    {
        bool yes = false;
        for (int i = 0; i < N; i++)
        {
            i64 a = 0;
            auto lastPos = A.begin() + i + 1;
            for (int j = i + 1; j < N; j++)
            {
                a += adder[i][j];
                a %= mod;
                dpC[i][j] += a;
                dpC[i][j] %= mod;

                if (dpP[i][j] == 0)
                    continue;
                auto firstPos = lower_bound(lastPos, A.end(), A[i] + A[j]);
                lastPos = firstPos;
                if (firstPos == A.end())
                    break;
                yes = true;
                int p = firstPos - A.begin();
                if (len >= K) {
                    result += (dpP[i][j] * (N - p)) % mod;
                    result %= mod;
                }
                adder[j][p] += dpP[i][j];
            }
        }
        
        // NAMBAHIN INI AJA BISA MEMPERCEPAT
        // DARI TLE MENJADI AC
        if (!yes) break;

        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                adder[i][j] = 0;
                dpP[i][j] = dpC[i][j];
                dpC[i][j] = 0;
            }
        }
    }

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