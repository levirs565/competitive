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

    int first = 0;
    // harusnya memakai multiset
    // kenapa bisa pakai set?
    multiset<int> s;
    s.insert(A[0]);

    for (int i = 1; i < N + K; i++)
    {
        int el = A[i % N];
        while (s.count(el) > 0)
        {
            s.erase(A[first]);
            first++;
            // cout << "Del " << first << endl;
            first %= N;
        }

        s.insert(el);

        while (s.size() >= 2 && *s.rbegin() - *s.begin() + 1 > K)
        {
            // cout << "Del 1" << first << endl;
            s.erase(A[first]);
            first++;
            first %= N;
        }

        ans = min(ans, K - (int)s.size());

        // for (auto c : s) cout << c << " ";
        // cout << endl;
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