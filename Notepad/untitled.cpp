#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int maxlen = 0;
    int result = 0;
    int N, M;
    cin >> N >> M;

    vector<int> trees(N);
    for (int i = 0; i < N; i++)
    {
        cin >> trees[i];
        maxlen = max(maxlen, trees[i]);
    }

    while (result < M)
    {
        for (int i = 0; i < N; i++)
        {
            if (trees[i] > maxlen)
            {
                result = result + (trees[i] - maxlen);
            }
        }

        if (result >= M)
        {
            cout << "res : " << result << '\n';
        }
        else
        {
            cout << "res : " << result << '\n';
            maxlen--;
            result = 0;
        }
    }

    cout << maxlen << '\n';
}
