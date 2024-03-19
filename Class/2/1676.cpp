#include <iostream>
#include <algorithm>

using namespace std;

int howmanytwos(int N)
{
    int counter = 0;
    if (N % 2 != 0)
    {
        return 0;
    }

    while (N % 2 == 0)
    {
        counter++;
        N = N / 2;
    }

    return counter;
}

int howmanyfives(int N)
{
    int counter = 0;
    if (N % 5 != 0)
    {
        return 0;
    }

    while (N % 5 == 0)
    {
        counter++;
        N = N / 5;
    }

    return counter;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int twos = 0, fives = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        // cout << howmanytwos(i) << '\n';
        // cout << howmanyfives(i) << '\n';
        twos += howmanytwos(i);
        fives += howmanyfives(i);
    }

    // cout << twos << '\n';
    // cout << fives << '\n';

    int tens = 0;
    if (twos > 0 && fives > 0)
    {
        tens = min(twos, fives);
    }

    cout << tens << '\n';
}

// https://www.acmicpc.net/board/view/121491