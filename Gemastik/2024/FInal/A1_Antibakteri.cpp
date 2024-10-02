#include <iostream>

using namespace std;

void solution() {
    int N;
    char T;
    int X, Y;

    cin >> N >> T >> X >> Y;

    int nimber = 0;

    if (T == 'D') {
        nimber = X == Y ? 0 : 1;
    } else if (T == 'K') {
        nimber = X;
    } else {
        nimber = Y;
    }

    if (nimber == 0) {
        cout << "Astik" << endl;
    } else {
        cout << "Gema" << endl;
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}