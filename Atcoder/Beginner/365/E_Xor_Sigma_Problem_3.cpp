// Created at 2025/09/16 08:30

#include <iostream>
#include <vector>
#include <array>

using namespace std;

void solution()
{
    int N;
    cin >> N;

    vector<int> A(N);
    for (auto &a : A)
        cin >> a;

    vector<int> prefix_xor(N + 1);
    vector<array<array<array<int, 2>, 2>, 30>> prefix(N + 1); // [i][bit][curr][nilai]

    for (int i = 0; i < N; i++)
    {
        int a = A[i];
        prefix_xor[i + 1] = prefix_xor[i] ^ a;

        for (int bit = 0; bit < 30; bit++)
        {
            for (int last = 0; last < 2; last++)
            {
                int c = (a >> bit) & 1;
                prefix[i + 1][bit][last ^ c][0] = prefix[i][bit][last][0] + (last == c);
                prefix[i + 1][bit][last ^ c][1] = prefix[i][bit][last][1] + (last != c);
            }
        }
    }

    int64_t ans = 0;
    for (int L = 0; L < N - 1; L++)
    {
        int R = N;

        vector<int> bits(30);
        int last = prefix_xor[R] ^ prefix_xor[L];

        for (int bit = 0; bit < 30; bit++)
        {
            int last_bit = (last >> bit) & 1;
            bits[bit] = prefix[R][bit][last_bit][1] - prefix[L][bit][0][1];
        }

        int64_t res = 0;
        int64_t carry = 0;

        int i = 0;
        do
        {
            int64_t n = carry;
            if (i < 30)
                n += bits[i];
            res += (n % 2) << i;
            carry = n / 2;
            i++;
        } while (i < 30 || carry > 0);

        ans += res - A[L];
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 1;
    // cin >> n;
    while (n--)
        solution();
    return 0;
}