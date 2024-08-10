#include <algorithm>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ranges>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

constexpr int prime = 31;
constexpr int maxN = 2e5 + 1;
constexpr i64 mod = 1e9 + 9;
i64 power[maxN];

vector<i64> buildHash(string s) {
  vector<i64> shash(s.length() + 1);
  shash[0] = 0;
  for (int i = 1; i <= s.size(); i++) {
    shash[i] = shash[i - 1] + ((s[i - 1] - 'a' + 1) * power[i]) % mod;
    shash[i] %= mod;
  }
  return shash;
}

void solution() {
  int N;
  cin >> N;

  cin.ignore();
  string s;
  getline(cin, s);

  power[0] = 1;
  for (int i = 1; i <= N; i++) {
    power[i] = (power[i - 1] * prime) % mod;
  }

  // cout << power[N] << endl;
  string r = s;
  reverse(r.begin(), r.end());

  auto shash = buildHash(s);
  auto rhash = buildHash(r);

  int maxLength = 0;
  for (size_t i = 1; i <= N; i++) {
    int L = 1, R = min(i, N - i + 1), ans = 0;

    // cout << i << endl;

    while (L <= R) {
      int mid = (L + R) / 2;
      // start and end inclusive
      int start = i - mid + 1;
      int end = i;
      int rstart = N - (i + mid - 1) + 1;
      int rend = N - i + 1;
      i64 leftHash = shash[end] - shash[start - 1];
      leftHash += mod;
      leftHash %= mod;
      i64 rightHash = rhash[rend] - rhash[rstart - 1];
      rightHash += mod;
      rightHash %= mod;

      // cout << leftHash << " " << rightHash << endl;

      if (start > rstart) {
        rightHash *= power[start - rstart];
        rightHash %= mod;
      } else if (rstart > start) {
        // cout << leftHash * power[rstart - start] << endl;
        leftHash *= power[rstart - start];
        leftHash %= mod;
      }

      // cout << L << " " << R << " " << mid << " " << s.substr(start - 1, mid)
      //      << " " << r.substr(rstart - 1, mid) << endl;
      // cout << leftHash << " " << rightHash << endl;
      // cout << start << " " << end << " " << rstart << " " << rend << endl;
      if (leftHash == rightHash) {
        ans = mid;
        L = mid + 1;
      } else {
        R = mid - 1;
      }
    }

    maxLength = max(maxLength, 2 * ans - 1);

    if (i == N)
      continue;

    L = 1, R = min(i, N - i), ans = 0;

    while (L <= R) {
      int mid = (L + R) / 2;
      int start = i - mid + 1;
      int end = i;
      int rstart = N - (i + mid) + 1;
      int rend = N - i;
      i64 leftHash = (shash[end] - shash[start - 1]) % mod;
      leftHash += mod;
      leftHash %= mod;
      i64 rightHash = (rhash[rend] - rhash[rstart - 1]) % mod;
      rightHash += mod;
      rightHash %= mod;

      if (start > rstart) {
        rightHash *= power[start - rstart];
        rightHash %= mod;
      } else if (rstart > start) {
        leftHash *= power[rstart - start];
        leftHash %= mod;
      }

      // cout << L << " " << R << " " << mid << " " << s.substr(start - 1, mid)
      //      << " " << r.substr(rstart - 1, mid) << endl;
      // cout << leftHash << " " << rightHash << endl;
      // cout << start << " " << end << " " << rstart << " " << rend << endl;

      if (leftHash == rightHash) {
        ans = mid;
        L = mid + 1;
      } else {
        R = mid - 1;
      }
    }

    maxLength = max(maxLength, ans * 2);
    // int oddLength = 0;
    // while (i - oddLength >= 0 && i + oddLength < s.size() &&
    //        s[i - oddLength] == s[i + oddLength])
    //   oddLength++;

    // int evenLength = 0;
    // while (i - evenLength >= 0 && i + 1 + evenLength < s.size() &&
    //        s[i - evenLength] == s[i + 1 + evenLength])
    //   evenLength++;

    // maxLength = max({maxLength, 2 * oddLength - 1, 2 * evenLength});
  }

  cout << maxLength << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}