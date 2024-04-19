#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    if (N == 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    double cutter = floor(((double)N / 100) * 15 + 0.5);
    // cout << cutter << '\n';

    int *num = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    sort(num, num + N);

    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        if (i < cutter)
        {
            num[i] = 0;
        }
        else if (N - cutter <= i)
        {
            num[i] = 0;
        }
        // cout << num[i] << '\n';
        sum += num[i];
    }
    int n = N - (cutter * 2);
    double result = floor((double)sum / n + 0.5);
    int resint = (int)result;

    cout << resint << '\n';
}