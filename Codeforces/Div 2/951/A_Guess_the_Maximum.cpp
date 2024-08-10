#include <iostream>
#include <vector>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    
    std::vector<int> a(n);

    for (auto& item : a)
        cin >> item;

    int minOfMax = 1e9;
    for (int l = 0; l + 1 < n; l++) {
        minOfMax = min(minOfMax, max(a[l], a[l+1]));
    }

    std::cout << minOfMax - 1 << std::endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}