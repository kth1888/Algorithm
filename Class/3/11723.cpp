#include <iostream>
#include <sstream>

using namespace std;

int n = 20;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int set = 0;

    int N;
    cin >> N;
    cin.ignore();

    string commandtype;
    while (N--)
    {
        cin >> commandtype;

        int commandvar;

        if (commandtype == "add")
        {
            cin >> commandvar;
            commandvar--;
            set = (set | (1 << commandvar));
        }
        else if (commandtype == "remove")
        {
            cin >> commandvar;
            commandvar--;
            set = (set & ~(1 << commandvar));
        }
        else if (commandtype == "check")
        {
            cin >> commandvar;
            commandvar--;
            int check = (set & (1 << commandvar));
            cout << (check ? 1 : 0) << '\n';
        }
        else if (commandtype == "toggle")
        {
            cin >> commandvar;
            commandvar--;
            set = (set ^ (1 << commandvar));
        }
        else if (commandtype == "all")
        {
            set = (1 << n) - 1;
        }
        else if (commandtype == "empty")
        {
            set = 0;
        }
    }
}

// https://gyyeom.tistory.com/62