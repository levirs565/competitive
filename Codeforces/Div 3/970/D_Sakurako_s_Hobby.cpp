#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

using i64 = int64_t;

enum class NodeState
{
    UNVISITED,
    VISITING,
    FINISHED
};

void solution()
{
    int n;
    cin >> n;

    vector<int> P(n);

    for (auto &p : P)
    {
        cin >> p;
        p--;
    };

    string s;
    cin >> s;

    vector<int> sz(n, 0);
    vector<int> cycle(n, -1);
    vector<NodeState> state(n, NodeState::UNVISITED);

    auto dfs = [&](auto self, int u) -> void
    {
        state[u] = NodeState::VISITING;
        if (s[u] == '0')
        {
            sz[u] = 1;
        }

        int v = P[u];
        if (state[v] == NodeState::VISITING)
        {
            cycle[u] = v;
        }
        else if (state[v] == NodeState::UNVISITED)
        {
            self(self, v);
            sz[u] += sz[v];
            cycle[u] = cycle[v];
        }
        else
        {
            sz[u] += sz[v];
            cycle[u] = cycle[v];
        }

        state[u] = NodeState::FINISHED;
    };

    for (int i = 0; i < n; i++) {
        if (state[i] != NodeState::FINISHED)
            dfs(dfs, i);

        cout << sz[cycle[i]] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}