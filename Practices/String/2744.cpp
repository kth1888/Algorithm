#include <iostream>
#include <string>

#define ASCII 32;

using namespace std;

int main()
{
    string text;

    cin >> text;

    for (char i : text)
    {
        if (int(i) < 123 && 96 < int(i))
        {
            int j = int(i) - ASCII;
            cout << char(j);
        }
        else if (int(i) < 91 && 64 < int(i))
        {
            int j = int(i) + ASCII;
            cout << char(j);
        }
        else
        {
            break;
        }
    }
    cout << "\n";

    return 0;
}