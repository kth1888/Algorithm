#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int a = 0;

    int count = 0;
    int temp = N;
    int startval = sqrt(N);
    int minval = 50001;

    while (startval != 0) // for (int i = 0; i < 11; i++)
    {
        if (temp == N)
        {
            a = startval;
        }
        else
        {
            a = sqrt(temp);
        }

        // cout << "a:" << a << '\n';
        temp = temp - (a * a);
        // cout << "temp:" << temp << '\n';
        count++;
        // cout << "count:" << count << '\n';
        if (count > 4)
        {
            temp = N;
            startval--;
            // cout << "startval:" << startval << '\n';
            minval = (minval >= count ? count : minval);
            // cout << minval << '\n';
            count = 0;
        }
        else if (count <= 4 && temp == 0)
        {
            temp = N;
            startval--;
            // cout << "startval:" << startval << '\n';
            minval = (minval >= count ? count : minval);
            // cout << minval << '\n';
            count = 0;
        }
    }

    if (N == 0)
    {
        cout << 0 << '\n';
    }
    else
    {
        cout << minval << '\n';
    }

    return 0;
}