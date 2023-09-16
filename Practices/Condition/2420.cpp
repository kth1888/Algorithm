#include <iostream>

using namespace std;

int main()
{
    int64_t N, M;

    cin >> N >> M;

    if (N > M)
    {
        cout << N - M << endl;
    }
    else
    {
        cout << M - N << endl;
    }

    return 0;
}