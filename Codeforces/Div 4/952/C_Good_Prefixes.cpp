#include <iostream>
#include <vector>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    std::vector<int64_t> array(n);

    for (auto &i : array)
      cin >> i;

    int goodCount = 0;
    int64_t prevSum = 0;
    int64_t maxItem = 0;

    for (auto item : array) {
      prevSum += item;

      if (item > maxItem)
        maxItem = item;

      if (prevSum - 2 * maxItem == 0)
        goodCount++;
    }

    cout << goodCount << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}