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

template <class Predicate> struct SegmentTree {
  std::vector<std::pair<int, int>> array;
  int valuesCount;
  Predicate predicate;

  SegmentTree(std::vector<int> &values)
      : array(2 * int(pow(2, int(ceil(log2(values.size()))))) - 1) {
    valuesCount = values.size();
    fillST(values, 0, valuesCount - 1, 0);
  }

  std::pair<int, int> fillST(std::vector<int> &values, int ss, int se, int si) {
    if (ss == se) {
      array[si] = {values[ss], ss};
      return array[si];
    }

    int mid = getMid(ss, se);
    array[si] = predicate(fillST(values, ss, mid, si * 2 + 1),
                          fillST(values, mid + 1, se, si * 2 + 2));

    return array[si];
  }

  int getMid(int start, int end) { return (start + end) / 2; }

  std::pair<int, int> querySQUtil(int ss, int se, int qs, int qe, int index) {
    if (qs <= ss && qe >= se)
      return array[index];

    if (se < qs || ss > qe)
      return predicate.defaultValue;

    int mid = getMid(ss, se);
    return predicate(querySQUtil(ss, mid, qs, qe, 2 * index + 1),
                     querySQUtil(mid + 1, se, qs, qe, 2 * index + 2));
  }

  std::pair<int, int> query(int qs, int qe) {
    return querySQUtil(0, valuesCount - 1, qs, qe, 0);
  }
};

struct MinPredicate {
  std::pair<int, int> operator()(std::pair<int, int> a, std::pair<int, int> b) {
    return min(a, b);
  }

  const std::pair<int, int> defaultValue = {std::numeric_limits<int>::max(),
                                            std::numeric_limits<int>::max()};
};

struct MaxPredicate {
  std::pair<int, int> operator()(std::pair<int, int> a, std::pair<int, int> b) {
    if (a.first == b.first)
      return {a.first, min(a.second, b.second)};
    return max(a, b);
  }

  const std::pair<int, int> defaultValue = {std::numeric_limits<int>::min(),
                                            std::numeric_limits<int>::min()};
};

void solution() {
  int N, Q;
  cin >> N >> Q;
  std::vector<int> array(N);
  for (int &i : array)
    cin >> i;

  SegmentTree<MinPredicate> minST(array);
  SegmentTree<MaxPredicate> maxST(array);

  for (int q = 0; q < Q; q++) {
    int l, r;
    cin >> l >> r;

    if (r - l == 2) {
      cout << int64_t(array[l - 1]) + int64_t(array[l]) + int64_t(array[l + 1])
           << endl;
      continue;
    }

    auto minItem = minST.query(l - 1, r - 1);
    int64_t result = std::numeric_limits<int64_t>::max();
    while (true) {
      int64_t maxValue = 0;
      if (minItem.second == l - 1) {
        // cout << "A ";
        auto maxItem = maxST.query(l, r - 1);
        int maxSecond = std::numeric_limits<int>::max();
        for (int x = maxItem.second + 1; x <= r - 1; x++)
          maxSecond = min(maxST.query(x, r - 1).first, maxSecond);
        for (int x = maxItem.second - 1; x >= l; x--)
          maxSecond = min(maxST.query(l, x).first, maxSecond);
        maxValue = int64_t(minItem.first) + int64_t(maxItem.first) +
                   int64_t(maxSecond);
      } else if (minItem.second == r - 1) {
        // cout << "B ";
        auto maxItem = maxST.query(l - 1, r - 2);
        int maxSecond = std::numeric_limits<int>::max();
        for (int x = maxItem.second + 1; x <= r - 2; x++)
          maxSecond = min(maxST.query(x, r - 2).first, maxSecond);
        for (int x = maxItem.second - 1; x >= l - 1; x--)
          maxSecond = min(maxST.query(l - 1, x).first, maxSecond);
        // cout << maxItem.first << " " << maxSecond << " ";
        maxValue = int64_t(minItem.first) + int64_t(maxItem.first) +
                   int64_t(maxSecond);
      } else {
        // cout << "C ";
        maxValue = int64_t(maxST.query(l - 1, minItem.second - 1).first) +
                   int64_t(minItem.first) +
                   int64_t(maxST.query(minItem.second + 1, r - 1).first);
      }
      result = min(maxValue, result);
      if (minItem.second + 1 >= r) {
        break;
      }
      auto newMinItem = minST.query(minItem.second + 1, xr - 1);
      if (newMinItem.first != minItem.first)
        break;
      minItem = newMinItem;
    }

    cout << result << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}