#include <iostream>

using namespace std;

int main()
{
    int num;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int blank = num - i;
        for (int j = 1; j < blank; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < i + 1; k++)
        {
            cout << "*";
        }
        cout << '\n';
    }
}