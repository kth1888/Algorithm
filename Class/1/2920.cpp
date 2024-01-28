#include <iostream>

using namespace std;

int isAsc(int num1, int length, int input[])
{
    // cout << num1 << '\n';

    if (num1 == length)
    {
        cout << "ascending" << '\n';
        return 1;
    }

    if (input[num1] + 1 == input[num1 + 1])
    {

        // cout << "asc called" << '\n';
        isAsc(num1 + 1, length, input);
    }
    else
    {
        cout << "mixed" << '\n';
        return 0;
    }
    return 0;
}

int isDesc(int num1, int length, int input[])
{
    // cout << num1 << '\n';

    if (num1 == length)
    {
        cout << "descending" << '\n';
        return 2;
    }

    if (input[num1] - 1 == input[num1 + 1])
    {

        // cout << "desc called" << '\n';
        isDesc(num1 + 1, length, input);
    }
    else
    {
        cout << "mixed" << '\n';
        return 0;
    }

    return 0;
}

int main()
{
    int input[8] = {
        0,
    };

    // for (int i = 1; i < 9; i++)
    // {
    //     cout << input[i] << '\n';
    // }

    for (int i = 0; i < 8; i++)
    {
        cin >> input[i];
    }

    int result;

    if (input[0] == 1)
    {
        result = isAsc(0, 7, input);
    }
    else if (input[0] == 8)
    {
        result = isDesc(0, 7, input);
    }
    else
    {
        cout << "mixed" << '\n';
    }
}
