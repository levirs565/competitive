#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using i64 = int64_t;

int main() {
    constexpr i64 MAX = 1000000;
    vector<bool> is_prime(MAX + 1, true);
    is_prime[0] = is_prime[1] = false;
    vector<i64> primes;

    for (i64 i = 2; i <= MAX; i++) {
        if (!is_prime[i]) continue;
        primes.push_back(i);
        for (i64 j = i * i; j <= MAX; j += i) {
            is_prime[j] = false;
        }
    }

    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;
        cout << primes[K - 1] << endl;
    }

    return 0;
}