#include <iostream>
#include <climits>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
    int N, Q;
    cin >> N >> Q;
    
    auto A = vector(N, vector(N, 0));
    // P[Y][X]

    for (auto& Y : A) {
        for (auto& X : Y) {
            char ch;
            cin >> ch;
            X = ch == '*';
        }
    }

    auto P = vector(N + 1, vector(N + 1, 0));

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            P[y][x] = P[y - 1][x] + (P[y][x - 1] - P[y - 1][x - 1]) + A[y - 1][x - 1];
        }
    }

    while (Q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int res = P[y2][x2] - P[y2][x1 - 1] - (P[y1 - 1][x2] - P[y1 - 1][x1 - 1]);
        cout << res << endl;
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