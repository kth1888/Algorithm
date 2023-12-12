#include <iostream>

using namespace std;

int main()
{

    int N;
    cin >> N;

    int *A = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int v;
    cin >> v;
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        if (A[i] == v)
        {
            count++;
        }
    }
    cout << count << '\n';

    delete[] A;

    return 0;
}
