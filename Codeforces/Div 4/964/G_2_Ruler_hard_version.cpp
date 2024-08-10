#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int l = 1, r = 999;
    while (r - l >= 3) {
      int a = (2 * l + r) / 3;
      int b = (l + 2 * r) / 3;
      cout << "? " << a << " " << b << endl;
      cout << flush;
      int result;
      cin >> result;
      if (result == -1)
        break;
      if (result == (a + 1) * (b + 1)) {
        r = a;
      } else if (result == a * b) {
        l = b;
      } else if (result == a * (b + 1)) {
        l = a;
        r = b;
      }
    }

    if (r - l == 2) {
      cout << "? 1 " << l + 1 << endl << flush;
      int result;
      cin >> result;
      if (result != l + 1) {
        r = l + 1;
      }
    }

    cout << "! " << r << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}