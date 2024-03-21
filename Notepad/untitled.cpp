#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    unsigned int N, M;

    cin >> N;

    unsigned int *A = new unsigned int[N];

    for (unsigned int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    sort(A, A + N);

    cin >> M;

    unsigned int *B = new unsigned int[M];

    for (unsigned int j = 0; j < M; j++)
    {
        cin >> B[j];
    }

    for (int i = 0; i < M; i++)
    {
        unsigned int searchvalue = B[i];

        int answer;
        for (int j = 0; j < N; j++)
        {
            if (searchvalue == A[j])
            {
                answer = 1;
                break;
            }
            else
            {
                answer = 0;
            }
        }
        cout << answer << '\n';
    }
}
