#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
  int T, N;
  cin >> T >> N;

  stack<char> target;
  while (T--) {
    char ch;
    cin >> ch;
    if (target.empty() || target.top() != ch)
      target.push(ch);
  }

  vector<char> destroyer(N);
  for (char &ch : destroyer)
    cin >> ch;

  for (char ch : destroyer) {
    if (target.empty())
      break;

    if (target.top() == ch)
      target.pop();
    else
      target.push(ch);
  }

  if (target.empty())
    cout << "MENANG" << endl;
  else
    cout << "KALAH" << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}