#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

void solution() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int na = a, nb = b, nc = c;

    int leafCount = 0;
    int height = 0;

    if (na > 0) {
      na--;
      leafCount = 2;
    } else if (nb > 0) {
      nb--;
      leafCount = 1;
    } else if (nc > 0) {
      nc--;
      leafCount = 0;
    }

    int nextLeafCount = 0;
    int filledLeafCount = 0;

    while (na > 0 && leafCount > 0) {
      int est = min(leafCount - filledLeafCount, na);
      na -= est;
      filledLeafCount += est;
      nextLeafCount += 2 * est;
      if (filledLeafCount >= leafCount) {
        height++;
        leafCount = nextLeafCount;
        nextLeafCount = 0;
        filledLeafCount = 0;
      }
    }

    while (nb > 0 && leafCount > 0) {
      int est = min(leafCount - filledLeafCount, nb);
      nb -= est;
      filledLeafCount += est;
      nextLeafCount += est;
      if (filledLeafCount >= leafCount) {
        height++;
        leafCount = nextLeafCount;
        nextLeafCount = 0;
        filledLeafCount = 0;
      }
    }

    while (nc > 0 && leafCount > 0) {
      int est = min(leafCount - filledLeafCount, nc);
      nc -= est;
      filledLeafCount += est;
      if (filledLeafCount >= leafCount) {
        height++;
        leafCount = nextLeafCount;
        nextLeafCount = 0;
        filledLeafCount = 0;
      }
    }

    if (na > 0 || nb > 0 || nc > 0 || filledLeafCount < leafCount) {
      cout << -1 << endl;
    } else {
      cout << height << endl;
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