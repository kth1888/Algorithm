#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    string Nstring = to_string(N);
    int Nlen = Nstring.length();
    int minnum = 1;
    for (int i = minnum; i < N; i++)
    {

        string Ns = to_string(i);

        int Nl = Ns.length();

        int sum = 0;
        int first = false;
        for (int j = 0; j < Nl; j++)
        {
            if (!first)
            {
                sum += i;
                first = true;
            }
            sum += ((int)Ns[j] - 48);
        }

        if (sum == N)
        {
            cout << i << '\n';
            return 0;
        }
    }
    cout << '0' << '\n';
}

// https://blog.naver.com/yhol98/221606311437