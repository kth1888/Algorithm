#include <iostream>
#include <stack>

using namespace std;
stack<int> value;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int coin = 0;
    int N, K;
    cin >> N >> K;

    while (N--)
    {
        int coin;
        cin >> coin;
        value.push(coin);
    }

    while (K != 0)
    {
        int coinval = value.top();
        value.pop();

        while (coinval <= K)
        {
            K -= coinval;
            coin++;
        }
    }

    cout << coin << '\n';
}