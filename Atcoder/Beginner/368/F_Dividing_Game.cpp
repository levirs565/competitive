#include <iostream>

using namespace std;

void solution() {
    int N;
    cin >> N;

    int x = 0;

    while (N--) {
        int A;
        cin >> A;

        int count = 0;

        for (int i = 2; i * i <= A; i++) {
            while (A % i == 0) {
                A /= i;
                count++;
            }
        }
        if (A > 1) count++;

        x = x ^ count;
    }

    if (x != 0) {
        cout << "Anna" << endl;
    } else {
        cout << "Bruno" << endl;
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}