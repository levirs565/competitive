#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solution() {
  int n, k;
  cin >> n >> k;

  std::vector<int> a(n);

  for (int &i : a)
    cin >> i;

  if (k <= 0) {
    int64_t sum = 0;
    for (int i : a) {
        sum += (int64_t) i;
    }

    if (sum >= int64_t(k)) {
      std::cout << "Yes" << std::endl;

      std::sort(a.begin(), a.end(), std::greater<int>());

      for (int &i : a) {
        std::cout << i << " ";
      }

      std::cout << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  } else {
    std::cout << "Yes" << std::endl;

    std::sort(a.begin(), a.end());

    for (int &i : a) {
      std::cout << i << " ";
    }

    std::cout << std::endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}