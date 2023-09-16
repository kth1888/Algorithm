#include <iostream>

using namespace std;

int main()
{
    int N;
    int cnt = 1;

    cin >> N;

    while (cnt <= N)
    {
        for (int i = 1; i <= cnt; i++)
        {
            cout << '*';
        }
        cout << '\n';
        cnt++;
    }

    return 0;
}