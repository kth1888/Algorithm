#include <iostream>

using namespace std;

int main()
{
    int K, N;
    cin >> K >> N;

    long long *cables = new long long[K];

    long long maximumsize = 0;
    long long maxlength = 0;
    for (int i = 0; i < K; i++)
    {
        cin >> cables[i];
        if (cables[i] > maximumsize)
        {
            maximumsize = cables[i];
        }
    }

    for (long long j = 1; j < maximumsize; j++)
    {

        long long result = 0;
        for (int i = 0; i < K; i++)
        {
            result += (cables[i] / j);
        }

        if (result == N)
        {
            maxlength = j;
        }
    }

    cout << maxlength << '\n';
}