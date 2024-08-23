#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solution()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (s.size() == 2 || s.substr(0, 2) != "10" || s[2] == '0' || stoi(s.substr(2, s.length() - 2)) < 2)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}