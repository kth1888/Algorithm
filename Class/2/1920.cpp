#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long int N, M;

    cin >> N;

    long int *A = new long int[N];

    for (long int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    sort(A, A + N);

    cin >> M;

    long int *B = new long int[M];

    for (long int j = 0; j < M; j++)
    {
        cin >> B[j];
    }

    // Comparsion

    int begin;
    int end;

    for (int i = 0; i < M; i++)
    {
        begin = 0;
        end = N - 1;

        long int searchvalue = B[i];

        while (begin <= end)
        {
            int mid = (begin + end) / 2;
            if (searchvalue < A[mid])
            {
                end = mid - 1;
            }
            else
            {
                begin = mid + 1;
            }
        }

        if (searchvalue == A[end])
        {
            cout << '1' << '\n';
        }
        else
        {
            cout << '0' << '\n';
        }
    }
}

/*
1 2 3 4 5
to
1 3 7 9 5

case : 1
s = 1, e = 5, m = 3
1 < 3
so
s = 1, e = 3, m = 2
1 < 2
so
s = 1, e = 2, m = 1?

case : 7
s = 1, e = 5, m = 3
7 > 3
so
s = 3, e = 5, m = 4
7 > 4
so
s = 4, e = 5, m = 4?

입력 변수의 범위에 신경쓰자
-2^31 ~ 2^31 : long int
*/