#include <iostream>
#include <climits>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
    int N;
    cin >> N;

    vector<vector<pair<int, int>>> E(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        E[u].push_back({v, c});
        E[v].push_back({u, c});
    }

    i64 farCost = INT_MIN;
    int farNode = -1;

    vector<int> parent(N, -1);

    auto dfs = [&] (auto self, int u, int p, i64 cost) -> void {
        parent[u] = p;
        if (cost > farCost) {
            farCost = cost;
            farNode = u;
        }

        for (auto [v, c] : E[u]) {
            if (v != p) {
                self(self, v, u, cost + c);
            }
        };
    };

    dfs(dfs, 0, -1, 0);

    int diameter1 = farNode;

    farNode = -1;
    farCost = INT_MIN;

    dfs(dfs, diameter1, -1, 0);
    
    cout << farCost << " ";

    vector<int> nodes;

    for (int u = farNode; u != -1; u = parent[u]) {
        nodes.push_back(u);
    }

    cout << nodes.size() << endl;
    for (auto u : nodes) cout << u << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}