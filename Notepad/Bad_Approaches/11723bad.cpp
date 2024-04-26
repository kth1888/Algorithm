#include <iostream>
#include <sstream>
#include <set>

using namespace std;

set<int> s;
set<int>::iterator iter;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++)
    {
        string cmdinput[2] = {"null", "999"};
        string input;
        getline(cin, input);

        stringstream ss(input);

        string temp;
        int j = 0;
        while (ss >> temp)
        {
            cmdinput[j] = temp;
            j++;
        }
        int commandvar = stoi(cmdinput[1]);
        string commandtype = cmdinput[0];
        if (commandtype == "add")
        {
            s.insert(commandvar);
        }
        else if (commandtype == "remove")
        {
            iter = s.find(commandvar);
            s.erase(iter);
        }
        else if (commandtype == "check")
        {
            iter = s.find(commandvar);
            if (iter != s.end())
            {
                cout << '1' << '\n';
            }
            else
            {
                cout << '0' << '\n';
            }
        }
        else if (commandtype == "toggle")
        {
            iter = s.find(commandvar);
            if (iter == s.end())
            {
                s.insert(commandvar);
            }
            else
            {
                s.erase(iter);
            }
        }
        else if (commandtype == "all")
        {
            set<int> s2;
            for (int j = 1; j <= 20; j++)
            {
                s2.insert(j);
            }
            s2.swap(s);
        }
        else if (commandtype == "empty")
        {
            s.clear();
        }
    }
}