#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text;
    int i;

    cin >> text;
    cin >> i;

    cout << text[i - 1] << "\n";
}