#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstring>
#include <exception>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;
using i64 = int64_t;

int MAX_C = 63;
i64 C[64][64];

string genPermutation(i64 zero, i64 one, i64 rank) {
  string result;

  i64 prevSum = 0;
  while (rank != prevSum) {
    i64 sumZero = C[zero + one - 1][zero - 1];
    i64 sumOne = sumZero + C[zero + one - 1][zero];

    prevSum = 0;
    if (sumZero >= rank) {
      result.push_back('0');
      zero--;
      prevSum = sumZero;
    } else if (sumOne >= rank) {
      result.push_back('1');
      rank -= sumZero;
      one--;
      prevSum = sumOne;
    }
  }

  while (one--)
    result.push_back('1');
  while (zero--)
    result.push_back('0');

  return result;
}

int main() {
  for (int N = 1; N <= MAX_C; N++) {
    C[N][0] = 1;
    for (int K = 1; K <= N; K++) {
      C[N][K] = C[N][K - 1] * (N - (K - 1)) / K;
    }
  }

  i64 N = 4, K = 60;
  cin >> N >> K;

  if (K == 1) {
    for (int i = 0; i < N; i++)
      cout << '1';
    return 0;
  }

  K--;

  int Z = 1;
  for (;; Z++) {
    if (Z > 60) {
      throw domain_error("not supported");
    }
    if (K > C[N + Z - 1][Z]) {
      K -= C[N + Z - 1][Z];
    } else {
      break;
    }
  }

  cout << "1" << genPermutation(Z, N - 1, K) << endl;

  return 0;
}