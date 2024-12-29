#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using i64 = int64_t;

i64 mod = 998244353;

struct Node
{
    i64 a, b, c;
    bool isLazy = false;
};

vector<Node> seg;
vector<i64> a;

void build(int t, int l, int r)
{
    if (l == r)
    {
        seg[t] = {a[l], 0, 0, false};
    }
    else
    {
        int mid = (l + r) / 2;
        build(2 * t + 1, l, mid);
        build(2 * t + 2, mid + 1, r);
        seg[t] = {0, 0, 0, false};
    }
}

void pull_down(int t, int l, int r)
{
    if (!seg[t].isLazy)
        return;

    if (l == r)
    {
        Node &n = seg[t];
        n.a = ((n.a * n.b) % mod + n.c) % mod;
        n.isLazy = false;
        return;
    }

    int mid = (l + r) / 2;
    pull_down(2 * t + 1, l, mid);
    pull_down(2 * t + 2, mid + 1, r);

    seg[2 * t + 1].b = seg[2 * t + 2].b = seg[t].b;
    seg[2 * t + 1].c = seg[2 * t + 2].c = seg[t].c;
    seg[2 * t + 1].isLazy = seg[2 * t + 2].isLazy = true;
    seg[t].isLazy = false;
}

Node pget(int t, int l, int r, int i)
{
    pull_down(t, l, r);

    if (l == r)
    {
        return seg[t];
    }
    int mid = (l + r) / 2;
    if (i <= mid)
    {
        return pget(2 * t + 1, l, mid, i);
    }
    return pget(2 * t + 2, mid + 1, r, i);
}

void rupdate(int t, int l, int r, int tl, int tr, i64 b, i64 c)
{
    if (l > tr || r < tl)
        return;

    pull_down(t, l, r);

    if (l >= tl && r <= tr)
    {
        seg[t].b = b;
        seg[t].c = c;
        seg[t].isLazy = true;
    }
    else
    {
        int mid = (l + r) / 2;
        rupdate(2 * t + 1, l, mid, tl, min(tr, mid), b, c);
        rupdate(2 * t + 2, mid + 1, r, max(mid + 1, tl), tr, b, c);
    }
}

void solution()
{
    int N, Q;
    cin >> N >> Q;

    a.resize(N);
    seg.resize(4 * N);

    for (auto &i : a)
    {
        cin >> i;
    }

    build(0, 0, N - 1);

    // for (int i = 0; i < N; i++)
    // {
    //     cout << pget(0, 0, N - 1, i).a << endl;
    // }

    while (Q--)
    {
        int t;
        cin >> t;
        if (t == 0)
        {
            int l, r;
            i64 b, c;

            cin >> l >> r >> b >> c;
            rupdate(0, 0, N - 1, l, r - 1, b, c);
        } else {
            int i;
            cin >> i;
            cout << pget(0, 0, N - 1, i).a << endl;            
        }
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