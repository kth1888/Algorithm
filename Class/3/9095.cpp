#include <iostream>

using namespace std;

int cache[11] = {
    0,
};

void solve(int n)
{
    if (cache[n] != 0)
    {
        cout << cache[n] << '\n';
    }
    else
    {
        for (int i = 4; i <= n; i++)
        {
            cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];
        }
        cout << cache[n] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;
    cin >> T;

    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;

    while (T--)
    {
        cin >> n;
        solve(n);
    }
}

// https://donggoolosori.github.io/2020/12/17/9095/