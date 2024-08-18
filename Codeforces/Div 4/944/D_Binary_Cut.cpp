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
  cin.ignore();
  while (t--) {
    string s;
    getline(cin, s);

    int count = 1;
    char last = s[0];
    bool hasIncrease = false;
    for (auto ch : s) {
        if (!hasIncrease && ch < last) {
            count++;
        } else if (hasIncrease && ch != last) {
            count++;
        }
        if (!hasIncrease && ch > last) {
            hasIncrease = true;
        }
        last = ch;
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