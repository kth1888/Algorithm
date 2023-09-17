#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int A, B, cnt;

    cin >> cnt;

    for (int i = 0; i < cnt; i++)
    {
        cin >> A >> B;

        cout << A + B << '\n';
    }

    return 0;
}
