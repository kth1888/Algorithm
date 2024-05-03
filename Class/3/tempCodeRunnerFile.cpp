#include <iostream>
#include <algorithm>

using namespace std;

int memo[1000000] = {
    0,
};
int initial = 0;

void calculator(int num, int count)
{
    if (num == 1)
    {
        if (memo[initial] == 0)
        {
            memo[initial] = count;
        }
        else
        {
            memo[initial] = min(memo[initial], count);
        }
    }

    if (num % 2 == 0)
    {
        calculator(num / 2, count + 1);
    }
    if (num % 3 == 0)
    {
        calculator(num / 3, count + 1);
    }
    if (num != 1)
    {
        calculator(num - 1, count + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    initial = N;

    calculator(N, 0);

    cout << memo[initial] << '\n';
}
