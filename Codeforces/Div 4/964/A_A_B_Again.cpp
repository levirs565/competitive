#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;



void solution() {
  int t;
  cin >> t;
  while (t--) {
    string a;
    cin >> a;
    cout << a[0] - '0' + a[1] - '0' << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}