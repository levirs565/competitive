#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

using i64 = int64_t;

void solution()
{
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> A(M);
    vector<vector<int>> times(N);

    for (auto &[T, P] : A)
    {
        cin >> T >> P;
        P--;
        times[P].push_back(T);
    }

    map<pair<int, int>, int> memo;
    vector<int> count(N, 0);

    for (int P = 0; P < N; P++)
    {
        if (times[P].size() / 2 < 1000)
            continue;

        bool PIn = false;
        int PLast = 0, PSum = 0;
        // when P2 in open state, count will equal last PSum + (P2 Open Time - P Open Time)
        // when P2 in close state, count will equal the count P and P2 inside together
        // Formula to get count:
        // PSum when close + (P2 Close Time - P Open Time) - PSum when open - (P2 Open Time - P Open Time before P2 Open Time)
        //                    ^ this not added on PSum
        // Formula can reduced to:
        // count[current] = PSum + (T - PLast) - count[before] 
        //                         ^ only when P inside
        // When P not inside:
        // PSum between P2 open and close is same

        for (auto [T, P2] : A) {
            if (P2 == P) {
                PSum += PIn * (T - PLast);
                PIn = !PIn;
                PLast = T;
            }
            
            count[P2] = PSum + PIn * (T - PLast) - count[P2];
        }

        for (int P2 = 0; P2 < N; P2++)
        {
            memo[minmax({P, P2})] = count[P2];
        }

        count.assign(N, 0);
    }

    int Q;
    cin >> Q;

    while (Q--)
    {
        int A, B;
        cin >> A >> B;
        A--;
        B--;

        if (A > B)
            swap(A, B);

        if (memo.count({A, B}) > 0)
        {
            cout << memo[{A, B}] << "\n";
            continue;
        }

        bool aIn = false, bIn = false;
        int lastT = 0;
        int ans = 0;

        int aIndex = 0, bIndex = 0;

        while (aIndex < times[A].size() && bIndex < times[B].size())
        {
            int T, P;
            if (times[A][aIndex] <= times[B][bIndex])
            {
                T = times[A][aIndex];
                P = A;
                aIndex++;
            }
            else
            {
                T = times[B][bIndex];
                P = B;
                bIndex++;
            }

            if (aIn && bIn)
            {
                ans += T - lastT;
            }
            if (P == A)
            {
                aIn = !aIn;
            }
            else
            {
                bIn = !bIn;
            }
            lastT = T;
        }

        memo[{A, B}] = ans;

        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution();
    return 0;
}