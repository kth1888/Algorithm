#include <iostream>
#include <vector>

using namespace std;

int zeros = 0;
int ones = 0;
vector<pair<int, int>> zerosones;

int fibonacci(int n)
{
    int memo[40];
    memo[0] = 0;
    memo[1] = 1;

    if (n < 2)
    {
        return memo[n];
    }
    for (int i = 2; i < n + 1; i++)
    {
        memo[i] = memo[i - 2] + memo[i - 1];

        int z2 = zerosones[i - 2].first;
        int o2 = zerosones[i - 2].second;
        int z1 = zerosones[i - 1].first;
        int o1 = zerosones[i - 1].second;

        zerosones.push_back(make_pair(z2 + z1, o2 + o1));
    }
    return memo[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        zerosones.push_back(make_pair(1, 0));
        zerosones.push_back(make_pair(0, 1));

        int N;
        cin >> N;
        int fibo = fibonacci(N);

        // cout << zeros << ' ' << ones << '\n';
        // zeros = 0;
        // ones = 0;

        cout << zerosones[N].first << ' ' << zerosones[N].second << '\n';

        zerosones.clear();
    }
}