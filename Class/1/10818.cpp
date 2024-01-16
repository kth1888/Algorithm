#include <iostream>

using namespace std;

int main()
{
    int amount;
    int temp = 0;
    int maxnum = 0;
    int minnum = 0;

    cin >> amount;

    int *numbers = new int[amount];

    for (int i = 0; i < amount; i++)
    {
        cin >> numbers[i];
    }

    for (int i = 0; i < amount; i++)
    {
        temp = numbers[i];
        if (maxnum == 0)
        {
            maxnum = temp;
        }
        if (maxnum < temp)
        {
            maxnum = temp;
        }
    }

    for (int i = 0; i < amount; i++)
    {
        temp = numbers[i];
        if (minnum == 0)
        {
            minnum = temp;
        }
        if (minnum > temp)
        {
            minnum = temp;
        }
    }

    cout << minnum << ' ' << maxnum << '\n';
}