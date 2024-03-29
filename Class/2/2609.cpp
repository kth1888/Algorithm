#include <iostream>

using namespace std;

int main()
{
    int N, M = 0;

    cin >> N >> M;

    int maxnum = 0;
    if (N > M)
    {
        maxnum = N;
    }
    else
    {
        maxnum = M;
    }

    int gcd = 0;
    int lcm = 0;

    for (int i = 1; i <= maxnum; i++)
    {
        if (N % i == 0 && M % i == 0)
        {
            gcd = i;
        }
    }

    lcm = (M * N) / gcd;

    cout << gcd << '\n';
    cout << lcm << '\n';
}