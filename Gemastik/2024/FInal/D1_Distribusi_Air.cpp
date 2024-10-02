#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

constexpr int maxN = 100'000;
using i64 = int64_t;

int par[maxN + 1];
int sz[maxN + 1];

void dsu_init(int N)
{
    for (int i = 0; i < N; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
}

int find_set(int u)
{
    if (par[u] == u)
        return u;
    par[u] = find_set(par[u]);
    return par[u];
}

void union_set(int u, int v)
{
    u = find_set(u);
    v = find_set(v);

    if (u == v)
        return;

    if (sz[u] < sz[v])
    {
        swap(u, v);
    }

    par[v] = u;
    sz[u] += sz[v];
}

i64 nC2(int n)
{
    return (i64)n * (n - 1) / 2;
}

void solution()
{
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<tuple<int, int, int>> edges(M);

    for (auto &[u, v, z] : edges)
    {
        cin >> u >> v >> z;
        u--;
        v--;
    }

    vector<int> queries(Q);

    for (auto& q : queries)
    {
        char t;
        cin >> t;

        cin >> q;
        q--;

        auto &[u, v, z] = edges[q];
        z = 0;
    }

    dsu_init(N);
    for (auto [u, v, z] : edges)
    {
        if (z == 0)
            continue;

        union_set(u, v);
    }

    i64 all = 0;

    for (int i = 0; i < N; i++)
    {
        if (find_set(i) == i)
        {
            all += nC2(sz[i]);
        }
    }

    vector<i64> ans(Q);
    for (int i = Q - 1; i >= 0; i--)
    {
        ans[i] = all;

        auto [u, v, z] = edges[queries[i]];
        z = 1;

        int a = find_set(u);
        int b = find_set(v);

        if (a == b) continue;

        all -= nC2(sz[a]) + nC2(sz[b]);

        union_set(a, b);

        all += nC2(sz[find_set(a)]);
    }

    for (auto a : ans)
    {
        cout << a << endl;
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