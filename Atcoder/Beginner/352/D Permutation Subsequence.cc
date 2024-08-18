#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <limits>
#include <set>
#include <vector>

using namespace std;

template <class Predicate> struct SegmentTree {
  std::vector<int> array;
  int valuesCount;
  Predicate predicate;

  SegmentTree(std::vector<std::pair<int, int>> &values)
      : array(2 * int(pow(2, int(ceil(log2(values.size()))))) - 1) {
    valuesCount = values.size();
    fillST(values, 0, valuesCount - 1, 0);
  }

  int fillST(std::vector<std::pair<int, int>> &values, int ss, int se, int si) {
    if (ss == se) {
      array[si] = values[ss].second;
      return array[si];
    }

    int mid = getMid(ss, se);
    array[si] = predicate(fillST(values, ss, mid, si * 2 + 1),
                          fillST(values, mid + 1, se, si * 2 + 2));

    return array[si];
  }

  int getMid(int start, int end) { return (start + end) / 2; }

  int querySQUtil(int ss, int se, int qs, int qe, int index) {
    if (qs <= ss && qe >= se)
      return array[index];

    if (se < qs || ss > qe)
      return predicate.defaultValue;

    int mid = getMid(ss, se);
    return predicate(querySQUtil(ss, mid, qs, qe, 2 * index + 1),
                     querySQUtil(mid + 1, se, qs, qe, 2 * index + 2));
  }

  int query(int qs, int qe) {
    return querySQUtil(0, valuesCount - 1, qs, qe, 0);
  }
};

struct MinPredicate {
  int operator()(int a, int b) { return min(a, b); }

  const int defaultValue = std::numeric_limits<int>::max();
};

struct MaxPredicate {
  int operator()(int a, int b) { return max(a, b); }

  const int defaultValue = std::numeric_limits<int>::min();
};

void solution() {
  int N, K;
  cin >> N >> K;

  std::vector<std::pair<int, int>> values(N);

  for (int i = 0; i < N; i++) {
    values[i].second = i;
    cin >> values[i].first;
  }

  if (K == 1) {
    std::cout << 0 << std::endl;
    return;
  }

  std::sort(values.begin(), values.end());

  SegmentTree<MinPredicate> minST(values);
  SegmentTree<MaxPredicate> maxST(values);

  int firstI = 0;
  int minD = std::numeric_limits<int>::max();
  for (int i = 1; i <= N; i++) {
    if (values[i].first == values[i - 1].first + 1) {
      if (i - firstI + 1 >= K) {
        int D = maxST.query(firstI, i) - minST.query(firstI, i);
        if (D < minD) {
          minD = D;
        }

        firstI++;
      }
    } else {
      firstI = i;
    }
  }

  std::cout << minD << std::endl;
}

#ifndef LOCAL
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solution();
  return 0;
}
#else
#define TEST_NO_DIFF
#include "test.h"

TEST_CASE("first") {
  test::check_solution(R"(4 1
2 3 1 4
)",
                       R"(0)");
}

TEST_CASE("second") {
  test::check_solution(R"(4 2
2 3 1 4
)",
                       R"(1)");
}

TEST_CASE("third") {
  test::check_solution(R"(10 5
10 1 6 8 7 2 5 9 3 4
)",
                       R"(5)");
}

#endif
