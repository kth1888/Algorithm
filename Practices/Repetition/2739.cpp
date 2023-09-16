#include <iostream>

using namespace std;

int main()
{
    int N;

    cin >> N;

    if ((1 <= N) && (N <= 9))
    {
        for (int i = 1; i < 10; i++)
        {
            cout << N << " * " << i << " = " << N * i << "\n";
        }
    }

    return 0;
}