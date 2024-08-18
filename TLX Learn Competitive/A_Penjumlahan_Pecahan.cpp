#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int64_t A, B, C, D;
    cin >> A >> B >> C >> D;
    int64_t E = A * D + C * B;
    int64_t F = B * D;
    auto g = gcd(E, F);
    E /= g;
    F /= g;
    cout << E << " " << F << endl;
    return 0;
}