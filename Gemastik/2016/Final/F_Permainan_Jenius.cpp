#include <iostream>

using namespace std;

void solution() {
    int N;
    cin >> N;

    int r = 0;

    for (int i = 0; i < N; i++) {
        int S;
        cin >> S;

        int c = 0;
        for (int j = 2; j * j <= S; j++) {
            while (S % j == 0) {
                S /= j;
                c++;
            }
        }

        if (S != 1) {
            c++;
        }

        r ^= c;
    }    

    if (r != 0) {
        cout << "TIDAK" << endl;
    } else {
        cout << "YA" << endl;
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}