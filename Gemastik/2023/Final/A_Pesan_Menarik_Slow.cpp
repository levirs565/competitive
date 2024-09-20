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

    vector<i64> dpP(11, 0), dpC(11, 0);

    dpP[0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 10; j++) {
            if (j > 0) {
                dpC[j] += (j * dpP[j - 1]) % mod;
                dpC[j] %= mod;
            }
            if (j < 10) {
                dpC[j] += ((10 - j) * dpP[j + 1]) % mod;
                dpC[j] %= mod;
            }
        }

        swap(dpP, dpC);
        dpC.assign(11, 0);
    }

    cout << dpP[oneCount] << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}