#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using i64 = int64_t;

void solution()
{
    int N, K;
    cin >> N >> K;

    vector<vector<int>> G(N);
    vector<int> steiner(N, 0);

    for (int i = 1; i <= N - 1; i++) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    int firstSteiner = -1;
    for (int i = 1; i <= K; i++) {
        int u;
        cin >> u;
        u--;
        steiner[u] = 1;
        if (firstSteiner == -1) {
            firstSteiner = u;
        } 
    }

    vector<int> size(N, 0);
    vector<int> penting(N, 0);
    vector<int> visited(N, 0);

    auto dfs = [&] (auto self, int u) -> void {
        if (steiner[u]) {
            penting[u] = 1;
        }
        visited[u] = 1;
        size[u] = 1;
        for (auto v : G[u]) {
            if (!visited[v]) {
                self(self, v);
                if (penting[v]) {
                    penting[u] = 1;
                }
                size[u] += size[v];
            }
        }
    };

    dfs(dfs, firstSteiner);

    visited.assign(N, 0);

    int count = N;

    auto dfs2 = [&] (auto self, int u) -> void {
        visited[u] = true;
        if (!penting[u]) {
            count -= size[u];
            return;
        }

        for (auto v : G[u]) {
            if (!visited[v]) {
                self(self, v);
            }
        }
    };

    dfs2(dfs2, firstSteiner);

    cout << count << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}