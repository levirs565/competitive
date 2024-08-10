#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory.h>
#include <set>
#include <vector>

using namespace std;

int mod = 998244353;

struct node {
  int64_t v[10];
  int p = 0;

  node() { memset(v, 0, sizeof(v)); }

  void set(int64_t a) {
    v[0] = a;
    for (int i = 1; i < 10; i++) {
      v[i] = v[i - 1] + 1;
      v[i] %= 10;
    }
  }

  void set(node a, node b, int64_t pow) {
    p = 0;
    for (int i = 0; i < 10; i++) {
      v[i] = ((a.get(i) * pow) % mod + b.get(i) % mod) % mod;
    }
  }

  void shift(int s) {
    p += s;
    p %= 10;
  }

  int64_t get() { return v[p]; }
  int64_t get(int s) { return v[(p + s) % 10]; }
};

class SegmentTree {
  using type = int64_t;
  vector<node> t;
  vector<int> lz;
  vector<type> p;
  vector<type> inv;
  int n;

  type calcBasePow(int pow) {
    if (pow == 0)
      return 1;
    if (pow & 1) {
      type ret = calcBasePow(pow - 1);
      return ((ret % mod) * 10) % mod;
    }
    type ret = calcBasePow(pow / 2);
    return ((ret % mod) * (ret % mod)) % mod;
  }

  void buildPower(int n) {
    auto base = calcBasePow(mod - 2);
    p[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= n; i++) {
      p[i] = (p[i - 1] * 10) % mod;
      inv[i] = (inv[i - 1] * base) % mod;
    }
  }

  void build(int v, int tl, int tr, std::string &str) {
    if (tl == tr) {
      lz[v] = 0;
      t[v].set(str[tl] - '0');
    } else {
      int mid = (tl + tr) / 2;
      build(2 * v, tl, mid, str);
      build(2 * v + 1, mid + 1, tr, str);
      t[v].set(t[2 * v], t[2 * v + 1], p[tr - mid]);
    }
  }

  node query(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return node();
    if (tl == l && tr == r)
      return t[v];

    pushdown(v);
    int mid = (tl + tr) / 2;
    node res;
    res.set(query(2 * v, tl, mid, l, min(r, mid)),
            query(2 * v + 1, mid + 1, tr, max(l, mid + 1), r), p[tr - mid]);
    return res;
  }

  void pushdown(int v) {
    if (lz[v] != 0) {
      t[2 * v].shift(lz[v]);
      t[2 * v + 1].shift(lz[v]);

      lz[2 * v] += lz[v];
      lz[2 * v + 1] += lz[v];

      lz[2 * v] %= 10;
      lz[2 * v + 1] %= 10;

      lz[v] = 0;
    }
  }

  void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
      return;
    if (tl == l && tr == r) {
      t[v].shift(add);

      lz[v] += add;
      lz[v] %= 10;

      return;
    }

    pushdown(v);
    int mid = (tl + tr) / 2;
    update(2 * v, tl, mid, l, min(r, mid), add);
    update(2 * v + 1, mid + 1, tr, max(l, mid + 1), r, add);
    t[v].set(t[2 * v], t[2 * v + 1], p[tr - mid]);
  }

public:
  SegmentTree(string s)
      : t(4 * s.size()), lz(4 * s.size()), p(s.size() + 1), inv(s.size() + 1),
        n(s.size()) {
    buildPower(n);
    build(1, 0, n - 1, s);
  }

  type query(int l, int r) {
    auto e = query(1, 0, n - 1, l, r).get();
    if (r < n - 1) {
      e *= inv[n - 1 - r];
      e %= mod;
    }
    return e;
  }

  void update(int l, int r, int add) { update(1, 0, n - 1, l, r, add); }
};

void solution() {
  int N, Q;
  cin >> N >> Q;
  string str;
  cin >> str;
  SegmentTree s(str);

  while (Q--) {
    int t, l, r;
    cin >> t >> l >> r;

    if (t == 2) {
      cout << s.query(l - 1, r - 1) << endl;
    } else if (t == 1) {
      int c;
      cin >> c;
      s.update(l - 1, r - 1, c);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}