#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution()
{
    int N;
    cin >> N;

    vector<pair<int, int>> A(N);

    for (int i = 0; i < N; i++)
    {
        A[i].second = i;
        cin >> A[i].first;
    }

    auto B = A;
    // auto C = A;
    sort(A.begin(), A.end());
    vector<pair<int, int>> result;
    vector<int> movedIndex(N, -1);

    for (int i = 0; i < N; i++)
    {
        if (A[i] == B[A[i].second])
        {
            if (i != A[i].second)
                result.push_back({i, A[i].second});
            swap(B[i], B[A[i].second]);
            movedIndex[B[A[i].second].second] = A[i].second;
        }
        else
        {
            if (i != movedIndex[A[i].second])
                result.push_back({i, movedIndex[A[i].second]});
            swap(B[i], B[movedIndex[A[i].second]]);
            movedIndex[B[movedIndex[A[i].second]].second] = movedIndex[A[i].second];
        }
    }

    cout << 3 * result.size() << endl;
    for (auto r : result)
    {
        // C[r.first].first = C[r.first].first ^ C[r.second].first;
        cout << r.first + 1 << " " << r.second + 1 << endl;
        // C[r.second].first = C[r.second].first ^ C[r.first].first;
        cout << r.second + 1 << " " << r.first + 1 << endl;
        // C[r.first].first = C[r.first].first ^ C[r.second].first;
        cout << r.first + 1 << " " << r.second + 1 << endl;
    }

    // for (auto c : C)
    // {
    //     cout << c.first << " ";
    // }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}