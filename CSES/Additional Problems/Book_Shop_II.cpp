#include <iostream>
#include <vector>
#include <climits>

using namespace std;

using i64 = int64_t;

void solution()
{
    int n, x;
    cin >> n >> x;

    vector<int> H(n);
    for (auto &h : H)
        cin >> h;

    vector<int> S(n);
    for (auto &s : S)
        cin >> s;

    vector<int> K(n);
    for (auto &k : K)
        cin >> k;

    vector<pair<i64, i64>> items;
    for (int i = 0; i < n; i++)
    {
        int price = H[i], page = S[i], copy = K[i];

        int count = 1;
        while (copy > count)
        {
            items.push_back({(i64)price * count, (i64)page * count});
            copy -= count;
            count *= 2;
        }

        if (copy > 0)
        {
            items.push_back({(i64)price * copy, (i64)page * copy});
        }
    }
    // dp[x] = jumlah halaman max saat membeli n buku pertama dengan harga x
    auto dp = vector(x + 1, (i64)LLONG_MIN);
    dp[0] = 0;

    for (int i = 1; i <= (int)items.size(); i++)
    {
        auto [price, page] = items[i - 1];
        for (int j = x; j >= 0; j--)
        {
            if (dp[j] == LLONG_MIN)
                continue;
            if (j + price <= x)
                dp[j + price] = max(dp[j + price], dp[j] + page);
        }
    }

    i64 ans = 0;
    for (int i = x; i >= 0; i--)
    {
        if (dp[i] == LLONG_MIN) continue;
        ans = max(ans, dp[i]);
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