#include <iostream>
#include <iomanip>

using namespace std;

using i64 = int64_t;

i64 mod = 1'000'000;

struct Num
{
    i64 value;
    bool exceed;

    Num(i64 v, bool e)
    {
        value = v;
        exceed = e;
        if (v >= mod)
        {
            value %= mod;
            exceed = true;
        }
    }

    Num(i64 v) : Num(v, false) {}

    Num operator*(const Num &other)
    {
        return Num(value * other.value, exceed || other.exceed);
    }
};

Num binpow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 1)
    {
        return Num(a) * binpow(a, b - 1);
    }
    Num ret = binpow(a, b / 2);
    return ret * ret;
}

int main()
{
    int a, b;
    cin >> a >> b;
    Num result = binpow(a, b);
    if (result.exceed) {
        cout << setfill('0') << setw(6) << right;
    }
    cout << result.value << endl;
    return 0;
}