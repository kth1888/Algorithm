#include <iostream>

using namespace std;

int main()
{
    int hour, min;

    cin >> hour >> min;

    int calculated = min - 45;

    min = calculated;

    if (calculated < 0)
    {
        min = 60 + calculated;
        hour = hour - 1;
        if (hour < 0)
        {
            hour = 24 + hour;
        }
    }

    cout << hour << ' ' << min << '\n';
}