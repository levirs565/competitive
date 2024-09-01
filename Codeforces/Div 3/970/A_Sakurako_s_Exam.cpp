
#include <iostream>

using namespace std;

void solution()
{
    int a, b;
    cin >> a >> b;

    b %= 2;
    if (a > 2)
    {
        a %= 2;
        a += 2;
    }

    if ((a == 2 && b == 1) || (a == 2 && b == 0) || (a == 0 && b == 0))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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