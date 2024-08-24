#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using i64 = int64_t;

void solution()
{
    int N;
    cin >> N;

    vector<int> H(N);

    for (auto &h : H)
        cin >> h;

    i64 T = 0;
    for (auto h : H)
    {

        if (T % 3 != 0 && h >= 2)
        {
            int j = 3 - (T % 3);
            T += j;
            h -= 2 + j;
        }

        int avail = h / 5;
        h -= avail * 5;
        T += avail * 3;

        while (h > 0)
        {
            T++;
            if (T % 3 == 0)
                h -= 3;
            else
                h--;
        }

    }

    cout << T << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}