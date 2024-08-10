#include <iostream>
#include <vector>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    swap(a[0], b[0]);
    cout << a << " " << b << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}