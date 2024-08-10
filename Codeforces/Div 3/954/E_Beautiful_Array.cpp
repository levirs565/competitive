#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <vector>

using namespace std;

int findMinPairSum(vector<int> &number) {
  vector<int> evenSum(number.size() + 1), oddSum(number.size() + 1);

  evenSum[0] = 0;
  oddSum[0] = 0;

  for (int i = 0, even = 0, odd = 0; i < number.size(); i++) {
    if (i % 2 == 0) {
      even += number[i];
    } else {
      odd += number[i];
    }

    evenSum[i + 1] = even;
    oddSum[i + 1] = odd;
  }

  int minSum = INT_MAX;
  for (int i = 0; i < number.size(); i++) {
    int sum = 0;
    if (i % 2 == 0) {
      sum = (oddSum[i] - oddSum[0]) - (evenSum[i] - evenSum[0]) +
            (evenSum.back() - evenSum[i + 1]) - (oddSum.back() - oddSum[i + 1]);
    } else {
      sum = (oddSum[i - 1] - oddSum[0]) - (evenSum[i - 1] - evenSum[0]) +
            (evenSum.back() - evenSum[i + 2]) -
            (oddSum.back() - oddSum[i + 2]) + number[i + 1] - number[i - 1];
    }
    minSum = min(minSum, sum);
  }

  return minSum;
}

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    std::map<int, vector<int>> mods;

    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      mods[a % k].push_back(a);
    }

    int remainderCount = 0;
    int result = 0;

    for (auto &[_, a] : mods) {
      sort(a.begin(), a.end());

      for (auto &i : a)
        i /= k;

      int sum = 0;
      if (a.size() % 2 == 0) {
        for (int j = 1; j < a.size(); j += 2) {
          sum += a[j] - a[j - 1];
        }
      } else {
        sum = findMinPairSum(a);
        remainderCount++;
      }

      result += sum;
    }

    if (remainderCount > 1)
      cout << "-1" << endl;
    else
      cout << result << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}