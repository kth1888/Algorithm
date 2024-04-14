#include <iostream>
#include <stack>

using namespace std;

int main()
{

    while (true)
    {
        stack<int> bracket;
        string input;
        bool isvalid = true;
        getline(cin, input);
        // cout << input << '\n';

        if (input[0] == '.')
        {
            // cout << "empty" << '\n';
            return 0;
        }

        int l = input.length();

        for (int i = 0; i < l; i++)
        {
            // cout << input[i] << ' ';
            if (input[i] == '(')
            {
                bracket.push(1);
                isvalid = true;
            }
            else if (input[i] == '[')
            {
                bracket.push(2);
                isvalid = true;
            }
            else if (input[i] == ']')
            {
                if (!bracket.empty() && bracket.top() == 2)
                {
                    bracket.pop();
                }
                else
                {
                    isvalid = false;
                    break;
                }
            }
            else if (input[i] == ')')
            {
                if (!bracket.empty() && bracket.top() == 1)
                {
                    bracket.pop();
                }
                else
                {
                    isvalid = false;
                    break;
                }
            }
        }
        if (bracket.empty())
        {
            if (isvalid)
            {
                cout << "yes" << '\n';
            }
            else
            {
                cout << "no" << '\n';
            }
        }
        else
        {
            cout << "no" << '\n';
        }
    }
}