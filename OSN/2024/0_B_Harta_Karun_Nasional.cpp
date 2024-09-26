#include <iostream>
#include <iomanip>

using namespace std;

void solution()
{
    int N = 256;
    cout << "TANYA 128" << endl;
    for (int i = 65; i <= 192; i++)
    {
        cout << i << " ";
    }
    cout << endl
         << flush;

    int h1;
    cin >> h1;

    if (h1 != 0)
    {
        // dikiri atau kanan
        cout << "TANYA 128" << endl;
        for (int i = 1; i <= 128; i++)
        {
            cout << i << " ";
        }
        cout << endl
             << flush;

        int h2;
        cin >> h2;

        int hasil;
        if (h2 == 0)
        {
            hasil = 65 - h1;
        }
        else
        {
            hasil = 192 + h1;
        }

        cout << "JAWAB " << hasil << endl;
    }
    else
    {
        cout << "TANYA 128" << endl;
        for (int i = 1; i <= 256; i++)
        {
            if (i >= 65 && i <= 192) continue;
            cout << i << " ";
        }
        cout << endl
             << flush;

        int h2;
        cin >> h2;

        cout << "TANYA 192" << endl;
        for (int i = 1; i <= 256; i++)
        {
            if (i >= 129 && i <= 192) continue;
            cout << i << " ";
        }
        cout << endl
             << flush;

        int h3;
        cin >> h3;

        int hasil;
        if (h3 == 0) {
            hasil = 64 + h2;
        } else {
            hasil = 193 - h2;
        }

        cout << "JAWAB " << hasil << endl;
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