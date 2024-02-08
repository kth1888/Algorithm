#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    char **Board = new char *[N];

    for (int i = 0; i < N; i++)
    {
        Board[i] = new char[M];

        for (int j = 0; j < M; j++)
        {
            cin >> Board[i][j];
        }
    }

    int changes = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Board[i][j] != Board[i][j + 1] && j + 1 != 8 && Board[i][j] != Board[i + 1][j] && i + 1 != 8)
            {
                cout << "comparing " << Board[i][j] << " and " << Board[i][j + 1] << '\n';
                changes++;

                cout << changes << '\n';
            }
        }
    }
    cout << "bn" << '\n';

    cout << changes << '\n';
}