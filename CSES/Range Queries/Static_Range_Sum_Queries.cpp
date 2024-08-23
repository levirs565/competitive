#include <iostream>
#include <climits>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
    int N, Q;
    cin >> N >> Q;

    vector<i64> P(N + 1);
    P[0] = 0;

    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        P[i] = P[i - 1] + x;
    }

    while (Q--) {
        int a, b;
        cin >> a >> b;
        cout << P[b] - P[a - 1] << endl;
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