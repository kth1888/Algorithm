#include <iostream>

using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;

    bool arr[1000001] = {
        false,
    };
    arr[0] = arr[1] = true;

    for (int i = 2; i * i <= N; i++)
    {
        if (arr[i])
        {
            continue;
        }
        else
        {
            for (int j = 2; j * i <= N; j++)
            {
                arr[i * j] = true;
            }
        }
    }

    for (int i = M; i <= N; i++)
    {
        if (!arr[i])
        {
            cout << i << '\n';
        }
    }

    return 0;
}

// https://katteniiki.tistory.com/23