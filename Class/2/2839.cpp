#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int x = N / 5;
    int y = (N - 5 * x) / 3;
    int z = (N - 5 * x) % 3;

    int limity = N / 3;

    // cout << x << y << z << limity << '\n';

    while (true)
    {
        if ((x * 5 + y * 3) != N)
        {
            if (y == limity)
            {
                cout << -1 << '\n';
                return 0;
            }
            else
            {
                x--;
                y = (N - 5 * x) / 3;
                z = (N - 5 * x) % 3;
            }
        }
        else
        {
            cout << x + y << '\n';
            return 0;
        }
    }

    return 0;
}