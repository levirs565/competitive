#include <iostream>
#include <climits>
#include <vector>
#include <set>

using namespace std;

void solution()
{
    int N, K;
    cin >> N >> K;

    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    int ans = K - 1;
    for (int i = 0; i < N; i++)
    {
        set<int> s;
        s.insert(A[i]);
        int count = K - 1;

        for (int j = 1; j < K; j++) {
            int idx = (i + j) % N;
            if (A[idx] >= A[i] + K) break;
            if (A[idx] <= A[i] - K) break;
            if (s.count(A[idx])) break;

            s.insert(A[idx]);
            if (*s.rbegin() - *s.begin() + 1 > K) break;
            count--;
            ans = min(ans, count);

            // if (count == 0) {
                // cout << A[i] + K << endl;
                // for (auto c : s) cout << c << " ";
                // cout << endl;
            // }
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