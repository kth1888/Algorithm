#include <iostream>

using namespace std;

int main()
{
    string input;

    do
    {
        cin >> input;

        if (input == "0")
        {
            break;
        }

        string reversed;

        int inputlen = input.length();
        // cout << inputlen << '\n';

        for (int i = 0; i < inputlen; i++)
        {
            // cout << input[input.length() - 1 - i] << '\n';
            reversed += input[inputlen - 1 - i];
        }
        // cout << reversed << '\n';

        if (input.compare(reversed) == 0)
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }
    } while (1);
}
