#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution() {
    int N;
    cin >> N;

    vector<int> A(N);

    for (auto& a : A) cin >> a;

    sort(A.begin(), A.end());

    int max1 = 0;
    for (int i = 1; i < N; i++) {
        max1 = max(max1, A[i] - A[i - 1]);
    }

    int max2 = A.back() - A.front();

    cout << max1 << endl;
    cout << max2 << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}