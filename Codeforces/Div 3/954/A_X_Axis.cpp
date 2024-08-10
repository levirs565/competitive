#include <algorithm>
#include <bitset>
#include <iostream>
#include <limits>
#include <array>

using namespace std;

// |a - x| + |b - x| + |c - x|

void solution() {
  int t;
  cin >> t;
  while (t--) {
    std::array<int, 3> ints;
    cin >> ints[0] >> ints[1] >> ints[2];

    std::sort(ints.begin(), ints.end());

    int minValue = std::numeric_limits<int>::max();
    for (int i = ints[0]; i <= ints[2]; i++) {
        int value = abs(ints[0] - i) + abs(ints[1] - i) + abs(ints[2] - i);
        if (value < minValue) {
            minValue = value;
        } 
    }

    cout << minValue << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}