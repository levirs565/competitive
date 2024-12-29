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
    i64 a = 0, b = 1, c = 0;
};

// apply f1, then apply f2
// bx + c

Node compose(Node f1, Node f2)
{
    Node res;
    res.b = (f1.b * f2.b) % mod;
    res.c = ((f2.b * f1.c) % mod + f2.c) % mod;
    res.a = f1.a;
    return res;
}

i64 calc(Node n) {
    return ((n.a * n.b) % mod + n.c) % mod;
}

vector<Node> seg;
vector<i64> a;

void build(int t, int l, int r)
{
    if (l == r)
    {
        seg[t].a = a[l];
    }
    else
    {
        int mid = (l + r) / 2;
        build(2 * t + 1, l, mid);
        build(2 * t + 2, mid + 1, r);
    }
}

// paling pertama di leaf
Node pget(int t, int l, int r, int i)
{
    if (l == r)
    {
        return seg[t];
    }
    int mid = (l + r) / 2;
    if (i <= mid)
    {
        return compose(pget(2 * t + 1, l, mid, i), seg[t]);
    }
    return compose(pget(2 * t + 2, mid + 1, r, i), seg[t]);
}

void rupdate(int t, int l, int r, int tl, int tr, i64 b, i64 c)
{
    if (l > tr || r < tl)
        return;

    if (l >= tl && r <= tr)
    {
        seg[t] = compose(seg[t], Node{0, b, c});
    }
    else
    {
        int mid = (l + r) / 2;

        seg[2 * t + 1] = compose(seg[2 * t + 1], seg[t]);
        seg[2 * t + 2] = compose(seg[2 * t + 2], seg[t]);
        seg[t].b = 1;
        seg[t].c = 0;

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

    // seg[0].b = 2;
    // seg[0].c = 2;
    // seg[1].b = 2;
    // seg[1].c = 3;
    // for (int i = 0; i < N; i++)
    // {
    //     Node n = pget(0, 0, N - 1, i);
    //     // cout << n.a << "," << n.b << "," << n.c << endl;
    //     cout << calc(n) << endl;
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
        }
        else
        {
            int i;
            cin >> i;
            cout << calc(pget(0, 0, N - 1, i)) << endl;
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