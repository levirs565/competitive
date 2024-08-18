#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

void solution() {
  int n;
  cin >> n;

  std::vector<std::pair<int, int>> rectangle(n);
  // area that can formed by all previous rectangle
  std::vector<int64_t> areaSum{0};
  std::map<int64_t, int> indexMap;

  indexMap[0] = 0;
  for (auto &[h, w] : rectangle) {
    cin >> h >> w;
    areaSum.push_back(areaSum[areaSum.size() - 1] + 1ll * h * w);
    indexMap[areaSum[areaSum.size() - 1]] = areaSum.size() - 1;
  }

  int64_t result = 0;

  set<int> verticalStackIndex{0}, horizontalStackIndex{0};
  for (int i = 1; i < n; i++) {
    set<int> startIndex;

    int prevHorizontalStack = -1, prevVerticalStack = -1;

    {
      // check previous rectangle that can stacked vertically
      // this means that current width is equal previous width
      // rect 1 height + rect 2 height = current height
      // either of rect 1 or rect 2 is previous rectangle (index is i - 1)
      // let rect 2 = previous rect
      // rect 1 height + prev height = current height
      // rect 1 height = current height - prev height
      // let rect 1 height = delta rect height
      // areaSum[i] = sum of rectangle j area where 0 <= j < i
      // areaSum[0] = 0
      // areaSum[1] = r0w * r0h
      // areaSum[2] = r0w * r0h + r1w * r1h
      // areaSum[i] = r0w * r0h + r1w * r1h + ... + r(i - 1)w * r(i - 1)h
      // prevArea = areaSum[i] - rih * r(i - 1)w
      // prevArea = r0w * r0h + r1w * r1h + ... + r(i - 1)w * r(i - 1)h - rih * r(i - 1)w
      // prevArea = areaSum[i - 1] + r(i - 1)w * (r(i - 1)h - rih)
      // prevArea = areaSum[i - 1] - r(i - 1)w * (rih - r(i - 1)h)
      // prevArea = areaSum[i - 1] - r(i - 1)w * delta rect height
      // when r(i - 1)w * delta rect height = rjw * rjh + r(j + 1)w * r(j + 1)h + ... + r(j + n)w * r(j + n)h 
      

      /* 
      areaSum[0] = 0
      1 2
      1,1 -> 1,2

      areaSum[1] = 2
      1 3
      1,2 -> 1,3
      2,2 -> 1,3
      prevArea = 2 - 2 * 1 = 0
      prevArea = 2 - 3 * 1 = -1

      areaSum[2] = 5
      2 3
      1,3 -> 3,3
      1,3 -> 3,3
      3,3 -> 2,3
      prevArea = 5 - 3 = 2
      prevArea = 5 - 6 = -1

      areaSum[3] = 11
      3 1

      1,4 -> 3,4
      1,4 -> 3,4
      4,4 -> 3,1
      prevArea = 11 - 2 = 9
      prevArea = 11 - 9 = 2

      areaSum[4] = 15
      */
      int64_t prevArea = areaSum[i] - 1ll * rectangle[i].first * rectangle[i - 1].second;
      // acumulated area - current height * prev width
      if (indexMap.count(prevArea) > 0 &&
          verticalStackIndex.count(indexMap[prevArea]) > 0) {
        // if in vertical stack, it means that rectangle is formed by vertical stack
        // and must use prev width
        // this ensure width at indexMap[prevArea] has same width
        prevHorizontalStack = indexMap[prevArea];
      }
    }

    {
      // check previous rectangle that can formed with current width
      int64_t prevArea = areaSum[i] - 1ll* rectangle[i].second * rectangle[i - 1].first;
      // acumulated area - current width * prev height
      if (indexMap.count(prevArea) > 0 &&
          horizontalStackIndex.count(indexMap[prevArea]) > 0) {
        // if in horizontal stack, it mean rectangle is formed by horizontal stack
        // and must use prev height
        // this ensure height at indexMap[prevArea] has same height
        prevVerticalStack = indexMap[prevArea];
      }
    }

    if (rectangle[i].first != rectangle[i - 1].first) {
      // Horizontal stack end, left to right
      for (int j : horizontalStackIndex)
        startIndex.insert(j);
      horizontalStackIndex.clear();
    }
    if (rectangle[i].second != rectangle[i - 1].second) {
      // Vertical stack end, bottom to up
      for (int j : verticalStackIndex)
        startIndex.insert(j);
      verticalStackIndex.clear();
    }

    if (prevHorizontalStack != -1)
      horizontalStackIndex.insert(prevHorizontalStack);

    if (prevVerticalStack != -1)
      verticalStackIndex.insert(prevVerticalStack);

    for (int j : startIndex) {
      // Only add to result when not in any stack to prevent double counting
      if (verticalStackIndex.count(j) == 0 && horizontalStackIndex.count(j) == 0)
        result += i - j;
    }

    verticalStackIndex.insert(i);
    horizontalStackIndex.insert(i);
  }

  for (int i = 0; i < n; i++) {
    if (horizontalStackIndex.count(i) > 0 || verticalStackIndex.count(i) > 0)
      result += n - i;
  }

  std::cout << result << std::endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}