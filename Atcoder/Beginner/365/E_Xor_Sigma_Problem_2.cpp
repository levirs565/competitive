// Created at 2025/08/17 01:32 

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int jumlah[30][2] = {}; // jumlah[bit][nilai]
    int last[30] = {};

    Node() {}

    Node(int num) {
        for (int i = 0; i < 30; i++) {
            int bit = (num >> i) & 1;
            jumlah[i][bit] = 1;
            last[i] = bit;
        }
    }

    int64_t to_int() {
        int64_t res = 0;
        int64_t carry = 0;
        
        int i = 0;
        do {
            int64_t n = carry;
            if (i < 30) n += jumlah[i][1];
            res += (n % 2) << i;
            carry = n / 2;
            i++;
        } while (i < 30 || carry > 0);

        return res;
    }
};

Node merge(Node l, Node r) {
    Node res;

    for (int i = 0; i < 30; i++) {
        res.jumlah[i][0] = l.jumlah[i][0] + r.jumlah[i][0 ^ l.last[i]];
        res.jumlah[i][1] = l.jumlah[i][1] + r.jumlah[i][1 ^ l.last[i]];
        
        res.last[i] = l.last[i] ^ r.last[i];
    }

    return res;
}

void solution() {    
    int N;
    cin >> N;

    vector<int> A(N);
    for (auto& a : A) cin >> a;

    Node node(A[N - 1]);
    int64_t ans = 0;

    for (int i = N - 2; i >= 0; i--) {
        node = merge(Node(A[i]), node);
        ans += node.to_int() - A[i];
    } 

    cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n = 1;
//   cin >> n;
  while (n--)
    solution();
  return 0;
}