#include <array>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;
using i64 = int64_t;

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<pair<string, string>> T(N);

  for (auto &[nama, nomor] : T) {
    cin >> nama >> nomor;
  }

  sort(T.begin(), T.end());

  while (Q--) {
    string nama;
    cin >> nama;

    auto pos = lower_bound(T.begin(), T.end(), pair<string, string>(nama, ""));
    if (pos != T.end() && pos->first == nama)
      cout << pos->second << endl;
    else
      cout << "NIHIL" << endl;
  }

  return 0;
}