#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    // int N = 1;

    queue<int> que;

    for (int i = 0; i < N; i++)
    {
        string input;
        getline(cin, input);
        stringstream ss(input);
        string temp;
        string icmd;
        int icnum;
        string inputslot[2];
        inputslot[1] = '0';
        int j = 0;
        while (ss >> temp)
        {
            inputslot[j] = temp;
            j++;
        }
        icmd = inputslot[0];
        icnum = stoi(inputslot[1]);

        if (icmd == "push")
        {
            que.push(icnum);
        }
        else if (icmd == "pop")
        {
            if (que.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                int temp = que.front();
                que.pop();
                cout << temp << '\n';
            }
        }
        else if (icmd == "size")
        {
            cout << que.size() << '\n';
        }
        else if (icmd == "empty")
        {
            if (que.empty())
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else if (icmd == "front")
        {
            if (que.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << que.front() << '\n';
            }
        }
        else if (icmd == "back")
        {
            if (que.empty())
            {
                cout << -1 << '\n';
            }
            else

            {
                cout << que.back() << '\n';
            }
        }
    }
}