#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

using i64 = int64_t;

struct Block
{
    // y location in right of block
    int fL = 0, fU = 1000000001;
    // y location in left of block
    int gL = 0, gU = 1000000001;
    // cost from left to right
    i64 cost = 0;

    // from left
    // cost to make inside gL and gU
    pair<int, i64> walkRight(int y) const
    {
        return {
            clamp(y, fL, fU),
            cost + max(y, gL) - min(y, gU)};
    }
};

Block combine(const Block &a, const Block &b)
{
    Block res;
    res.fL = clamp(a.fL, b.fL, b.fU);
    res.fU = clamp(a.fU, b.fL, b.fU);
    res.gL = clamp(b.gL, a.gL, a.gU);
    res.gU = clamp(b.gU, a.gL, a.gU);
    res.cost = a.cost + b.walkRight(a.walkRight(res.gU).first).second;
    return res;
}

struct SegmentTree
{
        int size;
    vector<Block> data;

    SegmentTree(vector<Block> &v) : size(v.size()), data(4 * v.size())
    {
        build(v, 1, 0, size - 1);
    }

    void build(vector<Block> &v, int t, int tl, int tr)
    {
        if (tl == tr)
        {
            data[t] = v[tl];
        }
        else
        {
            int mid = ((i64)tl + tr) / 2;
            build(v, 2 * t, tl, mid);
            build(v, 2 * t + 1, mid + 1, tr);
            data[t] = combine(data[2 * t], data[2 * t + 1]);
        }
    }

    Block get(int t, int tl, int tr, int l, int r)
    {
        if (l > r)
            return Block();
        if (tl == l && r == tr)
        {
            return data[t];
        }

        int mid = ((i64)tl + tr) / 2;
        return combine(
            get(2 * t, tl, mid, l, min(r, mid)),
            get(2 * t + 1, mid + 1, tr, max(mid + 1, l), r));
    }

    Block get(int l, int r)
    {
        return get(1, 0, size - 1, l, r);
    }
};

void solution()
{
    int N;
    cin >> N;
    vector<Block> segments(N);

    for (auto &s : segments)
    {
        cin >> s.fL;
        s.gL = s.fL;

        cin >> s.fU;
        s.gU = s.fU;
        s.cost = 1;
    }

    SegmentTree sg(segments);

    int Q;
    cin >> Q;

    while (Q--)
    {
        int sx, sy, tx, ty;
        cin >> sx >> sy >> tx >> ty;
        if (sx > tx)
        {
            swap(sx, tx);
            swap(sy, ty);
        }

        Block block = sg.get(sx - 1, tx - 1);
        // for (int i = sx - 1; i < tx; i++)
        // {
        //     block = combine(block, segments[i]);
        // }

        auto [cy, cost] = block.walkRight(sy);
        

        // Subtract 1, because left block has cost 1
        cout << max(cy, ty) - min(cy, ty) + cost - 1 << endl;
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