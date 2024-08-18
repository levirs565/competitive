#include <iostream>
#include <vector>
#include <numeric>
#include <array>
#include <climits>

using namespace std;
using i64 = int64_t;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> grid(N, vector(M, 0));

    for (auto& r : grid) {
        for (auto& c : r) cin >> c;
    }

    pair<int, int> pos = {INT_MAX, INT_MAX}; // column, row
    std::array<pair<int, int>, 4> tetangga = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int menarik = 1;
            for (auto [di, dj] : tetangga) {
                int ni = i + di, nj = j + dj;

                if (ni < 0 || nj < 0 || ni >= N || nj >= M) continue;

                menarik *= grid[ni][nj];
            }
            if (menarik == K) {
                pos = min(pos, {j, i});
            } 
        }
    }

    if (pos == make_pair(INT_MAX, INT_MAX)) cout << "0 0" << endl;
    else cout << pos.second + 1 << " " << pos.first + 1 << endl;

    return 0;
}