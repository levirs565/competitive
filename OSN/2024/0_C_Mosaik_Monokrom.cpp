#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void solution()
{
    int N, M;
    cin >> N >> M;

    vector<string> A(N);

    for (auto &a : A)
        cin >> a;

    vector<char> baris;
    long long b = 0;

    for (auto a : A)
    {
        int jumC = 0, jumD = 0;
        for (auto c : a)
        {
            if (c == '.')
                jumC++;
            else
                jumD++;
        }

        if (jumC >= jumD)
        {
            baris.push_back('.');
            b += jumC;
        }
        else
        {
            baris.push_back('#');
            b += jumD;
        }
    }

    vector<char> kolom;
    long long k = 0;
    for (int i = 0; i < M; i++)
    {
        int jumC = 0, jumD = 0;
        for (auto a : A)
        {
            if (a[i] == '.')
                jumC++;
            else
                jumD++;
        }

        if (jumC >= jumD)
        {
            kolom.push_back('.');
            k += jumC;
        }
        else
        {
            kolom.push_back('#');
            k += jumD;
        }
    }

    cout << N + M << endl;

    if (b >= k)
    {
        for (int i = 0; i < N; i++)
        {
            cout << "BARIS " << i + 1 << " " << baris[i] << endl;
        }
        for (int i = 0; i < M; i++)
        {
            cout << "KOLOM " << i + 1 << " " << kolom[i] << endl;
        }
    }
    else
    {
        for (int i = 0; i < M; i++)
        {
            cout << "KOLOM " << i + 1 << " " << kolom[i] << endl;
        }
        for (int i = 0; i < N; i++)
        {
            cout << "BARIS " << i + 1 << " " << baris[i] << endl;
        }
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