#include <iostream>

using namespace std;

int main()
{
    string input;

    int sum = 0;

    int leng = 0;

    cin >> leng;
    cin >> input;

    for (int i = 0; i < leng; i++)
    {
        int num = int(input[i]);
        sum += num - 48;
    }
    cout << sum << '\n';
}