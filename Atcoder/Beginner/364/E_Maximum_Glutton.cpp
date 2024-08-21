#include <algorithm>
#include <climits>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <numeric>

using namespace std;

using i64 = int64_t;
int N;
vector<pair<int, int>> A;
int X, Y;

int dp()
{
  vector<vector<vector<int>>> dp = vector(N + 1, vector(N + 1, vector<int>(X + 1, INT_MAX)));

  dp[0][0][0] = 0;

  for (int i = 0; i < N; i++)
  {
    auto [dx, dy] = A[i];
    for (int j = 0; j <= i; j++)
    {
      for (int k = 0; k <= X + 1; k++)
      {
        dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
        if (k + dx <= X && dp[i][j][k] != INT_MAX)
        {
          dp[i + 1][j + 1][k + dx] = min(dp[i + 1][j + 1][k + dx], dp[i][j][k] + dy);
        }
      }
    }
  }

  for (int j = N; j >= 0; j--)
  {
    for (int k = X; k >= 0; k--)
    {
      if (dp[N][j][k] <= Y)
      {
        return min(j + 1, N);
      }
    }
  }

  return 0;
}

void solution()
{

  cin >> N;
  cin >> X >> Y;

  A.resize(N);

  for (auto &a : A)
    cin >> a.first >> a.second;

  cout << dp() << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}