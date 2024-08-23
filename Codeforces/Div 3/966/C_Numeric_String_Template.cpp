#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solution()
{
    int n;
    cin >> n;

    vector<pair<int, int>> A(n);

    for (auto &[a, i] : A)
        cin >> a;
    for (int i = 0; i < n; i++)
        A[i].second = i;

    sort(A.begin(), A.end());

    vector<vector<int>> equals;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n && A[i].first == A[i + 1].first)
        {
            equals.push_back({A[i].second});
            while (i + 1 < n && A[i].first == A[i + 1].first)
            {
                i++;
                equals.back().push_back(A[i].second);
            }
        }
    }

    int m;
    cin >> m;

    while (m--)
    {
        string s;
        cin >> s;

        bool ans = s.size() == n;

        if (ans)
        {
            vector<int> cnt(26, 0);
            for (char ch : s)
            {
                cnt[ch - 'a']++;
            }

            for (auto &e : equals)
            {
                char ch = s[e.front()];
                if (cnt[ch - 'a'] != e.size())
                {
                    ans = false;
                    break;
                }
                for (auto i : e)
                {
                    if (s[i] != ch)
                    {
                        ans = false;
                        break;
                    }
                }
                if (!ans)
                    break;
                cnt[ch - 'a'] = 0;
            }

            for (auto c : cnt) {
                if (c > 1) ans = false;
            }
        }

        if (ans) cout << "YES";
        else cout << "NO";
        cout << "\n";
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
        solution();
    return 0;
}