#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> myheap(vector<int>{});

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    make_heap(myheap.begin(), myheap.end());

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
                pop_heap(myheap.begin(), myheap.end());
                int temp = myheap.back();
                cout << temp << '\n';
                myheap.pop_back();
            }
        }
        else
        {
            myheap.push_back(num);

            push_heap(myheap.begin(), myheap.end());
        }
    }
}