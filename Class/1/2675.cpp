#include <iostream>

using namespace std;

int main()
{
    int myCase = 0;

    cin >> myCase;

    for (int i = 0; i < myCase; i++)
    {
        int amount;
        string input;

        cin >> amount;
        cin >> input;

        int length = input.length();

        for (int j = 0; j < length; j++)
        {
            for (int k = 0; k < amount; k++)
            {
                cout << input[j];
            }
        }
        cout << '\n';
    }
}