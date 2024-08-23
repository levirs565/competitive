#include <iostream>
#include <vector>

using namespace std;

void solution() {
    int N, T, A;
    cin >> N >> T >> A;

    int sisa = N - T - A;
    bool curr = T > A;
    bool next1 = T + sisa > A;
    bool next2 = T > A + sisa;

    if (curr == next1 && next1 == next2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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