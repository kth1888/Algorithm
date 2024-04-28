#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    string *dud = new string[N];
    string *bo = new string[M];
    string *result = new string[((N > M) ? N : M)];

    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        dud[i] = temp;
    }

    for (int i = 0; i < M; i++)
    {
        string temp;
        cin >> temp;
        bo[i] = temp;
    }

    int k = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (dud[i] == bo[j])
            {
                result[k] = dud[i];
                k++;
            }
        }
    }
    sort(result, result + k);

    cout << k << '\n';
    for (int i = 0; i < k; i++)
    {
        cout << result[i] << '\n';
    }
}