#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solution()
{
    int n;
    cin >> n;
    
    vector<bool> state(n + 2, false);
    bool ans = true;

    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        if (i == 0) {
            state[j] = true;
        } else {
            if (!state[j + 1] && !state[j - 1]) {
                ans = false;
            }
            state[j] = true;
        }
    }

    if (ans) cout << "YES";
    else cout << "NO";
    cout << endl;
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