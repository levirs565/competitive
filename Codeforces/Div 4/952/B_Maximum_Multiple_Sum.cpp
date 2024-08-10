#include <iostream>
#include <vector>

using namespace std;

// formula:
// x + 2x + 3x + ... + kx
// (1 + 2 + 3 + ... + k)x
// k(k+1)x/2
// kx <= n
// k <= n/x

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int maxSum = 0;
    int maxSumX = 0;
    for (int x = 2; x <= n; x++) {
        int k = n / x;
        int sum = k * (k + 1) / 2;
        if (sum >= maxSum) {
            maxSum = sum;
            maxSumX = x;
        }
    }

    cout << maxSumX << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}