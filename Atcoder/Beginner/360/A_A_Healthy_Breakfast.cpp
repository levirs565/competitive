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
    std::string s;
    getline(cin, s);
    int rIndex = find(s.begin(), s.end(), 'R') - s.begin();
    int mIndex = find(s.begin(), s.end(), 'M') - s.begin();
    if (rIndex < mIndex) cout << "Yes";
    else cout << "No";
    cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}