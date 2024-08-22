#include <iostream>
#include <numbers>
#include <vector>

using namespace std;

using i64 = int64_t;

struct SumSegmentTree
{
    vector<i64> data;
    int size;

    SumSegmentTree(vector<int> &v) : data(4 * v.size()), size{(int)v.size()}
    {
        build(v, 1, 0, size - 1);
    }

    i64 build(vector<int> &v, int t, int l, int r)
    {
        if (l == r)
        {
            data[t] = v[l];
        }
        else
        {
            int mid = (l + r) / 2;
            data[t] = build(v, 2 * t, l, mid) + build(v, 2 * t + 1, mid + 1, r);
        }

        return data[t];
    }

    i64 query(int t, int l, int r, int tl, int tr)
    {
        if (tl > tr)
        {
            return 0;
        }
        if (l >= tl && r <= tr)
        {
            return data[t];
        }
        int mid = (l + r) / 2;
        return query(2 * t, l, mid, tl, min(mid, tr)) + query(2 * t + 1, mid + 1, r, max(mid + 1, tl), tr);
    }

    i64 query(int tl, int tr)
    {
        return query(1, 0, size - 1, tl, tr);
    }

    i64 update(int t, int l, int r, int i, int v)
    {
        if (i < l || i > r)
            return data[t];

        if (l == r && l == i)
        {
            data[t] += v;
            return data[t];
        }

        int mid = (l + r) / 2;
        data[t] = update(2 * t, l, mid, i, v) + update(2 * t + 1, mid + 1, r, i, v);

        return data[t];
    }

    void update(int i, int v)
    {
        update(1, 0, size - 1, i, v);
    }
};

void solution()
{
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    SumSegmentTree sum(A);

    while (Q--) {
        int a;
        cin >> a;
        if (a == 0) {
            int p, x;
            cin >> p >> x;
            sum.update(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << sum.query(l, r - 1) << endl;
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