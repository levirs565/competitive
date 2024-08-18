#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

void solution()
{
    int N;
    cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);

    long long ASum = 0;
    int maxDelta = 0;
    int pairA = 0;
    int pairB = 0; 


    for (int i = 0; i < N; i++) {
        cin >> A[i];
        cin >> B[i];

        ASum += A[i];

        int delta = B[i] - A[i];
        if (delta > maxDelta || (delta == maxDelta && B[i] > pairB)) {
            maxDelta = delta;
            pairA = A[i];
            pairB = B[i];
        }
    }

    cout << (ASum - pairA + pairB) << endl;
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
    test::check_solution(R"(10
690830957 868532399
741145463 930111470
612846445 948344128
540375785 925723427
723092548 925021315
928915367 973970164
563314352 832796216
562681294 868338948
923012648 954764623
691107436 891127278
)",
                         R"(7362669937)");
}

#endif
