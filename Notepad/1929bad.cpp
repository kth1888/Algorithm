#include <iostream>
#include <cmath>

using namespace std;

void eratos(int num, int size, int arr[])
{
    // cout << "case : " << num << '\n';
    int original = 0;
    for (int i = 0; i < size; i++)
    {
        // 1은 소수가 아님..
        if (arr[i] == 1)
        {
            arr[i] = 0;
        }

        // cout << arr[i] % num << '\n';
        if (arr[i] != 0 && arr[i] % num == 0)
        {
            if (original == 0 && arr[i] / 2 == 1)
            {
                original = 1;
                // cout << "original saved " << '\n';
            }
            else
            {
                arr[i] = 0;
            }
        }
    }
}

int main()
{
    int M, N;
    cin >> M >> N;

    int amount = N - M + 1;

    int *numbers = new int[amount];

    for (int i = M; i <= N; i++)
    {
        numbers[i - M] = i;
        // cout << numbers[i - M] << '\n';
    }

    int maxval;
    if (N < 4)
    {
        maxval = 2;
    }
    else
    {
        maxval = sqrt(N);
    }

    // cout << maxval << '\n';

    for (int j = 2; j <= maxval; j++)
    {
        eratos(j, amount, numbers);
    }

    for (int j = 0; j < amount; j++)
    {
        // cout << "number : " << j << '\n';
        if (numbers[j] != 0)
        {
            cout << numbers[j] << '\n';
        }
    }
    return 0;
}