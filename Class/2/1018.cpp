#include <iostream>
#include <algorithm>

using namespace std;

int chessboard(char answerW[8][8], char answerB[8][8], char **Board, int locX, int locY)
{
    int ansW = 0;
    int ansB = 0;
    int minans = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (Board[i + locX][j + locY] != answerW[i][j])
            {
                ansW++;
            }
            if (Board[i + locX][j + locY] != answerB[i][j])
            {
                ansB++;
            }
        }
    }

    if (ansW < ansB)
    {
        minans = ansW;
    }
    else
    {
        minans = ansB;
    }

    return minans;
}

int main()
{
    char answerW[8][8] = {
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}};
    char answerB[8][8] = {
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}};

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

    // io check
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         cout << Board[i][j];
    //     }
    //     cout << '\n';
    // }

    int lenX = N - 7;
    int lenY = M - 7;
    int totallen = lenX * lenY;
    int *answersheet = new int[totallen];
    int count = 0;
    int answer = 999;

    for (int i = 0; i < lenX; i++)
    {
        for (int j = 0; j < lenY; j++)
        {
            answersheet[count] = chessboard(answerW, answerB, Board, i, j);
            count++;
        }
    }

    for (int k = 0; k < totallen; k++)
    {
        answer = min(answer, answersheet[k]);
    }

    cout << answer << '\n';
}
