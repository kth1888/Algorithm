#include <iostream>

using namespace std;

long long cases[1001] = {
    0,
};

void solve(long long N)
{
    for (int i = 3; i <= N; i++)
    {
        cases[i] = (cases[i - 1] + cases[i - 2]) % 10007;
    }

    cout << cases[N] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cases[0] = 0;
    cases[1] = 1;
    cases[2] = 2;

    long long N;
    cin >> N;

    solve(N);
    return 0;
}