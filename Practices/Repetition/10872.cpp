#include <iostream>

using namespace std;

int main()
{
    int N;

    int factorial = 1;

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        factorial *= i;
    }

    cout << factorial << "\n";

    return 0;
}