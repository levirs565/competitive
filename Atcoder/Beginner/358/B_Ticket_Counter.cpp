#include <iostream>
#include <vector>

using namespace std;

void solution() {
    int n, k;
    cin >> n >> k;
    std::vector<int> arrive(n);

    for (auto& i : arrive)
        cin >> i;

    int64_t currentTime = 0;
    for (auto a : arrive) {
        if (currentTime < a) {
            currentTime = a;
        }
        currentTime += k;
        cout << currentTime << endl;
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}