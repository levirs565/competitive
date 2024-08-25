#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

void solution()
{
    int N, M, X1;
    cin >> N >> M >> X1;

    vector<tuple<int, int, int, int>> trains(M);

    for (auto &[A, B, S, T] : trains)
    {
        cin >> A >> B >> S >> T;
        A--;
        B--;
    }

    vector<tuple<int, int, int>> events; // time, event, index
                                         // datang/sampai, 1
                                         // keluar/mulai, 2

    for (int i = -1; auto &[A, B, S, T] : trains)
    {
        i++;
        events.push_back({S, 2, i});
        events.push_back({T, 1, i});
    }

    sort(events.begin(), events.end());

    vector<int> A(N, 0);
    vector<int> D(M, 0);

    D[0] = X1;

    for (auto [time, event, index] : events)
    {
        if (event == 1)
        {
            A[get<1>(trains[index])] = max(A[get<1>(trains[index])], time + D[index]);
        }
        else
        {
            if (index > 0)
                D[index] = max(0, A[get<0>(trains[index])] - time);
        }
    }

    for (int i = 1; i < M; i++)
    {
        cout << D[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}