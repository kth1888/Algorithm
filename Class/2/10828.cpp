#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    // int N = 1;

    stack<int> st;

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
            st.push(icnum);
        }
        else if (icmd == "pop")
        {
            if (st.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                int temp = st.top();
                st.pop();
                cout << temp << '\n';
            }
        }
        else if (icmd == "size")
        {
            cout << st.size() << '\n';
        }
        else if (icmd == "empty")
        {
            if (st.empty())
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else if (icmd == "top")
        {
            if (st.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << st.top() << '\n';
            }
        }
    }
}