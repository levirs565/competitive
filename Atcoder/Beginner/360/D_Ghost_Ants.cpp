#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <vector>

using namespace std;


void solution() {
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    
    std::vector<int64_t> XForward, XBackward;

    for (int i = 0; i < n; i++) {
        int64_t X;
        cin >> X;
        if (s[i] == '1') XForward.push_back(X);
        else XBackward.push_back(X);
    }

    std::sort(XBackward.begin(), XBackward.end());
    std::sort(XForward.begin(), XForward.end());

    double stopTime = t + 0.1;
    int64_t count = 0;

    for (size_t i = 0; i < XForward.size(); i++) {
        int64_t startX = XForward[i];
        int64_t endX = floor(2 * stopTime + startX);
        auto lowerBound = lower_bound(XBackward.begin(), XBackward.end(), startX);
        auto upperBound = upper_bound(XBackward.begin(), XBackward.end(), endX);

        if (lowerBound == XBackward.end()) continue;
        count += upperBound - lowerBound;
    }

    cout << count << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}