#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int K;
    stack<int> money;
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int input;
        cin >> input;
        if (input != 0)
        {
            money.push(input);
        }
        else
        {
            money.pop();
        }
    }

    int sum = 0;

    while (!money.empty())
    {
        int temp = money.top();
        money.pop();
        sum += temp;
    }

    cout << sum << '\n';
}