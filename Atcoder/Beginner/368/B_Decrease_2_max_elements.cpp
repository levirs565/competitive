#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution()
{
    int N;
    cin >> N;

    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    int count = 0;
    do
    {
        sort(A.begin(), A.end(), greater<int>());
        int newOp = 1;
        if (A.size() >= 3) {
            newOp = max(newOp, min(A[0] - A[2], A[1] - A[2]));
        }
        A[0] -= newOp;
        A[1] -= newOp;
        count += newOp;
        if (A[1] <= 0) {
            A.erase(A.begin() + 1);
        }
        if (A[0] <= 0) {
            A.erase(A.begin());
        }
    } while (A.size() > 1);
    cout << count << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}