#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, H;
    cin >> N >> H;

    int X[N + 1];
    int Y[N + 1] = {0};

    for (int i = 1; i <= N; i++) {
        cin >> X[i];
        Y[i] = X[i];
    }

    std::sort(Y + 1, Y + N + 1);

    double prob[N + 1];

    vector<pair<int, vector<bool>>> curr(1, make_pair(1, vector<bool>(N + 1, false))), next;

    for (int i = 1; i <= N; i++) {
        int x = X[i];
        int idx = upper_bound(Y + 1, Y + N + 1, x) - Y - 1;

        prob[i] = 0;
        for (auto state : curr) {
            if (state.second[idx]) {
                next.push_back(state);
                continue;
            }

            state.second[idx] = true;
            vector<bool> leftDir = state.second;
            int leftMost = x - H;
            for (int j = idx - 1; j > 0; j--) {
                if (Y[j] >= leftMost) {
                    leftDir[j] = true;
                    leftMost = Y[j] - H;
                    continue;                    
                }

                break;
            } 

            vector<bool> rightDir = state.second;
            int rightMost = x + H;
            for (int j = idx + 1; j <= N; j++) {
                if (Y[j] <= rightMost) {
                    rightDir[j] = true;
                    rightMost = Y[j] + H;
                    continue;
                }

                break;
            }

            if (all_of(leftDir.begin() + 1, leftDir.end(), [] (auto a) {
                return a;
            }))
                prob[i] += 1.0 / state.first / 2;
            else
                next.push_back(make_pair(state.first * 2, move(leftDir)));

            if (all_of(rightDir.begin() + 1, rightDir.end(), [] (auto a) {
                return a;
            }))
                prob[i] += 1.0 / state.first / 2;
            else
                next.push_back(make_pair(state.first * 2, move(rightDir)));
        }

        std::swap(curr, next);
        next.clear();
    }

    double mult = pow(2, N);

    for (int i = 1; i <= N; i++) {
        cout << (long long)fmod(prob[i] * mult, 998244353) << " ";
    }

    cout << endl;

    return 0;
}