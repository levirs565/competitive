#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool win(int sunet1, int sunet2, int slavic1, int slavic2) {
  int sunet = 0, slavic = 0;
  if (sunet1 > slavic1)
    sunet++;
  if (slavic1 > sunet1)
    slavic++;

  if (sunet2 > slavic2)
    sunet++;
  if (slavic2 > sunet2)
    slavic++;

  return sunet > slavic;
}

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int count =
        win(a, b, c, d) + win(a, b, d, c) + win(b, a, c, d) + win(b, a, d, c);

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