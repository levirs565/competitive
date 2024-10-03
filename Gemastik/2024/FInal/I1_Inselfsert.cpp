#include <iostream>

using namespace std;

using i64 = int64_t;
constexpr int maxN = 100'000 + 1;
i64 suffix[maxN];
i64 p10[maxN];

void solution()
{
    string N;
    int M, K;
    cin >> N >> M >> K;
    int sz = (int)N.size();

    p10[0] = 1;
    for (int i = 1; i <= sz; i++)
    {
        p10[i] = (p10[i - 1] * 10) % M;
    }

    suffix[sz] = 0;
    for (int i = sz - 1; i >= 0; i--)
    {
        suffix[i] = (suffix[i + 1] + (p10[sz - i - 1] * (N[i] - '0')) % M) % M;
    }

    i64 ans = 0;
    for (int j = 1; j <= K; j++)
    {
        bool yes = false;
        for (int i = 0; i < sz; i++)
        {
            i64 after = suffix[i];
            i64 before = (suffix[0] - suffix[i] + M) % M;
            i64 before2 = (before * 10) % M;
            i64 p = p10[sz - i];

            // cout << before << " " << after << " " << p << endl;

            i64 num = ((after + (p * j) % M) % M + before2) % M;
            
            if (num == 0) {
                // cout << j << endl; 
                yes = true;
                break;
            }
        }

        i64 num = ((suffix[0] * 10) % M + j) % M;
        // cout << j << " " << num << endl;
        if (yes || num == 0) {
            ans++;
        }
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}