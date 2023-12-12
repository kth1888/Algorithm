#include <iostream>
#include <string>

using namespace std;

int main()
{
    char begin;
    char end;

    int T;

    cin >> T;

    string *input = new string[T];
    for (int i = 0; i < T; i++)
    {
        cin >> input[i];
    }

    for (int i = 0; i < T; i++)
    {
        begin = input[i].front();
        end = input[i].back();
        cout << begin << end << '\n';
    }
}