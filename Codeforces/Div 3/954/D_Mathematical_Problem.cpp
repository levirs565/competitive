#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <vector>
#include <climits>

using namespace std;

pair<int, int> undefined_result = {INT_MAX, INT_MAX};

// mult stack, sum
pair<int, int> minOp(std::string& str, int index, bool hasTake2) {
  int currentDigit = str[index] - '0';

  if (index == str.size() - 1 && hasTake2)
    return {currentDigit, 0};
  if (index > str.size() - 2 && !hasTake2)
    return undefined_result;

  int result = INT_MAX;

  if (index + 1 < str.size() && !hasTake2) {
    int nextDigit = str[index + 1] - '0';
    int num = currentDigit * 10 + nextDigit;

    if (index == str.size() - 2) {
      return {num, 0};
    }

    auto next = minOp(str, index + 2, true);
    if (next != undefined_result)
      result = min(
        num * next.first + next.second,
        num + next.first + next.second
      );
  }

  {
    int next = minOp(str, index + 1, hasTake2);

    if (next != INT_MAX)
      result = min({
        result,
        currentDigit * next,
        currentDigit + next
      });
  }

  return result;
}

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    string str;
    cin.ignore();
    getline(cin, str);

    cout << minOp(str, 0, false) << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}