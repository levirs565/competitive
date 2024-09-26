#include <iostream>
#include <iomanip>

using namespace std;

void solution()
{
    int N;
    cin >> N;

    int termudaKemarin = -1;
    int tertuaKemarin = -1;
    long long sum = 0;

    for (int i = 1; i <= N; i++)
    {
        int baru;
        cin >> baru;

        if (sum > 0)
        {
            sum += i - 1;
        }

        int termuda = baru;
        if (termudaKemarin > 0)
        {
            termudaKemarin++;
            termuda = min(termuda, termudaKemarin);
        }

        cout << termuda << " ";

        if (termudaKemarin == -1)
            termudaKemarin = termuda;
        else
            termudaKemarin = min(termudaKemarin, termuda);

        int tertua = baru;
        if (tertuaKemarin > 0) {
            tertuaKemarin++;
            tertua = max(tertua, tertuaKemarin);
        }

        cout << tertua << " ";

        tertuaKemarin = max(tertua, tertuaKemarin);

        cout << fixed << setprecision(4) << double(sum + baru) / i << endl;

        sum += baru;
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