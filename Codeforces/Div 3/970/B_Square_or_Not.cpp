
#include <iostream>
#include <algorithm>

using namespace std;

void solution()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int oneCount = count(s.begin(), s.end(), '1');

    if (oneCount == n)
    {
        if (n == 1 || n == 4)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    else
    {
        int firstZero = s.find_first_of('0');
        int c = firstZero - 1;

        if (c <= 2 || n % c != 0 || n / c != c)
        {
            cout << "No" << endl;
            return;
        }

        bool yes = true;
        for (int r = 0; r < n / c; r++)
        {
            for (int i = 0; i < c; i++)
            {
                int j = r * c + i;
                char ch = s[j];
                char expected;
                if (r == 0 || r == n / c - 1 || i == 0 || i == c - 1)
                {
                    expected = '1';
                }
                else
                {
                    expected = '0';
                }

                if (ch != expected)
                {
                    yes = false;
                    break;
                }
            }

            if (!yes)
                break;
        }

        if (yes)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
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