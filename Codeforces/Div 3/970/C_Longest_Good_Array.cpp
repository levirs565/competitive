#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

using i64 = int64_t;

void solution()
{
    int l, r;
    cin >> l >> r;

    i64 diff = r - l;

    double a = 1;
    double b = 1;
    double c = -2 * diff;

    double D = b * b - 4 * a * c;
    double sD = sqrt(D);
    
    double rA = (-1 * b + sD) / 2 / a;
    double rB = (-1 * b - sD) / 2 / a;

    double rM = max({rA, rB, 0.0});

    cout << floor(rM) + 1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}