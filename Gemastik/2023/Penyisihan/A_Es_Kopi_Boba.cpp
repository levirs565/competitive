#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory.h>
#include <queue>
#include <set>
#include <vector>

using namespace std;

using i64 = int64_t;

void solution() {
  int N;
  cin >> N;

  int sum = 0;

  vector<int> a(N);
  for (auto &i : a) {
    cin >> i;
    sum += i;
  }

  int average = sum / N;

  if (sum % N != 0) {
    cout << "TIDAK SESUAI" << endl;
  } else {

    vector<int> notMatch;

    for (int i = 0; i < N; i++) {
        int v = a[i];
        if (v == average) continue;

        notMatch.push_back(i);
        if (notMatch.size() > 2) break;
    }

    if (notMatch.size() > 2) {
        cout << "TIDAK SESUAI" << endl;
    } else if (notMatch.empty()) {
        cout << "SESUAI" << endl;
    } else {
        if (a[notMatch[0]] < a[notMatch[1]])
            swap(notMatch[0], notMatch[1]);

        int delta1 = a[notMatch[0]] - average;
        int delta2 = average - a[notMatch[1]];

        if (delta1 != delta2) {
            cout << "TIDAK SESUAI" << endl;
        } else {
            cout << delta1 << " " << notMatch[0] + 1 << " " << notMatch[1] + 1 << endl; 
        }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}