#include <iostream>
#include <cmath>

using namespace std;

void travel(int N, int r, int c, int total)
{
    int len = int(pow(2, N));
    // cout << len / 2 << '\n';
    int half = len / 2;
    int amount = len * len / 4;

    // cout << amount << '\n';
    int result = total;

    if (amount >= 1)
    {
        if (r < (half))
        {
            // cout << "up";
            if (c < (half))
            {
                // 1
                // cout << " left" << '\n';
                result += amount * 0;
                // cout << "received " << result << '\n';
                travel(N - 1, r, c, result);
            }
            else
            {
                // 2
                // cout << " right" << '\n';
                result += amount * 1;
                // cout << "received " << result << '\n';
                travel(N - 1, r, c - half, result);
            }
        }
        else
        {
            // cout << "down";
            if (c < (half))
            {
                // 3
                // cout << " left" << '\n';
                result += amount * 2;
                // cout << "received " << result << '\n';
                travel(N - 1, r - half, c, result);
            }
            else
            {
                // 4
                // cout << " right" << '\n';
                result += amount * 3;
                // cout << "received " << result << '\n';
                travel(N - 1, r - half, c - half, result);
            }
        }
    }
    else
    {
        cout << result << '\n';
    }
}

int main()
{
    int N, r, c;
    cin >> N >> r >> c;

    travel(N, r, c, 0);
}