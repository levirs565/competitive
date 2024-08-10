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

#define ll long long int

const int MAX_CHAR = 26;
const int MAX_FACT = 60;
ll fact[MAX_FACT];

// Utility for calculating factorials
void precomputeFactorials() {
  fact[0] = 1;
  for (int i = 1; i < MAX_FACT; i++)
    fact[i] = fact[i - 1] * i;
}

// Function for nth permutation
void nPermute(string &str, i64 rank) {
  precomputeFactorials();

  // Length of given string
  int len = str.size();

  // Count frequencies of all
  // characters
  int freq[MAX_CHAR] = {0};
  for (int i = 0; i < len; i++) {
    freq[str[i] - '0']++;
  }

  // Out string for output string
  char out[MAX_CHAR];

  // Iterate till sum equals n
  i64 sum = 0;
  i64 k = 0;

  // We update both n and sum in this
  // loop.
  while (sum != rank) {
    sum = 0;
    // Check for characters present in freq[]
    for (int i = 0; i < MAX_CHAR; i++) {
      if (freq[i] == 0)
        continue;
      // Remove character
      freq[i]--;

      // Calculate sum after fixing
      // a particular char
      i64 xsum = fact[len - 1 - k];
      for (int j = 0; j < MAX_CHAR; j++)
        xsum /= fact[freq[j]];
      sum += xsum;

      // if sum > n fix that char as
      // present char and update sum
      // and required nth after fixing
      // char at that position
      if (sum >= rank) {
        out[k++] = i + '0';
        rank -= (sum - xsum);
        break;
      }

      // if sum < n, add character back
      if (sum < rank)
        freq[i]++;
    }
  }

  // if sum == n means this
  // char will provide its
  // greatest permutation
  // as nth permutation
  for (int i = MAX_CHAR - 1; k < len && i >= 0; i--)
    if (freq[i]) {
      out[k++] = i + '0';
      freq[i++]--;
    }

  // append string termination
  // character and print result
  out[k] = '\0';
  cout << "1" << out << endl;
}

int main() {
  i64 N, K;
  cin >> N >> K;

  if (K == 1) {
    for (int i = 0; i < N; i++) cout << '1' << endl;
    return 0;
  }
  K--;

  i64 f = 1;

  int Z = 1;
  for (; Z <= N; Z++) {
    f *= (N + Z - 1);
    f /= Z;
    if (K > f) {
      K -= f;
    } else {
      break;
    }
  }

  // cout << Z << " " << K << " " << f << endl;

  string digits;
  for (i64 i = 0; i < Z; i++)
    digits.push_back('0');
  for (i64 i = 0; i < N - 1; i++)
    digits.push_back('1');
  // cout << digits << endl;
  nPermute(digits, K);
  // cout << digits << endl;
  // string result;

  // i64 Y = Z;
  // f *= Y;
  // f /= (N + Y - 1);
  // Y--;
  // cout << f << endl;

  // for (i64 i = 0; i < N + Z; i++) {
  //   i64 q = K / f;
  //   K %= f;
  //   result.push_back(digits[q]);
  //   digits.erase(digits.begin() + q);
  //   if (i < N + Z) {
  //     f *= Y;
  //     f /= (N + Y - 1);
  //     Y--;
  //     cout << f << endl;
  //   }
  // }

  // string s = "1111";

  // int T = 4;
  // while (T--) {
  //   cout << "----" << endl;
  //   s += "0";
  //   sort(s.begin(), s.end());

  //   int count = 0;
  //   do {
  //     if (s[0] != '0') {
  //       cout << s << endl;
  //       count++;
  //     }
  //   } while (next_permutation(s.begin(), s.end()));
  //   cout << count << endl;
  // }

  return 0;
}