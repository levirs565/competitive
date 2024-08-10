#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

using i64 = int64_t;

i64 solve(int A, int B, int C, int D) {
  // cout << A << " " << B << " " << C << " " << D << endl;
  if (A != 0) {
    i64 hari = A / 3;
    A %= 3;

    i64 result = hari + (A != 0) + solve(0, B, C, D);

    // cout << result << endl;
    if (C != 0 && B == 0 && A != 0) {
      result = min(result, hari + 1 + solve(0, B, max(C - (3 - A), 0), D));
      // cout << result << endl;
    }
    if (D != 0 && B == 0 && C == 0 && A != 0) {
      result = min(result, hari + 1 + solve(0, B, C, max(D - (3 - A), 0)));
      // cout << result << endl;
    }

    return result;
  } else if (B != 0) {
    i64 hari = B / 3;
    B %= 3;

    i64 result = hari + (B != 0) + solve(0, 0, C, D);

    if (C != 0 && B != 0) {
      result = min(result, hari + 1 + solve(0, 0, max(C - (3 - B), 0), D));
    }
    if (D != 0 && C == 0 && B != 0) {
      result = min(result, hari + 1 + solve(0, 0, C, max(D - (3 - B), 0)));
    }

    return result;
  }

  i64 hariC = C / 3;
  if (C % 3 != 0)
    hariC++;

  i64 hariD = D / 3;
  if (D % 3 != 0)
    hariD++;

  return hariC + hariD;
}

void solution() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  cout << solve(A, B, C, D) << endl;

  // i64 hari = A / 3;

  // A %= 3;

  // if (A != 0) {
  //   if (C != 0) {
  //     C -= 3 - A;
  //     hari++;
  //     if (C < 0)
  //       C = 0;
  //     A = 0;
  //   } else if (D != 0) {
  //     D -= 3 - A;
  //     hari++;
  //     if (D < 0)
  //       D = 0;
  //     A = 0;
  //   } else {
  //     hari++;
  //     A = 0;
  //   }
  // }

  // hari += B / 3;

  // B %= 3;

  // if (B != 0) {
  //   if (C != 0) {
  //     C -= 3 - B;
  //     hari++;
  //     if (C < 0)
  //       C = 0;
  //     B = 0;
  //   } else if (D != 0) {
  //     D -= 3 - B;
  //     hari++;
  //     if (D < 0)
  //       D = 0;
  //     B = 0;
  //   } else {
  //     hari++;
  //     B = 0;
  //   }
  // }

  // hari += C / 3;
  // C %= 3;

  // if (C != 0) {
  //   hari++;
  // }

  // hari += D / 3;
  // D %= 3;

  // if (D != 0)
  //   hari++;

  // cout << hari << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}