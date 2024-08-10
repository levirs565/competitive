#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <vector>

using namespace std;


void solution() {
    int n;
    cin >> n;

    std::vector<int> boxes(n);
    std::vector<int> weight(n);

    for (auto& i : boxes) cin >> i;
    for (auto& i : weight) cin >> i;

    std::vector<int> boxMaxWeight(n, 0);
    
    int64_t result = 0;
    for (int i = 0; i < n; i++) {
        if (weight[i] >= boxMaxWeight[boxes[i] - 1]) {
            result += boxMaxWeight[boxes[i] - 1];
            boxMaxWeight[boxes[i] - 1] = weight[i];
        } else {
            result += weight[i];
        }
    }

    cout << result << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}