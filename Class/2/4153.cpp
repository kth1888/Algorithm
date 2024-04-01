#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c = 30001;
    int maxnum = 0;

    while (true)
    {
        cin >> a >> b >> c;
        int A = a * a;
        int B = b * b;
        int C = c * c;

        if (a == 0 && b == 0 && c == 0)
        {
            break;
        }

        maxnum = max(a, b);
        maxnum = max(maxnum, c);

        if (maxnum == a)
        {
            if (A == (B + C))
            {
                cout << "right" << '\n';
            }
            else
            {
                cout << "wrong" << '\n';
            }
        }
        else if (maxnum == b)
        {
            if (B == (A + C))
            {
                cout << "right" << '\n';
            }
            else
            {
                cout << "wrong" << '\n';
            }
        }
        else
        {
            if (C == (A + B))
            {
                cout << "right" << '\n';
            }
            else
            {
                cout << "wrong" << '\n';
            }
        }
    }
}