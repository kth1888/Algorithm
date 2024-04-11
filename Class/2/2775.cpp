#include <iostream>

using namespace std;

int calc(int a, int b)
{
    if (b == 1)
    {
        return 1;
    }

    if (a == 0)
    {
        return b;
    }
    else
    {
        return calc(a, b - 1) + calc(a - 1, b);
    }
}

int main()
{
    int T;
    cin >> T;

    for (int j = 0; j < T; j++)
    {
        int k, n;
        cin >> k;
        cin >> n;
        int result = calc(k, n);
        cout << result << '\n';
    }

    return 0;
}