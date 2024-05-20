#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int mysquare(int a)
{
    return a * a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    a = sqrt(N);

    vector<int> best(N + 1);
    vector<int> ones(N + 1);

    for (int i = 1; i <= a; i++)
    {
        best[i * i] = 1;
    }
    best[2] = 2;
    ones[2] = 2;
    best[3] = 3;
    ones[3] = 3;

    for (int i = 1; i <= N; i++)
    {
        int next = i + 1;
        if (best[next] != 1)
        {
            best[next] = best[1] + best[next - 1];
            ones[next] = 1 + ones[next - 1];
        }
        while (best[next] > 4)
        {
            best[next] = best[next] - ones[next] + best[ones[next]];
        }

        cout << next << " : " << best[next] << " : " << ones[next] << '\n';
    }

    cout << best[N] << '\n';
}