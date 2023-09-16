#include <iostream>

using namespace std;

int main()
{

    int count;
    cin >> count;

    int *A = new int[count];
    int *B = new int[count];

    for (int i = 0; i < count; i++)
    {
        cin >> A[i] >> B[i];
    }

    for (int i = 0; i < count; i++)
    {
        cout << A[i] + B[i] << "\n";
    }

    delete[] A;
    delete[] B;

    return 0;
}
