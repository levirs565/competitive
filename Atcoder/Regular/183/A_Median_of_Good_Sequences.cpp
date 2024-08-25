#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using i64 = int64_t;

constexpr int MAX_FACT = 60;
i64 fact[MAX_FACT];

void solution()
{
    int N, K;
    cin >> N >> K;

    if (N % 2 == 0)
    {
        cout << N / 2 << " ";
        for (int i = N; i >= 1; i--)
        {
            for (int j = i == N / 2; j < K; j++)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < K; i++)
        {
            cout << (N + 1) / 2 << " ";
        }

        if (N > 1)
        {
            vector<int> nums;
            for (int i = 1; i <= N; i++)
            {
                if (i == (N + 1) / 2)
                    continue;
                nums.push_back(i);
            }

            cout << nums[nums.size() / 2 - 1] << " ";

            for (int i = nums.size() - 1; i >= 0; i--)
            {
                for (int j = i == (nums.size() / 2 - 1); j < K; j++)
                {
                    cout << nums[i] << " ";
                }
            }
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