#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution() {
    int N;
    cin >> N;

    vector<string> A(N); 
    int maxL = 0;
    for (auto& a : A) {
        cin >> a;
        maxL = max(maxL, (int)a.size());
    }

    for (int i = 0; i < maxL; i++) {
        string str;
        for (auto& a : A) {
            str.push_back(i >= a.size() ? '*' : a[i]);
        }

        str.erase(str.begin(), str.begin() + str.find_first_not_of('*'));
        reverse(str.begin(), str.end());


        cout << str << endl;
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