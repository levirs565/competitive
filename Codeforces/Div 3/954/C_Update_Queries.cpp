#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <limits>
#include <set>
#include <vector>
#include <map>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    
    std::string a;
    cin.ignore();
    getline(cin, a);

    std::map<int, int> indexes;
    for (int i = 0; i < m; i++) {
        int j;
        cin >> j;
        indexes[j]++;
    }

    std::string b;
    cin.ignore();
    getline(cin, b);
    sort(b.begin(), b.end());

    // cout << b << endl;

    // current index
    int lIndex = 0, rIndex = m - 1;

    for (auto [index, count] : indexes) {
        if (count > 1) {
            for (int c = 2; c <= count; c++)
                rIndex--;
        }

        a[index - 1] = b[lIndex];
        lIndex++;
    }

    cout << a << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}