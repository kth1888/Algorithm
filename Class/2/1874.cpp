#include <iostream>
#include <stack>

using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;
    cin >> n;

    stack<int> inputstack;
    stack<int> tempstack;

    char *resultstr = new char[2 * n];

    int *resultarray = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> resultarray[i];
        inputstack.push(n - i);
        tempstack.push(0);
    }

    int comparedcase = 0;
    int storage = 0;

    for (int i = 0; i < n; i++)
    {
        comparedcase = resultarray[i];
        while (comparedcase != tempstack.top())
        {
            if (inputstack.empty())
            {
                cout << "NO" << '\n';
                return 0;
            }
            tempstack.push(inputstack.top());
            inputstack.pop();
            resultstr[storage] = '+';
            storage++;
            // cout << '+' << '\n';
        }
        if (comparedcase == tempstack.top())
        {
            tempstack.pop();
            resultstr[storage] = '-';
            storage++;
            // cout << '-' << '\n';
        }
    }

    for (int i = 0; i < storage; i++)
    {
        // cout << "case : " << i << '\n';
        cout << resultstr[i] << '\n';
    }

    return 0;
}

/*
1 2 3 4 5 6 7 8
to
4 3 6 8 7 5 2 1
---------------
4 push 1 2 3 4
2 pop 4 3 / 1 2
2 push 1 2 5 6
1 pop 4 3 6 / 1 2 5
2 push / 1 2 5 7 8
5 pop 4 3 6 8 7 5 2 1
*/

/*
1 2 3 4 5
to
1 2 5 3 4
------------------
1 push 1
1 pop / 1
1 push 2 / 1
1 pop / 1 2
3 push 3 4 5
1 pop 3 4 / 1 2 5

*/