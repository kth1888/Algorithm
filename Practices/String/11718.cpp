#include <iostream>

using namespace std;

int main()
{
    string input;

    int count = 0;
    while (count < 100)
    {
        getline(cin, input);
        if (cin.eof())
        {
            break;
        }
        else if (input.length() > 100)
        {
            break;
        }
        else
        {
            cout << input << "\n";
            count++;
        }
    }
    return 0;
}
