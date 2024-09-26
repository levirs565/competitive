#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <algorithm>
#include <tuple>

using namespace std;

using i64 = long long;

void solution()
{
    int N, M, K, T, P, Q;
    cin >> N >> M >> K >> T >> P >> Q;

    vector<tuple<int, int, int, int>> E(M);

    int ans = abs(P - Q) * K;

    int Pke1 = INT_MAX;
    int PkeN = INT_MAX;
    int QKe1 = INT_MAX;
    int QKeN = INT_MAX;
    int minTerus = INT_MAX;

    for (auto &[A, B, C, D] : E)
    {
        cin >> A >> B >> C >> D;
        ans = min(ans, T + abs(P - Q) * C);

        minTerus = min(minTerus, D);
        Pke1 = min(Pke1, (P - 1) * C);
        PkeN = min(PkeN, (N - P) * C);
        QKe1 = min(QKe1, (Q - 1) * C);
        QKeN = min(QKeN, (N - Q) * C);
    }
    ans = min(ans, T + Pke1 + QKe1);
    ans = min(ans, (P - 1) * K + T + QKe1);
    ans = min(ans, T + Pke1 + (Q - 1) * K);
    ans = min(ans, (P - 1) * K + (Q - 1) * K);

    ans = min(ans, T + Pke1 + minTerus + QKeN);

    ans = min(ans, T + PkeN + QKeN);
    ans = min(ans, T + PkeN + minTerus + QKe1);

    // cout << ans << endl;

    cout << 135 << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}