#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <limits>

using namespace std;

void solution()
{
    int N;
    cin >> N;

    std::vector<int> arr(N + 1);

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    std::vector<int> minValue(N+1, std::numeric_limits<int>::max());
    minValue[0] = std::numeric_limits<int>::lowest();

    for (int i = 1; i <= N; i++) {
        int l = upper_bound(minValue.begin(), minValue.end(), arr[i]) - minValue.begin();
        if (minValue[l - 1] < arr[i] && arr[i] < minValue[l]) {
            minValue[l] = arr[i];
        }
    }

    int l = 1;
    for (int i = 2; i <= N; i++) {
        if (minValue[i] < std::numeric_limits<int>::max())
            l = i;
    }  

    std::cout << l << std::endl;
}

#ifndef LOCAL
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}
#else
#define TEST_NO_DIFF
#include "test.h"

TEST_CASE("first")
{
    test::check_solution(R"(8
7 3 5 3 6 2 9 8
)",
                         R"(4)");
}

#endif
