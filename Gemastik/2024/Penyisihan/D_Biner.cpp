#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstring>
#include <exception>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;
using i64 = int64_t;

constexpr i64 maxN = 63;
i64 C[maxN][maxN];

int main() {
    for (int n = 0; n < maxN; n++) {
        C[n][0] = 1;
        for (int k = 1; k <= n; k++) {
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
        }
    }

    i64 N;
    cin >> N;
    N--;

    int one = 30;

    string result(63, '0');

    for (int i = 0; i < 63; i++) {
        if (N >= C[63 - i - 1][one]) {
            N -= C[63 - i - 1][one];
            one--;
            result[i] = '1';
        }
    }

    cout << strtoull(result.c_str(), nullptr, 2) << endl;
}