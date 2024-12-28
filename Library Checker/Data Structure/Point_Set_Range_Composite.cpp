#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using i64 = int64_t;

i64 mod = 998244353;

struct Node {
    // ax + b
    i64 a;
    i64 b;
};

Node compose(Node f1, Node f2) {
    // f1 . f2 = a1(a2x + b2) + b1 = a1a2 + a1b2 + b1
    Node res;
    res.a = (f1.a * f2.a) % mod;
    res.b = ((f1.a * f2.b) % mod + f1.b) % mod;
    return res;
}

i64 eval(Node f, i64 x) {
    return ((f.a * x) % mod + f.b) % mod;
}

vector<Node> seg;
vector<Node> list;

void build(int t, int l, int r) {
    if (l == r) {
        seg[t] = list[l];
    } else {
        int mid = (l + r) / 2;
        build(2 * t + 1, l, mid);
        build(2 * t + 2, mid + 1, r);
        seg[t] = compose(seg[2 * t + 1], seg[2 * t + 2]);
    }
}

Node range(int t, int l, int r, int tl, int tr) {
    if (tl > tr) {
        return {1, 0};
    }
    if (l >= tl && r <= tr) {
        return seg[t];
    }

    int mid = (l + r) / 2;
    return compose(
        range(2 * t + 1, l, mid, tl, min(tr, mid)),
        range(2 * t + 2, mid + 1, r, max(mid + 1, tl), tr)
    );
}

void update(int t, int l, int r, int i, Node node) {
    if (l == r) {
        seg[t] = node; 
    } else {
        int mid = (l + r) / 2;
        if (i <= mid) {
            update(2 * t + 1, l, mid, i, node);
        } else {
            update(2 * t + 2, mid + 1, r, i, node);
        }
        seg[t] = compose(seg[2 * t + 1], seg[2 * t + 2]);
    }
}

void solution()
{
    int N, Q;
    cin >> N >> Q;
    
    list.resize(N);
    seg.resize(4 * N);

    for (auto& node : list) {
        cin >> node.a >> node.b;
    }

    reverse(list.begin(), list.end());

    build(0, 0, N - 1);
    while (Q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int l, r;
            i64 x;
            cin >> l >> r >> x;

            l = N - l;
            r = N - r;

            swap(l, r);

            cout << eval(range(0, 0, N - 1, l, r - 1), x) << endl;
        } else if (t == 0) {
            int p;
            Node node;

            cin >> p >> node.a >> node.b;

            p = N - p - 1;
            update(0, 0, N - 1, p, node);
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