#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using i64 = int64_t;

int main() {
    int N, T;
    cin >> N >> T;

    int w = 0;
    int dw = 1000000;

    while (N--) {
        int a;
        cin >> a;
        int d = abs(T - a);

        if (d < dw) {
            dw = d;
            w = a;
        } else if (d == dw && a < w) {
            w = a;
        }
    }

    cout << w << endl;

    return 0;
}