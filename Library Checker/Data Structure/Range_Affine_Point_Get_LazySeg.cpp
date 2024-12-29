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
    // bx + c
};

Node compose(Node f1, Node f2)
{
    // f2 then f1
    // x1 = b2 x2 + c2
    // x0 = b1 x1 + c1 = b1 (b2 x2 + c2) + c1 = b1 b2 x2 + b1c2 + c1
    Node res;
    res.b = (f1.b * f2.b) % mod;
    res.c = ((f1.b * f2.c) % mod + f1.c) % mod;
    res.a = f2.a;
    return res;
}

vector<Node> seg;
vector<i64> a;

void build(int t, int l, int r)
{
    if (l == r)
    {
        seg[t] = {a[l], 1, 0};
    }
    else
    {
        int mid = (l + r) / 2;
        build(2 * t + 1, l, mid);
        build(2 * t + 2, mid + 1, r);
        seg[t] = {0, 1, 0};
    }
}

void push(int t, int l, int r)
{
    seg[2 * t + 1] = compose(seg[t], seg[2 * t + 1]);
    seg[2 * t + 2] = compose(seg[t], seg[2 * t + 2]);
    seg[t].b = 1;
    seg[t].c = 0;
}

Node pget(int t, int l, int r, int i)
{
    if (l == r)
    {
        return seg[t];
    }

    push(t, l, r);
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

    if (l >= tl && r <= tr)
    {
        seg[t] = compose(Node{0, b, c}, seg[t]);
    }
    else
    {
        int mid = (l + r) / 2;

        push(t, l, r);
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
        }
        else
        {
            int i;
            cin >> i;
            Node n = pget(0, 0, N - 1, i);
            cout << ((n.a * n.b) % mod + n.c) % mod << endl;
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