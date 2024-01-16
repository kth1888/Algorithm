#include <iostream>
#define LENGTH 9

using namespace std;

int main()
{
    int numbers[LENGTH];
    int result = 0;
    int temp = 0;
    int where = 0;

    for (int i = 0; i < LENGTH; i++)
    {
        cin >> numbers[i];
    }

    for (int i = 0; i < LENGTH; i++)
    {
        if (temp == 0)
        {
            temp = numbers[i];
            where = i + 1;
        }

        if (temp < numbers[i])
        {
            result = numbers[i];
            temp = result;
            where = i + 1;
        }
        else
        {
            result = temp;
        }
    }

    cout << result << '\n';

    cout << where << '\n';
}