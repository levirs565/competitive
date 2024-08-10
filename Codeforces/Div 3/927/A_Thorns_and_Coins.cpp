#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <vector>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cin.ignore();
    std::string a;
    getline(cin, a);

    int count = 0;
    for (int i = 0; i < n;) {
        if (a[i] == '@') {
            count++;
        } else if (a[i] == '*')
            break;
        if (a[i + 1] == '*') {
            i += 2;
        } else {
            i++;
        }
    }

    cout << count << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}