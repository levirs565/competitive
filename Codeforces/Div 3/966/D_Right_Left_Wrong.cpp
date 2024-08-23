#include <iostream>
#include <vector>
#include <string>

using namespace std;

using i64 = int64_t;

i64 solve(vector<i64>& P, string& s, int l, int r) {
    if (l >= r) return 0;
    while (l < s.size() && s[l] != 'L') {
        l++;
    }
    while (r >= 0 && s[r] != 'R') {
        r--;
    }

    if (l >= r) return 0;
    if (l >= s.size() || r < 0) return 0;

    return P[r + 1] - P[l] + solve(P, s, l + 1, r - 1);
}

void solution()
{
    int N;
    cin >> N;

    vector<i64> P(N + 1);
    P[0] = 0;
    for (int i = 1; i <= N; i++) {
        int j;
        cin >> j;
        P[i] = P[i - 1] + j;
    }

    string s;
    cin >> s;

    cout << solve(P, s, 0, N - 1) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solution();
    return 0;
}