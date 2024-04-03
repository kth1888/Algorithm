#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        bool result = true;
        string input;
        cin >> input;

        stack<bool> open;

        open.push(true);

        int inlen = input.length();
        for (int j = 0; j < inlen; j++)
        {
            if (input[j] == '(')
            {
                open.push(true);
            }
            else
            {
                open.pop();
            }

            if (open.empty())
            {
                // cout << "NO" << '\n';
                result = false;
                break;
            }
        }

        open.pop();
        if (open.empty())
        {
            // cout << "YES" << '\n';
            result = true;
        }
        else
        {
            // cout << "NO" << '\n';
            result = false;
        }

        if (result)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}

/*
(()())((()))
( = (( ( ((( = 6
) = ) )) ))) = 6
*/