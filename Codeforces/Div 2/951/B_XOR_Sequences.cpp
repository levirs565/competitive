#include <iostream>
#include <vector>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    unsigned int x, y;
    cin >> x >> y;
    unsigned int a = x ^ y;
    unsigned int power = __builtin_ctz(a);
    std::cout << (1 << power) << std::endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}