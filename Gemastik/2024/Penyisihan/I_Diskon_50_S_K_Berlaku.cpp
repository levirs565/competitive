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

void solution()
{
  int N, Q;
  cin >> N >> Q;

  vector<int> A(N);
  i64 sum = 0;
  for (auto &a : A)
  {
    cin >> a;
    sum += a;
  }

  sort(A.begin(), A.end(), greater<>());

  vector<i64> diskon(N + 1, -1);

  while (Q--)
  {
    int x;
    cin >> x;

    if (x <= N)
    {
      if (diskon[x] == -1)
      {
        diskon[x] = 0;
        for (int i = x; i <= N; i += x)
        {
          diskon[x] += A[i - 1] / 2;
        }
      }
      cout << sum - diskon[x] << endl;
    }
    else
    {
      cout << sum << endl;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}