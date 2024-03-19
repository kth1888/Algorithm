// blank
#include <iostream>

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

int main()
{
    int N;
    int twos = 0, fives = 0;
    cin >> N;
    twos = howmanytwos(N);
    cout << twos << '\n';
}