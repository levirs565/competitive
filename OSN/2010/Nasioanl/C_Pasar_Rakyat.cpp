#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using i64 = int64_t;

int main() {
    int N;
    cin >> N;

    int l = 1;
    while (N--) {
        int D;
        cin >> D;
        l = lcm(D, l);
    }

    cout << l << endl;

    return 0;
}