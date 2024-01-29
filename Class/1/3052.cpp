#include <iostream>

using namespace std;

int main()
{
    int input[10];
    int modulo[10];
    int counter[43] = {
        0,
    };
    int result = 0;

    for (int i = 0; i < 10; i++)
    {
        cin >> input[i];

        modulo[i] = input[i] % 42;

        // cout << input[i] << ' ' << modulo[i] << '\n';

        counter[modulo[i]]++;
    }

    for (int j = 0; j < 43; j++)
    {
        if (counter[j] != 0)
        {
            result++;
        }
    }

    cout << result << '\n';
}