#include <iostream>
#include <deque>

using namespace std;

void solution() {
    int N, K;
    cin >> N >> K;
    deque<int> D(N);

    for (auto& d : D) cin >> d;

    while (K--) {
        D.push_front(D.back());
        D.pop_back();
    }

    for (auto d : D) cout << d << " ";
    cout << endl; 
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}