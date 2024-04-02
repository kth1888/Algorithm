#include <iostream>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    int cnum = 1;
    int pnum = 1;

    for (int i = 1; i <= K; i++)
    {

        pnum = pnum * i;
    }

    for (int i = 0; i < K; i++)
    {
        cnum = cnum * (N - i);
    }

    int result = 1;
    result = cnum / pnum;

    cout << result << '\n';
}