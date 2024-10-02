#include <iostream>
#include <array>

using namespace std;
using i64 = int64_t;

void solution() {
    int N, U, D;
    cin >> N >> U >> D;

    array<int, 5> A, B, C;
    array<i64, 5> konstanta;

    for (auto& a : A) cin >> a;
    for (auto& b : B) cin >> b;

    for (size_t i = 0; i < C.size(); i++) {
        C[i] = B[i] - A[i]; 
    }

    for (int i = 0; i < (int)C.size(); i++) {
        int lIndex = (i + (int)C.size() - 1) % (int)C.size();
        int rIndex = (i + 1) % (int)C.size();

        konstanta[i] = 0;
        for (int j = 0; j < (int)C.size(); j++) {
            if (j == lIndex || j == rIndex) {
                konstanta[i] += 2 * C[j];
            } else {
                konstanta[i] -= C[j];
            }
        }

        if (konstanta[i] % 3 != 0) {
            cout << -1 << endl;
            return;
        }

        konstanta[i] /= 3;
    }

    array<i64, 5> x1, x2;

    for (size_t i = 0; i < x1.size(); i++) {
        x2[i] = 0;
        x1[i] = konstanta[i] + x2[i];

        if (x1[i] < 0) {
            x2[i] = -x1[i];
            x1[i] = konstanta[i] + x2[i];
        }
    }

    // for (auto x : x1) cout << x << " ";
    // for (auto x : x2) cout << x << " ";

    array<i64, 5> r1;

    for (int i = 0; i < (int)x1.size(); i++) {
        r1[i] = (i64)U * x1[i] + (i64) D * x2[i];
    }

    for (auto x : r1) cout << x << " ";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}