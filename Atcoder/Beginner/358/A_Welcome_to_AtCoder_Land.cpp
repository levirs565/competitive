#include <iostream>
#include <vector>

using namespace std;

void solution() {
  string a;
  string b;
  cin >> a;
  cin >> b;
  if (a == "AtCoder" && b == "Land")
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}