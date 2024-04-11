#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, V;

    cin >> A >> B >> V;

    int C = V - A;

    int q = C / (A - B);

    if (C - q * (A - B) > 0)
    {

        cout << q + 2 << '\n';
    }
    else
    {
        cout << q + 1 << '\n';
    }
}