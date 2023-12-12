// https://ya-ya.tistory.com/101

#include <iostream>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;

    int **A = new int *[N];
    for (int i = 0; i < N; i++)
    {
        A[i] = new int[M];
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }

    int **B = new int *[N];
    for (int i = 0; i < N; i++)
    {
        B[i] = new int[M];
        for (int j = 0; j < M; j++)
        {
            cin >> B[i][j];
        }
    }

    int **C = new int *[N];
    for (int i = 0; i < N; i++)
    {
        C[i] = new int[M];
        for (int j = 0; j < M; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }
}