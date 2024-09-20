#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using i64 = int64_t;

i64 mod = 1'000'000'007;

void solution() {
    int N;
    cin >> N;

    int oneCount = 0;

    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            oneCount++;
        }
    }

    vector<i64> dpP(1 << 10, 0), dpC(1 << 10, 0);

    dpP[0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 1 << 10; j++) {
            for (int k = 0; k < 10; k++) {
                dpC[j ^ (1 << k)] += dpP[j];
                dpC[j ^ (1 << k)] %= mod;
            }
        }

        swap(dpP, dpC);
        dpC.assign(1 << 10, 0);
    }

    int mask = 0;
    for (int i = 0; i < oneCount; i++) {
        mask += 1 << i;
    }

    cout << dpP[mask] << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}