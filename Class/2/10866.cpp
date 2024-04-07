#include <iostream>
#include <deque>
#include <sstream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    // int N = 1;

    deque<int> deq;

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

        if (icmd == "push_front")
        {
            deq.push_front(icnum);
        }
        else if (icmd == "push_back")
        {
            deq.push_back(icnum);
        }
        else if (icmd == "pop_front")
        {
            if (deq.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                int temp = deq.front();
                deq.pop_front();
                cout << temp << '\n';
            }
        }
        else if (icmd == "pop_back")
        {
            if (deq.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                int temp = deq.back();
                deq.pop_back();
                cout << temp << '\n';
            }
        }
        else if (icmd == "size")
        {
            cout << deq.size() << '\n';
        }
        else if (icmd == "empty")
        {
            if (deq.empty())
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
            if (deq.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << deq.front() << '\n';
            }
        }
        else if (icmd == "back")
        {
            if (deq.empty())
            {
                cout << -1 << '\n';
            }
            else

            {
                cout << deq.back() << '\n';
            }
        }
    }
}