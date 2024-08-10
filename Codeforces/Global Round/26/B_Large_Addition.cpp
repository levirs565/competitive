#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

void solution() {
  int t;
  cin >> t;

  int adder1[10], adder2[10];

  for (int i = 0; i <= 8; i++) {
    int num = 10 + i;
    for (int j = 5; j <= 9; j++) {
      if (num - j >= 5 && num - j <= 9) {
        adder1[i] = j;
        adder2[i] = num - j;
        break;
      }
    }
  }
  adder1[9] = -1;
  adder2[9] = -1;

  while (t--) {
    string number;
    cin >> number;

    int64_t a = 0, b = 0, mult = 1;

    for (size_t i = number.size() - 1; i > 0; i--, mult *= 10) {
      int digit = number[i] - '0';
      if (i < number.size() - 1)
        digit--;

      if (adder1[digit] == -1) {
        break;
      }

      a += mult * adder1[digit];
      b += mult * adder2[digit];
    }

    string result = std::to_string(a + b);
    if (result == number) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}