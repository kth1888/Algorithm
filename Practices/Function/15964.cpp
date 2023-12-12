// not finished

#include <iostream>

using namespace std;

int program(int A, int B)
{
    if (A <= 1000 && B <= 1000)
    {
        return (A + B) * (A - B);
    }
    else
    {
        return 0;
    }
    return 0;
}

int main()
{
    int A, B;

    cin >> A >> B;

    cout << program(A, B) << '\n';

    return 0;
}