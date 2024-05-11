#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

priority_queue<int, vector<int>, greater<int>> myheap;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    while (N--)
    {
        int num;
        cin >> num;
        if (num == 0)
        {
            if (myheap.empty())
            {
                cout << '0' << '\n';
            }
            else
            {
                int temp = myheap.top();
                cout << temp << '\n';
                myheap.pop();
            }
        }
        else
        {
            myheap.push(num);
        }
    }
}